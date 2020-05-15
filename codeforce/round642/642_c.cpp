#include <iostream>

using namespace std; 

long long dp[500001]; 

int main(){
    long long max = 1; 
    dp[0] = 0; 
    dp[1] = 0; 
    int t; 
    cin >> t; 
    for(int i = 0; i < t; i ++){
        int n; 
        cin >> n; 
        if( n > max){
            for(long long k = max+2; k <= n; k = k+2){
                dp[k] = dp[k-2] + (k*4 - 4)*(k/2); 
            }
        }
        cout << dp[n] << endl;
    }
    return 0; 
}