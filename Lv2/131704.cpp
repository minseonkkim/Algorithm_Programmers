#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> assist;
    int idx = 1;
    for(int i = 0; i < order.size(); i++){
        if(order[i] == idx){
            answer++;
            idx++;
        } else if(order[i] > idx){
            while(idx < order[i]){
                assist.push(idx);
                idx++;
            }
            answer++;
            idx++;
        } else{
            if(assist.top() == order[i]){
                assist.pop();
                answer++;
            } else return answer;
        }
    }
    return answer;
}
