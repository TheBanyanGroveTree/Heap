/**
   Description: Max heap implementation
   Author: Aahana Sapra
   Date: 03/01/2026
*/

#include <iostream>
#include <string>

using namespace std;

// Define heap struct
struct Heap {
  int arr[];
  int size;
};


// Define function prototypes
void heapify(int i);
void insert(int key); // enqueue
int extractMax();
int getMax();
void deleteKey(); // dequeue
void printHeap();

int main() {

  return 0;
}

// Maintain heap property
void heapify(int i) {
  // initialize indices & heap size
  int largest = i;
  int left = (2*i) + 1;
  int right = (2*i) + 2;
  int size = array.size();

  // check if left child exists
  // if greater than current largest node, update largest
  if ((left < size) && (arr[left] > arr[largest])) {
    largest = left;
  }
  
  // check if right child exists
  // if greater than current largest node, update largest
  if ((right < size) && (arr[right] > arr[largest])) {
    largest = right;
  }
  
  if (largest != i) {
    // swap current node with largest node
    swap(arr[i], arr[largest]);
	 
    // recursively heapify to subtree
    heapify(largest);
  }
}
