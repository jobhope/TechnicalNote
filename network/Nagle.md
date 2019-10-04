# **NAGLE 알고리즘**

## 작성자
[![tdm1223](https://avatars1.githubusercontent.com/u/21440957?s=100&v=4)](https://github.com/tdm1223)
[![rlatjdwo555](https://avatars0.githubusercontent.com/u/28692938?s=100&v=4)](https://github.com/rlatjdwo555)
[![Stupid07](https://avatars1.githubusercontent.com/u/35564566?s=100&v=4)](https://github.com/Stupid07)

## NAGLE ?
![nagle](https://user-images.githubusercontent.com/35564566/66195533-c76eee00-e6d1-11e9-8aaa-8e4cfe5994cf.png)

- **조금씩 여러 번 보내지 말고 한번에 많이 보내자** 라는 원칙을 기반으로 만들어진 알고리즘
- TCP에서 옵션값을 통해 on, off 가능하다. (default : on)

### 원리
- 데이터를 보내고 ACK를 받을 때까지 **출력 버퍼**에 데이터를 저장하였다가 ACK를 받으면 버퍼의 데이터를 모두 패킷으로 만들어 보낸다
- **NAGLE**이라는 데이터를 보낼 때 먼저 **N**이라는 데이터를 패킷으로 만들어 보내고, 계속해서 다음 데이터를 보내는 것이 아니라 **출력 버퍼**로 보내어 저장시켜 두고 ACK가 오면 출력버퍼에 저장된 **AGLE**라는 데이터를 보낸다.

### 장점 
- 네트워크의 효율성이 높아진다.
- 같은 데이터를 보내더라도 생성 패킷이 적다.
- 통신을 위한 처리 부하가 줄어든다.

### 단점
- 동시성이 떨어진다.
- ACK를 받을 때까지 패킷을 모으고 있기 때문에 반응 속도가 느려진다.
- 패킷이 전달되지 않았을 때 전송이 굉장히 느려 질 수 있다.

## Link
[참고 블로그](http://egloos.zum.com/depiness/v/772710)
