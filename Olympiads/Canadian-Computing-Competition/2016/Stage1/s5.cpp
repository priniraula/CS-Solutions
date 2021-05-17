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

constexpr int MAXN = 1e6 + 10;
constexpr int INF = 0x3f3f3f3f;
constexpr long long INFLL = 0x3f3f3f3f3f3f3f3f;

int A [MAXN], B[MAXN];

int main (){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N; 
  cin >> N;

  long long T; 
  cin >> T;

  for (int i = 0; i < N; ++i) {
    char h; 
    cin >> h; 

    A[i] = h - '0';
  } 

  for (int i = 0; i < 50; ++i){
    if (T & (1LL << i)){

      for (int j = 0; j < N; ++j){
        unsigned long long Q = ((j - (1LL << i) % N) + N) % N, P = (j + (1LL << i)) % N; 
        B[j] = A[Q] ^ A[P];
      }
      copy(B, B + N, A);
    }
  }

  for (int i = 0; i < N; ++i) {
    cout << B[i];
  }

  cout << "\n";
}
