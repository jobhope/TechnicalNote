# **빅엔디언과 리틀엔디언**

## 작성자
[![tdm1223](https://avatars1.githubusercontent.com/u/21440957?s=100&v=4)](https://github.com/tdm1223)
[![rlatjdwo555](https://avatars0.githubusercontent.com/u/28692938?s=100&v=4)](https://github.com/rlatjdwo555)
[![Stupid07](https://avatars1.githubusercontent.com/u/35564566?s=100&v=4)](https://github.com/Stupid07)

## 엔디언(Endianness)  
- 컴퓨터의 메모리와 같은 1차원의 공간에 여러 개의 연속된 대상을 배열하는 방법을 뜻한다. 
- 바이트를 배열하는 방법을 표현할때는 **바이트 순서**(Byte order)라고 한다.

- `빅엔디언` : 큰 단위가 먼저 나오는 것(MSB<sup>[1)](#ref1)</sup>)
- `리틀엔디언` : 작은 단위가 먼저 나오는 것(LSB<sup>[2)](#ref1)</sup>)
- `미들엔디언` : 몇몇 아키텍처는 2바이트 단위와 1바이트 단위로 서로 다른 순서를 사용한다.

## 바이트 순서에서의 빅엔디언과 리틀엔디언
![big-endian](https://upload.wikimedia.org/wikipedia/commons/thumb/5/54/Big-Endian.svg/300px-Big-Endian.svg.png)
![little-endian](https://upload.wikimedia.org/wikipedia/commons/thumb/e/ed/Little-Endian.svg/300px-Little-Endian.svg.png)

|종류|0x1234의 표현|0x12345678의 표현
|:---:|:---:|:---:|
|빅엔디언|`12 34`|`12 34 56 78`|
|리틀엔디언|`34 12`|`78 56 34 12`|
|미들엔디언|-|`34 12 78 56` <br>or<br> `56 78 12 34`|

- 대부분의 컴퓨터는 **리틀엔디언** 을 사용하며, 네트워크에서는 주소를 **빅엔디언**으로 사용한다.

- 네트워크의 영향으로 많은 프로토콜과 파일들이 **빅엔디언** 방식으로 이루어져 있다.

- **빅엔디언**은 사람이 숫자를 읽는 방식과 동일하기 때문에 디버깅을 편하게 할 수 있으며, 큰 단위가 먼저 나오기 때문에 비교 연산에 있어서 **리틀엔디언** 보다 유리하다.

- **리틀엔디언**은 작은 값부터 처리할 수 있기 때문에 사칙연산에서 **빅엔디언** 보다 유리한 점을 가지고 있다.

## 참조
- [엔디언 wiki](https://ko.wikipedia.org/wiki/%EC%97%94%EB%94%94%EC%96%B8)

## 각주
<a id="ref1"></a>
### 1) MSB(Most Significant Byte)
- 가장 큰 바이트를 가장 앞(또는 왼쪽)에 기록하는 방법
- 소문자 msb는 보통 bit를 의미한다.

### 2) LSB(Least Significant Byte)
- 가장 작은 바이트를 가장 앞(또는 왼쪽)에 기록하는 방법
- 소문자 lsb는 보통 bit를 의미한다.
