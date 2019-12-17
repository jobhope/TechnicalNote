# **Clean Code**

## 작성자
[![rlatjdwo555](https://avatars0.githubusercontent.com/u/28692938?s=100&v=4)](https://github.com/rlatjdwo555)

## Clean Code?
- 의도와 목적이 명확한 코드
- **가독성**이 좋은 코드

## 클린코드를 만드는 규칙
### 1. 의미있는 이름(Naming)
- 변수, 클래스, 메소드에 의도가 분명한 이름을 사용한다.
- 잘못된 정보를 전달할 수 있는 이름은 사용하지 않는다.
    - 범용적으로 사용되는 단어를 다른 의미로 사용하지 않는다.(ex: hp, alx, sco 등)
    - 가독성이 떨어지는 문자를 사용하지 않는다.(ex: L, I, 1, 0, o, O)
    - 연속된 숫자 또는 불용어<sup>[1)](#ref1)</sup>를 덧붙이지 않는다.
    - 발음하기 쉬운 이름을 사용한다.

### 2. 명확하고 간결하게 주석달기(Comment)
- 주석은 반드시 달아야 할 이유가 있는 경우에만 사용한다. 코드로 빠르게 유추할 수 있는 내용에는 주석을 사용하지 않는 것이 좋다. 
- 설명을 위한 설명을 달지 않는다.

> 코드로 빠르게 유추할 수 있는 내용에는 주석을 사용하지 않는 것이 좋다.
```java 
// 클래스 Account를 위한 정의
class Acount{
    double profit;
    // 생성자
    public Acount();
    // prifit에 새로운 값을 설정
    void setProfit(double profit){
        this.profit = profit;
    }
    // 이 어카운트의 profit을 반환
    double getPrifit(){
        return this.profit;
    }
}
```

> 주석 내용이 함수 선언과 동일하므로 개선이 필요하다.
```c
//주어진 이름과 깊이를 이용해서 서브트리[h1]에 있는 노드를 찾는다.
Node* FindNodeInSubtree(Node* subtree, String name, int depth);
```
> 함수의 중요한 세부 사항을 주석으로 남기는 것이 좋다.
```c
// 주어진 'name'으로 노드를 찾거나 아니면 NULL을 반환한다.
// 만약 depth <= 0 이면 'subtree'만 검색한다.
// 만약 depth == N 이면 N 레벨과 그 아래만 검색된다.
Node* FindNodeInSubtree(Node* subtree, String name, int depth);
```

### 3. 보기좋게 배치하고 꾸미기(Aesthetics)
- 줄바꿈과 들여쓰기를 이용하여 일관되고 간결한 코드를 작성한다.
- 데이터 자체가 더 간결하게 보일 수 있도록 테이블 구조로 변경한다.
- 코드를 그룹과 계층 구조 방식으로 조작하면 가독성이 향상된다.
- 코드를 문단으로 나눠서 작성한다.

> 일관성 있지만 세로로 길어지고 많은 공백과 반복이 발생
```java 
public class PerformanceTester{
    public TcpConnectionSimulator wifi = 
        new TcpConnectionsSimulator(
            500,   /* Kbps */
            80,    /* millisecs latency */
            200,   /* jitter */ 
            1      /* packet loss % */
        );
    
     public TcpConnectionSimulator t3_fiber = 
        new TcpConnectionsSimulator(
            45000, /* Kbps */
            10,    /* millisecs latency */
            0,     /* jitter */ 
            0      /* packet loss % */
        );
     public TcpConnectionSimulator cell = 
        new TcpConnectionsSimulator(
            100,    /* Kbps */
            400,    /* millisecs latency */
            250,    /* jitter */ 
            5       /* packet loss % */
        );
}
```
> 데이터 자체가 더 간결하게 보일 수 있도록 테이블 구조로 변경
```java 
public class PerformanceTester{
    // TcpConnectionSimulator(throughput, latency, jitter, packet_loss)
    //                          [Kbps]      [ms]    [ms]       [%]

    public TcpConnectionSimulator wifi     = new TcpConnectionSimulator(  500,  80, 200, 1);
    public TcpConnectionSimulator t3_fiber = new TcpConnectionSimulator(45000,  10,   0, 0);
    public TcpConnectionSimulator cell     = new TcpConnectionSimulator(  100, 400, 250, 5);
}
```
> 클래스 전체를 하나의 그룹으로 묶는 것보다 여러 개의 그룹으로 나누는 것이 읽기 좋다.
```java 
Class FrontendServer{
    FrontendServer();
    void ViewProfile(HttpRequest request);
    void OpenDatabase(String location, String user);
    void SavePrifile(HttpRequest request);
    String ExtractQueryParam(HttpRequest request, String param);
    void FindFriends(HttpRequest request);
    void ReplyOK(HttpRequest request, String html);
    void ReplyNotFound(HttpRequest, String error);
    void CloseDatabase(String location);
}
```
```java 
Class FrontendServer{
    FrontendServer();
    
    // Handlers
    void ViewProfile(HttpRequest request);
    void SavePrifile(HttpRequest request);
    void FindFriends(HttpRequest request);
    
    // Request/Reply Utilities
    String ExtractQueryParam(HttpRequest request, String param);
    void ReplyOK(HttpRequest request, String html);
    void ReplyNotFound(HttpRequest, String error);
    
    // Database Helpers
    void OpenDatabase(String location, String user);
    void CloseDatabase(String location);
}
```

### 4. 읽기 쉽게 흐름제어 만들기
- 왼쪽에 변수를, 오른쪽에 상수를 두고 비교한다.
  ```java
  if(length >= 10){...} // (o)
  if(10 >= length){...} // (x)
  ```
- 부정이 아닌 긍정을 다룬다.
  ```java
  if(a == b){
      // 같은 경우
  }
  else{
      // 다른 경우
  }
  
  /* 
    if(a != b){
       // 다른 경우
    }
    else {
       // 같은 경우
    }
   * /
  ```
- if/else를 사용하고 삼항 연산자는 간단한 경우에만 사용한다.
- do/while 루프를 피한다.
- 중첩을 최소화한다.
- 설명 변수와 요약 변수를 이용하여 커다란 표현을 작게 만든다.
  ```java
  final boolean user_owns_document = (request.user.id == document.owner.id);
  
  if(user_owns_document){
      // 사용자가 문서를 수정할 수 있다.
  }
  
  if(!user_owns_document){
      // 사용자가 문서를 수정할 수 없다.
  }
  ```
  
### 5. 착한 함수(Funtion)
- 함수는 가급적 작게, 한번에 하나의 작업만 수행되도록 작성해야 한다.

<br>

# <a id="ref1"></a>
1)　**불용어**(Stopword) : 인터넷 검색 시 검색 용어로 사용하지 않는 단어. 관사, 전치사, 조사, 접속사 등 검색 색인 단어로 의미가 없는 단어이다. 다만 각 검색 엔진마다 동일하지 않기 때문에 다를 수도 있다.
