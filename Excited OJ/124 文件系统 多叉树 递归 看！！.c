/*
Description
���ںܶ����ϵͳ���ļ�ϵͳ���ǻ������νṹ��Ƶġ���һ��Ŀ¼�¿��������ɸ�Ŀ¼���ļ�����ÿ��Ŀ¼���ļ�������ͨ��һ���Ӹ�Ŀ¼������Ψһ·����Ψһȷ��������ϣ����ʵ�ֶ�������һ���ļ�ϵͳ�ļ򵥹���
Ϊ�˼����⣬�����������¼��裺
�����ļ�ϵͳ��ʼʱֻ��һ����Ŀ¼root��
�������г��ֵ��ļ���Ŀ¼�����ֶ���Ψһ�ġ�����������������ͬ���ֵ��ļ����֣�������������ͬ���ֵ�Ŀ¼���֣�Ҳ������һ���ļ���һ��Ŀ¼������ͬ��
�ļ����ֺ�Ŀ¼���ֶ��ǳ�����1��20֮����ַ���������1��20������ֻ��Ӣ�Ĵ�д��ĸ��Ӣ��Сд��ĸ��������ɡ���Сд��ĸ֮�䲻��Ч��
����Ҫʵ�����²�����
CREATEFILE FILENAME DIRNAME
��������ĺ����ǣ���DIRNAME��Ŀ¼�´���һ������ΪFILENAME���ļ������Ǳ�֤�������������ʱ��DIRNAME��һ���Ѿ����ڵ�Ŀ¼����FILENAME����������״γ��֡�
CREATEDIR DIRNAME1 DIRNAME2 ��������ĺ����ǣ���DIRNAME2��Ŀ¼�´���һ������ΪDIRNAME1��Ŀ¼�����Ǳ�֤�������������ʱ��DIRNAME2��һ���Ѿ����ڵ�Ŀ¼����DIRNAME1����������״γ��֡�
LISTFILE DIRNAME ��������ĺ����ǣ����մ������Ⱥ�˳���ӡ��DIRNAMEĿ¼�µ������ļ����֡����Ǳ�֤�������������ʱ��DIRNAME��һ���Ѿ����ڵ�Ŀ¼.
LISTDIR DIRNAME ��������ĺ����ǣ����մ������Ⱥ�˳���ӡ��DIRNAMEĿ¼�µ�����Ŀ¼���֡����Ǳ�֤�������������ʱ��DIRNAME��һ���Ѿ����ڵ�Ŀ¼
InputFormat
��һ����һ������T����ʾһ����T��������Ҫ�㴦����ע���������֮�����໥�����ġ�ÿ�������µ�һ������ʱ���㶼Ӧ�������ʱֻ��һ������Ϊroot�ĸ�Ŀ¼���ڡ�T�Ĵ�С������20��
����ÿ�����ݣ���һ����һ������N(0<N<=100)����ʾ��N��������Ҫ�㴦����������N�У�ÿһ����������һ��������
	OutputFormat
	����ÿ��LISTFILE������LISTDIR����������ҵ���X���ļ�����Ŀ¼��������Ҫ���X�У����մ���ʱ����絽���˳��ÿһ�д�ӡһ���ļ�����Ŀ¼�������֡�����ҵ���0���ļ�����Ŀ¼�����Ͳ�Ҫ����κζ�������ע�ⲻҪ�������Ŀո�ͻ��з���
	SampleInput
	2
	8
	CREATEFILE desktop root
	CREATEDIR DESKTOP root
	LISTFILE root
	LISTDIR DESKTOP
	CREATEFILE scr20130412 DESKTOP
	CREATEFILE scr20130411 DESKTOP
	CREATEFILE scr20130413 DESKTOP
	LISTFILE DESKTOP
	5
	LISTFILE root
	CREATEDIR webapp root
	CREATEDIR myweb webapp
	CREATEDIR MyWeb webapp
	LISTDIR webapp
	Sample Output
	desktop
	scr20130412
	scr20130411
	scr20130413
	myweb
	MyWeb*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct TreeRecord *Tree;
enum {
	Dir, File
};
struct TreeRecord
{
	char *Data;
	int Type;
	Tree NSibling;
	Tree FChild;
};

Tree CreateTree(Tree L, int type, char *data)
{
	Tree T = malloc(sizeof(struct TreeRecord));
	T->Type = type;
	T->FChild = T->NSibling = NULL;
	T->Data = _strdup(data);
	if (L)
	{
		if (L->FChild)
		{
			L = L->FChild;
			while (L->NSibling)
				L = L->NSibling;
			L->NSibling = T;
			return T;
		}
		L->FChild = T;
	}
	return T;
}

Tree Find(Tree T, char *data)
{
	if (T)
	{
		if (!strcmp(T->Data, data))
			return T;
		Tree P = NULL;
		P = Find(T->FChild, data);
		if (P)
			return P;
		return Find(T->NSibling, data);
	}
	return NULL;
}

void show(Tree P, int type, char *data)
{
	P = P->FChild;
	while (P)
	{
		if (P->Type==type)
			printf("%s\n", P->Data);
		P = P->NSibling;
	}
}

int main(void)
{
	int t, n;
	char tmp1[100];
	char tmp2[100];
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		Tree Root = CreateTree(NULL, Dir, "root");
		for (int i = 0; i<n; i++)
		{
			scanf("%s", tmp1);
			if (!strcmp(tmp1, "CREATEFILE"))
			{
				scanf("%s %s", tmp1, tmp2);
				CreateTree(Find(Root, tmp2), File, tmp1);
			}
			else if (!strcmp(tmp1, "CREATEDIR"))
			{
				scanf("%s %s", tmp1, tmp2);
				CreateTree(Find(Root, tmp2), Dir, tmp1);
			}
			else if (!strcmp(tmp1, "LISTFILE"))
			{
				scanf("%s", tmp2);
				Tree P = Find(T, data);
				show(P, File, tmp2);
			}
			else
			{
				Tree P = Find(T, data);
				show(P, Dir, tmp2);
			}
		}
	}
	return 0;
}
