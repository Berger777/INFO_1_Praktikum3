#include "stdlib.h"
#include "stdio.h"
#include "konstanten.h"

char eingabe[ARRAY_SIZE];
char newArray[ARRAY_SIZE];

//Liest ein Char-Array ein und gibt den Pointer der auf das erste Element zeigt zurück
char* arrayEinlesen(){
    fgets(eingabe,ARRAY_SIZE,stdin);
    return eingabe;
}

//Erwartet als Parameter den Zeiger auf das erste Element eines Char-Arrays und spiegelt das Array
char* arraySpiegeln(char *arrayStart){
    char* pointer = arrayStart;
    char* reversePointer;

    char currentChar = *arrayStart;
    int stringLen = 0;


    //Die Länge der Eingabe berechnen
    while (currentChar != '\n'){
        //printf("Current lentgh:%d, character is: %c\n",stringLen, currentChar);
        stringLen++;
        pointer++;
        currentChar = *pointer;
    }
    //Alle Elemente vertauschen
    for (int i = 0; i < stringLen; ++i) { //Schleife wird so oft durchlaufen wie die Eingabe lang ist
        reversePointer = arrayStart + stringLen-1 - i; // strLen -1 weil arrayStart schon das erste Element ist
        newArray[i] = *reversePointer;
    }
    return newArray;
}
