#include <string>
#include <vector>
using namespace std;

string solution(string s) {
    for(int i = 0; i < s.length(); i++){
        if(!isalpha(s[i])) continue;
        if(i == 0 || s[i - 1] == ' ') s[i] = toupper(s[i]);
        else s[i] = tolower(s[i]);
    }
    return s;
}
