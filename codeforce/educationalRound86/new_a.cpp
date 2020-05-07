#include <bits/stdc++.h>
#define ll long long
#define MAX 100000
using namespace std;

int day[MAX] = {0, };
int dummy[MAX] = {0, };
int before[MAX] = {0, };
bool ch[MAX] = {false, };

void update(int& max){
    int idx = max;
    while(1){
        if(ch[idx] == true)
            break;
        for(int i = 0; i <= dummy[idx]; i++){
            int next = idx + i + dummy[idx];
            if(dummy[next] >= dummy[idx] + i)
                break;
            day[next] = day[idx] + 1;
            dummy[next] = dummy[idx] + i;
            before[next] = day[idx];
            ch[idx] = true;
        }
        idx--;
    }
    max = max + dummy[max]*2;
}

void solve(int& max, int n){
    while(1){
        update(max);
        if(max >= n)
            break;
    }
}

int main(){
    int t;
    cin >> t;
    day[1] = 0;
    day[2] = 1;
    day[3] = 1;
    before[2] = 1;
    before[3] = 1;
    dummy[1] = 1;
    dummy[2] = 1;
    dummy[3] = 2;
    ch[1] = true;
    int max = 3;

    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        if(day[n] == 0)
            solve(max, n);
        vector<int> split;
        while(n != 1){
            split.push_back(dummy[n] - dummy[before[n]]);
            n = before[n];
        }
        cout << split.size() << endl;
        for(int i = split.size()-1; i >= 0; i--)
            cout << split[i] << " ";

    }
    return 0;
}
