# **Stack**

## 작성자
[![tdm1223](https://avatars1.githubusercontent.com/u/21440957?s=100&v=4)](https://github.com/tdm1223)
[![rlatjdwo555](https://avatars0.githubusercontent.com/u/28692938?s=100&v=4)](https://github.com/rlatjdwo555)
[![Stupid07](https://avatars1.githubusercontent.com/u/35564566?s=100&v=4)](https://github.com/Stupid07)

## Stack?
- 후입선출 형태의 자료 구조

### Stack의 특징
- 선형 자료 구조 
- 마지막으로 들어간 것이 처음으로 나오는 후입선출 구조(LIFO)

### Stack의 활용
- 함수의 호출에 필요한 메모리 구조
- 인터럽트 루틴 처리
- 후위(Postfix) 표기법으로의 변환 및 연산
- Algorithm(올바른 괄호식인지 판단, 히스토그램)

### Stack의 주요 명령어
- PUSH : TOP에 자료 삽입
- POP : TOP에 있는 자료 제거
- TOP(PEEK) : TOP에 있는 자료 반환

### Stack의 시간복잡도
- 삽입, 삭제, 조회(TOP) : O(1)

## Stack 구현(Sudo Code)
- 배열로 구현하는 방법과 리스트로 구현하는 방법이 존재한다.
- 배열로 구현하는 방법이 비교적 빠르다.(객체 생성 시간 때문에)

### 1) 배열로 구현
```javascript=
TYPE T

Stack{
    T[] stack;
    top = -1;
    
    push(T data){
        array size check;
        stack[++top]= data;
    }
    
    T pop(){
        empty check;
        return stack[top--];
    }
    
    T peak(){
        empty check;
        return stack[top];
    }
    
    int size(){
        return top+1;
    }
}
```

### 2) 리스트로 구현
```javascript=
TYPE T

Node{
    T data;
    Node next;
}

List{
    Node front;
    int size = 0;
    
    addFirst(T data){
        Node newNode = new Node(data, null);
        newNode.next = front;
        front = newNode;
        size++;
    }
    
    T removeFirst(){
        front null check;
        T data = front.data;
        front = front.next;
        size--;
        return data;
    }    

    T peek(){
        front null check;
        return front.data;
    }
    
    int size(){
        return size;
    }
}

Stack{
    List<T> stack;
    
    push(T data){
        stack.addFirst(data);
    }
    
    T top(){
        data = stack.peek();
        return data;
    }
    
    T pop(){
        data = stack.removeFirst();
        return data;
    }
}

```

## 기타
- [스택으로 큐 구현하기](https://github.com/jobhope/TechnicalNote/blob/master/algorithm/%EC%8A%A4%ED%83%9D%EC%9C%BC%EB%A1%9C%20%ED%81%90%20%EA%B5%AC%ED%98%84.md)
