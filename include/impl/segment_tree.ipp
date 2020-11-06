#ifndef SEGMENT_TREE_SEGMENT_TREE_IPP_
#define SEGMENT_TREE_SEGMENT_TREE_IPP_

#include <iostream>
#include <vector>
#include <algorithm>

namespace eda {

namespace segment_tree {

template <typename T>
SegmentTree<T>::SegmentTree(std::vector<T> &data) :
	data_(4 * data.size())
{
	this->build(data, 0, data.size() - 1, 0);
}

template <typename T>
void SegmentTree<T>::print() {
	for (auto e : this->data_) {
		std::cout << e << ' ';
	}
	std::cout << std::endl;
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

} // namespace segment_tree

} // namespace eda

#endif // SEGMENT_TREE_SEGMENT_TREE_IPP_
