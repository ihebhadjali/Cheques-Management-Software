#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int verif(char*,char*);
int login(char user[],char pass[]){
    while((verif(user,"iheb")==0)||(verif(pass,"iheb123")==0)){
        printf("#\tLogin Panel\t#\nUsername :");
        scanf("%s",user);
        printf("Password :");
        scanf("%s",pass);
        if(verif(user,"iheb")==0)
            printf("Ops -_-\"! Wrong Username.\n");
        if((verif(user,"iheb")==1)&&(verif(pass,"iheb123")==0))
            printf("Ops -_-\"! Password Wrong.\n");
    }
    if((verif(user,"iheb")==0)||(verif(pass,"iheb123")==0)){
        printf("Login Error!");
        return 0;
    }
    else
        return 1;
}
int verif(char ch[],char chv[]){
    if(strlen(ch)!=strlen(chv))
        return 0;
    else{
        char *p,*pv;int v=1;
        for(p=ch,pv=chv;*p!='\0';p++,pv++){
            if(*p!=*pv)v=0;
        }
        if(v==0)
            return 0;
        else
            return 1;
    }
}
