#include "../main.cpp"

bool Test1() {
  long long expected = 720;
  long long result = factorial(6);
  return expected == result;
}

bool Test2() {
  std::vector<int> expected = {0,0,1,2};
  auto a = FDecomp(10, 5);
  for (int i = 0; i < a.size(); ++i) {
    if (expected[i] != a[i]) return false;
  }
  return true;
}

int main() {
  return Test1() && Test2();
}