#include<iostream>
#include<vector>

using namespace std;

bool visited[100001];

vector<int> graph[100001];

void dfs(int n){
    visited[n] = true;
    for(int i : graph[n]){
        if(!visited[i]){
            dfs(i);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, e;
    cin >> n >> e;
    for(int i=0; i<e; i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1);
    for(int i=1; i<n+1; i++){
        cout << (visited[i]? "TAK\n":"NIE\n");
    }
}