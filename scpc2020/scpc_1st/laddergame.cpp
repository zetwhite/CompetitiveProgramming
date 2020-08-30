#include <iostream>
#include <vector> 
#include <algorithm>
#include <queue> 
#include <cstring>
using namespace std;

int Answer;

class Line{
public: 
    short next[2002]; 
    short end[2002]; 
    Line(){
        memset(next, -1, sizeof(short)*2002); 
        memset(end, -1, sizeof(short)*2002); 
    }
}; 

int go(Line* lines, int here, int cursor, int k){
    Line& l = *(lines+here); 
    while(l.next[cursor] == -1 && cursor <= k){
        cursor++; 
    }
    if(cursor > k)
        return here; 
    if(l.end[cursor] != -1)
        return l.end[cursor]; 
    else{   
        int next = l.next[cursor]; 
        int result = go(lines, next, cursor + 1, k); 
        l.end[cursor] = result; 
        return result; 
    }
}


int dfs_go(Line* lines, int here, int goal, int cursor, int k, int count){
    if(go(lines, here, cursor, k) == goal){
        return count; 
    }
    else{
        int cnt1 = dfs_go(lines, here, goal, cursor+1, k, count+1); 
        int cnt2 = 5000; 
        Line& l = *(lines+here); 
        while(l.next[cursor] == -1 && cursor <= k){
            cursor++; 
        }
        if(cursor < k) 
            cnt2 = dfs_go(lines, l.next[cursor], goal, cursor+1, k, count); 
        if(cnt1 < cnt2)
            return cnt1; 
        return cnt2; 
    }
}

int solve(){
    int N, k, m; 
    cin >> N >> k >> m; 
    Line lines[N+1]; 
    int x, y; 
    for(int i = 0; i < k; i++){
        cin >> x >> y; 
        lines[x].next[i] = y; 
        lines[y].next[i] = x; 
    }
    for(int i = 0; i < N; i++){
        // cout << "start at = " << i+1 << ", "; 
        int res = go(lines, i+1, 0, k); 
        // cout << "return result = " << res << endl; 
    }
    int start, end; 
    int result = 0; 

    for(int i = 0; i < m; i++){
        cin >> start >> end; 
        int cnt = dfs_go(lines, start, end, 0, k, 0); 
        if(cnt == 5000)
            result -= 1; 
        else 
            result += cnt; 
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