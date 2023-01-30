#include<stdio.h>
#include<stdlib.h>
struct person{
	char name[30];
	char gender;
	int age;
	unsigned long long aadhar;
	unsigned long long mob;
	unsigned long regn;
	struct address{
		char vill[20];
		char post[20];
		char ps[20];
		char dist[20];
		char state[20];
		double pin;
	}add;
};
FILE *fptr,*ptr;
unsigned long long n;
int flag=0,count=0;
char ch;
struct person pr;
unsigned long k=2302000;
void newregistration(){
	fptr=fopen("registered.txt","a");
	ptr=fopen("vaccine.txt","w");
	if(feof(ptr)==0){
		pr.regn=k+1;
		fprintf(ptr,"%llu",pr.regn);	
	}
	else{
		fscanf(ptr,"%llu",&k);
		pr.regn=k+1;
		fprintf(ptr,"%llu",pr.regn);
	}
	fclose(ptr);
	system("cls");
	printf("\n\t\t\t\t********* Registration **********\n");
	printf("\t\t\t\tEnter Name: ");
	fflush(stdin);
	gets(pr.name);
	fflush(stdin);
	printf("\t\t\t\tGender(m/f): ");
	scanf("%c",&pr.gender);
	printf("\t\t\t\tAge: ");
	scanf("%d",&pr.age);
	printf("\t\t\t\tAadhar No.: ");
	scanf("%llu",&pr.aadhar);
	printf("\t\t\t\tMobile No.: ");
	scanf("%llu",&pr.mob);
	printf("\n\t\t\t\t**** Address ****\n");
	printf("\t\t\t\tVillage/Town: ");
	fflush(stdin);
	gets(pr.add.vill);
	printf("\t\t\t\tPost: ");
	fflush(stdin);
	gets(pr.add.post);
	printf("\t\t\t\tPolice Station: ");
	fflush(stdin);
	gets(pr.add.ps);
	printf("\t\t\t\tDistrict.: ");
	fflush(stdin);
	gets(pr.add.dist);
	printf("\t\t\t\tState: ");
	fflush(stdin);
	gets(pr.add.state);
	fflush(stdin);
	printf("\t\t\t\tPIN CODE: ");
	scanf("%ld",&pr.add.pin);
	printf("\t\t\t\tYour registration is successfully...");
	printf("\tYour registration No: %ld",pr.regn);
	fwrite(&pr,sizeof(pr),1,fptr);
	fclose(fptr);
}
void display(struct person pr){
	printf("\n\t\t\t\t********* DETAILS *********\n");
	printf("\n\t\t\t\tRegistration No: %ld\n",pr.regn);fflush(stdin);
	printf("\t\t\t\tName: %s\n",pr.name);fflush(stdin);
	printf("\t\t\t\tGender(m/f): %c\n",pr.gender);fflush(stdin);
	printf("\t\t\t\tAge: %d\n",pr.age);fflush(stdin);
	printf("\t\t\t\tAadhar No.: %llu\n",pr.aadhar);fflush(stdin);
	printf("\t\t\t\tMobile No.: %llu\n",pr.mob);fflush(stdin);
	printf("\t\t\t\t**** Address ****\n");
	printf("\t\t\t\tVillage/Town: %s\n",pr.add.vill);fflush(stdin);
	printf("\t\t\t\tPost: %s\n",pr.add.post);fflush(stdin);
	printf("\t\t\t\tPolice Station: %s\n",pr.add.ps);fflush(stdin);
	printf("\t\t\t\tDistrict.: %s\n",pr.add.dist);fflush(stdin);
	printf("\t\t\t\tState: %s\n",pr.add.state);fflush(stdin);
	printf("\t\t\t\tPIN CODE: %ld\n\n",pr.add.pin);
}
int displayAll(){
	fptr=fopen("registered.txt","r");
	if(fptr==NULL){
		printf("\t\t\t\tFile missing...\n");
		return 0;
	}
	system("cls");
	printf("\t\t\t\t*********** ALL RECORDS ************");
	fread(&pr,1,sizeof(pr),fptr);
	while(!feof(fptr)){
		display(pr);
		fread(&pr,1,sizeof(pr),fptr);
	}
	fclose(fptr);
	return 0;
}
int searchByReg(){
	system("cls");
	fptr=fopen("registered.txt","r");
	if(fptr==NULL){
		printf("\t\t\t\tFile missing...\n");
		return 0;
	}
	printf("\n\t\t\t\t********* SEARCH Records *********\n");
	printf("\t\t\t\tEnter Registration NO: ");
	scanf("%llu",&n);
	fread(&pr,1,sizeof(pr),fptr);
	while(!feof(fptr)){
		if(n==pr.regn){
			display(pr);
			flag=1;
		}
		fread(&pr,1,sizeof(pr),fptr);
	}
	fclose(fptr);
	if (flag==0){
		printf("\n\t\t\t\tRecord NOT found...\n");
		return 0;
	}
	return 0;
}

int searchByAadhar(){
	system("cls");
	fptr=fopen("registered.txt","r");
	if(fptr==NULL){
		printf("\t\t\t\tFile missing...\n");
		return 0;
	}
	printf("\n\t\t\t\t********* SEARCH Records *********\n");
	printf("\t\t\t\tEnter Aadhar NO: ");
	scanf("%llu",&n);
	fread(&pr,1,sizeof(pr),fptr);
	while(!feof(fptr)){
		if(n==pr.aadhar){
			display(pr);
			flag=1;
		}
		fread(&pr,1,sizeof(pr),fptr);
	}
	fclose(fptr);
	if (flag==0){
		printf("\n\t\t\t\tRecord NOT found...\n");
		return 0;
	}
	return 0;
}
int search(){
	int n;
	fptr=fopen("registered.txt","r");
	if(fptr==NULL){
		printf("\t\t\t\tFile doesn't exists...\n");
		return 0;
	}
	fread(&pr,1,sizeof(pr),fptr);
	do{
		system("cls");
		printf("\n\t\t\t\t********* SEARCH *********\n");
		printf("\t\t\t\t1. Search by Registration No\n");
		printf("\t\t\t\t2. Search by Aadhar No\n");
		printf("\t\t\t\t3. All Records \n");
		printf("\n\t\t\tEnter your choice: ");
		scanf("%d",&n);
		switch(n){
			case 1:
				searchByReg();
				break;
			case 2:
				searchByAadhar();
				break;
			case 3:
				displayAll();
				break;
			default:
				printf("\n\t\t\t\t\t\t\t\tINVALID INPUT...");
		}
		printf("\n\t\t\t\t\t\t\t\tContinue searching..(y/n):");
		fflush(stdin);
		scanf("%c",&ch);
	}while(ch=='y'||ch=='Y');
	return 0;
}
void vaccine(){
	ptr=fopen("vaccine.txt","r");
	fscanf(ptr,"%llu",&k);
	system("cls");
	printf("\n\t\t\t\t****** VACCINE Details ******\n");
	printf("\n\t\t\t\tREGISTERED person = %llu",k-2302000);
}
int main(){
	int n;
	do{
		system("cls");
		printf("\n\t\t\t\t****** VACCINE REGISTRATION ******\n");
		printf("\n\t\t\t\t1. New Registration\n");
		printf("\n\t\t\t\t2. Search\n");
		printf("\n\t\t\t\t3. Vaccine info \n");
		printf("\n\t\t\t\t0. Exit\n");
		printf("\n\t\t\tEnter your choice: ");
		scanf("%d",&n);
		switch(n){
			case 1:
				newregistration();
				break;
			case 2:
				search();
				break;
			case 3:
				vaccine();
				break;
			case 0:
				printf("\n Thanks for visiting...");
				break;
			default:
				printf("\t\t\t\tINVALID INPUT\n\t\t\t\tPLEASE TRY AGAIN...");
		}
		printf("\n\t\t\t\t\t\t\t\tContinue to Home page(y/n):");
		fflush(stdin);
		scanf("%c",&ch);
	}while(ch=='y'||ch=='Y');
	return 0;
}
