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

int month_list [12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isLeapYear (int year){
  return year % 4 == 0 && year % 100 != 0;
}

int main (){
  int x1, x2, y1, y2;
  int year, month, days, hours, mins, secs;

  scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
  scanf("%d:%d:%d:%d:%d:%d", &year, &month, &days, &hours, &mins, &secs);
  
  int dist = abs(x2 - x1) + abs(y2 - y1);

  while (dist--){
    ++secs;
    bool leap = isLeapYear(year);
    if (secs == 60){
      secs = 0;
      ++mins;
    }
    if (mins == 60){
      mins = 0;
      ++hours;
    }
    if (hours == 24){
      hours = 0;
      ++days;
    }
    if (days >  month_list[month - 1] && !leap){
      days = 1;
      ++month;
    }

    if (leap && days > month_list[month - 1] + 1 && month == 2){
      days = 1;
      ++month;
    }

    if (month > 12){
      month = 1;
      ++year;
    }
  } 
  printf("%d:%02d:%02d:%02d:%02d:%02d", year, month, days, hours, mins, secs);
}

