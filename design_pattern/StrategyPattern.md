## **Strategy Pattern**

## 작성자
[![tdm1223](https://avatars1.githubusercontent.com/u/21440957?s=100&v=4)](https://github.com/tdm1223)

## Strategy Pattern ?

![StrategyPattern](https://user-images.githubusercontent.com/21440957/163402752-e1707235-4837-47b0-910f-150a15da3414.png)

- 실행 중에 알고리즘을 선택할 수 있게 하는 행위 소프트웨어 디자인 패턴이다.
- 특정한 계열의 알고리즘들을 정의하고 각각 캡슐화하며 해당 계열 안에서 상호 교체가 가능하게 만든다.

## 관련 용어
### Strategy
- 전략 사용을 위한 인터페이스

### ConcreteStrategy
- 실제로 실행될 알고리즘
- `Strategy` 인터페이스를 구현

### Context
- 인스턴스를 주입받아 사용

## 특징
- 알고리즘을 사용하는 클라이언트와 상관없이 독립적으로 알고리즘을 다양하게 변경할 수 있다.
- 기능 추가, 로직 변경시 유연하게 확장할 수 있다.
- 전략 패턴은 주로 상속을 대체하려는 목적으로 사용한다. 
- 어떤 전략을 사용할지 **외부에서 데이터의 입력**이 필요하다.

## 전략 패턴을 사용하는 이유
- 클래스를 수정하지 않고도 기능을 추가하거나 변경할 수 있다. (개방 폐쇄의 원칙 실현)
- 코드 재사용이 용이하다.

## 예제
- [Strategy](/code/Strategy.cpp)