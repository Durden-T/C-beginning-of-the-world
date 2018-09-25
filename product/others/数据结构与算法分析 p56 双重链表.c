#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct Student;
struct Class;
struct StuCla;

struct Student {
	char Name[10];
	struct StuCla *FirstStu;//ָ��ĵ�һ��ѧ��    
};
struct Class {
	char Name[10];
	struct StuCla *FirstStu;//����ĵ�һ��ѧ�� 
};
struct StuCla {
	char Stu_name[10];//ѧ��������
	char Class_name[10];//�༶������
	int cla;//�������� 
	int stu; //�������� 
	struct Student *BelongStudent;//�������һ����㣬ָ��ѧ������� 
	struct Class   *BelongClass;//�������һ����㣬ָ��༶����� 
	struct StuCla  *SameCNextStudent;//����ͬ��ͬѧ������ 
	struct StuCla  *SameSNextStudent;//����һ��ѧ����ѡ�Ŀγ� 
};
typedef    struct StuCla *PtrToNode;
//��������в��ԣ�Ϊ�˼򵥣�ֻ��5���༶��5��ѧ����
struct Class classes[5];
struct Student student[5];
//��ʼ�����еİ༶��ѧ�� 
static void Initial()
{
	int i;
	char str1[10];
	char str2[10];
	char temp[2];
	for (i = 0; i<5; i++)
	{
		strcpy(str1, "class");
		strcpy(str2, "student");
		itoa(i+1, temp, 10);
		strcat(str1, temp);
		strcat(str2, temp);
		//printf("%s,%s\n",str1,str2);
		strcpy(classes[i].Name, str1);
		strcpy(student[i].Name, str2);
		classes[i].FirstStu = NULL;
		student[i].FirstStu = NULL;
	}
}
static void InsertIntoDoubleList(int stuN, int claN)
{
	PtrToNode temp = malloc(sizeof(struct StuCla));
	strcpy(temp->Stu_name, student[stuN].Name);
	strcpy(temp->Class_name, classes[claN].Name);
	temp->cla = claN;
	temp->stu = stuN;
	temp->BelongStudent = NULL;
	temp->BelongClass = NULL;
	temp->SameCNextStudent = NULL;
	temp->SameSNextStudent = NULL;

	//��ѧ�������ָ�������ɵĽ��
	PtrToNode Pre_ptr = NULL;
	PtrToNode ptr = student[stuN].FirstStu;
	//�����һ�β������� 
	if (ptr==NULL)
	{
		student[stuN].FirstStu = temp;
		temp->BelongStudent = &student[stuN];
		goto L;
	}
	while (ptr!=NULL)
	{
		//���ڵ�ǰ���֮ǰ 
		if (ptr->cla>temp->cla)
		{
			temp->SameSNextStudent = ptr;
			//�����ǰ�����������ĵ�һ����� 
			if (ptr==student[stuN].FirstStu)
			{
				student[stuN].FirstStu = temp;
				goto L;
			}
			else
			{
				Pre_ptr->SameSNextStudent = temp;
				goto L;
			}
		}
		else if (ptr->cla<temp->cla)
		{
			//������ǵ�һ�����ҵ���ǰ���һ����
			Pre_ptr = ptr;
			ptr = ptr->SameSNextStudent;
		}
		else
		{
			printf("ѧ��%d�ظ�����༶%d\n", stuN, claN);
			return;
		}
	}
	//����������뵽ĩβ����� 
	Pre_ptr->SameSNextStudent = temp;
	Pre_ptr->BelongStudent = NULL;
	temp->BelongStudent = &student[claN];

	//�ð༶�����ָ�������ɵĽ��
L:  ptr = classes[claN].FirstStu;
	//�����һ�β������� 
	if (ptr==NULL)
	{
		classes[claN].FirstStu = temp;
		temp->BelongClass = &classes[claN];
		return;
	}
	while (ptr!=NULL)
	{
		//���ڵ�ǰ���֮ǰ 
		if (ptr->stu>temp->stu)
		{
			temp->SameCNextStudent = ptr;
			//�����ǰ�����������ĵ�һ����� 
			if (ptr==classes[claN].FirstStu)
			{
				classes[claN].FirstStu = temp;
				return;
			}
			else
			{
				//������ǵ�һ�����ҵ���ǰ���һ���� 
				Pre_ptr->SameCNextStudent = temp;
				return;
			}
		}
		else if (ptr->stu<temp->stu)
		{
			Pre_ptr = ptr;
			ptr = ptr->SameCNextStudent;
		}
		else
		{
			printf("ѧ��%d�ظ�����༶%d\n", stuN, claN);
			return;
		}
	}
	//����������뵽ĩβ����� 
	Pre_ptr->SameCNextStudent = temp;
	Pre_ptr->BelongClass = NULL;
	temp->BelongClass = &classes[claN];
}
static void printStudent(int N)
{
	printf("ѧ��%d��ѡ�İ༶��:", N+1);
	PtrToNode ptr = student[N].FirstStu;
	while (ptr!=NULL)
	{
		printf("%10s", ptr->Class_name);
		if (ptr->BelongStudent!=NULL)
		{
			printf("ĩβ");
		}
		ptr = ptr->SameSNextStudent;
	}
	printf("\n");
}
static void printClass(int N)
{
	printf("�༶%d���е�ѧ����:", N+1);
	PtrToNode ptr = classes[N].FirstStu;
	while (ptr!=NULL)
	{
		printf("%10s", ptr->Stu_name);
		if (ptr->BelongClass!=NULL)
		{
			printf("ĩβ");
		}
		ptr = ptr->SameCNextStudent;
	}
	printf("\n");
}
static void printInformation()
{
	printf("���������ѧ����ѡ�İ༶:\n");
	int i;
	for (i = 0; i<5; i++)
	{
		printStudent(i);
	}
	printf("��������а༶�ﶼ��ʲôѧ��:\n");
	for (i = 0; i<5; i++)
	{
		printClass(i);
	}
}
int main()
{
	srand(time(NULL));
	Initial();
	int StuAndCla[5][5];
	int i;
	int j;
	int w;
	for (i = 0; i<5; i++)
	{
		for (j = 0; j<5; j++)
		{
			StuAndCla[i][j] = 0;
		}
	}
	for (w = 0; w<20; w++)
	{
		i = rand()%5;
		j = rand()%5;
		if (StuAndCla[i][j]==0)
		{
			StuAndCla[i][j] = 1;
			//printf("ѧ��%dѡ�˰༶%d",i+1,j+1);
			InsertIntoDoubleList(i, j);
			//printInformation();     
			//printf("\n"); 
		}
	}
	printInformation();
}