# **Kruskal Algorithm**

## 작성자
[![tdm1223](https://avatars1.githubusercontent.com/u/21440957?s=100&v=4)](https://github.com/tdm1223)

## Kruskal Algorithm?
- **탐욕적인 방법**을 이용하여 최소 비용 신장 트리를 구축하는 알고리즘이다.
    - 일반적으로 탐욕적인 방법은 **매 순간 최적의 선택**을 하는것이다.
    - 최적의 선택을 모아 최종 결정을 할때 **전체적인 관점**에서 최종 결정이 최적이라는 보장은 없다.
    - **하지만** Kruskal Algorithm은 최적의 해답을 주는것으로 증명되어 있다!

## Kruskal Algorithm의 흐름
- Kruskal Algorithm의 흐름은 아래와 같다.
- `입력 : 가중치 그래프 G = (V, E), 노드의 개수(n)`
- `출력 : 최소 비용 신장 트리(MST)를 이루는 간선들의 집합`

1. 간선을 가중치 순으로 정렬한다.
2. 간선을 차례대로 선택한다.
3. 간선을 추가했을때 그래프가 cycle을 이루는지 확인한다.
4. cycle을 이룬다면 무시하고 다음 간선을 선택한다.
5. cycle을 이루지 않는다면 해당 간선을 추가한다.

- MST를 구하는 다른 알고리즘에 비하면 간단해 보이지만 간선을 추가했을때 `cycle`여부에 대해 확인하는 작업이 중요하다.

## Union-find 연산
- kruskal algorithm에서만 사용되는것이 아니고 널리 사용되는 방법이다.
- 추가하고자 하는 간선의 양끝 정점이 같은 집합에 속해 있는지 검사할때 사용하는 연산이다.

### Union 연산
- `두 원소`가 속해 있는 `집합`을 입력 받아 `두 집합`의 `합집합`을 만드는 연산이다.

- 다음과 같은 집합이 있다고 가정하자
- `{1}, {2}, {3}, {4}`
- Union(1,4)와 Union(2,3)을 하면 아래와 같이 된다.
- `{1, 4}, {2, 3}`

### Find 연산
- 위 Union 연산을 할때 `find` 연산을 통해 원소가 속해 있는 집합을 찾을 수 있다.

```cpp
// 초기화
int root[MAX_SIZE];
for (int i = 0; i < MAX_SIZE; i++)
{
    parent[i] = i;
}

// Find
int Find(int x)
{
    if (root[x] == x)
    {
        return x;
    }
    else
    {
        return root[x] = find(root[x]);
    }
}

// Union
void Union(int x, int y)
{
    x = find(x);
    y = find(y);
    root[y] = x;
}
```

## Kruskal Algorithm 시간 복잡도
- `Union-find` 연산을 활용 하면 Kruskal Algorithm의 시간 복잡도는 간선들을 정렬하는 시간에 좌우된다.
- 간선 E개를 [퀵 정렬](https://github.com/jobhope/TechnicalNote/blob/master/algorithm/QuickSort.md) 같은 알고리즘으로 정렬한다면 Kruskal Algorithm의 시간 복잡도는 `O(Elog₂E)`가 된다.

## 참고
- C언어로 쉽게 풀어쓴 자료 구조