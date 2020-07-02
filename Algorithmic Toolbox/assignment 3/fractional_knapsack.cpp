#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using std::vector;

struct weightValuePair
{
  int weight, value;
  double vw;
};

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;

  vector<weightValuePair> max_v;
  // write your code here
  for(int i =0 ;i < values.size() ;i++) {
    weightValuePair k;
    k.weight = weights[i];
    k.value = values[i];
    k.vw = values[i]* 1.0 / weights[i];
    max_v.push_back(k);
  }

  std::sort(max_v.begin(), max_v.end(), [](const weightValuePair a, const weightValuePair b) {
    return a.vw > b.vw;
  });

  for (long i = 0; i < max_v.size(); i++)
  {
    if (capacity <= 0)
    {
      break;
    }
    if (max_v[i].weight <= capacity)
    {
      value += max_v[i].value;
      capacity -= max_v[i].weight;
    }
    else
    {
      value += max_v[i].vw * capacity;
      capacity = 0;
    }
  }

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
