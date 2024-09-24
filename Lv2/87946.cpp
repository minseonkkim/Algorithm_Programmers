#include <string>
#include <vector>

using namespace std;

bool visited[8];
int answer;

void dfs(int cnt, int k, vector<vector<int>>& dungeons){
    if(cnt > answer) answer = cnt;
    
    for(int i = 0; i < dungeons.size(); i++){
        if(!visited[i] && dungeons[i][0] <= k){
            visited[i] = true;
            dfs(cnt + 1, k - dungeons[i][1], dungeons);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    dfs(0, k, dungeons);
    
    return answer;
}
