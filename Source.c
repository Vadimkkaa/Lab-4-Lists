#include"Library.h"

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

	system("CLS");
	printf("Done\n");
	Sleep(1000);
	system("CLS");
}

void pushSpecialDate(Tours** plist, char* namee, int pricee, char* dataa) {
	Tours* p = malloc(sizeof(Tours));
	p->next = *plist;
	*plist = p;
	int  flagg;
	char symbol;
	int amount = 1;//of letters for name
	int pos = 0, g = 0;//position for letters in name
	//p->unite.date = (char*)malloc(9*sizeof(char));

	p->name = malloc(1 * sizeof(char));
	p->price = pricee;


	while (1) {

		//enter a letter
		if (namee[g] == '\0') {   //if this was the end of our word('\n')--we also need to finish
			//amount++;
			p->name[pos] = '\0';
			break;
		}
		amount++; //enlarge the amount of letters in our massive
		p->name = (char*)realloc(p->name, amount * sizeof(char)); //we just extend our massive
		p->name[pos++] = namee[g++]; //one more letter is entered:)
		 //transfer to the next position
	}
	//p->unite.date = (Tours*)realloc(p->unite.date,9*sizeof(Tours));
	strcpy(p->unite.date, dataa);
	p->flag = 0;
}

void pushSpecialDays(Tours** plist, char* namee, int pricee, int dayss) {
	Tours* p = malloc(sizeof(Tours));
	p->next = *plist;
	*plist = p;
	int  flagg;
	char symbol;
	int amount = 1;//of letters for name
	int pos = 0, g = 0;//position for letters in name


	p->name = malloc(1 * sizeof(char));
	p->price = pricee;

	while (1) {

		//enter a letter
		if (namee[g] == '\0') {   //if this was the end of our word('\n')--we also need to finish
			//amount++;
			p->name[pos] = '\0';
			break;
		}
		amount++; //enlarge the amount of letters in our massive
		p->name = (char*)realloc(p->name, amount * sizeof(char)); //we just extend our massive
		p->name[pos++] = namee[g++]; //one more letter is entered:)
		 //transfer to the next position
	}

	p->unite.days = dayss;
	p->flag = 1;
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
		system("CLS");
		printf("Deleted\n\n");
		Sleep(1000);
		system("CLS");
		
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
		printf("List is empty\n");
		
	else print(list, Amount);
}

void isEmptyPrintFull(Tours* list) {
	if (list == NULL)
		printf("List is empty\n");
		
    else printFull(list);
}

void freeLists(Tours* plist) {
	Tours* current = plist;
	Tours* current1 = NULL;
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
	system("CLS");
}

void isEmptyFree(Tours* plist) {
	if (plist == NULL)
		exit(0); else freeLists(plist);
}

void Search(Tours* plist) {
	Tours* current;
	current = plist;
	int choice;
	int Amount = 1;
	int searchFlag=0;
	printf("Please,choose the parameter u wanna find by\n1-Name\n2-Price\n3-Tour's start date\n4-Tour's duration\n");
	rewind(stdin);
	while (1) {
		rewind(stdin);
		if (!scanf("%d", &choice))
			printf("Wrong number.Try again\n"); else break;
	}
	switch (choice) {
	case 1:
	{
		int symbol='a';
		char* namee = malloc(sizeof(char));
		int pos = 0;
		int amount = 1;
		printf("Enter the Tour's name:\n");
		rewind(stdin);
	
		while (1) {

			scanf_s("%c", &symbol);  //enter a letter
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
		for (current = plist; current != NULL; current = current->next, Amount++) {
			
			if (strcmp(current->name, namee) == 0) {
				searchFlag = 1;
				isEmptyPrint(plist, Amount);
			}
			
		}
		if (searchFlag == 0)
			printf("Nothing was found :(\n\n");
		break;
	}
	case 2: {
		int pricee;
		printf("Enter the price:\n");
		while (1) {
			rewind(stdin);
			if (!scanf("%d", &pricee))
				printf("Wrong number.Try again\n"); else break;
		}

		for (current = plist; current != NULL; current = current->next, Amount++) {

			if (current->price == pricee){
				searchFlag = 1;
				isEmptyPrint(plist, Amount);
			}

		}
		if (searchFlag == 0)
			printf("Nothing was found :(\n\n");
		break;
	}
	case 3:
	{
		char datee[N];
		int unionFlag=0;
		rewind(stdin);
		while (1) {
			printf("Please,enter the start date in the format dd/mm/yy:\n");
			rewind(stdin);
			fgets(datee, N, stdin);
			if (datee[2] != '/' ||datee[5] != '/' || atoi(datee) > 31 || ((datee[3] - '0') * 10 + (datee[4] - '0') > 12))
				printf("Wrong format!Try again\n");
			else break;
		}

		for (current = plist; current != NULL; current = current->next, Amount++) {
			if (unionFlag == current->flag) {
					
				if (strcmp(datee, current->unite.date) == 0) {
					searchFlag = 1;
					isEmptyPrint(plist, Amount);
				}
					
					
			}
		}
		if (searchFlag == 0)
			printf("Nothing was found :(\n\n");
		break;
	}
	case 4: {
		int unionFlag = 1;
		int dayss;
		printf("Please,enter the The Tour's duration\n");
		while (1) {
			rewind(stdin);
			if (!scanf("%d", &dayss))
				printf("Wrong number!Try again\n");
			else break;
		}

		for (current = plist; current != NULL; current = current->next, Amount++) {
			if (unionFlag == current->flag) {
			
				if (dayss == current->unite.days) {
					searchFlag = 1;
					isEmptyPrint(plist, Amount);
				}
					
			}
		}
		if (searchFlag == 0)
			printf("Nothing was found :(\n\n");
		break;
	}
	default:
		printf("Wrong number\n\n");
	}
	
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

	int searchFlag = 0;

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
		if (!scanf("%d", &unionFlag) || unionFlag != 1 && unionFlag != 0)
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
					if (strcmp(datee, current->unite.date) == 0) {
						searchFlag = 1;
						isEmptyPrint(plist, Amount);
					}
				}
				else if (unionFlag == 1) {
					if (dayss == current->unite.days) {
						searchFlag = 1;
						isEmptyPrint(plist, Amount);
					}
				}
		}
	}
	if (searchFlag == 0)
		printf("Nothing was found :(\n");
	
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
		//fprintf(f,"%c",'|');
		fclose(f);
		break;
	}
	system("CLS");
	printf("Done\n");
	Sleep(1000);
	system("CLS");
	
}

void inputIntoBin(Tours* list, static int flagg, FILE* f) {
	Tours* p = list;
	int i = 0;
	char c, name[20];
	char name_f[100];
	char date[100];
	char* arr = malloc(sizeof(char));
	char symbol;
	int length = 1;
	static int specialFlag = 0;

	p = list;

	if (specialFlag == 0)
		list = list->next;
	if (list != NULL && specialFlag == 0) inputIntoBin(list, ++flagg, f);

	i = 0;

	if (list == NULL && specialFlag == 0) {
		list = p;
		specialFlag = 1;
		inputIntoBin(list, ++flagg, f);
		return;
	}

	while (1) {
		list = p;
		i = 0;
		fwrite(&(list->price), sizeof(int), 1, f);
		strcpy(name_f, list->name);
		while (name_f[i]) {
			fwrite(&name_f[i], sizeof(char), 1, f);
			i++;
		}
		fwrite(&name_f[i], sizeof(char), 1, f);
		i = 0;
		fwrite(&(list->flag), sizeof(int), 1, f);
		if (list->flag == 0) {
			strcpy(date, list->unite.date);
			while (date[i]) {
				fwrite(&date[i], sizeof(char), 1, f);
				i++;
			}
			fwrite(&date[i], sizeof(char), 1, f);

		}
		else {
			fwrite(&(list->unite.days), sizeof(int), 1, f);
		}
		flagg--;
		break;

		list = (list)->next;

	}

	system("CLS");
	printf("Done\n");
	Sleep(1000);
	system("CLS");
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
			FILE* file;
			if ((file = fopen(arr, "ab+")) == NULL) {
				printf("Open error\n");
				return 0;
			}
			inputIntoBin(list, 1, file);
			fclose(file);
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

int UploadBin(Tours** list) {
	FILE* f;
	Tours* p = *list;
	char file, c;
	int i = 0;
	char name[20];
	char name_for_copy[100], date[100];
	char* arr = malloc(sizeof(char));
	char symbol;
	int length = 1;

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


	if (!(f = fopen(arr, "rb+"))) {
		printf("Error opening\n");
		
		return 0;
	}


	i = 0;
	rewind(f);
	do {
		c = ' ';
		i = 0;
		fseek(f, -4, 1);
		if (!(*list = (Tours*)calloc(1, sizeof(Tours)))) {
			printf("Error");
			return 0;
		}
		fread(&(*list)->price, sizeof(int), 1, f);
		while (1) {
			fread(&name_for_copy[i], sizeof(char), 1, f);
			if (name_for_copy[i] == '\0') {
				break;
			}
			i++;
		}
		(*list)->name = (char*)calloc(30, sizeof(char));
		strcpy((*list)->name, name_for_copy);
		i = 0;
		fread(&(*list)->flag, sizeof(int), 1, f);
		if ((*list)->flag == 0) {
			while (1) {
				fread(&date[i], sizeof(char), 1, f);
				if (date[i] == '\0') {
					break;
				}
				i++;
			}

			strcpy((*list)->unite.date, date);
		}
		else {
			fread(&(*list)->unite.days, sizeof(int), 1, f);
		}
		(*list)->next = p;
		p = *list;
		fread(&i, sizeof(int), 1, f);
		if (feof(f)) {
			break;
		}
		rewind(stdin);
	} while (1);
	fclose(f);
	system("CLS");
	printf("Done\n");
	Sleep(1000);
	system("CLS");
	return 1;

}

void TextUpload(Tours** list) {
	char* arr;
	char* name, * data;
	int price;
	int flag;
	int days;
	char symbol;
	FILE* f;
	fpos_t current = 0;
	int i = 0, length = 1;
	int amount = 0;// Counter of amount of Lists for my reversePushing Function

	int amount1 = 0;
	char symbol1;
	char symbol2;
	int flag1 = 0;

	char number;//for the number of the string:1 or 2 and more importantly 13
	arr = (char*)malloc(1 * sizeof(char));
	name = (char*)malloc(1 * sizeof(char));
	data = (char*)malloc(9 * sizeof(char));
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
	if ((f = fopen(arr, "r+")) == NULL) {
		printf("Open error\n");
		return 0;
	}

	fseek(f, 0, 0);
	while (1) {
		fscanf(f, "%c", &symbol1);
		if (symbol1 == '.')
			amount1++;
		if (feof(f))
			break;
		//if (symbol1 == '|')                         //		
			//break;
	}
	// fseek(f, 7, 0);
	fseek(f, -4, 1);
	//fseek(f,5,1);
	while (amount1 > 0) {
		while (1) {
			if (flag1 == 1)
				fsetpos(f, &current);
			while (1) {

				fseek(f, -2, 1);
				fscanf(f, "%c", &symbol2);
				if (amount1 < 1)
					return;
				if (symbol2 == '\n')
					fseek(f, -1, 1);
				if (symbol2 == '.') {
					fgetpos(f, &current);
					flag1 = 1;
					break;
				}

			}

			fseek(f, 5, 1);
			length = 1;
			i = 0;
			while (1) {
				fscanf(f, "%c", &symbol);
				if (symbol == ' ') {
					name[i] = '\0';
					break;
				}
				name = (char*)realloc(name, ++length * sizeof(char));
				name[i++] = symbol;
			}
			//fscanf(f,"%s",&name1);
			fseek(f, 6, 1);
			fscanf(f, "%d", &price);
			fseek(f, 1, 1);
			fscanf(f, "%c", &symbol);
			if (symbol == 'D') {
				flag = 0;
				fseek(f, 13, 1);
				i = 0;
				while (1) {
					fscanf(f, "%c", &symbol);
					if (symbol == '\n') {
						data[i++] = '\0';
						amount++;
						pushSpecialDate(list, name, price, data);
						fscanf(f, "%c", &symbol);
						current -= 3;
						fsetpos(f, &current);
						amount1--;
						if (amount1 < 1) {
							printf("Done\n");
							system("CLS");
							return;
						}

						//fseek(f, 6, 1);

						break;
					}
					//  pushSpecial(list,name,price,data);


					data[i++] = symbol;


				}
			}
			else {
				flag = 1;
				fseek(f, 16, 1);//WTF i need to transfer to 15 position but in this case eveyrything goes to hell about the first list
				//fseek(f,-1,1);
				fscanf(f, "%d", &days);
				fscanf(f, "%c", &symbol);
				if (symbol == '\n') {
					amount++;
					pushSpecialDays(list, name, price, days);
					fscanf(f, "%c", &symbol);
					current -= 3;
					fsetpos(f, &current);
					amount1--;
					if (amount1 < 1) {
						printf("Done\n");
						
						return;
					}
					//fseek(f, 6, 1);


				}

			}
		}

	}
	fclose(f);
	system("CLS");
	printf("Done\n");
	Sleep(1000);
	system("CLS");
	//ReversePushing(list, amount);
}
