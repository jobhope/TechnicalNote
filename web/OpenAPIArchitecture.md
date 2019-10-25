# **Open API Architecture**

## 작성자
[![rlatjdwo555](https://avatars0.githubusercontent.com/u/28692938?s=100&v=4)](https://github.com/rlatjdwo555)

## 기본 구조(웹 서버)
![1](https://user-images.githubusercontent.com/28692938/67554171-ca498580-f749-11e9-95e6-a2f346d8a38e.PNG)

- 웹 서버는 컨트롤러의 역할로서 API 비즈니스 서버로부터 데이터를 다양한 뷰(XML, JSON)로 제공하는 역할을 함 
<br>

## 웹 서버 성능 향상
![2](https://user-images.githubusercontent.com/28692938/67554525-8efb8680-f74a-11e9-92a6-bc9f29e9e22c.PNG)
- 웹 서버 증설
- 메모리 캐시 서버 추가
<br>

## API 게이트웨이 서버
![3](https://user-images.githubusercontent.com/28692938/67555248-e0f0dc00-f74b-11e9-940c-2f1db9ee4335.PNG)
- API Gateway는 인증, 데이터 포맷, 로그 관리 등 핵심 컨트롤러 타워 역할
- 다양한 API를 묶어 하나로 제공
- API 트래픽 제어(모니터링) 
- Client에 API 서버 은닉
- 서비스별 API 사용현황 집계(로깅)
<br>

## 핵심 컴포넌트 전체
![4](https://user-images.githubusercontent.com/28692938/67555921-337ec800-f74d-11e9-9e7e-36ad3d12e6f4.PNG)
### API 포털 서버
- 제휴사 정보 관리
- 키 발급
- API 사용 관리
### 인증 서버
- 이용자 식별을 위한 인증 처리
- OAuth 인증
- HMAC 인증
### 통계 서버
- API 이용 로그 데이터 추출
- 통계 데이터 생성(API 대시보드)
### 캐시 서버
- 빠른 서비스 속도를 위한 캐싱
- SNS가 퍼지는 경우 트래픽이 급증 가능
<br>

## Link
[참고자료](http://kosta.or.kr/mail/2014/download/Track3-9_2014Architect.pdf)  


