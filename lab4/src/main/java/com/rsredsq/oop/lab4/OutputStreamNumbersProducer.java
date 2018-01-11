package com.rsredsq.oop.lab4;

import java.io.OutputStream;
import java.io.PrintStream;
import java.util.List;

public class OutputStreamNumbersProducer implements NumbersProducer {

  private PrintStream printStream;

  public OutputStreamNumbersProducer(final OutputStream output) {
    this.printStream = new PrintStream(output);
  }

  @Override
  public void outputFactorizedNumbers(List<Long> factorized) {
    printStream.print(factorized);
    printStream.println();
  }
}
