#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(string p) {
    string answer = "";
    
    // 1.
    if(p == "") return answer;
    
    // 2.
    string u = "", v = "";
    int open = 0, close = 0;
    for(int i = 0; i < p.length(); i++){
        if(p[i] == '(') open++;
        else close++;
        if(open != 0 && open == close){
            u = p.substr(0, i + 1);
            v = p.substr(i + 1);
            break;
        }
    }
    
    // 문자열 u가 올바른 괄호 문자열인지 검사
    bool isRightString = true;
    stack<char> st;
    for(int i = 0; i < u.length(); i++){
        if(u[i] == '(') st.push('(');
        else {
            if(st.size() == 0){
                isRightString = false;
                break;
            }
            st.pop();
        }
    }
    
    // 3.
    if(isRightString){
        v = solution(v);
        answer = u + v;
        return answer;       
    } 
    // 4.
    else{
        answer = "(";
        answer += solution(v);
        answer += ")";
        for(int i = 1; i < u.length() - 1; i++){
            if(u[i] == ')') answer += '(';
            else answer += ')';
        }
        return answer;
    }
}
