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

long long binPow (long long x, long long y){  
  long long res = 1;
  if (x == 0) return 0; 
  while (y > 0){  
    if (y & 1){  
      res = (res * x) % MAXN;
    }
    y = y >> 1;
    x = (x * x) % MAXN;  
  }  
  return res;  
} 
int main (){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  long long n, ans = 0LL;
  cin >> n;
  cout << binPow(2, n) << "\n";
}
