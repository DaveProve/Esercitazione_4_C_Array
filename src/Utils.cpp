#include <Utils.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

Portafoglio leggiInput(const string& nomeFile) {
    Portafoglio dati;
    ifstream input(nomeFile); // Apre il file
    string line; //Memorizza una riga del file

    getline(input, line); //Legge la prima linea (che contiene S)
    istringstream iss_S(line.substr(2)); // Crea un oggetto escludendo i primi due caratteri (S e ;)
    iss_S >> dati.S; //Memorizza il valore numerico di S

    getline(input, line); //Stesso procedimento anche per n
    istringstream iss_n(line.substr(2));
    iss_n >> dati.n;

    //ALlocazione degli array w e r
    dati.w = new double[dati.n];
    dati.r = new double[dati.n];

    getline(input, line); // Legge la terza riga e la "ignora"

    for (int i = 0; i < dati.n && getline(input, line); ++i) { //Ciclo per creare i due vettori
        istringstream iss(line);
        string w_str, r_str;

        getline(iss, w_str, ';'); //Prende la sottostringa e la salva in w_str finchè non c'è un delimitatore ;
        istringstream(w_str) >> dati.w[i]; // Converte w_str in un tipo double e memorizza il valore in w[i]

        // Stesso procedimento ma per r
        getline(iss, r_str, ';');
        istringstream(r_str) >> dati.r[i];
    }

    input.close(); // Chiude il file


    // Codice per stampare sull'output di QT i valori (non necessario)
    cout << fixed << setprecision(2);
    cout << "S = " << dati.S << ", n = " << dati.n << endl;
    cout << "w = [ ";
    for (int i = 0; i < dati.n; ++i) {
        cout << dati.w[i] << " ";
    }
    cout << "]" << endl;
    cout << "r = [ ";
    for (int i = 0; i < dati.n; ++i) {
        cout << dati.r[i] << " ";
    }
    cout << "]" << endl;

    return dati;  //Resistuisce i dati necessari
}

int controllo(const string& nomeFile){    //Funzione che dato in input un file controlla se esiste e funziona correttamente
    ifstream file(nomeFile);
    if(file.fail()){
        cerr << "File not found" << endl;
        return 1;
     }
    return 0;
}

double rate(double* w, double* r, int n) {  //Funzione che calcola il Rate of Return di un portafoglio
    double investimento = 0.0;             //Inizializziamo i dati di investimento e di ritorno
    double ritorno = 0.0;
    cout << fixed << setprecision(4);
    for (int i = 0; i < n; ++i) {        //Creiamo un ciclo for per il valore finale di w e del ritorno
        investimento += w[i];
        ritorno += w[i] * r[i];
    }
    double rate = ritorno / investimento; //Calcoliamo il rate

    return rate;
}

double calc(double S, double rate) {    //Crea una funzione per calcolare il valore finale V del portafoglio
    cout << fixed << setprecision(2);
    double V = (1+rate) * S;

    return V;
}

