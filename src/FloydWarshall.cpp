#include "../include/Algoritmos.h"
#include <iostream>
#include <iomanip>
using namespace std;

vector<vector<int>> executarFloydWarshall(const vector<vector<int>> &matrizAdjOriginal)
{
    int n = matrizAdjOriginal.size() - 1;
    const int INF = 1e9;

    vector<vector<int>> dist = matrizAdjOriginal;

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (dist[i][k] == INF)
                continue;

            for (int j = 1; j <= n; j++)
            {
                if (dist[k][j] == INF)
                    continue;

                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    bool cicloNegativoDetectado = false;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i][i] < 0)
        {
            cicloNegativoDetectado = true;
            cout << "[AVISO] Ciclo negativo detectado envolvendo o vertice " << i << "!\n";
        }
    }

    if (!cicloNegativoDetectado)
    {
        cout << "[OK] Nenhum ciclo negativo detectado na malha.\n";
    }

    cout << "\n"
         << string(100, '=') << "\n";
    cout << "   MATRIZ GLOBAL DE DISTANCIAS MINIMAS (FLOYD-WARSHALL) - RESGATERAPIDO\n";
    cout << string(100, '=') << "\n";

    cout << "      ";
    for (int v = 1; v <= n; v++)
    {
        cout << setw(5) << v;
    }
    cout << "\n     " << string(n * 5 + 1, '-') << "\n";

    for (int i = 1; i <= n; i++)
    {
        cout << " " << setw(3) << i << " |";
        for (int j = 1; j <= n; j++)
        {
            if (dist[i][j] == INF)
            {
                cout << setw(5) << "INF";
            }
            else
            {
                cout << setw(5) << dist[i][j];
            }
        }
        cout << "\n";
    }

    cout << string(100, '=') << "\n";
    cout << "[LEGENDA] Valores em minutos. INF = sem caminho disponivel.\n";

    return dist;
}