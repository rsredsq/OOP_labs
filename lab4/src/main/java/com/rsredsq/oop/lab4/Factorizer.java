package com.rsredsq.oop.lab4;

import com.rsredsq.oop.lab4.algorithm.FactorizationAlgorithm;
import lombok.SneakyThrows;

public abstract class Factorizer {
  protected final FactorizationAlgorithm algorithm;
  protected final NumbersIngester numbersIngester;
  protected final NumbersProducer numbersProducer;

  public Factorizer(
      final FactorizationAlgorithm algorithm,
      final NumbersIngester numbersIngester) {
    this(algorithm, numbersIngester, System.out::println);
  }

  @SneakyThrows
  public Factorizer(
      final FactorizationAlgorithm algorithm,
      final NumbersIngester numbersIngester,
      final NumbersProducer numbersProducer) {
    this.algorithm = algorithm;
    this.numbersIngester = numbersIngester;
    this.numbersProducer = numbersProducer;
  }

  public abstract void factorize();

}
