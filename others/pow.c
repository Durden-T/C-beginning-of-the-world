#include <stdio.h>
long long int Pow(long long int base, unsigned int n)
{
        long long int res = 1;
        while (n)
        {
                if (n & 1) //奇数
                        res *= base;
                base *= base;
                n >>= 1;
        }
        return res;
}
int main(void)
{
        long long int base;
        unsigned int n;
        scanf("%lld %u",&base,&n);//%lld
        printf("%lld",Pow(base,n));//
        return 0;
}
