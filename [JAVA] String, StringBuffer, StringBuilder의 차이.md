# **[JAVA] String, StringBuffer, StringBuilder의 차이**

## 작성자
[![rlatjdwo555](https://avatars0.githubusercontent.com/u/28692938?s=100&v=4)](https://github.com/rlatjdwo555)

## 1. Java에서 String의 동작

- String은 `Heap`에 저장된다.
- `Immutable`(불변성) 특징을 갖고 있다.

위 내용은 다음과 같이 증명할 수 있다.
```java
public static void main(String[] args){
    String str1 = "Hello";
    String str2 = "Hello";

    // == 연산은 객체의 주소값을 비교한다. 
    System.out.println(str1 == str2); // false

    String str3 = str1;
    System.out.println(str1 == str3); // true

    // String은 immutable하기 때문에 'Hi'라는 새로운 객체를 만든다!
    str1 = "Hi";
    System.out.println(str1 == str3); // false
    System.out.println(str1); // Hi
    System.out.println(str3); // Hello
}

```
  
- string의 생성 방식은 두 가지가 있다.
    1. `new` 연산자를 이용하는 방법
    2. `literal` 을 이용하는 방법 
    ```java
    String operator = new String("hello");
    String literal = "hello";
    ```
    Java 7 이상 기준으로 두 방식 모두 `Heap` 영역에 존재한다.
    
    좀 더 자세히 설명하자면 `new` 연산자로 생성하면 `Heap`에 존재하게 되고 리터럴을 이용하면 `string constant pool` 이라는 영역에 존재하게 된다.

    ```java
    public static void main(String[] args){
        String literal = "jophope";
        String oper = new String("jophope");
        String intern = oper.intern();

        System.out.println(literal == oper);  // false
        System.out.println(literal == intern); // true 
    }
    ``` 
    위 코드를 보면 기존에 `new`로 생성된 String객체와 `리터럴`로 생성된 String객체를 == 연산하면 `false`를 반환한다.  
    
    하지만 `new`를 통해 생성된 String객체의 `intern()` 메소드를 호출하여 새로운 String객체에 대입해보니 `리터럴` String 객체와 `==` 연산에서 `true`를 반환한다. 

    이는 리터럴로 이용하여 생성된 String은 `string constant pool`에 저장되는데 `intern()` 메소드를 호출하면서 `string constant pool` 내부에 있는 `"jobhope"`라는 문자열을 검색하게 되고 해당 주소값을 반환하여 `true`가 성립하게 되는 것이다.

    `string constant pool` 은 Java 6 까지는 `Perm` 이라는 영역에 존재했다가 Java 7부터 `Heap` 영역으로 옮겨지게 되었는데 그 이유는 다음과 같았다. 

 
    1. Perm은 Runtime에서 고정된 사이즈였기 때문에 String의 intern()을 호출하면 OOM(OutofMemoryException)을 발생시킬 수 있었다. 

    2. Heap으로 옮겨지면서 string constant pool의 모든 문자열도 GC(Garbage Collection)의 대상이 되었다!


<br>

## 2. StringBuffer와 StringBuilder의 차이 

앞서 설명한대로 String이 immutable 특징이었던데 반해 이들은 mutable한 특성을 갖고 있다.

즉 클래스를 한 번만 만들고(new) 연산이 필요할 때 크기를 늘리면서 문자열을 변경한다. 따라서 문자열 연산이 자주 있을 때 사용하면 성능이 좋다.

그럼 StringBuffer와 StringBuilder의 차이는 뭘까?

|StringBuffer|StringBuilder|
|:---:|:---:|
|동기식|비동기식|
|Multe-thread도 가능|Only Single-thread|

위 표처럼 가장 큰 특징은 동기화 여부이다.   
StringBuffer의 경우 멀티스레드 환경에서 synchronized 키워드로 동기화가 가능하도록 되어있다. 

```java
 public final class StringBuffer ...{
    ...
    @Override
    public synchronized StringBuffer append(Object obj) {
        toStringCache = null;
        super.append(String.valueOf(obj));
        return this;
    }
 }

 public final class StringBuilder ...{
    ...
    @Override
    public StringBuilder append(Object obj) {
        return append(String.valueOf(obj));
    }
 }
```

요약하자면 다음과 같다.
 - StringBuffer와 StringBuilder는 mutable한 특성을 갖는다.
 - StringBuffer는 동기식이고 StringBuilder는 비동기식이다.
 - 단순히 속도적인 측면만 봤을 때는 StringBuilder가 다소 빠르다.
 - 초기 생성할 때 Buffer Size를 설정할 수 있는데 이에 의한 생성, 확장 오버로드가 생길 수 있기 때문에 Buffer Size를 잘못 지정할 경우 성능이 떨어질 수도 있다. 

<br>

 ## 3. 다양한 문자열 최적화 

- ### 컴파일러 최적화, 한 줄에서 상수 String 사이의 덧셈 연산은 모두 합쳐진 문자열로 반환된다.  

    String 클래스의 덧셈 연산의 경우 초기 컴파일러 분석단계에서 리터럴 처리에 의해 최적화가 이루어져 오히려 빠른 결과를 보여줄 때도 있다. 
    ```
    String str = "Hello"+" "+"world";
    >> String str = "Hello world";

    String str2 = "My name is "+student.getName(); 
    >> "My name is "+student.getName(); // 상수만 변환된다
    ```

- ### JDK 1.5부터는 String 연산도 StringBuilder로 치환된다. 
    JDK 1.5부터는 String 연산의 퍼포먼스를 위해 덧셈 연산도 내부적으로 StringBuilder를 사용하게 한다.

    **원본 소스**<sup>[1)](#ref1)</sup>
    ```java
    public class StringTest {  
        public static void main(String[] args) {  
            String str0 = "It's a string....";  
            String str1 = "It's" + " a string" + "....";  
            String str2 = "It's a string...." + str0 + "000";  
            str2 = str0 + str1 + "1111" ;        
            str2 = str2 + "1111";  
            str2 += "1111";        
            for (int i=0;i<10;i++){  
                str2 = str2 + "1111";  
                str2 += "1111";        
            }  
        }  
    }
    ```

    **JDK 1.5 Compile**<sup>[1)](#ref1)</sup>
    ```java
    public class StringTest{  
        public static void main(String args[])    {  
            String str0 = "It's a string....";  
            String str1 = "It's a string....";  
            String str2 = (new StringBuilder("It's a string....")).append(str0).append("000").toString();  
            str2 = (new StringBuilder(String.valueOf(str0))).append(str1).append("1111").toString();  
            str2 = (new StringBuilder(String.valueOf(str2))).append("1111").toString();  
            str2 = (new StringBuilder(String.valueOf(str2))).append("1111").toString();  
            for(int i = 0; i < 10; i++)        {  
                str2 = (new StringBuilder(String.valueOf(str2))).append("1111").toString();  
                str2 = (new StringBuilder(String.valueOf(str2))).append("1111").toString();  
            }  
        }  
    }
    ```

    위와 같이 String의 덧셈 연산에서 컴파일러가 StringBuilder로 바꿔주는 모습을 볼 수 있다. 

    _*그렇다면 왜 아직도 String과 StringBuilder에서 속도 차이가 나는 것일까?*_

    **그것은 반복문을 사용해서 문자열을 더할 경우 StringBuilder 객체를 매번 새로 생성하기 때문이다. 따라서 반복문 안에서는 문자열 덧셈 연산을 해서는 안된다.** 

<br>

 ## 각주
<a id="ref1"></a>
1)　출처 : https://meetup.toast.com/posts/92 