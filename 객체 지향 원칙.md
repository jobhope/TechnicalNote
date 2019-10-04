# **객체 지향 원칙**

## 작성자
[![tdm1223](https://avatars1.githubusercontent.com/u/21440957?s=100&v=4)](https://github.com/tdm1223)
[![rlatjdwo555](https://avatars0.githubusercontent.com/u/28692938?s=100&v=4)](https://github.com/rlatjdwo555)
[![Stupid07](https://avatars1.githubusercontent.com/u/35564566?s=100&v=4)](https://github.com/Stupid07)

## 객체지향 5대원칙(SOLID)
- SRP(단일 책임 원칙)
- OCP(개방-폐쇄 원칙)
- LSP(리스코프 치환 원칙)
- ISP(인터페이스 분리 원칙)
- DIP(의존 역전 원칙)

### 5대 원칙이란?
- 객체지향을 설계할때 지키면 좋은 원칙

### Single Responsiblity Principle (SRP, 단일 책임 원칙)
- 소프트웨어의 설계 부품(클래스, 함수 등)은 단 하나의 책임(기능)만을 가져야 한다.
- 응집도<sup>[1)](#ref1)</sup>는 높고 결합도<sup>[2)](#ref1)</sup>는 낮게

### Open-Closed Principle (OCP, 개방-패쇄 원칙)
- 객체는 **확장**에 대해서는 **개방적**이고 **수정**에 대해서는 **폐쇄적**이어야 한다는 원칙이다.
- 기존의 코드를 변경하지 않고 기능을 수정하거나 추가할 수 있도록 설계해야 한다.
- 대표적인 문법이 인터페이스(Interface)이다.

### Liskov Substitution Principle (LSP, 리스코프 치환 원칙)
- **자식 클래스**는 언제나 자신의 **부모 클래스**를 **대체**할 수 있다는 원칙이다.
- 자식 클래스는 부모 클래스의 기능을 수행할 수 있어야 한다.

### Interface Segregation Principle (ISP, 인터페이스 분리 원칙)
- 한 클래스는 자신이 사용하지 않는 인터페이스는 구현하지 말아야 한다.
- 하나의 일반적인 인터페이스보다는, 여러 개의 구체적인 인터페이스가 낫다.

### Dependency Inversion Principle (DIP, 의존 역전 원칙)
- 상성이 높고 안정적인 고수준의 클래스는 구체적이고 불안정한 저수준의 클래스에 의존해서는 안된다는 원칙이다
- 추상화 된 것은 구체적인 것에 의존하면 안 된다. 구체적인 것이 추상화된 것에 의존해야 한다.
- 의존관계를 맺을 때, 구체적인 클래스보다 인터페이스나 추상 클래스와 관계를 맺는다는 것을 의미한다.
- DIP를 만족하면 '의존성 주입(DI)' 기술로 변화에 유연한 설계를 할 수 있다.

## 참조
- [SOLID 원칙](https://dev-momo.tistory.com/entry/SOLID-%EC%9B%90%EC%B9%99)
- [나무위키](https://namu.wiki/w/%EA%B0%9D%EC%B2%B4%20%EC%A7%80%ED%96%A5%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D/%EC%9B%90%EC%B9%99)

## 각주
<a id ="ref1"></a>

- 1)응집도 : 하나의 기능을 제공하기 위해 집중하는 정도
- 2)결합도 : 두 모듈 사이의 연관 관계
