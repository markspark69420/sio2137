#include<bits/stdc++.h>

using namespace std;


struct Path{
    int a;
    int b;
    int t;
};

int leader[500002];
int points[500002];
Path arr[1000002];

bool comp(Path a, Path b){
    return a.t > b.t;
}

int find(int a){
    if(leader[a] == a || leader[a] == 0)
        return a;
    int b = find(leader[a]);
    leader[a] = b;
    return b;
}

void join(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b)
        return;
    leader[a] = b;
    points[b] += points[a];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    
    int point_total, num, paths, last;
    cin >> num >> paths >> point_total;
    
    if(point_total == 1){
        cout << "KEEP CALM AND FOLLOW THE WHITE RABBIT";
        return 0;
    }

    for(int i=0; i<point_total; i++){
        cin >> last;
        points[last]++;
    }
    for(int i=0; i<paths; i++){
        cin >> arr[i].a >> arr[i].b >> arr[i].t;
    }

    sort(arr, arr+paths, comp);

    int indx=0, t;
    while(indx < paths && points[find(last)] != point_total){
        t = arr[indx].t;
        join(arr[indx].a, arr[indx].b);
        indx++;
    }
    if(points[find(last)] != point_total){
        cout << -1;
        return 0;
    }
    cout << t-1;

}