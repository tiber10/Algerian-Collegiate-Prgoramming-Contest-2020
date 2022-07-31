#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <random>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

ll power(ll a, int n){
    ll res = 1;
    while (n){
        if (n & 1)
            res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll res = 0;
    for (int i = 0; i < n; i++)
        res += int(s[i] - '0') * power(2, i) % mod * power(11, n - i - 1) % mod;
    cout << res % mod << endl;
}

int main() {
    freopen("luka.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n = 1;
    cin >> n;
    for (int i = 0; i < n; i++)
        solve();
}