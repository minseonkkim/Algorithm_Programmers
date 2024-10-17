#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dist[20001];
vector<int> graph[20001];

void bfs(){
    queue<int> q;
    dist[1] = 0;
    q.push(1);
    
    while(!q.empty()){
        int x = q.front();
        q.pop();
        
        for(int i = 0; i < graph[x].size(); i++){
            int nxt = graph[x][i];
            if(dist[nxt] != -1) continue;
            dist[nxt] = dist[x] + 1;
            q.push(nxt);
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    for(int i = 0; i < 20001; i++){
        dist[i] = -1;
    }
    
    for(int i = 0; i < edge.size(); i++){
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }
    bfs();
    
    int maxnum = -1;
    int maxcnt = 0;
    for(int i = 1; i <= n; i++){
        if(dist[i] > maxnum){
            maxnum = dist[i];
            maxcnt = 1;
        } else if(dist[i] == maxnum){
            maxcnt++;
        }
    }
    return maxcnt;
}
