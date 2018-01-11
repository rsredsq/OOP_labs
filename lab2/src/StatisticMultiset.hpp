#pragma once

#include <set>
#include <list>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <boost/optional.hpp>

template<class T>
class StatisticMultiset {
public:
  StatisticMultiset() = default;

  ~StatisticMultiset() noexcept = default;

  void addNum(const T& value);

  void addNums(const std::multiset<T>& set);

  void addNums(const std::vector<T>& vector);

  void addNums(const std::list<T>& list);

  void addNums(const StatisticMultiset& multiset);

  void addNumsFromFile(const std::string& path);

  T getMax() const;

  T getMin() const;

  double getAvg() const;

  long getCountUnder(T threshold) const;

  long getCountAbove(T threshold) const;

  std::string toString() const;

private:
  void calculateAverage() const;

  void invalidateCache() const;

  std::multiset<T> container;
  mutable boost::optional<double> averageValue;
  //this is definitely doesn't make sense, O(log(n)) complexity without caching
  mutable std::unordered_map<double, long> cachedCountUnder;
  mutable std::unordered_map<double, long> cachedCountAbove;
};
