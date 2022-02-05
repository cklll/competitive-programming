# https://leetcode.com/problems/reverse-linked-list/

from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head

        prev_head = None
        current = head
        while current:
            tmp = current.next
            current.next = prev_head
            prev_head = current
            current = tmp

        return prev_head

def build_list(l):
    nodes = [ListNode(val=val, next=None) for val in l]

    for i in range(len(l)-1):
        nodes[i].next = nodes[i+1]

    return nodes[0]

def print_list(head):
    s = ""
    current = head
    while current is not None:
        s += str(current.val) + " "
        current = current.next
    print(s)



head = build_list([1]); print_list(Solution().reverseList(head))
head = build_list([1,2]); print_list(Solution().reverseList(head))
head = build_list([1,2,3]); print_list(Solution().reverseList(head))
