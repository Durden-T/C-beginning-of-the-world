//TCPL 143 6-2 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define FIRSTM 6
#define MAX 100
#define TYPEC 5
struct stree 
{
	char* value;
	int match;
	struct stree *left;
	struct stree *right;
};
char *type[] = { "int","char","long","float","double" };
void treeprint(struct stree *);
struct stree *addtree(struct stree*,char*);
const int bg = sizeof(struct stree);
int main(void)
{
	char temp[MAX];
	struct stree *root = NULL;
	while (scanf("%s", temp)&&temp[0]!='`')
	{
		int i;
		for (i = 0; i<TYPEC&&strcmp(type[i], temp); i++)
			;
		if (i==TYPEC)
			continue;
		else
			if(scanf("%s", temp)&&strlen(temp)>FIRSTM)
				root=addtree(root, temp);
	}
	treeprint(root); 
	return 0;
}
struct stree *addtree(struct stree *p, char *w)
{
	static int cmp;
	if (p==NULL)
	{
		p = (struct stree*)malloc(bg);
		p->value = _strdup(w);
		p->match = 0;
		p->left = p->right = NULL;
	}
	else if (!(cmp = strncmp(w, p->value,FIRSTM)))
		p->match++;
	else if (cmp<0)
		p->left = addtree(p->left, w);
	else
		p->right = addtree(p->right, w);
	return p;
}
void treeprint(struct stree *p)
{
	if (p)
	{
		treeprint(p->left);
		printf("%s %d\n", p->value, p->count);
		treeprint(p->right);
	}
}