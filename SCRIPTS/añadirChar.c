#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    char dato[] = "1013352;;;;;;;;Europe";
    printf("\n%s", dato);
    SettearString(dato);
    printf("\n%s", dato); // Imprime la cadena modificada

    char copia[100]; // Ajusta el tamaño según sea necesario
    strcpy(copia, dato); // Copia la cadena modificada
    printf("\nCadena copiada: %s\n", copia);

    unsigned int a = atoi(strtok(copia, ";"));
    printf("El campo key es %u\n", a);

    char genero[7];
    strcpy(genero, strtok(NULL, ";"));
    printf("El campo genero es %s\n", genero);

    char nombre[40];
    strcpy(nombre, strtok(NULL, ";"));
    printf("El campo nombre es %s\n", nombre);

    char ciudad[40];
    strcpy(ciudad, strtok(NULL, ";"));
    printf("El campo ciudad es %s\n", ciudad);

    char statecode[40];
    strcpy(statecode, strtok(NULL, ";"));
    printf("El campo stecode es %s\n", statecode);

    char state[20];
    strcpy(state, strtok(NULL, ";"));
    printf("El campo state es %s\n", state);

    unsigned int b = atoi(strtok(NULL, ";"));
    printf("El campo zip es %u\n", b);

    char pais[20];
    strcpy(pais, strtok(NULL, ";"));
    printf("El campo pais es %s\n", pais);

    char continente[20];
    strcpy(continente, strtok(NULL, ";"));
    printf("El campo continente es %s\n", continente);
    
    return 0;
}
