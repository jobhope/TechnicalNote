# **SendMessage, PostMessage**

## 작성자
[![tdm1223](https://avatars1.githubusercontent.com/u/21440957?s=100&v=4)](https://github.com/tdm1223)

## SendMessage, PostMessage
- 윈도우 프로그램은 [메시지 처리](https://github.com/jobhope/TechnicalNote/blob/master/windows/MessageLoop.md)를 기본으로 한다.
- 메시지는 주로 사용자에 의해 발생된다.(Input Device..)
- 사용자에 의한 메시지 발생이 아닌 프로그램 내부에서 윈도우간의 통신을 위해 서로 다른 윈도우에게 메시지를 보낼때는 이 두 함수를 사용한다.

## SendMessage
### 함수 원형
```cpp
LRESULT SendMessage(
  HWND   hWnd,      // 메시지를 받을 윈도우 핸들
  UINT   Msg,       // 전달할 메시지
  WPARAM wParam,    // 메시지에 대한 부가적인 데이터
  LPARAM lParam     // 메시지에 대한 부가적인 데이터
);
```
### 동작
- 메시지를 메시지큐에 넣지 않고 윈도우 프로시저로 보내 즉시 처리하도록 한다.
- 메시지가 완전히 처리되기 전에는 반환하지 않는다.(Block)

### 장단점
- 보낸 메시지의 정확한 처리를 보장한다.
- 보낸 메시지가 완전히 처리 될때까지 기다리므로 메시지를 보낸 쪽은 블록 상태가 된다.(따라서 메인 스레드에서 다른 스레드로 메시지를 보낼 때 SendMessage를 사용하면 위험하다.)

## PostMessage
### 함수 원형
```cpp
BOOL PostMessageA(
  HWND   hWnd,      // 메시지를 받을 윈도우 핸들
  UINT   Msg,       // 전달할 메시지
  WPARAM wParam,    // 메시지에 대한 부가적인 데이터
  LPARAM lParam     // 메시지에 대한 부가적인 데이터
);
```
### 동작
- Msg 인수로 지정된 메시지를 hWnd 윈도우의 메시지 큐에 집어 넣어 윈도우 프로시저에서 이 메시지를 처리하도록 한다. 
- 메시지를 메시지 큐에 넣고 바로 반환하므로 메시지는 바로 처리되지 않는다. 
- 큐에 붙여진 메시지는 GetMessage() 에 의해 읽혀지고 DispatchMessage() 에 의해 윈도우 프로시저로 보내져 처리 된다.
- 급하게 처리될 필요가 없거나 현재 진행 중인 작업을 완전히 끝내야만 처리할 수 있는 메시지는 PostMessage() 함수로 큐에 붙인다.
- 메시지를 메시지큐에 붙이는데 성공한다면 TRUE를 반환하고 붙이는데 실패한다면 FALSE를 반환한다.

### 장단점
- 메시지를 메시지 큐에 넣고 반환하므로 메시지를 보내는 쪽에서 블록 시키지 않아 다른 작업을 할 수 있다.
- 메시지 큐에 넣었을때 메시지 큐에 대기하고 있는 메시지가 있다면 바로 처리 되지 않을 수 있다.(메시지가 언제 처리될디 모르므로 wParam, lParam에는 지역 포인터를 사용하지 않아야 한다.)