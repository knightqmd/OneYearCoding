#   git的分支操作
>当程序需要引入新的功能或者特性的时候我们需要引入分支的概念，将稳定版本设为master版本，而引入新功能的版本则被设为分支版本。举个例子来说，当我需要开发游戏时，游戏一开始只有大逃杀模式，而此时我们需要为游戏开发新的玩法，于是就要开发一种新的竞技场模式。但由于竞技场模式有很多的bug暂时不能上线，而其他程序员需要继续对大逃杀原本的游戏内容进行更新，此时我们就要为竞技场模式建立一个分支，等该模式开发好了之后再将其合并入master，而不是和大逃杀模式一样持续在master进行开发，从而导致master内容遭到新加入内容的影响（新模式有bug也不会对大逃杀模式的日常更新造成影响）。


![分支示意图](./image/%E5%88%86%E6%94%AF%E7%A4%BA%E6%84%8F%E5%9B%BE.png#pic_center)

##  分支的操作
|命令名称|作用|
|:-----|:----|
|git branch $BRANCHNAME|创建分支|
|git branch -v|查看分支|
|git checkout $BRANCHNAME|切换分支|
|git merge $BRANCHNAME |合并分支|


#   github的基本使用
1. 在github上创建远程库
2. 在本地端为远程库创建别名
```shell
    git remote -v   #查看当前所有远程地址别名
```
3. 增加远程地址别名
    **git remote add [别名] [远程地址]**
```shell
    git remote add $NAME $ADDRESS
```
4. 将本地库推送至远程库（如果推送失败记得使用魔法）
   **推送是推送本地库的分支 git push [别名/远程库地址] [要推送的分支]**
```shell
    git push $NAME $BRANCH
    $ git push OneYearCoding master
    Enumerating objects: 22, done.
    Counting objects: 100% (22/22), done.
    Delta compression using up to 16 threads
    Compressing objects: 100% (12/12), done.
    Writing objects: 100% (22/22), 76.72 KiB | 15.34 MiB/s, done.
    Total 22 (delta 3), reused 0 (delta 0), pack-reused 0
    remote: Resolving deltas: 100% (3/3), done.
    To https://github.com/knightqmd/OneYearCoding.git
    * [new branch]      master -> master

```
5. git clone [远程库地址]  #克隆远程库，该操作会拉取远程代码，并且自动创建本地库，并且为其创建别名默认为Origin
   **建议使用git clone -o [别名] [远程库地址]**
6. 将修改好的代码上传至github
```bash
    git push https://github.com/knightqmd/***.git master
```
7. 合作时需要远程仓库作者授予权限
   