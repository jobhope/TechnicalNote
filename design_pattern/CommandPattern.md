# **Command Pattern**

## 작성자
[![tdm1223](https://avatars1.githubusercontent.com/u/21440957?s=100&v=4)](https://github.com/tdm1223)

## Command Pattern?
![CommandPattern](https://user-images.githubusercontent.com/21440957/160071860-82c46e34-2ece-4d68-86fa-b8d4729e0394.png)

- 요청을 **객체의 형태로 캡슐화**하여 사용자가 보낸 요청을 나중에 이용할 수 있도록 요청에 필요한 정보(함수명, 매개변수 등)를 저장, 로깅, 취소할 수 있게 하는 패턴이다.

## 관련 용어
### Command
- 실행될 기능에 대한 인터페이스
- 실행될 기능을 `Execute` 함수로 선언한다.
- `Receiver` 객체를 가지고 있으며 `Receiver` 객체의 함수를 호출한다.
- 커맨드 객체는 별도로 `Invoker` 객체에 전달되어 명령을 발동하게 한다. 

### ConcreteCommand
- 실제로 실행되는 기능을 구현하는 클래스
- `Command`를 상속받아 구현한다.

### Invoker
- 기능의 실행을 요청하는 호출자 클래스
- 필요에 따라 명령 발동에 대한 기록을 남길 수 있다.
- 하나의 `Invoker` 객체에 다수의 `Command` 객체가 전달될 수 있다.

### Receiver
- `ConcreteCommand`의 기능을 실행하기 위해 사용하는 수신자 클래스이다.
- `Command`로부터 호출을 받아 자신에게 정의된 함수를 수행한다.

### Client
- `Client` 객체는 `Invoker` 객체와 하나 이상의 `Command` 객체를 보유한다.
- 어느 시점에서 어떤 명령을 수행할지를 결정한다.
- 명령을 수행하려면 `Client` 객체는 `Invoker` 객체로 `Command` 객체를 전달한다.

## 특징
- 실행될 기능을 캡슐화함으로써 주어진 여러 기능을 실행할 수 있는 재사용성이 높은 클래스를 설계한다.
- 이벤트가 발생했을 때 실행될 기능이 다양하면서도 변경이 필요한 경우 이벤트를 발생시키는 클래스를 변경하지 않고 **재사용**하고자 할 때 유용하다.
- 실행될 기능을 캡슐화함으로써 기능의 실행을 요구하는 `Invoker` 클래스와 실제 기능을 실행하는 수신자 클래스 사이의 **의존성을 제거**한다.
- 실행될 기능의 변경에도 `Invoker` 클래스를 수정 없이 그대로 사용 할 수 있도록 해준다.

## 예제
- [Command Pattern](/code/Command.cpp)
