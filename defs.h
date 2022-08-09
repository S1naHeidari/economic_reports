#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdint.h>
#include <errno.h>

typedef struct{
    char countryCode[4];
    char countryName[20];
    char gender;
    char degree[3];
    int year;
    long int numGrads;
}RecordType;

// Report 1 struct
typedef struct{
    float percentL6;
    float percentL7;
    float percentL8;
    long int total;
    char countryName[20];
}DegreePercent;

// Report 2 struct
typedef struct{
    float percentage;
    char countryName[20];
}FemaleGrads;

// Report 3 struct
typedef struct{
    float percent2014;
    float percent2015;
    float percent2016;
    float percent2017;
    char countryName[20];
}YearGrads;

// Report 4 struct
typedef struct{
    char countryCode[4];
    char countryName[20];
}CountryCodes;

// Report 5 struct
typedef struct{
    char degree[3];
    char countryName[20];
    long int total;
}TotalForDegree;


typedef struct Node{
    RecordType recordNode;
    struct Node *prev, *next;
}NodeType;

typedef struct{
    NodeType *head, *tail;
}ListType;

void initCountryCodes(ListType*);
void initData(ListType*);
void initDegreePercentages(ListType*);
void initDegreeYearTotal(ListType*);
void initFemaleGraduations(ListType*);
void initYearPercentages(ListType*);
int64_t my_getline(char **, size_t *, FILE *);
