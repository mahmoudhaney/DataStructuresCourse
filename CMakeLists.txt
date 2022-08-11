cmake_minimum_required(VERSION 3.22)
project(DataStructuresTraining)

set(CMAKE_CXX_STANDARD 14)

add_executable(DataStructuresTraining main.cpp Stacks/ArrayStack/Stack.cpp Stacks/ArrayStack/Stack.h Linkedlist/Single/SinglyLinkedlist.cpp Linkedlist/Single/SinglyLinkedlist.h Stacks/LinkedStack/StackBasedLinkedlist.cpp Stacks/LinkedStack/StackBasedLinkedlist.h Queues/Simple/SimpleQueue.cpp Queues/Simple/SimpleQueue.h Queues/Circular/CircularQueue.cpp Queues/Circular/CircularQueue.h Queues/LinkedQueue/QueueBasedLinkedlist.cpp Queues/LinkedQueue/QueueBasedLinkedlist.h Vector/Vector.cpp Vector/Vector.h Linkedlist/Double/DoublyLinkedlist.cpp Linkedlist/Double/DoublyLinkedlist.h Trees/BinaryTree/BinaryTree.cpp Trees/BinaryTree/BinaryTree.h Trees/BinarySearchTree/BinarySearchTree.cpp Trees/BinarySearchTree/BinarySearchTree.h Trees/BinaryHeap/BinaryHeap.cpp Trees/BinaryHeap/BinaryHeap.h Trees/AVLTree/AVLTree.cpp Trees/AVLTree/AVLTree.h Trees/LetterTree/Trie.cpp Trees/LetterTree/Trie.h HashTable/Chaining.cpp HashTable/Probing.cpp)
