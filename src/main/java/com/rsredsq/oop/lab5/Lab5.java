package com.rsredsq.oop.lab5;

import com.rsredsq.oop.lab4.Factorizer;
import com.rsredsq.oop.lab4.InputStreamNumbersIngester;
import com.rsredsq.oop.lab4.OutputStreamNumbersProducer;
import com.rsredsq.oop.lab4.SimpleFactorizer;
import com.rsredsq.oop.lab4.algorithm.SimpleFactorizationAlgorithm;
import lombok.SneakyThrows;

import java.io.InputStream;
import java.io.OutputStream;
import java.nio.file.Files;
import java.nio.file.Paths;

public class Lab5 {
  @SneakyThrows
  public static void main(String[] args) {
    try (final InputStream inputFileStream = Lab5.class.getResourceAsStream("/in.txt");
         final OutputStream outputFileStream = Files.newOutputStream(Paths.get("out.txt"))) {

      final InputStreamNumbersIngester numbersIngester = new InputStreamNumbersIngester(inputFileStream);
      final OutputStreamNumbersProducer numbersProducer = new OutputStreamNumbersProducer(outputFileStream);

      Factorizer factorizer = new MultithreadedFactorizer(
          new SimpleFactorizationAlgorithm(), numbersIngester, numbersProducer);

      factorizer.factorize();
    }
  }
}
