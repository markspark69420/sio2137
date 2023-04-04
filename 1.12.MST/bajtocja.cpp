#include<bits/stdc++.h>

using namespace std;

struct Edge{
    int a;
    int b;
    int w;
    int num;
};

bool comp(Edge a, Edge b){
    return a.w < b.w;
}

int leader[200001];
Edge edges[300000];
bool is_poss[300000];

int find(int a){
    if(a == leader[a] || leader[a]==0)
        return a;
    int b = find(leader[a]);
    leader[a] = b;
    return b;
}

void join(int a, int b){
    a = find(a);
    b = find(b);
    //cout << "a = " << a << " b = " << b << "\n";
    if(a==b)
        return;
    leader[a] = b;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int nodes, n;
    cin >> nodes >> n;
    for(int i=0; i<n; i++){
        cin >> edges[i].a >> edges[i].b >> edges[i].w;
        edges[i].num = i;
    }
    sort(edges, edges+n, comp);

    int j = 0;
    for(int i=0; i<n; i++){
        while((edges[j].w == edges[i].w) && j<n){
            if(find(edges[j].a) == find(edges[j].b)){
                is_poss[edges[j].num] = true;
            }
            j++;
        }
        //cout << "join(" << edges[i].a << ", " << edges[i].b << ")\n";
        join(edges[i].a, edges[i].b);
        //for(int j=0; j<nodes; j++)
        //    cout << leader[j] << ' ';
        //cout << '\n';
    }
    for(int i=0; i<n; i++){
        cout << (is_poss[i]?"NIE\n":"TAK\n");
    }
}