# **HTTP Cache**

## 작성자
[![rlatjdwo555](https://avatars0.githubusercontent.com/u/28692938?s=100&v=4)](https://github.com/rlatjdwo555)


## HTTP Cahce?
- 브라우저에서 수행하는 캐시
- 브라우저가 웹 페이지 구성요소를 클라이언트의 하드디스크에 저장
- 같은 요소를 재요청할 때, 서버에 요청하지 않고 저장된 것을 보여줌
- 대부분의 브라우저는 `HTTP conditional request`를 사용하여 자동 캐시 기능을 지원
- **`HTTP conditional request`**
    - 브라우저가 서버에 GET요청을 보낼 때, 요청하는 정보를 이미 디스크에 가지고 있을 경우(캐싱) 이 데이터의 변경 여부 확인 요청을 보내는 것
    
    - 서버는 요청된 리소스 본문을 전송하지 않고 304 헤더를 돌려보내며 대역폭을 절약한다. 

## 구현 방법
Response Header에 데이터를 추가하는 방법으로 구현할 수 있다.

### 1. Cache control + Expire
```
Cache-Control: public, max-age=31536000
```
- max-age 시간 동안 브라우저가 캐시를 사용
- 브라우저는 max-age 동안 서버에 요청을 하지 않는다.
- image, css, js 파일 등을 포함
- API의 경우 언제 새로운 데이터가 포함 될지 모르기 때문에 이 방식의 캐싱은 적합하지 않다. 

### 2. Last Modified
- 정보의 마지막 수정 시간을 비교
- DB에서 마지막 수정 시간을 관리하는 경우 부하를 줄일 수 있다.
- 단, Table Join 없이 간단한 데이터의 경우에만 적용 가능. 조인을 하는 경우 모든 테이블에서 수정일을 갖고 있어야 하고 이를 체크하는 쿼리 비용이 많이 소모된다.

```
Last-Modified: Fri, 25 Sep 2019 02:36:33 GMT
```
웹 서버에서 마지막 내용이 변경된 시간을 Response로 주게 되면 브라우저는 이후 동일한 요청에 대해 아래와 같은 Request Header를 추가로 보내게 된다.
```
If-Modified-Since: Fri, 25 Sep 2019 02:36:33 GMT
```
웹 서버는 마지막으로 변경된 시간을 체크하고 아직 안바뀐 경우 304 코드를 리턴하면 브라우저는 캐시 데이터를 사용

**실행 과정**
1. If-Modified-Since보다 이후에 변경된 데이터가 있는지 체크
2. 만약 없다면 304로 바로 리턴
3. 후 변경된 데이터가 있다면 기존과 동일하게 Response데이터를 만들고 Last-Modified를 마지막 변경시간으로 변경


### 3. Etag
- Last-Modified 방식과 거의 유사
- 시간 대신 Response 데이터에 MD5 Hash값을 사용
- DB 부하를 줄일 수는 없지만 Response 시간을 줄일 수 있다.
```
Etag: "15f0fff99ed5aae4edffdd6496d7131f"
```
Response에 다음과 같은 Etag 헤더를 추가해주면 이후 동일한 요청에 대해 Request 헤더에 체크 헤더가 추가된다.
```
If-None-Match: "15f0fff99ed5aae4edffdd6496d7131f"
```
웹 서버는 결과 JSON에 MD5 Hash 값과 If-None-Match의 값을 비교하여 동일하면 304를 리턴, 다르면 200에 결과 JSON을 리턴한다.

**실행 과정**
1. API 핸들러 처리(DB query)
2. 결과 JSON에 MD5 Hash
3. If-None-Match 헤더에 있는 값과 hash값을 비교
4. 만약 동일하다면 304 리턴
5. 다르다면 200에 결과 JSON 리턴

## Link
[참고블로그1](https://medium.com/@bbirec/http-%EC%BA%90%EC%89%AC%EB%A1%9C-api-%EC%86%8D%EB%8F%84-%EC%98%AC%EB%A6%AC%EA%B8%B0-2effb1bfab12)  
[참고블로그2](https://developer.mozilla.org/ko/docs/Web/HTTP/Caching)

