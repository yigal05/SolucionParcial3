#include <stdio.h>
#include <string.h>

typedef struct{
    unsigned char DD;
    unsigned char MM;
    unsigned short int AAAA;
}fecha;

typedef struct
{
    unsigned int CustomerKey;
    char gender[7] ;
    char name[40] ;
    char city[40] ;
    char stateCode[4] ;
    char state[25] ;
    int zipCode;
    char country[20] ;
    char contienent[20];
}crearTabla;

int main(){
    FILE *archivo = fopen("D:\\Users\\PC\\Desktop\\PARCIAL3\\BASES\\Customers.csv","rb");
    FILE *tina = fopen("D:\\Users\\PC\\Desktop\\PARCIAL3\\DATA\\CustomersData.txt", "wb");
    int dato=0;
    while ( dato!=20)
    {
        char tin[100];
        int index=0;
        for (int i = fgetc(archivo); i != 10;i = fgetc(archivo)){
            tin[index]= i;
            index= index+1;
        }
        tin[index] = '\0';

        crearTabla persona1 ;
        
        sscanf(tin, "%u,%[^;],%[^;],%[^;],%[^;],%[^;],%i,%[^;],%[^;]",
                &persona1.CustomerKey, persona1.gender, persona1.name, persona1.city,
                persona1.stateCode, persona1.state, &persona1.zipCode, persona1.country,
                persona1.contienent);
        printf("DATO NUMERO %i\n", dato);
        printf("%u,%s,%s,%s,%s,%s,%i,%s,%s",
                &persona1.CustomerKey, persona1.gender, persona1.name, persona1.city,
                persona1.stateCode, persona1.state, &persona1.zipCode, persona1.country,
                persona1.contienent);
        printf("\n\n");
        fwrite(&persona1,sizeof(persona1),1,tina);
        dato++;
    }
    
}