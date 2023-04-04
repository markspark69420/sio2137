#include<bits/stdc++.h>

using namespace std;

#define MAX 1000002

int iq_min[MAX];
int iq_max[MAX];
int masa[MAX];
int leader[MAX];

int find(int a){
    if(leader[a] == 0 || leader[a] == a)
        return a;
    int b = find(leader[a]);
    leader[a] = b;
    return b;
}

void unite(int a, int b){
    int x = find(a);
    int y = find(b);
    if(x == y)
        return;
    
    leader[x] = y;
    masa[y] += masa[x];
    iq_min[y] = min(iq_min[y], iq_min[x]);
    iq_max[y] = max(iq_max[y], iq_max[x]);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> masa[i];
        cin >> iq_min[i];
        iq_max[i] = iq_min[i];
    }

    int a, b;
    std::string input;
    while(cin >> input){
        if(input[0] == 'J'){
            cin >> a >> b;
            unite(a, b);
        }else if(input[0] == 'I'){
            if(input[4] == 'A'){
                cin >> a;
                cout << iq_max[find(a)] << '\n';    
            }
            else{
                cin >> a;
                cout << iq_min[find(a)] << '\n';
        
            }
        }
        else{
            cin >> a;
            cout << masa[find(a)] << '\n';
        }
    }
}