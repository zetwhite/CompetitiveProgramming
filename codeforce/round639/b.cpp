#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

void solve(vector<int>& dp){
    int cnt = 0; 
    int n; 
    cin >> n; 
    while(1){
        if(n < dp[0]){
            cout << cnt << "\n";  
            break; 
        }
        vector<int>::iterator it = upper_bound(dp.begin(), dp.end(), n);    
        int idx = it - dp.begin(); 
        idx--; 
        cnt++;
        n -= dp[idx]; 
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t; 
    cin >> t; 
    vector<int> dp; 
    dp.reserve(26000); 
    int cnt = 1; 
    int upper = 0; 
    while(1){
        int res = cnt*2 + upper*3;
        if(res > 1000000000)
            break;
        dp.push_back(res); 
        upper += cnt; 
        cnt ++;  
    }
    for(int i = 0; i < t; i++)
        solve(dp); 
    return 0; 
}