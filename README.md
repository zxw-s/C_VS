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

> Visual Studio（简称VS）：微软完整IDE，体积大，主打C#、C++、.NET、Windows桌面、Unity开发，Windows为主。**社区版 Community** 完全免费
> 
> VS核心概念：**解决方案(Solution .sln)** 可以包含多个**项目(Project .vcxproj / .csproj)**。
> 
> 项目路径、项目名称**禁止中文、空格**，避免编译报错。

# 一、安装（VS Installer）

1.下载Visual Studio Installer

官网：[https://visualstudio.microsoft.com/zh-hans/](https://visualstudio.microsoft.com/zh-hans/)

可选择 Visual Studio 2022 社区版（Community），免费个人使用。

2.安装程序会弹出组件勾选，按你的方向**勾选工作负载（必须勾选，否则没有对应模板）**

✅ C++开发：勾选 使用C++的桌面开发

✅ C# / .NET桌面、控制台：勾选 .NET桌面开发

✅ Unity游戏开发：勾选 Unity游戏开发

✅ Web后端：ASP.NET 和 Web开发

✅Python：Python开发（可选）

> 不需要的不要勾，不要全部安装，体积巨大；安装路径建议D盘；安装路径不要中文。

# 二、常用设置优化

打开选项：`工具 → 选项`

## 1. 编辑器外观

- 环境 → 字体和颜色：字体 `Consolas`，字号 14。
- 文本编辑器 → C/C++ → 常规：勾选**显示行号**。

## 2. 中文乱码（Windows 高频）

VS 默认 MSVC 编码 GBK；两种方案：

1. 编辑器乱码：文件 → 高级保存选项，编码选择 `UTF‑8 带签名`。
   
   > 找不到高级保存选项：工具 → 自定义 → 命令，把该命令添加到文件菜单。

2. 控制台乱码：项目属性 → C/C++ → 命令行，附加选项填入：`/utf‑8`，全局 UTF‑8 模式；确定，**重新生成解决方案**。

3. 代码兜底：main第一行写

```c
SetConsoleOutputCP(65001);
```

> 控制台输出中文乱码，优先加 `/utf‑8`编译选项。

## 3. 项目属性（右键项目→属性）

- 常规 → C 语言标准：C17；C++ 标准：C++17
- 平台：x64（推荐，不要用 x86）
- 配置分为 Debug（调试，带调试信息） / Release（发布，优化）

## 4. 多文件项目操作

1. 右键【源文件】→ 添加 → 新建项，新增`.c/.cpp`
2. 右键【头文件】→ 添加 → 新建项，新增`.h`头文件

> VS 不需要手动写 CMakeLists，加入项目树自动参与编译。

# 三、核心快捷键（VS 最重要）

| 快捷键            | 功能                 |
| -------------- | ------------------ |
| `Ctrl+S`       | 保存                 |
| `Ctrl+/`       | 注释选中代码             |
| `Ctrl+Shift+B` | 仅编译生成              |
| `F9`           | 设置 / 取消断点（行号左侧红点）  |
| `F5`           | **启动调试**           |
| `Ctrl+F5`      | 不调试直接运行（防止控制台一闪而过） |
| `F10`          | 逐过程调试，单步跳过函数       |
| `F11`          | 逐语句调试，进入函数内部       |
| `Shift+F11`    | 跳出当前函数             |
| `Shift+F5`     | 停止调试               |
| `Ctrl+Shift+B` | 仅生成（编译）项目          |

# 四、新手常见坑

1. ❌ 文件夹、项目名不能中文，否则编译各种诡异报错

2. ❌ 新建项目不要选错模板，写C++就选C++控制台，不要选空项目忘记加.cpp文件

3. ❌ 运行一闪而过：用  Ctrl+F5  运行，或者代码末尾加  system("pause"); 

4. ❌ 安装的时候没有勾选对应工作负载，会找不到模板，需要重新运行安装程序修改组件。

# 五、新建 C/C++/C# 控制台项目

打开VS → 创建新项目 → 搜索：`空项目/控制台应用`，选择模板 → 下一步

1. 创建新项目

2. 选模板：

- C++控制台：空项目 / 控制台应用

- C#控制台：控制台应用(.NET Framework / .NET)

3. 下一步：填写项目名称（英文），位置路径不要中文、空格

4. 创建。

> ✅ C 语言也直接用 C++ 控制台项目，写`.c`源码即可。

**概念区分**

- 解决方案(Solution)：可以放多个项目

- 项目(Project)：一个程序

新手：一个解决方案里放1个项目即可。

## VS 项目目录结构

```plaintext
DemoVS/
├── DemoVS.sln                #【解决方案文件】双击打开整个工作空间，提交Git
├── DemoVS/                   # 项目文件夹
│   ├── DemoVS.vcxproj        # 项目配置文件，提交Git
│   ├── DemoVS.vcxproj.filters # 文件分组配置
│   ├── main.c / main.cpp     # 源代码
│   ├── 源文件/头文件/          # 逻辑分组文件夹
│   └── x64/                  # Debug/Release编译产物，exe、obj，不要提交Git
└── .vs/                      # VS本地缓存，个人配置，**绝对不要提交Git**，自动生成
```

## .gitignore VS 模板

```gitignore
# VS本地缓存
.vs/
*.suo
*.user
*.userosscache

# 编译输出
[Dd]ebug/
[Rr]elease/
x64/
x86/
bin/
obj/

# 中间编译文件
*.obj
*.pdb
*.ilk
*.ipch
*.VC.db
```

> `.sln`、`.vcxproj`、`.vcxproj.filters` **需要提交 Git**；`.vs/`、x64 全部忽略GitHub。

# 六、编写代码、运行、调试

右键源文件 → 添加 → 新建项 → C/C++/C#/Python文件(.c/.cpp/.cs/.py)

## 编写代码

C示例main.c

```c
#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

int main(void)
{
    int a = 10;
    int b = 25;
    int res = add(a,b);
    printf("计算结果：%d\n", res);
    return 0;
}
```

C++示例main.cpp

```cpp
#include <iostream>

using namespace std;

int main()
{
    cout << "你好，VS！" << endl;
    return 0;
}
```

C#示例Program.cpp

```csharp
using System;

namespace DemoCs
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello VS C#！");
        }
    }
}
```

调试快捷键和 C++ 完全一致；项目文件后缀`.csproj`。

## 运行和调试

顶部工具栏：

- ▶️ 本地Windows调试器：编译+运行+调试

快捷键： F5 （调试运行）； Ctrl+F5 （直接运行，不调试）

> 调试时下方：**自动窗口、局部变量窗口**，实时观察变量值。

### 新手高频坑：控制台一闪而过

方案 1：运行用 `Ctrl+F5`（不调试启动），程序结束会暂停。

方案 2：代码末尾加 `getchar();`。

# 七、VS 和 VS Code怎么选

- 做 C++桌面、C#、Unity游戏 → 优先 Visual Studio

- Python、前端、轻量写代码 → VS Code

你是想学 C++ / C# / Unity？我可以给你一份最简上手步骤。

# 八、Visual Studio 全家桶乱码速记（Windows）

> 切记：项目路径/文件名禁止中文；**不要开启Windows Beta全局UTF‑8**。

## 1. C / C++（MSVC编译器）

1. 文件：文件 → 高级保存选项 → **UTF‑8 带BOM(65001)**
2. 项目属性 → C/C++ → 命令行 → 其他选项：

```plaintext
/utf-8
```

3. 代码兜底main开头：

```python
SetConsoleOutputCP(65001);
```

## 2. C#

1. `.cs` 文件保存：**UTF‑8 with BOM**
2. Main第一行：

```python
Console.OutputEncoding = System.Text.Encoding.UTF8;
Console.InputEncoding = System.Text.Encoding.UTF8;
```

## 3. Python

1. 右键项目 → 属性 → 调试 → 环境变量：

```plaintext
PYTHONIOENCODING=utf-8
```

2. 源码保存 UTF‑8
3. 代码兜底：

```python
import sys
sys.stdout.reconfigure(encoding="utf-8")
```

# 九、常用IDE中文乱码

（VS / VSCode / PyCharm / IDEA / CLion / Dev‑C++）

| IDE     | 语言         | 乱码核心配置                                                |
| ------- | ---------- | ----------------------------------------------------- |
| VS      | C/C++      | 编译参数 `/utf‑8`                                         |
| VS      | C#         | `Console.OutputEncoding`                              |
| VS      | Python     | 环境变量 `PYTHONIOENCODING=utf‑8`                         |
| VSCode  | C/C++(GCC) | `‑finput‑charset=UTF‑8 ‑fexec‑charset=GBK` tasks.json |
| VSCode  | Java       | JVM参数 `-Dfile.encoding=UTF‑8` settings.json           |
| VSCode  | Python     | 项目`.env`写入`PYTHONIOENCODING=utf‑8`                    |
| PyCharm | Python     | 运行配置环境变量 `PYTHONIOENCODING=utf‑8`                     |
| IDEA    | Java       | VM参数 `-Dfile.encoding=UTF‑8`                          |
| CLion   | C/C++      | CMakeLists添加gcc编译字符集参数                                |
| Dev‑C++ | C/C++      | 编译选项添加`‑finput‑charset=UTF‑8 ‑fexec‑charset=GBK`      |

## 通用排查三步法（所有IDE通用）

1. **编辑器乱码**：文件编码不对，另存为对应UTF‑8（部分工具需要BOM）
2. **编辑器正常，运行输出乱码**：编译器参数 / JVM参数 / 环境变量
3. **调试窗口乱码**：字体缺少中文支持，更换Consolas+微软雅黑

## Windows两个代码页

- `chcp 936` → GBK（系统默认）
- `chcp 65001` → UTF‑8

---

# 十、Visual Studio 图形化上传项目到GitHub

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

# 十一、VS项目上传GitHub完整Git命令清单

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

# Visual Studio 2019/2022/2006 开发纯C语言

> VS中C语言不是独立工作负载，安装时勾选 **使用C++的桌面开发**，里面已经包含C编译器MSVC。 `.c`后缀文件VS会自动按照C语言规则编译；`.cpp`按C++编译。

## 新建C语言项目

1. 创建新项目 → **控制台应用**
2. 把自动生成的 `cpp` 文件重命名为 `main.c`

main.c

```c
#include <stdio.h>
#include <windows.h>

int main(void)
{
    //SetConsoleOutputCP(65001);
    printf("VS C语言中文测试：你好！\n");
    return 0;
}
```

## ✅中文乱码全套配置（C语言 MSVC）

1. 编辑器乱码：文件 → **高级保存选项** 编码选择：**Unicode(UTF‑8 带签名)‑代码页65001（UTF‑8‑BOM）**

> 找不到高级保存选项：工具 → 自定义 → 命令，把该命令添加到文件菜单。

2. 控制台乱码：项目属性添加编译参数 `/utf‑8`（最重要）
   右键项目 → 属性 → 配置属性 → **C/C++ → 命令行** 其他选项填入：

```plaintext
/utf-8
```

确定，**重新生成解决方案**。

3. 代码兜底：main第一行写

```c
SetConsoleOutputCP(65001);
```

## 常用快捷键

- `Ctrl+Shift+B`：编译
- `Ctrl+F5`：不调试运行
- `F5`：调试运行
- `F10`单步跳过，`F11`单步进入

## 项目结构

```plaintext
C_Demo/
├─ C_Demo.sln        //解决方案
├─ C_Demo.vcxproj    //项目文件
└─ main.c            //C源码
```

## 多文件C项目

直接右键项目 → 添加 → 新建项，新建 `.c`源文件、`.h`头文件。
VS会自动把所有`.c`加入编译，不需要手动写编译命令。

## 高频坑

1. 文件后缀不要写成`.cpp`，写C代码用`.c`。
2. 项目路径、文件夹**禁止中文**。
3. 控制台一闪而过：旧版本可以末尾加 `system("pause");`

```c
#include <stdlib.h>
system("pause");
```

4. VS2022建议开启：工具 → 选项 → 调试 → 常规 → ✅**使用Windows Terminal进行控制台调试启动**，中文体验更好。

## VS C语言和C++简单区别

|      | C语言         | C++         |
| ---- | ----------- | ----------- |
| 文件后缀 | `.c`        | `.cpp`      |
| 编译模式 | C模式         | C++模式       |
| 编译器  | MSVC        | MSVC        |
| 乱码参数 | 同样 `/utf‑8` | 同样 `/utf‑8` |

> MSVC下C和C++乱码配置完全一样，区别只在于文件后缀。

---

# Visual Studio（VS）完整操作步骤（C语言）

文件名：`vs_demo.c` 用来熟悉 VS：新建项目、编辑、编译运行、断点调试。包含变量、数组、函数、指针、结构体。

> VS默认是C++项目，写C要把文件后缀改为 `.c`。

## 1.新建项目

1. 创建新项目 → 选择 **空项目** → 下一步，填写项目名称，创建。
2. 右侧【解决方案资源管理器】→ **源文件** 右键 → 添加 → 新建项 → **C文件(.c)**，命名 `vs_demo.c`，粘贴代码。

## 3.编写代码

```c
#include <stdio.h>

typedef struct Student
{
    int id;
    char name[20];
    double score;
} Student;

// 指针修改结构体分数
void setScore(Student *s, double newSc)
{
    s->score = newSc;
}

// 求数组平均值
double getAverage(int arr[], int len)
{
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        sum += arr[i];
    }
    return (double)sum / len;
}

int main(void)
{
    int nums[4] = {75, 88, 91, 66};
    Student stu = {2001, "李四", 79.5};

    printf("=== Visual Studio C测试程序 ===\n");

    printf("数组元素：");
    for (int i = 0; i < 4; i++)
    {
        printf("%d ", nums[i]);
    }
    double avg = getAverage(nums, 4);
    printf("\n数组平均值：%.2f\n", avg);

    printf("\n修改前学生：id=%d 姓名=%s 分数=%.1f\n", stu.id, stu.name, stu.score);
    setScore(&stu, 93.0);
    printf("指针修改后分数：%.1f\n", stu.score);

    int num;
    printf("\n请输入一个整数：");
    scanf("%d", &num);
    printf("你输入的数字：%d\n", num);

    return 0;
}
```

> `scanf`在VS中被认为是不安全的，编译运行是会有警告，VS中建议用`scanf_s`替代，通过**额外传递缓冲区大小**来防止缓冲区溢出。若仍然想用，可使用警告杂注关闭该警告：`#pragma warning(disable : 4996)`

运行示例：

```plaintext
=== Visual Studio C测试程序 ===
数组元素：75 88 91 66
数组平均值：80.00

修改前学生：id=2001 姓名=李四 分数=79.5
指针修改后分数：93.0

请输入一个整数：100
你输入的数字：100
```

---

## 2.编译运行

- **Ctrl+F7**：编译
- **Ctrl+F5**：不调试直接运行（弹出控制台窗口，不会一闪关闭）
- **F5**：启动调试模式

> ⚠️如果直接F5运行结束闪退：优先用 `Ctrl+F5`。不要滥用 `system("pause")`。

## 3.断点调试（VS最强大）

1. 在代码行号**左侧灰色区域点击**，出现**红色圆点=断点**。
   推荐断点位置：
- `double avg = getAverage(nums, 4);`

- `setScore(&stu, 93.0);`

- `getAverage`、`setScore`函数内部第一行
2. 按 **F5** 启动调试。

小练习任务：

1. 断点打在 `setScore(&stu,93.0);`，F11跳入函数，观察指针修改外部结构体。
2. 在监视窗口输入 `nums[0]`、`stu.score`，观察数值变化。

## VS调试核心快捷键

| 快捷键       | 功能              |
| --------- | --------------- |
| F10       | 逐过程（单步跳过，不进入函数） |
| F11       | 逐语句（跳进函数内部）     |
| Shift+F11 | 跳出当前函数          |
| F5        | 继续运行到下一个断点      |
| Ctrl+F10  | 运行到光标处          |

3. 调试窗口：
- **自动窗口**：自动显示当前作用域所有变量，结构体、数组可以展开查看成员。
- **局部变量窗口**：只看本函数内变量。
- **监视窗口(WATCH)**：手动输入表达式：`stu`、`nums[2]`、`&stu`、`*&stu`，观察指针地址与值。
- **调用堆栈**：查看当前运行在哪个函数（main / getAverage / setScore）。

> 练习：F11跳进 `setScore`，观察指针修改main函数里结构体的分数。

## VS常见坑

1. 新建的是`.cpp`文件：C代码后缀必须改为`.c`，否则按C++编译。
2. `for(int i=0;…)` 在.c文件完全支持，不需要额外配置。
3. scanf输入：就在VS弹出的控制台黑窗口输入。
4. F5直接运行窗口一闪：改用 `Ctrl+F5`（开始执行不调试）。
5. 报错 `scanf不安全`：VS认为scanf有风险。
   两种解决：
   1）代码最顶部加上：

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
```

2）项目属性禁用SDL检查。

---

# 三款工具简单对比总结

| 工具            | 特点          | 调试     | 适合人群     |
| ------------- | ----------- | ------ | -------- |
| Dev‑C++       | 图形零配置，轻量    | 基础，功能弱 | 初学入门     |
| VS‑Code       | 需要配置json，轻量 | 强大     | 练习、写小项目  |
| Visual Studio | 大型IDE，功能最全  | 调试能力最强 | 课程、大项目开发 |

> VS调试体验是三者里面最强：自动窗口、监视、调用堆栈，查看结构体数组非常直观。

# VS下 C / C++ / C# / Python 汇总

| 语言     | 文件后缀    | 工作负载       | 乱码核心                         |
| ------ | ------- | ---------- | ---------------------------- |
| C      | `.c`    | 使用C++的桌面开发 | `/utf‑8`编译参数                 |
| C++    | `.cpp`  | 使用C++的桌面开发 | `/utf‑8`编译参数                 |
| C#     | `.cs`   | .NET桌面开发   | `Console.OutputEncoding`     |
| Python | `.py`   | Python开发   | 环境变量`PYTHONIOENCODING=utf‑8` |
| Java   | `.java` | 无原生支持      | 只能手动javac编译                  |

> 对比小记：
> 
> - VS：C/C#/Python很强；Java弱
> - VSCode：C/C++/Java/Python全能，但是需要手动写配置
> - CLion：C/C++，CMake工程
> - Dev‑C++：入门C/C++
