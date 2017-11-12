package com.rsredsq.oop.lab4;

import com.rsredsq.oop.lab4.algorithm.FactorizationAlgorithm;
import com.rsredsq.oop.lab4.algorithm.SimpleFactorizationAlgorithm;
import lombok.SneakyThrows;

import java.io.InputStream;
import java.io.OutputStream;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;

public class SimpleFactorizer {
  private FactorizationAlgorithm algorithm;
  private NumbersIngester numbersIngester;
  private NumbersProducer numbersProducer;

  public SimpleFactorizer(
      final Class<? extends FactorizationAlgorithm> algorithmClass,
      final NumbersIngester numbersIngester) {
    this(algorithmClass, numbersIngester, System.out::println);
  }

  @SneakyThrows
  public SimpleFactorizer(
      final Class<? extends FactorizationAlgorithm> algorithmClass,
      final NumbersIngester numbersIngester,
      final NumbersProducer numbersProducer) {
    this.algorithm = algorithmClass.newInstance();
    this.numbersIngester = numbersIngester;
    this.numbersProducer = numbersProducer;
  }

  @SneakyThrows
  public static void main(String[] args) {
    try (final InputStream inputFileStream = SimpleFactorizer.class.getResourceAsStream("/in.txt");
         final OutputStream outputFileStream = Files.newOutputStream(Paths.get("out.txt"))) {

      final InputStreamNumbersIngester numbersIngester = new InputStreamNumbersIngester(inputFileStream);
      final OutputStreamNumbersProducer numbersProducer = new OutputStreamNumbersProducer(outputFileStream);

      SimpleFactorizer factorizer = new SimpleFactorizer(
          SimpleFactorizationAlgorithm.class, numbersIngester, numbersProducer);

      factorizer.factorize();
    }

  }

  public void factorize() {
    while (numbersIngester.hasNextNumber()) {
      final long nextNumber = numbersIngester.getNextNumber();
      final List<Long> factorized = algorithm.factorize(nextNumber);
      numbersProducer.outputFactorizedNumbers(factorized);
    }
  }
}
