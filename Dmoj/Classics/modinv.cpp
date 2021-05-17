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

constexpr int MAXN = 1e5 + 10;
constexpr int INF = 0x3f3f3f3f;
constexpr long long INFLL = 0x3f3f3f3f3f3f3f3f;

unsigned long long x = 0LL, y = 0LL;

void gcd(unsigned long long a, unsigned long long b){
  if (b == 0) {
    x = 1;
    y = 0;
  }
  else {
    gcd(b, a % b);
    unsigned long long res = x;
    x = y;
    y = res - a / b * y;
  }
}

int main (){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  unsigned long long n, m, ans = 0; 
  cin >> n >> m;
  gcd(n % m, m);
  ans = (x + m) % m;

  cout << ans << "\n";
}
