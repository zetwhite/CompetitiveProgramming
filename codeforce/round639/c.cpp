#include <iostream> 
#include <cstring> 
using namespace std; 

void solve(){
    int n; 
    cin >> n;
    bool *allocated = new bool[n]; 
    memset(allocated, 0, sizeof(bool)*n); 
    bool success = true;
    int i; 
    for(i = 0; i < n; i++){
        int a; 
        cin >> a; 
        int next = (i + a) % n;
        if(next < 0)
            next += n; 
        if(allocated[next]){
            success = false;
            break; 
        }
        allocated[next] = true;
    }
    if(success) 
        cout << "YES\n"; 
    else {
        for(i = i+1; i < n; i++){
            string s; 
            getline(cin, s); 
        }
        cout << "NO\n"; 
    }
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