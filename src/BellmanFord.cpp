#include "../include/Algoritmos.h"
#include <iostream>

using namespace std;


int executarBellmanFord(const vector<vector<pair<int, int>>>& listaAdj, int origem, int destino, vector<int>& predecessores) {
    int numVertices = listaAdj.size();
    const int INF = 1e9;
   
    vector<int> distancias(numVertices, INF);
    predecessores.assign(numVertices, -1);
   
    distancias[origem] = 0;

    for(int i = 1; i < numVertices-1; i++) {
        bool atualizacao = false;

        for(int j = 1; j < numVertices; j++) {
            if (distancias[j] == INF) continue;

            for(const auto& par: listaAdj[j]) {
                int verticeAtual = par.first;
                int tempo = par.second;

                if(distancias[verticeAtual] > distancias[j] + tempo) {
                    distancias[verticeAtual] = distancias[j] + tempo;
                    predecessores[verticeAtual] = j;
                    atualizacao = true;
                }
            }
        }
        if(!atualizacao) break;
    }

    bool semCiclo = cicloNegativo(numVertices, listaAdj, distancias);
    if(!semCiclo) return INF;
    
    if(distancias[destino] != INF) {
        imprimirCaminho(origem, destino, predecessores);
    } else {
        cout << "ALERTA: Nao ha caminho viavel ate o destino!\n";
    }
   
    return distancias[destino];
}

bool cicloNegativo(int numVertices, const vector<vector<pair<int, int>>>& listaAdj, const vector<int>& distancias) {
    const int INF = 1e9;

    for(int j = 1; j < numVertices; j++) {
        if (distancias[j] == INF) continue;

        for(const auto& par: listaAdj[j]) {
            int vertice = par.first;
            int tempo = par.second;

            if(distancias[vertice] > distancias[j] + tempo) {
                cout << "ALERTA: O grafo possui ciclo negativo!\n";
                return false;
            }
        }
    }
    return true;
}