# **URI, URL, URN 개념**

## 작성자
[![rlatjdwo555](https://avatars0.githubusercontent.com/u/28692938?s=100&v=4)](https://github.com/rlatjdwo555)

## URI(Uniform Resource Identifier)
- 인터넷에서 자원을 **식별**하기 위한 문자열이다. URI는 인터넷의 주소 같은 것으로 정보 리소스를 유일하게 식별하고 위치를 지정할 수 있다. 그리고 이 URL의 하위 개념으로 URL, URN이 있다.
    ```
    1) rewrite 기술을 사용한 의미있는 식별자
    >> http://test.com/company/location

    2) REST 서비스
    >> http://test.com/member/jobhope
    ```
- ~~꿀팁~~ : URI > URL 개념이 헷갈리면 URL의 L은 Low로 생각하고 하위 개념이라고 외우자
 
## URL(Uniform Resource Locator)
- 웹에서 자원의 **위치**를 나타낸다. 즉 특정 서버의 한 리소스에 대해 구체적인 위치를 표현한다.  
    ```
    safefood.com 서버에서 food폴더 안의 salad.png를 요청하는 URL
    >> http://safefood.com/food/salad.png
    ```
    
## URN(Uniform Resource Name)
- 어떤 리소스가 있을 때 해당 리소스의 위치에 영향을 받지 않는 고유한 이름 역할을 한다. 

- URN은 URL의 한계로 인해 나오게 되었다. URL은 주소이지 실제 이름이 아니다.
    ```
    변경 전 : http://safefood.com/food/20
    변경 후 : http://safefood.com/food/korea/20
    ```
    만약 위와 같이 URL이 바뀌었다면 변경 전 URL로 접근했을 때 페이지를 찾을 수 없게 된다. 이런 문제를 해결하기 위해 객체의 위치와 상관없이 실제 객체를 가리키는 이름을 사용하기 위해 등장하게 되었다. 

- URN은 아직 표준이 되지 않아 아직은 접할 기회가 별로 없다.
