#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Define structure
struct  Product{
    int id;
    char name[100];
    float price;
    int quantity;
};

 void writeToFile(const char * pFileName ){
    FILE *pFile=NULL;
    pFile=fopen(pFileName, "wb");
    if(pFile == NULL){
       printf(" Error in opening  File for Writing purpose") ;		
    }
    
    struct Product product;
    char choice; 
    do {
          printf("Enter product Details: \n");
          
          printf("\n product ID :");
          scanf("%d", &product.id);
          
          printf("\n product Name :");
          scanf("%s", &product.name);
          
          printf("\n product price :");
          scanf("%f", &product.price);

          printf("\n product quantity :");
          scanf("%d", &product.quantity);
   
         fwrite(&product, sizeof(struct Product), 1, pFile);
         printf("\n  Do you want to continue , press y for yes or n for no");
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

    
struct Product product;
printf("\n product List");

while(fread(&product, sizeof(struct Product),1, pFile) ==1){	
     printf("\n%d\t%s\t%f\t%d\n", product.id, product.name, product.price,product.quantity);	
}  
 fclose(pFile);
}

int main(int argc, char** argv) {
char pFileName[30]="tflproduct.dat";
writeToFile(pFileName);
readFromFile(pFileName);
return 0;
}