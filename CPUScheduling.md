# **CPUScheduling**

## 작성자
[![tdm1223](https://avatars1.githubusercontent.com/u/21440957?s=100&v=4)](https://github.com/tdm1223)

## CPU Scheduling
- 실행 준비가 된 프로세스 중에서 그중 하나를 선택해 CPU를 할당하는 것이다.
- CPU Scheduling은 프로세스가 아래와 같은 상황일 때 발생할 수 있다.
    - 실행 상태(running)에서 준비 상태(ready)로 전환 (인터럽트 발생)
    - 대기 상태(waiting)에서 준비 상태(ready)로 전환 (입출력 완료)
    - 준비 상태(ready)에서 실행 상태(running)로 변할 경우 (단기 스케줄링)
    - 실행 상태(running)에서 대기 상태(waiting)로 전환 (입출력 요청, wait)
    - 종료(terminated)

## Scheduling 기법
### 1. First Come First Served (FCFS 또는 FIFO)
- 가장 간단한 비선점 Scheduling 기법이다.
- 레디 큐에 도착한 순서대로 실행한다.
- 장점
    1) 구현이 간단하다.
- 단점
    1) 대기 시간은 도착 순서에 따라 다르다.
    2) 늦게 온 작업에게 불공평하다. (최악의 경우 : 오래 걸리는 프로세스가 먼저 도착)
```
P1 = 24, P2 = 3, P3 = 3일 때
P1, P2, P3 순으로 도착 시 대기시간이 P1 = 0, P2 = 24, P3 = 27이고 평균은 17이 된다.
P2, P3, P1 순으로 도착 시 대기시간이 P1 = 6, P2 = 0, P3 = 0이고 평균은 3이 된다.
```
### 2. Priority Scheduling
- 우선순위가 가장 높은 프로세스부터 할당하는 기법이다.
- 문제
    - 기아 상태 : 우선순위가 낮은 프로세스는 절대로 실행될 수 없는 상황이 발생한다.
- 해결책
    - Aging : 시간이 지날수록 우선순위가 낮은 프로세스의 우선순위를 높인다.

### 3. Round Robin (RR)
- 프로세스가 ready queue를 순환하듯 돌면서 할당 받는 기법이다.
    - 프로세스는 순서대로 CPU의 시간 단위만큼 할당 받는다. (선점 기법)
    - 이 시간이 경과하면 프로세스는 레디 큐의 끝에 추가되고 다음 프로세스가 할당받는다.
- 어떤 프로세스도 (n-1) q 시간 단위를 기다리지 않게 된다.
- 성능
    - 타임 슬라이스 시간을 너무 높게 설정 -> FIFO와 같게 된다.
    - 타임 슬라이스 시간을 너무 낮게 설정 -> Thread 간에 Context switching 하는 데 모든 시간을 소비하게 된다.
- Context switching이 너무 자주 일어나지 않고 모든 생산성을 잃지 않는 한 Context switching시간은 일반적으로 무시할 수 있다.

### 4. Shortest-Job-First(SJF) Scheduling
- CPU 점유 시간이 가장 짧은 프로세스에 CPU를 먼저 할당하는 기법이다.
- 요구 시간이 긴 프로세스가 요구 시간이 짧은 프로세스에게 항상 양보되어 기아 상태가 발생할 수 있다.

### 5. Shortest-Remaining-Time-First (SRTF) Scheduling
- SJF Scheduling을 비선점에서 선점 형태로 수정한 Scheduling기법이다.
- 장점
    - 최적이다.
    - 주어진 프로세스 집합에 대해 최소 평균 대기시간을 제공한다.
- 단점
    - 미래를 예측하기 힘들다.
    - 불공정하다.

### 6. Highest Response Ratio Next(HRRN)
- SJF Scheduling 기법의 약점인 긴 작업과 짧은 작업의 불평등을 보완한 Scheduling 기법이다.
- 비선점형 Scheduling 기법이다.
- 서비스 받을 시간이 분모에 있으므로 짧은 작업의 우선순위가 높아진다.
- 대기 시간이 분자에 있으므로 긴 작업도 대기 시간이 큰 경우에는 우선순위가 높아진다.

![hrn](https://user-images.githubusercontent.com/21440957/64307767-155cdd00-cfd2-11e9-94e2-2a383e7d34bb.JPG)<sup>[1)](#ref1)</sup>
```
대기시간이 P1 = 0 , P2 = 2, P3 = 4이고 서비스 시간이 P1 = 10, P2 = 4, P3 = 9일 때
P1 우선순위 : (0+10)/10 = 1
P2 우선순위 : (2+4)/4 = 1.5
P3 우선순위 : (4+9)/9 = 1.4
우선순위는 P2 -> P3 -> P1 순이다.
```

### 7. Multilevel Feedback Queue(다중 레벨 피드백 큐)
- ready queue를 여러 개로 분리하여 큐 사이에도 우선순위를 부여하는 스케줄링 기법이다.
- 프로세스가 여러 대기열 사이를 이동할 수 있다. 
- 다중 레벨 피드백 큐 구현시 고려사항
    - 대기열 수
    - 각 큐에 대한 Scheduling 알고리즘
    - 프로세스를 업그레이드할 시기를 결정하는 데 사용되는 함수
    - 프로세스를 강등할 시기를 결정하는 데 사용되는 함수
    - 프로세스가 서비스를 필요로 할 때 프로세스가 입력할 큐를 결정하는 데 사용되는 함수
```
Multilevel Feedback Queue의 예
Q1. RR (time quantum = 8)
Q2. RR (time quantum = 16)
Q3. FCFS
```

## 각주, Link
<a id="ref1">

1. [Wiki](https://ko.wikipedia.org/wiki/HRRN_%EC%8A%A4%EC%BC%80%EC%A4%84%EB%A7%81)

</a>
