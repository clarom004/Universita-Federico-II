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

//Inizio programma
int main () {
    /*
    Traccia: 
    */

    // Dichiarazione variabili
    int x = 10;
    int *px = &x;

    // Corpo Principale
    cout << x << endl;
    cout << &px << endl;
    cout << *px << endl;

    px++;

    cout << x << endl;
    cout << px << endl;
    cout << *px << endl;

    return 0;
}

// Cosa fa ogni funzione