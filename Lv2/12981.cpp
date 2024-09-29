#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    unordered_map<string, bool> um;
    
    int turn = 1;
    int cnt = 1;
    for(int i = 0; i < words.size(); i++){
        if(um[words[i]] || (i != 0 && words[i - 1][words[i - 1].length() - 1] != words[i][0])){
            answer.push_back(cnt);
            answer.push_back(turn);
            return answer;
        }
        um[words[i]] = true;
        cnt++;
        if(cnt > n) {
            cnt = 1;
            turn++;
        }
    }
    answer.push_back(0);
    answer.push_back(0);
    return answer;
}
