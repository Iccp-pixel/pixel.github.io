

#include <iostream>


using namespace std;

void encryption(string& c, int a[]) {

	for (int i = 0, j = 0; c[j]; j++, i = (i + 1) % 7) {

		c[j] += a[i];

		if (c[j] > 122) c[j] -= 90;
	}
}
void decode(string& c, int a[]) {

	for (int i = 0, j = 0; c[j]; j++, i = (i + 1) % 7) {

		c[j] -= a[i];

		if (c[j] < 32) c[j] += 90;
	}
}



void main()
{

	int a[] = { 4, 9, 6, 2, 8, 7, 3 };

	string s, s1;

	cout << "请输入字符串：";

	cin >> s;

	s1 = s;

	encryption(s, a);

	cout << "加密后密文：" << s << endl;

	decode(s, a);

	//cout << s << endl;
	if (s1 == s) cout << "解密后：" << s;

	else cout << "解密错误！";


}