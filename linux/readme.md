# README


# file

- normal file
- directory
- symbolic
- device file
    - 특정 장치와 상호 작용하기 위한 인터페이스를 제공
    - block device file
         - 데이터를 블록 단위로 읽고 쓸 수 있는 파일.
         - 디스크와 같은 블록 기반의 장치에 사용됨.
         - /dev 디렉토리에 위치함.
    - character device file
         - 입출력 장치(예: 터미널, 시리얼포트)와 관련된 파일에 사용된다.
         - 라인 단위로 데이터를 처리
         - /dev 디렉토리에 위치함.
- mount
    - 파일 시스템을 시스템의 특정 디렉토리에 연결하는 것을 의미
    - 외부 저장 장치(하드 디스크, USB 드라이브 등)나 네트워크 리소스(네트워크 파일 시스템)를 시스템에 연결하여 사용할 수 있다.
    - 명령어
        - **mount [option] \<device or file system\> \<location to mount\>**
        - **mount /dev/sdb1 /mnt/usb**
        - 위 명령은 '/dev/sdb1/'이라는 장치를 '/mnt/usb'라는 디렉토리에 연결한다. 이제 usb 플래시 드라이브의 내용을 '/mnt/usb'를 통해 읽고 쓸 수 있다. 
  
      


# system call 
- 운영체제에 의해 제공된느 서비스를 요청하는 프로그램과 운영체제간의 인터페이스
- 사용자 프로그램이 하드웨어 자원을 직접 제어하는 것을 방지
- 다중 사용자 환경에서 자원을 효율적으로 관리하고, 프로그램 간의 충돌을 방지할 수 있음
- 각 시스템 호출은 고유한 번호를 가지고 있다. 
- 종류
    - 파일관리 : 파일 r,w,o
    - 프로세스 제어 : 프로세스 생성, 종료, 대기 등
    - 메모리 관리 : 메모리 할당, 해제, 보호 등
    - 네으퉈킹 : 네트워크 연결, 데이터 전송 등

# process
- process image
  1. code
  2. data
  3. heap
  4. stack
- fork()
  - 부모 프로세스와 똑같은 프로세스를 생성한다.
  - child 프로세스는 fork() 이후부터 실행된다. 
- wait()
  - 자식 프로세스를 기다리면서 자식 프로세스의 반환값에 따라 추가적인 작업이 가능해진다.
- exec()
  - 특정 프로그램을 실행시킬 수 있다. 이때, pid는 유지되지만 내부 process image가 대체된다.
- system()
  - fork() -> exec()의 복잡한 과정을 한번에 구현한 함수

### 정리
위와 같은 함수들이 있는 이유는 결국 더 복잡한 프로그램을 만들기 위해 있는 것이다. 한 프로그램 내에는 여러 기능이 있을텐데, 전부 쓰레드로 구현하는 것은 어렵고,
단일 프로세스로 만들면 여러 작업을 동시에 할 수 없어지기 때문에 cpu가 쉬게 된다(cpu idle, ex: 리소스를 기다리는 경우). 멀티 프로세스로 프로그램을 짜게 되면
더 많은 작업을 적은 시간안에 시킬 수 있다. 


# thread

- mutex 
    - lock & unlock 
    - 이진 세마포어와 같은 역할을 한다.
- semaphore
    - P 연산 : 스레드가 임계구역에 접근하기 위해 자원을 기다림. 접근이 가능해지면 세마포어 값을 감소시킨다.
    - V 연신 : 스레드가 임계구역에서의 작업을 마치고 세마포어 값을 증가시킴.
- 차이점
    - mutex : 임계구역에 대한 lock, unlock을 통해 공유자원을 상호배제 시킨다.
    - semaphore : mutex의 역할도 할 수 있으며, 프로세스가 공유자원에 접근하는 것도 제한할 수 있다. 또한, 세마포어는 초기값을 1보다 높게 설정할 수 있어서 작업에 대한 버퍼링을 할 수 있다. 

# signal
- 시그널은 컴퓨터 시스템에서 발생하는 각종 이벤트를 처리하는 메커니즘이다. 
- 프로세스 간 통신, 예외 상황 처리, 비동기적인 이벤트 처리 등 다양한 상황에서 사용된다. 
- 프로세스는 시그널을 수신하고 이를 처리하는 핸들러를 등록할 수 있다.
- 활용
    - 시그널 발생 : alarm(), sleep()
    - 핸들러 등록 : 사용자 정의 시그널 핸들러를 작성해서 등록할 수 있다.
    - 전파 : kill(pid_t pid, int signo), kill을 통해 다른 프로세스에 시그널을 발생시킬 수 있다.
    - 비지역 점프 : setjmp(), longjmp()를 활용하여 시그널 발생 시 설정 지점으로 돌아갈 수 있다.
- 인터럽트와의 차이점
    - 인터럽트는 하드웨어 수준에서 나타나는 문제점에 대한 문제이며, 이를 처리하는 코드(프로그램)는 인터럽트 벡터에서 접근할 수 있다.
    - 시그널은 소프트웨어 수준에 나타나는 상황에 대한 처리를 한다.
    - 인터럽트 테이블(벡터)는 시스템 메모리 시작 주소에 보통 저장돼 있다. (0x000000000)


# pipe

- 프로세스 간 통신에 사용되며 단방향 통신이 가능한 파일이다.
- 이름없는파이프
    - 부모 자식 프로세스 관계에서 데이터를 전송할 때 쓰인다. 
    - 표준입출력에 쓰기 파이프를 복사하여 printf()를 통해 파이프에 데이터를 쉽게 보낼 수 있다. [ ex) dup2(fd, 1); ]
- 이름있는파이프 (named pipe)
    - fifo 라고도 불린다. 
    - 서로 다른 프로세스 간의 통신에 쓰인다. 


# shared memory 
- 공유메모리를 통해 두 프로세스가 직접적으로 데이터를 공유하여 쓰기, 읽기가 가능해진다. 
- shmget() : 공유메모리를 생성한다. 고유 키를 통해 메모리의 id 값을 반환받는다.
- shmat()  : 공유메모리 id를 통해 프로세스에 메모리를 부착시킨다. 공유메모리의 시작 주소를 반환받는다.
- shmdt() : 공유메모리를 프로세스에서 떼어낸다.
- shmctl() : 공유메모리에 대한 작업을 실행할 수 있다. IPC_RMID를 통해 삭제하는 것이 중요하다.