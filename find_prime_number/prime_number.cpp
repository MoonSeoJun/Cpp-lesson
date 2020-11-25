#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

bool isprime(int num)
{
	for (int i = 2; i <= num / 2; i++)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	return true;
}

int main() {

	vector<int> vec;

	for (int i = 2; i <= 100; i++)
	{
		vec.push_back(i);
	}

	for (auto itr = vec.begin(); itr != vec.end(); itr++)
	{
		if (isprime(*itr) == false)
		{
			itr = vec.erase(itr);
			itr--;
		}
	}

	for (auto i : vec)
	{
		cout << i << endl;
	}

	return 0;
}
