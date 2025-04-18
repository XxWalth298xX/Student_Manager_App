
#include "students.h"
#include "Searching.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//ham phan chia chuc nang
void searching(profile *s,char ms[20],char name[100])
{
	cleardata();
	char buffer[100];int ID;
	strcpy(buffer,ms+3);
    ID=atoi(buffer);
	if(ID==0) searchbyname(s,name);
	else searchbynum(s,ID);
}
//

//tim kiem theo ten
void searchbyname(profile *s,char name[100])
{
	long i=1800000;
	name[strlen(name)]='\0';
	if(name[0]=='\0') {printf("Error: name not found\n");return;}
	else
	while(i < 5000000)
	{
		if(strcmp(name,s[i].NAME)==0) {printdata(s,i);}
		i++;
	}
}
//

//tim kiem theo ma so
void searchbynum(profile *s,int ID) {
	printdata(s,ID);
}
//
