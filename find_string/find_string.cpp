#include <iostream>
#include <vector>
#include <tuple>
#include <sstream>
#include <iterator>

using namespace std;

auto return_many_values()
{
	return make_pair(1, "str");
}

int main()
{

	istringstream iss("Hello asdfsdio hwesdm flk");
	istream_iterator<string> begin(iss);
	istream_iterator<string> end;

	vector<string> vec(begin, end);

	for (auto i : vec)
	{
		cout << i << endl;
	}
}