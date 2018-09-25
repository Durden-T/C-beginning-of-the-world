/*���е�ɢ��
   Bessie͸��ţ���Ĵ���������ȥ�����ֽ�����һ�������Ĵ����糿�����룬�������ĺ���������ԡ�����磬���ڲݵ�֮�У������۲������ظ��������صĸо�������֪��һ�����뿪��ţ�*/

#include <stdio.h>
#include <stdlib.h>
typedef struct TreeRecord* Tree;
typedef struct TreeRecord Node;
struct TreeRecord
{
        int Number;
        Tree Left;
        Tree Right;
};
int find(Node Temp[],int a,int p)
{
        for(int i=1; i<=p; i++)
                if((Temp[i].Left&&Temp[i].Left->Number==a)||(Temp[i].Right&&Temp[i].Right->Number==a))
                        return i;
        return 0;
}
int MaxDeep(Tree Root)
{
        if(Root==NULL)
                return 0;
        int max1 = MaxDeep(Root->Left) + 1;
        int max2 = MaxDeep(Root->Right) + 1;
        return (max1 > max2) ? max1 : max2;
}
int main(void)
{
        int p;
        scanf("%d",&p);
        Node *Temp=malloc(sizeof(Node)*(p+1));
        for(int i=0; i<=p; i++)
        {
                Temp[i].Number=i;
                Temp[i].Left=Temp[i].Right=NULL;
        }
        for(int i=1; i<=p; i++)
        {
                static int a,b,c,found;
                scanf("%d %d %d",&a,&b,&c);
                if(b)
                {
                        if(a>b)
                                Temp[a].Left=&Temp[b];
                        else
                                Temp[a].Right=&Temp[b];
                }
                if(c)
                {
                        if(a>c)
                                Temp[a].Left=&Temp[c];
                        else
                                Temp[a].Right=&Temp[c];
                }
                found=find(Temp,a,p);
                if(found)
                        if(found>a)
                                Temp[found].Left=&Temp[a];
                        else
                                Temp[found].Right=&Temp[a];
        }
        printf("%d", MaxDeep(&Temp[1]));
        return 0;
}
