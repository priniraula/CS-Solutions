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

constexpr int MAXN = 100005;
constexpr int INF = 0x3f3f3f3f;
constexpr long long INFLL = 0x3f3f3f3f3f3f3f3f;

vector <int> vec [MAXN];
std::map <int, int> frequency;

int main (){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  for (int i = 1; i <= MAXN - 1; ++i) {
    for (int j = i; j <= MAXN - 1; j += i) {
      frequency[j]++;
    }
  }

  for (int i = 1; i <= MAXN - 1; ++i) {
    vec[frequency[i]].push_back(i);
  }


  int T;
  cin >> T;

  while (T-->0) {
    int K, A, B;
    cin >> K >> A >> B;

    int value1 = std::upper_bound(vec[K].begin(), vec[K].end(), A - 1) - vec[K].begin();
    int value2 = std::upper_bound(vec[K].begin(), vec[K].end(), B) - vec[K].begin();

    cout << value2 - value1 << "\n";
  }
}
