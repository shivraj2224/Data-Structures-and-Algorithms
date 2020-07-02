#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  //write your code here
  int k = 1 ;
  int total = n;
  int sum = 0;

  if(n == 0 ){
      summands.push_back(n);
      return summands;
  }

  do{

    if( k <= n ){
      summands.push_back(k);
      n = n - k ;
      k++ ;
    }
    else
    {
      for (int i = 0 ; i < summands.size() ; i++){
        sum += summands[i] ;
      }

      if ( (sum + n ) == total ){
        int rem = total - sum ;
        int len = summands.size() - 1 ;
        int last = rem + summands[len];
        summands.pop_back();
        summands.push_back(last);
      }
      return summands;
    }

  }while( n != 0);

  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
  std::cout << std::endl ;
}
