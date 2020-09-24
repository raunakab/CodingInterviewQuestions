#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

int firstDuplicate(std::vector<int> const & arr) {
	int length(arr.size());
	std::vector<int> hashArr(length, -1); // initialize hashArr to be all -1's.

	for (int i(0); i<length; ++i) {
		int currVal(arr[i]);
		int firstSeen(hashArr[currVal-1]);

		if (firstSeen != -1) return currVal;
		else hashArr[currVal-1] = i;
	}

	return -1;
}

int main() {
	vector<int> const test0({1,2,3,4});
	vector<int> const test1({1,2,1,3,5});
	vector<int> const test2({});
	vector<int> const test3({1,2,3,4,5,4,5});

	int result0(firstDuplicate(test0));
	int result1(firstDuplicate(test1));
	int result2(firstDuplicate(test2));
	int result3(firstDuplicate(test3));

	printf("Result 0: %i\n",result0);
	printf("Result 1: %i\n",result1);
	printf("Result 2: %i\n",result2);
	printf("Result 3: %i\n",result3);

	return 0;
}