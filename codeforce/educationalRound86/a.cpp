#include <iostream>
#include <cmath>
#include <climits>
#define ll long long
using namespace std;

ll min(ll x, ll y){
    if(x < y)
        return x;
    return y;
}

ll solve(ll x, ll y, ll a, ll b){
    ll res = LLONG_MAX;
    if(y < x)
        swap(x, y);
    res = min(res, (y-x)*a + x*b);
    res = min(res, a*(x+y));
    return res;
}

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        cout << solve(x, y, a, b) << endl;
    }
    return 0;
}
