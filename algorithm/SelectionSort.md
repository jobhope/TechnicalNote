# **Selection Sort(선택 정렬)**

## 작성자
[![tdm1223](https://avatars1.githubusercontent.com/u/21440957?s=100&v=4)](https://github.com/tdm1223)

## Selection Sort란?
- 해당 순서에 원소를 넣을 위치는 이미 정해져 있고, 어떤 원소를 넣을지 선택하는 정렬 알고리즘
- 알고리즘이 단순하며 사용할 수 있는 메모리가 제한적인 경우에 성능 상의 이점이 있다.

### Selection Sort의 시간복잡도
- 시간 복잡도 : O(N<sup>2</sup>). (전체 비교를 진행)
- 공간 복잡도 : O(N)

## Selection Sort의 구현
1. 정렬되지 않은 인덱스의 맨 앞에서부터, 이를 포함한 그 이후의 배열 값 중 가장 작은 값을 찾아간다.
2. 가장 작은 값을 찾으면, 그 값을 현재 인덱스의 값과 바꿔준다.
3. 다음 인덱스에서 위 과정을 반복해준다.

### C++ Version
```cpp
vector<int> selectionSort(vector<int>& v)
{
	for (int i = 0; i < v.size() - 1; i++)
	{
		int tmp = i; // i를 포함하여 I번째부터 끝까지 배열 값 중 가장 작은 값을 찾는다.
		for (int j = i + 1; j < v.size(); j++)
		{
			if (v[tmp] > v[j])
			{
				tmp = j;
			}
		}
		swap(v[i], v[tmp]); // 가장 작은 값을 현재 인덱스의 값과 바꿔준다.
	}
	return v;
}
```

### JAVA Version
```java
void selectionSort(int[] list) {
    for (int i = 0; i < list.length - 1; i++) {
        int tmp = i; // i를 포함하여 I번째부터 끝까지 배열 값 중 가장 작은 값을 찾는다.
        for (int j = i + 1; j < list.length; j++) {
            if (list[j] < list[tmp]) {
                tmp = j;
            }
        }
        //가장 작은 값을 현재 인덱스의 값과 바꿔준다.
	}
        int t = list[tmp];
        list[tmp] = list[i];
        list[i] = t;
    }
}
```