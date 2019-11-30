# **Short Circuit**

## 작성자
[![tdm1223](https://avatars1.githubusercontent.com/u/21440957?s=100&v=4)](https://github.com/tdm1223)
[![rlatjdwo555](https://avatars0.githubusercontent.com/u/28692938?s=100&v=4)](https://github.com/rlatjdwo555)

## 논리 연산자의 특징
- 논리 연산은 무조건 **왼쪽**부터 시작한다.

## Short Circuit?
- 논리연산자와 조합된 다른 연산식이나 조건식이 생략되는 경우를 말한다.
- 불필요한 연산이 줄어들게 되고 프로그램의 효율이 높아진다.

## 예시
- 아래와 같은 함수 2개가 있다고 가정한다.
```javascript
function A(){ console.log('Call A'); return false; }
function B(){ console.log('Call B'); return true; }
```
### 논리곱
- 논리곱에서는 왼쪽항이 참인 경우에만 오른쪽항의 연산을 수행한다.
- 왼쪽항이 거짓이라면 오른쪽항을 검사하지 않아도 전체 결과는 거짓이 된다.

### 논리곱 예시
```javascript
console.log( A() && B() );
// 함수 호출로 인해 콘솔에 "Call A" 기록
// 그 후 연산자의 결과값인 "false" 기록
```

### 논리합
- 논리합의 경우 논리식들 중 하나만 참이면 참이다.
- 왼쪽항이 참이면 오른쪽항은 검사하지 않아도 논리합의 전체 결과는 참이 된다.

### 논리합 예시
```javascript
console.log( B() || A() );
// 함수 호출로 인해 콘솔에 "Call B" 기록
// 그 후 연산자의 결과인 "true" 기록
```
