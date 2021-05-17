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

constexpr int MAXN = 1e7 + 7;
constexpr int INF = 0x3f3f3f3f;

int A [MAXN];
double B [MAXN];
int main (){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int N;
  cin >> N;
  for (int i = 1; i <= N; ++i){
    cin >> A[i];
  }
  if (A[1] == A[N]){
    cout << 1.0 << "\n";
  }
  else {
    double ans = 0.0;
    map<int, int> Q;
    Q[A[N]] = N;
    for (int i = N - 1; i > 1; --i){
      if (A[i] == A[1]){
        B[i] = 1.0;
      }
      else if (Q[A[i]]){
        B[i] = B[Q[A[i]]];
      }
      else {
        B[i] = (ans + 1) / (N - i + 1);
      }
      Q[A[i]] = i;
      ans += B[i];
    }
    ans = 0;
    for (int i = 1; i <= N; ++i){
      ans += B[i];
    }
    cout << setprecision(10) << fixed << (ans + 1) / N << "\n";
  }
}
