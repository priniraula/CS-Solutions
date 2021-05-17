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
  string input;
  cin >> input;
  map<char, int> count;
  for (auto &i: input){
    ++count[i];
  }
  bool yes = true;
  string odd_rev = "";
  if (input.size() % 2){
    bool one_odd = false;
    for (auto &[a, b]: count){
      if (b % 2 && !one_odd){
        one_odd = true;
        string res (b, a);
        odd_rev = res;
      }
      else if (b % 2 && one_odd){
        yes = false;
      }
    }
  }
  else {
    for (auto &[a, b]: count){
      if (b % 2){
        yes = false;
      }
    }
  }
        
  if (yes){
    if (input.size() % 2){
      for (auto &[a, b]: count){
        if (a != odd_rev[0]){
          for (int i = 0; i < b / 2; ++i){
            cout << a;
          }
        }
      }
      cout << odd_rev;
      for (auto itr = count.rbegin(); itr != count.rend(); ++itr){
        if (itr->first != odd_rev[0]){
          for (int i = 0; i < itr->second / 2; ++i){
            cout << itr->first;
          }
        }
      }
    }
    else {
      for (auto &[a, b]: count){
        for (int i = 0; i < b / 2; ++i){
          cout << a;
        }
      }
      for (auto itr = count.rbegin(); itr != count.rend(); ++itr){
        for (int i = 0; i < itr->second / 2; ++i){
          cout << itr->first;
        }
      }
    }
  }
  else {
    cout << "NO SOLUTION\n";
  }
}
