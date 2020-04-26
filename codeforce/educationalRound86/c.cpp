#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

ll gcd(ll a, ll b){
	while(b!=0){
		ll r = a%b;
		a= b;
		b= r;
	}
	return a;
}

ll lcm(ll a, ll b){
    return a * b / gcd(a,b);
}

ll get(ll l, ll b, ll limit){
    ll res = limit/l * (l-b);
    ll additional = (limit%l) - b;
    if(additional >= 0) res += additional + 1;
    return res;
}

void solve(){
    ll a, b, q;
    cin >> a >> b >> q;
    if(a>b)
        swap(a, b);
    ll l = lcm(a, b);

    for(int i = 0; i < q; i++){
        ll st, end;
        cin >> st >> end;
        ll st_cnt = get(l, b, st-1);
        ll end_cnt = get(l, b, end);
        cout << end_cnt - st_cnt << " ";
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
        solve();
    return 0;
}
