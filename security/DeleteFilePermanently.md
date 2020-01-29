# **파일 완전 삭제**

## 작성자
[![tdm1223](https://avatars1.githubusercontent.com/u/21440957?s=100&v=4)](https://github.com/tdm1223)

## 흔히 아는 파일 삭제
- 파일을 휴지통으로 보내고 휴지통에서 삭제를 할시 아래와 같은 창이 출력된다.
- **예**를 누른다면 파일이 사라지게 된다.

![1](https://user-images.githubusercontent.com/21440957/73357898-ca28cb00-42e0-11ea-85f9-f31f26344ca0.png)

- 그러나 완전 삭제한 줄만 알았던 위 test.txt파일은 **무료 프로그램** 만으로도 복구할 수 있다!

## 왜 why?
### 우리가 아는 하드 디스크 드라이브(HDD)는 아래와 같은 구조로 이루어져 있다.
1. 메타 데이터 영역
    - 메타영역에는 데이터영역에 기록된 파일의 이름, 위치, 크기, 시간정보, 삭제유무 등과 같은 파일에 대한 정보가 저장되어있다. 
    - 메타영역에 저장된 정보를 메타데이터라고 부른다.

2. 데이터 영역
    - 윈도우 탐색기를 통해 확인하는 정보는 메타데이터의 정보만으로 화면에 출력한다. 
    - 탐색기로 메타영역을 탐색하다가 파일을 열었을 경우 메타데이터에서 가리키는 데이터영역에 접근한다. 
    - 데이터영역으로 이동하여 해당 위치부터 순차적으로 파일 데이터를 읽어 처리하게 된다. 
    - 이처럼 파일을 읽고 쓰는 과정에서만 데이터영역에 접근하게 된다.

- 휴지통으로 파일을 지워도 메타 데이터 영역의 데이터만 지워질 뿐 데이터 영역에 존재하는 데이터는 지워지지 않는다!
- 하드디스크에는 삭제라는 개념은 없다. 계속 덮어 쓰기 할 뿐이다.
    - 모든 데이터를 0으로 덧쓰는 방법
    - 임의의 데이터로 덧쓰고 보수로 덧쓰는 방법
    - 랜덤으로 덧쓰는 방법
- 덧쓰는 횟수가 많아질수록 복구 가능성은 낮아지고 :floppy_disk::-1:  소요되는 시간은 길어진다. :alarm_clock: :+1:

## 하드디스크에서 파일을 완전히 삭제하는 방법은 없는걸까?
### 물리적인 방법
- 디가우저를 사용하면 된다. 그러나 이 경우 하드를 다시 쓸수 없게 된다. :sob:

### 소프트웨어적인 방법
- 원하는 구역에 데이터를 **여러 번 덧쓰는 방법**으로 기록된 데이터를 복구가 불가능하게 소거한다.
- 덧쓰는 내용이나 덧쓰는 횟수는 사용한 알고리즘에 따라 다르다.
- 일반적으로는 **3번** 이상 덧씌우는 방법을 사용한다.

#### 완전 삭제 알고리즘 종류
| 알고리즘 | 덮어쓰는 횟수 | 속도 |
|:--------:|:--------:|:--------:|
| Single pass	| 1 | 	매우 빠름|
| British HMG Infosec Standard(IS) 5, Baseline	| 1	| 매우 빠름 |
| Russian GOST R 50739-95 (GOST p50739-95) | 2 | 빠름 |
| British HMG Infosec Standard(IS) 5, Enhanced | 3 | 빠름 |
| NAVSO P-5239-26 (RLL/MFM ; US Navy Standard) | 3 | 빠름 |
| AFSSI-5020 (US Air-Force Standard) | 3 | 빠름 |
| AR380-19 (US Army Standard) | 3 |	빠름 |
| US DoD 5220.22-M(8-306. /E) | 3 | 빠름 |
| NCSC-TG-025 (The National Computer Security Center Standard) | 3 | 빠름 |
| Australian ASCI | 4 | 빠름 |
| NATO Data Destruction Standard | 7 | 보통 |
| US DoD<sup>[1)](#ref1)</sup> 5220.22-M(8-306. /E, C and E) | 7 | 보통 |
| RCMP TSSIT OPS-II (Canadian) | 7 | 보통 |
| US NSA erasure | 7 | 보통 |
| VSITR (German data-destruction standard) | 7 | 보통 |
| Bruce Schneier | 7 | 보통 |
| Gutmann Lite | 10 | 느림 |
| Pfitzner | 33 | 느림 |
| Gutmann (Peter Gutman) | 35 | 매우 느림 |

## 그렇다면 SSD는?
- SSD는 특성상 덧쓰는 것이 불가능 하고 셀을 지울 수 있는 횟수가 한정적이기 때문에 완전삭제를 할 필요가 없다. 
- HDD 완전 삭제 프로그램을 사용하더라도 SSD한테는 쓸모 없는 경우가 대부분이다.

## 각주

<a id="ref1">

1) US Department of Defense

</a>
