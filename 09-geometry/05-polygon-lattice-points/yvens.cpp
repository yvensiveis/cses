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

ll area(P ponto[], int n){
    ll total = 0;
    for(int i=0; i<n; i++){
        total += (ponto[i].y + ponto[i+1].y) * (ponto[i].x - ponto[i+1].x);
    }

    return abs(total);
}
 
ll boun(P ponto[], int n){
  ll B = 0;
  for(int i=0; i<n; i++){
    B += abs(__gcd(ponto[i+1].x - ponto[i].x, ponto[i+1].y - ponto[i].y));
  }

  return B; 
}

ll ins(P ponto[], int n){
    ll A = area(ponto, n);
    ll B = boun(ponto, n);
    ll C = (A - B)/2 + 1;

    return C;
}
 
int main() {
    int n; cin >> n;
    P ponto[n+1];
    for(int i=0; i<n; i++)
        ponto[i].read();
    ponto[n] = ponto[0];

    cout << ins(ponto, n) << ' ' << boun(ponto, n) << '\n';
}