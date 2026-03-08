#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> arr) {
    int n = arr[0].size();

    vector<vector<int>> dp(4, vector<int>(n, 0));

    dp[0][0] = arr[0][0];
    dp[1][0] = arr[1][0];
    dp[2][0] = arr[2][0];
    dp[3][0] = arr[0][0] + arr[2][0];

    for (int i = 1; i < n; ++i) {
        dp[0][i] = arr[0][i] + max(dp[1][i-1], dp[2][i-1]);
        dp[1][i] = arr[1][i] + max({dp[0][i-1], dp[2][i-1], dp[3][i-1]});
        dp[2][i] = arr[2][i] + max(dp[0][i-1], dp[1][i-1]);
        dp[3][i] = arr[0][i] + arr[2][i] + dp[1][i-1];
    }

    return max({dp[0][n-1], dp[1][n-1], dp[2][n-1], dp[3][n-1]});
}

#include <iostream>

using namespace std;

int main()
{
  cout << solution({{1, 3, 3, 2}, {2, 1, 4, 1}, {1, 5, 2, 3}}) << endl; //출력값 : 19
  cout << solution({{1, 7, 13, 2, 6}, {2, -4, 2, 5, 4}, {5, 3, 5, -3, 1}}) << endl; //출력값 : 32
  
  return 0;
}
