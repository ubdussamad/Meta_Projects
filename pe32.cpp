#include <iostream>
#include <string>

using namespace std;
int width (long int num);
int check_pan_digital (long int num1, long int num2, long int num3);
int chk_digit (long int num, int target);
int chk_ext (long int num);
long int buffer[10];
long int ci = 0;

int main ()
{
  long int _tmp = 90;
  long long int sum = 0;
  for (int i = 1; i < 99; i++)
    {
      for (int j = 0; j < 9999; j++)
	{
	  long int product = i * j;
	  long int total = width (i) + width (j) + width (product);
	  if (total != 9)
	    {
	      continue;
	    }
	  if (check_pan_digital (i, j, product))
	    {
	      if (chk_ext (product) == 0)
		{
		  sum += product;
		  buffer[ci] = product;
		  ci++;
		}
	    }
	}
    }
  cout << "The sum is:" << sum << endl;
  return (0);
}

int chk_ext (long int num)
{				// Returns 1 if it's present else 0
  for (int i = 0; i < ci + 1; i++)
    {
      if (buffer[i] == num)
	{
	  return (1);
	}
    }
  return (0);
}

int check_pan_digital (long int num1, long int num2, long int num3)
{
  for (int i = 1; i < 10; i++)
    {				//Gets something done out of order
      if (chk_digit (num1, i) == 0 && chk_digit (num2, i) == 0
	  && chk_digit (num3, i) == 0)
	{
	  return (0);
	}
    }
  return (1);
}

int chk_digit (long int num, int target)
{
  while (num > 10)
    {
      if (target == num % 10)
	{
	  return (1);
	}
      num = num / 10;
    }
  if (target != num)
    {
      return (0);
    }
  return (1);
}

int width (long int num)
{
  if (num < 10)
    {
      return (1);
    }
  int count = 1;
  while (1)
    {
      if (num < 10)
	{
	  return (count);
	}
      count++;
      num = num / 10;
    }
}
