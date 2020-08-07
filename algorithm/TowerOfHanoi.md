# **하노이의 탑**

## 작성자
[![tdm1223](https://avatars1.githubusercontent.com/u/21440957?s=100&v=4)](https://github.com/tdm1223)
[![rlatjdwo555](https://avatars0.githubusercontent.com/u/28692938?s=100&v=4)](https://github.com/rlatjdwo555)
[![Stupid07](https://avatars1.githubusercontent.com/u/35564566?s=100&v=4)](https://github.com/Stupid07)

## 하노이의 탑 ?
- 세 개의 기둥에서 규칙을 지키면서 원판을 옮기는 **재귀 알고리즘**의 대표적인 문제이다.

### 규칙
1. 한 번에 하나의 원판만 옮길 수 있다.
2. 큰 원판이 작은 원판 위에 있어서는 안 된다.

## 이동 횟수

### 원판 1개
0. `[1] [] []`
1. `[] [] [1]`
- 1을 옮긴다.

### 원판 2개
0. `[1,2] [] []`
1. `[2] [1] []`
2. `[] [1] [2]`
3. `[] [] [1,2]`
- 1을 빈칸에 옮기고 2를 옮긴후 다시 1을 올린다

### 원판 3개
0. `[1,2,3] [] []`
1. `[2,3] [] [1]`
2. `[3] [2] [1]`
3. `[3] [1,2] []`
4. `[] [1,2] [3]`
5. `[1] [2] [3]`
6. `[1] [] [2,3]`
7. `[] [] [1,2,3]`
- 2를 빈칸에 옮기고 3을 옮긴후 다시 2를 올린다
- 2를 옮길때마다 원판 2개에서의 행동이 필요하다

### 원판 N개
- A<sub>1</sub> = 1
- A<sub>2</sub> = 2 * A<sub>1</sub> + 1
- A<sub>3</sub> = 2 * A<sub>2</sub> + 1`
...
- A<sub>N</sub> = 2*A<sub>N-1</sub>+1 번

### 시간복잡도
1. A<sub>N</sub> = 2<sup>N-1</sup> + 2<sup>N-2</sup> ... + 2 + 1 `[1]`
2. 위 식에서 좌우에 2를 곱한다.
3. 2A<sub>N</sub> = 2<sup>N</sup> + 2<sup>N-1</sup> ... + 2 `[2]`
4. `[2]`에서 `[1]`을 뺀다.
5. A<sub>N</sub> = 2<sup>N</sup>-1

- N개의 원판을 이동할때 필요한 시간 복잡도
- O(2<sup>N</sup>-1)

## 소스코드
### Java
```java
void hanoi(int n, int from, int by, int to){
    if (n == 1){        
        System.out.printf("Move from %d to %d\n", from, to);
        return;
    }

    hanoi(n - 1, from, to, by);
    System.out.printf("Move from %d to %d\n", from, to);
    hanoi(n - 1, by, from, to);
}
```

### C++
```cpp
void hanoi(int n, int from, int by, int to)
{
    if (n == 1)
    {
        cout << "Move from " << from << "to " << to << endl;
    }
    else
    {
        hanoi(n - 1, from, to, by);
        cout << "Move from "<< from << "to "<< to << endl;
        hanoi(n - 1, by, from, to);
    }
}
```

### Python
```python
def hanoi(n, from_pos, to_pos, aux_pos):
    if n == 1:
        print(from_pos, "->", to_pos)
        return
    hanoi(n - 1, from_pos, aux_pos, to_pos)
    print(from_pos, "->", to_pos)
    hanoi(n - 1, aux_pos, to_pos, from_pos)
```
