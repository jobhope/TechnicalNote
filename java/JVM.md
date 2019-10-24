# **자바가상머신(JVM) 이란?**

## 작성자
[![rlatjdwo555](https://avatars0.githubusercontent.com/u/28692938?s=100&v=4)](https://github.com/rlatjdwo555)


## JVM(Java Virtual Machine)?
- 자바를 실행하기 위해 필요한 가상 머신
- Java Application을 클래스 로더를 통해 읽고 자바 API와 함께 실행
- JAVA와 OS 사이에서 중개자 역할을 하며 OS마다 독립적인 플랫폼으로 JAVA가 실행될 수 있게 해줌

## 자바프로그램 실행과정
1. 프로그램이 실행되면 JVM은 OS로부터 이 프로그램이 필요로 하는 메모리를 할당 받는다.

2. 자바 컴파일러가 소스코드(.java)를 읽어들여 바이트코드로(.class) 변환시킨다.
3. Class Loader를 통해 class파일들을 JVM으로 로딩한다.
4. 로딩된 class파일들은 Execution engine을 통해 해석된다.
5. 해석된 바이트코드는 Runtime Data Areas에 배치되어 실제 수행이 이루어진다. 실행 과정 속에서 필요에 따라 GC작업을 수행한다.


## JVM 구성
### Java Compiler 
- 자바 소스(.java)코드를 바이트 코드(.class)로 변환

### Class Loader
- 컴파일 시점이 아닌 런타임 시점에 동적으로 참조한다. 
- 클래스를 처음으로 참조할 때 해당 클래스를 로드한다. 

### Execution Engine
- 클래스 로더가 로드한 바이트 코드를 실행
- 인터프리터, JIT 총 2가지의 방법을 사용
- **Interpreter**(인터프리터)
    - 자바 바이트 코드를 명령어 단위로 읽어서 실행
    - 한 줄 씩 수행하기 때문에 느리다.
- **JIT**(Just - In - Time)
    - 인터프리터 방식의 단점을 보완하기 위해 도입
    - 인터프리터 방식으로 실행하다가 적절한 시점에서 바이트 코드 전체를 컴파일 후에 네이티브 코드로 변경, 이후에는 해당 부분에서 인터프리팅 하지 않고 네이티브 코드로 직접 실행
    - 네이티브 코드는 캐시에 보관하기 때문에 한 번 컴파일된 코드는 빠르게 수행
    
    - 컴파일 속도가 느리기 때문에 JVM은 내부적으로 해당 메소드가 얼마나 자주 수행되는지 체크하고, 일정 정도를 넘을 때에만 컴파일 수행
    - 한 번만 실행되는 코드라면 컴파일하지 않고 인터프리팅 하는 것이 유리

### Garbage collector
- GC(Garbage Collection)을 수행

## JVM의 메모리 구조(Runtime Data Area)
프로그램을 수행하기 위해 OS에서 할당받은 메모리 공간

### Method Area(Class area, Static area)
- 가장 처음 클래스 정보를 올릴 때 저장되는 메모리 공간
- 클래서 로더에 의해 로딩된 클래스, 메소드, 클래스 변수, 전역변수 등을 저장
- 모든 스레드가 공유
- GC의 관리 대상
- **Runtime Constant Pool** 영역 존재
    - 상수 자료형을 저장하여 실제 메모리 주소를 참조하고 중복을 방지

### Heap
- Runtime에 동적으로 할당되는 데이터를 저장(new 연산자로 생성된 객체, 배열 등)
- GC의 관리 대상

### PC Register
- Thread가 시작될 때 생성되며 스레드마다 하나씩 존재
- 현재 수행 중인 JVM 명령의 주소를 갖는다.

### JVM 스택 영역
- 메소드 호출 시에 임시로 할당되었다가 메소드가 종료되면 소멸(단위 = Frame)
- 매개변수, 지역변수, 리턴 값, 연산 시 발생하는 값을 임시로 저장

### Native method stack
- 컴파일된 바이트 코드가 아닌 실제 실행할 수 있는 기계어로 작성된 프로그램을 실행
- JAVA가 아닌 다른 언어로 작성된 코드를 위한 공간
- JNI(JAVA Native Interface)를 통해 호출하는 C/C++ 등의 코드를 수행

## Link
[참고블로그1](https://asfirstalways.tistory.com/158)  
[참고블로그2](https://minwan1.github.io/2018/06/06/2018-06-06-Java,JVM/)

