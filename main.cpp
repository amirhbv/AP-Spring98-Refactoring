#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int length(int n)
{
	for (int i = 0; ; i++)
	{
		int r = n / pow(10, i);
		if (r == 0)
			return i;
	}
}

vector<int> split_number_to_digits(int number)
{
	vector<int> result;
	while (number)
	{
		result.push_back(number % 10);
		number /= 10;
	}

	reverse(result.begin(), result.end());
	return result;
}

bool is_circular(int number)
{
	int len = length(number);
	vector<int> number_digits = split_number_to_digits(number);
	int cu = number_digits[0];
	number_digits[0] = 0;
	int i = 1;
	int t = len;
	while (t != 0)
	{
		i = (cu + i) % len;
		if (i == 0)
			i = len;
		cu = number_digits[i - 1];
		if (cu == -1)
			break;
		number_digits[i - 1] = -1;
		t--;
	}
	return cu == 0;
}

void print_result(int case_number, bool result)
{
	cout << "Case " << case_number << ": ";
	if (result)
		cout << "Yes";
	else
		cout << "No";
	cout << endl;
}

int main()
{
	for (int case_number = 1; ; case_number++)
	{
		int n;
		cin >> n;
		if (n == 0)
			break;
		bool result = is_circular(n);
		print_result(case_number, result);
	}
	return 0;
}
