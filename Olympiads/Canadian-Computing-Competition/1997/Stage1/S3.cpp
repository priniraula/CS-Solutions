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
  int _;
  scanf("%d", &_);
  while(_--){
    int r = 0, u = 0, o = 0, e = 0;
    scanf("%d", &u);
    printf("Round %d: %d undefeated, %d one-loss, %d eliminated\n", r, u, o, e);
    r++;

    while(u >= 2 || o >= 2){
      e += o/2;
      o -= o/2;
      o += u/2;
      u -= u/2;
      printf("Round %d: %d undefeated, %d one-loss, %d eliminated\n", r, u, o, e);
      r++;
    }

    if (u == 1 && o == 1){
      o++;
      u=0;
      printf("Round %d: %d undefeated, %d one-loss, %d eliminated\n", r, u, o, e);
      r++;
      o--;
      e++;
      printf("Round %d: %d undefeated, %d one-loss, %d eliminated\n", r, u, o, e);
    }

    printf("There are %d rounds.\n", r);
  }
}