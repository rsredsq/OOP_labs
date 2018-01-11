package com.rsredsq.oop.lab5;

import com.google.common.collect.Lists;
import com.google.common.collect.Queues;
import com.google.common.util.concurrent.ThreadFactoryBuilder;
import com.rsredsq.oop.lab4.Factorizer;
import com.rsredsq.oop.lab4.NumbersIngester;
import com.rsredsq.oop.lab4.NumbersProducer;
import com.rsredsq.oop.lab4.algorithm.FactorizationAlgorithm;
import lombok.SneakyThrows;

import java.util.List;
import java.util.concurrent.*;

public class MultithreadedFactorizer extends Factorizer {

  private final int numThreads;

  private final ExecutorService tasksExecutor;

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
    tasksExecutor = new ThreadPoolExecutor(numThreads, numThreads, 0, TimeUnit.MILLISECONDS,
        new LinkedBlockingQueue<>(),
        new ThreadFactoryBuilder()
            .setNameFormat("factorization-task-thread-pool-%d")
            .build());
  }

  @Override
  @SneakyThrows
  public void factorize() {
    while (numbersIngester.hasNextNumber()) {
      final long nextNumber = numbersIngester.getNextNumber();
      runAsyncFactorization(nextNumber);
    }

    tasksExecutor.shutdown();
    tasksExecutor.awaitTermination(Long.MAX_VALUE, TimeUnit.NANOSECONDS);
  }

  @SneakyThrows
  private void runAsyncFactorization(final long number) {
    CompletableFuture.supplyAsync(() -> algorithm.factorize(number), tasksExecutor).thenAccept((result) -> {
      synchronized (numbersProducer) {
        numbersProducer.outputFactorizedNumbers(result);
      }
    });
  }
}
