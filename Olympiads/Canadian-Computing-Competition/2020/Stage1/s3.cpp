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

constexpr int MAXN = 2e5 + 10;
constexpr int BASE = 131;
constexpr int INF = 0x3f3f3f3f;
constexpr long long INFLL = 0x3f3f3f3f3f3f3f3f;

int P [MAXN][26];
int F [26];

unordered_set<unsigned long long> S;

string N, H;

unsigned long long hashH [MAXN];
unsigned long long hashP [MAXN];

void add (int left, int right){
  S.insert((hashH[right] - hashH[left - 1] * hashP[right - left + 1]));
}

int main (){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  N.resize(MAXN);
  H.resize(MAXN);

  cin >> N >> H;

  for (int i = 1; i <= (int) H.size() ; ++i){
    ++F[N[i - 1] - 'a']; 
  }

  hashP[0] = 1;

  for (int i = 1; i <= (int) H.size() ; ++i){
    hashP[i] = hashP[i - 1] * BASE;
    hashH[i] = hashH[i - 1] * BASE + H[i - 1] - 'a';
    ++P[i][H[i - 1] - 'a'];

    for (int j = 0; j < 26; ++j){
      P[i][j] += P[i - 1][j];
    }
  }

  for (int left = 1, right = (int) N.size() ; right <=(int) H.size() ; ++left, ++right){
    bool found = 1;

    for (int i = 0; i < 26; ++i){
      if (P[right][i] - P[left - 1][i] != F[i]){
        found = 0;
        break;
      }
    }

    if (found){
      add(left, right);
    }
  }

  cout << (int) S.size() << "\n";
}
