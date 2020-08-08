# TLE
# class Node:
#     def __init__(self, key=None, prev=None, next=None):
#         self.key = key
#         self.prev = prev if prev is not None else self
#         self.next = next if next is not None else self


# class DoublyLinkedList:
#     def __init__(self):
#         self.nil = Node()

#     def print_list(self):
#         node = self.nil.next
#         while node != self.nil:
#             if node.next != self.nil:
#                 print(node.key, end=' ')
#             else:
#                 print(node.key)
#             node = node.next

#     def insert(self, key):
#         node = Node(key, self.nil, self.nil.next)
#         self.nil.next.prev = node
#         self.nil.next = node

#     def delete_node(self, node):
#         if node == self.nil:
#             return

#         node.next.prev = node.prev
#         node.prev.next = node.next

#     def delete(self, key):
#         node = self.nil.next
#         while node != self.nil:
#             if node.key == key:
#                 self.delete_node(node)
#                 break
#             node = node.next

#     def delete_first(self):
#         self.delete_node(self.nil.next)

#     def delete_last(self):
# self.delete_node(self.nil.prev)


# def main():
#     List = DoublyLinkedList()
#     n = int(input())
#     for i in range(n):
#         order = input().split()
#         if order[0] == "insert":
#             List.insert(order[1])
#         elif order[0] == "delete":
#             List.delete(order[1])
#         elif order[0] == "deleteFirst":
#             List.delete_first()
#         elif order[0] == "deleteLast":
#             List.delete_last()
#     List.print_list()

from collections import deque


def print_list(que):
    for i, q in enumerate(que):
        if i != len(que)-1:
            print(q, end=' ')
        else:
            print(q)


def main():
    List = deque()
    n = int(input())
    for i in range(n):
        order = input().split()
        if order[0] == "insert":
            List.appendleft(order[1])
        elif order[0] == "delete":
            try:
                List.remove(order[1])
            except ValueError:
                pass
        elif order[0] == "deleteFirst":
            List.popleft()
        elif order[0] == "deleteLast":
            List.pop()
    print_list(List)


if __name__ == "__main__":
    main()
