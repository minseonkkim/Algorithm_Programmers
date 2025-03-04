#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> edge[51];
int dist[51];

void dijkstra(){
    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});
    dist[1] = 0;
    
    while(!pq.empty()){
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        for(int i = 0; i < edge[cur].size(); i++){
            int next = edge[cur][i].first;
            int ncost = edge[cur][i].second;
            
            if(dist[next] > cost + ncost){
                dist[next] = cost + ncost;
                pq.push({-dist[next], next});
            }
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    fill(dist, dist + 51, 987654321);

    for(int i = 0; i < road.size(); i++){
        int a = road[i][0];
        int b = road[i][1];
        int d = road[i][2];
        edge[a].push_back({b, d});
        edge[b].push_back({a, d});
    }

    dijkstra();
    
    for(int i = 1; i <= N; i++){
        if(dist[i] <= K) answer++;
    }
    return answer;
}
