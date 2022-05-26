// https://leetcode.com/problems/game-of-life/

object Solution {
  def main(args: Array[String]): Unit = {
    gameOfLife(Array(Array(0,1,0), Array(0,0,1), Array(1,1,1), Array(0,0,0)))
    gameOfLife(Array(Array(1, 1), Array(1, 0)))
  }

  def gameOfLife(board: Array[Array[Int]]): Unit = {
    var newBoard = Array.ofDim[Int](board.size, board(0).size)
    val directions = List(
      (-1, -1),
      (-1, 0),
      (-1, 1),
      (0, -1),
      // (0, 0),
      (0, 1),
      (1, -1),
      (1, 0),
      (1, 1),
    )

    for(i <- board.indices) {
      for(j <- board(0).indices) {
        var liveCount = 0
        directions foreach {
          direction => {
            if (i + direction._1 >= 0 && i + direction._1 < board.size && j + direction._2 >= 0 && j + direction._2 < board(0).size) {
              liveCount += board(i+direction._1)(j+direction._2)
            }

            newBoard(i)(j) = board(i)(j)
            if (board(i)(j) == 0) {
              if (liveCount == 3) {
                newBoard(i)(j) = 1
              }
            } else {
              if (liveCount == 2 || liveCount == 3) {
              } else {
                newBoard(i)(j) = 0
              }
            }
          }
        }
      }
    }
    for (i <- board.indices) {
      for (j <- board(0).indices) {
        board(i)(j) = newBoard(i)(j)
      }
    }
    board foreach { row => row foreach print; println }
  }
}
