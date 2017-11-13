package com.rsredsq.oop.lab4;

import com.rsredsq.oop.lab4.algorithm.SimpleFactorizationAlgorithm;
import lombok.SneakyThrows;

import java.io.InputStream;
import java.io.OutputStream;
import java.nio.file.Files;
import java.nio.file.Paths;

public class Lab4 {
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
}
