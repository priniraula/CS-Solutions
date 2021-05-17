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
  long long n;
  cin >> n;
  long long summa = n * (n + 1) / 2;
  if (summa % 2){
    cout << "NO\n";
    return 0;
  }
  vector <int> a;
  vector <int> b;

  summa /= 2;
  while (n > 0){
    if (summa - n >= 0){
      a.push_back(n);
      summa -= n;
    }
    else {
      b.push_back(n);
    }
    --n;
  }

  cout << "YES\n";
  cout << (int) a.size() << "\n";
  for (auto &i: a) cout << i << " ";
  cout << "\n" << (int) b.size() << "\n";
  for (auto &i: b) cout << i << " ";
  cout << "\n";
}
