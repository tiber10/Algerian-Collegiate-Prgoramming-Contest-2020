#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stdio.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    vector<int> s(n);
    for (int& x : s)
        cin >> x;
    int mx = 0, r = -1, l = -1;
    for (int i = 0; i < n; i++){
        if (s[i] < mx)
            r = i;
        mx = max(mx, s[i]);
    }
    int mn = 1e9 + 7;
    for (int i = n - 1; i >= 0; i--){
        if (s[i] > mn)
            l = i;
        mn = min(mn, s[i]);
    }
    // cout << l << ' ' << r << endl;
    if (l != -1){
        swap(s[l], s[r]);
        for (int i = 0; i < n - 1; i++)
            if (s[i] > s[i + 1]){
                cout << "NO\n";
                return;
            }
        cout << "YES\n";
        return;
    }
    for (int i = 0; i < n - 1; i++){
        if (s[i] == s[i + 1]){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    // freopen("one.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n = 1;
    // cin >> n;
    for (int i = 0; i < n; i++)
        solve();
}