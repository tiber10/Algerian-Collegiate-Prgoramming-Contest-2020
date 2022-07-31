#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stdio.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

int main() {
    freopen("xor.in", "r", stdin);
    int n, t;
    cin >> t;
    for (int _ = 0; _ < t; _++){
        cin >> n;
        ll res = 1;
        for (int i = 0; i < n - 1; i++)
            res = res * 4 % mod;
        cout << res << '\n';
    }
}