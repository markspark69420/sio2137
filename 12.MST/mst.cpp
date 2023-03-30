#include<bits/stdc++.h>

using namespace std;

struct Ver{
    int a;
    int b;
    int w;
    int num;
};

bool comp(Ver a, Ver b){
    return a.w < b.w;
}

Ver edges[1000009];
int leader[1000009];

int find(int a){
    if(leader[a] == a || leader[a] == 0){
        return a;
    }
    int b = find(leader[a]);
    leader[a] = b;
    return b;
}

bool join(int a, int b){
    int x = find(a), y = find(b);
    if(x == y){
        return false;
    }
    leader[x] = y;
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    
    int e, n;
    cin >> n >> e;
    for(int i=0; i<e; i++){
        cin >> edges[i].a >> edges[i].b >> edges[i].w;
        edges[i].num = i+1;
    }  
    sort(edges, edges+e, comp);

    for(int i=0; i<e ; i++){
        if(join(edges[i].a, edges[i].b)){
            //e_add++;
            cout << edges[i].num << '\n';
        }
    }
}