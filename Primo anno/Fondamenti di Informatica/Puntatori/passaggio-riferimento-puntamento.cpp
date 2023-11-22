#include<iostream>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cctype>
#include<ctime>
#include<climits>
#include<stdio.h>
#include<windows.h>
#include<fstream>

using namespace std;

//Record

//Prototipo della funzione
void dimezza_rif(float &x);
void dimezza_punt(float *px);

//Inizio programma
int main () {
    //Traccia: Creare una funzione che dimezzi il valore di un numero sia per riferimento che per puntamento.

    // Dichiarazione variabili
    float numero = 23;

    // Corpo Principale
    cout << "Per riferimento:\n";
    cout << "\tPrima: numero=" << numero << endl;
    dimezza_rif(numero);
    cout << "\tDopo: numero=" << numero << endl;

    cout << "\nPer puntamento:\n";
    cout << "\tPrima: numero=" << numero << endl;
    dimezza_punt(&numero);
    cout << "\tDopo: numero=" << numero << endl << endl;

    return 0;
}

// Cosa fa ogni funzione
void dimezza_rif(float &x) {
    x /= 2;

    return;
}

void dimezza_punt(float *px) {
    *px /= 2;

    return;
}