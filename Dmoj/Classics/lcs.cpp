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

constexpr int MAXN = 1e3 + 7;
constexpr int INF = 0x3f3f3f3f;
constexpr long long INFLL = 0x3f3f3f3f3f3f3f3f;

int dp [MAXN][MAXN];
int A [MAXN], B[MAXN];

int main (){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < N; ++i){
    cin >> A[i];
  }
  for (int i = 0; i < M; ++i){
    cin >> B[i];
  }
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i <= N; ++i){
    for (int j = 0; j <= M; ++j){
      if (i && j){
        if (A[i - 1] == B[j - 1]){
          dp[i][j] = dp[i - 1][j - 1] + 1;
        }
        else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }
  }
  cout << dp[N][M] << "\n";
}
