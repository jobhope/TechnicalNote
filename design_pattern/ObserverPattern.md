# **Observer Pattern**

## 작성자
[![tdm1223](https://avatars1.githubusercontent.com/u/21440957?s=100&v=4)](https://github.com/tdm1223)

## Observer Pattern?
![Observer Pattern](https://user-images.githubusercontent.com/21440957/161577837-1c439004-e119-4827-a7ab-671d47ee4320.png)

- 요청을 **객체의 형태로 캡슐화**하여 사용자가 보낸 요청을 나중에 이용할 수 있도록 요청에 필요한 정보(함수명, 매개변수 등)를 저장, 로깅, 취소할 수 있게 하는 패턴이다.

## 관련 용어
### Observer
- 데이터의 변경을 통보 받는 인터페이스
- `Subject`에서는 `Observer` 인터페이스의 `Update` 메서드를 호출함으로써 `ConcreteSubject`의 데이터 변경을 `ConcreteObserver`에게 통보한다.

### Subject
- `ConcreteObserver` 객체를 관리하는 요소
- `Observer` 인터페이스를 참조해서` ConcreteObserver`를 관리한다.
- 변화 발생시 Notify 함수를 통해 관리하고 있는 `ConcreateObserver`들에게 통보한다.

### ConcreteSubject
- `Subject`를 상속받는 클래스
- 통지할 데이터가 있는 클래스이다.

### ConcreteObserver
- `ConcreteSubject`의 변경을 통보받는 클래스
- `Observer` 인터페이스의 `Update` 함수를 구현하여 변경을 통보받는다.

## 특징
- 한 객체의 상태 변화에 따라 다른 객체의 상태도 연동되도록 **일대다 객체 의존 관계**를 구성 한다.
- 옵저버 또는 리스너라 불리는 하나 이상의 객체를 관찰 대상이 되는 객체에 등록시킨다.
- 각각의 옵저버들은 관찰 대상인 객체가 발생시키는 이벤트를 받아 처리한다.
- 이벤트가 발생하면 옵저버는 콜백을 받는다. 
- 각각의 옵저버는 `notify` 함수를 구현함으로써 이벤트가 발생했을 때 처리할 각자의 동작을 정의해야 한다.
- 주체에는 일반적으로 등록(`register`, `subscribe`), 제거(`unregister`, `unsubscribe`) 메서드가 있다.
  - 등록은 새로운 옵저버를 목록에 등록한다.
  - 제거는 목록에서 옵저버를 제거한다.
- 분산 이벤트 핸들링 시스템을 구현하는 데 사용된다.

## 예제
- [Observer](/code/Observer.cpp)
