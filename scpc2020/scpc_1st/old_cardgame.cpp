#include <iostream> 
#include <vector> 
using namespace std; 

int cardX[3003];
int cardY[3003]; 
bool dp[3003][3003]; 

bool getCardFromX(int K, int idxX, int idxY){
    //cout << "getCardFromX [ x = " << idxX << ", y = " << idxY << "]" << endl; 
    bool result = false; 
    int val_minus = 0; 
    while(1){
        val_minus += cardX[idxX]; 
        if(val_minus > K)
            break; 
        idxX--; 
        if(idxX < 0)
            break; 
        if(dp[idxX][idxY] == false){
            result = true; 
            break; 
        }
    }
    //cout << "returns " << result << endl; 
    return result; 
}

bool getCardFromY(int K, int idxX, int idxY) {
    //cout << "getCardFromY [ x = " <<idxX << ", y = " << idxY << "] " << endl; 
    bool result = false;
    int val_minus = 0;  
    while (1){
        val_minus += cardY[idxY]; 
        if(val_minus > K) 
            break; 
        idxY--; 
        if(idxY < 0) 
            break; 
        if(dp[idxX][idxY] == false){
            result = true; 
            break; 
        }
    }
    //cout << "result = " << result << endl; 
    return result; 
}

void solve(int& win, int& lose){
    int N, K; 
    cin >> N >> K;
    win = 0; 
    lose = 0; 
    for(int i = 1; i <= N; i++){
        int x; 
        cin >> x; 
        cardX[i] = x; 
    } 
    for(int i = 1; i <= N; i++){
        int y; 
        cin >> y; 
        cardY[i] = y;  
    }
    for(int i = 0; i <= N; i++){
        for (int j = 0; j <= N; j++){
            if(i == 0 && j == 0) 
                continue; 
            int resultX = getCardFromX(K, i, j); 
            if(resultX == true){
                dp[i][j] = true;
                continue;
            } 
            int resultY = getCardFromY(K, i, j); 
            if(resultY == true){
                dp[i][j] = true; 
                continue;
            }
            dp[i][j] = false; 
        }
    }
    for(int i = 0; i <= N; i++){
        for (int j = 0; j <= N; j++){
            if(dp[i][j])
                win++; 
            else
                lose++; 
        }
    }
}

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	dp[0][0] = true; 
    cardX[0] = 0; 
    cardY[0] = 0; 
	for(test_case = 0; test_case  < T; test_case++)
	{

       int win, lose; 
        solve(win, lose); 
		cout << "Case #" << test_case+1 << endl;
		cout << win << " " << lose << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}