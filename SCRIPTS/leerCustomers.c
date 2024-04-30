#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    unsigned char DD;
    unsigned char MM;
    unsigned short int AAAA;
}fecha;

typedef struct {
    unsigned int CustomerKey;
    char gender[7];
    char name[40];
    char city[40];
    char stateCode[40]; 
    char state[20]; 
    unsigned int zipCode;
    char country[20];      
    char continent[20];
    fecha birthDay;
} Customer;

int main(){
    FILE *archivo= fopen("D:\\Users\\PC\\Desktop\\PARCIAL3\\DATA\\CustomersData.txt", "rb");
    Customer persona1;
    fread(&persona1,sizeof(Customer),1,archivo);
    printf("%s", persona1.country);

}