#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int M = 1e9 + 7;

vector<pair<int, int>> p;
bool tem_impar = false;

int fexp(int a, int b) {
    if (b == 0) return 1;
    int f = fexp(a, b >> 1);
    f = ((ll) f * f) % M;
    if (b & 1) f = ((ll) f * a) % M;
    return f;
}

int inv(int a) {
    return fexp(a, M-2);
}

int div(){
    int d = 1;
    for(int i=0; i<p.size(); i++)
        d = ((ll)d * (p[i].second + 1)) % M;
    
    return d;
}

int soma(){
    int d = 1, f = 1;
    for(int i=0; i<p.size(); i++){
        f = fexp(p[i].first, p[i].second + 1) - 1;
        f = (M + f) % M;
        f = ((ll)f * inv(p[i].first - 1)) % M;
    
        d = ((ll)d * (f)) % M;
    }
    return d;
}

int prod(){
    int d = 1, n = 1;
    
    if(tem_impar){
        bool flag = true;
        for(int i=0; i<p.size(); i++){
            if(p[i].second % 2 == 1 && flag){
                d = ((ll)d * ((p[i].second + 1)/2)) % (M-1);
                flag = false;
            }
            else d = ((ll)d * (p[i].second + 1)) % (M-1);
        }

        for(int i=0; i<p.size(); i++)
            n = ((ll)n * fexp(p[i].first, p[i].second)) % M;
    }
    else{
        for(int i=0; i<p.size(); i++)
            d = ((ll)d * (p[i].second + 1)) % (M-1);

        for(int i=0; i<p.size(); i++)
            n = ((ll)n * fexp(p[i].first, p[i].second/2)) % M;
    }

    return fexp(n, d);
}

void solve() {
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        if(y % 2 == 1) tem_impar = true;
        p.push_back({x, y});
    }

    cout << div() << '\n';
    cout << soma() << '\n';
    cout << prod() << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //int t; cin >> t; while (t--)
    solve();
    return 0;
}
