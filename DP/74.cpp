#include <vector>

using namespace std;

long long solution(int n) {
    vector<int> dp(n+1, 0);
    dp[1] = 1, dp[2] = 2;
    for (int i = 3; i <= n; ++i) {
        dp[i] = (dp[i-1] + dp[i-2]) % 1000000007;
    }

    return dp[n];
}

#include <iostream>

using namespace std;

int main()
{
  cout << solution(4) << endl; //출력값 : 5
  
  return 0;
}
