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

vector <string> parse_string (std::string to_parse, std::string delimiter) {
  size_t position = 0;
  vector <string> content;
  string token;

  while ((position = to_parse.find(delimiter)) != std::string::npos) {
    token = to_parse.substr(0, position);

    if (!token.empty()) {
      content.push_back(token);
    }
    to_parse.erase(0, position + delimiter.length());
  }

  if (!to_parse.empty()) {
    content.push_back(to_parse);
  }

  return content;
}

int main (){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int L;
  cin >> L;
  string c;
  cin >> c;

  vector <string> content = parse_string(c, "X");
  cout << content.size() << "\n";

  if (!content.empty()) {
    for (auto &i: content) {
      cout << i << "\n";
    }
  }
}
