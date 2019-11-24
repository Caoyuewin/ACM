#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>

int main() {
	int N;
	std::cin >> N;
	//str存储输入
	std::string str;
	while (N) {
		//encode_str存储输出
		std::string encoded_str;
		std::cin >> str;
		//count计数当前字母个数
		int count = 0;
		//tmp储存当前计数的字母
		char tmp = str[0];
		for (size_t i = 0; i < str.size(); ++i) {
			//如果与tmp相等说明当前字母仍在重复
			if (str[i] == tmp)
				count++;
			//如果不相等证明tmp对应的字母已经计数完成
			//另一个条件为了保证最后一个字母能够成功编码
			if((str[i] != tmp) || (i == str.size() -1)) {
				if (count > 1) {
					//数字转字符，num_str储存数字转字符串后的字符串
					char num_str[1000];
					//sprintf用来将数字转换成字符串，下面的语句意思：将count以十进制(%d)转换成字符串，储存在num_str中
					sprintf(num_str, "%d", count);
					//C++中的string支持+=操作，意思是在末尾追加。这里追加字符出现次数
					encoded_str += num_str;
				}
				//这里追加字符种类
				encoded_str += tmp;
				//tmp开始计数下一个字符
				tmp = str[i];
				//count置1
				count = 1;
			}
		}
		std::cout << encoded_str << std::endl;
		N--;
	}
	return 0;
}