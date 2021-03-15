/*

Suppose you have a sorted array of infinite numbers, how would you search an element in the array?

*/

//CODE

int search(arr,key)
{
	int low = 0;
	int high = 1;
	while(key > arr[high])
	{
	    low = high;
	    high = high * 2;
	}
     //Now we got a proper low and high value so we will apply binary search with these values.

	binarysearch(arr,low,high);
}