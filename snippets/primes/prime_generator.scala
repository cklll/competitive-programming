// https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes

import scala.math._

object PrimeGenerator {
  def main(args: Array[String]): Unit = {
    val maxVal = 1000000000 // search space
    val sqrtRoot = sqrt(maxVal).toInt
    val isPrimes = Array.fill[Boolean](maxVal+1)(true)

    2 to sqrtRoot foreach { i =>
      if (isPrimes(i)) {
        var j = i*i
        while (j <= maxVal) {
          isPrimes(j) = false
          j += i
        }
      }
    }

    2 to maxVal foreach { i =>
      if (isPrimes(i)) {
        println(i)
      }
    }
  }
}
