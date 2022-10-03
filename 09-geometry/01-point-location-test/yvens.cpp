#include <bits/stdc++.h>
using namespace std;
#define ll long long int
 
int main() {
  ll x1, y1, x2, y2, x3, y3;
  int t;
  cin >> t;
  while (t--) {
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    ll k = (y3 - y1) * (x2 - x1);
    ll l = (x3 - x1) * (y2 - y1);
    if (k > l)
      cout << "LEFT\n";
    else if (k < l)
      cout << "RIGHT\n";
    else
      cout << "TOUCH\n";
  }
}