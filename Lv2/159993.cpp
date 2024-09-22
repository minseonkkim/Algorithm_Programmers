#include <string>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int solution(vector<string> maps) {
    int answer = 0;
    
    char map[100][100];
    int visited[100][100];
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            visited[i][j] = -1;
        }
    }
    int n = maps.size();
    int m = maps[0].length();
    int sx, sy, lx, ly;
    for(int i = 0; i < maps.size(); i++){
        for(int j = 0; j < maps[i].length(); j++){
            map[i][j] = maps[i][j];
            if(map[i][j] == 'S'){
                sx = i;
                sy = j;
            }
        }
    }
    
    queue<pair<int, int>> q;
    q.push({sx, sy});
    visited[sx][sy] = 0;
    // 시작 ~ 레버
    bool flag = false;
    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        
        if(map[cx][cy] == 'L'){
            lx = cx;
            ly = cy;
            answer += visited[cx][cy];
            flag = true;
            break;
        }
        
        for(int i = 0; i < 4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(visited[nx][ny] != -1 || map[nx][ny] == 'X') continue;
            
            visited[nx][ny] = visited[cx][cy] + 1;
            q.push({nx, ny});
        }
    }
    if(!flag) return -1;
    
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            visited[i][j] = -1;
        }
    }
    queue<pair<int, int>> q2;
    q2.push({lx, ly});
    visited[lx][ly] = 0;
    
    // 레버 ~ 출구
    flag = false;
    while(!q2.empty()){
        int cx = q2.front().first;
        int cy = q2.front().second;
        q2.pop();
        
        if(map[cx][cy] == 'E'){
            answer += visited[cx][cy];
            flag = true;
            break;
        }
        
        for(int i = 0; i < 4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(visited[nx][ny] != -1 || map[nx][ny] == 'X') continue;
            
            visited[nx][ny] = visited[cx][cy] + 1;
            q2.push({nx, ny});
        }
        
    }
    if(!flag) return -1;
    return answer;
}
