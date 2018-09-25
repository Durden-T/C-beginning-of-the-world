/* Programming Exercise 11-8 */
#include <stdio.h>
#define LEN 20
char * string_in(const char * s1, const char * s2);
int main(void)
{
	char orig[LEN] = "transportation";
	char * find;

	puts(orig);
	find = string_in(orig, "port");
	if (find)
		puts(find);
	else
		puts("Not found");
	find = string_in(orig, "part");
	if (find)
		puts(find);
	else
		puts("Not found");

	return 0;
}
#include <string.h>
char * string_in(const char * s1, const char * s2)
{
	int l1 = strlen(s1), l2 = strlen(s2);
	int tries = l1 - l2 + 1;/* maximum number of comparisons */
	int nomatch = 1; /* set to 0 if match is found */
	if (tries > 0)
		while ((nomatch = strncmp(s1, s2, l2)) && tries--&&s1++);
	if (nomatch)
		return NULL;
	return (char *)s1; /* cast const away */
}





// #include<stdio.h>
// #include<string.h>
// char *mstrstr(char *s1, char *s2);
// int main(void)
// {
// 	char s1[] = "fuck you ah";
// 	char s2[]= "you";
// 	printf("%s", mstrstr(s1, s2));
// 	getchar();
// 	getchar();
// 	return 0;
// }
// char *mstrstr(char *s1,char *s2)
// {
// 	size_t l1 = strlen(s1),l2 = strlen(s2);
// 	int i = 0;
// 	while (strncmp(s1 + i, s2, l2)&&++i<l1-l2+2);
// 	if (i != l1 - l2 + 2)
// 		return  s1 + i;
// 	return NULL;
// }