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

vector <pair <int, int> > arr;

double divide (int a, int b, int x, int y){
  return ((double)abs(b - y) / (double)(abs(a - x)));
}

constexpr int MAXN = 1e9 + 7;
constexpr int INF = 0x3f3f3f3f;
constexpr long long INFLL = 0x3f3f3f3f3f3f3f3f;

int main (){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N; 
  double ans = 0.0;  
  cin >> N; 
  arr.resize(N); 

  for (auto &i: arr){
    cin >> i.first >> i.second;
  }
  sort(arr.begin(), arr.end());

  for (int i = 1; i < N; ++i){
    pair<int, int> previous = arr[i - 1];
    ans = max(ans, divide(previous.first, previous.second, arr[i].first, arr[i].second));
  }
  cout << setprecision(10) << fixed << ans << "\n";
}
