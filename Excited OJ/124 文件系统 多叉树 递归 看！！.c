/*
Description
现在很多操作系统的文件系统都是基于树形结构设计的。即一个目录下可以有若干个目录和文件，而每个目录和文件都可以通过一条从根目录出发的唯一路径来唯一确定。我们希望你实现对这样的一个文件系统的简单管理。
为了简化问题，我们做出如下假设：
假设文件系统初始时只有一个根目录root。
假设所有出现的文件和目录的名字都是唯一的。即，不会有两个相同名字的文件出现，不会有两个相同名字的目录出现，也不会有一个文件和一个目录名字相同。
文件名字和目录名字都是长度在1到20之间的字符串（包括1和20），且只由英文大写字母、英文小写字母、数字组成。大小写字母之间不等效。
你需要实现如下操作：
CREATEFILE FILENAME DIRNAME
这个操作的含义是：在DIRNAME的目录下创建一个名字为FILENAME的文件。我们保证当出现这个操作时，DIRNAME是一个已经存在的目录，而FILENAME这个名字是首次出现。
CREATEDIR DIRNAME1 DIRNAME2 这个操作的含义是：在DIRNAME2的目录下创建一个名字为DIRNAME1的目录。我们保证当出现这个操作时，DIRNAME2是一个已经存在的目录，而DIRNAME1这个名字是首次出现。
LISTFILE DIRNAME 这个操作的含义是：按照创建的先后顺序打印出DIRNAME目录下的所有文件名字。我们保证当出现这个操作时，DIRNAME是一个已经存在的目录.
LISTDIR DIRNAME 这个操作的含义是：按照创建的先后顺序打印出DIRNAME目录下的所有目录名字。我们保证当出现这个操作时，DIRNAME是一个已经存在的目录
InputFormat
第一行有一个整数T，表示一共有T组数据需要你处理。请注意各组数据之间是相互独立的。每当处理新的一组数据时，你都应当假设此时只有一个名字为root的根目录存在。T的大小不超过20。
对于每组数据，第一行有一个整数N(0<N<=100)，表示有N个操作需要你处理，接下来的N行，每一个行描述了一个操作。
	OutputFormat
	对于每个LISTFILE操作和LISTDIR操作，如果找到了X个文件（或目录），你需要输出X行，按照创建时间从早到晚的顺序，每一行打印一个文件（或目录）的名字。如果找到了0个文件（或目录），就不要输出任何东西。请注意不要输出多余的空格和换行符。
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
