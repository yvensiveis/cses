/*
Posicoes pares nao importam:
se eu tenho uma posicao perdedora e tiro moedas de uma pilha par,
elas vao para uma pilha impar que meu adversario pode retornar para
uma pilha par (o contrario nao ocorre).
Entao, tirar moedas de uma pilha impar equivale a excluir as moedas
do jogo, ja que elas vao para posicao pares que nao importam
Dai vira so um Nim normal nas posicoes impares
*/
#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define pc __builtin_popcount
#define int long long

using namespace std;

const int maxn = 2e5 + 10, inf = 2e9, M = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (int &x : v) cin >> x;
    int lucca = 0;
    for (int i = 1; i < n; i+=2)
        lucca ^= v[i];
    cout << (lucca ? "first" : "second") << endl;
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin >> t; while (t--)
    solve();
    return 0;
}