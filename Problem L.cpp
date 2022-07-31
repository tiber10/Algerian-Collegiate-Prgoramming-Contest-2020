#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <random>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int maxk = 1e3 + 7;

int p[maxk];
vector<int> dp[maxk];

ll cnt(ll x, int k){
    if (x == 1)
        return 1;
    return dp[x][k / x];
}

ll f(vector<ll>& s, int k){
    ll res = 1;
    for (ll x : s)
        res = res * cnt(x, k) % mod;
    return res;
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector<ll> s(n);
    for (ll& x : s)
        cin >> x;
    // cout << f(s, k) << endl;
    // return 0;
    ll res = f(s, k) - f(s, k - 1);
    if (res < 0)
        res += mod;
    cout << res << '\n';
}

int main() {
    freopen("valid.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int x = 2; x < maxk; x++){
        if (p[x] == 0){
            p[x] = x;
            for (int y = x * x; y < maxk; y++){
                if (p[y] == 0)
                    p[y] = x;
                p[y] = min(x, p[y]);
            }
        }
    }
    for (int x = 2; x < maxk; x++){
        dp[x].resize(maxk / x + 1);
        for (int y = 1; y < dp[x].size(); y++){
            dp[x][y] = dp[x][y - 1];
            if (y == 1 || p[y] >= x)
                dp[x][y]++;
        }
    }


    // cout << dp[2][2] << ' ' << endl;
    // return 0;
    int n = 1;
    cin >> n;
    for (int i = 0; i < n; i++)
        solve();
}