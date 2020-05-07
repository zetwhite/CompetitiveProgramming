#include <iostream>
using namespace std; 

void solve(){
    int n, m ;
    cin >> n >> m; 
    bool success = false; 
    if(n == 1 || m == 1)
        success = true; 
    if(n == 2 && m == 2)
        success = true;
    if(success)
        cout << "YES\n";
    else
        cout << "NO\n"; 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; 
    cin >> t; 
    for(int i = 0; i < t; i++){
        solve(); 
    }
    return 0; 
}