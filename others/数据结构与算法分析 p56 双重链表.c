#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct Student;
struct Class;
struct StuCla;

struct Student {
	char Name[10];
	struct StuCla *FirstStu;//指向的第一个学生    
};
struct Class {
	char Name[10];
	struct StuCla *FirstStu;//本班的第一个学生 
};
struct StuCla {
	char Stu_name[10];//学生的姓名
	char Class_name[10];//班级的名称
	int cla;//用于排序 
	int stu; //用于排序 
	struct Student *BelongStudent;//用于最后一个结点，指向学生主结点 
	struct Class   *BelongClass;//用于最后一个结点，指向班级主结点 
	struct StuCla  *SameCNextStudent;//用于同班同学那条链 
	struct StuCla  *SameSNextStudent;//用于一个学生所选的课程 
};
typedef    struct StuCla *PtrToNode;
//在这里进行测试，为了简单，只有5个班级，5名学生。
struct Class classes[5];
struct Student student[5];
//初始化所有的班级和学生 
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

	//让学生主结点指向新生成的结点
	PtrToNode Pre_ptr = NULL;
	PtrToNode ptr = student[stuN].FirstStu;
	//处理第一次插入的情况 
	if (ptr==NULL)
	{
		student[stuN].FirstStu = temp;
		temp->BelongStudent = &student[stuN];
		goto L;
	}
	while (ptr!=NULL)
	{
		//插在当前结点之前 
		if (ptr->cla>temp->cla)
		{
			temp->SameSNextStudent = ptr;
			//如果当前结点是主结点后的第一个结点 
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
			//如果不是第一个，找到它前面的一个。
			Pre_ptr = ptr;
			ptr = ptr->SameSNextStudent;
		}
		else
		{
			printf("学生%d重复插入班级%d\n", stuN, claN);
			return;
		}
	}
	//用来处理插入到末尾的情况 
	Pre_ptr->SameSNextStudent = temp;
	Pre_ptr->BelongStudent = NULL;
	temp->BelongStudent = &student[claN];

	//让班级主结点指向新生成的结点
L:  ptr = classes[claN].FirstStu;
	//处理第一次插入的情况 
	if (ptr==NULL)
	{
		classes[claN].FirstStu = temp;
		temp->BelongClass = &classes[claN];
		return;
	}
	while (ptr!=NULL)
	{
		//插在当前结点之前 
		if (ptr->stu>temp->stu)
		{
			temp->SameCNextStudent = ptr;
			//如果当前结点是主结点后的第一个结点 
			if (ptr==classes[claN].FirstStu)
			{
				classes[claN].FirstStu = temp;
				return;
			}
			else
			{
				//如果不是第一个，找到它前面的一个。 
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
			printf("学生%d重复插入班级%d\n", stuN, claN);
			return;
		}
	}
	//用来处理插入到末尾的情况 
	Pre_ptr->SameCNextStudent = temp;
	Pre_ptr->BelongClass = NULL;
	temp->BelongClass = &classes[claN];
}
static void printStudent(int N)
{
	printf("学生%d所选的班级有:", N+1);
	PtrToNode ptr = student[N].FirstStu;
	while (ptr!=NULL)
	{
		printf("%10s", ptr->Class_name);
		if (ptr->BelongStudent!=NULL)
		{
			printf("末尾");
		}
		ptr = ptr->SameSNextStudent;
	}
	printf("\n");
}
static void printClass(int N)
{
	printf("班级%d所有的学生有:", N+1);
	PtrToNode ptr = classes[N].FirstStu;
	while (ptr!=NULL)
	{
		printf("%10s", ptr->Stu_name);
		if (ptr->BelongClass!=NULL)
		{
			printf("末尾");
		}
		ptr = ptr->SameCNextStudent;
	}
	printf("\n");
}
static void printInformation()
{
	printf("先输出所有学生所选的班级:\n");
	int i;
	for (i = 0; i<5; i++)
	{
		printStudent(i);
	}
	printf("再输出所有班级里都有什么学生:\n");
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
			//printf("学生%d选了班级%d",i+1,j+1);
			InsertIntoDoubleList(i, j);
			//printInformation();     
			//printf("\n"); 
		}
	}
	printInformation();
}