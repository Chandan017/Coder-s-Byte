#include <iostream>
#include <string>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  size_t n;
  std::cin >> n;
  std::vector<int32_t> x(n);
  std::vector<int32_t> y(n);
  int32_t x_tot = 0;
  int32_t y_tot = 0;
  bool exists[2][2] = {};
  for(size_t i = 0; i < n; ++i){
    std::cin >> x[i] >> y[i];
    x_tot += x[i];
    y_tot += y[i];
    exists[x[i] % 2][y[i] % 2] = true;
  }
  if((x_tot + y_tot) % 2 == 1){
    std::cout << "-1\n";
  }else if(x_tot % 2 == 0){
    std::cout << "0\n";
  }else{
    if(exists[0][1] || exists[1][0]){
      std::cout << "1\n";
    }else{
      std::cout << "-1\n";
    }
  }
}
