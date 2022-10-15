#include <bits/stdc++.h>
using namespace std;

void solve(){
    int k, n, exp = 1, soma = 0, M = 0, tam = 0;
    cin >> n >> k;

    while(true){
        M = 2*(n % exp);
        M = (M + exp + 1) % (2*exp);
        tam = (n- M)/(2*exp) - ceil(double(1-M) / (2*exp)) + 1;

        if(k > soma + tam){
            soma += tam;
            if(soma == n-1){
                cout << (M + exp) % (2*exp) <<'\n';
                break;
            }
            exp *= 2;
            continue;
        }

        if(soma == 0) soma = -1;
        cout << exp*2*(k - soma - 1) + M << '\n';
        break;
    }

    return;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t; while (t--)
    solve();
    return 0;
}