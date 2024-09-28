#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dp[500][500];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int n = triangle.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < triangle[i].size(); j++){
            if(i == 0) dp[i][j] = triangle[i][j];
            else if(j == 0){
                dp[i][j] = triangle[i][j] + dp[i - 1][0];
            } else if(j == triangle[i].size() - 1){
                dp[i][j] = triangle[i][j] + dp[i - 1][triangle[i - 1].size() - 1];
            } else{
                dp[i][j] = triangle[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        if(dp[n - 1][i] > answer) {
            answer = dp[n - 1][i];
        }
    }
    return answer;
}
