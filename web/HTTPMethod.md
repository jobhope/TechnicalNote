# **HTTP Method**

## 작성자
[![tdm1223](https://avatars1.githubusercontent.com/u/21440957?s=100&v=4)](https://github.com/tdm1223)
[![rlatjdwo555](https://avatars0.githubusercontent.com/u/28692938?s=100&v=4)](https://github.com/rlatjdwo555)
[![Stupid07](https://avatars1.githubusercontent.com/u/35564566?s=100&v=4)](https://github.com/Stupid07)

## HTTP Method?
- HTTP 리소스에 필요한 액션을 수행하는 메소드의 집합
- 메소드 자체들이 기능하는 것이 아닌 메소드를 키워드로 액션을 수행

## Method 종류
|   Method    |                                         설명                                          | 캐시 가능 |
|:-----------:|:-------------------------------------------------------------------------------------:|:---------:|
|   **GET**   |                            데이터의 조회에 사용(**READ**)                            |    **YES**    |
|  **POST**   |    데이터의 제출에 사용(**INSERT**) - 서버 사이드에서 이를 활용해서 부가적인 처리     |    **YES**    |
|   **PUT**   |                            데이터를 **UPDATE** 할 때 사용                             |    NO     |
| **DELETE**  |                           데이터의 삭제에 사용(**DELETE**)                           |    NO     |
|  **PATCH**  |                          객체의 일부만 **UPDATE** 할 때 사용                          |    **YES**    |
|  **HEAD**   |                  **GET과 동일**하지만 응답 데이터(BODY)를 받지 않음                   |    **YES**    |
| **OPTION**  |                    서버에서 지원하는 **Method**들을 확인할 때 사용                    |    NO     |
|  **TRACE**  | 원격지 서버에 루프백 메시지 호출하기 위해 테스트용으로 사용(클라이언트가 서버에 요청) |    NO     |
| **CONNECT** |           Client가 Proxy를 통해서 Server와 SSL통신을 하고자 할 때 사용된다.           |    NO     |



