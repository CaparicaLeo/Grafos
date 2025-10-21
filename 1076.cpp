// 1076
// filhosdojava
// Leonardo Brzezinski Caparica de Almeida, Milena Alessandra Bernardi e Thiago Ceron de Almeida

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int qt_casos;
    cin >> qt_casos;

    for (int caso = 0; caso < qt_casos; caso++)
    {
        int ponto_inicial, qtd_nos, qtd_conexoes;
        cin >> ponto_inicial >> qtd_nos >> qtd_conexoes;

        vector<vector<bool>> grafo(qtd_nos, vector<bool>(qtd_nos));
        for (int j = 0; j < qtd_conexoes; j++)
        {
            int a, b;
            cin >> a >> b;

            grafo[a][b] = true;
            grafo[b][a] = true;
        }

        int total_arestas = 0;
        for (auto linha : grafo)
            for (auto celula : linha)
                total_arestas += celula;

        cout << total_arestas << endl;
    }

    return 0;
}

//./1076 < entrada.txt > saida.tx