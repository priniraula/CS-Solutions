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

const int MAXN = 1e6 + 10;
const int INF = 0x3f3f3f3f;

using ll = long long;
using ull = unsigned long long;

ll dp [MAXN], pfx [MAXN];
int main (){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int N, A, B, C;
  cin >> N >> A >> B >> C;
  pfx[0] = 0;
  for (int i = 1; i <= N; ++i){
    int res;
    cin >> res;
    pfx[i] = pfx[i - 1] + res;
  }
  int x = 0;
  for (int i = 1; i <= N; ++i){
    ll big = -INF;
    for (int j = x; j < i; ++j){
      ll a = A * (pfx[i] - pfx[j]) * (pfx[i] - pfx[j]), b = B * (pfx[i] - pfx[j]);
      if ((dp[j] + a + b + C) > big){
        big = dp[j] + a + b + C;
        x = j;
      }
      dp[i] = big;
    }
  }
  cout << dp[N] << "\n";
}
