#  DATA STRUCTURES C++

## First Task
 + Designed and implemeted a Vector class, then
 
## Second Task
 + Created a program that differentiates a <b> singly linked list</b>, a <b>doubly linked list</b> with a header node, and a <b>vector</b>. 
 Compares how long each task took for each container and each data size.
 + Attached discussion.txt which compares runtime of  SLL, DLL and Vector.
#### vector: 
+ faster to fill for larger
+ faster fill sometimes but should not dd anything
+ not better at sorting
+ change in size cost a lot of time
+ as vector to be copied again

#### singly linked list:
+ really need to conserve space and do not need to access node before

#### doubly linked list:
+ need to access node before roughly equivalent to singly linked list

 ## Third Task
 + Implemented a tree with arbitrary numbers of Children
 + Added a method Serialize() which writes a tree in a text file and Deserialize() which reads a tree from a text file.
 + Tested the tree with main.cpp

 ## Fourth Task
 
 + Wrote the code to calculate bigram probabilities from a corpus. (pair of words)
 + Bigram probabilities are calculated by the following program:
 freq (w1,w2) / freq(w1)
 + This probabilities are important in many natural language applications, such as voice recognition, natural language 
 generation, and machine translation.
 + Implemeted by maps and included normalizeString() method which ignores capital letters, and other grammar things.
 
 



 
