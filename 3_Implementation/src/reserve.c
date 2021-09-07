
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<Windows.h>
#include"airline.h"
void details()
{
printf("\n\t Enter your passport number:");
	gets(seek->passport); fflush(stdin);
	printf("\n\t Enter your  name:");
	gets(seek->name); fflush(stdin);
	printf("\n\t Enter your email address:");
	gets(seek->email); fflush(stdin);
    printf("\n\t Enter the Destination : ");
    gets(seek->destination); fflush(stdin);
    printf("\n\t Enter the gender : ");
    gets(seek->gender); fflush(stdin);
    printf("\n\t Enter the permanent address : ");
    gets(seek->address); fflush(stdin);
    printf("\n\t Enter the phone number : ");
    gets(seek->phonenumber); fflush(stdin);
	
    
}
void reservation(int a)
{
	
	seek =start;
	if (start== NULL)
	{
		// first user
		start= seek = (struct garuda_t*)malloc(sizeof(struct garuda_t));
		details();
		seek->track = NULL;
		printf("\n\t Seat booking successful!");
		printf("\n\t your seat number is: Seat A-%d", a);
		seek->seatnumber = a;
		return;
	}
	else if (a > 15) // FULL SEATS
	{
		printf("\n\t\t Seat Full.");
		return;
	}
	else
	{
		// next user
		while (seek->track)
			seek = seek->track;
		seek->track = (struct garuda_t *)malloc(sizeof(struct garuda_t));
		seek = seek->track;
		details();
		seek->track = NULL;
		printf("\n\t Seat booking succesful!");
		printf("\n\t your seat number is: Seat A-%d", a);
		seek->seatnumber = a;
		return;
	}
}
void savefile()
{
	FILE *fpointer = fopen("garuda records", "w");
	if (!fpointer)
	{
		printf("\n Error while opening file!");
		return;
		Sleep(800);
	}
	seek =start;
	while (seek)
	{
		fprintf(fpointer, "%-6s", seek->passport);
		fprintf(fpointer, "%-15s", seek->name);
		fprintf(fpointer, "%-15s", seek->email);
        fprintf(fpointer, "%-15s", seek->destination);
        printf(fpointer,"%-7s", seek->gender);
        printf(fpointer,"%-100s", seek->address);
        printf(fpointer,"%-10d", seek->phonenumber);
        fprintf(fpointer, "\n");
		seek = seek->track;
	}
	printf("\n\n\t Details have been saved to a file (garuda_t records)");
	fclose(fpointer);
}

void displayrecord()
{
	seek = start;
	while (seek)
	{
		printf("\n\n Passport Number : %-6s", seek->passport);
		printf("\n         name : %-15s", seek->name);
		printf("\n      email address: %-15s", seek->email);
		printf("\n      Seat number: A-%d", seek->seatnumber);
        printf("\n     Destination:%-15s", seek->destination);
printf("\n              gender:%-7s", seek->gender);
        printf("\n       address:%-100s", seek->address);
        printf("\n        phonenumber:%-10d", seek->phonenumber);
		printf("\n\n++*=====================================================*++");
		seek = seek->track;
	}
	}
void cancellation()
{
	seek= start;
	system("cls");
	char passport[6];
	printf("\n\n Enter passort number to delete :");
	gets(passport); fflush(stdin);
	if (strcmp(start->passport, passport) == 0)
	{
		mcopy = start;
		start= start->track;
		free(mcopy);
		printf(" booking deleted");
		Sleep(800);
		return;

	}
     while (seek->track)
	{
		if (strcmp(seek->track->passport, passport) == 0)
		{
			mcopy = seek->track;
			seek->track = seek->track->track;
			free(mcopy);
			printf("has been deleted ");
			getch();
			Sleep(800);
			return;
		}
		seek= seek->track;
	}
	printf("passport number  wrong  check your passport");
	}
