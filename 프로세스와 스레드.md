# **프로세스와 스레드**

## 작성자
[![tdm1223](https://avatars1.githubusercontent.com/u/21440957?s=100&v=4)](https://github.com/tdm1223)

## 프로세스와 스레드
![process thread](https://user-images.githubusercontent.com/21440957/63943223-27a6ba80-caaa-11e9-8d70-04a1e38c4c5f.png)
### 프로세스
- 하나 이상의 스레드에 의해 실행되는 컴퓨터 프로그램<sup>[1)](#ref1)</sup>
- 운영체제로부터 자원을 할당받는 **작업**의 단위
- 프로세스는 독립된 메모리 영역을 할당받는다.
- 프로세스가 다른 프로세스의 자원에 접근하려면 IPC(프로세스 간의 통신)를 사용해야 한다.

### 스레드
- 프로세스 내에서 실행되는 **흐름**의 단위<sup>[2)](#ref1)</sup>
- 프로세스가 할당받은 자원을 이용하는 **실행**의 단위 

### 프로세스와 스레드의 차이
- 스레드는 각각의 **register**(PC<sup>[3)](#ref1)</sup>)와 **stack**을 가지고 있다.
- 스레드는 프로세스의 **heap**, **static**, **code**, **data** 영역을 공유한다. 
    1) code 영역을 공유하기 때문에 한 프로세스 내부의 스레드들은 프로세스가 가지고 있는 함수를 모두 호출할 수 있다. 
    2) heap, data 영역을 공유하기 때문에 IPC 없이도 **스레드간의 통신**이 가능하다.

## 각주, Link
<a id="ref1">

1) [Wiki](https://en.wikipedia.org/wiki/Process_(computing))
2) [Wiki](https://en.wikipedia.org/wiki/Thread_(computing))
3) 다음번에 실행될 명령어의 주소
</a> 
