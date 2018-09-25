/*击鼓传花  n个人围坐成圈 编号1,2,3...n, 从第一个人开始传花 传m个人停止
 拿着花的人淘汰  下一个人继续传 只剩一个人时此人获胜 求编号*/

#include<stdio.h>
#include<stdlib.h>
#include "List.h"
typedef struct ListRecord *List;

int main(void)
{
	int m, n;
	scanf("%d%d", &m, &n);
	List People = CreateNHList();
	List Temp = People;
	for (int i = 1; i<n; i++)
	{
		Temp->Value = i;
		Temp = CreateList(Temp);
	}
	Temp->Value = n;
	Temp->Next = People;
	while (People!=People->Next)//判断只剩一个
	{
		int temp = People->Value;
		while (People->Value<temp+m)
		{
			if (People->Value==n)//传过一轮
				temp -= n;
			People = People->Next;
		}
		//List Previous = FindPrevious(People->Value, People);//开始删除
		List Previous = People;
		while (Previous->Next->Value!=People->Value)
			Previous = Previous->Next;
		Temp = People->Next;
		Previous->Next=Temp;
		free(People);
		People = Temp;
		n--;
	}
	printf("%d\n", People->Value);
	return 0;
}
