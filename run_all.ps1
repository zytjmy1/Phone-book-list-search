#!/bin/bash

# 创建虚拟环境在项目根目录
python3 -m venv .venv

# 激活
.venv\Scripts\activate     # Windows

# 安装依赖
pip install -r requirements.txt


# Step 1: 运行 Python 脚本
python chinese2pinyin.py

# Step 2: 编译 C++ 源码
g++ telephone_book.cpp -o telephone_book.exe

# Step 3: 运行编译好的 C++ 程序
./telephone_book.exe
