#include<bits/stdc++.h>

using namespace std;

int points;
int n;
double dist[100009];

inline bool check(double x){
    int pnum=0;
    double covered=-1;
    for(int i=0; i<n; i++){
        if(covered < dist[i]){
            pnum++;
            if(pnum > points)
                return false;
            covered = dist[i] + 2*x;
        }
    }
    //cout << "pnum = " << pnum << '\n'; 
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> points >> n;
    if(n == 1){
        cout << "0.0";
        return 0;
    }
    for(int i=0; i<n; i++){
        cin >> dist[i];
    }
    sort(dist, dist+n);
    double mid, end = 1000005, beg = 0;
    while(end-beg > 0.001){
        //cout << "mid = " << mid << '\n';
        mid = (end+beg)/2;
        if(check(mid)){
            end = mid;
            //cout << "end = " << end << '\n';
        }
        else{
            beg = mid;
            //cout << "beg = " << end << '\n';
        }
    }
    cout << fixed << setprecision(1) << mid;

}