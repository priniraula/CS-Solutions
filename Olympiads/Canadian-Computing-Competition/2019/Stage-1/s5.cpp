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

const int MAXN = 3e3+ 10;
const int INF = 0x3f3f3f3f;

using ll = long long;
using ull = unsigned long long;

int A [MAXN][MAXN], N;
namespace BIT {
  int tree [MAXN][MAXN];
  int get (int x, int y){
    int maxn = 0;
    for (; x != 0; x -= x & -x){
      for (int i = N - y + 1; i != 0; i -= i & -i){
        maxn = max(maxn, tree[x][i]);
      }
    }
    return maxn;
  }
  void update (int x, int y, int sz){
    for (; x <= N; x += x & - x){
      for (int i = N - y + 1; i <= N; i += i & -i){
        tree[x][i] = max(sz, tree[x][i]);
      }
    }
  }
}
int main (){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int K; cin >> N >> K;
  for (int i = 1; i <= N; ++i){
    for (int j = 1; j <= i; ++j){
      cin >> A[i][j];
    }
  }
  ll summ = 0LL;
  for (int i = N; i >= 1; --i){
    for (int j = i, k = 1; j <= N; ++j, ++k){
      BIT::update(j, k, A[j][k]);
    }
    for (int j = i, k = 1; j <= N; ++j, ++k){
      if (j + K - 1 <= N){
        summ += BIT::get(j + K - 1, k);
      }
    }
  }
  cout << summ << "\n";
}
