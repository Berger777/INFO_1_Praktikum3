#include <stdio.h>
#include <math.h>
#include <string.h>
#include "konstanten.h"

int isPrime(int i);

char* arraySpiegeln(char* arrayStart);
char* arrayEinlesen();

void aufgabe1();
void aufgabe2();
void aufgabe3();
void aufgabe4();


int main() {
    printf("Praktikum Nummer 3!\n-------------------------\n");
    //aufgabe1();
    //aufgabe2();
    //aufgabe3();
    aufgabe4();
    return 0;
}

void aufgabe1(){
    printf("Geben Sie einen Text ein:\n");
    char* eingabeArray = arrayEinlesen();
    printf("-------------------------\nSie haben eingegeben:\n%s",eingabeArray);
    eingabeArray = arraySpiegeln(eingabeArray);
    printf("Rueckwaerts gelesen ist der Text:\n%s\n",eingabeArray);
}

void aufgabe2(){
    int anzahl = 0;
    for (int i = 2; i < PRIMZAHLEN_BIS; ++i) {
        if(isPrime(i)){
            anzahl++;
        }
    }

    if(isPrime(anzahl)){
        printf("%d ist eine Primzahl!",anzahl);
    } else if (isPrime(anzahl)){
        printf("%d ist keine Primzahl!",anzahl);
    }
}



//Funktion: String in LowerCase umwandeln
char* toLowerCase(char* in){
    while(*in != '\0'){
        if(*in >= 'A' && *in <= 'Z'){
            *in+=32;
        }
        in++;
    }
    return in;
}

//Funktion: Ersetzt alle Character der Eingabe durch das Substiutions-Komplement, verschluesslen == 1 und entschluesseln == 0
char* substitution(char* eingabe, int verschluesseln){
    char currentChar;
    char map[SUBS_SIZE][SUBS_STATES] = { {'a','b'},{'b','j'},{'c',','},{'d','o'},{'e','t'},{'f','d'},{'g','g'},
                        {'h','l'},{'i','h'},{'j','r'},{'k','k'},{'l','i'},{'m','c'},{'n','x'},
                        {'o','a'},{'p','m'},{'q','.'},{'r','p'},{'s','z'},{'t','y'},{'u','e'},
                        {'v','v'},{'w','_'},{'x','q'},{'y','n'},{'z','s'},{'.','u'},{',','w'},
                        {'_','f'} };

    for (int i = 0; i < strlen(eingabe); ++i) {
        currentChar = *(eingabe+i);
        for (int j = 0; j < SUBS_SIZE; ++j) {
            if(currentChar == map[j][0] && verschluesseln){
                *(eingabe+i) = map[j][1];
            }else if (currentChar == map[j][1] && !verschluesseln){
                *(eingabe+i) = map[j][0];
            }
        }
    }
    return eingabe;
}

void aufgabe3(){
    char* eingabe = arrayEinlesen();
    toLowerCase(eingabe);
    char* ausgabe = substitution(eingabe, 1);
    printf("%s",ausgabe);
}




//Funktion: Status aller Lampen ausgeben
void lampenAusgeben(char c) {
    printf("| L1 | L2 | L3 | L4 | L5 | L6 | L7 | L8 |\n");

    for(int i = 0;i < 8;i++){
        if(c & (unsigned int)pow(2,i)){
            printf("| x  ");
        }else{
            printf("| -  ");
        }
    }
    printf("|\n");
}

//Funktion: Den Status einer einzelnen Lampe ändern
/*
 *
 */
void lampeStatusChange(char lampeNummer, char status, char* lamps){
    unsigned int integerVal = lampeNummer - '0';
    if(status == 'x'){
        lamps[0] = *lamps | (unsigned int)pow(2,integerVal-1); //Bitmaske verordern
    }else if(status == '-'){
        *lamps = *lamps & ~((unsigned int)pow(2,integerVal-1)); //Invertierte Bitmaske verunden
    }
    //printf("TEST: Lampe %d neuer Status: %c\n",integerVal, status);
}

void aufgabe4(){
    char lampsChar = 0;
    char* lamps = &lampsChar;
    lampenAusgeben(*lamps);
    char* eingabe;
    int loop = 1;

    while (loop){
        printf(">");
        eingabe = arrayEinlesen();

        if(*eingabe == 'q'){    //Schleife verlassen
            loop = 0;
        }
        else if(*eingabe > '8' || *eingabe < '1'){  //Validation
            printf("Lampe außerhalb von 1 bis 8.\n");
        }else if(*(eingabe+1) != '-' && *(eingabe+1) != 'x'){   //Validation
            printf("Lampenstatus ungültig!\n");
        }else{
            lampeStatusChange(*eingabe, *(eingabe+1), lamps);   //Erst die Lampennummer, dann den Status, dann das Lampenchar
            lampenAusgeben(*lamps);
        }
    }

}

