/**
   Description: Max heap implementation
   Author: Aahana Sapra
   Date: 03/01/2026
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Define heap struct
struct Heap {
  int size;
  int arr[size]{};
};


// Define function prototypes
void heapify(int i);
void insert(int key); // enqueue
int extractMax();
void deleteKey(int i); // dequeue
void printHeap();

int main() {
  // Initialize heap
  Heap* heap = new Heap();

  // Define const var for commands
  const string MANUAL = "MANUAL";
  const string FILE = "FILE";
  const string MAX = "MAX";
  const string DELETE = "DELETE";
  const string PRINT = "PRINT";
  const string QUIT = "QUIT";

  string userCommand = ""; // Declare str for user input

  // Continue prompting user for input until QUIT command
  bool keepModifying = true;
  while (keepModifying) {
    // read in user input
    cout << "Enter a command (MANUAL, FILE, MAX, DELETE, PRINT, QUIT): ";
    getline(cin, userCommand);

    // convert input to uppercase for comparison
    for (int i = 0; i < userCommand.size(); i++) {
      userCommand[i] = toupper(userCommand[i]);
    }
    
    // validate input
    if ((userCommand == MANUAL) && (userCommand == FILE) &&
	(userCommand == MAX) && (userCommand == DELETE) &&
	(userCommand == PRINT) && (userCommand == QUIT)) {
      cout << "Please input MANUAL, FILE, MAX, DELETE, PRINT, or QUIT." << endl;
    } else {
      // call appropriate method or exit program
      if (userCommand == MANUAL) {

      } else if (userCommand == FILE) {

      } else if (userCommand == MAX) {

      } else if (userCommand == DELETE) {

      } else if (userCommand == PRINT) {

      } else if (userCommand == QUIT) {

      }
    }
  }
  
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

// Insert new key into heap
void insert(int key) {
  arr[size - 1] = key; // add to end of arr
  int i = size - 1; // initial index = last element of arr

  // while key is greater than parent and i is not root
  // iteratively swap key with parent and update i to parent
  while ((i != 0) && (arr[(i - 1) / 2] < arr[i])) {
    swap(arr[i], arr[(i - 1) / 2]);
    i = (i - 1) / 2;
  }
}

// Extract maximum element (top priority) from heap
int extractMax() {
  // throw error if heap is empty
  if (size <= 0) {
    cout << "Heap underflow" << endl;
    return;
  }
  // remove and return single element
  if (size == 1) {
    int root = arr[0];
    arr[size - 1] = NULL;
    return root;
  }

  int root = arr[0]; // store max in temp var
  arr[0] = arr[size - 1]; // replace root with last element
  arr[size - 1] = NULL; // del last element
  heapify(0); // restore heap property

  return root;
}

// Delete key at given index
void deleteKey(int i) {
  // throw error if index out of bounds
  if (i >= size) {
    cout << "Out of bounds" << endl;
    return;
  }

  arr[i] = arr[size - 1]; // replace key with last element
  arr[size - 1] = NULL; // del last element
  heapify(i); // restore heap property
}


// Print heap elements
void printHeap() {
  for (int val : arr) {
    cout << val << " ";
  }
  cout << endl;
}
