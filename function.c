#include <stdio.h>
#include <stdlib.h>
#include <conio.h> //gotoxy
#include <string.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>

struct customer{
	char name_product[20],name_company[20],weight_str[20];
	int id_product;
	int price;
	int price_product;
	int date_product; //date for rent
	float weight_product;
}ct;

void login(void){
    int count = 0, i = 0;
    char user_name[10],check = ' ';
    char user_pass[10],code[10];
    char admin_user[10] = "user";
    char admin_pass[10] = "pass";
printf(" -------------------------------------------------------------------------------------------------------\n");
    do{
        printf("\n =============================================  LOGIN   ============================================== \n");
        printf(" \n\t\t\t\t     USERNAME: ");
	    scanf("%s", &user_name); 
	    printf(" \n\t\t\t\t     PASSWORD: ");
        while(i<10){
            user_pass[i] = getch();
            check = user_pass[i];
            if (check == 13){break;} //limit size of user
            else {printf("*");}
            i++;
        }
        user_pass[i] = '\0'; //delete null character
        i = 0;
        if(strcmp(user_name,admin_user) == 0 && strcmp(user_pass,admin_pass) == 0)
        {
            printf("  \n\n\n\t\t\t\t       \033[4mLOGIN IS SUCCESSFUL!!!\033[0m");
	        printf("\n\n\n\t\t\t\t     Press any key to continue...");
	        getch();//holds the screen
	        break;   
        }else{
            printf("\n\n\n\t\t\t\t   \033[4mSORRY !!!!  LOGIN IS UNSUCESSFUL\033[0m");
            printf("\n\n\n\t\t\t\t          Please try again\n");
		    count++;
		    getch();//holds the screen
        }
    }while(count <= 2);
        if(count > 2){
            printf("\n\t\t \033[4mSorry you have entered the wrong username and password for four times!!!\033[0m");
		    getch();  //holds the screen
            }
    getch();
    system("cls");
}
/*
void list_menu() {
    time_t t;
    int choice;
    printf(" -------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t%s", ctime(&t));
    printf(" -------------------------------------------------------------------------------------------------------\n");
    printf("|\t      ======================== Stock Management System ========================   \t\t|\n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t< 1 > Add Product\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t< 2 > Edit Product Detail\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t< 3 > Delete Product \t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t< 4 > Search Product \t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t< 5 > Show Stock \t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t< 6 > Show Bills \t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t< 7 > Exit \t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t  =======================================\t\t\t\t\t|\n");
    printf(" \t\t\t     Please select your choice [1-7]: ");
    scanf("%d", &choice);
    system("cls");

    switch (choice) {
        case 1:
            add();
            break;
        case 2:
            printf("2");
            break;
        case 3:
            printf("3");
            break;
        case 4:
            search();
            break;
        case 5:
            printf("5");
            break;
        case 6:
            printf("6");
            break;
        case 7:
            printf("System is exiting........");
            printf("7");
            break;
        default:
            printf("Invalid Input \nSystem Exit.......\n");
            getchar();
    }
}
*/
void add(){
   FILE *fp;
    int valid, index;
    char c;

do {
    system("cls");
    printf("\t      ======================== Stock Management System ========================   \t\t\n");
    int Id; // comparing ID if file != NULL
    fp = fopen("D:\\Project-111\\text\\filecs.txt", "a+"); // change to "a+"

    if (fp != NULL) { // Check if the file was opened successfully
        // Add product code
        I:
        printf("\nEnter Product Code\t : ");
        scanf("%d", &Id);

        while (fscanf(fp, "%s %s", ct.name_company, ct.name_product) != EOF) {
            if (Id == ct.id_product) {
                printf("\n\n\t-------------------> THE PRODUCT CODE ALREADY EXISTS.\n");
                goto I;
            }
        }

        ct.id_product = Id;
    } else {
        printf("\nProduct Code\t :");
        scanf("%d", &ct.id_product);
    }

    // Add product Company name
    do {
        fflush(stdin);
        printf("\nEnter Company name\t : ");
        gets(ct.name_company);
        ct.name_company[0] = toupper(ct.name_company[0]);

        for (index = 0; index < strlen(ct.name_company); ++index) {
            if (isalpha(ct.name_company[index]))
                valid = 1; // character is valid
            else {
                valid = 0; // character is not valid
                break;
            }
        }
        if (!valid) {
            printf("\n\t ------------------->Name contains invalid characters. Please enter again.");
            getch();
        }
    } while (!valid);
    // Add product name
    do {
        fflush(stdin);
        printf("\nEnter Product name\t : ");
        gets(ct.name_product);
        ct.name_product[0] = toupper(ct.name_product[0]);

        for (index = 0; index < strlen(ct.name_product); ++index) {
            if (isalpha(ct.name_product[index]))
                valid = 1; // character is valid
            else {
                valid = 0; // character is not valid
                break;
            }
        }
        if (!valid) {
            printf("\n\t ------------------->Name contains invalid characters. Please enter again.");
            getch();
        }
    } while (!valid);
    //Add weight of product
    do {
        fflush(stdin);
        printf("\nEnter Weight of Product(kg.)\t : ");
        fgets(ct.weight_str, sizeof(ct.weight_str), stdin);
        //ct.name_product[0] = toupper(ct.name_product[0]);
        size_t len = strlen(ct.weight_str);
        if (ct.weight_str[len - 1] == '\n') {
            ct.weight_str[len - 1] = '\0';
        }
        valid = 1;
        for (size_t index = 0; index < strlen(ct.weight_str); ++index) {
            if (!isdigit(ct.weight_str[index]) && ct.weight_str[index] != '.'){
                valid = 0; // not character --> digits
                break;
            }
        }
        if (valid) {
            ct.weight_product = atof(ct.weight_str);
            break;
        }else{
            printf("\n\t ------------------->Name contains invalid characters. Please enter again.");
            getch();
        }
    } while (valid);
    //Add date of rental
    do {    
        fflush(stdin);
        printf("\nEnter the number of days to rent\t : ");
        //scanf("%d",&ct.date_product);
        if (scanf("%d",&ct.date_product) > 0){
            valid = 1;
        }else{
            valid = 0;
            break;
        }
        if (!valid){
            printf("\n\t ------------------->Name contains invalid characters. Please enter again.");
            getch(); 
        }
    } while (!valid);
    // Write data to the file
    fprintf(fp, "%s %s %.2f %d\n", ct.name_company, ct.name_product, ct.weight_product, ct.date_product);
    fclose(fp); // Close the file
    printf("\n------------------->Press 'Enter' to add more item | Press any key to go to main menu");
} while ((c = getch())  == '\r');
    //list_menu();
}//end func add

void search(){
    char input_keyword[50],c;
    int found = 0;
    FILE *fp;
    fp = fopen("D:\\Project-111\\text\\filecs.txt", "r"); //open to read
    printf("\n Enter Keyword to search: ");
    fflush(stdin);
    gets(input_keyword);
    input_keyword[0] = toupper(input_keyword[0]);
    while (!feof(fp) && found == 0){
        fscanf(fp, "%s %s %f %d\n", ct.name_company, ct.name_product, &ct.weight_product, &ct.date_product);
        if(strcmp(input_keyword,ct.name_company)== 0){
            found = 1;
        }
    }
    if(found){
        printf(" -------------------Record found-----------------------\n");
        printf(" Company name: %s \n Product name: %s \n Weight Product(Kg.): %.2f\n Amount of rental days: %d\n",ct.name_company, ct.name_product, ct.weight_product, ct.date_product);
        printf(" ------------------------------------------------------\n");
    }else{
        printf(" -------------------Record not found-------------------\n");        
    }fclose(fp); // close tha file
    printf("Press any key to go to main menu");
    while(c == getch() == '\r');

}//end search func

void del_product(void) {
    char target[20], c;
    FILE *fp, *fn;
    int found = 0;

    fp = fopen("D:\\Project-111\\text\\filecs.txt", "r");
    fn = fopen("D:\\Project-111\\text\\file_edit.txt", "w+");

    printf("\nEnter name Company to Delete: ");
    fflush(stdin);
    scanf("%s", target);
    target[0] = toupper(target[0]);

    while (fscanf(fp, "%s %s %f %d\n", ct.name_company, ct.name_product, &ct.weight_product, &ct.date_product) != EOF) {
        if (strcmp(target, ct.name_company) == 0 || strcmp(target, ct.name_product) == 0) {
            found = 1;
        } else {
            fprintf(fn, "%s %s %f %d\n", ct.name_company, ct.name_product, ct.weight_product, ct.date_product);
        }
    }
    if (!found) {
        printf("\nRecord not found!");
        getch();
        //menu
    } else {
        printf("\nRecord deleted!");
    }
    fclose(fp);
    fclose(fn);
    remove("D:\\Project-111\\text\\filecs.txt");
    rename("D:\\Project-111\\text\\file_edit.txt", "D:\\Project-111\\text\\filecs.txt");

    printf("\n\n\n\t\t\t\tPress any key to continue...");
    while ((c = getch()) == '\r');
    //menu();
}
