#include <bits/stdc++.h>
using namespace std;
#define ll long long int

struct P {
	ll x, y;
	void read() { cin >> x >> y; }
	ll operator*(P b) const {
		return 1LL*x*b.y - 1LL*b.x*y;
	}
	P operator-(P b) {
		return P{x-b.x, y-b.y};
	}
    void operator-=(P b) {
        *this = *this - b;
    }
	ll triangle(P b, P c) {
		return (b - *this) * (c - *this);
	}
	bool operator<(P b) {
		return make_pair(x, y) < make_pair(b.x, b.y);
	}
	void show() {
		cout << x << ' ' << y << endl;
	}
};

// 1 = esquerda, -1 = direita, 0 = na reta
int local(P a, P b, P c){
    ll k = (c.y - a.y) * (b.x - a.x);
    ll l = (c.x - a.x) * (b.y - a.y);
    if (k > l)
        return 1;
    else if (k < l)
        return -1;
    else
        return 0;
}
 
bool seg_int(P a, P b, P c, P d){
    //lugar relativo de a e b por cd e de c e d por ab
    int k1 = local(c, d, a);
    int k2 = local(c, d, b);
    int k3 = local(a, b, c);
    int k4 = local(a, b, d);

    if(!k1 && !k2 && !k3 && !k4) return 0;
    
    return k1*k2 <= 0 && k3*k4 <= 0;
}

int in_poly(P ponto[], int n, P p){
    P z; z.x = 1e9 + 6; z.y = 1e9 + 5;
    ll total = 0;
    
    if(p.x >= 0) z.x += p.x;
    else z.x += 1e9 + p.x;
    
    if(p.y >= 0) z.y += p.y;
    else z.y += 1e9 + p.y;
    
    for(int i=0; i<n; i++){
        if((p.x - ponto[i+1].x)*(ponto[i].y - ponto[i+1].y) == (ponto[i].x - ponto[i+1].x)*(p.y - ponto[i+1].y)){
            bool yv = false;
            if(ponto[i].x == ponto[i+1].x){
                yv = p.y - ponto[i+1].y >= 0 && ponto[i].y - ponto[i+1].y > 0 && ponto[i].y >= p.y;
                yv = yv || (p.y - ponto[i+1].y <= 0 && ponto[i].y - ponto[i+1].y < 0 && ponto[i].y <= p.y);
            
            }else{
                yv = p.x - ponto[i+1].x >= 0 && ponto[i].x - ponto[i+1].x > 0 && ponto[i].x >= p.x;
                yv = yv || (p.x - ponto[i+1].x < 0 && ponto[i].x - ponto[i+1].x < 0 && ponto[i].x <= p.x);
            
            }
            
            if(yv) return 2;
        }
        else{
            total += seg_int(p, z, ponto[i], ponto[i+1]);
        }
    }
    return total%2;
}
    
int main(){
    int n, m; cin >> n >> m;
    P ponto[n+1];
    for(int i=0; i<n; i++)
        ponto[i].read();
    ponto[n] = ponto[0];
    
    string s[3] = {"OUTSIDE\n", "INSIDE\n", "BOUNDARY\n"};

    while(m--){
        int total = 0;
        P p; p.read();
        cout << s[in_poly(ponto, n, p)];
    }
}