#include<bits/stdc++.h>

using namespace std;

vector<int> g[1000009];
int visited[1000009];
int val[1000009];

long long get_max(int node){
    long long maxi = 0;
    visited[node] = true;
    for(int i : g[node]){
        if(!visited[i]){
            maxi = max(maxi, get_max(i));
        }
    }
    return val[node] + maxi;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> val[i+1];
    }
    for(int i=1; i<n; i++){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cout << get_max(1);
}