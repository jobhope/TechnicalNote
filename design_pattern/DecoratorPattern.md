## **Decorator Pattern**

## 작성자
[![tdm1223](https://avatars1.githubusercontent.com/u/21440957?s=100&v=4)](https://github.com/tdm1223)

## Decorator Pattern ?

![Decorator](https://user-images.githubusercontent.com/21440957/171869978-2f4e2db1-50de-4825-b4b8-0cf7bb471df5.jpg)

- 주어진 상황 및 용도에 따라 어떤 객체에 책임을 덧붙이는 패턴이다.
  - **기능 확장**이 필요할 때 서브 클래싱 대신 쓸 수 있는 유연한 대안이 될 수 있다.
- **객체의 결합**을 통해 기능을 동적으로 유연하게 확장 할 수 있게 해주는 패턴이다.
  - 기본 기능에 추가할 수 있는 기능의 종류가 많은 경우 각 추가 기능을 `Decorator` 클래스로 정의 한 후 필요한 `Decorator` 객체를 조합하여 추가 기능의 조합을 설계 한다.

## 사용하는 경우
- 객체의 타입과 호출 가능한 함수를 그대로 유지하면서 객체에 새로운 책임을 추가할 때 사용한다.
- 탈부착 가능한 책임을 정의할 때 사용한다.
- 상속을 통해 서브클래스를 계속 만드는 방법이 비효율적일 때 사용한다.
    - 조합되는 경우의 수가 많으면 서브클래스 수가 폭발적으로 늘어날 수 있다.

## 관련 용어
### Component
- 기본 기능을 뜻하는 `ConcreteComponent`와 추가 기능을 뜻하는 `Decorator`의 공통 기능을 정의
- 클라이언트는 `Component`를 통해 실제 객체를 사용함

### ConcreteComponent
- 기본 기능을 구현하는 클래스

### Decorator
- 많은 수가 존재하는 구체적인 `Decorator`의 **공통 기능**을 제공

### ConcreteDecorator
- `Decorator`의 하위 클래스로 기본 기능에 추가되는 **개별적인 기능**을 뜻함
- `ConcreteDecorator` 클래스는 `ConcreteComponent` **객체에 대한 참조**가 필요하다.
  - `Decorator` 클래스에서 `Component` 클래스로의 합성을 통해 표현된다.

## 장점
1. 기존 코드를 수정하지 않고도 `Decorator` 패턴을 통해 행동을 확장시킬 수 있다.
2. 구성과 위임을 통해서 실행중에 **새로운 행동을 추가**할 수 있다.
3. OCP 원칙을 위반하지 않고 클래스를 확장할 수 있다.

## 단점
1. 의미없는 객체들이 너무 많이 추가될 수 있다.
2. `Decorator`를 너무 많이 사용하면 코드가 복잡해질 수 있다.

## 예제
- [TemplateMethod](/code/Decorator.cpp)