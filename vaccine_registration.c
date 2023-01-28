#include<stdio.h>
#include<stdlib.h>
struct person{
	char name[30];
	char gender;
	int age;
	double aadhar;
	double mob;
	double regn;
	struct address{
		char vill[20];
		char post[20];
		char ps[20];
		char dist[20];
		char state[20];
		double pin;
	}add;
};
static struct person pr[100];
static int i,j,k=20598;
void newregistration(){
	FILE *fptr;
	char ch;
	fptr=fopen("registered.txt","a");
	if(fptr==NULL){
		printf("File doesn't exists...\n");
		printf("Do you want to create a file(y/n):");
		scanf("%c",&ch);
		if(ch=='y'||ch=='Y')
		fptr=fopen("registered.txt","w");
		else
		return 0;
		if(fptr!=NULL)
		printf("File Created");
	}
	printf("\t\t\t\tName: ");
	fflush(stdin);
	scanf("%[^\n]s",&pr[i].name);
	fflush(stdin);
	printf("\t\t\t\tGender(m/f): ");
	scanf("%c",&pr[i].gender);
	printf("\t\t\t\tAge: ");
	scanf("%d",&pr[i].age);
	printf("\t\t\t\tAadhar No.: ");
	scanf("%lf",&pr[i].aadhar);
	printf("\t\t\t\tMobile No.: ");
	scanf("%lf",&pr[i].mob);
	printf("\n\t\t\t\t**** Address ****\n");
	printf("\t\t\t\tVillage/Town: ");
	fflush(stdin);
	scanf("%[^\n]s",&pr[i].add.vill);
	printf("\t\t\t\tPost: ");
	fflush(stdin);
	scanf("%[^\n]s",&pr[i].add.post);
	printf("\t\t\t\tPolice Station: ");
	fflush(stdin);
	scanf("%[^\n]s",&pr[i].add.ps);
	printf("\t\t\t\tDistrict.: ");
	fflush(stdin);
	scanf("%[^\n]s",&pr[i].add.dist);
	printf("\t\t\t\tState: ");
	fflush(stdin);
	scanf("%[^\n]s",&pr[i].add.state);
	fflush(stdin);
	printf("\t\t\t\tPIN CODE: ");
	scanf("%lf",&pr[i].add.pin);
	pr[i].regn=k;
	printf("\t\t\t\tYour registration is successfully...");
	printf("\tYour registration No: %ld",k);
	i++;
	j++;
	k++;
}
void search(){
	
	
}
void vaccine(){
	
}
int main(){
	int n;
	char ch;
	do{
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
				printf("INVALID INPUT\nPLEASE TRY AGAIN...");
		}
		printf("\nWish you continue (y/n):");
		fflush(stdin);
		scanf("%c",&ch);
	}while(ch=='y'||ch=='Y');
	return 0;
}