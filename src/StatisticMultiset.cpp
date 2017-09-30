#include <iostream>
#include "StatisticMultiset.hpp"

template<class T>
void StatisticMultiset<T>::addNum(const T& value) {
  container.insert(value);
}

template<class T>
void StatisticMultiset<T>::addNums(const std::multiset<T>& set) {
  container.insert(set.cbegin(), set.cend());
  invalidateCache();
}

template<class T>
void StatisticMultiset<T>::addNums(const std::vector<T>& vector) {
  container.insert(vector.cbegin(), vector.cend());
  invalidateCache();
}

template<class T>
void StatisticMultiset<T>::addNums(const std::list<T>& list) {
  container.insert(list.cbegin(), list.cend());
  invalidateCache();
}

template<class T>
void StatisticMultiset<T>::addNums(const StatisticMultiset& multiset) {
  auto anotherContainer = multiset.container;
  container.insert(anotherContainer.cbegin(), anotherContainer.cend());
  invalidateCache();
}

template<class T>
void StatisticMultiset<T>::addNumsFromFile(const std::string& path) {
  std::ifstream numsStream{path};
  while (!numsStream.eof()) {
    T value;
    numsStream >> value;
    container.insert(value);
  }
}

template<class T>
T StatisticMultiset<T>::getMax() const {
  return *(--container.cend());
}

template<class T>
T StatisticMultiset<T>::getMin() const {
  return *container.cbegin();
}

template<class T>
double StatisticMultiset<T>::getAvg() const {
  if (!averageValue) {
    calculateAverage();
  }
  return *averageValue;
}

template<class T>
long StatisticMultiset<T>::getCountUnder(T threshold) const {
  if (cachedCountUnder.count(threshold)) return cachedCountUnder[threshold];
  auto actualIterator = container.lower_bound(threshold);
  long numsCount = std::distance(container.cbegin(), actualIterator);
  return cachedCountUnder[threshold] = numsCount;
}

template<class T>
long StatisticMultiset<T>::getCountAbove(T threshold) const {
  if (cachedCountAbove.count(threshold)) return cachedCountAbove[threshold];
  auto actualIterator = container.upper_bound(threshold);
  long numsCount = std::distance(actualIterator, container.cend());
  return cachedCountUnder[threshold] = numsCount;
}

template<class T>
std::string StatisticMultiset<T>::asString() const {
  std::string out;
  for (auto value: container) {
    auto strValue = std::to_string(value);
    out += strValue;
    out += '\n';
  }
  return out;
}

template<class T>
void StatisticMultiset<T>::calculateAverage() const  {
  double average = 0;
  for (auto val: container) {
    average += val;
  }
  average /= container.size();
  averageValue = average;
}

template<class T>
void StatisticMultiset<T>::invalidateCache() const {
  cachedCountAbove.clear();
  cachedCountUnder.clear();
  averageValue = boost::none;
}

template class StatisticMultiset<char>;
template class StatisticMultiset<signed char>;
template class StatisticMultiset<unsigned char>;
template class StatisticMultiset<short>;
template class StatisticMultiset<unsigned short>;
template class StatisticMultiset<int>;
template class StatisticMultiset<unsigned int>;
template class StatisticMultiset<long>;
template class StatisticMultiset<unsigned long>;
template class StatisticMultiset<long long>;
template class StatisticMultiset<unsigned long long>;
template class StatisticMultiset<float>;
template class StatisticMultiset<double>;
template class StatisticMultiset<long double>;