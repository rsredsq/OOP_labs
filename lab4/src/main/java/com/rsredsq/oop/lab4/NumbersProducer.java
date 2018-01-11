package com.rsredsq.oop.lab4;

import java.util.List;

@FunctionalInterface
public interface NumbersProducer {
  void outputFactorizedNumbers(final List<Long> factorized);
}
