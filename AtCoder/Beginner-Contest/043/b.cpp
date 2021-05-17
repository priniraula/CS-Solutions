#include <iostream>
#include <vector>

int main(){
  std::string inp;
  std::cin >> inp;
  std::vector<char>S;

  for (auto &i: inp){
    if (i=='B'){
      if(!S.empty()){
        S.pop_back();
      }
    }
    else{
      S.push_back(i);
    }
  }
  for (auto &i: S) std::cout << i;
  std::cout << "\n";
}
