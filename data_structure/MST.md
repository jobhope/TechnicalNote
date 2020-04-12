# **Minimum Spanning Tree**

## 작성자
[![tdm1223](https://avatars1.githubusercontent.com/u/21440957?s=100&v=4)](https://github.com/tdm1223)

## Spanning Tree(신장 트리)
- 그래프 내의 모든 정점을 포함하는 트리
- 최소 연결 부분 그래프이다.
- DFS, BFS같은 탐색 알고리즘을 이용하여 그래프에서 신장 트리를 찾을 수 있다. (간선 활용)

### 특징
- **하나의 그래프**에는 **여러 개의 신장 트리**가 존재할 수 있다.
- 모든 정점들이 연결 되어 있고, 사이클을 포함하지 않는다.
- **n개의 정점**을 **n-1개의 간선**으로 연결한다.

## Minimum Spanning Tree(최소 신장 트리)
- Spanning Tree 중에서 사용된 간선들의 가중치 합이 최소인 트리

### 특징
- 간선의 가중치의 합이 **최소**이다.
- **하나의 그래프**에는 **여러 개의 최소 신장 트리**가 존재할 수 있다. 
    - 모든 그래프의 간선이 길이가 같다면 모든 spanning tree가 minimum spanning tree가 된다.
- 모든 정점들이 연결 되어 있고, 사이클을 포함하지 않는다.
- **n개의 정점**을 **n-1개의 간선**으로 연결한다.

### 그래프에서 최소 신장 트리를 찾는 알고리즘
1. [Kruskal 알고리즘](https://github.com/jobhope/TechnicalNote/blob/master/algorithm/Kruskal.md)
2. Prim 알고리즘
