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


int toInt (string number){
	int numb = 0;
	while(number.length() > 0){
		if (number.rfind("M", 0) == 0){
			numb += 1000;
			number = number.substr(1);
			continue;
		}
		if (number.rfind("CM", 0) == 0){
			numb += 900;
			number = number.substr(2);
			continue;
		}
		if (number.rfind("D", 0) == 0){
			numb += 500;
			number = number.substr(1);
			continue;
		}
		if (number.rfind("CD", 0) == 0){
			numb += 400;
			number = number.substr(2);
			continue;
		}
		if (number.rfind("C", 0) == 0){
			numb += 100;
			number = number.substr(1);
			continue;
		}
		if (number.rfind("XC", 0) == 0){
			numb += 90;
			number = number.substr(2);
			continue;
		}
		if (number.rfind("L", 0) == 0){
			numb += 50;
			number = number.substr(1);
			continue;
		}
		if (number.rfind("XL", 0) == 0){
			numb += 40;
			number = number.substr(2);
			continue;
		}
		if (number.rfind("X", 0) == 0){
			numb += 10;
			number = number.substr(1);
			continue;
		}
		if (number.rfind("IX", 0) == 0){
			numb += 9;
			number = number.substr(2);
			continue;
		}
		if (number.rfind("V", 0) == 0){
			numb += 5;
			number = number.substr(1);
			continue;
		}
		if (number.rfind("IV", 0) == 0){
			numb += 4;
			number = number.substr(2);
			continue;
		}
		if (number.rfind("I", 0) == 0){
			numb += 1;
			number = number.substr(1);
			continue;
		}
	}
	return numb;
}

string toString (int number){
  string output = "";

  while(number >= 1000) {
    output += "M";
    number -= 1000;
  }
  while(number >= 900) {
    output += "CM";
    number -= 900;
  }
  while(number >= 500) {
    output += "D";
    number -= 500;
  }
  while(number >= 400) {
    output += "CD";
    number -= 400;
  }
  while(number >= 100) {
    output += "C";
    number -= 100;
  }
  while(number >= 90) {
    output += "XC";
    number -= 90;
  }
  while(number >= 50) {
    output += "L";
    number -= 50;
  }
  while(number >= 40) {
    output += "XL";
    number -= 40;
  }
  while(number >= 10) {
    output += "X";
    number -= 10;
  }
  while(number >= 9) {
    output += "IX";
    number -= 9;
  }
  while(number >= 5) {
    output += "V";
    number -= 5;
  }
  while(number >= 4) {
    output += "IV";
    number -= 4;
  }
  while(number >= 1) {
    output += "I";
    number -= 1;
  }

  return output;
}

int main (){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int _; 
  cin >> _;

	while (_-->0){
    string roman, main;

		cin >> roman; 
    main = roman;

		size_t pos = roman.find("+");
		string num1, num2;
		roman.pop_back();

		num1 = roman.substr(0, pos);
		num2 = roman.substr(pos + 1, roman.size());

    string output;
    int sum = toInt(num1) + toInt(num2);

    if (sum > 1000) {
      output = "CONCORDIA CUM VERITATE";
    }
		else {
      output = toString(sum);
    }
		cout << main << output << "\n";
	}
}