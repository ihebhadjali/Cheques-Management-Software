#include<stdio.h>
#define MAX 256
void chequeslistall();
void addcheque();
void delcheque();
int erasecheques(int);
int testfilevide(FILE*);
void menu(){
    system("cls");
    int order=4,rep=0,com=6;
    while((order<0)||(order>3)){
        printf("# Menu List #\nType on the keyboard:\n\t1 : List of Cheques.\n\t2 : Add a new Cheque.\n\t3 : Delete a Cheque.\n\t0 : Stop the program.\n>");
        scanf("%d",&order);
        if ((rep++)==2){
            printf("Error! Program Stopped.");
            break;
        }
    }
    switch (order){
        case 1:
            chequeslistall();
            break;
        case 2:
            addcheque();
            break;
        case 3:
            delcheque();
            break;
        case 0:
            break;
        default:
            printf("Ops! Invalid Command");
    }
}
void chequeslistall(){
    FILE *input_data = fopen("data.txt","r");
    struct date_struct{
        char day[3];
        char month[3];
        char year[5];
    };
    struct fullname{
        char first[20];
        char last[20];
    };
    int montant,line;
    char bank[20];
    struct date_struct date;
    struct fullname name;
    system("cls");
    if(input_data != NULL){
        if(testfilevide(input_data)==1)
            printf("\tYou don't have any Cheque.");
        else{
            printf("\t\t\t#\tCheques List\t#\n\t-------------------------------------------------------------\n\t    Date     |  Amount  |\tBank\t|  Client Name\n\t-------------------------------------------------------------\n");
            line=0;
            int total=0;
            while (1){
                line++;
                fscanf(input_data,"%s %s %d %s %s %s %s",&name.first,&name.last,&montant,bank,&date.day,&date.month,&date.year);
                printf("    %d\t| %s/%s/%s | %d Dt\t|    %s\t| %s %s\n",line,date.day,date.month,date.year,montant,bank,name.first,name.last);
                total+=montant;
                if(feof(input_data))
                    break;
            }
            printf("\t-------------------------------------------------------------\n\t\tTotal Amount :%d\n\t-------------------------------------------------------------\n",total);
            fclose(input_data);
        }
    }
    int com=4;
    while((com<0)||(com>3)){
        printf("\n1 : Add Cheque (Direct access)\n2 : Delete Cheque (Direct access)\n3 : Menu List\n0 : Stop the program.\n>");
        scanf("%d",&com);
    }
    switch (com){
        case 1:
            addcheque();
            break;
        case 2:
            delcheque();
            break;
        case 3:
            menu();
            break;
        case 0:
            printf("\n");
            break;
        default:
            printf("Ops! Invalid Command");
    }
}
void addcheque(){
    FILE *input_data = fopen("data.txt","a");
    struct date_struct{
        char day[3];
        char month[3];
        char year[5];
    };
    struct fullname{
        char first[20];
        char last[20];
    };
    int montant,com=2;
    char bank[20];
    struct date_struct date;
    struct fullname name;
    if(input_data == NULL)
        exit(1);
    system("cls");
    printf("# Add Cheque #\n\tFirst Name : ");
    scanf("%s",name.first);
    printf("\tLast Name : ");
    scanf("%s",name.last);
    printf("\tDate \"dd mm yyyy\" : ");
    scanf("%s %s %s",date.day,date.month,date.year);
    printf("\tAmount :");
    scanf("%d",&montant);
    printf("\tBank : ");
    scanf("%s",bank);
    fprintf(input_data,"\n%s %s %d %s %s %s %s",name.first,name.last,montant,bank,date.day,date.month,date.year);
    fclose(input_data);
    printf("The check was successfully added.");
    while((com<0)||(com>1)){
        printf("\nDo you want to add another Cheque ?!\n\t1 : Yes\n\t0 : No\n>");
        scanf("%d",&com);
    }
    if(com==1)
        addcheque();
    com=4;
    while((com<0)||(com>3)){
    printf("1 : Cheque List (Direct access)\n2 : Delete Cheque (Direct access)\n3 : Menu List\n0 : Stop the program.\n>");
    scanf("%d",&com);
    }
    switch (com){
        case 1:
            chequeslistall();
            break;
        case 2:
            delcheque();
            break;
        case 3:
            menu();
            break;
        case 0:
            printf("\n");
            break;
        default:
            printf("Ops! Invalid Command");
    }
}
void delcheque(){
    int line,com=2;
    system("cls");
    printf("# Delete Cheque #\n\tCheque Number : ");
    scanf("%d",&line);
    erasecheques(line-1);
    while((com<0)||(com>1)){
        printf("\nDo you want to delete another one ?!\n\t1 : Yes\n\t0 : No\n>");
        scanf("%d",&com);
    }
    if(com==1)
        delcheque();
    com=4;
    while((com<0)||(com>3)){
    printf("1 : Cheque List (Direct access)\n2 : Add Cheque (Direct access)\n3 : Menu List\n0 : Stop the program.\n>");
    scanf("%d",&com);
    }
    switch (com){
        case 1:
            chequeslistall();
            break;
        case 2:
            addcheque();
            break;
        case 3:
            menu();
            break;
        case 0:
            printf("\n");
            break;
        default:
            printf("Ops! Invalid Command");
    }
}
int erasecheques(int linecheque){
    FILE *fptr1, *fptr2;
    fptr1 = fopen("data.txt", "r");
    if (!fptr1) {
        printf(" File not found or unable to open the input file!!\n");
        return 0;
    }
    fptr2 = fopen("temp.txt", "w"); 
    if (!fptr2){
        printf("Unable to open a temporary file to write!!\n");
        fclose(fptr1);
        return 0;
    }
    linecheque++;
    char str[MAX];
    int ctr=0;
    while (!feof(fptr1)){
        strcpy(str, "\0");
        fgets(str, MAX, fptr1);
        if (!feof(fptr1)){
            ctr++;
            if (ctr!=linecheque)
                fprintf(fptr2, "%s", str);
        }
    }
    fclose(fptr1);
    fclose(fptr2);
    remove("data.txt");
    rename("temp.txt","data.txt");
    return 0;
}
int testfilevide(FILE* fichier)
{
    int caracterePremier = 0;
    caracterePremier = fgetc(fichier);
    if(caracterePremier==EOF)
        return 1;
    return 0;
}