# **좌표 압축 기법**

## 작성자
[![tdm1223](https://avatars1.githubusercontent.com/u/21440957?s=100&v=4)](https://github.com/tdm1223)

## 좌표 압축 기법
- 주어진 좌표값의 **최댓값**을 **최소화** 할 수 있도록 좌표값을 **재할당**하는 알고리즘.
- 좌표의 값보다 좌표의 순위가 중요한 상황에서 입력값의 개수보다 입력값의 범위가 클때 사용한다.
- N개의 데이터의 범위가 너무 클때 등장하는 데이터들을 [0,N) 범위로 다시 넘버링 하는 기법.

## 간단한 예제
- 문제
  - 수직선 상의 세 점 a, b, c의 좌표가 각각 [0, -2147483647, 2147483647] 일때 배열을 이용하여 표현한다면 점 3개를 사용하는거지만 무려 2<sup>32</sup>의 공간이 필요하다.
- 해결
  - 이 좌표를 크기 순서를 유지하여 [1, 0, 2] 으로 바꾸면 세 점의 위치관계는 유지되면서 0부터 2까지의 값으로 모두 표현할 수 있게 된다.

## 구현 코드
1. 데이터 입력을 받는다.
2. 중복 입력된 값을 제거한다.
3. 오름차순으로 정렬한다
4. 각 좌표에 대해 매칭한다(인덱싱)

```cpp
for (int i =0; i < data.size(); i++) 
{
    xPosition.push_back(data[i][0]);
    yPosition.push_back(data[i][1]);        
}
    
// 중복 입력된 값을 제거
xPosition.erase(unique(xPosition.begin(), xPosition.end()), xPosition, end());
yPosition.erase(unique(yPosition.begin(), yPosition.end()), yPosition, end());
    
// 오름차순 정렬
sort(xPosition.begin(), xPosition.end());
sort(yPosition.begin(), yPosition.end());
    
// 좌표 압축 
int x = 0;
int y = 0;
for (int i = 0; i < data.size(); i++) 
{
    for (int j = 0; j < xPosition.size(); j++) 
    {
        if (data[i][0] == xPosition[j]) 
        {
            x = j;
            data[i][0] = x; // x 좌표를 인덱스로 대체한다.
            break;
        }
    }
    for (int j = 0; j < yPosition.size(); j++) 
    {
        if (data[i][1] == yPosition[j]) 
        {
            y = j;
            data[i][1] = y; // y 좌표를 인덱스로 대체한다.
            break;
        }        
    }
}

```
