#include <iostream>
#include "../util.h"
using namespace std;


struct RetValSearch {
      bool found;
      int index;
      RetValSearch() : found(false), index(-1) {}
      RetValSearch(bool newFound, int newIndex) : found(newFound), index(newIndex) {}
};

template <typename T>
int binarnoTrazi (T polje[], int n, T x) {
      auto left = 0;
      auto right = n - 1;
      auto found = false;
      auto attempts = 0;
      auto index = -1;
      while (left <= right) {
            auto middle = (left + right) / 2;
            ++attempts;
            std::cout << "Searching A[" << left << " : " << right
                   << "]. Middle element: A[" << middle << "] = " << polje[middle]
                   << ". Attempts: " << attempts << ".\n";
            if (polje[middle] < x) {
                  left = middle + 1;
            } else if (polje[middle] > x) {
                  right = middle - 1;
            } else {
                  found = true;
                  index = middle;
                  break;
            }
      }
      return found ? index : -1;
}

int main () {
      int n, x; cin >> n >> x;
      float arr1[n];
      int arr2[n];
      for(int i = 0; i < n; i++) {
            arr1[i] = i * 1.1;
            arr2[i] = i + 3;
      }
      printArr(arr1, n);
      printArr(arr2, n);
      cout << binarnoTrazi(arr1, n, (float) x) << endl;
      cout << binarnoTrazi(arr2, n, x) << endl;
}
