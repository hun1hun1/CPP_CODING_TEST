#include <iostream>
#include <bitset>

using namespace std;

int solution(int N) {
    return bitset<32>(N).count();

    // int result = 0;
    // while (N != 1) {
    //     if (N % 2 == 1) result++;
    //     N /= 2;
    // }

    // return result + 1;
}

#include <iostream>

using namespace std;

int main()
{
  cout << solution(5) << endl; //출력값 : 2
  cout << solution(6) << endl; //출력값 : 2 
  cout << solution(5000) << endl; //출력값 : 5
  
  return 0;
}
