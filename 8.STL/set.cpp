#include<iostream>
#include<set>
#include<iterator>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int il;
    cin >> il;

    set<long long> liczby;
    char curr;
    long long l;
    set<long long>::iterator itr;

    for(int i=0; i<il; i++){
        cin >> curr;
        
        if(curr=='+'){
            cin >> l;
            liczby.insert(l);
        }
        else if(curr=='-'){
            cin >> l;
            liczby.erase(l);
        }
        else if(curr=='f'){
            cin >> l;
            auto upper = liczby.lower_bound(l);
            if(upper==liczby.end()){
                cout << "BRAK\n";
            }
            else{
                cout << *upper << '\n';
            }
        }
        else if(curr=='s'){
            cout << liczby.size() << '\n';
        }
        else{
            for(itr = liczby.begin(); itr != liczby.end(); itr++){
                cout << *itr << ' ';
            }
            cout<<'\n';
        }
    }
}