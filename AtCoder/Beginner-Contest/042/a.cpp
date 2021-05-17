#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
  vector<int> a (3);
  for (auto &i: a) cin >> i;
  sort(a.begin(), a.end());
  if (a[0]==5 && a[1]==5 && a[2]==7){
    cout << "YES\n";
  }
  else {
    cout << "NO\n";
  }
}
