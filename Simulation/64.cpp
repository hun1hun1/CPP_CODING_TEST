#include <vector>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

vector<vector<int>> solution(int n) {
    int direction = 0;
    int x = 0, y = 0;
    vector<vector<int>> result(n, vector<int>(n, 0));
    for (int num = 1; num <= n * n; ++num) {
        result[y][x] = num;
        if (y + dy[direction] >= n || x + dx[direction] >= n || y + dy[direction] < 0 || x + dx[direction] < 0 || result[y + dy[direction]][x + dx[direction]] != 0) {
            direction = (direction + 1) % 4;
        }
        x += dx[direction], y += dy[direction];
    }

    return result;
}

#include <iterator>
#include <iostream>

using namespace std;

void print(vector<vector<int>> vec)
{
  for(int i = 0 ; i < vec.size(); i++){
    copy(vec[i].begin(), vec[i].end(), std::ostream_iterator<int>(cout, " "));
    cout << endl;
  }
  
}

int main()
{
    print(solution(3));
    /*
    출력값 :
    1 2 3 
    8 9 4 
    7 6 5
    */
                    
    print(solution(4));
    /*
    출력값: 
    1 2 3 4 
    12 13 14 5 
    11 16 15 6 
    10 9 8 7
    */
  return 0;
}
