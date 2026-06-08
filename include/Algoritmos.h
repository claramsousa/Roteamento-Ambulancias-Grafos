#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include <vector>
#include <utility>

using namespace std;

/* =========================================================================
   1. ÍNDICES (1 a 20): O índice 0 das estruturas foi ignorado para 
      facilitar a leitura. Façam seus laços `for` começando do 1 indo até 
      o 20 (ou `tamanho - 1`).
      
   2. INFINITO (1e9): O valor que representa "infinito" (ausência de 
      caminho) na Matriz de Adjacência é 1e9 (1000000000). Usem este 
      valor nas verificações (ex: if (distancia != 1e9)). Não usar INT_MAX 
      para evitar problemas de overflow em somas.
   ========================================================================= */

int executarDijkstra(const vector<vector<pair<int, int>>>& listaAdj, int origem, int destino);

// Funções Bellman-Ford
int executarBellmanFord(const vector<vector<pair<int, int>>>& listaAdj, int origem, int destino, vector<int>& predecessores);
bool cicloNegativo(int numVertices, const vector<vector<pair<int, int>>>& listaAdj, const vector<int>& distancias);
void imprimirCaminho(int origem, int destino, const vector<int>& predecessores);
void construirCaminho(int vertice, const vector<int>& predecessores);

vector<vector<int>> executarFloydWarshall(const vector<vector<int>>& matrizAdjOriginal);

#endif