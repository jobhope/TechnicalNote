# **DI와 IoC**

## 작성자
[![rlatjdwo555](https://avatars0.githubusercontent.com/u/28692938?s=100&v=4)](https://github.com/rlatjdwo555)

## IoC(Inversion of Control)?
- IoC(제어의 역전)는 객체의 생성이나 소멸에 관련된 생명주기 제어 권한을 컨테이너에게 맡기는 개념이다. 
- 컨테이너가 직접 객체를 관리하기에 DI, AOP를 가능하게 한다.

> 기존에는 객체의 생성을 new Instance 로 정의했다면 Spring에서는 객체를 Bean으로 등록하고 컨테이너가 모든 생명주기를 관리한다.


## DI(Dependency Injection)?
- DI(의존성 주입)은 객체간의 의존성을 외부에서 주입하는 개념이다. 
- Spring 에서는 컨테이너가 Bean 객체들의 의존 관계 연결을 자동으로 수행한다.(@Autowired 등)

> 예를 들어 현재 어플리케이션의 DBMS를 Mysql -> Oracle로 변경하고 싶을 때, DI를 사용하지 않는다면 기존의 Mysql 객체를 주입하는 new Instance 코드를 모두 수정해야 할 것이다.

> 반면에 DI를 이용하면 DB정보를 담고 있는 DataSource 라는 Bean 객체 정보만 바꿔주면서 간단하게 수정이 가능하다. 

### 장점
- 소스 코드의 변경을 최소화한다. 
- 유지보수가 용이하다.
### 단점
- Spring에 종속될 수 있다.
- 웹 서버의 초기 실행 속도가 느려진다. 
