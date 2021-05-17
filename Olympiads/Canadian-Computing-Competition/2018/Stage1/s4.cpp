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

unordered_map<int, long long int> M;
long long f (int N){
  if (N <= 2){
    return 1;
  }
  if (M[N]) {
    return M[N];
  }
  long long res = 0LL, k = N;

  while (k > 1){
    int next = N / k;
    int sub = N / (next + 1);
    res += (k - sub) * f(next), k = sub;
  }

  M[N] = res; 
  return res;
}

int main (){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int N, res = 0;
  cin >> N;
  cout << f(N) << "\n";
}
