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


void insertChar(char *str, char c, int pos) {
    int len = strlen(str);
    for (int i = len; i >= pos; i--) {
        str[i + 1] = str[i];
    }
    str[pos] = c;
    str[len + 1] = '\0'; // Actualiza el último carácter de la cadena
}

void SettearString(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ';' && str[i + 1] == ';') {
            int pos = i + 1;
            insertChar(str, ' ', pos);
            i++;
        }
    }
}


int main() {
    char dato[] = "716838;Male;Aladino Longo;Vigevano;PV;Pavia;27029;;Europe;1/7/1954";
    FILE *tina = fopen("D:\\Users\\PC\\Desktop\\PARCIAL3\\DATA\\CustomersData.txt", "wb");
    
    Customer persona1;

    SettearString(dato);
    char copia[100];
    strcpy(copia, dato); 

    unsigned int a = atoi(strtok(copia, ";"));
    persona1.CustomerKey= a;

    char genero[7];
    strcpy(genero, strtok(NULL, ";"));
    strcpy( persona1.gender,genero);

    char nombre[40];
    strcpy(nombre, strtok(NULL, ";"));
    strcpy( persona1.name,nombre);

    char ciudad[40];
    strcpy(ciudad, strtok(NULL, ";"));
    strcpy( persona1.city,ciudad);

    char statecode[40];
    strcpy(statecode, strtok(NULL, ";"));
    strcpy( persona1.stateCode,statecode);

    char state[20];
    strcpy(state, strtok(NULL, ";"));
    strcpy( persona1.state,state);

    unsigned int b = atoi(strtok(NULL, ";"));
    persona1.zipCode=b;

    char pais[20];
    strcpy(pais, strtok(NULL, ";"));
    strcpy( persona1.country,pais);

    char continente[20];
    strcpy(continente, strtok(NULL, ";"));
    strcpy(persona1.continent,continente);    

    sscanf(strtok(NULL, ";"), "%hhu/%hhu/%hu", &persona1.birthDay.DD, &persona1.birthDay.MM, &persona1.birthDay.AAAA);
    fwrite(&persona1, sizeof(persona1),1, tina);
    return 0;
}
