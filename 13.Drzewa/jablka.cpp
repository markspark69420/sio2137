#include<bits/stdc++.h>

using namespace std;

vector<int> graph[1000009];
bool visited[1000009];
int max_;
int max_indx;

void dfs(int n, int d){
    visited[n] = true;
    if(d > max_){
        //cout << "ch max: " << max_indx << '\n';
        max_ = d;
        max_indx = n;
    }
    for(int i : graph[n]){
        if(!visited[i])
            dfs(i, d+1);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b;
    cin >> n;
    for(int i=0; i<n-1; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1, 0);
    max_ = 0;
    fill_n(visited, 1000000, 0);
    dfs(max_indx, 0);
    cout << max_;
}