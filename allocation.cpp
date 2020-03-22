#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    int* a = new int[1001];

    for(int i = 0; i < t; i++){
        int n, b;
        cin >> n >> b;
        for(int j = 0; j < 1001; j++)
            a[j] = 0;

        for(int j = 0; j < n; j++){
            int tmp;
            cin >> tmp;
            a[tmp]++;
        }

        int idx = 0;
        int cnt = 0;
        while(b>=0 && idx<1001){
            if(a[idx] > 0){
                a[idx]--;
                b-= idx;
                cnt++;
                continue;
            }
            idx++;
        }
        if(b < 0)
            cnt--;

        cout << "Case #" << i+1 <<": " <<cnt <<endl;
    }
    return 0;
}
