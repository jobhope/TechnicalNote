# **공백 클래스 (Empty Class)**

## 작성자
[![tdm1223](https://avatars1.githubusercontent.com/u/21440957?s=100&v=4)](https://github.com/tdm1223)

## 공백 클래스 ?

```cpp
class Empty{};
```

- 아무것도 없는 클래스
  - 비정적 데이터 멤버가 없다.
  - 가상 함수가 없다.
  - 가상 기본 클래스가 없다.

## 공백 클래스의 크기
- 공백 클래스는 **개념적**으로 차지하는 **메모리 공간**이 없다.
  - `C++`에서는 독립 구조의 객체는 반드시 크기가 **0을 넘어야**한다.
- `sizeof(Empty)`의 값은 1이 된다.

## 공백 기본 클래스 최적화 (EBO : Empty Base Optimization)

```cpp
class Empty{};

class A
{
private:
  int x;
  Empty e; // 공백 클래스
};

class B : private Empty // 기본 클래스로 만든다.
{
private:
  int x;
};
```

- 공백 클래스의 크기가 존재하기 때문에 `sizeof(A) > sizeof(int)`현상이 발생한다.
  - `A`의 크기는 바이트 패딩으로 인해 **8바이트**가 된다.
- `Empty` 객체를 멤버로 두지 않고 **기본 클래스**로 바꾸면 두 크기를 같게 할 수 있다.
  - `sizeof(B) == sizeof(int)`
- 공백 기본 클래스 최적화는 **단일 상속**에서만 적용된다.
