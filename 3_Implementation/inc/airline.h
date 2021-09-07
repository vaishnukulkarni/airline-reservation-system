#ifndef __airline_H__
#define __airline_H__

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<Windows.h>


struct garuda_t
{
	char passport[6];
	char name[15];
    char destination[15];
	int seatnumber;
	char email[15];
	char gender[7];
	char address[100];
	int phonenumber[10];

	struct garuda_t *track;
}
*start, *seek;
struct garuda_t *mcopy;
#endif