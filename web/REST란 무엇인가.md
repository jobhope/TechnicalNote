# **REST란 무엇인가?**

## 작성자
[![rlatjdwo555](https://avatars0.githubusercontent.com/u/28692938?s=100&v=4)](https://github.com/rlatjdwo555)

## 목차
<sup>[1) REST API의 탄생](#ch1)</sup><br>
<sup>[2) 그래서 REST가 뭔데?](#ch2)</sup><br> 
<sup>[3) REST의 특징](#ch3)</sup><br> 
<sup>[4) REST API 디자인 가이드](#ch4)</sup><br> 
　<sup>[4-1) REST API 중심 규칙](#ch4-1)</sup><br>
　<sup>[4-2) URI 설계 시 주의할 점](#ch4-2)</sup><br>
　<sup>[4-3) HTTP 응답 상태 코드](#ch4-3)</sup><br>   
#

<a id="ch1"></a>
## 1. REST API의 탄생<sup>[1)](#ref1)</sup>
- REST는 Representational State Transfer라는 용어의 약자로서 2000년도에 [로이 필딩 (Roy Fielding)](https://en.wikipedia.org/wiki/Roy_Fielding)의 박사학위 논문에서 최초로 소개되었습니다. 로이 필딩은 HTTP의 주요 저자 중 한 사람으로 그 당시 웹(HTTP) 설계의 우수성에 비해 제대로 사용되어지지 못하는 모습에 안타까워하며 웹의 장점을 최대한 활용할 수 있는 아키텍처로써 REST를 발표했다고 합니다.


<a id="ch2"></a>
## 2. 그래서 REST가 뭔데?
- REST는 일종의 네트워크 아키텍처이다. **자원을 정의하고 정보를 주고 받는 것**. 즉, HTTP URI를 통해 자원(Resource)을 정의하고, 적용된 HTTP Method(GET, POST, PUT, DELETE)에 따라서 Resource를 처리하는 방식을 나타낸다.  

- Resource의 종류에는 이미지, 텍스트, DB정보, Data Object 등이 있다. 

- Http Method 종류에 따른 행위
    - **GET** : 조회(read)
    - **POST** : 생성(create)  
    - **PUT** : 수정(update)
    - **DELETE** : 삭제(delete)
    - **HEAD** : header 정보 조회

- 쉽게 말해 REST는 다음의 구성으로 이루어져 있다.<sup>[1)](#ref1)</sup>
```
자원(Resource) - URI
행위(Verb) - HTTP METHOD
표현(Representations)
```

<a id="ch3"></a>
## 3. REST의 특징
- **Stateless(무상태성)**  
작업을 위한 상태정보를 따로 저장하고 관리하지 않는다. 즉, 세션이나 쿠키정보를 별도로 관리하지 않기 때문에 서버는 단순히 들어오는 요청만 처리하면 된다. 이로 인해서 서비스의 자유도가 높아지고 서버는 불필요한 정보를 관리하지 않기 때문에 구현이 단순해진다. 

- **Cacheable(캐시기능)**  
HTTP 웹 표준을 사용하기 때문에 캐싱 기능을 사용할 수 있다. HTTP 프로토콜 표준에서 사용하는 Last-Modified태그나 E-Tag를 이용하면 캐싱 구현이 가능하다. 

- **Client-Server 구조**  
REST 서버는 API제공, 클라이언트는 사용자 인증이나 세션, 로그인 정보 등을 관리하는 구조로 역할을 구분할 수 있기 때문에 서로간 의존성이 줄어들고 개발해야 할 내용이 명확해진다.

- **호환성**  
HTTP 웹 표준을 사용하기 때문에 HTTP 통신이 가능한 모든 환경에 적용이 가능하다. 

- **계층형 구조**  
REST 서버는 다중 계층으로 구성될 수 있으며 보안, 로드 밸런싱, 암호화 계층을 추가해 구조상의 유연성을 둘 수 있고 PROXY, 게이트웨이 같은 네트워크 기반의 중간매체를 사용할 수 있다.

<a id="ch4"></a>
## 4. REST API 디자인 가이드<sup>[1)](#ref1)</sup>
REST API 설계 시 가장 중요한 항목은 다음의 2가지로 요약할 수 있습니다.
```
첫 번째, URI는 정보의 자원을 표현해야 한다.    

두 번째, 자원에 대한 행위는 HTTP Method(GET, POST, PUT, DELETE)로 표현한다.
```
<a id="ch4-1"></a>
### 4-1. REST API 중심 규칙  

 - URI는 정보의 자원을 표현해야 한다. (리소스명은 동사보다는 명사를 사용)
 
        GET /members/delete/1   (x)

    위와 같은 방식은 REST를 제대로 적용하지 않은 URI입니다. URI는 자원을 표현하는데 중점을 두어야 합니다. delete와 같은 행위에 대한 표현이 들어가서는 안됩니다.  

 - 자원에 대한 행위는 HTTP Method(GET, POST, PUT, DELETE 등)로 표현
위의 잘못 된 URI를 HTTP Method를 통해 수정해 보면

        DELETE /members/1   (o)

    회원정보를 가져올 때는 GET, 회원 추가 시의 행위를 표현하고자 할 때는 POST METHOD를 사용하여 표현합니다.
#


**회원정보를 가져오는 URI**

    GET /members/show/1     (x)
    GET /members/1          (o)

**회원을 추가할 때**

    GET /members/insert/2 (x)  - GET 메서드는 리소스 생성에 맞지 않습니다.
    POST /members/2       (o)


`URI는 자원을 표현하는 데에 집중하고 행위에 대한 정의는 HTTP METHOD를 통해 하는 것이 REST한 API를 설계하는 중심 규칙입니다.`

<a id="ch4-2"></a>
### 4-2. URI 설계 시 주의할 점
1. **슬래시 구분자(/)는 계층 관계를 나타내는 데 사용**

        http://restapi.example.com/houses/apartments
        http://restapi.example.com/animals/mammals/whales

2. **URI 마지막 문자로 슬래시(/)를 포함하지 않는다.**  
URI에 포함되는 모든 글자는 리소스의 유일한 식별자로 사용되어야 하며 URI가 다르다는 것은 리소스가 다르다는 것이고, 역으로 리소스가 다르면 URI도 달라져야 합니다. REST API는 분명한 URI를 만들어 통신을 해야 하기 때문에 혼동을 주지 않도록 URI 경로의 마지막에는 슬래시(/)를 사용하지 않습니다.

        http://restapi.example.com/houses/apartments/ (X)
        http://restapi.example.com/houses/apartments  (0)

3. **하이픈(-)은 URI 가독성을 높이는데 사용**  
URI를 쉽게 읽고 해석하기 위해, 불가피하게 긴 URI경로를 사용하게 된다면 하이픈을 사용해 가독성을 높일 수 있습니다.

4. **밑줄(_)은 URI에 사용하지 않는다.**  
글꼴에 따라 다르긴 하지만 밑줄은 보기 어렵거나 밑줄 때문에 문자가 가려지기도 합니다. 이런 문제를 피하기 위해 밑줄 대신 하이픈(-)을 사용하는 것이 좋습니다.(가독성)

5. **URI 경로에는 소문자가 적합하다.**  
URI 경로에 대문자 사용은 피하도록 해야 합니다. 대소문자에 따라 다른 리소스로 인식하게 되기 때문입니다. 

6. **파일 확장자는 URI에 포함시키지 않는다.**  

        http://restapi.example.com/members/soccer/345/photo.jpg (X)


<a id="ch4-3"></a>
### 4-3 HTTP 응답 상태 코드
잘 설계된 REST API는 URI만 잘 설계된 것이 아닌 그 리소스에 대한 응답을 잘 내어주는 것까지 포함되어야 합니다. 정확한 응답의 상태코드만으로도 많은 정보를 전달할 수가 있기 때문에 응답의 상태코드 값을 명확히 돌려주는 것은 생각보다 중요한 일이 될 수도 있습니다. 혹시 200이나 4XX관련 특정 코드 정도만 사용하고 있다면 처리 상태에 대한 좀 더 명확한 상태코드 값을 사용할 수 있기를 권장하는 바입니다.


## 각주
<a id="ref1"></a>
1)　출처 : [김동범님 포스트](https://meetup.toast.com/posts/92) 


