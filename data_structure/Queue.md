# **Queue**

## 작성자
[![tdm1223](https://avatars1.githubusercontent.com/u/21440957?s=100&v=4)](https://github.com/tdm1223)
[![rlatjdwo555](https://avatars0.githubusercontent.com/u/28692938?s=100&v=4)](https://github.com/rlatjdwo555)
[![Stupid07](https://avatars1.githubusercontent.com/u/35564566?s=100&v=4)](https://github.com/Stupid07)

## Queue?
- 선입선출 형태의 자료 구조

### Queue의 특징
- 선형 자료 구조 
- 먼저 들어간 것이 먼저 나오는 선입선출 구조(FIFO)

### Queue 활용
- 프로세스 레디 큐
- 스케줄링
- 프린터 출력 처리
- 대기열이 있는 시스템
- 네트워크 패킷 전송시 필요한 버퍼 대기 큐
- javascript의 Event Loop 관리에 필요(비동기 처리)
- Algorithm(**BFS**)

### Queue의 주요 명령어
- enqueue : 맨 뒤에 자료 삽입
- dequeue : 맨 앞에 있는 자료 제거
- peekFront : QUEUE에 있는 맨 앞 자료 반환
- peekRear : QUEUE에 있는 맨 뒤 자료 반환

### Queue의 시간복잡도
- 삽입, 삭제, 조회(Front, Rear) : O(1)

## Queue 구현(Sudo Code)
### 1) 배열로 구현
- 환형 구조가 아닌 배열의 크기만큼만 쓰고 버리는 구조로 작성
```javascript=
TYPE T

Stack{
    T[] queue;
    front = 0;
    rear = 0;

    enQueue(T data){
        array size check;
        queue[rear++]= data;
    }
    
    T deQueue(){
        empty check;
        return queue[front++];
    }
    
    T peekFront(){
        empty check;
        return queue[front];
    }
    
    T peekRear(){
        empty check;
        return queue[rear];
    }
    
    int size(){
        return rear;
    }
}
```

### 2) 리스트로 구현
```javascript=
TYPE T

Node{
    T data;
    Node before;
    Node next;
}

Queue{
    Node front;
    Node rear;
    int size = 0;
    
    enQueue(T data){
        Node newNode = new Node(data, rear, null);
        if rear is not null{
            rear.next = newNode;
        }else{
            front = newNode;
        }
        rear = newNode;
        size++;
    }
    
    T deQueue(){
        front null check;
        T data = front.data;
        front = front.next;
        if front is null{
            rear = null;
        }else{
            front.before = null;
        }
        size--;
        return data;
    }    

    T peekFront(){
        front null check;
        return front.data;
    }
    
    T peekRear(){
        rear null check;
        return rear.data;
    }
    
    int size(){
        return size;
    }
}

```
