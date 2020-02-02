# **RDBMS와 NoSQL의 차이**

## 작성자
[![rlatjdwo555](https://avatars0.githubusercontent.com/u/28692938?s=100&v=4)](https://github.com/rlatjdwo555)

## RDBMS(Relational Database Management System)?
- 관계형 데이터베이스(ex: Oracle, MySQL 등)
- 데이터는 스키마(Schema)로 정의된 테이블에 저장
- 데이터의 효율적인 관리를 위해 테이블간의 관계를 구조화하는 것이 중요
- 시스템이 복잡해질수록 조인 연산으로 인한 성능 이슈 존재 
- 수직적 확장(Scale up) 방식이기 때문에 확장의 한계 발생

## NoSQL(Not Only SQL)?
- 비관계형 모델을 이용한 데이터 저장 방식  
    - **Key-value** 방식(Riak, Redis, Voldmort)
    - **Document** 방식(MongoDB, CouchDB)
    - **BigTable** 방식(Hbase, Casandra)
    - **Graph** 방식(Sones, AllegroGraph)

### 장점
- **분산처리와 병렬처리가 가능**
- 관계 설정이 없기에 설계 비용이 감소
- 수평적 확장(Scale out) 방식으로 비교적 저렴한 비용으로 확장 가능
- **Big Data 처리에 효과적**
- 데이터 모델의 유연한 변화 가능
- Auto Sharding<sup>[1)](#ref1)</sup>을 지원

### 단점
- 복잡한 조인 사용이 어려움
- 데이터의 일관성이 항상 보장되진 않음(중복 데이터 존재 가능) 따라서 중복 저장된 데이터를 똑같이 업데이트 해주는데 시간을 소모
- 데이터 업데이트 중 장애가 발생하면 데이터 손실 발생
- 인덱스 구조를 메모리에 저장하기 때문에 많은 인덱스를 사용하면 충분한 메모리가 필요
<br>

# <a id="ref1"></a>
1) **Sharding** : 하나의 데이터셋을 다수의 DB에 분산시키는 방법. 주로 데이터셋이 단일 DB에 저장하기에는 너무 클 때 사용한다.
