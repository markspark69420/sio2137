#include<bits/stdc++.h>

using namespace std;

struct scheme{
    int dest;
    int f_time;
    int first;
    int mod;
};

vector<scheme> graph[300003];

long long dist[300003];

long long get_time(long long t, scheme s){
    if(t <= s.first){
        return s.first + s.f_time;
    }
    else if((t-s.first)%s.mod == 0){
        return t + s.f_time;
    }
    else{
        return t + s.mod - ((t-s.first)%s.mod) + s.f_time;
    }
}

void dji(){
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
    q.push({0, 1});
    pair<long long, int> curr;
    while(!q.empty()){
        curr = q.top();
        //cout << "looking at: " << curr.first << ", " << curr.second << '\n';
        q.pop();
        if(dist[curr.second] == -1){
            dist[curr.second] = curr.first;

            for(scheme i : graph[curr.second]){
                if(dist[i.dest] == -1){
                    q.push({get_time(curr.first, i), i.dest});
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    fill_n(dist, 300003, -1);
    int n;
    cin >> n;
    int curr;
    int d, ft, f, mod;
    for(int i=1; i<n+1; i++){
        cin >> curr;
        for(int j=0; j<curr; j++){
            cin >> d >> ft >> f >> mod;
            graph[i].push_back({d, ft, f, mod});
        }
    }
    dji();
    if(dist[n] != -1){
        cout << dist[n];
    }
    else{
        cout << "ARESZT";
    }
}