#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <regex.h>
#include<ctype.h>
#include<stdbool.h>
#include "validation.h"
void main()
{
	int opt=0,len=0,i=0;
	char *cBuffer,*command;
	cBuffer=(char*)malloc(150*sizeof(char));
	command=(char*)malloc(150*sizeof(char));
	printf("\n enter buffer");
	gets(cBuffer);
	len=strlen(cBuffer);
	if(len==0)
		printf("\n no input");
	else{
		while(cBuffer[i] != ':'){
			command[i] = cBuffer[i];
			i++;
		}

		command[i]='\0';
		printf("\n command=%s",command);
		if(strcmp(command,"REG_USR")==0){
			
			reg_usr(cBuffer);
		}
		else if(strcmp(command,"REG_SVC")==0){
			printf("\n reg_svc matched");
			reg_svc(cBuffer);
		}
		else{
			printf("\n no proper input");
		}
	}
}
