#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+5;
typedef long long int ll;

void solve() {
    int n, x[MAXN];
    for(int i=0; i<MAXN; i++) x[i] = 0;

    cin >> n;
    for(int i = 0; i < n; i++){
        int k; cin >> k;
        x[k] = 1;        
    }
    int mdc = 1;

    for(int i = 1; i < MAXN; i++){
        int cont = 0;
        for(int j = i; j < MAXN; j+=i){
            if(x[j] != 0) cont ++;
            if(cont >= 2) break;
        }
        if(cont >= 2) mdc = i;
    }

    cout << mdc << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //int t; cin >> t; while (t--)
    solve();
    return 0;
}
