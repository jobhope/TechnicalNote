# **JAVA final**

## 작성자
[![rlatjdwo555](https://avatars0.githubusercontent.com/u/28692938?s=100&v=4)](https://github.com/rlatjdwo555)

## final?

### 1. Final variable
- 변수의 값을 **상수**로 지정
- `static` 키워드와 함께 사용

### 2. Final method
- **오버라이딩 불가**
- 예를 들어 부모 클래스에서 speak() 메소드가 입으로 말하도록 정의했는데 자식 클래스에서 재정의하여 손으로 말하도록 기능을 바꿀 수 없게

### 3. Final class
- **상속 불가**
- 클래스 내부의 메소드도 오버라이딩 불가
- 대표적으로 `String Class`
- 중요한 어떤 class에 대해 sub class로 시스템이 파괴될 수 있기 때문에 자바에서는 핵심 class에 대해 final class로 선언하고 있다.  
