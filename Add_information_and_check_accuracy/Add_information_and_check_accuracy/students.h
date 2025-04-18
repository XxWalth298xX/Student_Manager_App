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