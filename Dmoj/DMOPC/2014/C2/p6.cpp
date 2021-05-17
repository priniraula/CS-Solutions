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

constexpr int MAXN = 100005;
constexpr int INF = 0x3f3f3f3f;
constexpr long long INFLL = 0x3f3f3f3f3f3f3f3f;

class FenwickTree {
public:
  long long tree [MAXN];
  int N;

public: 
  void update (int index, int value) {
    for (int i = index; i <= N; i += i & -i) {
      tree[i] += value;
    }
  }

  long long int sum (int index) {
    long long int sum = 0;
    for (int i = index; i > 0; i -= i & -i) {
      sum += tree[i];
    }
    return sum;
  }

  long long int sum (int left, int right) {
    return sum (right) - sum (left - 1);
  }
};

struct Query {
  int index, mass, left, right;
  long long int result = 0;

  friend bool operator< (const Query &a, const Query &b) {
    return a.mass > b.mass;
  }
};

bool querySort (const Query &a, const Query &b) {
  return a.index < b.index;
}

vector <std::pair <int, int> > masses;
vector <Query> queries;

FenwickTree ft;

int main (){

  cin >> ft.N;

  for (int i = 1; i <= ft.N; ++i) {
    int m;
    cin >> m;
    masses.push_back({m, i});
  }
  
  sort(masses.begin(), masses.end(), std::greater<std::pair<int, int>>());

  int Q;
  cin >> Q;

  for (int i = 1; i <= Q; ++i) {
    int a, b, q;
    cin >> a >> b >> q;

    Query _q;
    _q.index = i;
    _q.left = a;
    _q.right = b;
    _q.mass = q;
    _q.result = 0;
    queries.push_back(_q);
  }

  sort(queries.begin(), queries.end());

  int index = 0;

  for (int i = 0; i < Q; ++i) {
    while (masses[index].first >= queries[i].mass && index < ft.N) {
      ft.update(masses[index].second, masses[index].first);
      ++index;
    }
    queries[i].result = ft.sum(queries[i].left + 1, queries[i].right + 1);
  }

  sort(queries.begin(), queries.end(), querySort);

  for (auto &i: queries) {
    printf("%lld\n", i.result);
  }
}
