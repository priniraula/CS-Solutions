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

int x [MAXN], y[MAXN];
int main() {
  int _;
  cin >> _;
  while(_-->0){
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
      cin>> x[i];
    }

    for (int i = 0; i < n; ++i) {
      cin>> y[i];
    }

    int a = 0, b = 0, c = 0, MAX = 0;
    while (a < n && b < n){
      if (y[b] >= x[a]){
        c = b - a;
        if (c > MAX) {
          MAX = c;
        }
        ++b;
      }
      else {
        ++a;
      }
    }
    cout << "The maximum distance is " << MAX << "\n";
  }
}