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

ll area(P pontos[], int n){
    ll total = 0;
    for(int i=0; i<n; i++){
        total += (pontos[i].y + pontos[i+1].y) * (pontos[i].x - pontos[i+1].x);
    }
    return abs(total);
}

int main() {
    int n; cin >> n;
    P pontos[n+1];
    for(int i=0; i<n; i++)
        pontos[i].read();
    pontos[n] = pontos[0];

    cout << area(pontos, n) << '\n';
    return 0;
}