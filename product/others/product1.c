#include<stdio.h>//p175 5
int main(void)
{
    char lets[5]="ABCDE";
    int i1,i2,i3;
    for(i1=0; i1 <=4;) //����һ��
    {
        for(i3=4; i3>i1; printf(" "),i3--) //��ӡ�ո�
            ;
        for(i2=0; i2 <= i1; printf("%c",lets[i2++])) //�����ӡ
            ;
        for(i2-=2; i2 >=0; printf("%c",lets[i2--])) //�����ӡ
            ;
        printf("\n");
        i1 ++;
    }
    return 0;
}

