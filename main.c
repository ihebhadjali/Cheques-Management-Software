#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"login.h"
#include"menu.c"
int main(){
    char user[20]="",password[20]="";
    printf("\t#################################################\n\t# Welcome to CMS ( Cheques Management Software ) #\n\t#################################################\nCMG is basically a management software which facilitates the management of cheques.\n\n");
    if(login(user,password)==1)
        menu();
    else
        printf("Error! Program Stopped.");
    printf("Thanks for choosing our CMS program.");
    return 0;
    system("pause");
}