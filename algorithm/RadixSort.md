# **Radix Sort(기수 정렬)**

## 작성자
[![tdm1223](https://avatars1.githubusercontent.com/u/21440957?s=100&v=4)](https://github.com/tdm1223)
[![rlatjdwo555](https://avatars0.githubusercontent.com/u/28692938?s=100&v=4)](https://github.com/rlatjdwo555)

## Radix Sort란?
- 낮은 자리수부터 비교하여 정렬해 간다는 것을 기본 개념으로 하는 정렬 알고리즘<sup>[1)](#ref)</sup>
- 비교를 하지 않기 때문에 **정수의 정렬**에서 높은 성능
- **실수**에 대해서는 정렬이 불가능하다.
- 버킷을 사용하기 때문에 추가적인 **메모리 공간**이 필요하다.
- 순서가 섞이지 않는 **안정 정렬(Stable Sort)**이다.

### Radix Sort의 시간복잡도
- 시간 복잡도 : O(dN) (d : 가장 긴 숫자의 자릿수)

## Radix Sort의 구현
1. 0부터 9까지의 값을 저장할 수 있는 버킷 9개를 준비한다.
2. 모든 숫자의 N(일->십->백...)의 자리 수를 해당하는 버킷에 분류한다. 
3. 0부터 9까지의 버킷에 저장되어 있는 값을 차례대로 빼서 저장한다.
4. 자릿수를 늘려서(N*10) 가장 **긴 자리수**(일->십->백...)까지 2~3과정을 반복한다.

### C++ version
```cpp
#include<iostream>
#include<vector>

using namespace std;

void radix_sort(vector<int>& a)
{
	// 최댓값 찾기
	int max = a[0];
	for (int i = 1; i < a.size(); i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	// 각 자리수에 대해 정렬
	for (int digit = 1; digit <= max; digit *= 10)
	{
		vector<int> output(a.size());
		int count[10];
		for (int i = 0; i < 10; i++)
		{
			count[i] = 0;
		}
		// 각 자리수를 버킷에 저장
		for (int i = 0; i < a.size(); i++)
		{
			count[(a[i] / digit) % 10]++;
		}
		for (int i = 1; i < 10; i++)
		{
			count[i] += count[i - 1];
		}
		// 자리수가 같은 수에 대해 순서 유지를 위해 뒤에서부터 저장
		for (int i = a.size() - 1; i > -1; i--)
		{
			int k = (a[i] / digit) % 10;
			output[count[k] - 1] = a[i];
			count[k]--;
		}
		for (int i = 0; i < a.size(); i++)
		{
			a[i] = output[i];
		}
	}
}
```

### Java version
``` java
import java.util.*;

public class Main {
    
    public static void main(String args[]) {
		int arr[] = {9,1,22,4,0,1,22,100,10};
		radix_sort(arr);
		System.out.println(Arrays.toString(arr));
		// 0 1 1 4 9 10 22 22 100 
    }
    
    static void radix_sort(int a[]) {
        int max = 0;  
        int size = a.length;
        
        for(int n : a){
        	max = Math.max(max, n);
        }
        
        for(int exp=1; exp<=max; exp*=10) {
            int count[] = new int[10];
            int output[] = new int[size];
            
            for(int i=0; i<size; i++){
            	count[(a[i]/exp)%10]++;
            }
            
            for(int i=1; i<10; i++){
            	count[i]+=count[i-1];
            }
            
            for(int i=size-1; i>=0; i--) {
                int j = (a[i]/exp)%10;
                output[count[j]-1] = a[i];
                count[j]--;
            }
            
            for(int i=0; i<size; i++){
            	a[i]=output[i];
            }
        }
    }
}
```

### Python version

### Javascript version

## Link
<a id = "ref">

1. [Wiki](https://en.wikipedia.org/wiki/Radix_sort)

</a>
