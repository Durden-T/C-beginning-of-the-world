//cpp p491 7  以后重写一遍
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10

char * mgets(char*, int);
int getlet(const char *);
void update(struct book *);
void getbook(char *, int);

struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
	bool delete;
};
int size = sizeof(struct book);

int main(void)
{
	int count = 0, deleted = 0;
	FILE * pbooks;
	struct book library[MAXBKS];
	char ch;
	struct book *pt;
	if ((pbooks = fopen("book.txt", "r")) == NULL)
	{
		fputs("failed.", stderr);
		exit(1);
	}
	while (fread(&library[count], size, 1, pbooks) == 1 && count < MAXBKS - deleted)
	{
		library[count].delete = false;
		if (count == 0)
			puts("Current contents of book.txt:");
		printf("%s by %s: $%.2f\n", library[count].title,
			library[count].author, library[count].value);

		printf("Do you wish to change or delete this or skip entry?<c/d/s> ");
		if ((ch = getlet("cds")) == 'c')
		{
			pt = &library[count];
			update(pt);
		}
		else if (ch == 'd')
		{
			library[count].delete = true;
			deleted++;
		}
		count++;

		fclose(pbooks);
	}
	if ((count - deleted) == MAXBKS)
	{
		fputs("The book.txt file is full.", stderr);
		exit(1);
	}
	puts("Please add new book titles.");
	puts("Press [enter] at the start of a line to stop.");

	while (count < MAXBKS + deleted && mgets(library[count].title, MAXTITL) != NULL &&library[count].title[0]!='\0')
	{
		if (library[count].title == '\n')
			exit(1);
		printf("Now enter the author: ");
		mgets(library[count].author, MAXTITL);
		printf("Now enter the value: ");
		scanf("%f", &library[count].value);
		getchar();
		count++;
		puts("Please add new book titles.");
		puts("Press [enter] at the start of a line to stop.");
	}

	puts("Here is the list of your books:");
	pbooks = fopen("book.txt", "w");
	for (int i = 0; i < count; i++)
	{
		if (library[i].delete != true)
		{
			printf("%s by %s: $%.2f\n", library[count].title,
				library[count].author, library[count].value);
			fwrite(&library[count], size, 1, pbooks);
		}
	}
	return 0;

}
void update(struct book *pt)
{
	char ch;
	struct book temp;
	puts("Enter the letter that indicates your choice:");
	puts("t) modify title a) modify author");
	puts("v) modify value s) quit, saving changes");
	puts("q) quit, ignore changes");
	while ((ch = getlet("tavsq")) != 'q'&&ch!='s')
	{
		switch (ch)
		{
		case 't':	fwrite(temp.title, MAXTITL, 1, stdin);		 break;
		case 'a':	fwrite(temp.author, MAXAUTL, 1, stdin);		 break;
		case 'v':	scanf("%f", &temp.value);					 break;
		case 's':	
			*(pt->author) = temp.author;
			*(pt->title) = temp.title;
			pt->value = temp.value;
			break;
		default:;
		}
	}
	puts("Done.");
}

void getbook(char * st, int n)
{
	while (mgets(st, n) == NULL || *st == '\0');
}



// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <stdbool.h>
// #define MAXTITL 40
// #define MAXAUTL 40
// #define MAXBKS 10 /* maximum number of books */
// #define CONTINUE 0
// #define DONE 1
// struct book { /* set up book template */
// 	char title[MAXTITL];
// 	char author[MAXAUTL];
// 	float value;
// };
// struct pack {
// 	struct book book; // different namespaces for two book identifiers
// 	bool delete_me;
// };
// /*
// strategy: rather than rearrange array of structures every time
// there is a deletion, combine structure with a data member indicating
// whether or not an item is marked for deletion. At the end of the program,
// show and store only those items not marked for deletion. The deletion
// information could be stored in a separate array, but storing it in a
// structure along with the book structure keeps the information together.
// */
// char * mgets(char * st, int n);
// int getlet(const char * s);
// int getbook(struct pack * pb);
// void update(struct pack * item);
// int main(void)
// {
// 	struct pack library[MAXBKS]; /* array of structures */
// 	int count = 0;
// 	int deleted = 0;
// 	int index, filecount, open;
// 	FILE * pbooks;
// 	int size = sizeof(struct book);
// 	if ((pbooks = fopen("book.dat", "r+b")) != NULL)
// 	{
// 		while (count < MAXBKS && fread(&library[count], size,
// 			1, pbooks) == 1)
// 		{
// 			if (count == 0)
// 				puts("Current contents of book.dat:");
// 			printf("%s by %s: $%.2f\n", library[count].book.title,
// 				library[count].book.author, library[count].book.value);
// 			library[count].delete_me = false;
// 			printf("Do you wish to change or delete this entry?<y/n> ");
// 			if (getlet("yn") == 'y')
// 			{
// 				printf("Enter c to change, d to delete entry: ");
// 				if (getlet("cd") == 'd')
// 				{
// 					library[count].delete_me = true;
// 					deleted++;
// 					puts("Entry marked for deletion.");
// 				}
// 				else
// 					update(&library[count]);
// 			}
// 			count++;
// 		}
// 		count--;
// 		fclose(pbooks);
// 	}
// 	filecount = count - deleted;
// 	if (count == MAXBKS)
// 	{
// 		fputs("The book.dat file is full.", stderr);
// 		exit(EXIT_FAILURE);
// 	}
// 	puts("Please add new book titles.");
// 	puts("Press [enter] at the start of a line to stop.");
// 	open = 0;
// 	while (filecount < MAXBKS)
// 	{
// 		if (filecount < count)
// 		{
// 			while (library[open].delete_me == false)
// 				open++;
// 			if (getbook(&library[open]) == DONE)
// 				break;
// 		}
// 		else if (getbook(&library[filecount]) == DONE)
// 			break;
// 		filecount++;
// 		if (filecount < MAXBKS)
// 			puts("Enter the next book title.");
// 	}
// 	puts("Here is the list of your books:");
// 	for (index = 0; index < filecount; index++)
// 		if (library[index].delete_me == false)
// 			printf("%s by %s: $%.2f\n", library[index].book.title,
// 				library[index].book.author, library[index].book.value);
// 	if ((pbooks = fopen("book.dat", "wb")) == NULL)
// 	{
// 		fputs("Can't open book.dat file for output\n", stderr);
// 		exit(EXIT_FAILURE);
// 	}
// 	for (index = 0; index < filecount; index++)
// 		if (library[index].delete_me == false)
// 			fwrite(&(library[index].book), size, 1, pbooks);
// 	fclose(pbooks);
// 	puts("Done!");
// 	return 0;
// }
// 
// int getbook(struct pack * pb)
// {
// 	int status = CONTINUE;
// 	if (mgets(pb->book.title, MAXTITL) == NULL || pb->book.title[0] == '\0')
// 		status = DONE;
// 	else
// 	{
// 		printf("Now enter the author: ");
// 		mgets(pb->book.author, MAXAUTL);
// 		printf("Now enter the value: ");
// 		while (scanf("%f", &pb->book.value) != 1)
// 		{
// 			puts("Please use numeric input");
// 			scanf("%*s");
// 		}
// 		while (getchar() != '\n')
// 			continue; /*clear input line */
// 		pb->delete_me = false;
// 	}
// 	return status;
// }
// void update(struct pack * item)
// {
// 	struct book copy;
// 	char c;
// 
// 	copy = item->book;
// 	puts("Enter the letter that indicates your choice:");
// 	puts("t) modify title a) modify author");
// 	puts("v) modify value s) quit, saving changes");
// 	puts("q) quit, ignore changes");
// 	while ((c = getlet("tavsq")) != 's' && c != 'q')
// 	{
// 		switch (c)
// 		{
// 		case 't': puts("Enter new title: ");
// 			mgets(copy.title, MAXTITL);
// 			break;
// 		case 'a': puts("Enter new author: ");
// 			mgets(copy.author, MAXAUTL);
// 			break;
// 		case 'v': puts("Enter new value: ");
// 			while (scanf("%f", &copy.value) != 1)
// 			{
// 				puts("Enter a numeric value: ");
// 				scanf("%*s");
// 			}
// 			while (getchar() != '\n')
// 				continue;
// 			break;
// 		}
// 		puts("t) modify title a) modify author");
// 		puts("v) modify value s) quit, saving changes");
// 		puts("q) quit, ignore changes");
// 	}
// 	if (c == 's')
// 		item->book = copy;
// }

