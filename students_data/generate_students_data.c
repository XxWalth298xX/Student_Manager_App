#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
int n=15000;int c=1;
//NAME
char *firstname[]={"DUC","THANH","NAM","QUAN","ANH","HOANG","TIEN","DUNG","NHAN","HOAI","NHI","THUONG","SAU","DUNG","NGA",
	"THANG","KHANH","LINH","MY","HANH","DAT","HAN","VAN","OANH","HUY","THINH","KIET","TRINH","UYEN"};
char *lastname[] = {"NGUYEN", "TRAN", "LE", "PHAM", "HOANG", "HUYNH",
	"PHAN", "VU", "VO", "DANG", "BUI", "DO", "HO", "NGO", "DUONG", "LY"};
char *middlename[] = {"VAN", "HUU", "DUC", "XUAN", "NGOC", "QUANG", "CONG", "KHANH", "MINH", "TRI", "TUAN", "DUNG",
	"PHUC", "THANH", "THINH","THI", "THUY", "LAN", "HONG", "MAI", "NHUNG", "NGOC", "QUYNH", "TRANG", "VY", "ANH", "CHI", "HOA", "LOAN"};
//NAME////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//DATE
char *day[] = {"1", "2", "3", "4", "5", "6", "7", "8","9", "10","11", "12", "13", "14", "15", "16", "17", "18", "19", "20","21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31"};
char *month[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12"};
char *year[] = {"2000", "2001", "2002", "2003", "2004", "2005", "2006"};
//DATE////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//SUBJECT
char *subject[] = {"SE","AI","GD","ITS","FI","MC"};
//SUBJECT////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct profile{
	char MSSV[20];
	char NAME[100];
	char DATE[100];
	char NUM[12];
	char ADD[11];
	char CLASS[10];
	char department[20];
	float  math;float lit; float eng; float aver;
};struct profile stu[500000];
void dataprint(int c){
	sprintf(stu[c].NAME,"%s %s %s",lastname[(rand()%16)],middlename[(rand()%29)],firstname[(rand()%29)]);
	int thang=month[(rand()%29)];
	sprintf(stu[c].DATE,"%s\\%s\\%s",day[(rand()%31)],month[(rand()%12)],year[(rand()%7)]);
	sprintf(stu[c].NUM, "%s%d%08d","0",rand() % 8+1 ,rand() % 90000000+1000000); 
	sprintf(stu[c].ADD, "%s","VietNam"); 
	sprintf(stu[c].CLASS, "%s%02d","C", rand() % 15);
	sprintf(stu[c].department, "%s",subject[(rand()%6)]); 
	stu[c].math=rand()%6+5;
	stu[c].eng=rand()%6+5;
	stu[c].lit=rand()%6+5;
	stu[c].aver=(stu[c].math+stu[c].eng+stu[c].lit)/3;
	
}
int main()
{
	FILE *fptr; srand(time(NULL));
	fptr = fopen("./students.txt", "w");
		
	for(int i=1;i<=n;++i)
	{
		sprintf(stu[c].MSSV,"HS018%05d",i);
		dataprint(c);
		fprintf(fptr, "%s,%s,%s,%s,%s,%s,%s,%.2f,%.2f,%.2f,%.2f\n",
    	stu[c].MSSV,
    	stu[c].NAME,
		stu[c].department,
    	stu[c].DATE,
    	stu[c].NUM,
    	stu[c].ADD,
    	stu[c].CLASS,
    	stu[c].math,stu[c].eng,stu[c].lit,stu[c].aver);
		c++;
	}
	for(int i=1;i<=n;++i)
	{
		sprintf(stu[c].MSSV,"HS019%05d",i);
		dataprint(c);		
		fprintf(fptr, "%s,%s,%s,%s,%s,%s,%s,%.2f,%.2f,%.2f,%.2f\n",
			stu[c].MSSV,
			stu[c].NAME,
			stu[c].department,
			stu[c].DATE,
			stu[c].NUM,
			stu[c].ADD,
			stu[c].CLASS,
			stu[c].math,stu[c].eng,stu[c].lit,stu[c].aver);
			c++;
	}
	for(int i=1;i<=n;++i)
	{
		sprintf(stu[c].MSSV,"HS020%05d",i);
		dataprint(c);		
		fprintf(fptr, "%s,%s,%s,%s,%s,%s,%s,%.2f,%.2f,%.2f,%.2f\n",
			stu[c].MSSV,
			stu[c].NAME,
			stu[c].department,
			stu[c].DATE,
			stu[c].NUM,
			stu[c].ADD,
			stu[c].CLASS,
			stu[c].math,stu[c].eng,stu[c].lit,stu[c].aver);
			c++;
	}
	fprintf(fptr,"END");
}