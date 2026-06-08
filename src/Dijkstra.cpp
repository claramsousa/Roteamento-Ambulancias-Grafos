#include "../include/Algoritmos.h"
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

int executarDijkstra(const vector<vector<pair<int, int>>>& listaAdj, int origem, int destino) {
    int n = listaAdj.size();
    const int INF = 1e9;
    vector<int> dist(n, INF);
    vector<int> predecessores(n, -1);
    
    // Fila de prioridade para escolher o vértice com a menor distância provisória
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    // Inicialização
    dist[origem] = 0;
    pq.push({0, origem});
    
    while (!pq.empty()) {
        pair<int, int> topo = pq.top();
        pq.pop();
        
        int d = topo.first;
        int u = topo.second;
        
        // Se a distância no topo da fila for maior que a melhor distância atual, ignoramos
        if (d > dist[u]) continue;
        
        // Se já alcançamos o destino, podemos interromper a busca
        if (u == destino) break;
        
        // Relaxamento das arestas vizinhas
        for (const auto& aresta : listaAdj[u]) {
            int v = aresta.first;
            int tempo = aresta.second;
            
            // Ignorar arestas com tempos (pesos) negativos
            if (tempo < 0) continue;
            
            if (dist[u] + tempo < dist[v]) {
                dist[v] = dist[u] + tempo;
                predecessores[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    
    // Se o destino for alcançável, imprime o caminho utilizando a função auxiliar compartilhada
    if (dist[destino] != INF) {
        imprimirCaminho(origem, destino, predecessores);
    } else {
        cout << "ALERTA: Nao ha caminho viavel ate o destino!";
    }
    
    return dist[destino];
}