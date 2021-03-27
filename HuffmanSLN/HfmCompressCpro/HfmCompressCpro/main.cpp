#include "pch.h"
#include<iomanip>
#include <iostream>
#include "Compress.h"
#include"Huffman.h"
using namespace std;

int main()
{
	cout << "=========Huffman文件压缩=======" << endl;
	cout << "请输入文件名：";
	char filename[256];
	cin >> filename;
	if (Compress(filename) == 1) {
		cout << "\n完成！" << endl;
	}
	else {
		cout << "\n失败" << endl;
	}
	return 0;
}