

/*
www.小空格.com

*/


#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include  <direct.h>  
#pragma comment(lib,"URlmon")


using namespace std;


//Download data
void download()
{
	char buffer[MAX_PATH];
	_getcwd(buffer, MAX_PATH);
	strcat_s(buffer, "//U disk.zip");
	HRESULT Result = URLDownloadToFileA(NULL, "http://bmob-cdn-24520.b0.upaiyun.com/2019/04/17/874a003c40802b038094e5875d6ac966.zip", buffer, 0, NULL);
	switch (Result)
	{
	case S_OK:

		printf("数据下载成功。\n");
		cout << endl
			<< "文件解压密码：udisk" << endl;


		break;

	case E_OUTOFMEMORY:

		printf("缓冲区长度无效，或者内存不足，无法完成该操作。\n");

		break;
	}

}


//Deal With
void decode(string& c, int p[])
{
	for (int i = 0, j = 0; c[j]; j++, i = (i + 1) % 7) {
		c[j] += p[i];
		//if (c[j] < 32)c[j] += 9;	//decode
		if (c[j] > 122) c[j] -= 90;	//encryption
	}

}


int main()
{

	system("color f2");
	system("title Locked");

	cout << endl
		<< "请输入访问码！"
		<< endl
		<< "http://coolc.club"
		<< endl
		<< endl
		<< "Tips：在文件夹中打开本程序"
		<< endl
		<< endl;

	int key[] = { 4, 9, 6, 2, 9, 7, 3, 7, 7, 9 };
	string password, contrast = ";9;2>844@";

	cin >> password;
	decode(password, key);
	//contrast = password;

	cout << endl << "正在解码..." << endl << endl;
	Sleep(2000);

	if (password == contrast)
	{
		cout << "解码成功！"
			<< endl << endl
			<< "正在下载数据..."
			<< endl << endl;
		download();

	}
	else
	{
		cout << endl << "错误！" << endl;
	}


	cout << "输入任意字符退出" << endl;

	int exit;
	cin >> exit;

	return 0;



}



