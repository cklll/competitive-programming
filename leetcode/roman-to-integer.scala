// https://leetcode.com/problems/roman-to-integer/submissions/

object Solution {
    def romanToInt(s: String): Int = {
        solve(s, 0)
    }

    val oneLetterMap = Map(
        "I" -> 1,
        "V" -> 5,
        "X" -> 10,
        "L" -> 50,
        "C" -> 100,
        "D" -> 500,
        "M" -> 1000,
    )

    val twoLetterMap = Map(
        "IV" -> 4,
        "IX" -> 9,
        "XL" -> 40,
        "XC" -> 90,
        "CD" -> 400,
        "CM" -> 900,
    )

    def solve(s: String, current: Int): Int = {
        val firstTwo = s.take(2)

        if (firstTwo == "") {
            return current
        }

        if (twoLetterMap.contains(firstTwo)) {
            return solve(s.drop(2), current + twoLetterMap(firstTwo))
        }

        val firstChar = s.take(1)
        solve(s.drop(1), current + oneLetterMap(firstChar))
    }
}
