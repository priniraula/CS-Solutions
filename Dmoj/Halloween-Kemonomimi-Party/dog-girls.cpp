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
constexpr int MAXM = 5005;
constexpr int BASE = 31;
constexpr int INF = 0x3f3f3f3f;
constexpr long long INFLL = 0x3f3f3f3f3f3f3f3f;

unsigned long long hasharr [MAXM], power [MAXM];
int dp [MAXM];

void do1 (string S){
  int N = (int) S.length(); power[0] = 1;
  for (long long i = 1; i <= N; ++i){
    power[i] = power[i - 1] * BASE % MAXN; 
    hasharr[i] = (hasharr[i - 1] * BASE + (S[i - 1] - 'a') + 1) % MAXN;
  }
} 

unsigned long long do3 (long long left, long long right){
  return (hasharr[right] - (hasharr[left - 1] * power[right - left + 1] % MAXN) + MAXN) % MAXN;
}

void do2 (string S){
  int N = (int)S.length(); set<long long> SET;
  for (int i = 1; i <= N/2; ++i){
    memset(dp, 0, sizeof(dp));

    for (int j = i * 2; j <= N; ++j){
      long long one = do3(j - i + 1, j), two = do3(j - (i * 2) + 1, j - i);
      if (one == two){
        dp[j] = dp[j - i] + 1;
      }
    }

    for (int j = 0; j <= N; ++j){
      if (dp[j]){
        SET.insert(do3(j - i * dp[j], j));
      }
    }
  }
  cout << (int) SET.size() << "\n";
}

int main (){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  string w; cin >> w;
  do1(w);
  do2(w);
}
