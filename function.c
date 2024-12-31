#include <stdio.h>
#include <string.h>
#include "function.h"


void printMenuHome(){
	printf("\n");
	printf("\t   CHOOSE YOUR ROLE\n");
	printf("\t======================\n");
	printf("\t[1] Admin.\n");
	printf("\t[2] Student.\n");
	printf("\t[3] Teacher.\n");
	printf("\t[0] Exit the program.\n");
	printf("\t======================\n");
}
void printMenu(){
	printf("\n");
	printf("\t\tMENU\n");
	printf("\t======================\n");
	printf("\t[1] Student management.\n");
	printf("\t[0] Exit the menu.\n");
	printf("\t======================\n");
}
void inputMenu(){
	int choice;
	do{
		printMenu();
		printf("\tEnter the choice: ");
		scanf("%d", &choice);
		printf("\n");
		fflush(stdin);
		switch(choice){
			case 1:
				inputStudentMenu();
				break;
			case 0:
				printExit();
				break;
			default:
				printf("\tsai cu phap!\n");
		}
	}while(choice != 0);
}
void inputStudentMenu(){
	struct Student user[100] = {1,"Tran Quang Duy","kow43@gmail.com","0913121212"};
	int n = 1;
	int choice;
	do{
		printStudentMenu();
		printf("\tEnter the choice: ");
		scanf("%d", &choice);
		printf("\n");
		fflush(stdin);
		switch(choice){
			case 1:
				addStudent(user,&n);
				break;
			case 2:
				printStudent(user,n);
				break;
			case 4:
				editStudent(user,n);
				break;
			case 0:
				printExit();
				break;
			default:
				printf("\tsai cu phap!\n");
		}
	}while(choice != 0);
}
void printStudentMenu(){
	printf("\n");
	printf("\t   STUDENT MENU\n");
	printf("\t======================\n");
	printf("\t[1] Add a new student.\n");
	printf("\t[2] Show all student.\n");
	printf("\t[3] Search a student.\n");
	printf("\t[4] Edit a student.\n");
	printf("\t[5] Delete a student.\n");
	printf("\t[0] Exit the menu student.\n");
	printf("\t======================\n");
}
void printExit(){
	printf("\t====Thank You======\n");
	printf("\t====See You Soon===");
	printf("\n");
}
void printStudent(struct Student user[], int n){
	int i;
	printf("\t\t\t\t\t\t\t\t\t**All student**\n\n");
	printf("\t|=================|=====================================|=====================================|===========================|=================|\n");
    printf("\t| %-15s | %-35s | %-35s | %-25s | %-15s |\n", "ID", "Name", "Email", "Phone", "NO.Course");
    printf("\t|=================|=====================================|=====================================|===========================|=================|\n");
    for (i = 0; i < n; i++) {
        printf("\t| %-15d | %-35s | %-35s | %-25s | %-15d |\n",
		user[i].id,
		user[i].name,
		user[i].mail,
		user[i].phone,
		user[i].no_course);
        printf("\t|-----------------|-------------------------------------|-------------------------------------|---------------------------|-----------------|\n");
    }

}
void addStudent(struct Student user[], int *n){
	int add = *n;
	int i, choice;
	printf("\t\t**Add a new student**\n");
	addStudent:
	printf("\tEnter the ID: ");
	int check = 0;
	scanf("%d", &user[add].id);
	fflush(stdin);
	for(i = 0; i < *n; i++){
		if(user[add].id == user[i].id||user[add].id < 1){
			check = 1;
		}
	}
	if(check != 1){
		printf("\tEnter the Name: ");
		fgets(user[add].name, sizeof(user[add].name), stdin);
		user[add].name[strcspn(user[add].name,"\n")] = '\0';
		addMail:
		printf("\tEnter the Email: ");
		fgets(user[add].mail, sizeof(user[add].mail), stdin);
		user[add].mail[strcspn(user[add].mail,"\n")] = '\0';
		int same = 0;
		for(i = 0; i < *n; i++){
			if(strcmp(user[add].mail, user[i].mail) == 0){
				same = 1;
			}
		}
		if(same == 1){
			printf("\tError: This Email is already exists.\n");
			goto addMail;
		}
		addPhone:
		printf("\tEnter the Phone: ");
		same = 0;
		fgets(user[add].phone, sizeof(user[add].phone), stdin);
		user[add].phone[strcspn(user[add].phone,"\n")] = '\0';
		for(i = 0; i < *n; i++){
			if(strcmp(user[add].phone, user[i].phone) == 0){
				same = 1;
			}
		}
		if(same == 1){
			printf("\tError: This Phone is already exists.\n");
			goto addPhone;
		}
		(*n)++;
		printf("\tAdded successfully!!\n");
		end:
		printf("\tGo back(b)? or Exit(0)?:");
		scanf("%s", &choice);
		fflush(stdin);
		if(strcmp(choice,"b")==0){
			printf("\tmenu");
		}else if(strcmp(choice,"0")==0){
			printExit();
			exit(0);
		}else{
			goto end;
		}	
	}else{
		printf("\tError: This ID is already exists.\n");
		goto addStudent;
	}
}
void editStudent(struct Student user[], int n){
	int i, edit, choice[1];
	editStudent:
	printf("\t\t**Edit student**\n");
	int searchId;
	printf("\tEnter the ID student: ");
	scanf("%d", &searchId);
	int check = 0;
	fflush(stdin);
	printf("\tStudent Infomations\n");
	printf("\t----------------------\n");
	for(i = 0; i < n; i++){
		if(searchId == user[i].id){
			check = 1;
			edit = i;
			printf("\tID: %d\n", user[i].id);
			printf("\tName: %s\n", user[i].name);
			printf("\tEmail: %s\n", user[i].mail);
			printf("\tPhone: %s\n", user[i].phone);
		}
	}
	if(check == 1){
		printf("\t\t**Update The New Student**\n");
		char temp[100];
		printf("\tEnter the new name(0 for skip): ");
		strcpy(temp, user[edit].name);
		fgets(user[edit].name, sizeof(user[edit].name), stdin);
		user[edit].name[strcspn(user[edit].name,"\n")] = '\0';
		if(strcmp(user[edit].name, "0") == 0){
			strcpy(user[edit].name, temp);
		}
		printf("\tEnter the new email(0 for skip): ");
		strcpy(temp, user[edit].mail);
		fgets(user[edit].mail, sizeof(user[edit].mail), stdin);
		user[edit].mail[strcspn(user[edit].mail,"\n")] = '\0';
		if(strcmp(user[edit].mail, "0") == 0){
			strcpy(user[edit].mail, temp);
		}
		printf("\tEnter the new phone(0 for skip): ");
		strcpy(temp, user[edit].phone);
		fgets(user[edit].phone, sizeof(user[edit].phone), stdin);
		user[edit].phone[strcspn(user[edit].phone,"\n")] = '\0';
		if(strcmp(user[edit].phone, "0") == 0){
			strcpy(user[edit].phone, temp);
		}
		printf("\tUpdate successfully!!\n\n");
		end:
		printf("\tGo back(b)? or Exit(0)?:");
		scanf("%s", &choice);
		fflush(stdin);
		if(strcmp(choice,"b")==0){
			printf("\tmenu");
		}else if(strcmp(choice,"0")==0){
			printExit();
			exit(0);
		}else{
			goto end;
		}
	}else{
		printf("\tError: This ID is already exists.\n\n");
		goto editStudent;
	}
}
void deleteStudent(struct Student user[], int *n){
	int add = *n;
	int i, searchId, deletev;
	printf("\t\t**Delete a new student**\n");
	deleteStudent:
	printf("\tEnter the ID: ");
	int check = 0;
	scanf("%d", &searchId);
	fflush(stdin);
	printf("\tStudent Infomations\n");
	printf("\t----------------------\n");
	for(i = 0; i < n; i++){
		if(searchId == user[i].id){
			check = 1;
			deletev = i;
			printf("\tID: %d\n", user[i].id);
			printf("\tName: %s\n", user[i].name);
			printf("\tEmail: %s\n", user[i].mail);
			printf("\tPhone: %s\n", user[i].phone);
		}
	}
	if(check != 1){
		printf("Delete(Y/N)");
		(*n)++;
		printf("\tAdded successfully!!\n");	
	}else{
		printf("\tError: This ID is already exists.\n");
		goto deleteStudent;
	}
}
