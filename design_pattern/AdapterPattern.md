## **Adapter Pattern**

## 작성자
[![tdm1223](https://avatars1.githubusercontent.com/u/21440957?s=100&v=4)](https://github.com/tdm1223)

## Adapter Pattern ?

![Adapter](https://user-images.githubusercontent.com/21440957/169350820-e643a67f-f416-4423-bffa-b92f3ba9d244.png)

- 한 클래스의 인터페이스를 사용하고자 하는 **다른 인터페이스로 변환**할 때 사용하는 패턴이다.
- **인터페이스 호환성** 문제 때문에 같이 쓸 수 없는 클래스들을 연결해서 쓸 수 있다.
  - 지원하지 않는 인터페이스를 지원하는것 처럼 만든다.
- 직접적으로 호출하지 않고 중간에 **어댑터를 통해 호출**함으로서 호환성이 없더라도 함께 동작할 수 있고 유지보수를 쉽게 할 수 있다.
- 클라이언트가 서로 다른 클래스들에 의존하고자 할 때 하나의 추상화된 인터페이스로 의존되어야 할 경우 사용할 수 있다.

## 사용하는 경우
- 이미 만들어진 클래스를 재사용이 필요할 때 기존의 클래스를 개조해서 필요한 클래스를 만든다.
    - 필요한 함수들을 빠르게 만들 수 있다.
    - 버그가 발생해도 기존의 클래스에는 버그가 없으므로 `Adapter` 역할의 클래스를 중점적으로 조사하면 된다.
- 이미 만들어진 클래스를 새로운 인터페이스에 맞게 개조시킬때 `Adapter` 패턴을 사용한다.
    - `Adapter` 패턴은 기존의 클래스를 수정하지 않고 목적 인터페이스에 맞춘다.
    - 기존 클래스의 인터페이스만 알면 새로운 클래스를 만들 수 있다.

## Adapter 패턴의 종류
### 클래스에 의한 `Adapter` 패턴

- 상속을 사용한 `Adapter`

![ClassAdapter](https://user-images.githubusercontent.com/21440957/169350873-3fdda04a-52f9-43c0-a3be-c00b70e8fd94.jpg)

- `Adapter`가 `Adaptee`의 서브 클래스이기 때문에 `Adaptee`의 행동을 **오버라이드** 할 수 있다.
- `Adaptee` 객체를 만들지 않아도 된다. 
- `Adapter` 클래스가 특정 `Adatee` 클래스에만 적용가능하다.

### 인스턴스에 의한 Adapter 패턴

- 위임을 사용한 `Adapter`

![ObjectAdapter](https://user-images.githubusercontent.com/21440957/169350902-e5b9cb2f-6c5e-483c-ad71-23afe8d7af2e.jpg)

- 상속이 아닌 구성을 사용하기 때문에 더 유연하다 
- `Adaptee` 객체를 만들어야 사용가능하다.

## 관련 용어
### Client
- `Third Party` 라이브러리나 외부시스템을 사용하는 부분이다.

### Adaptee
- `Third Party` 라이브러리나 외부시스템을 의미한다.

### Target Interface
- `Adapter`가 구현(`implements`) 하는 인터페이스이다. 클라이언트는 `Target Interface`를 통해 `Adaptee`인 써드파티 라이브러리를 사용하게 된다.

### Adapter
- `Client` 와 `Adaptee` 중간에서 호환성이 없는 둘을 연결시켜주는 역할을 담당한다.
- `Target Interface`를 구현하며, 클라이언트는 `Target Interface`를 통해 어댑터에 요청을 보낸다.
- 어댑터는 클라이언트의 요청을 `Adaptee`가 이해할 수 있는 방법으로 전달하고, 처리는 `Adaptee`에서 이루어진다.

## 장점
- 관계가 없는 인터페이스 간 같이 사용이 가능하다.
- 프로그램 검사가 용이하다.
- 클래스 재사용성이 증가한다.

## 단점
- 어댑터 클래스에서 통일 시켜주는 부분을 하나씩 구현해야 한다.

## 예제
- [AbstractFactory Pattern](/code/Adapter.cpp)