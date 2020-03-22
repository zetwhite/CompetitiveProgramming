#include <bits/stdc++.h>
using namespace std;
int values[51][32];
int dp[52][1600];

inline void reset_dp(){
    for(int i = 0; i < 52; i++)
        memset(dp+i, -1, sizeof(int)*1600);
}

int get_best(int nth, int remain, int max_n, int max_k){
    if(remain <= 0){
        dp[nth][remain] = 0;
        return 0;
    }
    if(nth >= max_n){
        dp[nth][remain] = 0;
        return 0;
    }
    int best_val = 0;
    int st = 0;
    if(max_k < remain)
        st = max_k;
    else
        st = remain;
    for(int i = st; i>=0; i--){
        int tmp;
        if(dp[nth+1][remain-i]!=-1)
            tmp = dp[nth+1][remain-i];
        else
            tmp = get_best(nth+1, remain-i, max_n, max_k);
        tmp += values[nth][i];
        if(best_val < tmp)
            best_val = tmp;
    }
    dp[nth][remain] = best_val;
    return best_val;
}

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n, k, p;
        cin >> n >> k >> p;

        for(int j = 0; j < n; j++){
            values[j][0] = 0;
            for(int l = 1; l <= k; l++){
                cin >> values[j][l];
                values[j][l] += values[j][l-1];
            }
        }
        reset_dp();
        int res = get_best(0, p, n, k);
        cout << "Case #" <<i+1 <<": " << res << endl;
    }
    return 0;
}
