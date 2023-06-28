#include <stdio.h>
#include <stdlib.h>
#include <conio.h> //gotoxy
#include <string.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>

#define MAX_CUSTOMERS 50 //จำนวนลูกค้า

struct customer{
	char name_product[20],name_company[20],weight_str[20];
	int id_product;
	int price_product;
	int date_product; //date for rent
	float weight_product;
}ct;

void login(void){
    int count = 0, i = 0;
    char user_name[10],check = ' ';
    char user_pass[10];
    char admin_user[10] = "user";
    char admin_pass[10] = "pass";
printf(" -------------------------------------------------------------------------------------------------------");
    do{
        printf("\n\n =============================================  LOGIN   ============================================== \n");
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
            list_menu();
	        break;   
        }else{
            printf("\n\n\n\t\t\t\t   \033[4mSORRY !!!!  LOGIN IS UNSUCESSFUL\033[0m");
            printf("\n\n\n\t\t\t\t          Please try again");
		    count++;
		    getch();//holds the screen
        }
    }while(count <= 3);
        if(count > 3){
            printf("\n\t\t \033[4mSorry you have entered the wrong username and password for four times!!!\033[0m");
		    getch();  //holds the screen
            exit(0);
            }
}

void list_menu() {
    time_t t;
    int choice;
    I:
    system("cls");
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
    printf("|\t\t\t\t< 6 > Exit \t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t  =======================================\t\t\t\t\t|\n");
    printf(" \t\t\t     Please select your choice [1-6]: ");
    scanf("%d", &choice);
    system("cls");

    switch (choice) {
        case 1:
            add();
            break;
        case 2:
            edit_info();
            break;
        case 3:
            del_product();
            break;
        case 4:
            search();
            break;
        case 5:
            bills();
            break;
        case 6:
            printf("System is exiting........");
            exit(0);
            break;
        default:
            printf(" -------------------------------------------------------------------------------------------------------\n");
            printf("  =========================================  INVALID INPUT   ========================================== \n");
            printf("\n\n\t\t-------->Please select [1-6] | Press any button to main menu .....");
            fflush(stdin);
            getchar();
            system("cls");
            goto I;
            break;
    }
}

void add(){
   FILE *fp;
    int valid, index;
    char c;

printf(" -------------------------------------------------------------------------------------------------------\n");
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
    fprintf(fp, "%d %s %s %.2f %d\n", ct.id_product, ct.name_company, ct.name_product, ct.weight_product, ct.date_product);
    fclose(fp); // Close the file
    printf("\n------------------->Press 'Enter' to add more item | Press any key to go to main menu");
} while ((c = getch())  == '\r');
    list_menu();
}//end func add

void search(){
    char input_keyword[50],c;
    int found = 0;
    FILE *fp;
    fp = fopen("D:\\Project-111\\text\\filecs.txt", "r"); //open to read
    printf(" -------------------------------------------------------------------------------------------------------\n");
    printf("\t      ======================== Stock Management System ========================   \t\t\n");
    printf("\n ---> Enter Keyword to search: ");
    fflush(stdin);
    gets(input_keyword);
    input_keyword[0] = toupper(input_keyword[0]);
    while (!feof(fp) && found == 0){
        fscanf(fp, "%d %s %s %f %d\n", &ct.id_product, ct.name_company, ct.name_product, &ct.weight_product, &ct.date_product);
        if(strcmp(input_keyword,ct.name_company)== 0){
            found = 1;
        }
    }
    if(found){
        printf(" \n ------------------------------------------Record found!----------------------------------------------\n"); 
        printf(" Company name: %s \n Product name: %s \n Weight Product(Kg.): %.2f\n Amount of rental days: %d\n",ct.name_company, ct.name_product, ct.weight_product, ct.date_product);
        printf(" ------------------------------------------------------\n");
    }else{
        printf(" \n ------------------------------------------Record not found!------------------------------------------\n");      
    }fclose(fp); // close tha file
    printf("\nPress any key to go to main menu....");
    while(c == getch() == '\r');
    list_menu();
}//end search func

void del_product(void) {
    char target[20], check;
    FILE *fp, *fn;
    int found = 0;

    fp = fopen("D:\\Project-111\\text\\filecs.txt", "r");
    fn = fopen("D:\\Project-111\\text\\file_edit.txt", "w+");

    printf(" -------------------------------------------------------------------------------------------------------\n");
    printf("\t      ======================== Stock Management System ========================   \t\t\n");
    printf("\n    Enter name Company to Delete: ");
    fflush(stdin);
    scanf("%s", &target);
    target[0] = toupper(target[0]);

    while (fscanf(fp, " %d %s %s %f %d\n", &ct.id_product, ct.name_company, ct.name_product, &ct.weight_product, &ct.date_product) != EOF) {
        if (strcmp(target, ct.name_company) == 0 || strcmp(target, ct.name_product) == 0) {
            printf(" ------------------------------------------------------\n");
            printf(" - Company name: %s \n - Product name: %s \n - Weight Product(Kg.): %.2f\n - Amount of rental days: %d\n",ct.name_company, ct.name_product, ct.weight_product, ct.date_product);
            printf(" ------------------------------------------------------\n");
            printf("\n    Press 'Y' to edit the existing record or any key to cancel...");
            fflush(stdin);
            scanf("%c",&check);
            if(check == 'Y' || check == 'y'){
                found = 1;
            }else{
                goto I;
            }
        } else {
            fprintf(fn, "%d %s %s %f %d\n", ct.id_product, ct.name_company, ct.name_product, ct.weight_product, ct.date_product);
        }
    }
    if (!found) {
        printf(" \n ------------------------------------------Record not found!------------------------------------------\n");
        printf("\nPress any key to go to main menu....");
        getch();
        list_menu();
    } else {
        printf(" \n ------------------------------------------Record deleted---------------------------------------------\n");
    }
    I:
    fclose(fp);
    fclose(fn);
    remove("D:\\Project-111\\text\\filecs.txt");
    rename("D:\\Project-111\\text\\file_edit.txt", "D:\\Project-111\\text\\filecs.txt");

    printf("\nPress any key to go to main menu....");
    getch();
    list_menu();
} //end function del_product

void bills(){
    FILE *fp,*fn;
    int discount = 0;
    char c;
    ct.price_product = 1500;

    fn = fopen("D:\\Project-111\\text\\file_bills.txt", "w"); //file bills
    fp = fopen("D:\\Project-111\\text\\filecs.txt", "r");
    if(fp==NULL){
        printf(" \n ------------------------------------------Record not found!------------------------------------------\n");   
        list_menu();
    }else{
        while(fscanf(fp, " %d %s %s %f %d\n", &ct.id_product, ct.name_company, ct.name_product, &ct.weight_product, &ct.date_product) != EOF){
        if(ct.weight_product >= 80){ //มากกว่า 80 กิโลกรัม
            ct.price_product += (ct.date_product * 50); //วันละ 50 
        }else if (((ct.weight_product > 80)&&(ct.weight_product <= 1000)) && ((ct.date_product > 30)&&(ct.date_product <= 75))){
            discount = ct.price_product * 0.15;//15%
            ct.price_product += (ct.date_product * 50)-discount ;
        }else if ((ct.weight_product >= 1000)&&(ct.weight_product <= 2000) && (ct.date_product > 75)){
            discount = ct.price_product * 0.45;//45%
            ct.price_product += (ct.date_product * 50)-discount;
        }
        fprintf(fn,"%d %s %s %.2f %d %d\n", ct.id_product, ct.name_company, ct.name_product, ct.weight_product, ct.date_product, ct.price_product);
        }
    }
    fclose(fp);
    fclose(fn);
    read_info();
}//end func bills 

void read_info(){
    FILE *fp;
    int choice, found = 0, i = 0, j = 0;
    char c,target[20],line[20];//line จำนวนบรรทัด
    struct customer ct[MAX_CUSTOMERS];
    fp = fopen("D:\\Project-111\\text\\file_bills.txt", "r");
    if (fp == NULL){
        printf(" -------------------Record not found!-----------------------");
        printf("\n\nPress any key to go to main menu....");
        getch();
        list_menu();
    }else{
        I:
        system("cls");
        fflush(stdin);
        printf(" -------------------------------------------------------------------------------------------------------\n");
        printf("\t\t\t\tPlease select your choice \n\n");
        printf("\t\t\t\t< 1 > Show All\t\t\t\t\t\t\t\t\n");
        printf("\t\t\t\t< 2 > Show Company\t\t\t\t\t\t\t\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\n");
        printf("\n\t\t\t   Please select your choice [1/2]: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1://All
            system("cls");
            printf(" -------------------------------------------------------------------------------------------------------\n");
            printf("  ID\t    Company\t     Product Detail\tWeight(kg.)\tAmount of rental\tPricr(Baht)\n");
            printf(" -------------------------------------------------------------------------------------------------------\n");
            //printf("%4d %14s %23s %14.2f %15d %23d",12,"AFTCN","asdasdasd",23.98,23,67489); Pattern for printf 
            while (fscanf(fp,"%d %s %s %f %d %d\n", &ct[i].id_product, ct[i].name_company, ct[i].name_product, &ct[i].weight_product, &ct[i].date_product, &ct[i].price_product) != EOF){
                printf("%4d %14s %23s %14.2f %15d %23d\n", ct[i].id_product, ct[i].name_company, ct[i].name_product, ct[i].weight_product, ct[i].date_product, ct[i].price_product);
                i++;
            }
            printf(" -------------------------------------------------------------------------------------------------------\n"); // edit here
            printf("\n\nPress any key to go to main menu....");
            getch();
            list_menu();
            break;
        case 2://by company
            system("cls");
            printf(" -------------------------------------------------------------------------------------------------------\n");
            printf("\t\t\tEnter Company name: ");
            fflush(stdin);
            gets(target);
            target[0] = toupper(target[0]);
            i = 0;
            while (fscanf(fp,"%d %s %s %f %d %d\n", &ct[i].id_product, ct[i].name_company, ct[i].name_product, &ct[i].weight_product, &ct[i].date_product, &ct[i].price_product) != EOF){
                if (strcmp(target, ct[i].name_company) == 0){ //เจอข้อมูลในไฟล์
                    found = 1;
                    break;
                }
                i++;
            }
            if (found){
                system("cls");
                printf(" -------------------------------------------------------------------------------------------------------\n");
                printf("  ID\t    Company\t     Product Detail\tWeight(kg.)\tAmount of rental\tPricr(Baht)\n");
                printf(" -------------------------------------------------------------------------------------------------------\n");
                for(j = 0; j <= i; j++){
                    printf("%4d %14s %23s %14.2f %15d %23d\n", ct[j].id_product, ct[j].name_company, ct[j].name_product, ct[j].weight_product, ct[j].date_product, ct[j].price_product);
                }
                printf(" -------------------------------------------------------------------------------------------------------\n");
            }else{
                printf("\n-------------> Record not found,Go back to main menu....");
                getch();
                list_menu();
            }
            break;
        default:
            printf("\n-------------> Invalid Choice! System Exit,Please select again....");
            getch();
            goto I;
            break;
        }
    }
    fclose(fp);
}

void edit_info(){
    int valid,ID,index,check;
    char target[20],c;
    FILE *fp, *fn;
    fp = fopen("D:\\Project-111\\text\\filecs.txt", "r");

    printf(" -------------------------------------------------------------------------------------------------------\n");
    printf("\t      ======================== Stock Management System ========================   \t\t\n");
    if(fp == NULL){
        printf(" \n ------------------------------------------Record not found!------------------------------------------\n"); 
        list_menu();
    }else{
        fn = fopen("D:\\Project-111\\text\\file_edit_detail.txt", "a");
        system("cls");
        printf("\n ---> Enter Product Code for edit : ");
        scanf("%d",&ID);
        while (fscanf(fp, "%d %s %s %f %d\n", &ct.id_product, ct.name_company, ct.name_product, &ct.weight_product, &ct.date_product) != EOF)
        {
            if (ID == ct.id_product){
                check = 1;
                printf(" \n ------------------------------------------Record found!----------------------------------------------\n"); 
                printf("\n- Product ID\t\t: %d",ct.id_product);
                printf("\n- Product Company\t: %s",ct.name_company);
                printf("\n- Product Name\t\t: %s",ct.name_product);
				printf("\n- Price\t\t\t: %.2f",ct.weight_product);
				printf("\n- Product Code\t\t: %d",ct.date_product);
                printf("\n --------------------------------------------------------------- \n");
                printf("\n\n\t******** New Record ********");
            do { // company
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
                    printf("\n\t -------------> Name contains invalid characters. Please enter again.");
                    getch();
                }
            } while (!valid);

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
                    printf("\n\t -------------> Name contains invalid characters. Please enter again.");
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
                }valid = 1;
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
                    printf("\n\t -------------> Name contains invalid characters. Please enter again.");
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
                    printf("\n\t -------------> Name contains invalid characters. Please enter again.");
                    getch(); 
                }
            } while (!valid);
                printf("Press 'Y' to edit the existing record or any key to cancel...");
                scanf("%c",&c);
                if(c == 'y' || c == 'Y'){
                    fprintf(fn,"%d %s %s %.2f %d\n", ct.id_product, ct.name_company, ct.name_product, ct.weight_product, ct.date_product);
                    printf("\n\n\t\tYOUR RECORD IS SUCCESSFULLY EDITED!!!");
                }
            }else{//end add
                fprintf(fn,"%d %s %s %.2f %d\n", ct.id_product, ct.name_company, ct.name_product, ct.weight_product, ct.date_product);
            }
        }
        if (!check){
            printf("\n\nTHIS PRODUCT DOESN'T EXIST!!!!");
        }
        fclose(fp);
        fclose(fn);
        remove("D:\\Project-111\\text\\filecs.txt");
        rename("D:\\Project-111\\text\\file_edit_detail.txt","D:\\Project-111\\text\\filecs.txt");
        getch();
    }list_menu();
}//end func edit_info 
