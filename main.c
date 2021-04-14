//#include"Library.h"
//#include"Functions.h"
//typedef struct Tours Tours;
////int trips;
//struct Tours{
//	int price;
//	char* name;
//	union  {
//		char date[N];
//		int days;
//	}unite;
//	int flag;
//	Tours* next;
//};
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
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

void push(Tours** plist) {
	Tours* p = malloc(sizeof(Tours));
	p->next = *plist;
	*plist = p;
	int pricee, dayss, flagg;
	char symbol;
	int amount = 1;//of letters for name
	int pos = 0;//position for letters in name
	char datee[9];
	char* namee = malloc(sizeof(char));

	p->name = malloc(1 * sizeof(char));
	while (1) {
		printf("Please,enter the price:\n");
		rewind(stdin);
		if (!(scanf("%d", &pricee)) && pricee < 0) {
			printf("Wrong number!Please,try again\n");
		}
		else {
			p->price = pricee;
			break;
		}
	}

	printf("Please,enter the Tour name:\n");
	rewind(stdin);
	while (1) {

		scanf("%c", &symbol);  //enter a letter
		if (symbol == '\n') {   //if this was the end of our word('\n')--we also need to finish
			//amount++;
			p->name[pos] = '\0';
			break;
		}
		amount++; //enlarge the amount of letters in our massive
		p->name = (char*)realloc(p->name, amount * sizeof(char)); //we just extend our massive
		p->name[pos] = symbol; //one more letter is entered:)
		pos++; //transfer to the next position
	}

	while (1) {
		printf("What would you like to add:\n0-The date of start\n1-The trip's duration\n");
		rewind(stdin);
		if (!(scanf("%d", &flagg)) || flagg != 0 && flagg != 1) {
			printf("Wrong number!Please,try again\n");
		}
		else {
			switch (flagg)
			{
			case 0:
				p->flag = 0;
				while (1) {
					printf("Please,enter the start date in the format dd/mm/yy:\n");
					rewind(stdin);
					fgets(p->unite.date, N, stdin);
					if (p->unite.date[2] != '/' || p->unite.date[5] != '/' || atoi(p->unite.date) > 31 || ((p->unite.date[3] - '0') * 10 + (p->unite.date[4] - '0') > 12))
						printf("Wrong format!Try again\n");
					else break;
				}
				break;

			case  1:
				p->flag = 1;
				printf("Please,enter the trip's duration:\n");
				rewind(stdin);
				scanf("%d", &p->unite.days);
				break;


			}
			break;
		}

	}



}
void delete(Tours** plist) {
	Tours* pos2;
	Tours* pos1 = NULL;
	int choice;
	int amount = 0;
	char ch;
	for (Tours* pos2 = *plist; pos2 != NULL; pos2 = pos2->next)
		amount++;
	printf("Are you sure you wanna delete a list?\ny/n\n");
	while (1) {
		rewind(stdin);
		if (!(scanf("%c", &ch)))
			printf("Wrong letter!Try again\n"); else break;
	}
	if (ch == 'y' || ch == 'Y' && amount > 0) {
		while (1) {
			printf("Enter the number of list you wanna delete:\n");
			rewind(stdin);
			scanf("%d", &choice);
			if (choice < 1)
				continue;
			if (amount <= 0) {
				printf("No lists left:(\n");
				return;
			}
			if (amount < choice) {
				printf("We don't have this amount of lists\n");
				continue;
			}

			else break;

		}
		pos2 = *plist;
		if (choice == 1) {
			*plist = pos2->next;
			free(pos2);
			pos2 = *plist;
		}
		else {
			amount = 1;
			while (amount < choice && pos2 != NULL) {
				pos1 = pos2;
				pos2 = pos2->next;
				amount++;
			}
			pos1->next = pos2->next;
			free(pos2);
		}
		printf("Deleted\n\n");
		//trips--;
	}
}


void printFull(Tours* plist) {//////////MAKE IT AS A TABLE!!!!!!!!!!!!!!!!!!!!
	int number = 1;//number of the list
	printf("-----------------------------------------------------------------------------------------------------------------------\n");
	printf("|Information of the list   |   Price   |   The Tour's name   |   The Tour's date of start   |   The Tour's duration   |\n");
	printf("-----------------------------------------------------------------------------------------------------------------------\n");

	for (Tours* p = plist; p != NULL; p = p->next, number++) {
		printf("|%-26d", number);
		printf("|%-11d", p->price);
		printf("|%-21s", p->name);
		if (p->flag == 0) {
			printf("|%-30s", p->unite.date);
			printf("|\t\t\t      |");
		}
		if (p->flag == 1) {
			printf("|\t\t\t            |");
			printf("%-25d|", p->unite.days);
		}
		printf("\n");
		printf("-----------------------------------------------------------------------------------------------------------------------\n");
	}
	printf("\n");


	//for (Tours* p = plist; p!= NULL; p = p->next, number++) {
	//	printf("|%d\t\t           |", number);
	//	printf("%d\t       |", p->price);
	//	printf("%s\t             |", p->name);
	//	if (p->flag == 0){
	//		printf("%s\t                    |",p->unite.date);
	//		printf("\t                      |");
	//    }
	//	if (p->flag == 1) {
	//		printf("\t                            |");
	//		printf("%d \t\t      |",p->unite.days);
	//	}
	//	printf("\n");
	//	printf("-----------------------------------------------------------------------------------------------------------------------\n");
	//}
//	printf("\n");
	//trips = number;
}

void print(Tours* plist, int Amount) {
	int number = 1;//number of the list
	number = Amount;
	Tours* p = plist;
	while (Amount > 1) {
		p = p->next;
		Amount--;
	}

	printf("-----------------------------------------------------------------------------------------------------------------------\n");
	printf("|Information of the list   |   Price   |   The Tour's name   |   The Tour's date of start   |   The Tour's duration   |\n");
	printf("-----------------------------------------------------------------------------------------------------------------------\n");

	printf("|%-26d", number);
	printf("|%-11d", p->price);
	printf("|%-21s", p->name);
	if (p->flag == 0) {
		printf("|%-30s", p->unite.date);
		printf("|\t\t\t      |");
	}
	if (p->flag == 1) {
		printf("|\t\t\t            |");
		printf("%-25d|", p->unite.days);
	}
	printf("\n");
	printf("-----------------------------------------------------------------------------------------------------------------------\n");

	printf("\n");
}
void isEmptyPrint(Tours* list, int Amount) {
	if (list == NULL)
		printf("List is empty\n"); else print(list, Amount);
}
//void isEmptyDelete(Tours** list) {
//	if (*list == NULL)
//		printf("List is empty\n"); else delete(&list); ;
//}
void isEmptyPrintFull(Tours* list) {
	if (list == NULL)
		printf("List is empty\n"); else printFull(list);
}
void freeLists(Tours* plist) {
	Tours* current = plist;
	Tours* current1=NULL;
	int amount = 1;
	while (current) {
		current = current->next;
		amount++;
	}
	current = plist;
	current1 = current;
	while (amount > 0) {
		current = current->next;
		free(current1);
		if (current == NULL)
			break;
		current1 = current;
		amount--;
	}
	printf("Done\n");
}
void isEmptyFree(Tours*plist) {
	if (plist == NULL)
		exit(0); else freeLists(plist);
}
void CompleteSearch(Tours* plist) {
	Tours* current;
	current = plist;
	int pricee;

	char datee[N];
	int dayss;
	int unionFlag;

	char* namee = malloc(sizeof(char));
	char symbol;
	int pos = 0, amount = 1;

	int Amount = 1;//for calling the function of Print
	printf("Enter all required aspects:\n");
	rewind(stdin);
	printf("Enter the price:\n");
	while (1) {
		rewind(stdin);
		if (!scanf("%d", &pricee))
			printf("Wrong number.Try again\n"); else break;
	}

	printf("Enter the Tour's name:\n");
	rewind(stdin);
	while (1) {

		scanf("%c", &symbol);  //enter a letter
		if (symbol == '\n') {   //if this was the end of our word('\n')--we also need to finish
			//amount++;
			namee[pos] = '\0';
			break;
		}
		amount++; //enlarge the amount of letters in our massive
		namee = (char*)realloc(namee, amount * sizeof(char)); //we just extend our massive
		namee[pos] = symbol; //one more letter is entered:)
		pos++; //transfer to the next position
	}

	printf("What would you like to enter?\n0-The Tour's date of start\n1-The Tour's duration\n");
	while (1) {
		rewind(stdin);
		if (!scanf("%d", &unionFlag) || unionFlag != 1 && unionFlag != 2)
			printf("Wrong number!Try again\n");
		else break;
	}
	switch (unionFlag) {
	case 0:
		printf("Please,enter the Date of start:\n");
		fgets(datee, N, stdin);
		break;
	case 1:
		printf("Please,enter the The Tour's duration\n");
		while (1) {
			rewind(stdin);
			if (!scanf("%d", &dayss))
				printf("Wrong number!Try again\n");
			else break;
		}
		break;
	}

	for (current = plist; current != NULL; current = current->next, Amount++) {
		if (unionFlag == current->flag) {
			if (strcmp(current->name, namee) == 0 && pricee == current->price)
				if (unionFlag == 0)
				{
					if (strcmp(datee, current->unite.date) == 0)
						isEmptyPrint(plist, Amount);
				}
				else if (unionFlag == 1) {
					if (dayss == current->unite.days)
						isEmptyPrint(plist, Amount);
				}
		}
	}
}
void inputIntoText(Tours* plist, char* arr) {
	Tours* current = plist;
	//char addInformation;
	int i = 1;
	FILE* f;
	fpos_t endSet = 0;

	while (1) {
		rewind(stdin);
		if ((f = fopen(arr, "a+")) == NULL) {
			printf("Open error\n");
			return 0;
		}
		while (current) {
			fsetpos(f, &endSet);
			fprintf(f, "%d", i);
			fprintf(f, "%c", '.');
			fprintf(f, "%s", "Name:");
			fprintf(f, "%s", current->name);
			fprintf(f, "%c", ' ');
			fprintf(f, "%s", "Price:");
			fprintf(f, "%d", current->price);
			if (current->flag == 0) {
				fprintf(f, "%c", ' ');
				fprintf(f, "%s", "Date of start:");
				fprintf(f, "%s", current->unite.date);
			}
			else {
				fprintf(f, "%c", ' ');
				fprintf(f, "%s", "Trips's duration:");
				fprintf(f, "%d", current->unite.days);
			}
			fprintf(f, "%c", '\n');
			current = current->next;
			i++;
		}
		fclose(f);
		break;
	}
}
inputIntoBin(Tours*plist,char* arr) {
	Tours* current = plist;
	//char addInformation;
	int i = 1;
	FILE* f;
	fpos_t endSet = 0;
	char c = '.';
	char c1 = ' ';
	char c2 = '\n';
	char namee[] = "Name:";
	char namee1[] = "Price:";
	char namee2[] = "Date of start:";
	char namee3[] = "Trip's duration";
	while (1) {
		rewind(stdin);
		if ((f = fopen(arr, "ab+")) == NULL) {
			printf("Open error\n");
			return 0;
		}
		while (current) {
			fsetpos(f, &endSet);
			fwrite(&(i),sizeof(int),1,f);
			fwrite(&(c),sizeof(char),1,f);
			fwrite(&(namee),sizeof(char),5,f);
			fwrite(&(current->name),sizeof(char),sizeof(current->name)/sizeof(char),f);
			fwrite(&(c1),sizeof(char),1,f);
			fwrite(&(namee1),sizeof(char),6,f);
			fwrite(&(current->price),sizeof(int),1,f);
			if (current->flag == 0) {
				fwrite(&(c1),sizeof(char),1,f);
				fwrite(&(namee2),sizeof(char),14,f);
				fwrite(&(current->unite.date),sizeof(char),8,f);
			}
			else {
				fwrite(&(c1),sizeof(char),1,f);
				fwrite(&(namee3),sizeof(char),17,f);
				fwrite(&(current->unite.days),sizeof(int),1,f);
			}
			fwrite(&(c2),sizeof(char),1,f);
			current = current->next;
			i++;
		}
		fclose(f);
		break;
	}
}
void FileCreate(Tours* list) {
	int choice;
	char symbol;
	char* arr;
	int i = 0, length = 1;
	int max;
	int Amount;//of numbers
	arr = (char*)malloc(1 * sizeof(char));

	while (1) {
		printf("Please,choose the file type\n1-Text\n2-Binary\n3-Exit\n");
		rewind(stdin);
		scanf_s("%d", &choice);
		if (choice == 1) {                                                              //TEXT
			printf("Please enter the file name:\n");
			rewind(stdin);
			while (1) {
				scanf("%c", &symbol);
				if (symbol == '\n') {

					if (arr[i - 4] == '.' && arr[i - 3] == 't' && arr[i - 2] == 'x' && arr[i - 1] == 't') {
						arr[i] = '\0';
						break;
					}

					if (arr[i - 1] == '.') {
						length += 3;
						arr = (char*)realloc(arr, length * sizeof(char));
						arr[i] = 't';
						arr[i + 1] = 'x';
						arr[i + 2] = 't';
						arr[i + 3] = '\0';
						break;
					}

					length += 4;
					arr = (char*)realloc(arr, length * sizeof(char));
					arr[i] = '.';
					arr[i + 1] = 't';
					arr[i + 2] = 'x';
					arr[i + 3] = 't';
					arr[i + 4] = '\0';
					break;
				}
				arr[i] = symbol;
				i++;
				length++;
				arr = (char*)realloc(arr, length * sizeof(char));
			}
			rewind(stdin);
			inputIntoText(list, arr);
			printf("Done\n");
			break;
		}
		else if (choice == 2) {                                                           //bINARY
			printf("Please enter the file name:\n");
			rewind(stdin);
			while (1) {
				scanf("%c", &symbol);
				if (symbol == '\n') {

					if (arr[i - 4] == '.' && arr[i - 3] == 'b' && arr[i - 2] == 'i' && arr[i - 1] == 'n') {
						arr[i] = '\0';
						break;
					}

					if (arr[i - 1] == '.') {
						length += 3;
						arr = (char*)realloc(arr, length * sizeof(char));
						arr[i] = 'b';
						arr[i + 1] = 'i';
						arr[i + 2] = 'n';
						arr[i + 3] = '\0';
						break;
					}

					length += 4;
					arr = (char*)realloc(arr, length * sizeof(char));
					arr[i] = '.';
					arr[i + 1] = 'b';
					arr[i + 2] = 'i';
					arr[i + 3] = 'n';
					arr[i + 4] = '\0';
					break;
				}
				arr[i] = symbol;
				i++;
				length++;
				arr = (char*)realloc(arr, length * sizeof(char));
			}
			rewind(stdin);
			inputIntoBin(list,arr);
			printf("Done\n");
			break;
		}

		else if (choice == 3) return 0;
		else {
			printf("Wrong number!\n");
			return 0;
		}
	}
}


int main(void) {
	Tours* list=NULL;
	int choice;
	char c;
	while (1) {
		printf("What would you like to do?\n1-Add a list\n2-See the whole list\n3-Delete one list\n4-Find sth(full enter)\n5-Save your lists\n6-Upload a list\n7-Exit program\n");
		rewind(stdin);
		scanf("%d", &choice);
		switch (choice) {
		    case 1:
				push(&list);
			    break;
		    case 2:
				isEmptyPrintFull(list);
			    break;
			case 3:
				delete(&list);
				break;
			case 4:
				printf("Wanna find sth(all parameteres)?\ny/n\n");
				rewind(stdin);
				while (1) {
					rewind(stdin);
					if (!(scanf_s("%c", &c)) || c != 'y' && c != 'Y' && c != 'n' && c != 'N')
						printf("Sth went wrong!Please please, try again\n"); else break;
				}
				if (c == 'y' || c == 'Y')
				CompleteSearch(list);
				break;
			case 5:
				printf("Let's create a file first\n");
				FileCreate(list);
				break;
			case 6:
				break;
			case 7:
				isEmptyFree(list);
				return 0;
				break;
			default :
				printf("Wrong number!Please try again\n");
				printf("\n");
		}
	}
	return 0;
}