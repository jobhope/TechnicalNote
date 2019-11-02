# **웹 페이지 속도 개선 방법**

## 작성자
[![rlatjdwo555](https://avatars0.githubusercontent.com/u/28692938?s=100&v=4)](https://github.com/rlatjdwo555)

## In Front-end 

### 1. Code Compression
- js, css 소스코드를 압축
- 용량 감소에 따른 네트워크 패킷 전송 속도 증가

### 2. Image Optimization
- 고해상도 이미지를 device 해상도에 맞게 최적화
- 리사이징, 손실 압축 기법 등이 존재 

### 3. Image Sprite
![CSS Sprite sample](https://user-images.githubusercontent.com/28692938/68067786-a7455400-fd8f-11e9-985f-251adc971dbd.jpg)
```css
<style>
    .up, .down, .right, .left { background: url("/examples/images/img_image_sprites.png") no-repeat; 
    .up { width: 21px; height: 20px; background-position: 0 0; }
    .down { width: 21px; height: 20px; background-position: -21px 0; }
    .right { width: 22px; height: 20px; background-position: -42px 0; }
    .left { width: 22px; height: 20px; background-position: -65px 0; }
</style>
```
- 여러 개의 css 이미지를 하나의 이미지로 합쳐서 관리
- 좌표 값으로 개별 이미지 사용
- 이미지를 로드하기 위한 Server request를 줄일 수 있다.
- 모바일 같이 한정된 자원을 사용하는 플랫폼에서 로딩 시간 개선 가능
- 이미지 파일을 하나로 합쳐서 관리하므로 서버측 용량도 줄일 수 있다.

### 4. Image Lazy Loading
- 웹 페이지에서 이미지의 로딩을 지연 실행
- 이미지 로드 때문에 전체 페이지의 로드가 느려지는 것을 해결하기 위한 방법
<br>

## In Back-end

### 1. [Browser Cache(HTTP Cache)](https://github.com/jobhope/TechnicalNote/blob/master/web/HttpCache.md)
- max-age
- Last Modified
- Etag

### 2. CDN(Content Delivery Network)
- 이미지 저장을 위한 프록시 서버
- 사용자 기준 가장 가까운 곳의 서버로부터 컨텐츠를 전송 받는다.
- 트래픽이 특정 서버에 집중되지 않고 분산되도록 하는 기술
- URL을 통해 로드하는 jquery 같은 경우도 CDN의 개념이라고 할 수 있다.
```javascript
<script src="https://code.jquery.com/jquery-3.2.1.min.js"></script>
```

### 3. [모바일에서 웹 사이트의 속도를 개선 시킬 수있는 AMP](https://github.com/jobhope/TechnicalNote/blob/master/web/AMP%EC%99%80PWA.md)

### 4. DB Index
