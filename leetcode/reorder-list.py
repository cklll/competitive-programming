# https://leetcode.com/problems/reorder-list/

from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        if not head.next:
            return


        # split the list to half, [1, 2, 3, 4] -> [1, 2], [3, 4]
        # if odd number, first list get one more number
        current1, current2 = head, head
        while current2 and current2.next:
            current1, current2 = current1.next, current2.next.next

        head2, current1.next = current1.next, None

        # reverse 2nd list
        if not head2 or not head2.next:
            pass
        else:
            prev_head = None
            current = head2
            while current:
                tmp = current.next
                current.next = prev_head
                prev_head = current
                current = tmp

            head2 = prev_head


        # merge list
        current1 = head
        current2 = head2
        while current1 is not None:
            tmp_next_current1 = current1.next
            if current2 is not None:
                tmp_next_current2 = current2.next

                current1.next = current2
                current2.next = tmp_next_current1
                current2 = tmp_next_current2

            current1 = tmp_next_current1


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


# head = build_list([1]); Solution().reorderList(head); print_list(head)
# head = build_list([1,2]); Solution().reorderList(head); print_list(head)
# head = build_list([1,2,3]); Solution().reorderList(head); print_list(head)
# head = build_list([1,2,3,4]); Solution().reorderList(head); print_list(head)
# head = build_list([1,2,3,4,5]); Solution().reorderList(head); print_list(head)
# head = build_list([1,2,3,4,5,6]); Solution().reorderList(head); print_list(head)
head = build_list([1,2,3,4,5,6,7]); Solution().reorderList(head); print_list(head)
