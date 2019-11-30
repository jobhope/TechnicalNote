# **Deque**

## 작성자
[![tdm1223](https://avatars1.githubusercontent.com/u/21440957?s=100&v=4)](https://github.com/tdm1223)
[![rlatjdwo555](https://avatars0.githubusercontent.com/u/28692938?s=100&v=4)](https://github.com/rlatjdwo555)
[![Stupid07](https://avatars1.githubusercontent.com/u/35564566?s=100&v=4)](https://github.com/Stupid07)

## Deque?
- 양쪽 끝에서 삽입과 삭제가 모두 가능한 자료 구조
- Double-ended Queue

### Deque 특징
- 선형 자료 구조 
- Stack(LIFO), Queue(FIFO)처럼 활용이 가능하다.

### Deque의 활용
- Java의 LinkedList, ArrayDeque 라이브러리
- Stack, Queue를 대신해서 활용하거나 앞, 뒤로 삽입, 삭제가 이루어질 때 사용한다.

### Deque의 주요 명령어
- addFirst : head에 자료 삽입
- addLast : tail에 자료 삽입
- removeFirst : head의 자료 제거
- removeLast : tail의 자료 제거
- peekHead : 맨 뒤에 있는 자료 반환
- peekTail : 맨 앞에 있는 자로 반환

### Deque의 시간복잡도
- 삽입, 삭제, 조회(TOP) : O(1)

## Deque 구현(Sudo Code)
- 배열과 리스트로 구현하는 두가지 방법이 존재한다.
- 일반적으로 배열로 구현하는것이 속도가 빠르다.

### 1) 배열로 구현
```javascript
TYPE T

Deque{
    T[] deque;
    head = mid; // 양쪽에서 I/O 발생하기 때문에 중앙 index부터 시작
    tail = mid;
    
    addFirst(T data){
        array size check;
        deque[--head] = data;
    }
    addLast(T data){
        array size check;
        deque[tail++] = data;
    }
    
    T removeLast(){
        empty check;
        return deque[--tail];
    }
    
    T removeFirst(){
        empty check;
        return deque[head++];
    }
    
    T peekHead(){
        empty check;
        return deque[head];
    }
    
    T peekTail(){
        empty check;
        return deque[tail-1];
    }
}
```

### 2) 리스트로 구현
```javascript
TYPE T

Node{
    Node before;
    T data;
    Node next;
}

Deque{
    Node head;
    Node tail;
    int size = 0;
    
    addFirst(T data){
        Node newNode = new Node(data);
        newNode.next = head;
        if head is null{
            tail = newNode;
        }else{
            head.before = newNode;
        }
        head = newNode;
        size++;
    }
    
    addLast(T data){
        Node newNode = new Node(data);
        newNode.before = tail;
        if tail is null {
            head = newNode;
        }else{ 
            tail.next = newNode;
        }
        tail = newNode;
        size++;
    }
    
    T removeFirst(){
        head null check;
        T data = head.data;
        head = head.next;
        size--;
        return data;
    }    

    T removeLast(){
        tail null check;
        T data = tail.data;
        tail = tail.before;
        size--;
        return data;
    }

    T peekHead(){
        head null check;
        return head.data;
    }
    
    T peekTail(){
        tail null check;
        return tail.data;
    }
    
    int size(){
        return size;
    }
}
```
