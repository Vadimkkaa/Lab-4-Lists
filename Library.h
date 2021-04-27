#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<Windows.h>

#define N 9
typedef struct Tours Tours;
//int trips;
struct Tours {
	int price;
	char* name;
	union {
		char date[N];
		int days;
	}unite;
	int flag;
	Tours* next;
};

void push(Tours** plist);

void pushSpecialDate(Tours** plist, char* namee, int pricee, char* dataa);

void pushSpecialDays(Tours** plist, char* namee, int pricee, int dayss);

void delete(Tours** plist);

void printFull(Tours* plist);

void print(Tours* plist, int Amount);

void isEmptyPrint(Tours* list, int Amount);
//void isEmptyDelete(Tours** list) {
//	if (*list == NULL)
//		printf("List is empty\n"); else delete(&list); ;
//}
void isEmptyPrintFull(Tours* list);

void freeLists(Tours* plist);

void isEmptyFree(Tours* plist);

void Search(Tours*plist);

void CompleteSearch(Tours* plist);

void inputIntoText(Tours* plist, char* arr);

void inputIntoBin(Tours* list, static int flagg, FILE* f);

void FileCreate(Tours* list);

int UploadBin(Tours** list);

void TextUpload(Tours** list);
