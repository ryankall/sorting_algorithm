
//#include <math.h>
#include <iostream>
using namespace std;





/** Finds the largest item in an array.
@pre The size of the array is >= 1.
@post The arguments are unchanged.
@param theArray The given array.
@param size The number of elements in theArray.
@return The index of the largest entry in the array. */
int findIndexofLargest( const int theArray[], int size);

/** Sorts the items in an array into ascending order.
@pre None.
@post The array is sorted into ascending order; the size of the array
is unchanged.
@param theArray The array to sort.
@param n The size of theArray. */
void selectionSort(int theArray[], int n)
{
    // last = index of the last item in the subarray of items yet
    //to be sorted;
    // largest = index of the largest item found
    for ( int last = n -1 ; last >= 1; last--)
    {
        // At this point, theArray[last+1..n-1] is sorted, and its
        // entries are greater than those in theArray[0..last].
        // Select the largest entry in theArray[0..last]
        int largest = findIndexofLargest(theArray, last+1);
        // Swap the largest entry, theArray[largest], with
        // theArray[last]
        std::swap(theArray[largest], theArray[last]);
    } // end for
} // end selectionSort
int findIndexofLargest( const int theArray[], int size)
{
    int indexSoFar = 0; // Index of largest entry found so far

    for ( int currentIndex = 1; currentIndex < size; currentIndex++)
    {
        // At this point, theArray[indexSoFar] >= all entries in
        // theArray[0..currentIndex - 1]
        if (theArray[currentIndex] > theArray[indexSoFar])
        indexSoFar = currentIndex;
    } // end for
return indexSoFar; // Index of largest entry
} // end findIndexofLargest


void insertionSort(int theArray[], int n)
{
// unsorted = first index of the unsorted region,
// loc = index of insertion in the sorted region,
// nextItem = next item in the unsorted region.
// Initially, sorted region is theArray[0],
//unsorted region is theArray[1..n-1].
// In general, sorted region is theArray[0..unsorted-1],
//unsorted region theArray[unsorted..n-1]
    for ( int unsorted = 1; unsorted < n; unsorted++)
    {
    // At this point, theArray[0..unsorted-1] is sorted.
    // Find the right position (loc) in theArray[0..unsorted]
    // for theArray[unsorted], which is the first entry in the
    // unsorted region; shift, if necessary, to make room
            int nextItem = theArray[unsorted];
            int loc = unsorted;
            while ((loc > 0) && (theArray[loc - 1] > nextItem))
            {
                // Shift theArray[loc - 1] to the right
                theArray[loc] = theArray[loc - 1];
                loc--;
            } // end for
    // At this point, theArray[loc] is where nextItem belongs
    theArray[loc] = nextItem; // Insert nextItem into sorted region
    
    }
// end while
// end insertionSort
}



/** Sorts the items in an array into ascending order.
@pre None.
@post theArray is sorted into ascending order; n is unchanged.
@param theArray The given array.
@param n The size of theArray. */
void bubbleSort(int theArray[], int n)
{
    bool sorted = false;
    // False when swaps occur
    int pass = 1;
    while (!sorted && (pass < n))
    {
        // At this point, theArray[n+1-pass..n-1] is sorted
        // and al of its entries are > the entries in theArray[0..n-pass]
        sorted = true;
        // Assume sorted
        for ( int index = 0; index < n - pass; index++)
        {
            // At this point, all entries in theArray[0..index-1]
            // are <= theArray[index]
            int nextIndex = index + 1;
            if (theArray[index] > theArray[nextIndex])
            {
                // Exchange entries
                swap(theArray[index], theArray[nextIndex]);
                sorted = false; // Signal exchange
            } // end if
        } // end for
       pass++;     // Assertion: theArray[0..n-pass-1] < theArray[n-pass]
    }
        
} // end while
// end bubbleSort


/*****************************************************/

const int MAX_SIZE = 10 ;
/** Merges two sorted array segments theArray[first..mid] and
theArray[mid+1..last] into one sorted array.
@pre first <= mid <= last. The subarrays theArray[first..mid] and
theArray[mid+1..last] are each sorted in increasing order.
@post theArray[first..last] is sorted.
@param theArray The given array.
@param first The index of the beginning of the first segment in
theArray.
@param mid The index of the end of the first segment in theArray;
mid + 1 marks the beginning of the second segment.
@param last The index of the last element in the second segment in
theArray.
@note This function merges the two subarrays into a temporary
array and copies the result into the original array theArray. */
void merge(int theArray[], int first, int mid, int last)
{
    int tempArray[MAX_SIZE]; // Temporary array
    // Initialize the local indices to indicate the subarrays
    int first1 = first;
    // Beginning of first subarray
    int last1 = mid;
    // End of first subarray
    int first2 = mid + 1;
    // Beginning of second subarray
    int last2 = last;
    // End of second subarray
    // While both subarrays are not empty, copy the
    // smaller item into the temporary array
    int index = first1;
    // Next available location in tempArray
    while ((first1 <= last1) && (first2 <= last2))
    {
        // At this point, tempArray[first..index-1] is in order
        if (theArray[first1] <= theArray[first2])
        {
            tempArray[index] = theArray[first1];
            first1++;
        }
        else
        {
            tempArray[index] = theArray[first2];
            first2++;
        } // end if
    index++;
    }
    // end while
    // Finish off the first subarray, if necessary
    while (first1 <= last1)
    {
        // At this point, tempArray[first..index-1] is in order
        tempArray[index] = theArray[first1];
        first1++;
        index++;
    } // end while
    
    // Finish off the second subarray, if necessary
    while (first2 <= last2)
    {
        // At this point, tempArray[first..index-1] is in order
        tempArray[index] = theArray[first2];
        first2++;
        index++;
    } // end for

 // Copy the result back into the original array
    for (index = first; index <= last; index++)
    theArray[index] = tempArray[index];


}

/** Sorts the items in an array into ascending order.
@pre theArray[first..last] is an array.
@post theArray[first..last] is sorted in ascending order.
@param theArray The given array.
@param first The index of the first element to consider in theArray.
@param last The index of the last element to consider in theArray.*/
void mergeSort(int theArray[], int first, int last)
{
    if (first < last)
    {
        // Sort each half
        int mid = first + (last - first) / 2; // Index of midpoint
        // Sort left half theArray[first..mid]
        mergeSort(theArray, first, mid);
        // Sort right half theArray[mid+1..last]
        mergeSort(theArray, mid + 1, last);
        // Merge the two halves
        merge(theArray, first, mid, last);
    } // end if
} // end mergeSort



void quickSort(int arr[], int first, int last) {

      int i = first, j = last;

      int tmp;

      int pivot = arr[(first + last) / 2];
      /* partition */

      while (i <= j) {
            while (arr[i] < pivot)
                i++;

            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };

     /* recursion */
      if (first < j)
            quickSort(arr, first, j);

      if (i < last)
            quickSort(arr, i, last);

}

//test functions
int main(){
 
    int a[]= {2,3,4,5,7,6,8,10,9,1};
    
    quickSort(a, 0, 9);
    for(int i= 0; i<10;i++){
        cout<<a[i]<<" ";
    }
    
    return 0;
}
