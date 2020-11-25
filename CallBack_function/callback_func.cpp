#include <iostream>
#include <algorithm>

using namespace std;

bool whenNegative(int a, int b)
{
	return a < 0 && b < 0;
}

bool whenPositive(int a, int b)
{
	return a > 0 && b > 0;
}

int when(int a, int b, bool(*fp)(int, int))
{
	if (fp(a, b))
	{
		return a + b;
	}

	return -1;
}


int main() 
{
	cout << when(1, 2, whenPositive) << endl;

	return 0;
}