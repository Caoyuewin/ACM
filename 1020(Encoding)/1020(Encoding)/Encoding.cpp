#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>

int main() {
	int N;
	std::cin >> N;
	//str�洢����
	std::string str;
	while (N) {
		//encode_str�洢���
		std::string encoded_str;
		std::cin >> str;
		//count������ǰ��ĸ����
		int count = 0;
		//tmp���浱ǰ��������ĸ
		char tmp = str[0];
		for (size_t i = 0; i < str.size(); ++i) {
			//�����tmp���˵����ǰ��ĸ�����ظ�
			if (str[i] == tmp)
				count++;
			//��������֤��tmp��Ӧ����ĸ�Ѿ��������
			//��һ������Ϊ�˱�֤���һ����ĸ�ܹ��ɹ�����
			if((str[i] != tmp) || (i == str.size() -1)) {
				if (count > 1) {
					//����ת�ַ���num_str��������ת�ַ�������ַ���
					char num_str[1000];
					//sprintf����������ת�����ַ���������������˼����count��ʮ����(%d)ת�����ַ�����������num_str��
					sprintf(num_str, "%d", count);
					//C++�е�string֧��+=��������˼����ĩβ׷�ӡ�����׷���ַ����ִ���
					encoded_str += num_str;
				}
				//����׷���ַ�����
				encoded_str += tmp;
				//tmp��ʼ������һ���ַ�
				tmp = str[i];
				//count��1
				count = 1;
			}
		}
		std::cout << encoded_str << std::endl;
		N--;
	}
	return 0;
}