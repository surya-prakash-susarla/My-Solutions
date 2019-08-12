
// COPIED 2016
# **__Notes about data structures__**

## __RED BLACK TREES__ :
Red black trees stats:
* insertion : O(log n)
* deletion : O(log n)
* search : O(log n)
* minimum : O(log n)
* maximum : O(log n)

Automatically balance themselves after operations ,

## Root node is always black.

## Properties of red-black trees:
* Every node is either red or black 
* Every leaf ( NULL ) node is black 
* Red nodes never appear in a row, they must always have a black parent and black children.
* Every branch in the tree passes through the same number of black nodes.

__BLACK HEIGHT__ : The number of black nodes ( not including itself ) between the origin and a leaf node.

__Comparison to AVL Trees__ : 
1. AVL trees are useful if search is done more than insertion 
2. Red black trees are much useful otherwise.

