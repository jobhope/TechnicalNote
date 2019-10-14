# **Call by Sharing**

## 작성자
[![rlatjdwo555](https://avatars0.githubusercontent.com/u/28692938?s=100&v=4)](https://github.com/rlatjdwo555)
[![Stupid07](https://avatars1.githubusercontent.com/u/35564566?s=100&v=4)](https://github.com/Stupid07)

## Call by Sharing?
- Python, JavaScript 등의 함수 인자 전달 방식(Java에서는 이와 유사한 동작을 하지만 Pass by value<sup>[1)](#ref)</sup>라고 부른다)
- **값**(Value)을 전달하면 복사해서 전달하기 때문에 **지역 변수로만** 사용한다. (원본 값 변경 되지 않음)
- **객체**(Reference)를 전달하면 Mutable한 객체이면 **속성의 값은 변경 가능**
- call by reference와 달리 전달받은 **객체에 새로운 메모리 값의 할당은 불가능**, 내부에서 재정의해서 사용 가능

### 값을 전달하면 지역변수로만 사용
```javascript=
function change(num) {
   num = num * 10;
}

var num = 10;
change(num);

console.log(num);   // 10
```

### 객체를 전달하면 객체의 속성 값은 변경 가능
```javascript=
function change(obj1) {
   obj1.item = "changed";
}

const obj1 = { item: "unchanged" };
change(obj1);

console.log(obj1.item);   // changed
```

### 전달 받은 객체에 새로운 메모리 값의 할당은 불가능
```javascript=
function change(obj2) {
   obj2 = { item2: "changed" };
}

const obj2 = { item: "unchanged" };
change(obj2);

console.log(obj2.item);   // unchanged
```

## in Python
- 변경 가능한(Mutable) 객체 : list, set, dictionary
- 변경 불가능한(Immutable) 객체 : 그 외 모든 객체(bool, int, float, tuple, str, frozenset) - 파이썬은 int, bool등의 모든 값이 객체이다<sup>[2)](#ref)</sup>

## in JavaScript
- 변경 가능한(Mutable) 객체 : 그 외 모든 객체
- 변경 불가능한(Immutable) 객체 : primitive data type (Boolean, null, undefined, Number, String, Symbol) <sup>[3)](#ref)</sup>

## Link
[참고블로그](https://medium.com/@lyhlg0201/call-by-value-reference-sharing-4bbcf94d9808)  
[참고블로그2](https://yes90.tistory.com/47)

## 각주
<a id="ref"></a>
- 1)&nbsp;Java에서는 JVM의 Stack의 Value를 전달하기 때문에 primitive type, reference type의 value를 전달한다는 의미로 pass by value 라고 부르는 것 같다. 
- [2) Mutable vs Immutable Objects in Python](https://medium.com/@meghamohan/mutable-and-immutable-side-of-python-c2145cf72747)
- [3) 객체와 변경불가성(Immutability)](https://poiemaweb.com/js-immutability)
