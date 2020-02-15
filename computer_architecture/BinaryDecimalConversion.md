# **10진수와 2진수의 변환**

## 작성자
[![tdm1223](https://avatars1.githubusercontent.com/u/21440957?s=100&v=4)](https://github.com/tdm1223)
[![rlatjdwo555](https://avatars0.githubusercontent.com/u/28692938?s=100&v=4)](https://github.com/rlatjdwo555)
[![Stupid07](https://avatars1.githubusercontent.com/u/35564566?s=100&v=4)](https://github.com/Stupid07)

## 10진수 11.625<sub>(10)</sub>를 2진수로 변환 해보자 :keycap_ten: -> :two:
### 정수
1) 수가 0이 될때까지 2로 나눈다.
2) **나머지**를 아래에서 위로 붙여 읽는다.
3) 해당하는 값이 2진수로 변환된 값이다.

| / | 11|   | % | 읽는 방향  | 
|:-:|:-:|:-:|:-:|:-:|
| 2 | 5 |...| 1 | ^ |
| 2 | 2 |...| 1 | \||
| 2 | 1 |...| 0 | \||
| 2 | 0 |...| 1 | \||

> 1011<sub>(2)</sub>

- **Java Code**
    ```java  
    int decimal = 11;
    System.out.println(Integer.toBinaryString(decimal)); // 1011
    ```
- **Cpp Code**
    ```cpp
    int decimal = 11;
	string binary = "";
	while (decimal>0)
	{
		if (decimal % 2 == 0)
		{
		    binary += '0';
		}
		else
		{
		    binary += '1';
		}
		decimal /= 2;
	}
	reverse(binary.begin(), binary.end());
	cout << binary << endl; // 1011
    ```
### 소수
1) 소수부분이 0이 될때까지 2로 곱하면서 정수 부분을 분리한다.
2) 분리된 정수부분을 위에서 아래로 붙여 읽는다.
3) 해당하는 값이 2진수로 변환된 소수값이다.

| * |읽는 방향| 0 |.| 625 |
|:-:|:-:|:-:|:-:|:-:|
| 2 |\|| 1 |.| 250 |
| 2 |\|| 0 |.| 5 |
| 2 |v| 1 |.| 0 |

> 0.101<sub>(2)</sub>

## 결과
> 1011.101<sub>(2)</sub>

## 2진수 1011.101<sub>(2)</sub>를 10진수로 변환 해보자 :two: -> :keycap_ten:
### 정수
1) 오른쪽 자리수 부터 2의 0승 ~ N승 까지의 값을 곱한다
2) 곱해진 값들을 합산하면 10진수 값이 된다.

|10진수| 2<sup>3</sup> | 2<sup>2</sup> | 2<sup>1</sup> | 2<sup>0</sup>|
|:--:|:--:|:--:|:--:|:--:|
|2진수| 1 | 0 | 1 | 1 |
|10진수| 8 | 0 | 2 | 1 |
|합산 | 11 |  |  |  |

> 11<sub>(10)</sub>

- **Java Code**
    ```java 
    String binary = "1011";
    System.out.println(Integer.parseInt(binary,2)); // 11
    ```
- **Cpp Code**
    ```cpp
    string binary = "1011";
	int decimal = 0;
    
    int expo = 1;
	for (int i = binary.size() - 1; i >= 0; i--)
	{
		decimal += (binary[i] - '0') * expo;
		expo *= 2;
	}
	cout << decimal << endl; // 11
    ```
### 실수
1) 왼쪽 자리수 부터 2의 -1승 ~ -N승 까지의 값을 곱한다
2) 곱해진 값들을 합산하면 10진수 값이 된다.

|10진수 |2<sup>-1</sup> | 2<sup>-2</sup> | 2<sup>-3</sup> | 
|:--:|:--:|:--:|:--:|
| 2진수 | 1 | 0 | 1 | 
| 10진수 | 0.5 | 0 | 0.125 |
| 합산 | 0.625 |  |  | 

> 0.625<sub>(10)</sub>
