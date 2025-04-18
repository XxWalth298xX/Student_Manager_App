#pragma once
typedef struct {
    char MSSV[20];
    char NAME[100];
    char DATE[100];
    char NUM[12];
    char ADD[11];
    char CLASS[10];
    char department[20];
    float math;
    float lit;
    float eng;
    float aver;
} profile;
void studentdata(profile *s);
void printdata(profile *s, long ID);
void cleardata();
void studentdata1(profile *s);
void printdata1(profile *s, long ID);
void cleardata1();
void studentdatadem(profile *s);
int data18print(profile *s);
int data19print(profile *s);
int data20print(profile *s);
void printdatareverse(profile s);
void delete_data(profile *s, long ID);
