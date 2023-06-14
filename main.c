#include <stdio.h>
#include <stdlib.h>
#include <conio.h> //gotoxy
#include <string.h>
#include <windows.h>
#include <time.h>
#include "function.h"

/*
void login();
 typedef struct{
	char name_product[20],name_product[20];
	int id_product;
	int price;
	int price_product;
	int date_product; //date for rent
	float weight_product;
}stock;
*/
time_t t;

int main()
{	
	int choice;
	time(&t);
	printf("                                                                                                         \n");
	printf(" -------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t\t%s",ctime(&t));
	printf(" -------------------------------------------------------------------------------------------------------\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t==================================\t\t\t\t\t|\n");
	printf("|\t\t\t\t|\t     WELCOME TO \t |\t\t\t\t\t|\n");
	printf("|\t\t\t\t|\tSTOCKPILE MGMT SYSTEM\t |\t\t\t\t\t|\n");
	printf("|\t\t\t\t==================================\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t    Providing rental services at various stocks\t\t\t\t\t|\n");
	printf("|\t\t\t\t      Number:(+66)08x-xxx-xxxx\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t         \"Lost items and not be returned.        \t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|Press any key to continue.........\t\t\t\t\t\t\t\t\t|\n");
	printf(" -------------------------------------------------------------------------------------------------------\n"); 
    getch(); //hold screen 
	system("cls"); //change page
	login(); // call func login()
    printf(" -------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t\t%s",ctime(&t));
	printf(" -------------------------------------------------------------------------------------------------------\n");
	printf("|\t      ======================== Stock Management System ========================   \t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t< 1 > Add Product\t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t< 2 > Edit Product Detail\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t< 3 > Delete Product \t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t< 4 > Show Stock \t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t< 5 > Show Bills \t\t\t\t\t\t\t|\n");
	printf("|\t\t\t\t< 6 > Exit \t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t  =======================================\t\t\t\t\t|\n");
    printf(" \t\t\t     Please select your choice [1-6] : ");
    scanf("%d",&choice);
    system("cls");
    switch(choice){
    case 1:
        printf("1");
        break;
    case 2:
        printf("2");
        break;
    case 3:
        printf("3");
        break;
    case 4:
        printf("4");
        break;
    case 5:
        printf("5");
        break;
    case 6:
        printf("System is exit........");
        printf("6");
        break;
    default:
        printf("Invalid Input \nSystem Exit.......\n");
    	getchar();  
	}
}