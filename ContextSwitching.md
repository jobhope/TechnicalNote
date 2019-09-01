# **Context Switching**

## 작성자
[![tdm1223](https://avatars1.githubusercontent.com/u/21440957?s=100&v=4)](https://github.com/tdm1223)

## Context Switching
- 하나의 프로세스가 CPU를 사용 중인 상태에서 다른 프로세스가 CPU를 사용하도록 하기 위해, 사용 중인 프로세스의 상태를 보관하고 새로운 프로세스의 상태를 적재하는 작업을 말한다. <sup>[1)](#ref1)</sup>
- 한 프로세스의 상태는 그 프로세스의 프로세스 제어 블록(PCB)에 기록되어 있다.
- Context Switching 동안에는 다른 작업을 수행할 수 없기 때문에, Context Switching 시간은 오버헤드라고 할 수 있다.

## 진행 과정
1) CPU가 다른 프로세스로 전환하면 시스템은 프로세스의 상태를 PCB에 저장한다.
2) 대기열에서 다음 프로세스를 선택하고 PCB를 복원한다.
3) PCB의 프로그램 카운터가 로드되어 선택한 프로세스에서 실행을 계속 한다.

## 발생 시점
1) 멀티태스킹
    - 멀티 태스킹 환경에서 프로세스가 할당 받은 시간이 종료되어 프로세스가 사용하던 CPU를 다른 프로세스가 사용할 수 있도록 재배정할 때 발생한다.

2) 인터럽트 핸들링
    - CPU가 프로그램을 실행하고 있을 때, 입출력 하드웨어 등의 장치나 또는 예외상황이 발생하여 처리가 필요할 경우에 CPU에게 알려 처리할 수 있도록 하는 것을 말한다.<sup>[2)](#ref1)</sup>

    - context switching을 발생시킬 수 있는 인터럽트
        1. I/O request (입출력 요청)
        2. time slice expired (CPU 사용시간이 만료)
        3. fork a child (자식 프로세스를 만듦)
        4. wait for an interrupt (인터럽트 처리를 기다림)

3) 유저 모드 <-> 커널 모드 전환
    - 운영 체제에서 사용자 모드와 커널 모드 간 전환이 필요한 경우 Context Switching이 필요하지 않다. 
    - 모드 전환은 그 자체로 컨텍스트 스위치가 아니지만 운영 체제에 따라 Context Switching이 발생할 수 있다.

## 각주
<a id="ref1">

1) [Wiki(context switching)](https://en.wikipedia.org/wiki/Context_switch)
2) [Wiki(interrupt)](https://en.wikipedia.org/wiki/Interrupt)
</a>
