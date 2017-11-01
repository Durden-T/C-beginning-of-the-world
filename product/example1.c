//CPP p 483
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LEN 81
typedef void(*PFUN)(char *);
int showmenu(void);
void eatline(void);     // read through end of line
void show(PFUN fp, char * str);
void ToUpper(char *);   // convert string to uppercase
void ToLower(char *);   // convert string to uppercase
void Transpose(char *); // transpose cases
void Dummy(char *);     // leave string unaltered
PFUN fun[4] = { ToUpper,ToLower,Transpose,Dummy };
int main(void)
{
	char line[LEN];
	puts("Enter a string (empty line to quit):");

	while (gets_s(line, LEN) != NULL && line[0] != '\0')
	{
		int index;
		char copy[LEN];
		strcpy(copy, line);// make copy for show()
		
		while ((index = showmenu()) != 4)
			show(fun[index], copy);  // use selected function
		puts("Enter a string (empty line to quit):");
	}

	puts("Bye!");

	return 0;
}

int showmenu(void)
{
	char ans;
	puts("Enter menu choice:");
	puts("u) uppercase       l) lowercase");
	puts("t) transposed case o) original case");
	puts("n) next string");
	ans = getchar();    // get response
	ans = tolower(ans); // convert to lowercase
	eatline();          // dispose of rest of line
	while (strchr("ulton", ans) == NULL)
	{
		puts("Please enter a u, l, t, o, or n:");
		ans = tolower(getchar());
		eatline();
	}
	switch (ans)
	{
	case 'u':return 0;
	case 'l':return 1;
	case 't':return 2;
	case 'o':return 3;
	default :return 4;
	}
}

void eatline(void)
{
	while (getchar() != '\n')
		continue;
}

void ToUpper(char * str)
{
	while (*str)
	{
		*str = toupper(*str);
		str++;
	}
}

void ToLower(char * str)
{
	while (*str)
	{
		*str = tolower(*str);
		str++;
	}
}
void Transpose(char * str)
{
	while (*str)
	{
		if (islower(*str))
			*str = toupper(*str);
		else if (isupper(*str))
			*str = tolower(*str);
		str++;
	}
}

void Dummy(char * str)
{
	// leaves string unchanged
}

void show(void(*fp)(char *), char * str)
{
	(*fp)(str); // apply chosen function to str
	puts(str);  // display result
}
