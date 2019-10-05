# **JOIN의 종류**

## 작성자
[![rlatjdwo555](https://avatars0.githubusercontent.com/u/28692938?s=100&v=4)](https://github.com/rlatjdwo555)


## JOIN?
- 두 개 이상의 테이블을 연결 또는 결합하여 데이터를 출력하는 것
- 조인을 사용하는 이유는 정규화로 인해 분리된 테이블에서 필요한 데이터만 얻기 위함. 

## JOIN의 종류
- INNER JOIN
- OUTER JOIN
- CROSS JOIN
- SELF JOIN
- ANTI JOIN
- SEMI JOIN


## INNER JOIN
- 두 테이블 간의 **공통 속성**(교집합)을 가진 튜플들을 보여준다.
- 표현 방법
    - **EQUI JOIN**(동등조인)
        - 연산자(=)를 사용해서 EQUI JOIN 이라고 부른다.
        ```sql
        SELECT *
        FROM EMPLOYEE, DEPARTMENT
        WHERE EMPLOYEE.DepartmentID = DEPARTMENT.DepartmentID
        ```
        
    - **명시적인 표현**
        - INNER JOIN 표시가 있다면 WHERE 절에서 사용하던 JOIN 조건을 FROM 절에 사용한다는 뜻
        - USING, ON 조건절을 필수적으로 사용
        ```sql
        SELECT *
        FROM EMPLOYEE INNER JOIN DEPARTMENT
        ON EMPLOYEE.DepartmentID = DEPARTMENT.DepartmentID
        ```
    - **USING 조건절**
        - 원하는 컬럼에 대해서만 선택적으로 EQUI JOIN
        - ALIAS나 테이블 이름과 같은 접두사를 사용할 수 없음
        - USING 조건에는 1개 이상의 컬럼을 정의할 수 있음
        ```sql
        SELECT * 
        FROM EMP JOIN DEPT USING(DEPTNO)
        ```
    - **ON 조건절**
        - 컬럼명이 다르더라도 JOIN조건을 사용할 수 있음
        - 테이블이 많이 사용될 경우 가독성이 떨어질 수 있음
        ```sql
        SELECT T.TEAM_NAME, S.STADIUM_ID, S.STADIUM_NAME
        FROM TEAM T JOIN STADIUM S 
        ON(T.STADIUM_ID = S.HOMETEAM_ID);
        -- STADIUM_ID 와 HOMETEAM_ID는 같은 데이터지만 컬럼 이름이 다르다. 
        ```

## OUTER JOIN
- JOIN 조건에서 테이블간에 한 쪽에만 데이터가 있는 경우, 데이터가 있는 테이블 쪽의 모든 내용을 보여주는 것.
- 조인 조건에 만족하지 않아도 해당 행을 출력하고 싶을 때 사용
- USING, ON 조건절을 필수적으로 사용
- 항상 **기준이 되는 테이블이 드라이빙 테이블**이 된다. 드라이빙 테이블에 따라 쿼리의 성능이나 튜닝에 많은 영향을 끼치기 때문에 **데이터 양 보다는 적은 데이터를 추출하는 테이블**을 드라이빙 테이블로 잡는 것이 중요하다.

※**드라이빙 테이블** : JOIN이 발생했을 때 첫번째로 ACCESS되는 테이블

- 표현 방법
    - **LEFT OUTER JOIN**
        - 왼쪽 테이블을 기준으로 데이터를 출력
        - 오른쪽에 null값이 위치 
        ```sql
        SELECT *
        FROM EMP LEFT OUTER JOIN DEPT USING(DEPTNO)
        ```
    - **RIGHT OUTER JOIN**
        - 오른쪽 테이블을 기준으로 데이터를 출력
        - 왼쪽에 null값이 위치 
        ```sql
        SELECT *
        FROM EMP RIGHT OUTER JOIN DEPT USING(DEPTNO)
        ```
    - **FULL OUTER JOIN**
        - LEFT OUTER JOIN과 RIGHT OUTER JOIN 2개의 결과를 합쳐서 출력
        - 중복되는 데이터는 삭제
        ```sql
        SELECT *
        FROM EMP A FULL OUTER JOIN EMP B ON A.MGR = B.EMPNO;
        ```

## CROSS JOIN
- CROSS PRODUCT 라고도 하며 테이블 간 JOIN 조건이 없을 때 생기는 **모든 경우의 수 조합**
- 양 쪽 집합의 N * M 건의 데이터 조합이 발생
```sql
SELECT P.PLAYER_NAME, T.TEAM_NAME
FROM PLAYER P CROSS JOIN TEAM T;
```


## SELF JOIN
- 자가 조인이라고도 하며 같은 두 테이블을 활용하여 데이터를 추출하는 기법
- 예를 들어, EMP 테이블에 각 사원별로 관리자(MGR)가 있을때 사원 정보와 관리자 정보를 함께 확인하기 위해 사용.
```sql
SELECT e.empno, e.ename, e.job, e.hiredate, e.sal, m.empno, m.ename, m.job 
FROM emp E INNER JOIN emp M ON E.mgr = M.empno
```

## ANTI JOIN
- 조인의 대상이 되는 테이블과 일치하지 않는 데이터를 추출하는 조인방식
- 주로 NOT IN, NOT EXISTS 사용시 발생하는 조인 연산이다.
```sql
SELECT count(e1.ename)
FROM myemp1 e1 
WHERE (ename, sal) NOT IN (
                        SELECT ename, sal 
                        FROM myemp1_old e2
                        );
```

## SEMI JOIN
- 조인과 유사하게 데이터를 연결하는 조인 기법
- 분산 질의를 효과적으로 수행하기 위해 사용
- 서브 쿼리를 사용할 때, 메인 쿼리와 연결하기 위해 적용하는 유사 조인을 의미하기도 한다.

```sql
SELECT A.DNAME
FROM DEPT A
WHERE A.DEPTNO IN ( -- OR EXISTS
                SELECT B.EMPNO
                FROM EMP B WHERE B.EMPNO = A.DEPTNO
                );
```


## Link
[참고블로그1](https://limkydev.tistory.com/143)  
[참고블로그2](https://clairdelunes.tistory.com/22)  
[참고블로그3](https://coding-factory.tistory.com/87)  
[참고블로그4](http://ojc.asia/bbs/board.php?bo_table=LecSQLnPlSql&wr_id=390)  
[참고블로그5](https://wisoft.tistory.com/entry/database-sql-join-method)  
[참고블로그6](http://blog.naver.com/PostView.nhn?blogId=typeofb&logNo=221452913670&parentCategoryNo=&categoryNo=39&viewDate=&isShowPopularPosts=true&from=search)

