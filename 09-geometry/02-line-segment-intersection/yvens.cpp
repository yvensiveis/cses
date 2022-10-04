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

    if(!k1 && !k2 && !k3 && !k4){
        //normalizar por a
        b-=a; c-=a; d-=a;
        ll z3, z4;

        //analisar c e d entre 0 e b
        if(b.x*c.x + b.y*c.y < 0) z3 = -1;
        else if(b.x*c.x + b.y*c.y < b.x*b.x + b.y*b.y) z3 = 0;
        else z3 = 1;
    
        if(b.x*d.x + b.y*d.y < 0) z4 = -1;
        else if(b.x*d.x + b.y*d.y < b.x*b.x + b.y*b.y) z4 = 0;
        else z4 = 1;
    
        return z3 * z4 != 1;
    }
    
    return k1*k2 <= 0 && k3*k4 <= 0;
}

int main(){
    P a, b, c, d;
    int t;
    cin >> t;
    while (t--) {
        a.read(); b.read(); c.read(); d.read();
        if(seg_int(a, b, c, d)) cout << "YES\n";
        else cout << "NO\n";
    }
}