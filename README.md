# Chinese Namebook Search
## 📖 Overview
A C++ program to process Chinese names from Chinese-namebook.txt, perform fuzzy pinyin searches, and match test cases from Test_Cases.txt. Outputs results to console and output.txt in UTF-8.
✨ Features

Reads and processes Chinese names.
Fuzzy pinyin substring search.
Matches test cases with names.
UTF-8 console and file output.
Error handling for file operations.

## 📂 Project Structure

Source: TelephoneBook.cpp
Input:
text_files/Chinese-namebook.txt: List of names.
text_files/Test_Cases.txt: Pinyin test cases.


Output: output/output.txt: Search results.

## 🚀 How It Works

Using the pypinyin package in python to read names from Chinese-namebook.txt,
Generates pinyin substrings and stores in a Fuzzy search map in C++.
Matches pinyin test cases from Test_Cases.txt.
Outputs results to console and output.txt.

## 🛠️ Prerequisites

C++11+ compiler (e.g., MSVC, GCC).
Windows (uses windows.h for UTF-8 console)
UTF-8 encoded input files.

==which is the most important thing: keep every text file to be encoded as UTF-8!==

==which is the most important thing: keep every text file to be encoded as UTF-8!==

==which is the most important thing: keep every text file to be encoded as UTF-8!==

## 🔧 Build & Run

First of all, make sure the "run_all.ps1" file is in your project root directory.

Then, you need to run the instruction as follow:
~~~bash
.\run_all.ps1
~~~
After that, you could see the output in the "output" folder.

## 📋 Example
Input (Chinese-namebook.txt):
魏子豪
张伟杰
吴子墨

Test Cases (Test_Cases.txt):
wei
zi
hao

Output (output.txt):
我的名单是
第0位同学是:魏子豪
第1位同学是:张伟杰
第2位同学是:吴子墨

===============================================

我的用例是wei
我的答案是魏子豪

我的用例是zi
我的答案是吴子墨

我的用例是hao
我的答案是周雨浩

## ⚠️ Notes

Ensure input files are UTF-8 encoded.
Use PowerShell or VS Code terminal for proper UTF-8 console output.
Optimize substring generation for better performance.

## 🐛 Troubleshooting

File Not Found: Verify text_files directory and files.
Garbled Text: Check file encoding and console UTF-8 support.
Build Issues: Ensure C++11+ and required headers.

## 📜 License
For educational use. Modify and share freely.
