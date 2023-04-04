#include<bits/stdc++.h>

using namespace std;

int post[500005];
int pre[500005];
vector<int> g[500005];
int d;


void dfs(int node){
    pre[node] = ++d;
    for(int i : g[node]){
        dfs(i);
    }
    post[node] = d;
}

bool q(int boss, int p){
    if(p == boss)
        return false;
    if(pre[p] < pre[boss])
        return false;
    if(pre[p] > post[boss])
        return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    int n, curr, curr2;
    cin >> n;
    for(int i=1; i<n; i++){
        cin >> curr;
        g[curr].push_back(i);
    }
    dfs(0);
    while(true){
        cin >> curr;
        if(curr == -1){
            break;
        }
        cin >> curr2;
        cout << (q(curr, curr2)? "TAK\n":"NIE\n");
    }
}