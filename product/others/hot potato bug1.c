/*���Ĵ���  n����Χ����Ȧ ���1,2,3...n, �ӵ�һ���˿�ʼ���� ��m����ֹͣ
 ���Ż�������̭  ��һ���˼����� ֻʣһ����ʱ���˻�ʤ ����*/

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
	while (People!=People->Next)//�ж�ֻʣһ��
	{
		int temp = People->Value;
		while (People->Value<temp+m)
		{
			if (People->Value==n)//����һ��
				temp -= n;
			People = People->Next;
		}
		//List Previous = FindPrevious(People->Value, People);//��ʼɾ��
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
