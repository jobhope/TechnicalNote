# **Enum hack**

## 작성자
[![tdm1223](https://avatars1.githubusercontent.com/u/21440957?s=100&v=4)](https://github.com/tdm1223)

## Enum hack?
- `enum` 타입의 값은 `int`가 놓일 곳에서도 쓸 수 있다는 C++의 특징을 활용하는 일종의 편법이다.

1. 구식 컴파일러에서 객체 상수화(const 형태의 상수)를 받아들이지 못하는 상황이 존재한다.
2. 구식 컴파일러는 클래스 상수를 선언하는 과정에서 대입하는 것이 맞지 않다고 판단한다.
3. 컴파일과정에서 어떠한 배열의 길이를 클래스 상수로 넣었을 때 구식 컴파일러는 이 배열의 길이를 모른다고 할 수 있다. 
4. `const` 형태가 아닌 `enum`을 활용하여 상수를 선언 할 수 있다.

```cpp
class GamePlayer{
private:
  static const double FungeFactor;
};

const double CostEstimate::FudgeFactor = 1.35;
```
- 위의 경우처럼 정적 상수를 추가하는것이 일반적이다.
- 아래처럼(구식컴파일러의 3번 경우) 클래스를 컴파일 하는 도중에 클래스 상수의 값이 필요할때는 아래와 같은 방법을 사용한다.
```cpp
class GamePlayer{
private:
  enum {NumTurns = 5};  // enum hack
  int scores[NumTurns]; // 해결
};
```

 ## 특징
1. 동작방식이 const 보단 #define에 가깝다.
    - `const`처럼 사용할 수 있다.
    - `enum`안에 들어있는 상수는 주소를 참조 할 수 없기 때문에 다른 클래스나 영역에서 참조할 수 없다.
    - `const`객체의 경우 메모리를 일반적으로는 잡지 않지만 컴파일러에 따라 잡는 경우도 있는데 `enum`은 어떤 경우에도 메모리를 추가적으로 잡지 않는다.
2. 템플릿 메타 프로그래밍의 핵심 기법이다.
