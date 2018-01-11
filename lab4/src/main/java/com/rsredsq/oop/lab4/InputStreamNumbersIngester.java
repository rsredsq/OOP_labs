package com.rsredsq.oop.lab4;

import java.io.InputStream;
import java.util.Scanner;

public class InputStreamNumbersIngester implements NumbersIngester {

  private final Scanner numbersScanner;

  public InputStreamNumbersIngester(final InputStream numbersStream) {
    this.numbersScanner = new Scanner(numbersStream);
  }

  @Override
  public boolean hasNextNumber() {
    return numbersScanner.hasNextLong();
  }

  @Override
  public long getNextNumber() {
    return numbersScanner.nextLong();
  }
}
