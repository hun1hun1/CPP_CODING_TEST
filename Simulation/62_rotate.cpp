#include <vector>

using namespace std;

void rotate_vector(vector<vector<int>>& arr, int n) {
    int size = arr.size();
    for (int i = 0; i < n; ++i) {
        for (int r = 0; r < size / 2; ++r) {
            for (int j = 0; j < size - 1 - 2 * r; ++j) {
                int d0 = arr[r][j+r], d1 = arr[j+r][size - 1 - r], d2 = arr[size - 1 - r][size - 1 - j - r], d3 = arr[size - 1 - j - r][0 + r];
                arr[r][j+r] = d3, arr[j+r][size - 1 - r] = d0,
                arr[size - 1 - r][size - 1 - j - r] = d1, arr[size - 1 - j - r][0 + r] = d2;
            }
        }
    }
}

vector<vector<int>> solution(vector<vector<int>> arr, int n) {
    rotate_vector(arr, n);
    return arr;
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
  print(solution({
                   {1, 2, 3, 4},
                   {5, 6, 7, 8},
                   {9, 10, 11, 12},
                   {13, 14, 15, 16}
                 }, 1));
  /*
    출력값
    13 9 5 1 
    14 10 6 2 
    15 11 7 3 
    16 12 8 4 
  */
  
  print(solution({
                   {1, 2, 3, 4},
                   {5, 6, 7, 8},
                   {9, 10, 11, 12},
                   {13, 14, 15, 16}
                 }, 3));
  /*
    출력값
    4 8 12 16 
    3 7 11 15 
    2 6 10 14 
    1 5 9 13 
  */
             
  return 0;
}
