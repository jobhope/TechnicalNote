# **UNICODE**

## 작성자
[![tdm1223](https://avatars1.githubusercontent.com/u/21440957?s=100&v=4)](https://github.com/tdm1223)

## 문자셋의 종류
- 유니코드에 대해 알기 전에 컴퓨터에서 표현하는 문자셋의 종류에 대해 알 필요가 있다.
1. SBCS
    - 문자를 표현하는데 **1바이트**를 사용한다.
    - 아스키 코드
2. MBCS
    - 문자를 표현하는데 한글을 **2바이트**, 영문은 **1바이트**를 사용한다.
3. WBCS
    - 문자를 표현하는데 **2바이트**를 사용한다.
    - 유니코드

## UNICODE?
- 문자를 표현하는데 **2바이트**를 사용하는 WBCS(Wide Byte Character Set)중 하나의 표현방식

## 프로그래밍에서의 UNICODE
```cpp
int main()
{
    char str[] = "ABC가나"
    int size = sizeof(str);
    int len = strlen(str);
    printf("%d", size); // 8
    printf("%d", len); // 7
}
```
- C언어 기준으로 한글은 2바이트, 영문은 1바이트의 공간을 차지하게 된다.
- 따라서 `for`문으로 **한글 길이**만큼만 단순하게 돌리면 문제가 발생하게 된다.
- 실수를 줄이기 위해 `char`대신 `wchar_t`, `"ABC"`대신 `L"ABC"`를 사용한다.
- 입력과 출력 모두 같은 문자셋으로 맞춰줄 필요가 있다. (wchar 사용시 wprintf 사용하기 ...)
