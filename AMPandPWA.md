# **AMP와 PWA**

## 작성자
[![Stupid07](https://avatars1.githubusercontent.com/u/35564566?s=100&v=4)](https://github.com/Stupid07)

## AMP(Accelerated Mobile Page)란?
- Google이 시작한 웹 페이지를 더 빠르게 렌더링하기 위한 방법들이다.
- AMP HTML과 AMP JS를 활용한 웹 페이지를 제작시, 구글의 cdn 서버에서 동적 서비스들을 캐싱해둠으로서 웹 페이지의 성능을 개선 할 수 있다.
- 다만, AMP를 활용하기 위해서는 외부 Javascript, css등을 적용하지 못하는 등의 속도에 영향을 줄 수 있는 요소들에 제약사항이 있다.
- 따라서 모바일 전용 페이지를 만들 필요성이 생기는 등의 단점들로 인해 필요한 웹 페이지에 적용 하는 것이 중요하다.<sup>[1)](#ref1)</sup>

## PWA(Progressive Web Apps)란?
- 웹을 통해서 네이티브 앱과 유사한 환경을 모바일 및 데스크톱에 제공하는 웹 앱 이다.
- 현재는 모든 모던 브라우저가 이 기능을 지원 하고 있어서 PWA 구현에 필요한 요소만 갖춘다면 웹 앱을 구현 할 수 있다.<sup>[2)](#ref1)</sup>
- PWA로 식별되기 위한 핵심 원칙들<sup>[3)](#ref1)</sup>을 지켜야하며 이를 위해 필요한 기술들이 크게 3가지가 있다.<sup>[4)](#ref1)</sup>
  - ### HTTPS
    - PWA는 네이티브 앱과 유사한 환경을 제공하기 위해 운영체제의 권한들을 일부 부여받는다.
    - 따라서 보안연결은 필수 이다보니 HTTP 프로토콜이 아닌 HTTPS 프로토콜을 사용해야한다.
   - ### Web App Manifest
    - 사이트와 관련된 정보를 앱의 기본요소인 manifest 파일에 JSON형태로 기록해야한다.
   - ### Service Worker
    - PWA를 구성하는 핵심 기술로서 브라우저에서 사용하던 기술이다.
    - 이 기술을 활용해 오프라인에서도 캐싱을 활용해 앱을 실행 시킬 수 있다.
   - 그 외 기술들<sup>[5)](#ref1)</sup>
  
## 그래서 왜 AMP, PWA?
- 웹의 발전과 함께 사용자들은 더 빠른, 더 좋은 웹 서비스를 원해왔다.
- 또한, 웹의 이용이 데스크톱 뿐만 아니라 모바일 환경으로 넘어왔다.
- 따라서 모바일 환경에서 더 빠르게 렌더링 할 수 있는 AMP와 더 편하게 접근 할 수 있는 PWA는 사용자들을 더 편하게 할 것이다.

## 참조
- [AMP는 어떻게 웹 페이지의 성능을 높일 수 있나](https://d2.naver.com/helloworld/6856597)
- [NAVER Tech Talk: 구글 AMP, PWA 소개](https://d2.naver.com/news/8185757)
- [빠른 웹을 위한 오픈소스 프로젝트 - AMP](https://brunch.co.kr/@sangjinkang/10)

## 각주
<a id="href1"></a>
- [1)나는 AMP를 좋아하지 않는다.](https://blog.outsider.ne.kr/1285)
- [2)2018년과 이후 JavaScript의 동향 - 브라우저 밖의 JavaScript[PWA 부분]](https://d2.naver.com/helloworld/5644368)
- [3)프로그레시브 웹 앱이 무엇인가요?](https://developer.mozilla.org/ko/docs/Web/Progressive_web_apps/%EC%86%8C%EA%B0%9C)
- [4)웹-프로젝트는-pwa이어야-한다1](https://webactually.com/2017/09/%EC%9B%B9-%ED%94%84%EB%A1%9C%EC%A0%9D%ED%8A%B8%EB%8A%94-pwa%EC%9D%B4%EC%96%B4%EC%95%BC-%ED%95%9C%EB%8B%A41/)
- [5)pwa를-구성하는-기술들](https://medium.com/@euncho/pwa%EB%A5%BC-%EA%B5%AC%EC%84%B1%ED%95%98%EB%8A%94-%EA%B8%B0%EC%88%A0%EB%93%A4-a5be57df5575)
