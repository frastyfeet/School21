#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <limits>
#include <utility>

enum COLOR { RED, BLACK };

template <typename T>
struct Node {
  T value;
  Node *left, *right, *parent;
  bool color;

  Node()
      : value(T()),
        left(nullptr),
        right(nullptr),
        parent(nullptr),
        color(BLACK) {}
  Node(const T& val)
      : value(val),
        left(nullptr),
        right(nullptr),
        parent(nullptr),
        color(RED) {}
};

namespace s21 {

template <typename Key>
class set;  // forward declaration

template <typename Key>
class RBtree {
  friend class set<Key>;

 public:
  RBtree() : root(NIL) {}
  RBtree(const Key& value) : root(NIL), tree_size(0) { insert(value); }
  RBtree(std::initializer_list<Key> const& items) : root(NIL), tree_size(0) {
    for (const auto& item : items) {
      insert(item);
    }
  }
  RBtree(const RBtree& other) : root(NIL), tree_size(0) {
    if (this != &other) {
      clear(root);
      copy_from(other.root);
    }
  }

  ~RBtree() { clear(root); }

  RBtree& operator=(const RBtree& other) {
    if (this != &other) {
      clear(root);
      copy_from(other.root);
    }
    return *this;
  }

  std::size_t size() const { return tree_size; }
  bool empty() const { return root == NIL; }

  void clear(Node<Key>* node_) {
    if (node_ != NIL) {
      clear(node_->left);
      clear(node_->right);
      delete node_;
    }
  }

  void printHelper(Node<Key>* root, std::string indent, bool last) {
    if (root != NIL) {
      std::cout << indent;
      if (last) {
        std::cout << "R----";
        indent += "   ";
      } else {
        std::cout << "L----";
        indent += "|  ";
      }
      std::string sColor = (root->color == RED) ? "RED" : "BLACK";
      std::cout << root->value << "(" << sColor << ")" << std::endl;
      printHelper(root->left, indent, false);
      printHelper(root->right, indent, true);
    }
  }
  Node<Key>* getRoot() { return root; }

  Node<Key>* insert(const Key& value) {
    Node<Key>* current = root;
    Node<Key>* parent = NIL;

    while (current != NIL) {
      if (value == current->value) {
        return nullptr;
      }
      parent = current;
      if (value < current->value) {
        current = current->left;
      } else {
        current = current->right;
      }
    }
    Node<Key>* new_node = new Node<Key>(value);
    new_node->parent = parent;

    if (parent == NIL) {
      root = new_node;
      new_node->color = BLACK;
      new_node->left = NIL;
      new_node->right = NIL;
      new_node->parent = NIL;
    } else if (value < parent->value) {
      parent->left = new_node;
    } else {
      parent->right = new_node;
    }
    new_node->left = NIL;
    new_node->right = NIL;
    new_node->parent = parent;
    new_node->color = RED;

    tree_size++;
    fixInsert(new_node);
    return new_node;
  }

  bool erase(const Key& key) {
    Node<Key>* erase_node = this->findNode(key);
    if (erase_node == NIL) {
      return false;
    }

    Node<Key>* y = erase_node;
    Node<Key>* x;
    bool y_original_color = y->color;

    if (erase_node->left == NIL) {
      x = erase_node->right;
      transplant(erase_node, erase_node->right);
    } else if (erase_node->right == NIL) {
      x = erase_node->left;
      transplant(erase_node, erase_node->left);
    } else {
      y = minimum(erase_node->right);
      y_original_color = y->color;
      x = y->right;

      if (y->parent == erase_node) {
        if (x != NIL) x->parent = y;
      } else {
        transplant(y, y->right);
        y->right = erase_node->right;
        y->right->parent = y;
      }

      transplant(erase_node, y);
      y->left = erase_node->left;
      y->left->parent = y;
      y->color = erase_node->color;
    }

    if (y_original_color == BLACK) {
      fixDelete(x);
    }

    delete erase_node;
    --tree_size;
    return true;
  }

  class TreeIterator {
   public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = Key;
    using difference_type = std::ptrdiff_t;
    using pointer = Key*;
    using reference = Key&;
    TreeIterator() : node_(NIL) {}
    explicit TreeIterator(Node<Key>* node) : node_(node) {}

    bool operator==(const TreeIterator& other) const {
      return node_ == other.node_;
    }
    bool operator!=(const TreeIterator& other) const {
      return node_ != other.node_;
    }

    Key& operator*() const { return node_->value; }

    TreeIterator& operator++() {
      if (node_ == NIL) return *this;

      if (node_->right != NIL) {
        node_ = node_->right;
        while (node_->left != NIL) {
          node_ = node_->left;
        }
      } else {
        Node<Key>* parent = node_->parent;
        while (parent != NIL && node_ == parent->right) {
          node_ = parent;
          parent = parent->parent;
        }
        node_ = parent;
      }
      return *this;
    }

    TreeIterator operator++(int) {
      TreeIterator temp = *this;
      ++(*this);
      return temp;
    }

   private:
    Node<Key>* node_;
  };

  class Const_TreeIterator {
   public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = Key;
    using difference_type = std::ptrdiff_t;
    using pointer = const Key*;
    using reference = const Key&;

    Const_TreeIterator() : node_(NIL) {}
    explicit Const_TreeIterator(Node<Key>* node) : node_(node) {}
    Const_TreeIterator(const TreeIterator& it) : node_(it.node_) {}

    bool operator==(const Const_TreeIterator& other) const {
      return node_ == other.node_;
    }
    bool operator!=(const Const_TreeIterator& other) const {
      return node_ != other.node_;
    }

    const Key& operator*() const { return node_->value; }

    Const_TreeIterator& operator++() {
      if (node_ == NIL) return *this;

      if (node_->right != NIL) {
        node_ = node_->right;
        while (node_->left != NIL) {
          node_ = node_->left;
        }
      } else {
        Node<Key>* parent = node_->parent;
        while (parent != NIL && node_ == parent->right) {
          node_ = parent;
          parent = parent->parent;
        }
        node_ = parent;
      }
      return *this;
    }

    Const_TreeIterator operator++(int) {
      Const_TreeIterator temp = *this;
      ++(*this);
      return temp;
    }

   private:
    Node<Key>* node_;
  };

  using iterator = TreeIterator;
  using const_iterator = Const_TreeIterator;
  iterator begin() { return iterator(minimum(root)); }
  iterator end() { return iterator(NIL); }
  const_iterator cbegin() const { return const_iterator(minimum(root)); }
  const_iterator cend() const { return const_iterator(NIL); }

  Node<Key>* findNode(const Key& key) const {
    Node<Key>* find_node = root;
    while (find_node != NIL && find_node->value != key) {
      if (key < find_node->value) {
        find_node = find_node->left;
      } else {
        find_node = find_node->right;
      }
    }
    return find_node;
  }
  Node<Key>* root;
  static inline Node<Key>* NIL = []() {
    Node<Key>* nil = new Node<Key>();
    // nil->value = Key();
    nil->color = BLACK;
    nil->left = nil;
    nil->right = nil;
    nil->parent = nil;
    return nil;
  }();

  std::size_t tree_size = 0;

 private:
  Node<Key>* minimum(Node<Key>* node) const {
    while (node->left != NIL) {
      node = node->left;
    }
    return node;
  }

  Node<Key>* maximum(Node<Key>* node) const {
    while (node->right != NIL) {
      node = node->right;
    }
    return node;
  }
  void transplant(Node<Key>* u, Node<Key>* v) {
    if (u->parent == NIL) {
      root = v;
    } else if (u == u->parent->left) {
      u->parent->left = v;
    } else {
      u->parent->right = v;
    }
    if (v != NIL) {
      v->parent = u->parent;
    }
  }
  void fixInsert(Node<Key>* new_node) {
    Node<Key>* uncle = NIL;
    while (new_node != root && new_node->parent->color == RED) {
      if (new_node->parent == new_node->parent->parent->right) {
        uncle = new_node->parent->parent->left;
        if (uncle != NIL && uncle->color == RED) {
          new_node = uncleRed(uncle, new_node);
        } else {
          new_node = uncleBlack(new_node);
        }
      } else if (new_node->parent == new_node->parent->parent->left) {
        uncle = new_node->parent->parent->right;
        if (uncle != NIL && uncle->color == RED) {
          new_node = uncleRed(uncle, new_node);
        } else {
          new_node = uncleBlack(new_node);
        }
      }
    }
    root->color = BLACK;
  }
  Node<Key>* uncleRed(Node<Key>* uncle, Node<Key>* new_node) {
    uncle->color = BLACK;
    new_node->parent->color = BLACK;
    new_node->parent->parent->color = RED;
    new_node = new_node->parent->parent;
    return new_node;
  }

  /* Before Right Rotation:
        x
       /
      y
     / \
    a   b
  After Right Rotation:
      y
     / \
    a   x
       /
      b                 */

  void right_rotate(Node<Key>* x) {
    Node<Key>* y = x->left;
    x->left = y->right;
    if (y->right != NIL) {
      y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == NIL) {
      root = y;
    } else if (x == x->parent->right) {
      x->parent->right = y;
    } else {
      x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
  }
  /*Before Rotation:
      x
       \
        y
       / \
      a   b

  After Left Rotation:
        y
       / \
      x   b
       \
        a           */

  void left_rotate(Node<Key>* x) {
    Node<Key>* y = x->right;
    x->right = y->left;
    if (y->left != NIL) {
      y->left->parent = x;
    }
    y->parent = x->parent;  // ← ВОТ ЭТА СТРОКА!
    if (x->parent == NIL) {
      root = y;
    } else if (x == x->parent->left) {
      x->parent->left = y;
    } else {
      x->parent->right = y;
    }
    x->parent = y;
    y->left = x;
  }

  Node<Key>* uncleBlack(Node<Key>* new_node) {
    if (new_node->parent == new_node->parent->parent->right) {
      if (new_node == new_node->parent->left) {
        new_node = new_node->parent;
        right_rotate(new_node);
      }
      new_node->parent->color = BLACK;
      new_node->parent->parent->color = RED;
      left_rotate(new_node->parent->parent);
    } else {
      if (new_node == new_node->parent->right) {
        new_node = new_node->parent;
        left_rotate(new_node);
      }
      new_node->parent->color = BLACK;
      new_node->parent->parent->color = RED;
      right_rotate(new_node->parent->parent);
    }
    return new_node;
  }
  void fixDelete(Node<Key>* x) {
    Node<Key>* sibling;

    while (x != root && (x == NIL || x->color == BLACK)) {
      sibling = (x->parent->right == x) ? x->parent->left : x->parent->right;
      if (sibling->color == RED) {
        sibling = sibling_red(x, sibling);
      }
      if (sibling->color == BLACK &&
          ((sibling->left == NIL || sibling->left->color == BLACK) &&
           (sibling->right == NIL || sibling->right->color == BLACK))) {
        sibling->color = RED;
        x = x->parent;
      } else {
        if (x->parent->left == x) {
          fixDeleteLeftCase(x, sibling);
        } else {
          fixDeleteRightCase(x, sibling);
        }
        x = root;
      }
    }
    if (x != NIL) x->color = BLACK;
  }

  void fixDeleteLeftCase(Node<Key>* x, Node<Key>* sibling) {
    if (sibling->right == NIL || sibling->right->color == BLACK) {
      if (sibling->left != NIL) sibling->left->color = BLACK;
      sibling->color = RED;
      right_rotate(sibling);
      sibling = x->parent->right;
    }

    sibling->color = x->parent->color;
    x->parent->color = BLACK;
    if (sibling->right != NIL) sibling->right->color = BLACK;
    left_rotate(x->parent);
  }

  void fixDeleteRightCase(Node<Key>* x, Node<Key>* sibling) {
    if (sibling->left == NIL || sibling->left->color == BLACK) {
      if (sibling->right != NIL) sibling->right->color = BLACK;
      sibling->color = RED;
      left_rotate(sibling);
      sibling = x->parent->left;
    }

    sibling->color = x->parent->color;
    x->parent->color = BLACK;
    if (sibling->left != NIL) sibling->left->color = BLACK;
    right_rotate(x->parent);
  }

  Node<Key>* sibling_red(Node<Key>* x, Node<Key>* sibling) {
    sibling->color = BLACK;
    x->parent->color = RED;
    if (x->parent->right == x) {
      left_rotate(x->parent);
      sibling = x->parent->right;
    } else {
      right_rotate(x->parent);
      sibling = x->parent->left;
    }
    return sibling;
  }

  void copy_from(Node<Key>* node) {
    if (node == NIL) return;
    insert(node->value);  // важно: используйте публичный insert
    copy_from(node->left);
    copy_from(node->right);
  }
};
}  // namespace s21