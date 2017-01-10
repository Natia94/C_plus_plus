//Natela Khomasuridze
#include <assert.h>
#include <iostream>

#include "Ntree.h"

int main() {
    
    // Ntree must be templated to hold any type
    // constructor should take a single argument of type T, allocate
    // a node containing that value, and point the tree's root to it
    
    Ntree<std::string> foodtree("Food");
    
    // addChildren should be a public method that takes two arguments
    // the first argument is a T that is the value of the node
    // that should be the parent of the new nodes
    // the second argument is a std::initializer_list<T> that allows you
    // to conveniently pass in a list of arguments (as seen below). You can
    // iterate over it like any other container.
    
    foodtree.addChildren("Food", { "Plant", "Animal" } );
    foodtree.addChildren("Plant", { "Roots", "Leaves", "Fruits" } );
    foodtree.addChildren("Animal", { "Fish", "Mammals", "Birds" } );
    foodtree.addChildren("Roots", { "Potatoes", "Carrots" } );
    foodtree.addChildren("Leaves", { "Lettuce", "Cabbage" } );
    foodtree.addChildren("Fruits", { "Apples", "Pears", "Plums", "Oranges" } );
    foodtree.addChildren("Fish", { "Salmon", "Tuna" } );
    foodtree.addChildren("Mammals", { "Beef", "Lamb" } );
    foodtree.addChildren("Birds", { "Chicken", "Duck" } );
    foodtree.addChildren("Salmon", { "Wild", "Farm" } );
    foodtree.addChildren("Apples", { "GrannySmith", "Gala" } );
    
    // write serialize method that takes filepath
    foodtree.serialize("foodtree.out");
    
    // default constructor creates empty tree
    Ntree<std::string> foodtree2;
    // tree2 should become the tree deserialized from filepath
    foodtree2.deserialize("foodtree.out");
    
    // overload equality operator
    assert(foodtree==foodtree2);
    
    // everything you write must work on all types of T
    Ntree<int> inttree(9);
    inttree.addChildren(9, { 6 } );
    inttree.addChildren(6, { 5, 4, 2 } );
    inttree.addChildren(5, { 10, 7, 1 } );
    inttree.addChildren(4, { 3, 8 } );
    inttree.addChildren(3, { 11, 12, 13, 14 } );
    
    inttree.serialize("inttree.out");
    Ntree<int> inttree2;
    inttree2.deserialize("inttree.out");
    assert(inttree==inttree2);
}
