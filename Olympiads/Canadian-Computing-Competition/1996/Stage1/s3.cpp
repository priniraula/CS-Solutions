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

void patterns (int n, int k){
  cout << "The bit patterns are\n";
  deque<string>p; 

  string pos (n-k, '0'); 
  string concat (k, '1'), a; 
  pos += concat;

  do {
    a = "";

    for (auto i: pos) {
      a += i;
    }

    p.push_front(a);
  } while (next_permutation(pos.begin(), pos.end()));

  for (auto i:p) {
    cout << i << "\n"; 
    cout << "\n";
  }
}

int main (){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int _, n, k;
    cin >> _;
    while (_-->0){
      cin >> n >> k;
      patterns(n, k);
    }
}