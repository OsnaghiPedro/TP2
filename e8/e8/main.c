#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Para su mejor lectura se hace en un solo archivo

void leerPrimerPalabra(char * text1, char * text2);
int BuscarPalabra(char * textBus, char * text);

#define IS_SPACE(a) ((a)==' ') ? 1 : 0

int main()
{
    char texto[100];
    char palabra[30];

    //leemos texto
    printf("ingrese un texto: ");
    gets(texto);

    //guardamos la primer palabra en el palabra
    leerPrimerPalabra(texto, palabra);

    printf("El texto es: %s\n"
           "la primer palabra es: %s", texto, palabra);

    printf("\n\nla palabra: %s se repite %d veces.",palabra, BuscarPalabra(palabra,texto));
    return 0;
}


//Funcion que lee la primer palabra de text1 y la guarda en text2

void leerPrimerPalabra(char * text1, char * text2){

while(*text1 && !IS_SPACE(*text1))
{
    *text2 = *text1;
    text1++;
    text2++;

}
*text2 = '\0';

}

//Funcion que busca la parabra textBus en text
//retorna la cantidad de veces que se repite
int BuscarPalabra(char * textBus, char * text){

int cont=0;
char aux[30];
char * paux;
//leemos el texto mientas no sea . o fin de cadena
while(*text && *text != '.')
{
    //apuntamos a aux (inicio)
    paux = aux;
    //leemos palabras hasta el espacio y la pasamos a aux
    while(*text && !IS_SPACE(*text))
    {
       *paux = *text;
       paux++;
       text++;
    }
    // cierro aux
    *paux = '\0';

    //comparamos aux con textBus

    //strcmp devuelve 0 si coinciden
    if (!strcmp(textBus,aux)) cont++;

    //aumentamos el puntero en uno para saltar el ' '
    text++;
}
 return cont;
}
