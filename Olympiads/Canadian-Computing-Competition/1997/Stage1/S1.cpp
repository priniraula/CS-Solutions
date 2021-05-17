#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
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

  int n, a, b, c; 
  cin >> n; 
  string a1 [20], b1 [20], c1[20];

  while (n-->0){
    cin >> a >> b >> c; cin.ignore();

    for (int i = 0; i < a; ++i) {
      getline(cin, a1[i]);
    } 
    for (int i = 0; i < b; ++i) {
      getline(cin, b1[i]);
    }
    for (int i = 0; i < c; ++i) {
      getline(cin, c1[i]);
    }

    for (int i = 0; i < a; ++i){
      for (int j = 0; j < b; ++j){
        for (int k = 0; k < c; ++k){
          cout << a1[i] << " " << b1[j] << " " << c1[k] << ".\n";
        }
      }
    }
    cout << "\n";
  }
}