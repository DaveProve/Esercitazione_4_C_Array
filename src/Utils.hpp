#pragma once

#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

struct Portafoglio {
    double S;   //Saldo
    double* w;  //Peso
    double* r;  //Rendimento
    int n;      //Numero di investimenti

    Portafoglio() : w(nullptr), r(nullptr), n(0) {}  //Inizializza i due puntatori a nullptr e n a 0
    ~Portafoglio() {  //Distruttore
        delete[] w;
        delete[] r;
    }
};

//Richiamiamo le funzioni che utilizziamo
Portafoglio leggiInput(const string& nomeFile);
int controllo(const string& nomeFile);
double rate(double* w, double* r, int n);
double calc(double S, double rate);

#endif
