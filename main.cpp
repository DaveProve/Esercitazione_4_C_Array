#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <Utils.hpp>

using namespace std;


int main() {
    string fileName = "data.csv";  //Definiamo il file di input
    controllo(fileName);  //Controlliamo il file

    Portafoglio dati = leggiInput(fileName);  //Prendiamo i dati dal file utilizzando la funzione definita nel .cpp

    double S = dati.S;
    double* w = dati.w;
    double* r = dati.r;
    int n = dati.n;

    double rate_ret = rate(&w[0], &r[0], n);  //Calcoliamo il rate of return
    cout << "Rate of return: " << rate_ret << endl;

    double V = calc(S, rate_ret);  //E il valore di V
    cout << "V: " << V << endl;

    ofstream outputFile("C:/Users/davep/PCS2024_Exercises/Esercitazione_4_C_Array/Exercise_2/result.txt"); //Apriamo un file di output
    controllo("result.txt");   //E controlliamolo

    outputFile << "S = " << fixed << setprecision(2) << S << ", n = " << n << endl;  //a questo punto stampiamo tutto nel file secondo il formato richiesto
    outputFile << "w = [ ";
    for (int i = 0; i < n; ++i) {
        outputFile << w[i] << " ";
    }
    outputFile << "]" << endl;
    outputFile << "r = [ ";
    for (int i = 0; i < n; ++i) {
        outputFile << r[i] << " ";
    }
    outputFile << "]" << endl;
    outputFile << "Rate of return: " << fixed << setprecision(4) << rate_ret << endl;
    outputFile << "V: " << fixed << setprecision(2) << V << endl;

    outputFile.close();  //Chiudiamo il file

    delete[] w;   //Deallochiamo la memoria dei due puntatori
    delete[] r;

    return 0;
}

