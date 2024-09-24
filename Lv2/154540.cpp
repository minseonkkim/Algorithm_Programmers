#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

bool visited[100][100];
int n, m;


int bfs(vector<string>& maps, int sx, int sy){
    int sum = 0;
    queue<pair<int, int>> q;
    q.push({sx, sy});
    visited[sx][sy] = true;
    
    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        sum += (maps[cx][cy] - '0');
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(visited[nx][ny] || maps[nx][ny] == 'X') continue;
            
            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }
    return sum;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    n = maps.size();
    m = maps[0].length();
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visited[i][j] && maps[i][j] != 'X'){
                int day = bfs(maps, i, j);
                answer.push_back(day);
            }
        }
    }
    if(answer.size() == 0) answer.push_back(-1);
    sort(answer.begin(), answer.end());
    return answer;
}
