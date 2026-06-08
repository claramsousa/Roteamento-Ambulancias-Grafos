#include "../include/Algoritmos.h"
#include <iostream>
#include <vector>

using namespace std;

void imprimirCaminho(int origem, int destino, const vector<int>& predecessores) {
    if (predecessores[destino] == -1 && origem != destino) {
        cout << "ALERTA: Não há caminho viável até o destino!\n";
        return;
    }

    cout << "Rota: ";

    if (origem != destino) {
        construirCaminho(destino, predecessores);
    } else {
        cout << origem;
    }
}

void construirCaminho(int verticeAtual, const vector<int>& predecessores) {
    if (predecessores[verticeAtual] == -1) {
        cout << verticeAtual;
        return;
    }

    construirCaminho(predecessores[verticeAtual], predecessores);
    cout << " -> " << verticeAtual;
}
