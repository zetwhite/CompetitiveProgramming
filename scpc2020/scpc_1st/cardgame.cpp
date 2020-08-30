#include <iostream> 
#include <vector> 
using namespace std; 

short cardX[3003];
short cardY[3003]; 
bool dpX[3003][3003]; 
bool dpY[3003][3003]; 
short ddpX[3003][3003]; 
short ddpY[3003][3003]; 

bool getCardFromX(int K, int idxX, int idxY){
    if(idxX == 0) 
        return false;
    
    if(dpX[idxX-1][idxY] == false && dpY[idxX-1][idxY] == false) {
        ddpX[idxX][idxY] = cardX[idxX]; 
        return true; 
    }
    if(dpX[idxX-1][idxY] == true){
        int dist = ddpX[idxX-1][idxY] + cardX[idxX]; 
        if(dist > K)
            return false; 
        else{
            ddpX[idxX][idxY] = dist; 
            return true; 
        }
    }
    return false; 
}

bool getCardFromY(int K, int idxX, int idxY){
    if(idxY == 0) 
        return false;
    if(dpY[idxX][idxY-1] == false && dpX[idxX][idxY-1] == false) {
        ddpY[idxX][idxY] = cardY[idxY]; 
        return true; 
    }
    if(dpY[idxX][idxY-1] == true){
        int dist = ddpY[idxX][idxY-1] + cardY[idxY]; 
        if(dist > K)
            return false; 
        else{
            ddpY[idxX][idxY] = dist; 
            return true; 
        }
    }
    return false; 
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
            dpX[i][j] = getCardFromX(K, i, j); 
            dpY[i][j] = getCardFromY(K, i, j); 
        }
    }
    for(int i = 0; i <= N; i++){
        for (int j = 0; j <= N; j++){
            if(dpX[i][j] || dpY[i][j])
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
	dpX[0][0] = true;
    dpY[0][0] = true; 
    ddpX[0][0] = 3003;  
    ddpY[0][0] = 3003; 
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