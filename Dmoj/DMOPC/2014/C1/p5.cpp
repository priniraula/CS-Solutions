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

constexpr int MAXN = 1e3 + 10;
constexpr int INF = 0x3f3f3f3f;
constexpr long long INFLL = 0x3f3f3f3f3f3f3f3f;

char grid[MAXN][MAXN];
int dist[MAXN][MAXN], row, col;

int X [4] = {1, 0, -1, 0};
int Y [4] = {0, 1, 0, -1};


bool is_valid (int x, int y){
  return x >= 0 && y >= 0 && x < row && y < col && grid[x][y] != 'X'; 
}


int dijk (int x, int y){
  queue<pair<int, int>> Q;
  Q.push({x, y});
  dist[x][y] = 0;
    
  while (!Q.empty()){
    x = Q.front().first, y = Q.front().second;
    if (grid[x][y] == 'E'){
      return dist[x][y];
    }
    Q.pop();

    for (int i = 0; i < 4; ++i){
      int a = x + X[i], b = y + Y[i];
      if (is_valid(a, b)){
        if (dist[a][b] == -1){
          dist[a][b] = dist[x][y] + 1;
          Q.push({a, b});
        }
      }
    }

  }
  return -1;
} 

int main (){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int xs, ys, xe, ye, teleport;
  cin >> row >> col >> xs >> ys >> xe >> ye;
  
  for (int i = 0; i < row; ++i){
    for (int j = 0; j < col; ++j){
      cin >> grid[i][j];
      dist[i][j] = -1;
    }
  }

  grid[xs][ys] = 'O';
  grid[xe][ye] = 'E';
  
  int one = dijk(xs, ys);

  for (int i = 0; i < row; ++i){
    for (int j = 0; j < col; ++j){
      dist[i][j] = -1;
    }
  }

  grid[xe][ye] = 'O';

  cin >> teleport;
  while (teleport--){
    int r1, r2;
    cin >> r1 >> r2;
    grid[r1][r2] = 'E';
  } 

  int two = dijk(xs, ys);
  cout << one - two << "\n";
}
