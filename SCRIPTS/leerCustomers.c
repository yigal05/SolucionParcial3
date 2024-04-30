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

void imprimir(Customer registros[], int tamano) {
    for (int i = 0; i < tamano; i++) {
        printf("\n\nRegistro %d:\n", i+1);
        printf("CustomerKey: %u\n", registros[i].CustomerKey);
        printf("Gender: %s\n", registros[i].gender);
        printf("Name: %s\n", registros[i].name);
        printf("City: %s\n", registros[i].city);
        printf("State Code: %s\n", registros[i].stateCode);
        printf("State: %s\n", registros[i].state);
        printf("Zip Code: %u\n", registros[i].zipCode);
        printf("Country: %s\n", registros[i].country);
        printf("Continent: %s\n", registros[i].continent);
        printf("Birthday %hhu/%hhu/%hu\n", registros[i].birthDay.DD, registros[i].birthDay.MM, registros[i].birthDay.AAAA);
        printf("\n");
    }
}

int main(){
    FILE *tina = fopen("D:\\Users\\PC\\Desktop\\PARCIAL3\\DATA\\CustomersData.txt", "rb");
    fseek(tina,0,SEEK_END);
    int tamano= ftell(tina)/sizeof(Customer);
    fseek(tina,0,SEEK_SET);
    Customer *personas = (Customer *)malloc(tamano * sizeof(Customer));
    fread(personas, sizeof(Customer), tamano, tina);
    for( int i =0 ; i<1000;i++){printf("EL dia DE LA PERSONA %i ES : %hhu \n", i , personas[i].birthDay.DD);}
    free(personas);

}