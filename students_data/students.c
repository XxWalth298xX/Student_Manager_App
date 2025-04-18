#include "students.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// doc va gan du lieu tu trong file students.txt
void studentdata(profile *s) {
    FILE *fptr = fopen("./students.txt", "r");
    if (fptr == NULL) {
        printf("ERROR\n");
        return;
    }
    long i = 0;
	char buffer[200];
	char m[50];
	char line[256];
    while (fgets(line, sizeof(line), fptr)) {
        if (strncmp(line, "\0", 3) == 0) break;
        fscanf(fptr,"%[^,]",buffer);
        strcpy(m,buffer+3);
        i=atoi(m);
        strcpy(s[i].MSSV,buffer);
        fscanf(fptr,",%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%f,%f,%f,%f",
               s[i].NAME,s[i].department, s[i].DATE,
               s[i].NUM, s[i].ADD, s[i].CLASS,
               &s[i].math, &s[i].lit, &s[i].eng, &s[i].aver);
    }

    fclose(fptr);
}
//

// xoa du lieu trong file stu.txt
void cleardata()
{
    FILE *fptw = fopen("./stu.txt", "w+");
	fprintf(fptw,"\0");
    fclose(fptw);
}
//

// in du lieu vo file stu.txt
void printdata(profile *s,long ID)
{
    FILE *fptw = fopen("./stu.txt", "a");
	fprintf(fptw,"%s,%s,%s,%s,%s,%s,%s,%f,%f,%f,%f\n",s[ID].MSSV, s[ID].NAME,s[ID].department, s[ID].DATE,s[ID].NUM, s[ID].ADD, s[ID].CLASS,
    s[ID].math,s[ID].lit,s[ID].eng,s[ID].aver);
    fclose(fptw);
}
//

// doc va gan du lieu tu trong file students1.txt
void studentdatadem(profile *s) {
    FILE *fptr = fopen("./students.txt", "r");
    if (fptr == NULL) {
        printf("ERROR\n");
        return;
    }
    long i = 0;
	char buffer[200];
	char m[50];
	char line[256];
    while (fgets(line, sizeof(line), fptr)) {
        if (strncmp(line, "END", 3) == 0) break;
        fscanf(fptr,"%[^,]",buffer);
        strcpy(s[i].MSSV,buffer);
        fscanf(fptr,",%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%f,%f,%f,%f",
               s[i].NAME,s[i].department, s[i].DATE,
               s[i].NUM, s[i].ADD, s[i].CLASS,
               &s[i].math, &s[i].lit, &s[i].eng, &s[i].aver);
        i++;
    }

    fclose(fptr);
}
//

//
void studentdata1(profile *s) {
    FILE *fptr = fopen("./stu1.txt", "r");
    if (fptr == NULL) {
        printf("ERROR\n");
        return;
    }
    long i = 0;
	char buffer[200];
	char m[50];
	char line[256];
    while (fgets(line, sizeof(line), fptr)) {
        if (strncmp(line, "END", 3) == 0) break;
        fscanf(fptr,"%[^,]",buffer);
        strcpy(s[i].MSSV,buffer);
        fscanf(fptr,",%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%f,%f,%f,%f",
               s[i].NAME,s[i].department, s[i].DATE,
               s[i].NUM, s[i].ADD, s[i].CLASS,
               &s[i].math, &s[i].lit, &s[i].eng, &s[i].aver);
        i++;
    }

    fclose(fptr);
}
//

// xoa du lieu trong file stu1.txt
void cleardata1()
{
    FILE *fptw = fopen("./stu1.txt", "w+");
	fprintf(fptw,"\0");
    fclose(fptw);
}
//

// in du lieu vo file stu.txt
void printdata1(profile *s,long ID)
{
    FILE *fptw = fopen("./stu1.txt", "a");
	fprintf(fptw,"%s,%s,%s,%s,%s,%s,%s,%f,%f,%f,%f\n",s[ID].MSSV, s[ID].NAME,s[ID].department, s[ID].DATE,s[ID].NUM, s[ID].ADD, s[ID].CLASS,
    s[ID].math,s[ID].lit,s[ID].eng,s[ID].aver);
    fclose(fptw);
}
//

//
int data18print(profile *s)
{
    long i = 0;long count = 0;
    while(s[i].MSSV[0] != '\0')
    {
        if (s[i].MSSV[0] == 'H' && s[i].MSSV[1] == 'S' && s[i].MSSV[2] == '0' && s[i].MSSV[3] == '1' && s[i].MSSV[4] == '8')
        {
            printdata1(s,i);
            count++;
        }
        i++;
    }
    return count;
}
//

int data19print(profile *s)
{
    long i = 0;long count = 0;
    while(s[i].MSSV[0] != '\0')
    {
        if (s[i].MSSV[0] == 'H' && s[i].MSSV[1] == 'S' && s[i].MSSV[2] == '0' && s[i].MSSV[3] == '1' && s[i].MSSV[4] == '9')
        {
            printdata1(s,i); 
            count++;
        }
        i++;
    }
    return count;
}
//

int data20print(profile *s)
{
    long i = 0;long count = 0;
    while(s[i].MSSV[0] != '\0')
    {
        if (s[i].MSSV[0] == 'H' && s[i].MSSV[1] == 'S' && s[i].MSSV[2] == '0' && s[i].MSSV[3] == '2' && s[i].MSSV[4] == '0')
        {
            printdata1(s,i); 
            count++;
        }
        i++;
    }
    return count;
}
//
void printdatareverse(profile s)
{
    FILE *fptw = fopen("./students.txt", "a");
    fprintf(fptw,"%s,%s,%s,%s,%s,%s,%s,%f,%f,%f,%f\n",s.MSSV, s.NAME,s.department, s.DATE,s.NUM, s.ADD, s.CLASS,
    s.math,s.lit,s.eng,s.aver);
    fclose(fptw);
}
//

void delete_data(profile *s, long ID) {
    long i = 1600000; // Start from the 16th record
    FILE *fptw = fopen("./students.txt", "w");
    while(i<5000000) {
        if (strcmp(s[i].MSSV, s[ID].MSSV) != 0&& strcmp(s[i].MSSV, "\0") != 0) {
            //printf("ID: %s\n", s[i].MSSV);
            fprintf(fptw, "%s,%s,%s,%s,%s,%s,%s,%.2f,%.2f,%.2f,%.2f\n",
                s[i].MSSV,
                s[i].NAME,
                s[i].department,
                s[i].DATE,
                s[i].NUM,
                s[i].ADD,
                s[i].CLASS,
                s[i].math, s[i].lit, s[i].eng, s[i].aver);
        }
        i++;
    }
    fclose(fptw);
}