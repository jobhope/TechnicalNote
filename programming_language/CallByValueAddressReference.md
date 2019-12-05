# **함수의 인자 전달 방식(Call by Value, Call by Address, Call by Reference)**

## 작성자
[![Stupid07](https://avatars1.githubusercontent.com/u/35564566?s=100&v=4)](https://github.com/Stupid07)

## 사전 지식

```javascript
function foo(parameter, param){
    return parameter;
}

function main(){
	let argument;
    foo(argument, 10);
}
```
### 전달인자(Argument)
- 함수 호출시 전달되는 값
- 예제의 argument, 10이 전달인자
### 매개변수(Parameter)
- 함수 호출시 인자를 받아들이는 변수
- 예제의 parameter, param이 매개변수




## Call by Value?

- **전달인자**의 **값(Value)**을 **매개변수**로 복사해서 전달
- 매개변수로 복사해서 전달하기 때문에 함수 내부에서 값을 변경해도 **원본 변경 불가능**

## Call by Address?

- C/C++ 언어의 **포인터**에 해당하는 개념
- **전달인자**의 **주소값(Address)**을 **매개변수**로 복사해서 전달
- 복사된 주소값을 이용해 Call by Reference처럼 주소를 참조하여 **원본 변경 가능**
- 그러나 결국 Call by Value처럼 값을 복사해와서 사용하므로 Call by Reference와 구분함

## Call by Reference?

- C++의 **참조자**에 해당하는 개념
- **별칭(Alias)**이라고도 불림
- **전달인자**의 참조하는 영역에 대해 같은 **참조(Reference)**를 가리키는 **매개변수** 생성
- 같은 영역을 참조하고 있으므로 **원본 변경 가능**



### 그래서 Call by Address와 Call by Reference가 무슨차이?

- 같은 역할을 하고 비슷하게 쓰이니 둘의 차이를 구분하지 않고 Call by Reference로 사용할때가 많음
- 개인적으로 두 개념의 차이는 **참조하는 영역의 변경 가능**이라고 생각함
- Call by Address는 결국 주소값을 포인터 변수에 복사해 와서 쓰기 때문에 내부에서 지역변수 처럼 새로운 주소값을 할당해 사용 가능
- Call by Reference라고 불리는 참조자의 경우 컴파일을 하게 되면 결국 const 포인터로 변경되어 계산됨
- 따라서 둘 모두 원본 변경 가능 하지만 매개변수가 참조하는 영역 변경은 Call by Address만 가능함



### Java의 Reference Type은 어떤 전달방식?

- Java의 객체를 함수의 매개변수로 전달할때 보통 Call by Reference로 오해
- 그러나 정확히는 Call by Value, Call by Address와 유사하게 JVM Stack의 Value를 전달
- 따라서 Java에서는 이를 **Pass By Value**라고 명칭
- Python, JavaScript에서는이와 유사한 방식이지만 **[Call by Sharing](https://github.com/jobhope/TechnicalNote/blob/master/programming_language/call-by-sharing.md)** 이라고 명칭

## Link
[참조에 의한 호출 - 나무위키](https://namu.wiki/w/%EC%B0%B8%EC%A1%B0%EC%97%90%20%EC%9D%98%ED%95%9C%20%ED%98%B8%EC%B6%9C)

[참조블로그](http://blog.naver.com/PostView.nhn?blogId=lee9742&logNo=80157306799&fbclid=IwAR3AoAm7vaOBsHM-_J9V1CUmYVINPkuw2dVwiaa3LQB0sgk1FOF-hcQp3d4)
