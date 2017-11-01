#include <stdio.h>  
#include <stdlib.h>  
char* strncpy(char *dest,char *src,unsigned int n){  
        char *strRtn=dest;  
        while(n && (*dest++=*src++)){  
                n--;  
        }  
        printf("n:%d/n",n);  
        if(n)  
        {  
                while(--n)  
                        *dest++;  
        }  
        return strRtn;  
}  