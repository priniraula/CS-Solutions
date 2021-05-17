#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int  main(){
  int n, k;
  cin >> n >> k;
  vector<int>no (k);
  for (auto &i: no) cin >> i;
  sort(no.begin(),no.end());
  auto chzk = [&](int k) -> bool{
    while(k>0){
      int dig=k%10;
      if(binary_search(no.begin(), no.end(), dig)) return false;
      k/=10;
    }
    return true;
  };
  while(true){
    if(chzk(n)){
      cout << n;
      break;
    }
    ++n;
  }
}
