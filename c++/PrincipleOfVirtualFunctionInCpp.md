# **가상함수의 동작 원리**

## 작성자
[![tdm1223](https://avatars1.githubusercontent.com/u/21440957?s=100&v=4)](https://github.com/tdm1223)

## C++에서 멤버함수
- C++에서 객체가 생성되면 **멤버 변수는 객체 내**에 존재한다.
- **멤버 함수는 메모리의 한 공간**에 별도로 위치하고 이 함수가 정의된 클래스의 **모든 객체가 이를 공유하는 형태**를 취한다.

## C++에서 가상함수
- **한 개 이상의 가상 함수**를 포함하는 클래스에 대해서는 **컴파일러**가 **가상 함수 테이블**을 만든다.
- 가상 함수 테이블은 실제 호출되어야 할 **함수의 위치정보**를 담고 있는 테이블이다.
- 가상 함수 테이블은 **객체의 생성과 상관없이** main 함수가 호출되기 이전에 메모리 공간에 할당된다.
- 가상 함수 테이블은 **멤버 함수의 호출**에 사용되는 일종의 데이터이다.

### 가상함수의 동작 원리를 알수 있는 예제
```cpp
class A
{
public:
    virtual void ShowFunc() { cout << "A show" << endl; }
};

class B : public A
{
public:
    void Show() { cout << "B show" << endl; }
    void Func() { cout << "B func"<< endl; }
};

int main()
{
    A* a = new A();
    a->Show(); // 결과는 A show
    A* b = new B();
    b->Show(); // 결과는 B show
    return 0;
}
```
- 위 구조에서 **B 클래스**의 **가상 함수 테이블**을 살펴보면, 오버 라이딩된 **A클래스의 Show 함수**에 대한 정보가 없다.
- 가상 함수의 호출 원리로 b의 Show함수를 호출하면 B클래스의 Show함수가 호출된다.
