# **QuickSort(퀵 정렬)**

## 작성자
[![tdm1223](https://avatars1.githubusercontent.com/u/21440957?s=100&v=4)](https://github.com/tdm1223)

## 1. QuickSort란?
- **분할 정복** 방법에 근거한 이름 그대로 빠른 정렬이다.
- 전체 리스트를 2개의 부분 리스트로 분할하고, 각각의 부분 리스트에 대해 다시 QuickSort를 실행 한다.
- 퀵 정렬의 내부 루프는 대부분의 컴퓨터 아키텍처에서 효율적으로 작동하도록 설계되었다. 메모리 참조가 지역화 되어 있기 때문에 CPU 캐시의 hit ratio가 높아진다.<sup>[1)](#ref1)</sup>

### QuickSort의 **시간 복잡도**
- 최악의 경우 : O( n<sup>2</sup>) (이미 배열이 정렬되어 있거나 역순인 경우) 
- 일반적인 경우 : O(nlogn)

## 2. QuickSort의 구현
1. pivot으로 잡을 값 하나를 정한다. (일반적으로 가장 왼쪽이나 오른쪽)
2. pivot의 값보다 작은 원소들은 왼쪽에, 큰 원소들은 오른쪽에 재배치한다.
3. 이후 나눠진 값에 대해 다시 피벗을 설정한 후 위의 과정을 반복한다.

```java
// 가장 왼쪽값을 피벗으로 잡은 경우
public void quickSort(int[] arr, int left, int right) {
    int pivot = arr[left];
    int first = left;
    int last = right;
    while (left < right){
        while (pivot <= arr[right] && left < right) right--;
        if(left > right) break;
        while (pivot >= arr[left] && left < right) left++;
        if(left > right) break;
        int tmp = arr[left];
        arr[left] = arr[right];
        arr[right] = tmp
    }
    
    int tmp = arr[left];
    arr[left] = arr[first];
    arr[first] = tmp;
    if (first < left) quickSort(arr, first, left - 1);
    if (last > right) quickSort(arr, left + 1, last);
}
```

## 3. QuickSort의 개선
- 정렬된 배열과 역순 배열일 때 퀵 정렬의 속도가 느려지는 것은 pivot으로 정해진 위치의 값을 택하기 때문에 가장 큰 값이나 가장 작은 값이 pivot이 되기 때문이다. 
- 재귀의 깊이가 깊어지고 스택이 넘치며 속도가 느려진다.
- 이를 개선하기 위한 여러 방법이 존재한다.

### 1) 난수 분할을 사용한 퀵 정렬 개선
- pivot을 선택하는 대안으로 pivot을 **난수**로 선택하는 것이다. 확률적으로 퀵 정렬의 속도 향상을 기대 할 수 있다.
- 0부터 n-1 범위의 난수를 발생시켜 난수의 위치와 배열의 제일 오른쪽 요소의 위치를 바꾼 후에 퀵 정렬 알고리즘을 수행한다.
- 평균적으로 고른 속도 향상은 있을 수도 있지만 속도의 결과가 **확률**에 맡겨지게 된다.

### 2) 삽입 정렬을 사용한 퀵 정렬 개선
- 삽입 정렬은 구현이 간단하고 크기가 작은 배열에서는 매우 효율이 좋다. 
- 삽입 정렬은 추가적인 메모리를 필요로 하지 않는다.
- 작은 구간에 대해서는 삽입 정렬을 사용하면서 퀵 정렬의 재귀의 깊이를 줄여줌으로써 속도의 향상을 기대할 수 있다. 
- 구간의 크기가 너무 큰 경우 삽입 정렬은 큰 크기의 배열에서 성능이 좋지 못하여 전체적인 성능이 떨어진다.
- 퀵 정렬 종료 조건을 분할 리스트의 크기가 적절한 크기(100~200)보다 작을 때로 변경하고, 작을 때는 삽입정렬을 수행하도록 변경한다.

### 3) 세 값의 중위 값을 구한 퀵 정렬의 개선<sup>[2)](#ref1)</sup>
1) 배열의 가장 왼쪽 값`a[left]`, 가장 오른쪽 값`a[right]`, 중간의 값`a[(left+right)/2]` 3개의 값을 사용한다. 이 세 값을 **오름차순**으로 정렬한다.
2) 중간 값`a[(left+right)/2]`을 가장 오른쪽의 앞의 값`a[right-1]`과 위치를 바꾼다.
3) 배열의 첫 번째 값은 마지막의 앞의 값보다 항상 작고, 마지막 값은 마지막 앞의 값보다 항상 크다.`a[left] < a[right-1] < a[right]`
4) 분할 구간은 배열 앞에서 두 번째 값과 뒤에서 세 번째 값으로 좁혀진다. `a[left+1]`부터 `a[right-2]`까지
5) 정렬 범위에서 2개를 줄이므로 재귀의 깊이를 줄일 수 있으며 분할도 대부분 중앙에서 이루어진다. 
6) 최악의 경우인 정렬된 배열이나 역순의 배열의 경우 분할을 중앙에서 할 수 있으므로 이 방법을 쓰면 속도가 빨라진다.

## 각주
<a id="ref1">
</a>

1) [위키백과](https://ko.wikipedia.org/wiki/%ED%80%B5_%EC%A0%95%EB%A0%AC)
2) [세 값의 중위](http://egloos.zum.com/mentalray/v/10878147)
