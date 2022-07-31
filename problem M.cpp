#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <random>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<string> s(n);
    for (int i = 0; i < n; i++){
        cin >> s[i];
        sort(s[i].begin(), s[i].end());
    }
    sort(s.begin(), s.end());
    vector<int> lst(1, 1);
    for (int i = 1; i < n; i++){
        if (s[i] == s[i - 1])
            lst.back()++;
        else
            lst.push_back(1);
    }
    int odd = false;
    int res = 0;
    for (int x : lst){
        res += x - (x & 1);
        odd += (x & 1);
    }
    if (odd)
        res++;
    cout << res * k << endl;
}

int main() {
    freopen("name.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n = 1;
    cin >> n;
    for (int i = 0; i < n; i++)
        solve();
}