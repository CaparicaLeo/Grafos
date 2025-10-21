//1076
//filhosdojava
//Leonardo Brzezinski Caparica de Almeida, Milena Alessandra Bernardi e Thiago Ceron de Almeida

#include <iostream>
#include <vector>

using namespace std;

void dfs(int no, vector<vector<int>>& grafo, vector<bool>& visitado, int& contador) {
    visitado[no] = true;
    for (int vizinho : grafo[no]) {
        if (!visitado[vizinho]) {
            contador++; 
            dfs(vizinho, grafo, visitado, contador);
        }
    }
}

int main() {
    int qt_casos;
    cin >> qt_casos;

    for (int caso = 0; caso < qt_casos; caso++) {
        int ponto_inicial, qtd_nos, qtd_conexoes;
        cin >> ponto_inicial >> qtd_nos >> qtd_conexoes;

        vector<vector<int>> grafo(qtd_nos);

        for (int i = 0; i < qtd_conexoes; i++) {
            int a, b;
            cin >> a >> b;
            grafo[a].push_back(b);
            grafo[b].push_back(a);
        }

        vector<bool> visitado(qtd_nos, false);
        int total_arestas = 0;

        dfs(ponto_inicial, grafo, visitado, total_arestas);

        cout << total_arestas * 2 << endl;
    }

    return 0;
}

//  ./1076 < entrada.txt > saida.tx