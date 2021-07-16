#include <iostream>
#include "binaryTree.h"

void createBasicBinaryTrees() {
  BinaryTree<int> binaryTree = BinaryTree<int>();
  BinaryTree<int> binaryTreeLeft = BinaryTree<int>();
  BinaryTree<int> binaryTreeRight = BinaryTree<int>();

  binaryTree.setData(1);
  binaryTreeLeft.setData(84);
  binaryTreeRight.setData(85);

  binaryTree.setChild(&binaryTreeLeft, 0);
  binaryTree.setChild(&binaryTreeRight, 1);

  std::cout << binaryTree.getData() << std::endl;
  std::cout << binaryTree.getChild(0)->getData() << std::endl;
  std::cout << binaryTree.getChild(1)->getData() << std::endl;
}

int main() {
  createBasicBinaryTrees();
}