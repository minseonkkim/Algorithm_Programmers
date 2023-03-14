#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

vector<string> split(string input, char delimiter);

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    map<string, string> m;
    for(int i = 0; i < record.size(); i++){
        vector<string> v = split(record[i], ' ');
        if(v[0] == "Enter" || v[0] == "Change"){
            m[v[1]] = v[2];
        } 
    }
    
    for(int i = 0; i < record.size(); i++){
        vector<string> v = split(record[i], ' ');
        if(v[0] == "Enter"){
            answer.push_back(m[v[1]] + "님이 들어왔습니다.");
        } else if(v[0] == "Leave"){
            answer.push_back(m[v[1]] + "님이 나갔습니다.");
        }
    }

    return answer;
}

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
 
    return answer;
}
