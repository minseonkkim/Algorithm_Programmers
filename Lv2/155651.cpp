#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int getTime(string s){
    return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));
}

int solution(vector<vector<string>> book_time) {
    vector<pair<int, int>> v;
    for(int i = 0; i < book_time.size(); i++){
        v.push_back({getTime(book_time[i][0]), getTime(book_time[i][1]) + 10});
    }
    sort(v.begin(), v.end());
    
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < v.size(); i++){
        if(!pq.empty() && pq.top() <= v[i].first){
            pq.pop();
        }
        pq.push(v[i].second);
    }
    
    return pq.size();
}
