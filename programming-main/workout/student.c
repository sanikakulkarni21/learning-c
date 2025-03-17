#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include<stdlib.h>

struct Student {
    int id;
    char name[20];
    int age;
};
void menu() {
    printf("\nWelcome to Transflower\n");
    printf("1. Enter new data\n");
    printf("2. Display previous data\n");
    printf("3. Exit\n");
}
void displayStudent(struct Student *s) {
    if (s->id == 0) {  
        printf("\nNo student data available. Please enter student details first.\n");
        return;
    }
    printf("\n****** Student Information ******\n");
    printf("ID: %d\n", s->id);
    printf("Name: %s\n", s->name);
    printf("Age: %d\n", s->age);
}
void acceptStudent(struct Student *s) {
    printf("\nEnter Student ID: ");
    scanf("%d", &s->id);

    printf("Enter Student Name: ");
    scanf("%s", s->name); 

    printf("Enter Age: ");
    scanf("%d", &s->age);

    printf("\nThank you for providing student information.\n");
}
void WriteTofile(const char *pFilename , struct Student *std){
    FILE*pFile=fopen(pFilename,"w");
    if (pFile==NULL)
    {
        printf("unable to open this file \n");
        return ;
    }
    fprintf(pFile,"enter student ID\n",std->id);
    fprintf(pFile,"enter student name\n",std->name);
    fprintf(pFile,"enter student age\n",std->age);
    fclose(pFile);
}
void ReadTofile (const char *pFilename, struct Student *std){
    FILE *pFile = fopen(pFilename, "r");
    if (pFile==NULL)
    {
        printf("unable to open this file\n");
        return;
    }
    char buffer[100];
    
    while(fgets(buffer,sizeof(buffer),pFile))
    {
        printf("%s", buffer);

    }
        fclose(pFile);
    
}
int acceptOption() {
    int option;
    printf("\nEnter your option: ");
    scanf("%d", &option);
    return option;
}


int main() {
    struct Student *ptrUser ;
    const char *pfilename="student.info";
    bool status = true;
    int value;
    ptrUser = (struct Student*)malloc(sizeof(struct Student));
    if (ptrUser==NULL){
        printf(" allocation failed\n");
    }
    else{
        printf("memory allocation is succesfully done\n");
    }

    while (status) {
        menu();
        value = acceptOption();

        switch (value) {
            case 1:
                acceptStudent(ptrUser);
                WriteTofile(pfilename, ptrUser);
                break;
            case 2:
                displayStudent(ptrUser);
                ReadTofile(pfilename, ptrUser);
                break;
            case 3:
                printf("Exit.\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }
    free(ptrUser);
    return 0;
}