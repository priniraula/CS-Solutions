#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <numeric>
#include <ostream>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

#define DEBUG(x) do { std::cerr << #x << ": " << x << std::endl; } while (0)
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

constexpr int MAXN = 1e2 + 10;
constexpr int INF = 0x3f3f3f3f;
constexpr long long INFLL = 0x3f3f3f3f3f3f3f3f;

char grid [MAXN][MAXN]; 
int N, M, SX, SY, dist [MAXN][MAXN];
int movex [4] = {0, 0, -1, 1 };
int movey [4] = {-1, 1, 0, 0};

bool visited [MAXN][MAXN], gone [MAXN][MAXN];

void printGraph (){
  for (int i = 1; i <= N; ++i){
    for (int j = 1; j <= M; ++j){
      if (grid[i][j] == '.'){
        if (dist[i][j] == INF){
          cout << -1 << "\n";
        }
        else {
            cout << dist[i][j] << "\n";
        }
      }
    }
  }
}

bool isConvoyer (int i, int j){
  return grid[i][j] == 'L' || grid[i][j] == 'R' || grid[i][j] == 'U' || grid[i][j] == 'D';
}

bool safe (int x, int y){
  return x >= 1 && y >= 1 && x <= N && y <= M && !gone[x][y] && grid[x][y] != 'W';
}

void go(){
  priority_queue<pair<int, int>> Q;
  char CON [4] = {'L', 'R', 'U', 'D'};
  if (!gone[SX][SY]) {
    Q.push({SX, SY});
  }

  visited[SX][SY] = 1, dist[SX][SY] = 0;

  while (!Q.empty()){
    int a = Q.top().first, b = Q.top().second;
    Q.pop();
    visited[a][b] = 0;

    for (int k = 0; k < 4; ++k){
      int res1 = a + movex[k], res2 = b + movey[k];
      if (grid[a][b] == '.' || grid[a][b] == 'S' || grid[a][b] == CON[k]){
        if (!safe(res1, res2)) {
          continue;
        }
        int next = dist[a][b] + (grid[a][b] == CON[k] ? 0 : 1); 
        if (dist[res1][res2] > next){
          dist[res1][res2] = next;
          if (!visited[res1][res2]){
            visited[res1][res2] = 1;
            Q.push({res1, res2});
          }
        }
      }
    }
  }
}

int main (){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> N >> M;

  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= M; ++j){
      cin >> grid[i][j];

      if (grid[i][j] == 'S'){
        SX = i, SY = j;
      }
    }
  }  

  memset(dist, INF, sizeof(dist)), memset(visited, 0, sizeof(visited));

  for (int i = 1; i <= N; ++i){
    for (int j = 1; j <= M; ++j){
      if (grid[i][j] == 'C'){
        for (int k = j; k <= M && grid[i][k] != 'W'; ++k){
          if (grid[i][k] == 'S' || grid[i][k] == '.' || grid[i][k] == 'C'){
            gone[i][k] = 1;
          }
        }        

        for (int k = j; k >= 1 && grid[i][k] != 'W'; --k){
          if (grid[i][k] == 'S' || grid[i][k] == '.' || grid[i][k] == 'C'){
            gone[i][k] = 1;
          }
        }

        for (int k = i; k <= N && grid[k][j] != 'W'; ++k){
          if (grid[k][j] == 'S' || grid[k][j] == '.' || grid[k][j] == 'C'){
            gone[k][j] = 1;
          }
        }        

        for (int k = i; k >= 1&& grid[k][j] != 'W'; --k){
          if (grid[k][j] == 'S' || grid[k][j] == '.' || grid[k][j] == 'C'){
            gone[k][j] = 1; 
          }
        }
      }
    }
  }

  go();
  printGraph();
}
