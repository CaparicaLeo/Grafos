#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
struct Aresta
{
    int u, v, peso;

    bool operator<(const Aresta &outra) const
    {
        return peso < outra.peso;
    }
};

struct DSU
{
    vector<int> pai;

    DSU(int n)
    {
        pai.resize(n + 1);
        iota(pai.begin(), pai.end(), 0);
    }

    int encontrar(int i)
    {
        if (pai[i] == i)
        {
            return i;
        }
        return pai[i] = encontrar(pai[i]);
    }

    void unir(int i, int j)
    {
        int raiz_i = encontrar(i);
        int raiz_j = encontrar(j);
        if (raiz_i != raiz_j)
        {
            pai[raiz_i] = raiz_j;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int R, C;
    cin >> R >> C;

    vector<Aresta> arestas(C);
    for (int i = 0; i < C; ++i)
    {
        cin >> arestas[i].u >> arestas[i].v >> arestas[i].peso;
    }

    sort(arestas.begin(), arestas.end());

    DSU dsu(R);

    long long custo_total = 0;
    int arestas_adicionadas = 0;

    for (const auto &aresta : arestas)
    {
        if (dsu.encontrar(aresta.u) != dsu.encontrar(aresta.v))
        {
            dsu.unir(aresta.u, aresta.v);

            custo_total += aresta.peso;

            arestas_adicionadas++;

            if (arestas_adicionadas == R - 1)
            {
                break;
            }
        }
    }

    cout << custo_total << endl;

    return 0;
}