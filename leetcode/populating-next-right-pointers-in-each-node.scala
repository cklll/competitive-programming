// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

class Node(var _value: Int) {
  var value: Int = _value
  var left: Node = null
  var right: Node = null
  var next: Node = null
}

object Solution {
  def main(args: Array[String]): Unit = {
    val node1 = Node(1)
    val node2 = Node(2)
    val node3 = Node(3)
    val node4 = Node(4)
    val node5 = Node(5)
    val node6 = Node(6)
    val node7 = Node(7)
    node1.left = node2
    node1.right = node3
    node2.left = node4
    node2.right = node5
    node3.left = node6
    node3.right = node7
    val newNode = connect(node1)

    println(newNode.next)
    println(newNode.left.next.value)
    println(newNode.left.next.next)
    println(newNode.left.left.next.value)
    println(newNode.left.right.next.value)
    println(newNode.right.left.next.value)
    println(newNode.right.right.next)


    val newNode2 = connect(node7)
  }

  def connect(root: Node): Node = {
    if (root == null) {
      return root
    }
    if (root.left != null) {
      recur(root.left, root.right)
    }
    root
  }

  def recur(left: Node, right: Node): Unit = {
    left.next = right
    if (left.left != null) {
      recur(left.left, left.right)
      recur(left.right, right.left)
      recur(right.left, right.right)
    }
  }
}
