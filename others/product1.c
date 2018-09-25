#include<stdio.h>//p175 5
int main(void)
{
    char lets[5]="ABCDE";
    int i1,i2,i3;
    for(i1=0; i1 <=4;) //换下一行
    {
        for(i3=4; i3>i1; printf(" "),i3--) //打印空格
            ;
        for(i2=0; i2 <= i1; printf("%c",lets[i2++])) //正向打印
            ;
        for(i2-=2; i2 >=0; printf("%c",lets[i2--])) //反向打印
            ;
        printf("\n");
        i1 ++;
    }
    return 0;
}

