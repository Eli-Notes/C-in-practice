#include <iostream>
#include <string>
using namespace std;

int main() {

	// ������Ҫ����
	string s;    // �洢�����������ӵ�����
	int L;       // �洢�����ַ�����
	int L1;      // �洢��һ�������ֵĳ���
	int L2;      // �洢�ڶ��������ֵĳ���
	string s1;   // �洢��һ����
	string s2;   // �洢�ڶ�����
	string sout; // �洢����Ľ��
    
	// ����s�����ֳ�s1��s2
	cin >> s;
	L = s.size();
	for (int i = 0; i < L; i++) if (s[i] == '+') L1 = i;
	L2 = L - 1 - L1;
	for (int i = 0; i < L1; i++) s1 = s1 + s[i];
	for (int i = L1 + 1; i < L; i++) s2 = s2 + s[i];

	// ���s1��s2������洢��sout�������sout
	int flag = 0;                             // ���ڱ�ʾ��λ������Ҫ��λʱ����Ϊ1������Ϊ0
	for (int i = 0; i < L1 | i < L2; i++) {
		int a = 0, b = 0;
		if (i < L1) a = s1[L1 - i - 1] - '0'; // a��s1���������i+1�����֣�����s1�ĳ���ʱ��ֵΪ0
		if (i < L2) b = s2[L2 - i - 1] - '0'; // b��s2���������i+1�����֣�����s2�ĳ���ʱ��ֵΪ0
		string c = to_string(a + b + flag);   // cΪa��b��ӵĽ��(�ַ�����ʽ)��flag��ʾ��λ����1��0��
		flag = 0;                             // ����ѭ���ù�flag֮������Ϊ0
		if (c.size() == 1) sout = c + sout;   // c<10ʱ��ֱ�����c������Ҫ��λ
		else sout = c[1] + sout, flag = 1;    // c>=10ʱ����һ��ѭ����λ��������flagΪ1
	}
	cout << sout << endl;

	return 0;
}

