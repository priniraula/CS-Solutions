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

typedef std::pair<int, std::pair<std::string, int>> pair_t;

vector <pair_t> skills_user;

bool compare (pair_t pair1, pair_t pair2) {
  if (pair1.first == pair2.first) {
    return pair1.second.second < pair2.second.second;
  }
  return pair1.first < pair2.first;
}

int main (){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N;
  cin >> N;
  skills_user.resize(N);

  for (int i = 0; i < N; ++i) {
    string name;
    int skill;
    cin >> name >> skill;
    skills_user.push_back({skill, {name, i}});
  }

  sort(skills_user.begin(), skills_user.end(), compare);

  int Q;
  cin >> Q;

  while (Q-->0) {
    int S, D;
    bool found = false;
    cin >> S >> D;

    for (auto &i: skills_user) {
      if (i.first >= S && i.first <= D + S) {
        cout << i.second.first << "\n";
        found = true;
        break;
      }
    }

    if (!found) {
      cout << "No suitable teacher!" << "\n";
    }
  }
}
