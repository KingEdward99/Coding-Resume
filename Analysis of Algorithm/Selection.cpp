/*
    This algorithms finds the kth largest element in an array using the selection algorithm.

    An idea I think I have is implementing the algorithm to find the tallest person on a sports team. 
*/

#include <iostream>
using namespace std;

/*
FindKthLargest( list, N, K )
          list  the values to look through
          N     the size of the list
          K     the element to select
          for i = 1 to K do
             largest = list[1]
             largestLocation = 1

   for j = 2 to N-(i-1) do
      if list[j] > largest then
         largest = list[j]
         largestLocation = j
      end if
end for
   Swap( list[N-(i-1)], list[largestLocation] )
end for
return largest

*/