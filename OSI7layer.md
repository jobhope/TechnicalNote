# **OSI 7 Layer**

## 작성자
[![Stupid07](https://avatars1.githubusercontent.com/u/35564566?s=100&v=4)](https://github.com/Stupid07)

## OSI 7 Layer란?
- 국제 표준화 기구에서 **개방형 시스템 상호 연결을 위한 기초 참조 모델**(Open Systems Interconnection Reference Model)로서 만들어진 계층형 모델이다.<sup>[1)](#ref1)</sup>
- 현재 네트워크 시스템의 기반이 된 모델이며 다양한 시스템의 연결은 이 계층 모델을 기반으로 통신한다.
- 물론, 현재의 인터넷은 각 계층의 역할들이 합쳐지면서 TCP/IP 4 layer 라고도 불리는 계층 모델을 기반으로 한다.
- 또한, 계층모델에 의해 프로토콜도 계층별로 구성된다.

### 왜 계층구조일까?
- 인터넷 뿐만이 아니라 한 시스템과 다른 한 시스템이 통신 하기에는 다양한 규칙들과 장비들을 필요로 하고 이를 위한 복잡한 시스템이 필요하다.
- 이런 크고 복잡한 시스템을 계층구조로 표현하면 잘 정의된 특정 부분을 논의 할 수 있게 된다.
- 이렇게 복잡한 시스템을 계층별로 단순화 하게 됨으로서 계층별로 제공하는 서비스의 구현을 변경하는것도 쉬워진다.
- 계속해서 갱신되는 복잡하고 커다란 시스템에 대해, 시스템의 다른 요소에 영향을 주지 않고 서비스 구현을 변화시키는 능력이 계층구조의 장점이다.
- 따라서 통신영역 외에도 다양한 영역에서 계층 구조를 활용한다.

### 프로토콜이란?
- 둘 이상의 통신 개체 간에 교환되는 메시지 포맷과 순서뿐 아니라, 메시지의 송수신과 다른 이벤트에 따른 행동들을 정의한다.
- 쉽게말하면 메시지를 주고받는 양식, 규칙 또는 **통신 규약**이라고 볼 수 있다.
- 연결된 통로를 통해 시스템간에 메시지를 주고받으려면, 한쪽에서 보낸 메시지를 반대쪽에서 받았을 때 이해 할 수 있어야한다.
- 마치 사람끼리 대화를 할 때 '안녕' 이란 말을 하면 반대쪽에서 '안녕'이란 메시지를 받았고 이는 인사에 해당되어 '안녕' 등의 메시지를 상대방도 보내기 시작한다.
- 이런 메시지를 주고 받을 때 언어와 대화 방법에 대해 암묵적인 규칙이 있기에 의사소통을 할 수 있게 된다.
- 이와같이 통신 모델에서도 상호간의 메시지 규칙들을 정의하게 되고, 계층 모델 형태이다보니 프로토콜도 계층별로 존재하게 된다.

## OSI 7 계층의 구조

|<center>계층</center>|<center>데이터 단위</center>|<center>프로토콜 예제</center>|
|:---:|:---:|:--:|
|<center>7. 응용 계층(**Application Layer**)</center>|<center>message</center>|<center>HTTP, SMTP, FTP, SIP</center>|
|<center>6. 표현 계층(**Presentation Layer**)</center>|<center>message</center>|<center>ASCII, MPEG</center>|
|<center>5. 세션 계층(**Session Layer**)</center>|<center>message</center>|<center>NetBIOS, TLS</center>|
|<center>4. 전송 계층(**Transport Layer**)</center>|<center>segment</center>|<center>TCP, UDP, SCTP</center>|
|<center>3. 네트워크 계층(**Network Layer**)</center>|<center>datagram, packet</center>|<center>IP, ICMP, ARP, RIP, BGP</center>|
|<center>2. 데이터 링크 계층(**Data Link Layer**)</center>|<center>frame</center>|<center>PPP, Ethernet, Token ring</center>|
|<center>1. 물리 계층(**Physical Layer**)</center>|<center>bit</center>|<center>DSL, ISDN</center>|

## 7계층 응용 계층(Application Layer)
- 많은 프로토콜이 존재하는 계층으로서 통신의 최종 목적지이다.
- 응용 프로그램들이 통신으로 활용하는 계층이며 새로운 응용 계층 프로토콜 추가는 굉장히 쉽다.
- 응용 프로그램과 밀접한 관계를 가지는 프로토콜들이 많다.
- 대부분 네트워크를 공부하면서 소켓 프로그래밍을 배우게 되는데 간단한 채팅 프로그램을 만들어봤던 사람들은 서버와 클라이언트간에 주고 받는 규칙들을 정의 해보았을 것이다.
- 그때 정의했던 규칙들 또한 응용 계층의 프로토콜이라고 볼 수 있다.
- 마찬가지로 소켓 프로그래밍으로 HTTP의 규격에 맞는 형태로 메시지를 만들어 보내게 되면 HTTP 통신도 할 수 있다.

## 6계층 표현 계층(Presentation Layer)
- 애플리케이션들이 교환되는 데이터의 의미를 해석하도록 하는 서비스를 제공하는 계층이다.
- 이들 서비스는 데이터가 표현되고 저장되는 내부적인 포멧 뿐만 아니라 데이터 압축과 데이터 암호화를 포함한다.
- 인터넷의 계층구조에는 포함되어 있지 않으며 필요에 따라 응용 계층에서 지원하거나 어플리케이션 개발자가 직접 개발해야한다.

## 5계층 세션 계층(Session Layer)
- 데이터 교환의 경계와 동기화를 제공하는 계층이다.
- 체킹포인트와 회복방법을 세우는 수단을 포함한다.
- 표현 계층과 마찬가지로 인터넷의 계층구조에는 포함되어 있지 않으며 필요에 따라 응용 계층에서 지원하거나 어플리케이션 개발자가 직접 개발해야한다.

## 4계층 전송 계층(Transport Layer)
-

## 3계층 네트워크 계층(Network Layer)
-

## 2계층 데이터 링크 계층(Data Link Layer)
-

## 1계층 물리 계층(Physical Layer)
-


## 참조
- Computer Networking : A Top-Down Approach 6th, James F. Kurose*Keith W. Ross 지음


## 각주
<a id="ref1" href="https://ko.wikipedia.org/wiki/OSI_%EB%AA%A8%ED%98%95"> 1) OSI 모형 wiki </a>

