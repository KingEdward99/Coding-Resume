/*
    Given a collection of wide receivers (their name, and receiving yards), using shell sort algorithm ranks them
    according to either total yards or total touchdowns.
*/

/*
    Shell sort pseudocode:
    	 Shellsort( list, N )
          list  the elements to be put into order
          N     the number of elements in the list
	passes = [lg N]
	while (passes ≥ 1) do 
	increment = 2passes - 1
	for start = 1 to increment do 
	      InsertionSort( list, N, start, increment )
   end for
	   passes = passes - 1
end while

*/