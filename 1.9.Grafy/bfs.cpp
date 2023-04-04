#include<vector>
#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

vector<int> graph[100001];
int dist[100001];

void bfs(){
    queue<int> q;
    dist[1] = 0;
    for(int i : graph[1]){
        q.push(i);
        dist[i] = 1;
    }
    int curr_node;
    while(!q.empty()){
        curr_node = q.front();
        for(int i : graph[curr_node]){
            if(dist[i]==-1){
                dist[i] = dist[curr_node] + 1;
                q.push(i);
            }
        }
        q.pop();
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fill_n(dist, 100001, -1);
    int n, e;
    int a, b;
    cin >> n >> e;
    for(int i=0; i<e; i++){
        cin >> a >> b;
        if(a!=b){
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
    }
    bfs();
    for(int i=1; i<n+1; i++){
        cout << dist[i] << '\n';
    }
}