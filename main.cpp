/**
   Description: Max heap implementation
   Author: Aahana Sapra
   Date: 03/01/2026
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <limits>
#include <ios>
#include <fstream>

using namespace std;

// Define heap struct
struct Heap {
  static const int size = 100; // number of elements it can hold
  int arr[size]{}; // arr of keys
  int count; // actual number of elements
};


// Define function prototypes
void heapify(Heap*& heap, int i);
void insert(Heap*& heap, int key); // enqueue
int extractMax(Heap*& heap);
void deleteAll(Heap* heap);
void printHeap(Heap* heap, int index, int depth);

int main() {
  // Initialize heap and size var
  Heap* heap = new Heap();
  heap->count = 0;

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
    if ((userCommand != MANUAL) && (userCommand != FILE) &&
	(userCommand != MAX) && (userCommand != DELETE) &&
	(userCommand != PRINT) && (userCommand != QUIT)) {
      cout << "Please input MANUAL, FILE, MAX, DELETE, PRINT, or QUIT." << endl;
    } else {
      // call appropriate method or exit program
      if (userCommand == MANUAL) {
	// read in up to 100 int and store in heap arr
	cout << "Enter up to " << heap->size
	     <<" integers separated by spaces."
	     << " Hit enter to stop inputting numbers." << endl;

	string inputLine = "";
	getline(cin, inputLine); // read entire line

	// parse line
	stringstream ss(inputLine);
	int key = 0; // don't write directly into arr
	while ((ss >> key) && (heap->count < 100)) {
	  insert(heap, key);
	}

      } else if (userCommand == FILE) {
	ifstream file("numbers.txt"); // open file

	// Read in space separated numbers
	int key = 0;
	while ((file >> key) && (heap->count < 100)) {
	  insert(heap, key);
	}

	file.close();
		
      } else if (userCommand == MAX) {
	// check if heap is empty
	if (heap->count == 0) {
	  cout << "Heap is empty." << endl;
	} else {
	  cout << extractMax(heap) << endl;
	}
      } else if (userCommand == DELETE) {
	deleteAll(heap);
      } else if (userCommand == PRINT) {
	printHeap(heap, 0, 0);
      } else if (userCommand == QUIT) {
	delete heap; // delete dynamically allocated mem
	keepModifying = false;
      }
    }
  }
  
  return 0;
}


// Maintain heap property
void heapify(Heap*& heap, int i) {
  // initialize indices
  int largest = i;
  int left = (2*i) + 1;
  int right = (2*i) + 2;

  // check if left child exists
  // if greater than current largest node, update largest
  if ((left < heap->count) && (heap->arr[left] > heap->arr[largest])) {
    largest = left;
  }
  
  // check if right child exists
  // if greater than current largest node, update largest
  if ((right < heap->count) && (heap->arr[right] > heap->arr[largest])) {
    largest = right;
  }
  
  if (largest != i) {
    // swap current node with largest node
    swap(heap->arr[i], heap->arr[largest]);
	 
    // recursively heapify to subtree
    heapify(heap, largest);
  }
}


// Insert new key into heap
void insert(Heap*& heap, int key) {
  heap->arr[heap->count] = key; // add to end of arr
  heap->count++;
  int i = heap->count - 1; // initial index = last element of arr

  // while key is greater than parent and i is not root
  // iteratively swap key with parent and update i to parent
  while ((i != 0) && (heap->arr[(i - 1) / 2] < heap->arr[i])) {
    swap(heap->arr[i], heap->arr[(i - 1) / 2]);
    i = (i - 1) / 2;
  }
}


// Extract maximum element (top priority) from heap
int extractMax(Heap*& heap) {
  // remove and return single element
  if (heap->count == 1) {
    int root = heap->arr[0];
    heap->arr[heap->count - 1] = 0;
    heap->count--;
    return root;
  }

  int root = heap->arr[0]; // store max in temp var
  heap->arr[0] = heap->arr[heap->count - 1]; // replace root with last element
  heap->arr[heap->count - 1] = 0; // del last element
  heap->count--; // decrease count
  heapify(heap, 0); // restore heap property

  return root;
}


// Delete all numbers from heap and output
void deleteAll(Heap* heap) {
  int count = heap->count; // set before extractMax alters
  for (int i = 0; i < count; i++) {
    cout << extractMax(heap) << " ";
  }
  cout << endl;
}


// Traverse heap recursively to print sideways
void printHeap(Heap* heap, int index, int depth) {
  // Base case
  if (index >= heap->count) {
    return;
  }

  // Print left child first
  // depth = how far node is from root (num edges)
  printHeap(heap, (2 * index + 1), (depth + 1));

  // Print current node with indentation
  for (int i = 0; i < depth; i++) {
    cout << "\t";
  }
  cout << heap->arr[index] << endl;

  // print right child
  printHeap(heap, (2 * index + 2), (depth + 1));
}
