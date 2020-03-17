// 13_Roman_to_Integer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int changeRoman(char *s);

int romanToInt(char* s) {

	int sum = changeRoman(s);

	int pre, cur;

	for (int i = 1; i < strlen(s); ++i)
	{
		pre = changeRoman(s + i - 1);
		cur = changeRoman(s + i);
		if (pre >= cur)
		{
			sum += cur;
		}
		else
		{
			sum = sum - pre * 2 + cur;
		}
	}
	/*while (*s != '\0')
	{
		sum += changeRoman(s);
		s++;
	}*/
	return sum;
}

int changeRoman(char *s)
{
	int data = 0;
	switch (*s)
	{
	case 'I': data = 1; break;
	case 'V': data = 5; break;
	case 'X': data = 10; break;
	case 'L': data = 50; break;
	case 'C': data = 100; break;
	case 'D': data = 500; break;
	case 'M': data = 1000; break;
	default: break;
	}
	return data;
}

int main()
{
	int num = romanToInt("MCMXCVI");
	printf("%d\n", num);
	return 0;
}

