#include <string>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

bool visited[100][100];
int answer = 987654321;

void bfs(vector<string>& board, int sx, int sy){
    queue<pair<pair<int, int>, int>> q;
    q.push({{sx, sy}, 0});
    visited[sx][sy] = true;
    
    while(!q.empty()){
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int ccnt = q.front().second;
        q.pop();
        
        if(board[cx][cy] == 'G'){
            answer = min(answer, ccnt);
            break;
        }
        
        for(int i = 0; i < 4; i++){
            int nx = cx + dx[i], ny = cy + dy[i];
            if(nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].size() || board[nx][ny] == 'D') continue;
            while(true){
                nx += dx[i];
                ny += dy[i];
                
                if(nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].size() || board[nx][ny] == 'D'){
                    nx -= dx[i];
                    ny -= dy[i];
                    break;
                }
            }
            if(visited[nx][ny]) continue;
            
            q.push({{nx, ny}, ccnt + 1});
            visited[nx][ny] = true;
        }
    }
}

int solution(vector<string> board) {
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].length(); j++){
            if(board[i][j] == 'R'){
                bfs(board, i, j);
                break;
            }
        }
    }
    if(answer == 987654321) return -1;
    else return answer;
}
