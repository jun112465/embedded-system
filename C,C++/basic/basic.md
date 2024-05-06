### 불가능한 반환값
- c언어에서 배열을 반환하는 것은 불가능하다. 배열의 포인터를 반환하여 조작하자.

### void* 의 의미
- 'void*'는 c언어에서 일반 포인터를 나타낸다. 즉, 어떠한 데이터의 형태든 가리키는 포인터다. 
- 'void*'를 사용하여 모든 형태의 데이터를 반환하거나 가리킬 수 있다. 
- malloc 함수는 'void*'를 리턴하기 때문에 형변환이 필요하다.

### 함수포인터
- 함수의 이름은 곧 포인터다.
- <function_name> == &<function_name>, 오른쪽은 명시적으로 주소임을 나타냈을 뿐이다. 
- 함수포인터는 함수의 주소를 저장하여, 함수를 호출할 수 있습니다.
- 사용 이유
    1. 콜백 함수 등록
    2. 다형성 구현
    3. 런타임 다양한 동작 지정
    4. 모듈화와 유지 보수성.

```c
// 함수의 기본 형식
return_type (*pointer_name)(parameter_list);

int (*ptr)(int);

int add(int a, int b);

// ()에 따른 차이
void *my_func(); // void*를 리턴하는 함수
void (*my_func)(); // 함수포인터
```

```c
// 구조체 활용
#include <stdio.h>

typedef struct math{

    int (*add)(int, int);
    int (*subtract)(int, int);
}MathFunctions;

int add(int a, int b){
    return a+b;
}
int subtract(int a, int b){
    return a-b;
}
void math_functions_init(MathFunctions *mf){
    mf->add = add;
    mf->subtract = subtract;
}

int main(){
    MathFunctions math_func;
    math_functions_init(&math_func);
    printf("Add(1,3) : %d\n", math_func.add(1,3));
    printf("Sub(3,1) : %d\n", math_func.subtract(3,1));
}

```

### extern
- 다른 파일의 전역변수에 접근할 때 사용하는 키워드
```c
//test.c
int a = 10

int test(){
....
}

//main.c
extern int a;
prinf("%d", a); //10
```

### exit() vs return
- return : 일반 함수를 반환값과 함께 종료시킨다.
- exit : 프로세스 자체를 종료시킨다. 종료 전 모든 파일에 대한 입출력을 저장한다. main 함수에서의 return은 exit과 기능적으로 거의 유사.

### 변수명에 _t 붙는 이유
- **'_t'**는 typedef로 정의된 사용자 지정 타입에 관례로 붙게된다.
- pid_t : typedef int pid_t
- uid_t : typedef int uid_t
- ....

### sscanf(char *str, const char *format, type data)
- str에서 format과 같은 형식의 데이터를 찾아서 data에 값을 넣어준다.

### 구조체의 크기
- 구조체의 크기는 가장 큰 멤버 변수로 인해 정해진다. 가장 크기가 큰 멤버 변수의 배수의 크기로 정해진다.
- 이때 구조체 크기를 조정할 수 있다.
      - pack(push, 1)
      - pack(pop)
      - 위 두 함수를 사용해서 구조체 패킹 크기를 지정할 수 있다.
      - 구조체 pack 이라는 검색어로 자세히 공부해보자.
      - 주로 헤더가 있는 파일을 읽을 때, packing이 필요하다. (예, bmp file)

### static
- 전역변수
    - 전역 변수에 static 키워드를 사용하면 해당 변수의 범위가 파일 내로 제한되고 다른 파일에서는 접근할 수 없다.
    - 이는 파일 내에서만 해당 변수를 사용할 수 있도록 하고, 다른 파일과의 변수명 충돌을 방지.
- 지역변수
    - 지역 변수에 static 키워드를 사용하면 해당 변수가 정적으로 할당된다. 이는 변수가 함수가 호출될 때마다 생성되는 것이 아니라 프로그램이 시작될 때 한 번만 초기화되고 메모리에 유지된다. (상수는 const)
    - 또한, static으로 선언된 지역 변수는 해당 함수가 종료되더라도 소멸되지 않고 계속해서 유지된다.
    - 이를 통해 변수의 지속성을 제어하고, 함수 호출 사이에서 변수의 값을 유지할 수 있다.
- 함수  
    - 함수에 static 키워드를 사용하면 해당 함수의 범위가 파일 내로 제한됩니다. 다른 파일에서는 호출할 수 없다.
    - 이는 파일 내에서만 해당 함수를 사용할 수 있도록 하고, 다른 파일과의 함수명 충돌을 방지한다.
    - 또한, static으로 선언된 함수는 프로그램이 실행될 때 한 번만 초기화되며, 메모리에 상주하게 된다.

