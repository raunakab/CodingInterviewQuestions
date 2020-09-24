int putBack(vector<int> & arr, int const val) {
	int & src(arr[val-1]);
	int popped(arrVal);
	
	src = val;
	return popped;
}
