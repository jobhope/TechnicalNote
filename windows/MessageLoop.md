# **MessageLoop**

## 작성자
[![tdm1223](https://avatars1.githubusercontent.com/u/21440957?s=100&v=4)](https://github.com/tdm1223)

## Message Loop?
- Windows 프로그램에서 메시지를 처리하는 부분이며, Windows 기반의 모든 GUI 프로그램에 **반드시 포함**되는 루틴이다.<sup>[1)](#ref1)</sup>
- 메시지를 꺼내오고 저장한후 해독하여 프로그램에 전달하는 역할을 한다.
- 일반적으로 종료 메세지를 받을때까지 무한루프로 돌게 된다.
- WinMain함수에서 Main Window를 만든 후에 WinMain함수는 메시지 루프를 실행한다.
- WinMain 함수의 끝에 아래와 같은 형식으로 존재한다.
```cpp
while(GetMessage(&Message,0,0,0)) {
	TranslateMessage(&Message);
	DispatchMessage(&Message);
}
```
- 메시지루프는 메시지를 처리하지는 않는다. 실제로 메세지를 처리하는 함수는 WndProc함수이다.

## Message Loop 주요 함수
### BOOL GetMessage(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax)
- 시스템이 유지하는 메시지 큐<sup>[1)](#ref1)</sup>에서 메세지를 읽는다.
- 읽은 메시지는 첫번째 인자인 MSG 구조체에 저장된다. 
- 읽은 메세지가 WM_QUIT라면 FALSE를 리턴하고 종료한다.
- 읽은 메시지가 WM_QUIT이 아닐 경우 TRUE를 리턴하고 루프를 계속 돈다.
- 나머지 세 개의 인수는 읽은 메시지의 범위를 지정한다.

### BOOL TranlateMessage(CONST MSG *lpMsg)
- 키보드 입력 메시지를 해독하여 프로그램에서 쓸 수 있도록 한다.
- 메시지가 입력 되었을 때(**WM_KEYDOWN**, **WM_KEYUP**) 문자가 입력 되었다는 메시지(**WM_CHAR**)를 만드는 역할을 한다.
- 예를들어 T를 입력하면 T가 입력 되었다는 메시지를 만들게 된다.

### BOOL DispatchMessage(CONST MSG *lpMsg)
- 메시지 큐<sup>[1)](#ref1)</sup>에서 꺼낸 메세지를 프로그램의 메시지 처리 함수인 WndProc함수로 전달한다.
- 이 함수에 의해 메세지가 프로그램으로 전달되면 프로그램은 전달된 메세지를 확인하고 점검한 후 다음 동작을 결정한다.

<a id="ref1">

## Link

1) [Wiki](https://en.wikipedia.org/wiki/Message_loop_in_Microsoft_Windows)

## 각주

1) 시스템이나 사용자로부터 발생된 메세지가 잠시 대기하는 메시지 임시 저장 영역

</a>
