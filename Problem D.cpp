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
    int n;
    cin >> n;
    vector<int> s1(n);
    for (int& x : s1)
        cin >> x;
    vector<int> s2(n);
    for (int& x : s2)
        cin >> x;
    string Y = "Youssef\n", R = "Rashad\n";
    int l1 = 0, r1 = n;
    int l2 = 0, r2 = n;
    while (r1 - l1 > 0){
        if (s1[l1] > s2[l2]){
            swap(s1, s2);
            swap(l1, l2);
            swap(r1, r2);
            swap(Y, R);
        }
        if (s1[r1 - 1] > s2[r2 - 1]){
            cout << Y;
            return;
        }
        int cnt1 = 0, cnt2 = 0;
        for (int i = l2; i < r2; i++)
            if (s1[i] < s2[l2])
                cnt1++;
        for (int i = r2 - 1; i >= l2; i--)
            if (s2[i] > s1.back())
                cnt2++;
        if (cnt1 != cnt2){
            cout << (cnt1 < cnt2 ? R : Y);
            return;
        }
        l1 += cnt1;
        r2 -= cnt2; 
    }
    cout << R << endl;
}

int main() {
    freopen("card.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n = 1;
    cin >> n;
    for (int i = 0; i < n; i++)
        solve();
}