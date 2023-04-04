#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    int p;
    cin >>p;
    int tab[n];
    for (int i = 0;i<n;i++){
        cin >> tab[i];
    }
    int start;
    int end;
    char a;
    for (int i = 0;i<p;i++){
        cin >> start;
        cin >> end;
        cin >> a;
        if(a == 'R'){
            sort(tab+start,tab+end);
        }else{
            sort(tab+start-1,tab+end,greater<int>());
        }
    }
    for(int i = 0;i<n;i++){
        cout << tab[i] << ' ';
    }
}