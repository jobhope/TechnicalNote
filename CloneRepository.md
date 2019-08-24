# **repository를 clone할 때 모든 branch를 local에 받기**

## 작성자
[![Stupid07](https://avatars1.githubusercontent.com/u/35564566?s=100&v=4)](https://github.com/Stupid07)

## 문제의 시작
- 부스트캠프가 끝나고, 부스트캠프 때의 내용들을 백업 해두기로 했다.
- 그리고 아무 생각없이 clone을 받았는데...
- ![clone의 문제](https://user-images.githubusercontent.com/35564566/63637198-d61abc00-c6b4-11e9-9030-cb5a6fab30ab.PNG)
- 해당 Repository에는 161개의 branch가 존재하는데 clone은 `master` branch 1개만 받아왔다.
- 따라서 모든 branch를 local에 받아오는 방법을 찾게 되었다.

## 원격 저장소의 branch와 local 저장소의 branch의 관계
- git clone으로 받아오게 되면 origin/master branch를 tracking 하고 있는 master branch만 존재하게 된다.
- 이 때, clone의 결과로 origin이란 이름으로 remote repository가 등록 되게 되므로 **remote-tracking branch**<sup>[1)](#ref1)</sup> 들이 등록된다.
- 또한, **Remote-tracking branch**와 연결된 **tracking branch**<sup>[2)](#ref2)</sup>를 생성 할 수 있게 된다.
- master branch는 이미 이렇게 연결되어 있어서 우리가 git pull, git push 등의 명령에 대해 뒤의 인자를 직접 명시하지 않아도 처리 되는 이유다.

<a id="ref1"></a>
### **Remote-tracking branch**
- 원격 저장소에서 추적하는 branch들을 말한다.
- 예를들면 `origin`이란 원격 저장소가 있고, 해당 저장소에 `master` branch가 있다면 `origin/master` 형태로 표시되는 branch이다.
- 이 branch는 원격 저장소의 master branch와 연결된 branch라고 보면된다.

<a id="ref2"></a>
### **tracking branch**
- Remote-tracking branch를 tracking하는 branch들을 말한다.
- 우리가 기존의 fetch명령어들이 우리 작업물에 바로 적용되지 않고 비교할 수 있었던 이유가 각각이 branch로 존재하기 때문이다.
- fetch는 tracking branch에 연결된 remote-tracking branch를 update하게 된다. 따라서 remote-tracking branch와 tracking branch를 비교 할 수 있다.
- git clone 시에 master branch는 자동으로 tracking branch로 origin/master인 remote-tracking branch와 연결된다.


## 방법1) 쉘 스크립트를 이용해 모든 branch를 받아오는 방법
- 위의 설명을 참조하여 원격저장소에서 Remote-tracking branch들과 연결된 tracking branch들을 만들어주고 받아오는 방법을 취하면 된다.
```
git branch -r | grep -v '\->' | while read remote; do git branch --track "${remote#origin/}" "$remote"; done
git fetch --all
git pull --all
```
> [참조 : how-to-fetch-all-git-branches](https://stackoverflow.com/questions/10312521/how-to-fetch-all-git-branches/10312587#10312587)
- git branch -r 명령어
  - remote 저장소의 Remote-tracking branch의 리스트를 받아올 수 있다.
- grep -v '\->'
  - 받아온 리스트의 첫번째는 `origin/HEAD -> origin/master`로 되어있어서 이를 제거하기 위함이다.
- git branch --track trackingBranch remoteTrackingBranch
  - remoteTrackingBranch를 추적하는 trackingBranch를 만든다.
- ${remote#origin/}
  - Bash스크립트 문법으로 $는 내부의 값을 변수로 인식해서 remote는 변수가 된다.
  - 이 때, 매개 변수 확장 문법에 의해 ${변수#단어}는 변수의 앞부분 부터 짧게 일치한 단어 삭제<sup>[3)](#ref3)</sup>를 가리킨다.
  - 따라서 origin/을 지운 값이 된다.

## 방법2) git clone --mirror를 이용한 방법
- git clone의 다양한 옵션중에 `--mirror` 옵션이 있다.
- 이 옵션을 사용하면 원격 저장소의 모든 파일을 형상 관리 하는 `.git` 폴더를 받아올 수 있다.
```
mkdir repo_folder && cd repo_folder
git clone --mirror repo_URL .git
git config --bool core.bare false
git reset --hard
```
- 첫번째 파일들이 저장될 폴더를 만들고 폴더 내부로 들어간다.
- 두번째 `--mirror`옵션을 이용하여 내부의 `.git`폴더로 파일들을 받는다.
- 세번째 git 구성의 `bare` 값을 false로 바꿔서 빈 저장소에서 일반 저장소로 변경한다.
- 네번째 `reset --hard` 를 이용해서 .git 폴더의 내용들을 기준으로 정상적인 저장소로 변경합니다.


## 결과
- 시리즈로 되어있는 repository는 방법1을 이용해서 받았고, 따로 존재하는 것들은 방법2를 이용해 받았다.
- ![backup 폴더](https://user-images.githubusercontent.com/35564566/63638134-4cbcb700-c6bf-11e9-9f81-abf77cef971c.png)


## 그 외 정보들

### push의 --mirror 옵션
- `push`의 `--mirror` 옵션을 이용하면 현재의 모든 commit 기록을 그대로 `push` 할 수 있다.
- 이를 이용해서 원격 저장소를 옮기거나 처음 등록 할 때, repository를 remote에 등록하고 `--mirror` 옵션을 이용해 `push` 함으로서 기록을 살려서 저장할 수 있다.

### 한 개의 branch만 clone 받는 명령어
```
git clone [repository] -b [branch_name] --single-branch
```

### 그 외 다양한 실전 Git 명령어들
- [GitHub 환경에서의 실전 Git 레시피](https://meetup.toast.com/posts/116)

## 참조
- [Git clone Docs](https://git-scm.com/docs/git-clone)
- [Git branch Docs](https://git-scm.com/docs/git-branch)
- [how-to-fetch-all-git-branches](https://stackoverflow.com/questions/10312521/how-to-fetch-all-git-branches/10312587#10312587)
- [how-to-clone-all-remote-branches-in-git](https://stackoverflow.com/questions/67699/how-to-clone-all-remote-branches-in-git)
- [Git: Remote Tracking Branch vs Tracking Branch](http://dogfeet.github.io/articles/2012/git-tracking-vs-remote-tracking.html)

## 각주
<a id="ref3"></a>
- [3)Bash 입문자를 위한 핵심 요약 정리 (Shell Script)](https://blog.gaerae.com/2015/01/bash-hello-world.html)
