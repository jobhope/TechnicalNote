# **페이지 교체 알고리즘**

## 작성자
[![tdm1223](https://avatars1.githubusercontent.com/u/21440957?s=100&v=4)](https://github.com/tdm1223)
[![rlatjdwo555](https://avatars0.githubusercontent.com/u/28692938?s=100&v=4)](https://github.com/rlatjdwo555)
[![Stupid07](https://avatars1.githubusercontent.com/u/35564566?s=100&v=4)](https://github.com/Stupid07)

## 페이지 교체 알고리즘의 종류

### Random
- 임의로 페이지를 골라 swap device로 보낸다. (하드웨어적으로 구현)

### FIFO
- 메모리에 **가장 오래 있던 페이지**를 골라 swap device로 보낸다.
- 많이 사용되지만 페이지 교체 정책으로 적절하지 않을 수 있다. -> 중요한 페이지들을 보내 버릴 수도 있기 때문이다.
- 연결 리스트 큐로 만들어 구현한다.
- 메모리를 늘렸음에도 불구하고 페이지 폴트가 더 많이 발생하는 **벨 레이디의 모순** 현상이 나타난다.

### OPT(Optimal)
- **가장 먼 미래 동안 사용되지 않을 페이지**를 골라서 내보낸다.
- 페이지의 로그를 미리 다 알고 있어야 구현이 가능하다. (현실적으로 불가능)

### LRU(Least Recently Use)
- **최근에 최소로 사용된 페이지**를 swap device로 보낸다.
- LRU 알고리즘은 프로그램의 Locality에 기반을 두기 때문에 잘 동작한다.
 
### LFU(Least Frequently Used)
- **사용 빈도가 가장 적은 페이지**를 교체하는 기법이다.
- 활발하게 사용되는 페이지는 사용 횟수가 많아 교체되지 않고 사용된다.
- 프로그램 실행 초기에 많이 사용된 페이지가 그 후로 사용되지 않을 경우에도 프레임을 계속 차지할 수 있다.

### NUR(Not Used Recently)
- LRU와 유사한 알고리즘으로, **최근에 사용하지 않은 페이지**를 교체하는 기법이다.
- 최근의 사용 여부를 확인하기 위해서 각 페이지마다 두 개의 비트, 참조 비트와 변형 비트가 사용된다.
- 참조 비트 : 페이지가 호출되지 않았을 때는 0, 변경되었을 때는 1로 지정된다.
- 변형 비트 : 페이지 내용이 변경되지 않았을 때는 0, 변경되었을 때는 1로 지정된다.

## 예제
### page fault 횟수 구하기
- 1번부터 5번까지의 page가 있고, 실제 사용 순서가 주어졌을 때 page fault
- page frame : 3
- 참조 페이지 리스트 : 1, 2, 3, 1, 3, 4, 1, 2

### FIFO
```
seq   : 1 2 3 4 5 6 7 8
------------------------
frame : 1 1 1 1 1 2 3 4
frame :   2 2 2 2 3 4 1
frame :     3 3 3 4 1 2
------------------------
fault : O O O X X O O O
fault count : 6
```

### LRU
```
seq   : 1 2 3 4 5 6 7 8
------------------------
frame : 1 1 1 2 2 1 3 4
frame :   2 2 3 1 3 4 1
frame :     3 1 3 4 1 2
------------------------
fault : O O O X X O X O
fault count : 5
```
