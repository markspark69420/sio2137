#include<bits/stdc++.h>

using namespace std;

long long distFrom[1001];
bool visited[1001];
pair<int, int> points[1001];
long long start, num, jump;

long long sq(long long x){
    return x*x;
}

void getDist(int point){
    pair<int, int> p = points[point];
    for(int i=0; i<num; i++){
        distFrom[i] = sq(p.first-points[i].first) + sq(p.second - points[i].second);
    }
}

void bfs(int point){
    queue<int> q;
    q.push(point);
    int curr;
    while(!q.empty()){
        curr = q.front();
        q.pop();
        if(!visited[curr]){
            getDist(curr);
            for(int i=0; i<num; i++){
                if(distFrom[i] <= jump && visited[i] == false){
                    q.push(i);
                }
            }    
        }
        visited[curr] = true;
    }
}

int main(){
    cin >> num >> start >> jump;
    jump *= jump;
    start--;
    for(int i=0; i<num; i++){
        cin >> points[i].first >> points[i].second; 
    }
    long long max_dist = 0;
    bfs(start);
    getDist(start);
    for(int i=0; i<num; i++){
        max_dist = max(max_dist, distFrom[i] * visited[i]);
    }
    cout << std::fixed << std::setprecision(3) << sqrt(max_dist) + sqrt(jump);
}