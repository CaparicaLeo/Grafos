#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility> 

using namespace std;

struct Spam
{
    int origem, T1, T2;
    string A1, A2, A3;

    Spam(int o, int t1, int t2, string a1, string a2, string a3)
        : origem(o), T1(t1), T2(t2), 
          A1(std::move(a1)), A2(std::move(a2)), A3(std::move(a3)) {}
};

vector<vector<int>> ler_grafo(int N)
{
    vector<vector<int>> amigos(N + 1);
    for (int i = 1; i <= N; i++)
    {
        int x;
        while (cin >> x && x != 0)
        {
            amigos[i].push_back(x);
        }
    }
    return amigos;
}

vector<Spam> ler_spams()
{
    vector<Spam> spams;
    while (true)
    {
        int P, T1, T2;
        string A1, A2, A3;
        cin >> P;
        if (P == 0)
            break;
        cin >> T1 >> T2 >> A1 >> A2 >> A3;
        spams.emplace_back(P, T1, T2, A1, A2, A3);
    }
    return spams;
}

vector<string> ler_nomes(int N)
{
    vector<string> nomes(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> nomes[i];
    }
    return nomes;
}

vector<int> simular_propagacao(int N, const Spam &spam, const vector<vector<int>> &amigos)
{
    vector<int> enviados(N + 1, 0);
    vector<bool> recebeu(N + 1, false);
    queue<int> fila;

    fila.push(spam.origem);
    recebeu[spam.origem] = true;

    while (!fila.empty())
    {
        int p = fila.front();
        fila.pop();

        for (int amigo : amigos[p])
        {
            enviados[p]++;

            if (!recebeu[amigo])
            {
                recebeu[amigo] = true;
                fila.push(amigo);
            }
        }
    }
    return enviados;
}

string get_atributo(const Spam &spam, int num_enviados)
{
    if (num_enviados < spam.T1)
        return spam.A1;
    if (num_enviados < spam.T2)
        return spam.A2;
    return spam.A3;
}

void solve(int N)
{
    vector<vector<int>> amigos = ler_grafo(N);
    vector<Spam> spams = ler_spams();
    vector<string> nomes = ler_nomes(N);

    vector<vector<string>> atributos(N + 1);

    for (const auto &spam : spams)
    {
        vector<int> enviados = simular_propagacao(N, spam, amigos);

        for (int i = 1; i <= N; i++)
        {
            atributos[i].push_back(get_atributo(spam, enviados[i]));
        }
    }

    for (int i = 1; i <= N; i++)
    {
        cout << nomes[i] << ": ";
        for (const auto &a : atributos[i])
        {
            cout << a << " ";
        }
        cout << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    while (cin >> N && N != 0)
    {
        solve(N);
    }

    return 0;
}