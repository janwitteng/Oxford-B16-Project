#ifndef BINARY_TREE_COMPLETE
#define BINARY_TREE_COMPLETE

#include <limits>
#include <vector>

// Wraps a vector in a complete binary tree
template <typename V> struct CompleteBT {
  std::vector<V> *_storage;
  size_t _root;
  size_t _size;

  CompleteBT(std::vector<V> *storage) : _storage{storage}, _root{0}, _size{storage->size()} {}
  CompleteBT(std::vector<V> *storage, size_t root, size_t size)
      : _storage{storage}, _root{root}, _size{size} {}

  CompleteBT subtree(size_t root) const { return CompleteBT{_storage, root, _size}; }

  friend V &value(CompleteBT &t) { return (*t._storage)[t._root]; }
  friend const V &value(const CompleteBT &t) { return (*t._storage)[t._root]; }
  friend CompleteBT parent(const CompleteBT &t) {
    if (t._root == 0)
      return t.subtree(std::numeric_limits<size_t>::max());
    return t.subtree((t._root - 1) / 2);
  }
  friend CompleteBT left(const CompleteBT &t) { return t.subtree(2 * t._root + 1); }
  friend CompleteBT right(const CompleteBT &t) { return t.subtree(2 * t._root + 2); }

  explicit operator bool() const { return _root < _size; } // not empty
};

#endif