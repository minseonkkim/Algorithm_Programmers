#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    string num[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    string str[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    for(int i = 0; i < 10; i++){
        while(s.find(str[i]) != -1){
            s.replace(s.find(str[i]), str[i].length(), num[i]);
        }
    }
    int result = stoi(s);
    return result;
}
