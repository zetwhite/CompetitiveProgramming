#include <iostream>
#include <cmath>
using namespace std;

double Answer;

double solve(){
    int R, start, end; 
    cin >> R >> start >> end; 

    int N; 
    cin >> N; 
    double distance = end - start; 
    int result = 0; 
    int right, left, height; 
    for(int i = 0; i < N; i++){
        cin >> right >> left >> height; 
        if(height > R) {
            distance += (height-R)*2; 
            distance += R*M_PI; 
            distance -= R*2; 
        }
        else{
            double _h = R - height; 
            double angle = acos(double(_h)/R); 
            distance += angle*R*2;
            distance -= sqrt(R*R - _h*_h)*2; 
        } 
    }
    return distance; 
}

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = solve(); 
        cout << fixed;
        cout.precision(9);
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}