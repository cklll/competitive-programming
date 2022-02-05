class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

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
