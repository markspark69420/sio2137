#include<iostream>
#include<algorithm>

using namespace std;

int len;
int tree[120000];
int a, b, temp_res;

void add(int indx){
    a = len-1;
    b = indx + len + 1;
    while(a/2!=b/2){
        //  cout << a << ' ' << b << '\n';
        if(a%2==0){
            tree[a+1]++;
        }
        if(b%2==1){
            tree[b-1]++;
        }
        a/=2;
        b/=2;
    }
}

int read(int indx){
    temp_res = 0;
    a = len+indx;
    temp_res += tree[a];
    a/=2;
    while(a>0){
        temp_res += tree[a];
        a/=2;
    }
    return temp_res;
}

int main(){
    int true_res = 0;
    pair<int,int> tab[60000];
    cin >> len;
    for(int i=0; i<len; i++){
        cin >> tab[i].first;
        tab[i].second = i;
    }
    sort(tab, tab+len);
    /*cout << "<sort>\n";
    for(int i=0; i<len; i++){
        cout << tab[i].first << ' ' << tab[i].second << '\n';
    }
    cout << "</sort>\n";*/
    for(int i=0; i<len; i++){
        true_res += read(tab[i].second);
        
        add(tab[i].second);
    }
    cout << true_res;
}