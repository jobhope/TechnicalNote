# **Virtual**

## 작성자
[![tdm1223](https://avatars1.githubusercontent.com/u/21440957?s=100&v=4)](https://github.com/tdm1223)

## 들어가기 전에
- **C++ 컴파일러**는 **포인터 연산의 가능성 여부**를 판단할 때 **선언한 포인터의 자료형**을 기준으로 판단하지, **실제 가리키는 객체의 자료형**을 기준으로 판단하지 않는다.

### 간단한 예
```cpp
// Base <- Derived
Base * basePtr = new Derived(); // 컴파일 성공 -> basePtr는 Base 포인터
Derived * derivedPtr = basePtr; // 컴파일 에러
basePtr -> DerivedFunc() // 컴파일 에러. basePtr는 Base 포인터이기 때문에 Derived에 있는 함수는 호출할 수 없다.
```

## Virtual Keyword
- virtual 키워드를 사용해 함수를 **가상함수로 선언**하면, 해당 함수 호출 시 **포인터의 자료형**을 기반으로 호출대상을 결정하지 않고, 포인터 변수가 **실제로 가리키는 객체**를 참조하여 호출의 대상을 결정한다.
- **다형성**<sup>[1)](#ref1)</sup>을 표현할 수 있는 Keyword이다.

### 아래 예를 통해 이해할 수 있다.
```cpp
class A
{
public:
	virtual void func()
	{
		cout << "A " << endl;
	}
};
class B : public A
{
public:
	virtual void func()
	{
		cout << "B " << endl;
	}
};
class C : public B
{
public:
	virtual void func()
	{
		cout << "C " << endl;
	}
};
int main()
{
	A* a = new A;
	A* b = new B;
	A* c = new C;

	a->func();    
	b->func();
	c->func();
}
```
- A*형으로 각각의 클래스를 가리키는 객체를 선언한다.
- 세 클래스 모두 func라는 함수를 가지고 있고 그 함수를 호출하고 있다.
- 실행 결과 A B C 순으로 찍히게 된다.
- **virtual** 선언이 안 되어 있다면 A A A로 출력된다.
- virtual keyword는 한곳에만 선언해도 적용 된다.

## 각주

<a id="ref1">

1) 모습은 같은데 형태는 다르다 = 문장은 같은데 결과는 다르다. (참조하는 객체의 자료형이 다르기 때문) 이름이 같은 함수여도 객체에 따라서 결과가 다르다.

</a>
