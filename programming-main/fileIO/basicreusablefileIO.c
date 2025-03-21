#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Define structure
struct  Student{
    int id;
    char name[100];
    int age;
};

 void writeToFile(const char * pFileName ){
    FILE *pFile=NULL;
    pFile=fopen(pFileName, "wb");
    if(pFile == NULL){
       printf(" Error in opening  File for Writing purpose") ;	
    	
    }
    
    struct Student student;
    char choice; 
    do {
          printf("Enter student Details: \n");
          
          printf("\n Student ID :");
          scanf("%d", &student.id);
          
          printf("\n Student Name :");
          scanf("%s", &student.name);

          printf("\n Student Age :");
          scanf("%d", &student.age);
   
         fwrite(&student, sizeof(struct Student), 1, pFile);
         printf("\n  Do you want to continue , press y for yes or n for no: ");
         getchar();
         choice=getchar();
    }
    while( choice =='y' || choice =='Y');
    fclose(pFile);
}


void readFromFile(const char * pFileName){
    FILE *pFile=fopen(pFileName, "rb");
    if(pFile == NULL){
       printf(" Error in opening  File for Reading purpose") ;	
       return;	
    }
    
   struct Student student;
   printf("\n Transflower Students List");
   
   while( fread(&student, sizeof(struct Student),1, pFile) ==1){	
        fprintf("%d\t%s\t%d\n", student.id, student.name, student.age);	
   }  
    fclose(pFile);
}


int main(int argc, char** argv) {
  char pFileName[30]="tflstudent.dat";
  writeToFile(pFileName);
   readFromFile(pFileName);
   return 0;
}