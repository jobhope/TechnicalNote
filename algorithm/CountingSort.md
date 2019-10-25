# **Counting Sort(계수 정렬)**

## 작성자
[![tdm1223](https://avatars1.githubusercontent.com/u/21440957?s=100&v=4)](https://github.com/tdm1223)

## Counting Sort란?
- 원소간 비교하지 않고 각 원소가 **몇개 등장**하는지 갯수를 세는 정렬이다.
- 같은 숫자라도 정렬할 때 순서가 섞이지 않는 **안정 정렬**이다.
- 크기가 한정되어 있는 데이터에 사용하기 좋다.
- 두 값을 비교하며 정렬을 하지 않는 **Non-Comparison Sort**의 방법 중 하나이다.
- 26개의 알파벳으로 이루어진 문자열에서  Suffix Array를 O(nlogn)에 얻을 수 있다.

### Counting Sort의 시간복잡도
- 시간 복잡도 : O(n+k) (k : 리스트중 가장 큰 값)
    - 각 숫자가 나온 횟수를 세는 시간 O(n)
    - 다시 숫자를 정렬된 리스트에 채워넣는 시간 O(n)
    - 총 k번 만큼 반복해야하는 시간O(k)
- 공간 복잡도 ; O(n+k)
    - 정렬을 위한 길이 n의 배열 한개
    - 계수를 위한 길이 k의 배열 한개

## Counting Sort의 구현
1. 각 값마다 몇개가 있는지 새로운 배열에 저장한다.
2. 위에서 만든 배열의 누적합을 구하여 배열에 저장한다.
3. 누적합을 저장한 배열을 이용하여 새로운 배열에 각 번호에 맞게 값을 하나씩 주고 1씩 빼준다.

### Java version
```java
public class Main {
	public static void main(String[] args) {
		int[] a = { 1, 0, 3, 4, 3, 4 };
		a = sort(a);
		System.out.println(Arrays.toString(a));
	}

	public static int[] sort(int[] a) {
		int max = -1;
		for (int i = 0; i < a.length; i++) {
			max = Math.max(a[i], max);
		}
		int[] arr = new int[a.length];
		int[] prefixSum = new int[max + 1];
		Arrays.fill(prefixSum, 0);

		// 각 원소 갯수 계산 후 누적합 계산
		for (int i = 0; i < a.length; i++) {
			prefixSum[a[i]] += 1;
		}
		for (int i = 1; i < prefixSum.length; i++) {
			prefixSum[i] += prefixSum[i - 1];
		}

		// 누적합을 이용해 정렬
		for (int i = a.length - 1; i >= 0; i--) {
			arr[--prefixSum[a[i]]] = a[i];
		}
		
		return arr;
	}
}
```
