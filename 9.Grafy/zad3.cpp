#include<iostream>
#include<vector>

using namespace std;

struct Node{
    bool reached;
    int loop_id;
};

Node nodes[100001];
vector<int> graph[100001];
int curr_id;

void dfs(int n){
    nodes[n].reached = true;
    nodes[n].loop_id = curr_id;
    for(int i : graph[n]){
        if(!nodes[i].reached){
            dfs(i);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, e, q;
    cin >> n >> e >> q;
    int a,b;
    for(int i=0; i<e; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);        
    }
    for(int i=1; i<n+1; i++){
        if(!nodes[i].reached){
            curr_id++;
            dfs(i);
        }
    }

    for(int i=0; i<q; i++){
        cin >> a >> b;
        if(nodes[a].loop_id == nodes[b].loop_id){
            cout << "T\n";
        }
        else{
            cout << "N\n";
        }
    }
}