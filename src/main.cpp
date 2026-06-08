#include <iostream>
#include <iomanip>
#include "../include/Grafo.h"
#include "../include/Algoritmos.h"


using namespace std;


void exibirLayoutMenu() {
    cout << "\n=======================================================\n";
    cout << "    SISTEMA - ROTEAMENTO DE AMBULANCIAS   \n";
    cout << "=======================================================\n";
    cout << " 1. Rota Padrao (Dijkstra - Apenas pesos positivos)\n";
    cout << " 2. Rota Preditiva (Bellman-Ford - bonus/transito)\n";
    cout << " 3. Matriz Global de Distancias (Floyd-Warshall)\n";
    cout << " 8. [Debug] Exibir Matriz de Adjacencia carregada\n";
    cout << " 9. [Debug] Exibir Lista de Adjacencia carregada\n";
    cout << " 0. Sair do Sistema\n";
    cout << "=======================================================\n";
    cout << "Escolha uma opcao: ";
}


int lerSetorValido(string tipo) {
    int setor;
    cout << "Setor da " << tipo << " (1 a 20): ";
    cin >> setor;
   
    while (setor < 1 || setor > 20) {
        cout << "[ERRO] Setor inexistente na malha! Digite um valor entre 1 e 20: ";
        cin >> setor;
    }
    return setor;
}


int main() {
    Grafo hospitalGrafo(20);


    if (!hospitalGrafo.carregarDatasetDeCSV("data/dataset_rotas.csv")) {
        cout << "Fechando o sistema devido a erro de leitura.\n";
        return 1;
    }
    cout << "[SISTEMA] Malha de trafego carregada com sucesso a partir do CSV.\n";


    int opcao, orig, dest, tempoRetornado;
    vector<int> predecessores;


    do {
        exibirLayoutMenu();
        cin >> opcao;


        switch (opcao) {
            case 1:
                orig = lerSetorValido("Ambulancia [Origem]");
                dest = lerSetorValido("Emergencia [Destino]");
               
                tempoRetornado = executarDijkstra(hospitalGrafo.getListaAdj(), orig, dest);
               
                cout << "\n[RESULTADO] Tempo minimo estimado da rota (Dijkstra): "
                     << tempoRetornado << " minutos.\n";
                break;
               
            case 2:
                orig = lerSetorValido("Ambulancia [Origem]");
                dest = lerSetorValido("Emergencia [Destino]");
               
                tempoRetornado = executarBellmanFord(hospitalGrafo.getListaAdj(), orig, dest, predecessores);
                
                if(tempoRetornado == 1e9) {
                    cout << "\n";
                    break;
                }

                cout << "\n[RESULTADO] Tempo preditivo da rota (Bellman-Ford): "
                     << tempoRetornado << " minutos.\n";
                break;
               
            case 3: {
                cout << "\nGerando matriz global de distancias...\n";
                vector<vector<int>> matrizGlobal = executarFloydWarshall(hospitalGrafo.getMatrizAdj());
               
                cout << "[RESULTADO] Matriz processada com sucesso!\n";
                break;
            }
            case 8:
                hospitalGrafo.exibirMatriz();
                break;
               
            case 9:
                hospitalGrafo.exibirLista();
                break;
            case 0:
                cout << "\nEncerrando o sistema de despacho...\n";
                break;


            default:
                cout << "\nOpcao invalida!\n";
        }
    } while (opcao != 0);


    return 0;
}