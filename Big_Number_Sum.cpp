/* Big number sum

Input: 123+999
Output: 1122
by Zhang Qian, Apr 2019

*/
#include <iostream>
#include <string>
using namespace std;

int main() {

	// Pre-define
	string s;    // input, eg. 123 + 321
	string s1;   // first number, eg. 123
	string s2;   // second number , eg. 321
	string sout; // output
	int L;       // length of s
	int L1;      // length of s1
	int L2;      // length of s2

	// input s and split into s1 and s2
	cin >> s;
	L = s.size();
	for (int i = 0; i < L; i++) if (s[i] == '+') L1 = i;
	L2 = L - 1 - L1;
	for (int i = 0; i < L1; i++) s1 = s1 + s[i];
	for (int i = L1 + 1; i < L; i++) s2 = s2 + s[i];

	// sum s1 and s2 by summing each digit from right to left
	int flag = 0; // add one or not: 1 yes, 0 no.
	for (int i = 0; i < L1 | i < L2; i++) {
		// get the digit
		int a = 0, b = 0;
		if (i < L1) a = s1[L1 - 1 - i] - '0';           // a is the i+1 digit from the right of s1
		if (i < L2) b = s2[L2 - 1 - i] - '0';           // b is the i+1 digit from the right of s2
		// sum the digit and reset flag
		string c = to_string(a + b + flag);             // c = a + b + flag
		if (c.size() == 1) sout = c + sout, flag = 0;   // if c < 10, append c and set flag = 0
		else sout = c[1] + sout, flag = 1;              // if c >= 10, append c[1] and set flag = 1
		// for the digit on the left
		if (!(i + 1 < L1 | i + 1 < L2)) sout = '1' + sout;
	}

	// return
	cout << sout << endl;
	return 0;
}
