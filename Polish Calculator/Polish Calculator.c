//Polish Calculator TCPL p79 with stack.c
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define MAX 100
#define MMAX 10//math max
#define NUMBER '0'
#define MATH 'm'
#define RECV 'v'//most recently printed value
char getop(char *);
char math[MMAX];
double op2;
extern void ungets(void);
extern void push(double);
extern double pop(void);
extern void clear(void);
void mathfnc(char[]);
int main(void)
{
	char type,temp[MAX];
	int var = 0;
	double variable[26] = { 0 };
	printf("Polish Calculator\n");
	while ((type = getop(temp))!=EOF)
	{
		switch (type)
		{
		case NUMBER:
			push(atof(temp));
			break;
		case MATH:
			mathfnc(math);
			break;
		case '+':
			push(pop()+pop());
			break;
		case '-':
			op2 = pop();
			push(pop()-op2);
			break;
		case '*':
			push(pop()*pop());
			break;
		case '/':
			op2 = pop();
			push(pop()/op2);
			break;
		case '%':
			if ((op2 = pop())!=0.0)
				push(fmod(pop(),op2));
			else
				printf("error:zero divisor\n");
			break;
		case '\n':
			if(op2=pop())
			printf("%.8g\n", op2);
			break;
		case '?':
			op2 = pop();
			printf("%.8g\n", op2);
			push(op2);
			getchar();
			break;
		case RECV:
			push(var);
			getchar();
			break;
		default:
			if (isupper(type))
			{
				if (!variable[type-'A'])
				{
					char t;
					while (isspace(t = getchar()));
					if (t=='=')
						variable[type-'A'] = pop();
					else
						printf("error:can't find = \n");
					getchar();
				}
				else
					push(variable[type-'A']);
			}
			else
			{
				printf("error:unknown command %s\n", temp);
				getchar();
			}
		}
		var = type;
	}
	return 0;
}
char getop(char *t)
{
	int i;
	while ((t[0] = getchar())==' '||t[0]=='\t')
		;
	t[1] = '\0';
	if (islower(math[0]=t[0]))
	{
		int mi = 0;
		while (islower(math[++mi] = getchar()));
		ungetc(math[mi], stdin);
		math[mi++] = '\0';
		if(strlen(math)>1)
			return MATH;
	}
	if (!isdigit(t[0])&&t[0]!='.'&&t[0]!='-')
		return t[0];
	i = 0;
	if (t[0]=='-')
		if ((t[++i] = getchar())==EOF)
			return '-';
		ungetc(t[i], stdin);
		if (!isdigit(t[i])&&t[i]!='.')
			return '-';
		i--;
	while (isdigit((t[++i] = getchar())));
	if (t[i]=='.')
		while (isdigit((t[++i] = getchar())));
	if(t[i]!=EOF)
		ungetc(t[i], stdin);
	t[i] = '\0';
	return NUMBER;
}
void mathfnc(char s[])
{
	if (!strcmp(s, "sin"))
		push(sin(pop()));
	else if (!strcmp(s, "pow"))
	{
		op2 = pop();
		push(pow(pop(), op2));
	}
	else if (!strcmp(s, "exp"))
		push(exp(pop()));
	else
	{
		printf("error:%s not supported,now supported sin,pow,exp\n", s);
		getchar();
	}
}
