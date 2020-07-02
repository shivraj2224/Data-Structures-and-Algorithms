#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    int Count = 0;
    int refillPos = 0;
    int currentLoc = 0;
    stops.push_back(dist);
    int i = 0;
    while(true){
        if (tank + currentLoc >= dist){
            return Count;
        }
        if( tank < stops[i] - currentLoc ){
            refillPos = i-1;
            if( currentLoc == stops[refillPos]){
                return -1; 
            }
            Count += 1;
            currentLoc = stops[i-1];
            i --;
            continue;
        }
        i++;
    }

    return -1;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
