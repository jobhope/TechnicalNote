# **Insertion Sort(삽입 정렬)**

## 작성자
[![tdm1223](https://avatars1.githubusercontent.com/u/21440957?s=100&v=4)](https://github.com/tdm1223)

## Insertion Sort란?
- 현재 위치에서, 그 이하의 배열들을 비교하여 자신이 들어갈 위치를 찾아, 그 위치에 삽입하는 정렬 알고리즘
- 1개짜리 배열로부터 시작하여 **크기를 하나씩 늘려**나가는 정렬이다.
- 정렬해야될 수가 적을때 quick sort보다 빠른 성능을 내기도 한다.

### Insertion Sort의 시간복잡도
- 시간 복잡도 : O(N<sup>2</sup>), 이미 정렬되어 있는 경우에는 **O(N)**
- 공간 복잡도 : O(N)

## Insertion Sort의 구현
1. 두 번째 인덱스부터 시작한다. 현재 인덱스는 별도의 변수에 저장해주고, 비교 인덱스를 현재 인덱스 -1로 잡는다.
2. 별도로 저장해 둔 삽입을 위한 변수와, 비교 인덱스의 배열 값을 비교한다.
3. 삽입 변수의 값이 더 작으면 현재 인덱스로 비교 인덱스의 값을 저장해주고, 비교 인덱스를 -1하여 비교를 반복한다.
4. 만약 삽입 변수가 더 크면, 비교 인덱스 +1에 삽입 변수를 저장한다.

### C++ Version
```cpp
vector<int> insertionSort(vector<int>& v)
{
    for (int i = 1; i < v.size(); i++)
    {
        int key = v[i];
        // 비교 인덱스
        int j = i - 1;
        
        // 삽입을 위한 변수와 비교 인덱스의 배열 값 비교
        while (j >= 0 && key < v[j])
        {
            swap(v[j], v[j + 1]);
            j--;
        }
        v[j + 1] = key;
    }
    return v;
}
```
