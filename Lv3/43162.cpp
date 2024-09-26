#include <string>
#include <vector>
using namespace std;

bool visited[200];

void dfs(vector<vector<int>>& computers, int idx, int n){
    visited[idx] = true;
    for(int i = 0; i < n; i++){
        if(i == idx) continue;
        if(!visited[i] && computers[idx][i] == 1){
            dfs(computers, i, n);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(computers, i, n);
            answer++;
        }
    }
    
    return answer;
}
