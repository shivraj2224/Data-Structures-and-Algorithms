#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    int n = numbers.size(); 
    
    int index1 = -1;
    for (int first = 0; first < n; ++first) {
        if(index1 == -1 || (numbers[first] > numbers[index1])){
	    index1 = first;
	}
    }

    int index2 = -1 ;
    for(int second = 0 ;second < n; ++second) {
        if(index1 != second && ((index2 == -1) || ( numbers[second] > numbers[index2])) ){
	    index2 = second ;
	}
    }
    
    return ((long long)numbers[index1])*numbers[index2] ;

}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers);
    std::cout<< "\n";
    return 0;
}
