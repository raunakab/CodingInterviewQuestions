#include <stdlib.h>
#include <stdio.h>
#include <vector>

#define HOLE -1

using namespace std;

int putBack(vector<int> & arr, int const val) {
	int & src(arr[val-1]);
	int popped(src);
	
	src = val;
	return popped;
}

void findIndex(vector<int> const & arr, int const length, int & index) {
	for (; index<length; ++index) if (arr[index] != index+1) return;
	return;
}

int firstDuplicate(vector<int> & arr) {
	int const length(arr.size());
	int index(0);
	findIndex(arr,length,index);

	if (index >= length) return -1;

	int popped(arr[index]);
	int prevPopped(popped);
	arr[index] = HOLE;

	while (index < length) {
		prevPopped = popped;
		popped = putBack(arr,prevPopped);

		if (popped == HOLE) {
			findIndex(arr,length,index);
			if (index < length) {
				popped = arr[index];
				arr[index] = HOLE;
			}
		} else if (prevPopped == popped) return popped;
	}

	return -1;
}

// int firstDuplicate(vector<int> & arr) {
// 	int length(arr.size());
// 	int copy(-1);
	
// 	for (int i(0); i<length; ++i) {
// 		copy = arr[i];
// 		result = popReplace(arr,i);
// 		if (copy == result) return result;
// 		else if (result != 0) putBack(arr,result);
// 	}
// 	return -1;
// }

int main() {
	vector<int> test0({1,2});
	vector<int> test1({1,2,1,3,5});
	vector<int> test2({});
	vector<int> test3({5,5,5,5,5,5,5,5});

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