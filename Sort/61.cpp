#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Pos {
    int r;
    int c;
    int heightDiff;
    bool operator<(const Pos &p) const {
        return heightDiff > p.heightDiff;
    }
};

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
bool visited[301][301];

bool isValid(int nr, int nc, int rows, int cols) {
    return nr >= 0 && nr < rows && nc >= 0 && nc < cols && !visited[nr][nc];
}

int solution(vector<vector<int>> land, int height) {
    int totalCost = 0;
    int rows = land.size(), cols = land[0].size();

    priority_queue<Pos> pq;
    pq.push({0, 0, 0});

    while (!pq.empty()) {
        Pos current = pq.top();
        pq.pop();

        if (visited[current.r][current.c]) continue;

        totalCost += current.heightDiff;

        for (int i = 0; i < 4; i++) {
            int nr = current.r + dy[i], nc = current.c + dx[i];
            if (isValid(nr, nc, rows, cols)) {
                int diff = abs(land[current.r][current.c] - land[nr][nc]);

                if (diff > height) pq.push({nr, nc, diff});
                else pq.push({nr, nc, 0});
            }
        }

        visited[current.r][current.c] = true;
    }

    return totalCost;
}

#include <iostream>

using namespace std;

void init()
{
  for(int i = 0 ; i <= 300; i++)
    for(int j = 0; j <= 300; j++)
      visited[i][j] = 0;
}

int main()
{
  cout << solution({{1, 4, 8, 10}, {5, 5, 5, 5}, {10, 10, 10, 10}, {10, 10, 10, 20}}, 3) << endl; //출력값 : 15
  init();
  cout << solution({{10, 11, 10, 11}, {2, 21, 20, 10}, {1, 20, 21, 11}, {2, 1, 2, 1}}, 1) << endl; //출력값 : 18
  
  return 0;
}
