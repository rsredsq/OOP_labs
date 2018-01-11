#include <iostream>
#include "StatisticMultiset.hpp"

int main() {
  //example of usage from lab2
  std::cout << "Lab 02" << std::endl;
  StatisticMultiset<int> ms1;
  ms1.addNum(89);
  ms1.addNum(54);
  ms1.addNum(54);
  ms1.addNum(24);
  StatisticMultiset<int> ms2;
  std::vector<int> somedata = {10, 40, 6, 87};
  ms2.addNums(somedata);
  StatisticMultiset<int> ms3;
  ms3.addNums(ms1);
  ms3.addNums(ms2);
  std::cout << ms3.toString();
  std::cout << " Min: " << ms3.getMin()
            << " Avg: " << ms3.getAvg()
            << " Max: " << ms3.getMax()
            << std::endl;

  std::cout << ms3.getCountAbove(40);
  return 0;
}