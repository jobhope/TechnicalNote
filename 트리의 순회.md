# **트리의 순회**

## 작성자
[![tdm1223](https://avatars1.githubusercontent.com/u/21440957?s=100&v=4)](https://github.com/tdm1223)

## 이진 트리 노드
```cpp
struct node
{
    int val; // 데이터
    node* left; // 왼쪽 자식 노드
    node* right; // 오른쪽 자식 노드
};
```
## 전위 순회(preorder)
- V -> L -> R
1. 노드를 방문한다.
2. 왼쪽 서브 트리를 순회한다.
3. 오른쪽 서브 트리를 순회한다.
```cpp
void preorder(node* n)
{
    // 1. 노드를 방문한다.
    cout<<n->val<<endl;
    // 2. 왼쪽 서브 트리를 순회한다.
    if(n->left != NULL)
    {
        preorder(n->left);
    } 
    // 3. 오른쪽 서브 트리를 순회한다.
    if(n->right != NULL)
    {
        preorder(n->right);
    }   
}
```
## 중위 순회(Inorder)
- L -> V -> R
- **트리의 값이 순차적으로 정렬된다.**
1. 왼쪽 서브 트리를 순회한다.
2. 노드를 방문한다.
3. 오른쪽 서브트리를 순회한다.
```cpp
void Inorder(node* n)
{
    // 1. 왼쪽 서브 트리를 순회한다.
    if(n->left != NULL)
    {
        Inorder(n->left);
    } 
    // 2. 노드를 방문한다.
    cout<<n->val<<endl;
    // 3. 오른쪽 서브 트리를 순회한다.
    if(n->right != NULL)
    {
        Inorder(n->right);
    }   
}
```
## 후위 순회(postorder)
- L -> R -> V
1. 왼쪽 서브 트리를 순회한다.
2. 오른쪽 서브트리를 순회한다.
3. 노드를 방문한다.
```cpp
void postorder(node* n)
{
    // 1. 왼쪽 서브 트리를 순회한다.
    if(n->left != NULL)
    {
        postorder(n->left);
    } 
    // 2. 오른쪽 서브 트리를 순회한다.
    if(n->right != NULL)
    {
        postorder(n->right);
    }   
    // 3. 노드를 방문한다.
    cout<<n->val<<endl;
}
```
## 레벨 순회
- 레벨별로 순회하며 각 노드를 방문한다.
- level1 -> level2 -> ... -> levelN
```cpp
void levelorder(node* root)
{
    queue<node*> q;
    q.push(root);
    while (!q.empty())
    {
        node* front = q.front();
        visit[front->data] = 1;
        if (front->left != NULL)
        {
            q.push(front->left);
        }
        if (front->right != NULL)
        {
            q.push(front->right);
        }
    }
}

```
## 예제
![tree](https://user-images.githubusercontent.com/21440957/65881994-3f39d180-e3cf-11e9-8068-f6b5b2e87f8a.png)

<details close> <summary> 전위 순회 </summary>

- F, B, A, D, C, E, G, I, H 

</details>
<details close> <summary> 중위 순회 </summary>

- A, B, C, D, E, F, G, H, I 

</details>
<details close> <summary> 후위 순회 </summary>

- A, C, E, D, B, H, I, G, F

</details>
<details close> <summary> 레벨 순회 </summary>

- F, B, G, A, D, I, C, E, H

</details>

## 참조
- [Wiki](https://ko.wikipedia.org/wiki/%ED%8A%B8%EB%A6%AC_%EC%88%9C%ED%9A%8C)
