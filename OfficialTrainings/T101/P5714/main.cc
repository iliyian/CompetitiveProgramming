// 原来c艹默认精度6位有效数字

#include <iostream>
using namespace std;

int main() {
  double w, h;
  cin >> w >> h;
  double bmi = w / h / h;
  if (bmi < 18.5) cout << "Underweight";
  else if (18.5 <= bmi && bmi < 24) cout << "Normal";
  else cout << bmi << endl << "Overweight";
  return 0;
}