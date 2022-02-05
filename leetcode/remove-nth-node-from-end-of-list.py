# https://leetcode.com/problems/remove-nth-node-from-end-of-list/submissions/

from typing import Optional
from helpers import linked_list_helper

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        fast = head
        slow = head # keep a distance of n

        for _ in range(n):
            fast = fast.next

        # remove head
        if fast is None:
            return head.next

        while fast is not None and fast.next is not None:
            fast, slow = fast.next, slow.next

        if slow.next:
            slow.next = slow.next.next
        else:
            slow.next = None

        return head

linked_list_helper.print_list(Solution().removeNthFromEnd(linked_list_helper.build_list([1,2,3,4]), 2))
linked_list_helper.print_list(Solution().removeNthFromEnd(linked_list_helper.build_list([1]), 1))
linked_list_helper.print_list(Solution().removeNthFromEnd(linked_list_helper.build_list([1, 2]), 1))
linked_list_helper.print_list(Solution().removeNthFromEnd(linked_list_helper.build_list([1, 2]), 2))
