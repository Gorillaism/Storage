#Linked Lists in Python by Daniel Örhill

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

    def __str__(self):
        str = ""
        str += f"{self.data}"
        return str


class Storage:
    def __init__(self):
        self.head = None
        self.counter = 0

    def push(self, data):
        newNode = Node(data)

        if self.head is None:
            self.head = newNode
        else:
            newNode.next = self.head
            self.head = newNode

        self.counter += 1

    def pop(self):
        if self.head is None:
            return None
        else:
            tempNode = self.head
            self.head = self.head.next
            self.counter -= 1
            return tempNode.data
        

    def peek(self):
        if self.head is None:
            return False
        else:
            return self.head.data

    def isempty(self):
        if self.head is None:
            return True
        else:
            return False

    def swap(self, pos1, pos2):
        if self.counter <= pos1 or self.counter <= pos2 and pos1 is not pos2:
            return False
        
        current_node = self.head
        pos1_node = None
        pos2_node = None
        checker = 0

        while current_node is not None:
            if checker is pos1:
                pos1_node = current_node
            if checker is pos2:
                pos2_node = current_node

            checker += 1
            current_node = current_node.next
        
        temp = pos1_node.data
        pos1_node.data = pos2_node.data
        pos2_node.data = temp

        return True

