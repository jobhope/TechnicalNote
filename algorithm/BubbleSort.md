# **Bubble Sort(버블 정렬)**

## 작성자
[![tdm1223](https://avatars1.githubusercontent.com/u/21440957?s=100&v=4)](https://github.com/tdm1223)

## Bubble Sort란?
- 매번 연속된 두 개 인덱스를 비교하여 조건에 맞게 위치를 바꾸는 정렬

### Bubble Sort의 시간복잡도
- 시간 복잡도 : O(N<sup>2</sup>). (전체 비교를 진행)
- 공간 복잡도 : O(N)

## Bubble Sort의 구현
1. 현재 인덱스 값과, 바로 이전의 인덱스 값을 비교한다.
2. 이전 인덱스가 더 크면, 현재 인덱스와 바꿔준다.
3. 현재 인덱스가 더 크면, 교환하지 않고 다음 두 연속된 배열 값을 비교한다.
4. 위 과정을 반복한다.

### C++ Version
```cpp
// 오름차순 버블정렬
vector<int> bubbleSort(vector<int>& v)
{
	for (int i = 0; i < v.size() - 1; i++)
	{
		for (int j = 1; j < v.size() - i; j++)
		{
			// 이전 인덱스가 더 크면 현재 인덱스와 바꿔준다. 내림차순이라면 >를 <로 바꾼다
			if (v[j - 1] > v[j]) 
			{
				swap(v[j - 1], v[j]);
			}
		}
	}
	return v;
}
```

### JAVA Version
```java
int[] bubbleSort(int[] arr) {
	int tmp = 0;
	for (int i = 0; i < arr.length; i++) {
		for (int j = 1; j < arr.length - i; j++) {
			if (arr[j] < arr[j - 1]) {
				tmp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	return arr;
}
```
