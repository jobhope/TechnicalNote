# **Merge Sort(병합 정렬)**

## 작성자
[![tdm1223](https://avatars1.githubusercontent.com/u/21440957?s=100&v=4)](https://github.com/tdm1223)

## Merge Sort란?
- **분할 정복** 방식으로 설계된 비교 기반 정렬이다. <sup>[1)](#ref1)</sup>
- 큰 문제를 반으로 쪼개 문제를 해결해 나가는 방식으로 분할은 배열의 크기가 1보다 작거나 같을 때까지 반복한다.

### Merge Sort의 시간복잡도
- 시간 복잡도 : O(nlogn)
- 공간 복잡도 : O(nlogn)

## Merge Sort의 구현
1. 길이가 n인 정렬되지 않은 리스트를 각각 한개의 값을 포함하는 n개의 리스트로 분할한다. (한개는 정렬된 것으로 생각한다.)
2. 다시 한개의 길이가 n인 리스트가 될때까지 분할된 리스트들을 반복해서 병합하면서 정렬한다.

### C++ Version
```cpp
void merge(vector<int>& v, int left, int right, int mid)
{
    vector<int> tmp;
    int i = left;
    int j = mid + 1;
    int cnt = 0;
    while (i <= mid && j <= right)
    {
        if (v[i] <= v[j])
        {
            tmp.push_back(v[i++]);
        }
        else if (v[i] > v[j])
        {
            tmp.push_back(v[j++]);
        }
    }
    // 남은 값들을 뒤에 채운다.
    while (i <= mid)
    {
        tmp.push_back(v[i++]);
    }
    while (j <= right)
    {
        tmp.push_back(v[j++]);
    }
    // 원래 배열에 복사한다.
    for (int k = left; k <= right; k++)
    {
        v[k] = tmp[cnt++];
    }
}

void mergeSort(vector<int>& v, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        //분할
        mergeSort(v, start, mid); // s부터m까지
        mergeSort(v, mid + 1, end); // m+1부터e까지
        //합병
        merge(v, start, end, mid);
    }
}
```
### Java Version
```java
// 정적, 동적 배열 모두 적용 가능하도록 List interface를 사용했습니다.
class MergeSort{
	public void merge(List<Integer> list, int left, int right, int mid){
		List<Integer> temp = new ArrayList<>(list.size());
		int i = left, j = mid+1;
		while(i <= mid && j <= right) {
			if(list.get(i) <= list.get(j)) {
				temp.add(list.get(i++));
			}else {
				temp.add(list.get(j++));
			}
		}

		// 남은 값 뒤에 채우기
		while(i<= mid) {
			temp.add(list.get(i++));
		}
		while(j<= right) {
			temp.add(list.get(j++));
		}

		// 원래 리스트에 복사
		for(int idx = left; idx <= right; idx++) {
			list.set(idx, temp.get(idx-left));
		}
	}

	public void mergeSort(List<Integer> list, int start, int end) {
		if(start < end) {
			int mid = (start + end)>>1;
			// 분할
			mergeSort(list, start, mid);
			mergeSort(list, mid+1, end);
			// 병합
			merge(list, start, end, mid);
		}
	}
}
```

### Python3 Version
```python3
# python의 경우 list slicing을 활용해 더 깔끔한 코드가 가능하지만
# slicing 때마다 List를 복사하므로 성능적인 부분과
# 다른 언어의 코드와 유사한 형태로 작성하기 위해 index를 활용했습니다.
def merge(valueList, left, right, mid):
    temp = []
    i, j = left, mid+1
    while i <= mid and j <= right:
        if valueList[i] <= valueList[j]:
            temp.append(valueList[i])
            i+=1
        else:
            temp.append(valueList[j])
            j+=1
    
    # 남은 값 채우기
    while i <= mid:
        temp.append(valueList[i])
        i+=1
    while j <= right:
        temp.append(valueList[j])
        j+=1
    
    # 원래 리스트 값 변경
    for idx in range(len(temp)):
        valueList[idx+left] = temp[idx]


def mergeSort(valueList, start, end):
    if start < end :
        mid = (start+end)//2
        # 분할
        mergeSort(valueList, start, mid)
        mergeSort(valueList, mid+1, end)
        # 병합
        merge(valueList, start, end, mid)
```

### JavaScript(Node.js) Version
```node
let merge = (list, left, right, mid)=>{
    let temp = new Array();
    let i = left, j = mid +1;
    while(i <= mid && j <= right){
        if(list[i] <= list[j]){
            temp.push(list[i++]);
        }else{
            temp.push(list[j++]);
        }
    }

    // 남은 값 뒤에 채우기
    while(i <= mid){
        temp.push(list[i++]);
    }
    while(j <= right){
        temp.push(list[j++]);
    }

    // 원래 배열에 복사
    temp.forEach((value, idx)=>{
        list[left + idx] = value;
    });
};

let mergeSort = (list, start, end)=>{
    if(start < end){
        let mid = (start+end)>>1;
        // 분할
        mergeSort(list, start, mid);
        mergeSort(list, mid+1, end);
        // 병합
        merge(list, start, end, mid);
    }
};
```

## 각주
<a id="ref1">

1. [Wiki](https://ko.wikipedia.org/wiki/%ED%95%A9%EB%B3%91_%EC%A0%95%EB%A0%AC)

</a>
