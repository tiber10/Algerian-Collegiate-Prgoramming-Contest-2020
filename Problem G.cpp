#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
 
using namespace std;
 
//#define int long long
 
const int N = 1e6 + 7, MOD = 1e9 + 7;
 
vector <int> t[4 * N], pos[N];
int a[N];
 
void build(int v, int l, int r) {
    t[v].clear();
    if (l == r) {
        t[v].push_back(a[l]);
        return;
    }
    int m = (l + r) / 2;
    build(2 * v + 1, l, m);
    build(2 * v + 2, m + 1, r);
    t[v].resize(t[2 * v + 1].size() + t[2 * v + 2].size());
    merge(t[2 * v + 1].begin(), t[2 * v + 1].end(), t[2 * v + 2].begin(), t[2 * v + 2].end(), t[v].begin());
}
 
int ask(int v, int l, int r, int L, int R, int val) {
    if (l > R || r < L)
        return 0;
    if (l >= L && r <= R)
        return lower_bound(t[v].begin(), t[v].end(), val) - t[v].begin();
    int m = (l + r) / 2;
    return ask(2 * v + 1, l, m, L, R, val) + ask(2 * v + 2, m + 1, r, L, R, val);
}
 
void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    build(0, 0, n - 1);
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < pos[i].size(); ++j) {
            int calc = ask(0, 0, n - 1, pos[i][j - 1], pos[i][j], i);
            ans = (ans + calc * (pos[i][j - 1] + 1) % MOD * (n - pos[i][j]) % MOD * j % MOD * (pos[i].size() - j)) % MOD;
        }
    }
    cout << ans << "\n";
    for (int i = 1; i <= n; ++i)
        pos[i].clear();
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; 
    cin >> t;
    while (t--)
        solve();
    return 0;
}