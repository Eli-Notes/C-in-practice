#include <iostream>
#include <string>
using namespace std;

int main() {

	// 定义重要变量
	string s;    // 存储输入的两个相加的数字
	int L;       // 存储输入字符长度
	int L1;      // 存储第一个大数字的长度
	int L2;      // 存储第二个大数字的长度
	string s1;   // 存储第一个数
	string s2;   // 存储第二个数
	string sout; // 存储输出的结果
    
	// 输入s，并分成s1和s2
	cin >> s;
	L = s.size();
	for (int i = 0; i < L; i++) if (s[i] == '+') L1 = i;
	L2 = L - 1 - L1;
	for (int i = 0; i < L1; i++) s1 = s1 + s[i];
	for (int i = L1 + 1; i < L; i++) s2 = s2 + s[i];

	// 相加s1和s2，结果存储在sout，并输出sout
	int flag = 0;                             // 用于表示进位数，需要进位时设置为1，否则为0
	for (int i = 0; i < L1 | i < L2; i++) {
		int a = 0, b = 0;
		if (i < L1) a = s1[L1 - i - 1] - '0'; // a是s1从右往左第i+1个数字，超过s1的长度时，值为0
		if (i < L2) b = s2[L2 - i - 1] - '0'; // b是s2从右往左第i+1个数字，超过s2的长度时，值为0
		string c = to_string(a + b + flag);   // c为a和b相加的结果(字符串格式)，flag表示进位数（1或0）
		flag = 0;                             // 本轮循环用过flag之后，重置为0
		if (c.size() == 1) sout = c + sout;   // c<10时，直接输出c，不需要进位
		else sout = c[1] + sout, flag = 1;    // c>=10时，下一轮循环进位，故设置flag为1
	}
	cout << sout << endl;

	return 0;
}

