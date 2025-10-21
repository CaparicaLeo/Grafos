#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Estado
{
    int lin, col, movimentos;
};

int dr[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dc[] = {-1, 1, -2, 2, -2, 2, -1, 1};

bool ehValido(int r, int c)
{
    return r >= 0 && r < 8 && c >= 0 && c < 8;
}

int bfs(int lin_inicio, int col_inicio, int lin_fim, int col_fim)
{
    if (lin_inicio == lin_fim && col_inicio == col_fim)
    {
        return 0;
    }

    vector<vector<bool>> visitado(8, vector<bool>(8, false));
    queue<Estado> fila;

    fila.push({lin_inicio, col_inicio, 0});
    visitado[lin_inicio][col_inicio] = true;

    while (!fila.empty())
    {
        Estado atual = fila.front();
        fila.pop();

        for (int i = 0; i < 8; ++i)
        {
            int nova_lin = atual.lin + dr[i];
            int nova_col = atual.col + dc[i];

            if (nova_lin == lin_fim && nova_col == col_fim)
            {
                return atual.movimentos + 1;
            }

            if (ehValido(nova_lin, nova_col) && !visitado[nova_lin][nova_col])
            {
                visitado[nova_lin][nova_col] = true;
                fila.push({nova_lin, nova_col, atual.movimentos + 1});
            }
        }
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string origem_str, destino_str;

    while (cin >> origem_str >> destino_str)
    {
        int col_inicio = origem_str[0] - 'a';
        int lin_inicio = origem_str[1] - '1';
        int col_fim = destino_str[0] - 'a';
        int lin_fim = destino_str[1] - '1';

        int movimentos = bfs(lin_inicio, col_inicio, lin_fim, col_fim);

        cout << "To get from " << origem_str << " to " << destino_str << " takes " << movimentos << " knight moves." << endl;
    }

    return 0;
}