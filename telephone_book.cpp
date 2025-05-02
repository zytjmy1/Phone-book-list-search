// 电话簿.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <windows.h> // 需要包含此头文件

using namespace std;

// 插入str中从idx开始所有连续字符串
void search(int idx, const string str,map<string,string>&mymap)
{
    int len = str.length();
    string temp = "";
    for (int i = idx;i < len;i++)
    {
        temp += str[i];
        // map中没有temp的话，插入
        if (!mymap.count(temp))
            mymap[temp] = str;
    }
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    ifstream file(R"(./text_files/Chinese-namebook.txt)");
    ofstream out("./output/output.txt", ios::out | ios::binary); // 改这里
    out << "\xEF\xBB\xBF"; // 写入 UTF-8 BOM
    // 判断是否成功打开
    if (!file.is_open()) {
        cerr << "无法打开文件" << endl;
        return 1;
    }
    string line, chs = "aeiou",py = "";
    map<string, string> mymap;
    int cnt = 0;
    vector<int> index;
    index.push_back(0);
    // 读取一行
    // line就是weizihao
    cout << "我的名单是" << endl;
    out << "我的名单是" << endl;
    while (getline(file, line)) {
        cout << "第" << cnt << "位同学是:" << line << endl;
        out << "第" << cnt << "位同学是:" << line << endl;
        // 找一行中的所有单个字组合
        int len = line.length();
        for (int i = 1;i<len;i++)
        {
            // 前一个是元音，后一个不是元音，
            // 此时要开始插入一个拼音
            // 这里的代码逻辑可以优化，重复计算了前后是否为元音
            if (chs.find(line[i-1]) != string::npos && chs.find(line[i]) == string::npos)
            {
                index.push_back(i);
            }
        }
        // 根据index把所有模糊查找补充map
        for (int elem : index)
        {
            search(elem, line, mymap);
        }
        cnt++;

    }

    cout << endl << "===============================================" << endl<<endl;
    //string temp;
    //cin >> temp;
    //if (mymap[temp] != "")
    //    cout << mymap[temp] << endl;
    //else
    //    cout << "没找到！";
    
    // 打开测试用例文件
    ifstream infile(R"(./text_files/Test_Cases.txt)");
    if (!infile.is_open()) {
        cerr << "无法打开 testcases.txt 文件！" << endl;
        return 1;
    }

    string temp,detail;
    while (getline(infile, temp)) {
        cout << "我的用例是" << temp << endl;
        out << "我的用例是" << temp << endl;
        if (mymap.count(temp))  // 更安全地判断 key 是否存在
        {
            cout << "我的答案是" << mymap[temp] << endl;
            out << "我的答案是" << mymap[temp] << endl;

        }
        else
        {
            cout << "没找到！" << endl;
            out << "没找到！" << endl;

        }
        cout << endl;
        out << endl;
    }
    out.close(); // 关闭输出文件
    file.close(); // 关闭文件
    cout<<endl<<"===============================================" << endl;
    cout<<"所有文件已输出到.\output\output.txt!"<<endl<<endl;

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
