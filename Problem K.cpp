#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stdio.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

void solve(){
    int t;
    cin >> t;
    string s;
    cin >> s;
    vector<int> c(26);
    for (char x : s)
        c[int(x - 'a')]++;
    int mx = 0;
    for (int x : c)
        mx = max(mx, x);
    cout << s.size() - mx << endl;    
}

int main() {
    freopen("string.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        solve();
}