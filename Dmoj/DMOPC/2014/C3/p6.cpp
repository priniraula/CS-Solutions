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

int cost [2010][3], worth [2010][3];
int dp [10010];

int main (){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N, T;
  cin >> N >> T;

  dp[0] = 0;

  for (int i = 1; i <= N; ++i) {
    for (int j = 0; j < 3; ++j) {
      cin >> cost[i][j] >> worth[i][j];
    }
  }

  for (int i = 1; i <= N; ++i) {
    for (int j = T; j >= 0; --j) {
      for (int k = 0; k < 3; ++k) {
        if (j >= cost[i][k]) {
          dp[j] = std::max (dp[j], dp[j - cost[i][k]] + worth[i][k]);
        }
      }
    }
  }

  cout << dp[T] << "\n";
}
