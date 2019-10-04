# **Reverse Proxy와 Load Balancing**

## 작성자
[![Stupid07](https://avatars1.githubusercontent.com/u/35564566?s=100&v=4)](https://github.com/Stupid07)


## 웹 사이트의 속도를 개선시키기 위한 구조란?
- 매일 대규모 트래픽이 발생하는 웹 서버를 만들어야 하는 상황이라고 하자
- 만약 서버를 **Monolithic architecture**<sup>[1)](#ref1)</sup> 구조로 단일 서버의 형태로 구성했다면, 해당 서버는 사용자들의 요청들을 감당 할 수 없을 것이다.
- 따라서, 같은기능을 하는 서버를 복제하거나, **Micro Service Architecture**<sup>[2)](#ref1)</sup> 구조로 여러 서버의 형태로 구성하는등 여러대의 서버를 구성해야 할 것이다.
- 서버가 여러대 이므로 서버마다 각각의 네트워크 환경이 구성되며 통신을 통해 처리해야한다.
- 그런나 사용자는 네트워크를 통해 Request를 보낼 때 이를 구분하지 않고 하나의 도메인을 통해 하나의 목적지에 보내게 된다.
- 또한, **동일 출처 정책**(Same-origin policy)<sup>[3)](#ref1)</sup>에 의해 Response는 요청한 목적지에서 오는 결과이어야만 한다.
- 따라서 사용자의 요청들을 받아서 어떤식으로 분산해서 처리 할지 결정하고 이를 다시 사용자에게 전달하는 서버가 필요하게 된다.
- 이런 처리를 분산하는 것을 **Load Balancing** 이라고 하며, 이런 분산하는 처리를 담당하는 서버를 **Load Balancer** 라고 한다.
- 그러면 이 **Load Balancing**을 어떤식으로 구현해야 할까?
- 이 방법에는 네트워크 장비를 이용한 처리<sup>[4)](#ref1)</sup>와 **Reverse Proxy**를 이용한 **Load Balancing**서버를 만드는 방법 등이 있다.

## Reverse Proxy란?
![network-diagram-with-drawio](https://user-images.githubusercontent.com/35564566/64080067-b0cc2480-cd2a-11e9-8ab4-0e990d17957c.png)
> 그림은 [draw.io](https://www.draw.io)를 이용했습니다.
- 설명 추가할 예정


### 만약 내부 접속이 API 서버인 경우
- 보통 API 서버와 함께 부하 분산에 나오는 개념이 **API Gateway**이다.
- API 서버의 경우는단순한 부하 분산 외에도 인증, 권한부여, 모니터링, logging 등의 다양한 기능을 필요로 한다.
- 또한, API 서버의 경우 보통 MSA구조로 다양한 서비스들이 분산되어 있어 이를 통합 해서 처리 할 수 있어야한다.
- 이를 위한 MSA구조의 컴포넌트를 **API Gateway**<sup>[7)](#ref1)</sup>라고 한다.

## Load Balancing
- 작성 예정

### DSR
- 

## 참조
- [L4/L7 스위치의 대안, 오픈 소스 로드 밸런서 HAProxy](https://d2.naver.com/helloworld/284659)
- [reverse-proxy-vs-load-balancer](https://www.nginx.com/resources/glossary/reverse-proxy-vs-load-balancer/)

## 각주
<a id="ref1"></a>
- 1) Monolithic architecture : 나중에 글로 추가할 예정
- 2) Micro Service Architecture : 나중에 글로 추가할 예정
- [3) 동일 출처 정책(Same-origin policy)](https://developer.mozilla.org/ko/docs/Web/Security/Same-origin_policy)
- [4) kakao의 L3DSR 구성 사례](https://tech.kakao.com/2014/05/28/l3dsr/)
- [7) 배민 API GATEWAY - spring cloud zuul 적용기](http://woowabros.github.io/r&d/2017/06/13/apigateway.html)

