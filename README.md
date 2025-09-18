# leetCode
private leetcode practice

# GCC (G++) 与 GDB 开发调试速查指南

## 一、G++ 关键编译选项

| 选项 | 说明 |
|:---|:---|
| `-g` | **包含调试信息**，GDB 调试必需 |
| `-Wall` | 开启几乎所有常用警告 |
| `-Wextra` | 开启额外警告 |
| `-Werror` | 将所有警告视为错误 |
| `-O0` | 关闭优化（调试时使用） |
| `-O2`/`-O3` | 高强度优化（发布时使用） |
| `-std=c++11` | 指定 C++ 标准（如 c++14, c++17, c++20） |
| `-Iinclude_dir` | 添加头文件搜索路径 |
| `-Llib_dir` | 添加库文件搜索路径 |
| `-llibrary_name` | 链接指定库（如 `-lm` 数学库） |

## 二、G++ 基本命令

```bash
# 编译单个文件（输出 a.out）
g++ main.cpp

# 编译并指定输出文件名
g++ main.cpp -o program

# 编译多个文件
g++ main.cpp utils.cpp -o program

# 分步编译
g++ -g -Wall -c main.cpp -o main.o
g++ -g -Wall -c utils.cpp -o utils.o
g++ main.o utils.o -o program

# 完整编译命令（推荐）
g++ -g -Wall -O0 -std=c++17 main.cpp utils.cpp -o program -lm
```

## 三、GDB 核心调试命令

| 命令 | 简写 | 功能 |
|:---|:---|:---|
| `run` | `r` | 开始运行程序 |
| `start` | | 开始运行并在 main() 暂停 |
| `break <location>` | `b` | 设置断点（函数/行号/文件:行号） |
| `continue` | `c` | 继续运行至下一个断点 |
| `next` | `n` | 单步跳过（不进入函数） |
| `step` | `s` | 单步进入（进入函数内部） |
| `finish` | `fin` | 执行完当前函数 |
| `print <expr>` | `p` | 打印表达式值 |
| `display <expr>` | `disp` | 每次暂停时自动打印表达式值 |
| `backtrace` | `bt` | 显示调用栈（定位崩溃） |
| `frame <n>` | `f` | 切换到调用栈的第 n 帧 |
| `info breakpoints` | `i b` | 查看所有断点信息 |
| `delete <n>` | `d` | 删除编号为 n 的断点 |
| `watch <expr>` | | 设置观察点（值改变时暂停） |
| `list` | `l` | 显示当前位置周围的源代码 |
| `quit` | `q` | 退出 GDB |

## 四、调试示例流程

```bash
# 1. 使用调试选项编译
g++ -g -Wall -O0 -std=c++17 main.cpp -o program

# 2. 启动 GDB
gdb ./program

# 3. 在 GDB 中设置断点并运行
(gdb) b main
(gdb) b utils.cpp:15
(gdb) run

# 4. 使用调试命令
(gdb) n        # 单步执行
(gdb) p var    # 查看变量
(gdb) bt       # 查看调用栈（崩溃时）
(gdb) c        # 继续运行

# 5. 退出
(gdb) q
```
