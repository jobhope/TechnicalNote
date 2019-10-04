# **스택을 어떤 자료구조로 구현하는것이 좋을 것인가?**

## 작성자
[![tdm1223](https://avatars1.githubusercontent.com/u/21440957?s=100&v=4)](https://github.com/tdm1223)
[![rlatjdwo555](https://avatars0.githubusercontent.com/u/28692938?s=100&v=4)](https://github.com/rlatjdwo555)
[![Stupid07](https://avatars1.githubusercontent.com/u/35564566?s=100&v=4)](https://github.com/Stupid07)

## 스택의 특성
- **LIFO** 구조

## 스택을 다양한 자료구조로 구현한다면 ?
### Array
- **top 포인터**로 **index 접근**을 하기 때문에 속도가 **빠르다**.
- 추가적인 **메모리 소모는 없지만** 스택의 **크기가 한정적**이다.
- 크기 확장시 O(n)의 비용이 소모된다.
- push의 시간복잡도 : O(1)
- pop의 시간복잡도 : O(1)
- size의 시간복잡도 : O(1)

### 단방향 LinkedList
- **head 노드**에서 push, pop을 구현하면 O(1)의 시간복잡도가 된다.
- Array에 비해 구현에 추가적인 메모리를 소모하지만 크기를 동적으로 늘릴 수 있다.
- push의 시간복잡도 : O(1)
- pop의 시간 복잡도 : O(1)
- size의 시간 복잡도 : O(N)

### 양방향 LinkedList
- 단방향과 같은 시간복잡도
- 노드 추가시 양방향에 대한 연결 처리 때문에 속도와 메모리 비용이 요구됨.
- push의 시간복잡도 : O(1)
- pop의 시간복잡도 : O(1)
- size의 시간 복잡도 : O(N)

## 그렇다면 어떤 자료구조가 제일 효율적인가?
- 스택의 최대 크기를 확정적으로 알 수 있는 경우 Array를 이용해 구현하는 것이 좋다.
- 일반적으로 크기를 상황에따라 확장 시키기 때문에 Array의 경우 크기 확장시 2배의 비용이 들어 단방향 LinkedList로 구현하는것이 더 효율적이다.
