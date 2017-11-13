package com.rsredsq.oop.lab4;

import com.rsredsq.oop.lab4.algorithm.FactorizationAlgorithm;

import java.util.List;

public class SimpleFactorizer extends Factorizer {

  public SimpleFactorizer(
      final Class<? extends FactorizationAlgorithm> algorithmClass,
      final NumbersIngester numbersIngester) {
    super(algorithmClass, numbersIngester);
  }

  public SimpleFactorizer(
      final Class<? extends FactorizationAlgorithm> algorithmClass,
      final NumbersIngester numbersIngester,
      final NumbersProducer numbersProducer) {
    super(algorithmClass, numbersIngester, numbersProducer);
  }

  public void factorize() {
    while (numbersIngester.hasNextNumber()) {
      final long nextNumber = numbersIngester.getNextNumber();
      final List<Long> factorized = algorithm.factorize(nextNumber);
      numbersProducer.outputFactorizedNumbers(factorized);
    }
  }
}
