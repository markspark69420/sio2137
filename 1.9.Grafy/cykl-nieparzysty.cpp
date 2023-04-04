#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

vector<int> graph[100001];
int visited[100001];
int node_from[100001];

pair<int,int> bfs(int n){
    queue<pair<int,int>> q;
    q.push({n, 0});
    int curr_node, curr_dist;
    node_from[q.front().first] = -1;
    while(!q.empty()){
        curr_node = q.front().first;
        curr_dist = q.front().second;
        q.pop();
        visited[curr_node] = curr_dist;
        for(int i : graph[curr_node]){
            if(visited[i]==-1){
                node_from[i] = curr_node;
                q.push({i, curr_dist+1});
            }
            else if(visited[i] == curr_dist && curr_dist != 0){
                return {i,curr_node};
            }
        }
    }
    return {-1,-1};
}

void get_path(int a, int b){
    vector<int> path_b{b};
    int curr_a = a, curr_b = b;
    while(curr_a != curr_b && curr_a!=-1){
        curr_a = node_from[curr_a];
        curr_b = node_from[curr_b];
        path_b.push_back(curr_b);
    }
    //cout << (path_a[0]);
    for(int i=0; i<path_b.size(); i++){
        cout << ' ';
        cout << path_b[i];
    }

    /*for(int i=path_a.size()-2; i>0; i--){
        cout << ' ';
        cout << path_a[i];
    }*/

    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, n, e;
    int a, b;
    cin >> t;
    bool found;
    fill_n(visited, 100001, -1);
    for(int _=0; _<t; _++){
        found = false;
        cin >> n >> e;
        for(int i=0; i<n+1; i++){
            graph[i].clear();
        }
        fill_n(visited, n+1, -1);

        for(int i=0; i<e; i++){
            cin >> a >> b;
            if(a!=b){
                graph[a].push_back(b);
                graph[b].push_back(a);
            }
        }
        
        for(int i=1; i<n+1; i++){
            if(visited[i] == -1){
                pair<int,int> res = bfs(i);
                if(res.first != -1){
                    cout << "TAK ";
                    get_path(res.first, res.second);
                    cout << '\n';
                    found = true;
                    break;
                }
            }
        }
        if(!found){
            cout << "NIE\n";
        }
    }
    return 0;
}