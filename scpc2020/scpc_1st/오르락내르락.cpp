#include <iostream>
#include <cstring> 
#include <vector> 
using namespace std;

int Answer;
int* dp; 
int* sum; 

void fill(){
    dp[0] = 0; 
    dp[1] = 0; 
    dp[2] = 1; 
    sum[0] = 0; 
    sum[1] = 0; 
    sum[2] = 1; 
    for(int i = 4; i <= 1000'000; i=i+2){
        dp[i] = dp[i/2] + 1; 
        dp[i-1]  = dp[i] + 1; 
        sum[i-1] = sum[i-2] + dp[i-1]; 
        sum[i] = sum[i-1] + dp[i]; 
    }
}


int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

	int T, test_case;
    dp = new int[1000'005]; 
    sum = new int[1000'005]; 
    fill(); 


	cin >> T;
    int n1, n2; 
	for(test_case = 0; test_case  < T; test_case++)
	{
        cin >> n1 >> n2; 
        Answer = sum[n2] - sum[n1-1]; 
		cout << "Case #" << test_case+1 << "\n";
		cout << Answer << "\n";
	}

	return 0;//Your program should return 0 on normal termination.
}