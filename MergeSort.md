# **Merge Sort**

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
```cpp
void merge(vector<int>& v, int left, int right, int mid)
{
    vector<int> tmp;
    int i = left;
    int j = mid + 1;
    int cnt = 0;
    while (i <= mid && j <= right)
    {
        if (v[i] < v[j])
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

## 각주
<a id="ref1">

1. [Wiki](https://ko.wikipedia.org/wiki/%ED%95%A9%EB%B3%91_%EC%A0%95%EB%A0%AC)

</a>
