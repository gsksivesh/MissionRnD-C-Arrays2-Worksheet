/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
*/
#include<stdio.h>
#include<stdlib.h>
int findSingleOccurenceNumber(int *arr, int len)
{
	int i, j;
	int count;
	if ((len - 1) % 3 != 0)
		return -1;
	if (arr == NULL)
		return -1;
	for (i = 0; i < len; i++)
	{
		count = 0;
		for (j = 0; j < len; j++)
		{
			if (i == j)
				continue;
			if (arr[i] == arr[j])
				count++;
		}
		if (count != 2)
			return arr[i];
	}
}
