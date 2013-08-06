#include <iostream>
#include <stdlib.h>
#include <time.h>          
using namespace std;

const int NUM_PRODUCTS = 32768;
const int LOW_VALUE = 0;
const int FAILURE = -1;

int lSearch(int arr [], int target);
int bSearch(int arr [], int target);
void showResults(int result, char str [], int target);

int main()
{
   int arr1[NUM_PRODUCTS], arr2[NUM_PRODUCTS];
   int randInt, result, target1, target2, k;
   //Set unsorted array arr1 and sorted array arr2
   srand((unsigned) time(NULL)); 

   for (k = 0; k < NUM_PRODUCTS; k++)
   {
      randInt = rand() % (NUM_PRODUCTS + 1) + LOW_VALUE;
      arr1[k] = randInt;
      arr2[k] = k;
   }

   //Set target1
   cout << "Enter product id: ";
   cin >> target1;

   //linear search for target
   result = lSearch(arr1, target1);
   showResults(result, "L Search", target1);

   //Set target2
   cout << "Enter product id: ";
   cin >> target2;

   //Binary search for target2
   result = bSearch(arr2, target2);
   showResults(result, "B Search", target2);

   cout << endl;
   return 0;
}


int lSearch(int arr [], int target)
{
int position = 0;
int result = -1;

while (result == -1 && position < NUM_PRODUCTS)
{
   if (arr[position] == target)
   {
      result = position;   
   }
   position++;
}
return result;
}

int bSearch(int arr [], int target)
{
   int middlePosition;
   int middleValue;
   int result = -1;
   int low = 0;
   int high = NUM_PRODUCTS - 1;

   //Failure case
   if (target < 0 || target > NUM_PRODUCTS)
      return FAILURE;
   while (result == -1 && low <= high)
   {
      middlePosition = (low + high) / 2;
      middleValue = arr[middlePosition];
      if (target == middleValue)
      {
         result = middlePosition;
      }
      else if (target < middleValue)
         high = middlePosition - 1;
      else
         low = middlePosition + 1;

   }
   return result;
}

void showResults(int result, char str [], int target)
{
   cout << endl << endl << str << endl << "-----------------" << endl;
   if (result != FAILURE)
      cout << "Found product id [" << target << "] in array position [" << result << "]" << endl << endl;
   else
      cout << "TARGET [" << target << "] not found." << endl << endl << endl;
}