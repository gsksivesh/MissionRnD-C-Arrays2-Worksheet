/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int date_to_number(char *date)
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
int countGreaterNumbers(struct transaction *Arr, int len, char *date)
{
	int i, count = 0;
	int given_date;
	given_date = date_to_number(date);
	for (i = 0; i < len; i++)
	{
		if (date_to_number(Arr[i].date)>given_date)
			count++;
	}
	return count;
}
