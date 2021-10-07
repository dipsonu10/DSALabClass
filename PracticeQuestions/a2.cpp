/*
given an array and an integer k find the maximum for each and every contiguous subarray of size k
*/
/***
 * @example 
 * input arr[] = {1,2,3,1,4,5,2,3,6}, k=3
 * output 3 3 4 5 5 5 6
 * 
 * input arr[] = {8,5,10,7,9,4,15,12,90,13}, k=4
 * output 10 10 10 15 15 90 90 
 */
// CPP program for the above approach
#include <bits/stdc++.h>
using namespace std;

// A Dequeue (Double ended queue) based
// method for printing maximum element of
// all subarrays of size k
void printKMax(int arr[], int n, int k)
{
	// Create a Double Ended Queue, Qi that will store indexes of array 
	// elements The queue will store indexes of useful elements in every 
	// window and it will maintain decreasing order of values from 
	// front to rear in Qi, i.e., arr[Qi.front[]] to arr[Qi.rear()] 
	// are sorted in decreasing order
	std::deque<int> Qi(k);

	/* Process first k (or first window)
	elements of array */
	int i;
	for (i = 0; i < k; ++i)
	{
		// For every element, the previous
		// smaller elements are useless so
		// remove them from Qi
		while ((!Qi.empty()) && arr[i] >= arr[Qi.back()])
			// Remove from rear
			Qi.pop_back();

		// Add new element at rear of queue
		Qi.push_back(i);
	}

	// Process rest of the elements,
	// i.e., from arr[k] to arr[n-1]
	for (; i < n; ++i)
	{
	
		// The element at the front of
		// the queue is the largest element of
		// previous window, so print it
		cout << arr[Qi.front()] << " ";

		// Remove the elements which
		// are out of this window
		while ((!Qi.empty()) && Qi.front() <= i - k)
			// Remove from front of queue
			Qi.pop_front();

		// Remove all elements smaller than the currently being 
		// added element (remove useless elements)
		while ((!Qi.empty()) && arr[i] >= arr[Qi.back()])
			Qi.pop_back();

		// Add current element at the rear of Qi
		Qi.push_back(i);
	}

	// Print the maximum element
	// of last window
	cout << arr[Qi.front()]<<endl;
}

// Driver code
int main()
{
	int arr[] = { 1,2,3,1,4,5,2,3,6 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 3;
	printKMax(arr, n, k);
	return 0;
}

/**
 * 1, 2, 3, 1, 4, 5, 2, 3, 6->ele
 * 0  1  2  3  4  5  6  7  8->index
 *                &
 * k = 3
 * 
 * 
 * to store the index
 * +----------+
 *  4
 * +----------+
 * 
 * O/P
 * 3_3_4_
 */