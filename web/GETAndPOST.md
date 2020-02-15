# GET과 POST의 차이

## 작성자
[![rlatjdwo555](https://avatars0.githubusercontent.com/u/28692938?s=100&v=4)](https://github.com/rlatjdwo555)

## GET과 POST
GET과 POST는 HTTP Method의 종류 중 하나이며 Client와 Server가 응답을 주고 받는 형태입니다. 

## GET 방식
GET 방식은 주로 **조회** 기능에 사용됩니다. Client가 Server에 어떤 데이터를 요청할 때 사용합니다. 예를 들어 게시판에 접근할 때 글 목록을 불러오는 방법이 GET 방식 입니다. 이 방식은 데이터를 URL에 포함시켜서 전송하기 때문에 보안성이 낮으며 주로 간단한 데이터 조회에 쓰입니다.   

- URL에 데이터(Parameter)를 포함하여 요청
- URL에 데이터가 노출되어 보안성이 낮음
- 캐싱 가능 

## POST
POST 방식은 주로 **서버의 리소스를 추가하거나 변경할 때** 사용합니다. 예를 들어 게시판의 글 쓰기, 댓글 작성 등이 있습니다. 이 방식은 데이터를 body로 감싸서 보내기 때문에 보안성이 좋으며 객체 값도 전송이 가능합니다.

- URL에 데이터를 노출하지 않아서 보안성이 좋음
- 데이터를 Body에 포함하여 전송
- 캐싱 불가능
