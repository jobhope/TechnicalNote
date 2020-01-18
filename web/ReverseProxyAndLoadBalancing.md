# **Reverse Proxy와 Load Balancing**

## 작성자

[![Stupid07](https://avatars1.githubusercontent.com/u/35564566?s=100&v=4)](https://github.com/Stupid07)


## 웹 사이트의 속도를 개선시키기 위한 구조란?

- 매일 대규모 트래픽이 발생하는 웹 서버를 만들어야 하는 상황이라고 하자
- 만약 서버를 **Monolithic architecture**<sup>[1)](#ref1)</sup> 구조로 단일 서버의 형태로 구성했다면, 해당 서버는 사용자들의 요청들을 감당 할 수 없을 것이다.
- 따라서, 같은기능을 하는 서버를 복제하거나, **Micro Service Architecture**<sup>[2)](#ref1)</sup> 구조로 여러 서버의 형태로 구성하는등 여러대의 서버를 구성해야 할 것이다.
- 서버가 여러대 이므로 서버마다 각각의 네트워크 환경이 구성되며 통신을 통해 처리해야한다.
- 그런나 사용자는 네트워크를 통해 Request를 보낼 때 이를 구분하지 않고 하나의 도메인을 통해 도메인에 등록된 IP 중 하나의 목적지에 보내게 된다.
- 또한, **동일 출처 정책**(Same-origin policy)<sup>[3)](#ref1)</sup>에 의해 통신하는 하나의 웹 서버 이외에는 다른 서버에서 Response들을 받아 처리할 수 없으므로 **MSA**구조 등을 통해 추가적인 통신이 필요할 경우에 통신하는 웹 서버에서만 전달 해야하는 단점이 있다.(물론,**CORS**<sup>[4)](#ref1)</sup>를 통해 해결 가능하다)
- 따라서 사용자의 요청들을 받아서 어떤식으로 분산해서 처리 할지 결정하고 이를 다시 사용자에게 전달하는 서버가 필요하게 된다.
- 이런 처리를 분산하는 것을 **Load Balancing** 이라고 하며, 이런 분산하는 처리를 담당하는 서버를 **Load Balancer** 라고 한다.
- 그러면 이 **Load Balancing**을 어떤식으로 구현해야 할까?
- 이 방법에는 네트워크 장비를 이용한 처리<sup>[5)](#ref1)</sup>와 **Reverse Proxy**를 이용한 **Load Balancing**서버를 만드는 방법 등이 있다.

## Reverse Proxy란?

![network-diagram-with-drawio](https://user-images.githubusercontent.com/35564566/72659793-a1fbbb00-3a08-11ea-9ccf-386c8d03952b.png)

> 그림은 [draw.io](https://www.draw.io)를 이용했습니다.

- 다양한 Client는 DNS에 등록된 Reverse Proxy IP로 웹 서비스를 요청하고, Reverse Proxy는 내부 네트워크의 대표로서 이 요청을 받아 내부서버에서 처리 후, 다시 Client에게 Reverse Proxy의 IP로 응답하게 된다.
- 이런 웹 서버들의 네트워크를 대표할 수 있는 Proxy를 Reverse Proxy라고 하며, 이는 서버 뿐만이 아니라 스위치 등의 네트워크 장비<sup>[5)](#ref1)</sup>로도 구현 될 수 있다.
- 또한, 이를 활용하면 내부망 뿐만아니라 실제 물리적으로 나뉘어져있는 외부 서버들을 하나의 가상 서버로서 활용 할 수 있다.
- 왜 Reverse Proxy라고 부르는가에 대해 생각하면 보통 Client쪽에 보안, 캐싱 등의 이유로 기업이나 ISP에서 Proxy가 존재하게 되는데 이를 Forward Proxy라고 하며 반대로 웹 서버쪽에 역으로 존재하는 Proxy 라는 뜻으로 생각된다.
- 예를들어 User의 10.20.40.80이 웹 서비스를 요청하는경우
  - User는 DNS에 등록된 IP인 200.100.50.25를 확인하고 200.100.50.25로 HTTP Request를 보내게 된다.
  - 중간에 있는 Reverse Proxy는 이를 수신하고 **Load Balancing**과정을 통해 내부 네트워크의 서버 중 하나를 선택하고 내부 IP인 10.10.10.2에 해당 요청을 전송한다.(Server02로 전송했다고 가정)
  - Server02는 요청에 해당하는 서비스를 처리 후 HTTP Response를 생성한다.
  - 만들어진 Response를 다시 Reverse Proxy에 전송하고, 이를 받은 Reverse Proxy는 다시 자신의 IP인 200.100.50.25의 Response로 변경 후 Client에 보내게 된다.
- 이것이 기본적인 Reverse Proxy의 과정이며 매번 응답마다 다시 Reverse Proxy를 거치는것이 부담이 많이 되어 응답을 직접 내부 Server에서 반환하기 위해 IP, MAC 주소를 변경하여 내부서버에서 Client로 직접 Return하는 방법이 있는데 이것이 **DSR**(Direct Server Return) 이다.


### 만약 내부 접속이 API 서버인 경우

- 보통 API 서버와 함께 부하 분산에 나오는 개념이 **API Gateway**이다.
- API 서버의 경우는단순한 부하 분산 외에도 인증, 권한부여, 모니터링, logging 등의 다양한 기능을 필요로 한다.
- 또한, API 서버의 경우 보통 **MSA**구조로 다양한 서비스들이 분산되어 있어 이를 통합 해서 처리 할 수 있어야한다.
- 이를 위한 MSA구조의 컴포넌트를 **API Gateway**<sup>[6)](#ref1)</sup>라고 한다.

## Load Balancing

- 여러대의 서버로 구조가 분산되어 있을 때 서버들의 부하를 분산하는 처리를 **Load Balancing** 또는 **Server Load Balancing**<sup>[7)](#ref1)</sup> 이라고 한다. 이런 **Load Balancing**을 처리하는 장비를 **Load Balancer**라고 부른다.
- Load Balancing 방법에는 [**CPU Scheduling**](https://github.com/jobhope/TechnicalNote/blob/master/operating_system/CPUScheduling.md)과 유사한 알고리즘을 사용하며 내부적으로도 네트워크의 Layer와 장비의 사용등에 따라 다양한 형태로 존재할 수 있다.
- 일반적으로 알려진 방법은 Round Robin, Least Connections, Source 등의 방법이 있다.
- **Round Robin**
  - 모든 서버에 균일하게 분배하는 방식
  - 장점으로 간단하게 구현이 가능
  - 단점으로 효과적인 부하 분산을 할 수 없음
- **Least Connections**
  - 서버들 중 연결이 가장 적은 서버로 사용자를 분산하는 방식
  - 장점으로 서버의 부하상태를 고려하여 분산하므로 효율적
  - 단점으로 서버의 연결상태를 체크하는 부하와 신규 서버 배치시 신규서버로 과도하게 몰릴 수 있음
- **Source**
  - 사용자의 IP를 Hashing 하여 분배하는 방식
  - 장점으로 사용자는 항상 같은 서버로 연결되는 것을 보장
  - 단점으로 부하 분산이 제대로 안되고 특정 서버로 몰릴 수 있음

### DSR(Direct Server Return)

- 위의 설명에서 내부 웹 서버에서 Client로 직접 응답을 보내는것을 DSR이라고 한다.
- 내부 웹 서버에서 Client로 직접 응답을 보내기 위해서는 웹서버의 IP를 Client에서 요청했던 IP인 Reverse Proxy의 IP로 Response를 보내면 된다.
- 이를 위해 보통 Loopback 주소를 Reverse Proxy의 IP로 변경해서 처리한다. 단, 브로드캐스팅이 안되도록 서브넷마스크 설정을 해줘야한다. 그 외에도 ARP에 응답하지 않도록 설정이 필요하다.
- 또한, 내부 웹 서버까지 Client의 IP가 전달되어야 하는데, 이를 위해 Reverse Proxy를 L7 Server가 아닌 L4 Switch 같은 네트워크 장비를 이용해서 처리하는 편이다.
- 이 때 Reverse Proxy가 내부 웹 서버로 요청을 그대로 전송하기 위해 IP만 변경하면서 처리하는것을 L3DSR, MAC 주소만 변경해서 처리하는것을 L2DSR이라고 부른다.<sup>[5)](#ref1)</sup>

## 참조

- [L4/L7 스위치의 대안, 오픈 소스 로드 밸런서 HAProxy](https://d2.naver.com/helloworld/284659)
- [reverse-proxy-vs-load-balancer](https://www.nginx.com/resources/glossary/reverse-proxy-vs-load-balancer/)
- [로드 밸런서(Load Balancer)란?](https://nesoy.github.io/articles/2018-06/Load-Balancer)

## 각주

<a id="ref1"></a>

- 1) Monolithic architecture : 나중에 글로 추가할 예정
- 2) Micro Service Architecture : 나중에 글로 추가할 예정
- [3) 동일 출처 정책(Same-origin policy)](https://developer.mozilla.org/ko/docs/Web/Security/Same-origin_policy)
- [4) CORS(Cross-Origin Resource Sharing)](https://developer.mozilla.org/ko/docs/Web/HTTP/Access_control_CORS)
- [5) kakao의 L3DSR 구성 사례](https://tech.kakao.com/2014/05/28/l3dsr/)
- [6) 배민 API GATEWAY - spring cloud zuul 적용기](http://woowabros.github.io/r&d/2017/06/13/apigateway.html)
- [7) SLB (Server Load Balancing)](https://ssup2.github.io/theory_analysis/SLB/)
