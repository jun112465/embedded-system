#include <fcntl.h>
#include <linux/fb.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <unistd.h>

#define FRAMEBUFFER_DEVICE "/dev/fb0"
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define PIXEL_SIZE 4 // 32비트 컬러

void draw_rectangle(char *fbp, int x, int y, int width, int height, unsigned int color) {
    for (int j = y; j < y + height; j++) {
        for (int i = x; i < x + width; i++) {
            long int position = (i + SCREEN_WIDTH * j) * PIXEL_SIZE;
            *((unsigned int*)(fbp + position)) = color;
        }
    }
}

int main() {
    int fbfd = open(FRAMEBUFFER_DEVICE, O_RDWR);
    if (fbfd == -1) {
        perror("Error opening framebuffer device");
        exit(1);
    }

    struct fb_var_screeninfo vinfo;
    if (ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo)) {
        perror("Error reading variable information");
        close(fbfd);
        exit(1);
    }

    int screensize = vinfo.yres_virtual * vinfo.xres_virtual * PIXEL_SIZE;
    char *fbp = (char *)mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, 0);
    if ((intptr_t)fbp == -1) {
        perror("Error mapping framebuffer device to memory");
        close(fbfd);
        exit(1);
    }

    // 흰색으로 초기화
    unsigned int white = (255 << 16) | (255 << 8) | 255;
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        for (int j = 0; j < SCREEN_WIDTH; j++) {
            long int position = (j + SCREEN_WIDTH * i) * PIXEL_SIZE;
            *((unsigned int*)(fbp + position)) = white;
        }
    }

    // 빨간색 사각형 그리기
    draw_rectangle(fbp, 200, 150, 400, 300, (255 << 16)); // 빨간색: R=255, G=0, B=0

    munmap(fbp, screensize);
    close(fbfd);

    return 0;
}
