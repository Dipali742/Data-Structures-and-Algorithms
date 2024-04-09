/*
   Time Complexity:O(n)
   Space Complexity:O(1)
*/

void heapify(vector<int>&arr, int n, int index)
{
	int largest = index;
	// If left child is greater than replace it with node
	if (2 * index + 1 < n && arr[largest] < arr[2 * index + 1])
	{
		largest = 2 * index + 1;
	}
	// If right child is greater than replace it with node
	if (2 * index + 2 < n && arr[largest] < arr[2 * index + 2])
	{
		largest = 2 * index + 2;
	}

	// If any child has more value call heapify on corresponding sub-tree.
	if (largest != index)
	{
		swap(arr[largest], arr[index]);
		heapify(arr, n, largest);
	}


}
vector<int>MinToMaxHeap(int n, vector<int>&arr)
{
	// Calling heapify process in bottom-up manner.
	for (int i = n / 2; i >= 0; i--)
	{
		heapify(arr, n, i);
	}
	return arr;
}
