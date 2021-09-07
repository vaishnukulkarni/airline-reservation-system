#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<Windows.h>
#include"reserve.h"
#include"airline.h"
void cancellation();
void displayrecord();
void savefile();
void main()
{
	
	int option;
	start = seek = NULL;
	int number = 1;
	do
	{
        printf("\n\t\t      GARUDA AIRLINES                 ");
		printf("\n\n\n\t\t Please enter your choice from below (1-4):");
		printf("\n\n\t\t 1. RESERVATION");
		printf("\n\n\t\t 2. CANCELLATION");
		printf("\n\n\t\t 3. DISPLAY RECORDS");
		printf("\n\n\t\t 4. EXIT");
		printf("\n\n\t\t ANY ISSUE HELP LINE:08394-22746 ");
		printf("\n\n\t\t Enter your choice :");
        scanf("%d", &option); fflush(stdin);
		system("cls");
		switch (option)
		{
		case 1:
			reservation(number);
			number++;
			break;
		case 2:
			cancellation();
			break;
		case 3:
			displayrecord();
			break;
		case 4:
		{
				  savefile();
				  break;
		}
		default:
			printf("\n\n\t SORRY INVALID CHOICE!");
			printf("\n\n\t PLEASE CHOOSE FROM 1-4");
			printf("\n\n\t Do not forget to chose from 1-4");
		}
		getch();
	} while (option != 4);
}

