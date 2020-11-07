#ifndef SEGMENT_TREE_SEGMENT_TREE_IPP_
#define SEGMENT_TREE_SEGMENT_TREE_IPP_

#include <iostream>
#include <vector>
#include <algorithm>

namespace eda {

namespace segment_tree {

template <typename T>
SegmentTree<T>::SegmentTree(std::vector<T> &data) :
	data_(4 * data.size()),
	size_(data.size())
{
	this->build(data, 0, data.size() - 1, 0);
}

template <typename T>
void SegmentTree<T>::print() {
	// for (int i = 0; i < this->size_; i++) {
	// 	std::cout << this->data_[i] << ' ';
	// }
	// std::cout << std::endl;

	this->print(0, this->size_ - 1, 0, 0);
}

template <typename T>
void SegmentTree<T>::build(std::vector<T> &data, int low, int high, int root) {
	if (low == high) {
		this->data_[root] = data[low];
		return;
	}

	int mid = (low + high) / 2;
	int left = 2 * root + 1;
	int right = 2 * root + 2;

	this->build(data, low, mid, left);
	this->build(data, mid + 1, high, right);

	this->data_[root] = std::min(this->data_[left], this->data_[right]);
}

template <typename T>
T SegmentTree<T>::range_query(int low, int high, int, int, int root) {

}

template <typename T>
void SegmentTree<T>::print(int low, int high, int root, int depth) {
	int mid = (low + high) / 2;

	if (low != high)
		this->print(mid + 1, high, 2 * root + 2, depth + 1);

	for (int i = 0; i < depth; i++) {
		std::cout << "    ";
	}
	std::cout << this->data_[root] << std::endl;

	if (low != high)
		this->print(low, mid, 2 * root + 1, depth + 1);
}

} // namespace segment_tree

} // namespace eda

#endif // SEGMENT_TREE_SEGMENT_TREE_IPP_
