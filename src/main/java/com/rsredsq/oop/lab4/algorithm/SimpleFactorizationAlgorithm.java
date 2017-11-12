package com.rsredsq.oop.lab4.algorithm;

import com.google.common.collect.Lists;

import java.util.List;

public class SimpleFactorizationAlgorithm implements FactorizationAlgorithm {
  public List<Long> factorize(long number) {
    List<Long> factors = Lists.newArrayList();
    for (long i = 2; i <= number; i++) {
      while (number % i == 0) {
        factors.add(i);
        number /= i;
      }
    }
    return factors;
  }
}
