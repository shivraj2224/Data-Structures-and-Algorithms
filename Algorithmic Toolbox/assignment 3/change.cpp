#include <iostream>

int get_change(int m) {
  //write your code here
    int n=0 ;
    int tens = m/10;
    if(tens >= 1){
        n += tens ;
    }
    m = m - tens*10;
    int fives = m/5 ;
    if(fives >= 1){
        n += fives;
    }
    m = m - fives*5;
    n += m ;

  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
