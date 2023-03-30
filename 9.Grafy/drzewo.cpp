#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<int> graph[1000001];
int dist[1000001];

int bfs(){
    queue<int> q;
    dist[1] = 1;
    for(int i : graph[1]){
        dist[i] = 1;
        q.push(i);
    }
    int curr_node;
    while(!q.empty()){
        curr_node = q.front();
        q.pop();
        for(int i : graph[curr_node]){
            //if(dist[i] != -1 && dist[i] != dist[curr_node]){
            //    cout << "sus dist i: " << i << " curr_node: " << curr_node << " " << dist[i] << ' ' << dist[curr_node];
            //    return 1;
            //}
            if(dist[i]==-1){
                q.push(i);
                dist[i] = 1;
            }
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fill_n(dist, 1000001, -1);
    int n, e;
    cin >> n >> e;
    
    if(n!=e+1){
        cout << "NIE";
        return 0;
    }
    if(n<1){
        cout << "NIE";
        return 0;
    }
    int a,b;
    for(int i=0; i<e; i++){
        cin >> a >> b;
        if(a==b){
            cout << "NIE";
            return 0;
        }else{
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
    }
    if(bfs()!=1){
        for(int i=1; i<n+1; i++){
            if(dist[i]==-1){
                cout << "NIE" << i;
                return 0;
            }
        }
    }else{
        cout << "NIE";
        return 0;
    }
    cout << "TAK";
    return 0;
}