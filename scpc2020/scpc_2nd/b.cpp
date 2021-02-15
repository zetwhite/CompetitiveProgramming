#include <iostream>

using namespace std;
typedef long long ll; 

ll Answer;

ll solve(){
    int n; 
    ll M; 
    cin >> n >> M; 

    ll sum[n+1]; 
    ll value[n+1]; 
    
    value[0] = 0; 
    for(int i = 1; i <= n; i++)
        cin >> value[i]; 
    
    sum[0] = 0; 
    for(int i = 1; i <= n; i++){
        sum[i] = sum[i-1] + value[i]; 
        //cout << "sum [" << i << "] " << sum[i] << endl; 
    }

    ll result = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; i+j <= n; j++){
            ll tmp; 
            if(j == 0)
                tmp = value[i]; 
            else 
                tmp = sum[i+j] - sum[i-1]; 
            //cout << "(" << i << ", " << i + j << ") = " << tmp << endl; 
            if(tmp <= M && result < tmp){
                result = tmp; 
            }
        }
    }
    return result; 
}

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = solve(); 
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}