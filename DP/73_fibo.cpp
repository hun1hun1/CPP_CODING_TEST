#include <vector>

using namespace std;

int solution(int n) {
    vector<int> fibo(n+1, 0);
    fibo[1] = 1, fibo[2] = 1;
    for (int i = 3; i <= n; ++i) {
        fibo[i] = (fibo[i-1] + fibo[i-2]) % 1234567;
    }

    return fibo[n];
}

#include <iostream>

using namespace std;

int main()
{
  cout << solution(3) << endl; //출력값 : 2
  cout << solution(5) << endl; //출력값 : 5
  
  return 0;
}
