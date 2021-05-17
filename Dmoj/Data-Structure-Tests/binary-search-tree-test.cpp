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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define DEBUG(x) do { std::cerr << #x << ": " << x << std::endl; } while (0)

constexpr int MAXN = 1e9 + 7;
constexpr int INF = 0x3f3f3f3f;

using ordered_set = tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>;

int main (){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, M, P = 0;
  cin >> N >> M;
  ordered_set S;
  while (N--){
    int res;
    cin >> res;
    S.insert(res);
  }
  while (M--){
    char input;
    int res;
    cin >> input >> res;
    res = P ^ res;
    if (input == 'I'){
      S.insert(res);
    }
    else if (input == 'R'){
      auto itr = S.lower_bound(res - 1);
      if (*itr == res){
        S.erase(itr);
      }
    }
    else if (input == 'S'){
      P = *S.find_by_order(res - 1);
      cout << P << "\n";
    }
    else if (input == 'L'){
      auto itr = S.lower_bound(res - 1);
      if (*itr != res){
        P = -1;
      }
      else {
        P = S.order_of_key(res) + 1;
      }
      cout << P << "\n";
    }
  }
  for (auto &i: S){
    cout << i << " ";
  }
}
