# **트랜잭션 격리 수준(Isolation Level)**

## 작성자
[![Stupid07](https://avatars1.githubusercontent.com/u/35564566?s=100&v=4)](https://github.com/Stupid07)


## 트랜잭션의 격리 수준이란?
- 트랜잭션이 안전하게 수행되기 위해 보장해야하는**ACID**(원자성, 일관성, 고립성, 지속성) 중 **고립성**(Isolation)<sup>[1)](#ref)</sup>에 대하여 성능관련 문제로 인해 유연하게 조절 할 수 있도록 격리 수준을 구분해놓은 것
- 격리 수준이 낮아지면 성능은 향상되지만 **동시성 제어**가 되지 않아 문제가 발생 할 수 있음
- 따라서 DBMS는 다양한 **Lock 기법**(**Locking, timestamp ordering, MVCC**)<sup>[2)](#ref)</sup>을 활용해 트랜잭션 격리 수준에 맞춰 데이터 접근을 통제
- 아래에선 **[2단계 로킹](#lock)** 기법을 활용해 설명



## 격리 수준의 종류와 발생하는 동시성 제어 문제

| 격리 수준 | Lost Update | Dirty Read | Unrepeatable Read| Phantom Data Read |
| :--------: | :---------: | :----------: | :----------: | :----------: |
| **READ UNCOMMITED** | X | O | O | O |
| **READ COMMITTED**  | X | X | O | O |
| **REPEATABLE READ** | X | X | X | O |
| **SERIALIZABLE** | X | X | X | X |

- 격리 수준을 **높일 경우** **성능이 저하**되지만 동시성 제어로 인해 **일관성(Consistency)이 보장됨**
- 격리 수준을 **낮출 경우** **성능은 향상**되지만 동시성 제어에 문제가 생겨 **일관성(Consistency)이 보장되지 않을 수 있음**

### Oracle?

- Oracle은 READ COMMITTED, SERIALIZABLE만 존재
- Default는 READ COMMITTED

```sql
SET TRANSACTION ISOLATION LEVEL SERIALIZABLE;
```



### MySQL?

- InnoDB엔진 사용시 Default는 REPEATABLE READ

```sql
SET SESSION TRANSACTION ISOLATION LEVEL READ COMMITTED;
```



### READ UNCOMMITED

- 

### READ COMMITED

- 

### REPETABLE READ

- 

### SERIALIZABLE

- 





## 동시성 제어로 발생하는 문제

### 갱신 손실(Lost Update)

- 하나의 트랜잭션이 갱신한 내용을 commit/rollback 하기 전에 다른 트랜잭션이 접근해 덮어씀으로서 갱신 했던 내용이 사라지는 것을 의미

| X값 | 트랜잭션1 | 트랜잭션2 |
| :--------: | :---------: | :----------: |
| 10 |   read_item(X) <- 10을 읽음   |  |
| 10 |   X = X - 5 |  |
| 10 |    | read_item(X) <- 10을 읽음 |
| 5 |   write_item(X) |  |
| 5 |    | X = X + 5 |
| 15 |    | **write_item**(**X**) <- 갱신 손실 발생 |



### 오손 읽기(Dirty Read)

- 


### 비반복적 읽기(UnRepeatable Read)

- 


### 유령 데이터 읽기(Phantom Data Read)

- 




### 그 외 문제

- **모순성(Inconsistency)** : 트랜잭션이 동시에 실행되면서 갱신 전의 값, 갱신 후의 값이 실행 순서에 따라 다르게 읽히면서 데이터가 불일치 하는 문제
- **연쇄복귀(Cascading Rollback)** : 트랜잭선이 동시에 실행되면서 같은 데이터를 공유 할 때 해당 데이터에 대해 한 트랜잭션이 commit을 한 결과에 대해 다른 트랜잭션이 rollback을 할 수 없는 문제



## 사전 지식
<a id="lock"></a>

### Lock의 유형

- **공유 잠금(Shared Lock, S Lock)** : Read Lock
- **독점 잠금(Exclusive Lock, X Lock)** : Write Lock

### Lock 호환성 테이블

|       |    S    |  X   |
| :---: | :-----: | :--: |
| **S** | **Yes** |  No  |
| **X** |   No    |  No  |

- Read Lock 끼리는 공유 가능(S Lock이 걸린 데이터에 Read 가능)하나 Write시에는 어떤 Lock도 없어야함
- Write Lock이 걸리면 Read도 불가

### 2단계 로킹

- **확장** 단계 : 항목들에 대해 새로운 Lock을 획득 할 수 있지만 해제할 수 없음
- **수축** 단계 : 이미 보유하고 있는 Lock을 해제할 수 있지만 새로운 Lock을 획득 할 수 없음(commit, rollback 등)
- 교착상태는 검출, 시간초과, 방지 프로토콜 등으로 해소



## Link
[[Database] 8. 트랜잭션, 동시성 제어, 회복](https://mangkyu.tistory.com/30)

[11. Transaction - 트랜잭션](https://movefast.tistory.com/94)

[[MySQL] isolation level 종류 및 특징](https://hyunki1019.tistory.com/111)

## 각주
<a id="ref"></a>

1) **고립성**(**Isolation**) : 트랜잭션을 수행 시 다른 트랜잭션의 연산 작업이 끼어들지 못하도록 보장하는것을 의미

2)  [잠금(Lock)](http://www.jidum.com/jidums/view.do?jidumId=283)
