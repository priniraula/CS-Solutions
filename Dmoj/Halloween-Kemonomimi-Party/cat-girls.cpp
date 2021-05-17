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

long long A [MAXN], B[MAXN], C[MAXN];

int main (){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N, start = 1; cin >> N;
  long long W; cin >> W;

  while(N--){
    char a; cin >> a;
    if (a == 'A'){
      int width, cute, value = 0; cin >> width >> cute;
      A[start] = A[start - 1] + cute, B[start] = B[start - 1] + width;
      value = lower_bound(B, B + start + 1, B[start] - W) - B + 1; 
      C[start] = max(C[start - 1], A[start] - A[value - 1]);
      cout << C[start] << "\n";
      ++start;
    }
    else {
      --start;
    }
  }
}
