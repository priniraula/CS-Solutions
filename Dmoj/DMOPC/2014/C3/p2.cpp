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

int main (){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N, wa_count = 0;
  cin >> N;
  vector <string> list (N, "");

  for (auto &i: list) {
    cin >> i;
    if (i == "WA") {
      ++wa_count;
    }
  }

  int wa_to_ac = 0, ir_10_ac = 0, ir_10_wa = 0;
  int wa_to_change = floor(0.3 * wa_count);

  for (auto &i: list) {
    if ((i == "WA") && (wa_to_ac != wa_to_change)){
      ++wa_to_ac;
      cout << "AC" << "\n";
    } 
    else if ((i == "IR") && (ir_10_ac != 10)){
      ++ir_10_ac;
      cout << "AC" << "\n";
    }
    else if ((i == "IR") && (ir_10_wa != 10)){
      ++ir_10_wa;
      cout << "WA" << "\n";
    }
    else if (i == "TLE") {
      cout << "WA" << "\n";
    }
    else {
      cout << i << "\n";
    }
  }
}
