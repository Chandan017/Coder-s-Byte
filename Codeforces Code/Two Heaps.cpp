#include <iostream>
#include <string>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  size_t n;
  std::cin >> n;
  std::vector<size_t> a(n * 2);
  std::vector<size_t> counts(100);
  for(size_t i = 0; i < n * 2; ++i){
    std::cin >> a[i];
    counts[a[i]] += 1;
  }
  std::vector<size_t> locals(100);
  std::vector<size_t> result(n * 2);
  size_t singles = 0;
  size_t groups = 0;
  for(size_t i = 0; i < n * 2; ++i){
    if(locals[a[i]] % 2 == 1){
      result[i] = 2;
      locals[a[i]] += 1;
    }else if(locals[a[i]] + 2 <= counts[a[i]]){
      result[i] = 1;
      locals[a[i]] += 1;
    }else if(counts[a[i]] == 1){
      singles += 1;
    }else{
      groups += 1;
    }
  }
  size_t ptr_single = 1;
  size_t ptr_group = singles % 2 == 0 ? 1 : 2;
  for(size_t i = 0; i < n * 2; ++i){
    if(result[i] == 0){
      if(counts[a[i]] == 1){
        result[i] = ptr_single;
        ptr_single ^= 3;
      }else{
        result[i] = ptr_group;
        ptr_group ^= 3;
      }
    }
  }
  size_t mult[2] = {};
  for(size_t i = 0; i < n * 2; ++i){
    bool ok = true;
    for(size_t j = 0; j < i; ++j){
      if(a[i] == a[j] && result[i] == result[j]){
        ok = false;
        break;
      }
    }
    if(ok){
      mult[result[i] - 1] += 1;
    }
  }
  std::cout << mult[0] * mult[1] << '\n';
  for(size_t i = 0; i < n * 2; ++i){
    std::cout << result[i] << ' ';
  }
  std::cout << '\n';
}
