#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
 
using namespace std;
 
#define int long long
 
const int INF = 1e10 + 7;
 
void solve() {
    int n, k, L;
    cin >> n >> k >> L;
    vector <int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int l = 0, r = INF;
    while (r - l > 1) {
        int m = l + r >> 1;
        int sum = 0;
        for (int i = 0; i < n; ++i)
            sum += m / a[i];
        if (sum >= k)
            r = m;
        else
            l = m;
    }
    cout << r * L << "\n";
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