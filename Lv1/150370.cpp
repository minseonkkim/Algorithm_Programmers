#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    int today_num = stoi(today.substr(0, 4)) * 12 * 28 + stoi(today.substr(5, 7)) * 28 + stoi(today.substr(8, 10));
    
    map<string, int> m;
    for(int i = 0; i < terms.size(); i++){
        m[terms[i].substr(0, 1)] = stoi(terms[i].substr(2));
    }
    
    for(int i = 0; i < privacies.size(); i++){
        int priv_num = stoi(privacies[i].substr(0, 4)) * 12 * 28 + stoi(privacies[i].substr(5, 7)) * 28 + stoi(privacies[i].substr(8, 10));
        if(priv_num + m[privacies[i].substr(11)] * 28 <= today_num){
            answer.push_back(i + 1);
        }
    }
    
    
    return answer;
}
