#include <stdio.h>
#include <regex.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
 
void  reg_svc(char str[])
{
    //char* str;
    int i=0,len=0;
   // str=(char*)malloc(100*sizeof(char));
    //gets(str);
    len=strlen(str);
    str[len]='\0';
    printf("\n len=%d",len);
    const char* pattern = "[A-Z_]+:[a-zA-Z ]+,[a-zA-Z ]+,[a-zA-Z ]";
    regex_t re;
	
    if (regcomp(&re, pattern, REG_EXTENDED|REG_NOSUB) != 0) return 0;

    int status = regexec(&re, str, 0, NULL, 0);
    regfree(&re);
	if(len==0)
		printf("\n no input");

	else if (status == 0) {
	       	printf("\n%s matching",str);
     }
	
    else{
		svc_validate_buffer(str);         	
    }
    
}    
void svc_validate_buffer(char cBuffer[100]){
	bool flag1 = false,flag2=false,flag3=false;
	char sName[100],sType[100],sStatus[100],command[100];
	int i=0,j=0;
	printf("cbuffer=%s",cBuffer);
	if(cBuffer[0]!='\n'){

		while(cBuffer[i] != ':'){
			command[i] = cBuffer[i];
			i++;
		}

		command[i]='\0';
		//printf("\n command=%s",command);
		i++;

		while(cBuffer[i] != ',')
			sName[j++] = cBuffer[i++];

		sName[j]='\0';
		i++;
		//printf("\nstype =>%s",cName);
		j=0;

		while(cBuffer[i] != ',')
                        sType[j++] = cBuffer[i++];

                sType[j]='\0';
                i++;
		j=0;


		while(cBuffer[i] != '\0')
			sStatus[j++] = cBuffer[i++];

		sStatus[j]='\0';
		/*printf("\nsname =>%s",sName);
		 printf("\nstype =>%s",sType);
		  printf("\nsstatus =>%s",sStatus);
		  printf("\n length of stype=%d",strlen(sType));
		   printf("\n length of sstatus=%d",strlen(sStatus));
		    printf("\n length of sname=%d",strlen(sName));

		if(strlen(command)!=0){
			command_validation(command);

		}*/


		if(strlen(sName)!=0){
			for(i=0;sName[i]!='\0';i++){
				if(isalpha(sName[i]) || sName[i]==' '){
					continue;
				}
				else{
					flag1=true;
					break;
				}
			}
		}
		else{
			printf("\n no service name");
		}

		if(flag1==true)
			printf("\nservice name invalid");
		 
		 if(strlen(sType)!=1){
                        for(i=0;sType[i]!='\0';i++){
                                if(isalpha(sType[i]) || sType[i]==' '){
                                        continue;
                                }
                                else{
                                        flag2=true;
                                        break;
                                }
                        }
                }
		else{
                        printf("\n no service type");
                }


                if(flag2==true)
                        printf("\nservice type invalid");

		//email_validation(cMailid);
		 if(strlen(sStatus)!=1){
                        for(i=0;sStatus[i]!='\0';i++){
                                if(isalpha(sStatus[i]) || sStatus[i]==' '){
                                        continue;
                                }
                                else{
                                        flag3=true;
                                        break;
                                }
                        }
                }
		else{
                        printf("\n no service status");
                }


                if(flag3==true)
                        printf("\nservice status invalid");

	}
     }


