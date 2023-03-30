#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int m, w;
    cin >> m >> w;
    int mury[w];
    fill_n(mury, w, 0);
    int start = m/2;
    int temp;
    for(int i=0; i<m; i+=2){
        cin >> temp;
        mury[temp]--;
        cin >> temp;
        mury[w-temp]++;
    }
    int prefix[w+1];
    fill_n(prefix, w+1, 0);
    prefix[0]=start;
    for(int i=0; i<w; i++){
        prefix[i+1] = prefix[i] + mury[i];
    }
    int min=2137420,streak=0;
    for (int i = 1; i < w+1; i++){
        if(min>prefix[i]){
            min = prefix[i];
            streak=1;
        }else if(min==prefix[i]){
            streak++;
        }
    }
    cout << min << ' ' << streak;
}