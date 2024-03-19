# README

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
