#include<stdio.h>//cpp p436 5
#include<stdlib.h>
#include<string.h>
#define BUF 256
int main(int argc,char * argv[])
{
	char temp[BUF];
	if (argc != 3)
		exit(EXIT_FAILURE);
	FILE * source;
	if ((source = fopen(argv[2], "r")) == NULL)
		exit(EXIT_FAILURE);
	while (fgets(temp, BUF, source) != NULL && (strchr(temp, *argv[1])) != NULL)
		fputs(temp, stdout);
	fclose(source);
	return 0;
}


