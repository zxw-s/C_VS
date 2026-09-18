> 和`.gitignore`一起放在 sln 同级目录

# 项目名称

简短描述项目功能，例如：C语言练习，熟悉VS Code

## 项目介绍

简单介绍这个项目实现了什么功能，用到的技术。

- 开发IDE：Visual Studio
- 开发语言：C
- 项目类型：控制台应用

## 环境要求

- Visual Studio 2019 / 2022 /2026
- 安装对应组件：
  - C++：使用C++的桌面开发
  - C#：.NET桌面开发

## 编译 & 运行

1. 使用Visual Studio打开 `.sln` 解决方案文件
2. 在上方选择 `Debug` / `Release` 配置，选择x64或x86平台
3. 点击【本地Windows调试器】运行程序

## 目录结构



# Visual Studio 图形化上传项目到GitHub

> 前提：
> 
> 1. 已经建好VS项目，**项目sln根目录放好`.gitignore`和README.md**
> 2. VS安装时勾选【Git】组件；登录GitHub账号

## 方式一：新项目，直接在VS创建Git仓库并推送（推荐）

1. 打开你的VS解决方案 `.sln`

2. 顶部菜单：**Git → 创建Git存储库**

3. 在弹窗中选择：**GitHub**

4. 登录GitHub账号（浏览器授权）

5. 填写仓库名称、项目描述；选择【Public公开 / Private私有】

6. 勾选：**添加README**（可选，你已经有README就不用勾）

7. `.gitignore`模板选择：`VisualStudio`（我们之前写好的也可以直接用）

8. 点击右下角 **创建并推送（Create and Push）**
   
   > ✅ 自动完成：本地git初始化 + 创建GitHub远程仓库 + 一次性推送到GitHub

## 方式二：本地已有项目，GitHub网页先建好空仓库，再在VS关联

1. GitHub网页新建**空仓库**（不要勾选Add README，避免冲突），复制仓库地址
2. VS打开项目 → 顶部菜单 **Git → 创建Git存储库**
3. 左侧选择【现有远程】，粘贴刚刚复制的GitHub仓库地址
4. 本地路径自动识别为当前sln目录，点【创建】
5. 打开 **Git更改** 面板（视图 → Git更改）
6. 查看变更列表：
   - 文件前面`+`代表新增；确认`.vs/ bin/ obj/`不会出现（.gitignore生效）
   - 点击**暂存全部**（加号按钮），文件进入【已暂存的更改】
7. 在上方输入**提交信息**，示例：`init:项目初始化`
8. 点击【提交暂存内容】（提交到本地仓库）
9. 在Git更改面板上方，点**推送（向上箭头）**，代码上传GitHub

## ✅ 后续日常修改提交流程（图形化）

1. 修改代码，保存

2. 打开【Git更改】面板，查看改动文件

3. 暂存全部 → 写提交备注 → 提交暂存内容

4. 点【推送】上传到GitHub
   
   > 配套按钮说明：
   > 
   > - 拉取（向下箭头）：把GitHub远程代码下载到本地
   > - 同步：先拉取远程最新代码，再推送本地提交（等价git pull+push）

## 分支图形化操作

1. 底部状态栏可以看到当前分支（默认main）
2. 点击分支名 → 新建分支，输入分支名，自动切换
3. 分支提交代码后，切换回main分支，点击**合并**，VS可视化处理合并冲突

## 冲突可视化解决

当拉取代码出现冲突：

1. VS弹出合并编辑器，左右窗口：左侧本地代码，右侧远程代码
2. 选择保留【传入更改】/【保留当前】/【同时保留】
3. 解决完所有冲突，完成合并，再提交+推送

## ⚠️新手避坑

1. 提交前看一眼变更列表，**绝对不要提交.vs、bin、obj文件夹**，.gitignore要放在sln同级
2. 如果远程仓库自带README，首次推送会报错：点【拉取】同步一次，再提交推送
3. 中文文件名尽量少，防止编码异常
4. 找不到Git菜单：安装VS时勾选【Git for Windows】组件

## VS Git面板常用入口

- 视图 → Git更改（最常用）
- 视图 → Git仓库（查看提交记录、分支）
- 视图 → 团队资源管理器（旧版VS）

# VS项目上传GitHub完整Git命令清单

> 前提：已经在项目sln根目录放好 `.gitignore` 和 `README.md`

## 1. 初始化本地仓库（只执行一次）

打开 **Git Bash**，cd 进入你的解决方案（`.sln`）所在文件夹

```bash
# 进入项目根目录（替换成你自己文件夹路径）
cd D:/code/VSProject

# 初始化git仓库
git init
```

## 2. 查看文件状态

```bash
git status
```

红色文件代表未跟踪，确认没有不该提交的文件（bin、obj、.vs 被.gitignore过滤就正常）

## 3. 添加文件到暂存区

```bash
# 添加所有源码文件
git add .
```

## 4. 提交到本地仓库

```bash
git commit -m "init: 项目初始化，基础代码提交"
```

> commit 规范示例：
> 
> - `feat: 新增学生添加功能`
> - `fix: 修复中文乱码bug`
> - `refactor: 代码重构`

## 5. 关联远程GitHub仓库

先在GitHub网页新建空仓库，复制仓库地址，执行下面命令：

```bash
git remote add origin https://github.com/你的用户名/仓库名.git
```

> 查看远程仓库：`git remote -v`

## 6. 推送到GitHub

```bash
# 首次推送
git push -u origin main
```

> 后续提交只需要：

```bash
git add .
git commit -m "描述本次修改"
git push
```

## 7. 常用配套命令

```bash
# 拉取远程更新（多人协作）
git pull origin main

# 查看提交日志
git log

# 撤销暂存（git add后反悔，不删除文件）
git reset HEAD .
```

## 8. 新手避坑

1. 不要手动提交 `.vs/ bin/ obj/`，`.gitignore`已经配置过滤
2. 首次推送报错：
   - 远程仓库有README时，先执行：`git pull origin main --allow-unrelated-histories`
3. 文件名中文尽量少，防止编码问题
4. 每次提交前 `git status` 检查一遍，防止误提交敏感信息

## 简易工作流（记住这个流程）

`git status` → `git add .` → `git commit -m "备注"` → `git push`
