#include<bits/stdc++.h>

using namespace std;

// dist, id
// priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
set<pair<long long, int>> q;
//dist, id
vector<pair<int, int>> graph[500005];

long long dist[500005];

void dji(){
    q.insert({0,1});
    long long curr_id, curr_dist;
    while(!q.empty()){
        curr_dist = q.begin()->first;
        curr_id = q.begin()->second;
        //cout << "curr " << curr_dist << ',' << curr_id << '\n';
        q.erase(q.begin());
        if(dist[curr_id] == -1){
            //cout << "set dist[" << curr_id << "] to " << curr_dist << '\n';
            dist[curr_id] = curr_dist;
        }
        for(pair<int, int> i : graph[curr_id]){
            if(dist[i.second] == -1){
                //cout << "pushed {" << curr_dist + i.first << ',' << i.second << '}' << '\n';
                //dist[i.second] = curr_dist + i.first;
                q.insert({curr_dist + i.first, i.second});
            }
        }

    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(nullptr);
    cin.tie(nullptr);
    fill_n(dist, 500005, -1);
    int n, e, a, b, w;
    cin >> n >> e;

    for(int i=0; i<e; i++){
        scanf("%d %d %d", &a, &b, &w);// >> a >> b >> w;
        graph[a].push_back({w, b});
        graph[b].push_back({w, a});
    }

    dji();

    for(int i=1; i<n+1; i++){
        cout << dist[i] << '\n';
    }
}