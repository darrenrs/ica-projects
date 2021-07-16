#include <iostream>

template <typename T>
class BinaryTree {
  public:
    BinaryTree();

    void setData(T data);
    T getData();

    void setChild(BinaryTree<T>* node, int side);
    BinaryTree<T>* getChild(int side);

  private:
    T data;
    BinaryTree<T>* left = nullptr;
    BinaryTree<T>* right = nullptr;
};

template <typename T>
BinaryTree<T>::BinaryTree() {
  std::cout << "Binary tree initialized at " << this << std::endl;
}

template <typename T>
void BinaryTree<T>::setData(T data) {
  this->data = data;
}

template <typename T>
T BinaryTree<T>::getData() {
  return data;
}

template <typename T>
void BinaryTree<T>::setChild(BinaryTree<T>* node, int side) {
  if (!side) {
    this->right = node;
  } else {
    this->left = node;
  }
}

template <typename T>
BinaryTree<T>* BinaryTree<T>::getChild(int side) {
  if (!side) {
    return this->right;
  } else {
    return this->left;
  }
}