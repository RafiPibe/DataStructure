#include <bits/stdc++.h>
using namespace std;

pair<int,int> par[500001];

pair<int, int> find(int a){
    if(par[a].first == a) return par[a];
    return par [a] = find (par[a].first);
}

void join(int a, int b) {
    pair <int,int> par_a = find (a);
    pair <int,int> par_b = find (b);
    if(par_a != par_b){
        if (par[par_a.first].second > par[par_b. first] . second) swap(par_a, par_b);
        par[par_a.first].first = par_b.first;
        par[par_b.first].second += par[par_a. first]. second;
    }
} 

int main () {
    int n,m,k, a, b;
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) par[i] = make_pair(i, 1);
    while (m--) { 
        cin >> k;
        if(k > 0) cin >> a, k--;
        while(k--) cin >> b, join(a, b);
    }

    for (int i = 0; i < n; i++){
        pair<int, int> tmp = find(i);
        cout << tmp.second<<" ";
    }
    cout<<endl;
    return 8;
}