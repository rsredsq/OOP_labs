package com.rsredsq.oop.lab5;

import com.google.common.collect.Lists;
import com.google.common.util.concurrent.ThreadFactoryBuilder;
import com.rsredsq.oop.lab4.Factorizer;
import com.rsredsq.oop.lab4.NumbersIngester;
import com.rsredsq.oop.lab4.NumbersProducer;
import com.rsredsq.oop.lab4.algorithm.FactorizationAlgorithm;

import java.util.List;
import java.util.concurrent.CompletableFuture;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class MultithreadedFactorizer extends Factorizer {

  private final int numThreads;

  private final ExecutorService tasksExecutor;

  private final List<CompletableFuture<List<Long>>> factorizationTasks = Lists.newArrayList();

  public MultithreadedFactorizer(
      final FactorizationAlgorithm algorithm,
      final NumbersIngester numbersIngester) {
    this(algorithm, numbersIngester, System.out::println, Runtime.getRuntime().availableProcessors());
  }

  public MultithreadedFactorizer(final FactorizationAlgorithm algorithm,
                                 final NumbersIngester numbersIngester,
                                 final NumbersProducer numbersProducer) {
    this(algorithm, numbersIngester, numbersProducer, Runtime.getRuntime().availableProcessors());
  }

  public MultithreadedFactorizer(
      final FactorizationAlgorithm algorithm,
      final NumbersIngester numbersIngester,
      final NumbersProducer numbersProducer,
      final int numThreads) {
    super(algorithm, numbersIngester, numbersProducer);
    this.numThreads = numThreads;
    tasksExecutor = Executors.newFixedThreadPool(numThreads,
        new ThreadFactoryBuilder()
            .setNameFormat("factorization-task-thread-pool-%d")
            .build());
  }

  @Override
  public void factorize() {
    while (numbersIngester.hasNextNumber()) {
      final long nextNumber = numbersIngester.getNextNumber();
      runAsyncFactorization(nextNumber);
    }

    outputProducedNumbers();
  }

  private void outputProducedNumbers() {
    factorizationTasks.forEach((future) -> {
      final List<Long> result = future.join();
      numbersProducer.outputFactorizedNumbers(result);
    });
  }

  private void runAsyncFactorization(final long number) {
    factorizationTasks.add(CompletableFuture.supplyAsync(() -> algorithm.factorize(number), tasksExecutor));
  }
}
