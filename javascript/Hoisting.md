# **Hoisting**

## 작성자
[![Stupid07](https://avatars1.githubusercontent.com/u/35564566?s=100&v=4)](https://github.com/Stupid07)

## Hoisting 이란?

- 기존에 C언어나 Java 언어를 사용해 보았다면 변수를 사용하기 전 **선언 후 사용**하는것에 익숙 할 것이다.
- 만약 사용 후 선언하는 형태로 구현하였다면 컴파일 과정에서 정의되지 않았다고 오류를 출력 할 것이다.
- 특히 C언어의 경우 함수에 대해서도 함수 원형을 위에 선언하지 않는다면 아래서 선언한 함수를 위에서 사용 할 수 없다.
- 만약 JavaScript에서 사용 후 선언하는 형태로 구현한다면 어떤일이 발생할까?

```javascript
printHello(); // hello!
function printHello(){
	console.log("hello!");
};

console.log(num); // undefined
var num = 10;

```

- 무려 오류없는 실행이 되고, 함수 선언의 경우 정상적인 동작을 한다!
- 하지만, 변수의 경우 오류는 없지만 대입한 10의 값이 아닌 `undefined`라는 값을 가지고 있었다.
- 분명히 **모든 코드는 순차적으로 실행**시킨다고 배웠던 것 같은데 어떻게 실행 후 선언이 오류가 나지않고 실행되며, **undefined**는 무엇일까?
- 이렇게 **선언 전에 실행하였으나 함수나 변수가 이미 등록되어 호출할 수 있는 현상**이 바로 **Hoisting** 이며, 이를 이해하기 위해 JavaScript의 실행구조에 대해 알아야한다.



## JavaScript의 실행구조

- V8, Rhino 등 엔진에 따라 구현이 다를 수 있지만 공통적으로 소스코드를 해석해 **실행에 필요한 환경을 구성**하고 이 환경을 **호출 스택**(**Call Stack**)에 쌓으면서 소스코드를 실행하게 된다.
-  이 때, 실행에 필요한 환경을 JavaScript 에서는 **컨텍스트**(**Context**)  또는 **실행 컨텍스트**(**Excution Context**)라고 부른다.
- 전역 환경 또한 전역 컨텍스트 형태로 존재하며, 함수의 호출로 인해 스코프가 다른 환경으로 실행해야할때 컨텍스트를 생성해서 호출 스택에 쌓고 실행하게 된다.
- 컨텍스트의 내부는 크게 **변수 객체**(**Variable Object**), **스코프 체인**(**Scope Chain**), **thisValue** 로 구분 할 수있다.

|     컨텍스트 내부 객체     |                             설명                             |
| :------------------------: | :----------------------------------------------------------: |
| 변수 객체(Variable Object) | 변수, 매개변수와 인자, 함수 선언으로 생성한 함수가 객체의 형태로 존재 |
|  스코프 체인(Scope Chain)  | 해당 컨텍스트에서 참조할 수 있는 객체들을 리스트 형태로 보관 |
|         thisValue          |                 현재 컨텍스트의 this값 할당                  |

> 전역 컨텍스트는 변수 객체에 연결된 전역 객체(Global Object)에 매개변수가 없는 등 조금 다를 수 있음

- 소스코드를 해석하며 이 컨텍스트를 생성하고, 변수 객체에 연결된 활성 객체(Activation Object) 내부에 변수를 선언하고 공간을 할당하게 된다.
- 이 과정에서 변수 또는 함수가 실제 실행되기 전에 이미 변수 객체에 등록되게 되고 그 결과 선언전에 호출해도 오류가 나지않고 호출이 되는 **Hoisting**이 발생하게 된다.
- 변수 선언의 경우 변수 객체에 변수를 등록하는 **선언 단계** 외에도 **undefined** 값으로 초기화되는 **초기화 단계**가 한번에 이루어져서 **undefined** 값을 가지게 된다.
- 함수 선언의 경우 **함수선언**을 통해 생성할때와 다르게 **함수 표현식** 을 사용해서 생성한다면 변수 선언 방식을 따르게 된다. 



#### 클로저(Closure) 란?

- 함수의 호출이 끝나서 호출 스택에서 제거된 컨텍스트에 대해 존재하고 있던 활성 객체(AO)를 계속 유지하며 다른 컨텍스트의 함수에서 참조하여 이 환경을 활용 할 수 있는데 이를 **클로저**(**Closure**)라고 한다.



### 함수 표현식과 Hoisting

- JavaScript에서 함수를 생성할 때 **함수 표현식**을 사용한 방법이 있다. - [함수 선언, 함수표현식](https://github.com/jobhope/TechnicalNote/blob/master/javascript/CreateFunction.md)
- **함수 표현식**을 사용해 함수를 생성한다면, 위에서 **함수 선언** 방식의 결과와 다른 결과가 나온다. 

```javascript
console.log(printHi); // undefined
printHi(); // TypeError: printHi is not a function
var printHi = function(){
    console.log("hi!");
}
```

- 함수를 선언 전에 인식 할 수 없으며, **함수**에 대해서는 **Hoisting**이  이루어지지 않는다.
- 다만, 함수 표현식을 통해 선언한 함수를 대입하는 **변수**는 기존과 마찬가지로 **Hoisting**이 이루어진다. 
- 따라서 이런 **함수 표현식**의 성질을 이용해 **Hoisting**으로 전역 스코프에 불필요한 변수 추가등을 막는 [IIFE](https://developer.mozilla.org/ko/docs/Glossary/IIFE)로 사용되기도 한다.



## 참조

- [실행 컨텍스트와 자바스크립트의 동작 원리](https://poiemaweb.com/js-execution-context)
- [Hoisting](https://developer.mozilla.org/ko/docs/Glossary/Hoisting)
