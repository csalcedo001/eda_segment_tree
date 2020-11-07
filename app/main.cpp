#include <iostream>

#include "segment_tree.hpp"

using namespace std;

int main() {
	int n = 6;

	vector<int> elements(n);

	for (int i = 0; i < n; i++) {
		elements[i] = i + 1;
	}

	eda::segment_tree::SegmentTree<int> s(elements);

	s.print();

	return 0;
}
