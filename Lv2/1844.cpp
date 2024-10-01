#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int visited[100][100];

int bfs(vector<vector<int>>& maps){
    int n = maps.size();
    int m = maps[0].size();
    
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = 1;
    
    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        
        if(cx == n - 1 && cy == m - 1) 
            return visited[cx][cy];
        
        for(int i = 0; i < 4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if(nx < 0 || ny < 0 || nx == n || ny == m) continue;
            if(visited[nx][ny] > 0 || maps[nx][ny] == 0) continue;
            
            visited[nx][ny] = visited[cx][cy] + 1;
            q.push({nx, ny});
        }
    }
    return -1;
}

int solution(vector<vector<int>> maps)
{
    return bfs(maps);
}
