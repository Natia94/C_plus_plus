#  DATA STRUCTURES C++

## First Task
 + Designed and implemeted a Vector class, then
 
## Second Task
 + Created a program that differentiates a <b> singly linked list</b>, a <b>doubly linked list</b> with a header node, and a <b>vector</b>. 
 Compares how long each task took for each container and each data size.
 + Attached discussion.txt which compares runtime of  SLL, DLL and Vector.
 
#### vector: 
+ Vector is faster to be filled when it comes to large amount of numbers.
+ faster fill sometimes but should not dd anything
+ Vector is not better at sorting. 
+ To change the size of vector cost a lot of time as vector to be copied again

#### singly linked list:
+ Singly Linked List really needs to conserve space and do not need to access node before.

#### doubly linked list:
+ Double Linked List needs to access node before roughly equivalent to singly linked list

## Third Task
 + Implemented a tree with arbitrary numbers of Children
 + Added a method Serialize() which writes a tree in a text file and Deserialize() which reads a tree from a text file.
 + Tested the tree with main.cpp

## Fourth Task
 + Wrote the code to calculate bigram probabilities from a corpus. (pair of words)
 + Bigram probabilities are calculated by the following formula:
 freq (w1,w2) / freq(w1)
 + This probabilities are important in many natural language applications, such as voice recognition, natural language 
 generation, and machine translation.
 + Implemeted by maps and included normalizeString() method which ignores capital letters, and other grammar things.
 
 



 
