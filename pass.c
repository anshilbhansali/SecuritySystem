// A security system in which you can add passwords, delete passwords,
// exit the system, and re enter using one of the added passwords.
// Done by Anshil Bhansali
// abhansa2@illinois.edu


#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int x;
char pass1[20], pass2[20],newp[20], check2[20] ; 
int i;

void ADD();
void DELETE();
void EXIT();
 

int main(){

printf("Enter DEFAULT password:  ");
scanf("%s", &pass1);


if(strcmp(pass1, "PASS")==0)
{
	
		printf("\nUsage: \n");
		printf("To add a password, type: ADD <password> \n");
		printf("To delete a password, type: DELETE <password> \n");
		printf("To exit the system, type: EXIT SYST\n");
		printf("\nEnter you command: ");
		scanf("%s %s", &pass1, &pass2);

		//printf("%s %s \n", pass1, pass2);

		if(strcmp(pass1, "ADD")==0) ADD();
			
		else if(strcmp(pass1, "DELETE")==0) DELETE();
		
		else if(strcmp(pass1, "EXIT")==0 && strcmp(pass2, "SYST")==0) EXIT();		
		
		else printf("Use one of the above functions\n");
	
}
else printf("Access Denied\n");

return 0;
}

void ADD()
{


FILE * fp;
fp = fopen("passwords.txt", "a");
fprintf(fp, "%s\n", pass2);
fclose(fp);

printf("\nAdded %s\n", pass2);
printf("\nUsage: \n");
printf("To add a password, type: ADD <password> \n");
printf("To delete a password, type: DELETE <password> \n");
printf("To exit the system, type: EXIT SYST \n");
printf("\nEnter you command: ");
scanf("%s %s", &pass1, &pass2);

if(strcmp(pass1, "ADD")==0) ADD();
			
else if(strcmp(pass1, "DELETE")==0) DELETE();
		
else if(strcmp(pass1, "EXIT")==0 && strcmp(pass2, "SYST")==0) EXIT();		
		
else printf("Use one of the above functions\n");

}



void DELETE() {

FILE * fp;
fp = fopen("passwords.txt", "r+");
i=100;
while(i>0)
{
	fscanf(fp, "%s", check2);

	if(strcmp(pass2,check2) == 0 )
	{
		fseek(fp, -strlen(check2), SEEK_CUR);
		int k;
		k = strlen(check2) ;
		while (k>0)
		{
			fputs(" ", fp);
			k=k-1 ;
		}

	fputs("\n", fp);
	fclose(fp);
	int x=0;

	//reset check2
	for(;x<20;x++)
		check2[x] = 0;


	printf("\nUsage: \n");
	printf("To add a password, type: ADD <password> \n");
	printf("To delete a password, type: DELETE <password> \n");
	printf("To exit the system, type: EXIT SYST \n");
	printf("\nEnter you command: ");

	scanf("%s %s", &pass1, &pass2);

	if(strcmp(pass1, "ADD")==0) ADD();
			
	else if(strcmp(pass1, "DELETE")==0) DELETE();
		
	else if(strcmp(pass1, "EXIT")==0 && strcmp(pass2, "SYST")==0) EXIT();		
		
	else printf("Use one of the above functions\n");

	}

	else i--;

}

printf("\nPassword does not exist\n");
printf("Logging you out of system \n");
EXIT();

}


void EXIT() {


printf("\nEnter password : ");
scanf("%s", &newp);

//printf("\n %s \n", newp);

if(strcmp(newp, "PASS")==0)
{
	printf("\nLogging you in ... \n");

	printf("\nUsage: \n");
	printf("To add a password, type: ADD <password> \n");
	printf("To delete a password, type: DELETE <password> \n");
	printf("To exit the system, type: EXIT SYST\n");
	printf("\nEnter you command: ");
	scanf("%s %s", &pass1, &pass2);
	if(strcmp(pass1, "ADD")==0) ADD();
			
	else if(strcmp(pass1, "DELETE")==0) DELETE();
		
	else if(strcmp(pass1, "EXIT")==0 && strcmp(pass2, "SYST")==0) EXIT();		
		
	else printf("Use one of the above functions\n");
}

else
{
	FILE * fp;
	fp = fopen("passwords.txt", "r");
	i=100;

	while(i>0)
	{

	fscanf(fp, "%s", check2); // bug


	if(strcmp(newp,check2) == 0 )
	{
		printf("\nLogging you in ... \n");

		printf("\nUsage: \n");
		printf("To add a password, type: ADD <password> \n");
		printf("To delete a password, type: DELETE <password> \n");
		printf("To exit the system, type: EXIT SYST\n");
		printf("\nEnter you command: ");
		scanf("%s %s", &pass1, &pass2);
		if(strcmp(pass1, "ADD")==0) ADD();
			
		else if(strcmp(pass1, "DELETE")==0) DELETE();
		
		else if(strcmp(pass1, "EXIT")==0 && strcmp(pass2, "SYST")==0) EXIT();		
		
		else printf("Use one of the above functions\n");

	}

	i--;

	}
	printf("Access Denied\n");

	EXIT();
}

}
