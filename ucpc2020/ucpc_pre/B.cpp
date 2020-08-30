#include <iostream>
#include <cmath>
#include <vector> 
#include <string> 
using namespace std; 

typedef long long ll; 

string patterns[1000010]; 
//-2-4-6-8-11-14-17...(a)
//1-3-5-7-9-12-15-1... (b)
//1-3-5-7-10-13-16-... (c)
ll pattt[1000'030][3]; 
string results[3] = {"-2-4-6-8-11-14-17...", "1-3-5-7-9-12-15-1...", "1-3-5-7-10-13-16-..."}; 


//자리수 구하는 함수 
int getSpace(int n){
    int i = 0; 
    while(n > 0){
        i++; 
        n /= 10; 
    }
    return i; 
}

//( a * b^10 ) mod k 해주는 함수 
int getLeft(int a, int b, int k) { 
    long long left = a % k; 
    for(int i = 0; i < b; i++){
        left = left*10; 
        left = left%k; 
    }
    return int(left);  
}

//n자리에 들어갈 패턴을 구해주는 함수, pattern은 n-1자리용 패턴 (즉, len(pattern) == n)
string getNextPattern(int n){
   // cout << "==============" << n << "===============" << endl; 

    string next(n+1, '0'); 
    int left = getLeft(1, (n-1), n);
    for(int i = 0;i < n; i++){
        int _left = (left + i)%n;  
        next[i+1] = patterns[n-1][_left]; 
    }
    next[0] = next[n]; 

    left = getLeft(1, (n-1), n+1); 
    string shiftResult(n+1, '0'); 
    for(int i = 0; i <= n; i++){
        int _left = (left + i) % (n+1); 
        shiftResult[_left] = next[i]; 
    }
    patterns[n] = shiftResult; 
    cout << "nextStart = " << next << endl; 
    cout << "modResult = " << shiftResult << endl; 
    return patterns[n]; 
}

void fillPattern(int max_space){
    patterns[2] = "bca"; 
    for(int i = 3; i <= max_space; i++){
        getNextPattern(i); 
    }
    return; 
}


void printSeq(int group, int end){
    string groups[3] = {"1-3-5-7-9-12-15-18-21", 
     "1-3-5-7-10-13-16-19-22", "-2-4-6-8-11-14-17-20"};

    for(int i = 0; i< end; i++){
        cout << groups[group][i]; 
    } 
    cout << "\n"; 
}

void solve(int a, int b, int k){
    if(b <= 2 && (a*int(pow(10, b)) <= 20 )){
        int n = a * int(pow(10, b)); 
        if(n < 10 && n%2 == 1){
            printSeq(0, n);   
        }
        else if(n < 10 && n%2 ==0){
            printSeq(2, n); 
        }
        else if(n>=10 && n%3 == 0){
            printSeq(0, n); 
        }
        else if(n>=0 && n%3 == 1){
            printSeq(1, n); 
        }
        else 
            printSeq(2, n); 
    }
    else{
        //cout << "k = " << k << endl; 
        int left = getLeft(a, b, k+1); 
        int res = patterns[k][left]; 
        //cout << "result = " << char(res) << endl; 
        cout << results[res - 'a'] << "\n"; 
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    int T ; 
    cin >> T; 
    vector<int> as, bs, space; 
    as.reserve(T); 
    bs.reserve(T);  
    space.reserve(T);  

    int max_space = 5; 
    for(int i = 0; i < T; i++){
        int a, b; 
        cin >> a >> b; 
        as.push_back(a); 
        bs.push_back(b); 
        int tmp = getSpace(a) + b; 
        if(max_space < tmp)
            max_space = tmp; 
        space.push_back(getSpace(a) + b); 
    }

    fillPattern(max_space); 
    for(int i = 2; i <= max_space; i++){
        cout << i << "th = > " << patterns[i] << endl;  
    }
    for(int i = 0; i < T; i++){
        solve(as[i], bs[i], space[i]); 
    }
    return 0; 
}