# **접근 제한자**

## 작성자
[![tdm1223](https://avatars1.githubusercontent.com/u/21440957?s=100&v=4)](https://github.com/tdm1223)
[![rlatjdwo555](https://avatars0.githubusercontent.com/u/28692938?s=100&v=4)](https://github.com/rlatjdwo555)
[![Stupid07](https://avatars1.githubusercontent.com/u/35564566?s=100&v=4)](https://github.com/Stupid07)

## 접근 제한자?

### public
- 가장 넓은 범위의 접근 제한자
- 주로 `Getter`/`Setter` 메소드에 사용한다. 객체 데이터를 외부에서 직접 접근할 경우 무결성이 깨질 수 있기 때문이다.

### protected
- 클래스의 **내부, 상속 관계**에 있는 클래스에서만 사용 가능한 접근 제한자
- 클래스 외부에서는 proteted멤버에 접근할 수 없다.

### private
- 클래스의 **내부**에서만 사용 가능한 접근 제한자
- 주로 **자료 보호**의 목적으로 사용한다.
- **내부**에서만 쓰이는 함수에 사용한다.

## 언어별 특징
### Java
- Java에는 아무것도 선언하지 않았을 때 기본으로 default 접근 제한자 설정

|  | Same Project | Other Package Subclass | Same Package | Same class |
|:--------:|:--------:|:--------:|:--------:|:--------:|
| **public** | O | O | O | O |
| **protected** | X | O | O | O |
| **default** | X | X | O | O |
| **private** | X | X | X | O |
- 단, Java의 최상위 class 선언에는 public과 default 밖에 적용 할 수 없음
- Inner class 선언에는 protected와 private도 사용 가능함

### C++
```cpp
class Position
{
public:
    int x;
    int y;
protected:
    int a;
private:
    int b;
}
```
- **클래스**내 멤버에 대한 접근 제한자를 두지 않으면 **private**
- **구조체**내 멤버에 대한 접근 제한자를 두지 않으면 **public**
- **friend** 키워드를 통해 접근 제한자를 무시할 수 있다.

### C#
- getter, setter를 단순화 하는 **프로퍼티**라는 변수를 제공
```csharp
class Position
{
    private int x;
    public int X
    {
        get { return x; }
        set { x = value; }
    }
}

```
