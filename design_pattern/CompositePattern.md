## **Composite Pattern**

## 작성자
[![tdm1223](https://avatars1.githubusercontent.com/u/21440957?s=100&v=4)](https://github.com/tdm1223)

## Composite Pattern ?

<img width="450" alt="Composite" src="https://user-images.githubusercontent.com/21440957/173221341-38e427a0-ebb9-499d-ba10-e31b1107ebbb.png">


- 객체들의 관계를 트리 구조로 구성하여 부분-전체 계층을 표현하는 패턴이다.
- 클라이언트가 복합 객체나 단일 객체를 동일하게 구별없이 다르게 하는 것을 목적으로 한다.

## 사용하는 경우
- 객체들 간에 계급 및 계층구조가 있고 이를 표현해야할 때 사용한다.
- 클라이언트가 단일 객체와 집합 객체를 구분하지 않고 동일한 형태로 사용하고자 할 때 사용한다.

## 관련 용어
### Component
- 구체적인 부분
- `Leaf` 클래스와 전체에 해당하는 `Composite` 클래스에 공통 인터페이스를 정의한다.

### Leaf
- 구체적인 부분 클래스
- `Composite` 객체의 부품으로 설정한다.

### Composite
- 전체 클래스
- 복수 개의 `Component`를 갖도록 정의한다.
- 복수 개의 `Leaf`, 복수 개의 `Composite` 객체를 부분으로 가질 수 있다.

## 장점
- 객체들이 모두 같은 타입으로 취급되기 때문에 새로운 클래스 추가가 용이하다.
- 단일객체, 집합객체 구분하지 않고 코드 작성이 가능하다.

## 단점
- 설계를 일반화 시켜 객체간의 구분, 제약이 힘들다.

## 예제
- [Composite](/code/Composite.cpp)