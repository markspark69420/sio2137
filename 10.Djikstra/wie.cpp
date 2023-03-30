#include<bits/stdc++.h>

using namespace std;

struct state{
    int w;
    int og;
    int b;
    /*state(int w, int og, int b){
        this->w = w;
        this->og = og;
        this->b = b;
    }
    state(){
        state(0,0,0);
    }*/
    bool operator() (const state a, const state b){
        return a.w > b.w;
    }
};

// w, node
vector<pair<int, int>> graph[100001];
vector<int> short_dist[100001];
int dist[100001];
bool in_path[100001];

bool comp(state a, state b){
    return a.w < b.w;
}

void dji(){
    priority_queue<state, vector<state>, state> dji_q;
    dji_q.push({0, 1, 1});
    state curr;
    while(!dji_q.empty()){
        curr = dji_q.top();
        dji_q.pop();
        if(dist[curr.b] == -1){
            //cout << "best dist for " << curr.b << " = " << curr.w << '\n';
            dist[curr.b] = curr.w;
            for(pair<int, int> j : graph[curr.b]){
                dji_q.push({curr.w+ j.first, curr.b, j.second});
            }
        }
        if(dist[curr.b] == curr.w){
            short_dist[curr.b].push_back(curr.og);
        }
    }
}

void bfs(int n){
    queue<int> q;
    q.push(n);
    in_path[1] = true;
    int curr;
    //cout << "b: pushed into queue 1\n";
    while(!q.empty()){
        curr = q.front();
        q.pop();
        in_path[curr] = true;
        for(int i : short_dist[curr]){
            if(!in_path[i]){
                q.push(i);
                //cout << "b: pushed into queue " << i << "\n";
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    fill_n(dist, 100001, -1);
    int nodes, edges;
    cin >> nodes >> edges;
    int a, b, w;
    for(int i=0; i<edges; i++){
        cin >> a >> b >> w;
        graph[a].push_back(make_pair(w, b));
        graph[b].push_back(make_pair(w, a));
    }
    dji();
    bfs(nodes);
    for(int i=0; i<nodes+1; i++){
        //cout << "in path: \n";
        if(in_path[i])
            cout << i << '\n';
    }
}