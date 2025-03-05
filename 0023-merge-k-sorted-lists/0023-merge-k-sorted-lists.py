# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        # Define a lambda function for the heap to compare ListNodes
        ListNode.__lt__ = lambda self, other: self.val < other.val

        # Initialize a priority queue (min-heap)
        min_heap = []

        # Push the head of each list into the min-heap
        for l in lists:
            if l:
                heapq.heappush(min_heap, l)

        # Create a dummy node to serve as the starting point of the merged list
        dummy = ListNode(0)
        current = dummy

        # While there are nodes in the heap
        while min_heap:
            # Get the smallest node from the heap
            node = heapq.heappop(min_heap)
            # Append this node to the merged list
            current.next = node
            current = current.next
            # If there is a next node in the list, push it into the heap
            if node.next:
                heapq.heappush(min_heap, node.next)

        # Return the next node of dummy which is the head of the merged list
        return dummy.next