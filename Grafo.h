#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <utility>
#include <string>

using namespace std;

class Grafo {
private:
    int numVertices;
    const int INF = 1e9;
    
    //estruturas
    vector<vector<int>> matrizAdj;
    vector<vector<pair<int, int>>> listaAdj;

    void adicionarAresta(int origem, int destino, int tempo);

public:
    Grafo(int vertices);

    bool carregarDatasetDeCSV(const string& caminhoArquivo);

    void exibirMatriz() const;
    void exibirLista() const;

    int getNumVertices() const { return numVertices; }
    const vector<vector<int>>& getMatrizAdj() const { return matrizAdj; }
    const vector<vector<pair<int, int>>>& getListaAdj() const { return listaAdj; }
};

#endif