# **Call by Sharing**

## 작성자
[![rlatjdwo555](https://avatars0.githubusercontent.com/u/28692938?s=100&v=4)](https://github.com/rlatjdwo555)


## Call by Sharing?
- Python의 함수 인자 전달 방식
- **값**(Value)을 전달하면 **지역 변수로만** 사용한다. (원본 값 변경 되지 않음)
- **객체**(Reference)를 전달하면 **속성의 값은 변경 가능**
- 전달받은 **객체에 새로운 메모리 값의 할당은 불가능**

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
- 변경 불가능 데이터 : 전역 변수, 튜플
- 변경 가능한 객체 : 리스트

## Link
[참고블로그](https://medium.com/@lyhlg0201/call-by-value-reference-sharing-4bbcf94d9808)  
[참고블로그2](https://yes90.tistory.com/47)
