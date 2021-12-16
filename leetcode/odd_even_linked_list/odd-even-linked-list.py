# https://leetcode.com/problems/odd-even-linked-list/
from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head == None:
            return None

        even_head = head.next
        even_tail = head.next
        current = head

        while even_tail != None and even_tail.next != None:
            current.next = even_tail.next
            tmp = current.next.next
            current.next.next = even_head
            even_tail.next = tmp

            even_tail = even_tail.next
            current = current.next

        return head

def printer(head):
    s = ""
    while head != None:
        s += str(head.val) + " "
        head = head.next
    print(s)

printer(Solution().oddEvenList(ListNode(1)))
printer(Solution().oddEvenList(ListNode(1, ListNode(2))))
printer(Solution().oddEvenList(ListNode(1, ListNode(2, ListNode(3)))))
printer(Solution().oddEvenList(ListNode(1, ListNode(2, ListNode(3, ListNode(4))))))
printer(Solution().oddEvenList(ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))))
