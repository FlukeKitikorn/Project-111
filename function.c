#include <stdio.h>
#include <stdlib.h>
#include <conio.h> //gotoxy
#include <string.h>
#include <windows.h>
#include <time.h>

void login(void){
    int count = 0, i = 0;
    char user_name[10],c = ' ';
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
            c = user_pass[i];
            if (c == 13){break;} //limit size of user
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

void add(){
    /*
    FILE *fp;
    int valid,index;
    char c;

    do{
    system("cls");
    printf("|\t      ======================== Stock Management System ========================   \t\t|\n");
    int idcompany; //comparing ID if file != NULL
    fp = fopen("file.txt",w+); //change to a+
    fprintf(fp,"%s","testfile");
    if((fp = fopen(file.txt,w+)!= NULL)){

    }




    }while ();
   
    */
}
int main(){
    /*mode  w = only write end in program
            a = append to old file
            r = only Read
            w+,a+,r+
   */ 
   FILE *fp;
   fp = fopen("textf.txt",w); // append
   fprintf(fp,"Test : 1\n");
   fprintf(fp,"Test2 :\n");
   fprintf(fp,"%s %f\n","Test3 :",2);
   fclose(fp);
   /* 
   int i;
   for(i = 0 ; i < 0 ; i++){
        printf("%d",&i);
   }
   */
}