#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    map<char, int> m;
    for(int i = 0; i < survey.size(); i++){
        if(choices[i] == 1) m[survey[i][0]] += 3;
        else if(choices[i] == 2) m[survey[i][0]] += 2;
        else if(choices[i] == 3) m[survey[i][0]] += 1;
        else if(choices[i] == 5) m[survey[i][1]] += 1;
        else if(choices[i] == 6) m[survey[i][1]] += 2;
        else if(choices[i] == 7) m[survey[i][1]] += 3;
    }
    
    if(m['R'] >= m['T']) answer += 'R';
    else answer += 'T';
    if(m['C'] >= m['F']) answer += 'C';
    else answer += 'F';
    if(m['J'] >= m['M']) answer += 'J';
    else answer += 'M';
    if(m['A'] >= m['N']) answer += 'A';
    else answer += 'N';
    return answer;
}
