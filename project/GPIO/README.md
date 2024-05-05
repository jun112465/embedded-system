# 프로젝트 실행과정
- POWER ON -> Startup Code -> main()

# GPIO 제어 과정
![alt text](image.png)

1. Main() ->
2. HAL_Init() -> 주변장치 리셋, 플래쉬 인터페이스 초기화, systik 설정
3. SystemClock_Config() -> 시스템 클럭 설정
4. MX_GPIO_Init() -> __HAL_RCC_GPIOC_CLK_ENABLE(); -> GPIO C포트 클럭 활성화
5. HAL_GPIO_Init(GPIO_LED_GPIO_Port, &GPIO_InitStruct); -> GPIO 옵션 설정

- 클럭을 키면 전류를 더욱 사용한다. 극한으로 전류를 아껴야 하는 상황에는 Sleep 모드 뿐만 아니라, 클럭도 하나 하나 전부 제어해야 한다. 