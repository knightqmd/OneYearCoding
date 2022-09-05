#   git的使用

1. 进入git官网下载对应版本git ---win64版本

2. 安装git
```bash
git config global User.name $NAME ---建立用户名，用以区分哪个用户提交的代码
git config global User.email $YOUREMAIL
```
3. 建立用于存放git项目的文件夹
##  1.git命令

 ```shell
 git init
#output 
EX:Initialized empty Git repository in C:/UserApp/OneYearCodingLife/.git/
```
```shell
git status
#output
On branch master
No commits yet
nothing to commit (create/copy files and use "git add" to track)
```
```bash
git add $YOURFILENAME   //将文件添加至暂存区
```
*此时使用git status查看*
```shell
$ git status
On branch master

No commits yet

Changes to be committed:
  (use "git rm --cached <file>..." to unstage)
        new file:   gitLearning/git install.md

```
**注意此时文件已经被存入暂存区，按照上述代码提示可以删除提交至暂存区的文件，工作区的文件是不会被删除的**
```shell
#将暂存区的文件提交至本地库，并附加版本信息
git commit -m "first time commit，sth about git basic use" $FILENAME

$ git commit -m "first time commit, md about basic git command" gitLearning/
[master (root-commit) 9843275] first time commit, md about basic git command
 1 file changed, 29 insertions(+)
 create mode 100644 gitLearning/git install.md

```
**产看日志信息**
```bash
git reflog
git log       #查看详细日志信息
```
##  2.修改文件并提交

1. 对文件进行修改补充
2. git status查询状态
```bash
    $ git status
On branch master
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   git install.md

   ```
**此时发现该文件已经被修改，并且没有提交至暂存区**
3. 将文件添加至暂存区，并且提交到本地库
```bash
git add 
```
##  查看历史版本
1. 产看日志信息
```bash
git log
git reflog
```
2. 版本穿梭
   1. 通过版本信息查看版本号
   2. 找到需要穿梭的版本号
   3. 使用git reset --hard $VERSION
```bash
git reset --hard $VERSION

$ git reset --hard 9843275
HEAD is now at 9843275 first time commit, md about basic git command
```
