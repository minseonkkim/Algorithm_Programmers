#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> scov;
    int sum = 0;
    for(int i = 0; i < scoville.size(); i++){
        sum += scoville[i];
        scov.push(scoville[i]);
    }
    while(scov.top() < K){
        answer++;
        int food1 = scov.top();
        scov.pop();
        if(scov.empty()) return -1;
        int food2 = scov.top();
        scov.pop();
        int mix = food1 + food2 * 2;
        scov.push(mix);
        sum += (mix - food1 - food2);
    }
    return answer;
}
