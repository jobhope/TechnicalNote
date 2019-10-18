# **HTTP와 HTTPS**

## 작성자
[![tdm1223](https://avatars1.githubusercontent.com/u/21440957?s=100&v=4)](https://github.com/tdm1223)
[![rlatjdwo555](https://avatars0.githubusercontent.com/u/28692938?s=100&v=4)](https://github.com/rlatjdwo555)
[![Stupid07](https://avatars1.githubusercontent.com/u/35564566?s=100&v=4)](https://github.com/Stupid07)

## HTTP
- WWW 상에서 정보를 주고받을 수 있는 **프로토콜** 
- 클라이언트와 서버 사이에 이루어지는 요청/응답 프로토콜이다. 
- 주로 HTML 문서를 주고받는 데에 쓰인다. 
- TCP(HTTP/1, HTTP/2)와 UDP(HTTP/3)를 사용하며, 80번 포트를 사용한다.
- 클라이언트인 웹 브라우저가 HTTP를 통하여 서버로부터 정보를 요청하면, 서버는 이 요청에 응답하여 필요한 정보를 해당 사용자에게 전달한다. 이 정보가 출력 장치(웹 브라우저)를 통해 사용자에게 나타난다.

## HTTPS
- HTTP의 보안상의 문제를 해결하기 위해 등장한 **프로토콜**
- HTTP에 SSL(Secure Socket Layer) 또는 TLS(Transport Layer Security)를 이용해 암호화하여 주고받는다.
- 443번 포트를 사용한다.
- 모든 HTTP 요청과 응답 데이터는 네트워크로 보내지기 전에 전송 계층과 응용 계층 사이에서 암호화된다.
- 통신 패킷을 **Sniffing**<sup>[1)](#ref)</sup>하더라도 정보를 보호 할 수 있다.
- 보안을 위해 사용하는 세션키(대칭키)를 생성 및 교환하는 과정이 필요하다. 이를 **SSL Handshake** 라고 한다.

### SSL Handshake
- SSL Handshake의 핵심은 비대칭키를 이용한 인증과정을 통해 서로 공유하는 대칭키를 생성하는 것이다.
- 이 과정에서 Certificate Authority(CA)<sup>[2)](#ref)</sup>를 통해 서버의 공개키를 확인하게 되고 증명된 사이트의 경우 공개키 서명방식을 이용해 서로 인증하게 된다.

## 참조
- [TLS/SSL Handshake란](https://hanjungv.github.io/2017-11-07-1_CS_SSL/)

## 각주
<a id="ref"></a>
- 1)Sniffing : 네트워크 상에서 다른사람의 패킷 등을 엿보는 보안 공격
- 2)Certificate Authority(CA) : 다른 곳에서 사용하기 위한 디지털 인증서를 발급하는 공인된 회사들이다. 인증 기관들은 공개키 인증서를 발급해준다.
