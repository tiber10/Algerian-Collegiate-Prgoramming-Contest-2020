#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <random>

using namespace std;

typedef long long ll;

mt19937 mrand(random_device{} ());
int rnd(int x = 1e9 + 7) {
    return mrand() % x;
}

struct Node{
    int x, y;
    int cnt = 0;
    ll summa;
    Node* left;
    Node* right;
    Node(int x = 0){
        this -> x = x;
        this -> y = rnd();
        this -> cnt = 1;
        this -> summa = x;
        this -> left = nullptr;
        this -> right = nullptr;
    } 
};

void update(Node* &v){
    if (v == NULL)
        return;
    v -> cnt = 1;
    v -> summa = v -> x;
    if (v -> left != NULL){
        v -> cnt += v -> left -> cnt;
        v -> summa += v -> left -> summa;
    }
    if (v -> right != NULL){
        v -> cnt += v -> right -> cnt;
        v -> summa += v -> right -> summa;
    }
}

Node* merge(Node* a, Node* b){
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;
    if (a -> y < b -> y){
        a -> right = merge(a -> right, b);
        update(a);
        return a;
    }
    else{
        b -> left = merge(a, b -> left);
        update(b);
        return b;
    }
}

pair<Node*, Node*> split(Node* v, int x){
    if (v == NULL)
        return {v, v};
    pair<Node*, Node*> u;
    if (v -> x >= x){
        u = split(v -> left, x);
        v -> left = u.second;
        update(v);
        return {u.first, v};
    }
    else{
        u = split(v -> right, x);
        v -> right = u.first;
        update(v);
        return {v, u.second};
    }
}

pair<Node*, Node*> splitBySum(Node* v, ll s){
    if (!v)
        return {v, v};
    ll cntL = 0;
    if (v->left)
        cntL += v->left->summa;
    if (cntL + v->x <= s){
        auto u = splitBySum(v->right, s - cntL - v->x);
        v->right = u.first;
        update(v);
        return {v, u.second};        
    } else {
        auto u = splitBySum(v->left, s);
        v->left = u.second;
        update(v);
        return {u.first, v};
    }
}

void solve(){
    int n;
    ll M;
    cin >> n >> M;
    vector<pair<int, int>> s(n);
    for (pair<int, int>& x : s)
        cin >> x.first;
    for (pair<int, int>& x : s)
        cin >> x.second;
    sort(s.begin(), s.end());
    Node* root = nullptr;
    int res = 0;
    for (int i = 0; i < n; i++){
        auto u = split(root, s[i].second);
        root = merge(u.first, merge(new Node(s[i].second), u.second));
        if (M < s[i].first)
            break;
        u = splitBySum(root, M - s[i].first);
        if (u.first)
            res = max(res, u.first->cnt);
        root = merge(u.first, u.second);
    }
    cout << res << endl;
}

int main() {
    freopen("cakes.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n = 1;
    cin >> n;
    for (int i = 0; i < n; i++)
        solve();
}