#ifndef SEGMENT_TREE_SEGMENT_TREE_HPP_
#define SEGMENT_TREE_SEGMENT_TREE_HPP_

#include <vector>

namespace eda {

namespace segment_tree {

template <typename T>
class SegmentTree {
private:
	std::vector<T> data_;
	int size_;

public:
	SegmentTree(std::vector<T> &);
	T range_query(int, int);
	void print();

private:
	void build(std::vector<T> &, int, int, int);
	T range_query(int, int, int, int, int);
	void print(int, int, int, int);
};

} // namespace segment_tree

} // namespace eda

#include "impl/segment_tree.ipp"

#endif // SEGMENT_TREE_SEGMENT_TREE_HPP_
