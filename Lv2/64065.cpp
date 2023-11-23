#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int> b){
    if(a.size() < b.size()) return true;
    return false;
}


vector<int> solution(string s) {
    vector<int> answer;
    
    vector<vector<int>> v;
    vector<int> tmp;
    bool start = false;
    string t = "";
    for(int i = 1; i < s.length() - 1; i++){
        char c = s[i];
        if(c == '{') {
            start = true;
        } else if(c == '}'){
            tmp.push_back(stoi(t));
            t = "";
            v.push_back(tmp);
            start = false;
            tmp.clear();
        } else if(isdigit(c) && start){
            t += c;
        } else if(c == ',' && start){
            tmp.push_back(stoi(t));
            t = "";
        }
    }
    sort(v.begin(), v.end(), cmp);
    
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].size(); j++){
            if(find(answer.begin(), answer.end(), v[i][j]) == answer.end()){
                answer.push_back(v[i][j]);
            }
        }
    }
    return answer;
}
