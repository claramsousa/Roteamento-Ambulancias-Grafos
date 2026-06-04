#include "Grafo.h"
#include <fstream>  
#include <sstream> 
#include <iostream>
#include <iomanip>

Grafo::Grafo(int vertices) : numVertices(vertices) {
    matrizAdj.assign(vertices + 1, vector<int>(vertices + 1, INF));
    
    for (int i = 1; i <= vertices; i++) {
        matrizAdj[i][i] = 0;
    }

    listaAdj.resize(vertices + 1);
}

void Grafo::adicionarAresta(int origem, int destino, int tempo) {
    matrizAdj[origem][destino] = tempo;
    listaAdj[origem].push_back({destino, tempo});
}

bool Grafo::carregarDatasetDeCSV(const string& caminhoArquivo) {
    ifstream arquivo(caminhoArquivo);
    
    if (!arquivo.is_open()) {
        cout << "[ERRO] Nao foi possivel abrir o arquivo: " << caminhoArquivo << "\n";
        return false;
    }

    string linha, item;
    
    getline(arquivo, linha);

    while (getline(arquivo, linha)) {
        if (linha.empty()) continue;

        stringstream ss(linha);
        int origem, destino, tempo;

        getline(ss, item, ','); origem = stoi(item);
        getline(ss, item, ','); destino = stoi(item);
        getline(ss, item, ','); tempo = stoi(item);

        adicionarAresta(origem, destino, tempo);
    }

    arquivo.close();
    return true;
}

void Grafo::exibirMatriz() const {
    cout << "\n" << string(95, '=') << "\n";
    cout << "   MATRIZ DE ADJACENCIA (DIGRAFO COM PESOS) - RESGATERAPIDO\n";
    cout << string(95, '=') << "\n";
    
    cout << "      ";
    for (int v = 1; v <= numVertices; v++) {
        cout << setw(4) << v;
    }
    cout << "\n     " << string(numVertices * 4.5, '-') << "\n";

    for (int u = 1; u <= numVertices; u++) {
        cout << " " << setw(3) << u << " |";
        
        for (int v = 1; v <= numVertices; v++) {
            if (matrizAdj[u][v] == INF) {
                cout << setw(4) << "INF";
            } else {
                cout << setw(4) << matrizAdj[u][v];
            }
        }
        cout << "   ]\n";
    }
}

void Grafo::exibirLista() const {
    cout << "\n" << string(60, '=') << "\n";
    cout << "   LISTA DE ADJACENCIA - MALHA DE TRAFEGO\n";
    cout << string(60, '=') << "\n";

    for (int u = 1; u <= numVertices; u++) {
        cout << setw(2) << u;
        
        if (listaAdj[u].empty()) {
            cout << " -> (sem rotas de saida)\n";
        } else {
            cout << " -> ";
            for (size_t i = 0; i < listaAdj[u].size(); i++) {
                int destino = listaAdj[u][i].first;
                int tempo = listaAdj[u][i].second;
                
                cout << destino << "[" << tempo << "m]";
                
                if (i < listaAdj[u].size() - 1) {
                    cout << " -> ";
                }
            }
            cout << "\n";
        }
    }
}