CC = gcc
TARGET = output
OBJECTS = main.o game.o webtoon.o coding.o

all : $(TARGET)

# " @ $^ " 구문을 실행할 때 오브젝트 파일이 없으면 오브젝트 파일과 동일한 이름의 c파일을 찾아 오브젝트 파일을 자동으로 생성
$(TARGET) : $(OBJECTS)
	$(CC) -o $@ $^
  
clean : 
	rm *.o $(TARGET)

