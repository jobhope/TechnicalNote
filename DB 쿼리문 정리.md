# **DB 자주 쓰이는 쿼리문 정리**

## 작성자
[![rlatjdwo555](https://avatars0.githubusercontent.com/u/28692938?s=100&v=4)](https://github.com/rlatjdwo555)


## 찾고 싶은 SQL문을 Ctrl+F로 검색

## 쿼리의 수행 순서
- select -> from -> where -> group by -> having -> column -> order by -> limit
- 30, 40, 50번 부서 사원의 업무별 급여 합계와 평균을 구하시오.
  단, 급여가 2000 이상이면서 업무의 최소 급여합계가 1000 이상인 부서만 구합니다.
```
select sum(salary) as totalSum, avg(salary) as '평균 급여'
from employees
where 1 = 1 
and salary >= 2000
and department_id in(30, 40, 50)
group by job_id
having totalSum >= 1000
order by sum(salary) desc
limit 2, 2
```


## SELECT
- 사원 번호가 100인 사원의 모든 정보를 출력하세요.
```
select * from employees where employee_id = 100 
```

## INSERT
```
insert into product(name, inch, price) values('SAM2200', 85, 1580000);
insert into product values('SAM1100', 85, 8900000);
```

## UPDATE
- TV 관련 상품 가격을 20% 인하하여 저장하세요. 그 결과를 출력하세요.
```
update product set price = price-(price*0.2) where type = 'TV';
```

## DELETE
- 사원번호가 100인 사원의 정보를 삭제하세요.
```
delete from employees where employee_id = 100
```

## LIKE
- 이름이 S자로 시작하는 사람의 모든 정보를 검색하세요.
```
select * from emp where ename like 'S%';
```
- 이름 중 S자로 끝나는 사람의 모든 정보를 검색하세요.
```
select * from emp where ename like '%S';
```
- 이름 중 S자가 들어있는 사람의 모든 정보를 검색하세요.
```
select * from emp where ename like '%S%';
```

## null
- 커미션이 null인 사람의 정보를 검색하세요.
```
select * from emp where comm is null;
```

- 커미션이 null이 아닌 사람의 정보를 검색하세요.
```
select * from emp where comm is not null;
```


## 평균(avg), 합계(sum), 최고(max), 최저(min)
- 각 부서별 평균 월급, 전체 월급, 최고 월급, 최저 월급을 구하여 평균 월급이 많은 순으로 검색하세요.
```
select deptno, avg(sal), sum(sal), max(sal), min(sal) from emp
group by deptno
order by avg(sal) desc;
```

## 테이블 정보(desc)
- emp 테이블 정보의 구조를 확인하는 sql을 작성하세요.
```
desc emp
```

## 중복 제거 (distinct)
- 급여의 중복제거
```
select distinct salary from employees
```

## IN, NOT IN
- 부서 번호가 101, 102, 103 인 것들
```
where employee_id in(101, 102, 103);
```

- 부서 번호가 101, 102, 103 이 아닌 것들
```
where employee_id not in(101, 102, 103);
```

## 숫자에서 문자로
```
select cast(123 as char);
```

## 문자에서 숫자로
```
select cast('123' as unsigned);
```

## 문자에서 날짜로
```
select cast('20190410' as date)
       , cast(cast('20190410' as date) as char)
       , 20190410+30
       , date_add(cast(20190410 as date), interval 3 month)
       , date_add(cast(20190410 as date), interval 24 day)
       , date_sub(cast(20190410 as date), interval 24 day);
```


## 날짜 관련 함수
- 입사일이 2014년도인 사람의 모든 정보를 검색하세요
```
select * from emp where extract(YEAR from hiredate) = 2014;
select * from emp where year(hiredate) = 2014;
```


### 분석 함수
```
select ename, sal
       , rank() over(order by sal desc) as '급여 순위'
       , dense_rank() over(order by sal desc) as '순위가 같으면'
       , ntile(5) over(order by sal desc, hiredate) as '그룹 묶기'
       , row_number() over(order by sal desc, hiredate) as 'sequence number'
       , cume_dist() over(order by sal desc)*100 as '전체 백분율'
       , first_value(sal) over(order by sal desc)
       , last_value(sal) over(order by sal desc)
from emp;
```

### 누적 함수
- N-1의 sal만 누적하기 
```
select ename, sal, sum(sal) over(order by sal rows 1 preceding)
from emp;
```

- N+1 sal 누적하기
```
select ename, sal, sum(sal) over(order by sal rows unbounded preceding)
from emp;
```

- N-1, N+1 sal 누적하기
``` 
select ename, sal, sum(sal) over(order by sal rows 
between 1 preceding and 1 following)
from emp;
```

- 자기부터 뒤에있는 것, 앞에있는 것 누적값 = 전체 합계
```
select ename, sal, sum(sal) over(order by sal rows 
between unbounded preceding and unbounded following)
from emp;
```
