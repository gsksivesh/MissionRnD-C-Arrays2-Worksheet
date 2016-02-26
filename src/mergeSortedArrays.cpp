/*
OVERVIEW: You are given 2 bank statements that are ordered by date - Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int date_to_number1(char *date)
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
struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen)
{
	int i_A = 0, i_B = 0;
	int i_answer = 0;
	struct transaction *answer = NULL;
	int prev_date = 0, next_date = 0;
	if (A == NULL || B == NULL || ALen == 0 || BLen == 0)
		return NULL;
	answer = (struct transaction*)malloc(sizeof(struct transaction)*(ALen + BLen));
	while (i_A < ALen && i_B < BLen)
	{
		if (date_to_number1(A[i_A].date) < date_to_number1(B[i_B].date))
		{
			answer[i_answer] = A[i_A];
			i_A++;

		}
		else
		{
			answer[i_answer] = B[i_B];
			i_B++;
		}
		i_answer++;
	}
	while (i_A < ALen)
	{
		answer[i_answer] = A[i_A];
		i_A++;
		i_answer++;
	}
	while (i_B < BLen)
	{
		answer[i_answer] = B[i_B];
		i_B++;
		i_answer++;
	}
	return answer;
}
