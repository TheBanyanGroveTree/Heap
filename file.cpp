#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
  int arr[100]{}; // Initialize int arr

  ofstream outFile("numbers.txt"); // Create and open output file

  srand(time(0)); // Seed random number generator
  // Generate random numbers between 1-1000 and write to file
  int min = 1;
  int max = 1000;
  for (int i = 0; i < 100; i++) {
    arr[i] = min + (rand() % (max - min + 1));
    outFile << arr[i] << " ";
  }
  
  outFile.close();
  
  return 0;
}
