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




### READ UNCOMMITED

- **Isolation Level 0**에 해당하며 기본적인 갱신 손실(**Lost Update**)만 방지하는 상태
- UPDATE와 같이 갱신에 대하여 배타적 락을 설정하여 갱신 손실을 방지
- 어떤 트랜잭션이 Commit, Rollback 으로 종료되지 않아도 다른 트랜잭션에서 데이터 참조 가능
- SELECT시 공유 락을 설정하거나 체크하지 않기 때문에 다른 트랜잭션이 갱신하면서 설정한 배타적 락을 무시하고 변경 중인 데이터를 참조하거나(**Dirty Read**), 참조중인 데이터를 변경하는 문제(**Unrepeatable Read**), 추가 삽입 되는 데이터 문제(**Phantom Data Read**) 등이 발생

### READ COMMITED

- **Isolation Level 1**에 해당하며 Level 0의 기능에 추가로 오손 읽기(**Dirty Read**)까지 방지하는 상태
- SELECT와 같이 읽기에 대하여 공유 락을 설정하여 오손 읽기를 방지 
- 단, 공유 락이 트랜잭션이 종료되는 Commit, Rollback 시점까지 유지되는 것이 아닌 SELECT 문이 처리되는 순간만 설정되므로 반복 읽기시 중간에 데이터의 갱신(**Unrepeatable Read**), 삽입(**Phantom Data Read**) 에 의해 문제 발생

### REPETABLE READ

- **Isolation Level 2**에 해당하며 Level 1의 기능에 추가로 비반복적 읽기(**Unrepeatable Read**)까지 방지하는 상태
- 공유 락, 배타적 락을 트랜잭션이 종료될 때 까지 유지하여 비반복적 읽기를 방지
- 이 단계부터 Locking 기법을 활용해도 Lock이 많아지고, MVCC 기법을 활용해도 Undo 영역이 커지면서 성능이 떨어 질 수 있음
- 단, SELECT나 UPDATE 등을 이용해 현재 존재하는 데이터에 대해서만 락을 설정하므로 SELECT 등을 이용해 범위 데이터를 처리 할 때 범위 내에 있으나 존재 하지 않아 락이 걸리지 않은 영역에 데이터가 추가로 삽입(**Phantom Data Read**) 되면 문제 발생

### SERIALIZABLE

- **Isolation Level 3**에 해당하며 Level 2의 기능에 추가로 유령 데이터 읽기(**Phantom Data Read**)까지 방지하는 상태
- SELECT가 이루어지는 범위(테이블)에 공유락을 설정하여 유령 데이터 읽기를 방지
- 최고 단계 고립 수준으로 일관성이 보장되지만 성능이 안좋음
- 따라서 동시성이 중요한 DB에서는 거의 사용하지 않고 낮은 단계의 격리 수준(일반적으로 READ COMMITED)과 함께 어플리케이션 단계에서 낙관적 락(**Optimistic Lock**), 비관적 락(**Pessimistic Lock**)<sup>[3)](#ref)</sup>등을 활용해 처리하는 경우가 많음

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



## 동시성 제어로 발생하는 문제

### 갱신 손실(Lost Update)

- 하나의 트랜잭션이 갱신한 내용을 commit/rollback 하기 전에 다른 트랜잭션이 접근해 덮어씀으로서 **갱신 했던 내용이 사라지는** 것을 의미
- **READ UNCOMMITED** 부터 갱신 손실이 일어나지 않음

| X값 | 트랜잭션1 | 트랜잭션2 |
| :--------: | :---------: | :----------: |
| 10 |   read_item(X) <- 10을 읽음   |  |
| 10 |   X = X - 5 |  |
| 10 |    | read_item(X) <- 10을 읽음 |
| 5 |   write_item(X) |  |
| 5 |    | X = X + 5 |
| 15 |    | **write_item**(**X**) <- 갱신 손실 발생 |



### 오손 읽기(Dirty Read)

- 하나의 트랜잭션이 갱신하려던 내용을 Rollback 하기전에 다른 트랜잭션이 접근해 읽고 처리한 경우 **무효가 된 데이터를 읽는** 것을 의미
- **READ COMMITED**부터 오손 읽기가 일어나지 않음

| X값  |            트랜잭션1            |                        트랜잭션2                         |
| :--: | :-----------------------------: | :------------------------------------------------------: |
|  10  |                                 |                                                          |
|  20  | UPDATE TABLE SET X=20 WHRE id=1 |                                                          |
|  20  |                                 |       SELECT X FROM TABLE WHERE id=1 <- 20을 읽음        |
|  10  |          **ROLLBACK**           |                                                          |
|  10  |                                 | **COMMIT** <- 오손 읽기 발생(무효가 된 X=20을 읽고 완료) |

### 비반복적 읽기(UnRepeatable Read)

- 하나의 트랜잭션이 **반복적으로 동일한 읽기 연산을 실행** 할 때 다른 트랜잭션의 **갱신완료**로 인해 **이전과 다른 결과**가 나오는 것을 의미
- **REPEATABLE READ**부터 비반복적 읽기가 일어나지 않음

| X값  |            트랜잭션1            |                          트랜잭션2                           |
| :--: | :-----------------------------: | :----------------------------------------------------------: |
|  10  |                                 |         SELECT X FROM TABLE WHERE id=1 <- 10을 읽음          |
|  10  | UPDATE TABLE SET X=20 WHRE id=1 |                                                              |
|  20  |           **COMMIT**            |                                                              |
|  20  |                                 | SELECT X FROM TABLE WHERE id=1 <- 20을 읽음<br />(비반복적 읽기 발생) |
|  20  |                                 |                          **COMMIT**                          |

### 유령 데이터 읽기(Phantom Data Read)

- 하나의 트랜잭션이 **범위데이터를 읽을 때** 다른 트랜잭션의 데이터 **삽입완료**로 인해  **이전에 없던 유령 데이터가 나타나는** 것을 의미
- **SERIALIZABLE**부터 유령 데이터 읽기가 일어나지 않음

| count(id)값 |              트랜잭션1               |                  트랜잭션2                   |
| :---------: | :----------------------------------: | :------------------------------------------: |
|      4      |                                      | SELECT count(id) FROM TABLE <- id 1 ~ 4 조회 |
|      4      | INSERT INTO TABLE VALUES (5, 'test') |                                              |
|      5      |              **COMMIT**              |                                              |
|      5      |                                      | SELECT count(id) FROM TABLE <- id 1 ~ 5 조회 |
|      5      |                                      |                  **COMMIT**                  |



### 그 외 문제

- **모순성(Inconsistency)** : 트랜잭션이 동시에 실행되면서 갱신 전의 값, 갱신 후의 값이 실행 순서에 따라 다르게 읽히면서 데이터가 불일치 하는 문제
- **연쇄복귀(Cascading Rollback)** : 트랜잭선이 동시에 실행되면서 같은 데이터를 공유 할 때 해당 데이터에 대해 한 트랜잭션이 commit을 한 결과에 대해 다른 트랜잭션이 rollback을 할 수 없는 문제



## 사전 지식
<a id="lock"></a>

### Lock의 유형

- **공유 잠금(Shared Lock, S Lock)** : Read Lock
- **독점,배타적 잠금(Exclusive Lock, X Lock)** : Write Lock

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

3) [JPA 트랜잭션과 락](http://wonwoo.ml/index.php/post/983)
