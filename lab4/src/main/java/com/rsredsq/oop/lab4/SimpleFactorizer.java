package com.rsredsq.oop.lab4;

import com.rsredsq.oop.lab4.algorithm.FactorizationAlgorithm;

import java.util.List;

public class SimpleFactorizer extends Factorizer {


  public SimpleFactorizer(
      final FactorizationAlgorithm algorithm,
      final NumbersIngester numbersIngester) {
    super(algorithm, numbersIngester);
  }

  public SimpleFactorizer(
      final FactorizationAlgorithm algorithm,
      final NumbersIngester numbersIngester,
      final NumbersProducer numbersProducer) {
    super(algorithm, numbersIngester, numbersProducer);
  }

  public void factorize() {
    while (numbersIngester.hasNextNumber()) {
      final long nextNumber = numbersIngester.getNextNumber();
      final List<Long> factorized = algorithm.factorize(nextNumber);
      numbersProducer.outputFactorizedNumbers(factorized);
    }
  }
}
