import scala.io.Source
import scala.util.Using

object Problem {
  def main(args: Array[String]): Unit = {
    var result = "2143"

    val usedDigits = Array.fill[Boolean](10)(false)

    Using(Source.fromFile("snippets/primes/up_to_9_digits.txt")) { source =>
      for (line <- source.getLines()) {
        val usedDigits = Array.fill[Boolean](10)(false)
        0 to line.length - 1 foreach { i =>
          val num = line.charAt(i).toInt - '0'
          usedDigits(num) = true
        }

        var isPandigital = true
        1 to line.length foreach { i =>
          if (!usedDigits(i)) {
            isPandigital = false
          }
        }

        if (isPandigital) {
          result = line
          println(line)
        }
      }
    }
  }
}
