#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE *fptr;
	FILE *fptw;
	fptr = fopen("students.txt", "r");
	fptw = fopen("students.txt", "w");
	char s[500];
	int i;
	scanf("%d",&i);
	sprintf(s, "%d\n", i);
    printf("%s\n",s);
}