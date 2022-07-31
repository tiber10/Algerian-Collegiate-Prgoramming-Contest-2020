#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <random>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

bool ok(int x, int y, int mask, vector<vector<int>>& s, vector<vector<int>>& c){
    return x >= 0 && y >= 0 && x < s.size() && y < s[0].size() && (s[x][y] | mask) == mask && c[x][y] == 0;
}

vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};

bool dfs(int sx, int sy, int fx, int fy, int mask, vector<vector<int>>& s, vector<vector<int>>& c){
    bool res = false;
    c[sx][sy] = 1;
    if ((s[sx][sy] | mask) != mask)
        return false;
    if (sx == fx && sy == fy)
        return true;
    for (int k = 0; k < dx.size(); k++){
        if (ok(sx + dx[k], sy + dy[k], mask, s, c))
            res |= dfs(sx + dx[k], sy + dy[k], fx, fy, mask, s, c);
    }
    return res;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> s(n, vector<int> (m));
    vector<vector<int>> color(n, vector<int> (m, 0));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            cin >> s[i][j];
    }
    int mask = (1 << 30) - 1;
    int sx, sy, fx, fy;
    cin >> sx >> sy >> fx >> fy;
    for (int k = 29; k >= 0; k--){
        for (int i = 0; i < n; i++)
            fill(color[i].begin(), color[i].end(), 0);

        if (dfs(sx - 1, sy - 1, fx - 1, fy - 1, mask ^ (1 << k), s, color))
            mask ^= (1 << k);
    }
    cout << mask << endl;
}

int main() {
    freopen("min.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n = 1;
    cin >> n;
    for (int i = 0; i < n; i++)
        solve();
}