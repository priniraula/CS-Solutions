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

constexpr int MAXN = 1e9 + 7;
constexpr int INF = 0x3f3f3f3f;
constexpr long long INFLL = 0x3f3f3f3f3f3f3f3f;

int grid [4][4];
bool visited [4];

bool isCycle (int i, int parent) {
  visited[i] = true;
  for (int j = 0; j < 4; ++j) {
    if (grid[i][j]) {
      if (!visited[j]) {
        if (isCycle (j, i)) {
          return true;
        }
      }
      else if (j != parent) {
        return true;
      }
    }
  }
  return false;
}

bool isTree () {
  if (isCycle(0, -1)) {
    return false;
  }

  for (int i = 0; i < 4; ++i) {
    if (!visited[i]) {
      return false;
    }
  }
  return true;
}

int main (){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      cin >> grid[i][j];
    }
  }

  memset(visited, false, sizeof visited);

  if (isTree()) {
    cout << "Yes" << "\n";
  }
  else {
    cout << "No" << "\n";
  }
}
