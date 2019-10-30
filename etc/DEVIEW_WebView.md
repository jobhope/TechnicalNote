# 안드로이드 앱의 다중 웹뷰 환경에서 성능 병목 진단 및 최적화 사례

## 웹브라우저 엔진을 탑재한 앱의 웹뷰 사용
- 웹 브라우저 엔진 VS 시스템 웹뷰
    - 엔진 유지 보수 비용 vs API 파편화 이슈 대응
    - 엔진 내장한 앱 크기 증가 vs 버전에 따른 성능 및 기능의 제약

- XWhale
    - Intel의 Crosswalk 프로젝트를 계승
    - 시스템 웹뷰를 대체하고 추가 기능을 제공하는 API 제공
    - 네이버앱, 네이버 카페 적용


## 다중 웹뷰를 활용한 사용자 반응성 개선
- 백그라운드에서 로딩 및 렌더링 수행하여 반응성 개선
- 네이버 페이지는 스왑 페이지를 미리 로딩해 놓는다. 

## 앱 시동시 성능 분석
- Histogram으로 성능 측정

- 다중 웹뷰 생성에 따른 부담
    - 브라우저 엔진 초기화
    - 렌더링 프로세스 생성
    - 웹뷰 생성
    - 웹 페이지 로딩

- 웹 페이지 로딩의 병목 구간
    - CSS parsing
    - Javascript 실행
    - Layout 변동
    - Resource request(이미지 등)에 대한 response 지연


- RAIL 성능모델
    - Response: 사용자 입력으로부터 paint까지 100ms 이내
    - Animation: 각 Farme의 갱신은 16ms 이내
    - Idle : 유휴 시간에 처리할 background task는 50ms 이내
    - Load : First Meaningful Paint(첫 페이지가 완전히 나타난 시간) 100ms 이내

- HTTP Cache의 활용도 및 영향력
    - 캐시 사이즈가 생각보다 빨리 찬다(이미지 다운로드 등)
    - Eviction heuristics의 맹점(LRU time)

- 1~3차 캐시 hit비율을 확인해보니 3시간 간격이었을때가 hit 비율이 높았다

- Http Cache를 사용해보니 네트워크 지연 감소 확인

- 이미지 로딩의 부하
    - 저사양 단말에서 불필요한 고해상도 이미지 로딩
    - 네트워크 전송 및 이미지 decoding에 따른 부담
    - 단말 최적화 이미지 전송(proxy vs client hint)

## 성능 개선 결과
- privileged HTTP Cache구현
    - 지정된 URL패턴의 리소스에 대하여 일정 보존 기간 보장
    - 지정된 referer로 요청된 이미지에 대해 보존 기간 보장
        - third party로부터 API를 통해 유입되는 이미지
        - Resource의 URL만으로 이미지를 판별하기 위해 response의 MIME타입을 확인하여 이미지만 캐시하도록 보장
        
    - 지정된 resource type(js/css)에 대하여 추가 보존 기간 보장

- Low tier device의 성능 80~120ms 개선
- Cross WebView CSS cache 구현
    - Render 프로세스 안에서 모든 WebView가 접근 가능하도록
    - Cross thread map으로 global cache 구현

- CSSruleset은 document와 lifecycle을 함께 하므로
    - Parsing된 ruleset을cache로 복사하여 garbagecollection대상에서 제외
    - 메모리 최적화를 위하여 memorypressure와 연동 및 지정된 URL로 제한

- Proxy 기반 이미지 최적화
    - 이미지 크기를 특정하여 요청하는 API가 필요
    - 현실적으로 메모리 한계점이 존재
    - Data saver역할은 가능

- 이미지 품질과 성능의 접점
    - 서버에서 내려오는 큰 이미지에 대해 리사이징을 하는게 아니라 단말에 맞게 이미지가 실제 픽셀에 비해 낮춰서 오기에 큰 효용이 없다.


    