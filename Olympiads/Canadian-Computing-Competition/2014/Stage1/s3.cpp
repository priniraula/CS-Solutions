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

  int _; 
  cin >> _; 
  
  while(_--){
    int sz;
    cin >> sz;

    stack<int> S1, S2;

    for (int i = 0; i < sz; ++i){
      int res; 
      cin >> res;

      S1.push(res);
    }

    int res = 1;
    bool found = false;

    while(!S1.empty() || (!S2.empty() && S2.top() == res)){
      int a = 0;
      if (S1.empty()) {
        a = -1;
      }
      else {
        a = S1.top();
        S1.pop();
      }

      while(!S2.empty() && (S2.top() == res)){
        S2.pop(), ++res;
      }

      if (a != -1){
        if (a == res){
          ++res;
        }
        else {
          S2.push(a);
        }
      }
    }
    if (S2.empty()) {
      cout << "Y\n";
    }
    else {
      cout << "N\n";
    }
  }
}
