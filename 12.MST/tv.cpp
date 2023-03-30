#include<bits/stdc++.h>

using namespace std;

bool visited[5000];
long long dist_from_mst[5000];
bool in_mst[5000];
pair<int, int> points[5000];
int nodes_num;

// crap

/*unsigned long long root(unsigned long long x, unsigned long long aprox){
    if(x==0)
        return 0;
    unsigned long long res[2] ={aprox,(aprox+x/aprox)/2};
    bool a = 0;
    bool b = 1;
    int iter = 0;
    while(res[0]!=res[1] && iter < 2000){
        res[a] = (res[b]+x/res[b])/2;
        a = b;
        b = not b;
        iter++;
    }
    unsigned long long c = min(res[0], res[1]);
    return (x==c*c)? c : c+1;
}*/

long long root(unsigned int x){
    return ceil(sqrt(x));
}

long long get_dist(pair<int, int> a, pair<int, int> b){
    int x = a.first - b.first;
    int y = a.second - b.second;
    //if(x == 0 || y == 0)
    //    return x+y;
    return root(x*x + y*y);
}

void ch_dist(int node){
    for(int i=0; i<nodes_num; i++){
        if(in_mst[i])
            continue;
        dist_from_mst[i] = min(get_dist(points[node], points[i]), dist_from_mst[i]);
    }
}

int min_dist(){
    int indx=0;
    unsigned int mini = dist_from_mst[0];
    for(int i=1; i<nodes_num; i++){
        if(mini > dist_from_mst[i]){
            indx = i;
            mini = dist_from_mst[i];
        }
    }
    return indx;
}

long long prim(){
    long long dist_max = 1;
    in_mst[0] = true;
    fill(dist_from_mst, dist_from_mst+nodes_num, 10000000);
    visited[0] = true;
    ch_dist(0);
    ch_dist(0);
    int mst_num = 1;
        //     for(int i=0; i<nodes_num; i++){
        //    cout << (in_mst[i]?0:dist_from_mst[i]) << ' ';
        // }
    while(mst_num < nodes_num){
        int curr = min_dist();
        in_mst[curr] = true;
        ch_dist(curr);
        dist_max = max(dist_from_mst[curr], dist_max);
        dist_from_mst[curr] = 10000000;
        mst_num++;
        // cout << "after adding " << points[curr].first << " ," << points[curr].second << '\n';
        // for(int i=0; i<nodes_num; i++){
        //    cout << (in_mst[i]?0:dist_from_mst[i]) << ' ';
        // }
        // cout << '\n' << dist_sum <<'\n';
    }
    return dist_max;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int nodes_og;
    cin >> nodes_og;
    nodes_num = nodes_og;
    for(int i=0; i<nodes_num; i++){
        cin >> points[i].first;
        cin >> points[i].second;
        for(int j=0; j<i; j++){
            if(points[i] == points[j]){
                i--;
                nodes_num--;
                break;
            }
        }
    }
    long long p = prim();
    cout << p*(nodes_og-1);
}