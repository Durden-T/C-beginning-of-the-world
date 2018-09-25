char * strcpy(char * strDest,const char * strSrc)  
{
if ((NULL==strDest) || (NULL==strSrc)) 
throw "Invalid argument(s)"; 
char * strDestCopy = strDest; 
while ((*strDest++=*strSrc++)!='\0'); 
return strDestCopy;
}