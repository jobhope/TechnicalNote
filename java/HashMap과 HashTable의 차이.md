# **HashMap과 HashTable의 차이**

## 작성자
[![rlatjdwo555](https://avatars0.githubusercontent.com/u/28692938?s=100&v=4)](https://github.com/rlatjdwo555)


## 1. 공통점 

- Map 인터페이스를 상속받는다.
- Key-Value 구조를 갖는다.

## 2. 차이점
- **동기화(Synchronization)**
    - Hashtable은 동기화를 지원한다.
    - HashMap은 동기화를 지원하지 않는다.
    - 즉, **멀티 스레드 환경에서는 Hashtable**을 사용해야 한다.
    - HashMap을 동기화 하려면 ConcurrentHashMap을 사용하면 된다.
  
- **속도**
    - HashMap이 다소 속도가 빠르다. Hashtable은 동기화 처리 비용이 있기 때문이다.

- **반환값**
    - HashMap은 저장된 요소들의 순회를 위해 Iterator를 반환한다.
    - Hashtable은 Enumeration을 반환한다.
    - Enumeration과 Iterator는 컬렉션에 저장된 요소를 접근하는데 사용되는 인터페이스이다. Enumeration은 Collection 프레임워크 이전에 사용되던 인터페이스로 Iterator의 사용을 권장한다.


## 참조
- [Odol87 블로그](https://odol87.tistory.com/3)
