/*
OVERVIEW: You are given 2 bank statements that are ordered by date. Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int date_to_number4(char *date)
{
	int i;
	int idate = 0, imonth = 0, iyear = 0;
	for (i = 0; date[i] != '\0'; i++)
	{
		if (date[i] > '9' || date[i] < '0')
			break;
		idate = idate * 10 + (date[i] - '0');
	}
	i++;
	for (; date[i] != '\0'; i++)
	{
		if (date[i] > '9' || date[i] < '0')
			break;
		imonth = imonth * 10 + (date[i] - '0');
	}
	i++;
	for (; date[i] != '\0'; i++)
	{
		if (date[i] > '9' || date[i] < '0')
			break;
		iyear = iyear * 10 + (date[i] - '0');
	}
	idate = idate + imonth * 100 + iyear * 10000;
	return idate;
}
struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) 
{
	struct transaction *ans;
	int Aindex, Bindex;
	int ansindex=0;
	int Adate, Bdate;
	if (A == NULL || B == NULL)
		return NULL; 
	ans = (struct transaction*)malloc(sizeof(struct transaction));
	
	for (Aindex = 0; Aindex < ALen; Aindex++)
	{
		Adate = date_to_number4(A[Aindex].date);
		for (Bindex = 0; Bindex < BLen; Bindex++)
		{
			Bdate = date_to_number4(B[Bindex].date);
			if (Adate < Bdate)
				break;
			else if (Adate == Bdate)
			{
				ans[ansindex] = B[Bindex];
				ansindex++;
				ans = (struct transaction*)realloc(ans, sizeof(struct transaction)*(ansindex + 1));
			}
		}
	}
	if (ansindex == 0)
		return NULL;
	return ans;
}
