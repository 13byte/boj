#include <bits/stdc++.h>
using namespace std;

void ft_parse(deque<int> &dq, string &arr)
{
	int num = 0;
	for (int i = 1; i + 1 < arr.size(); ++i)
	{
		if (arr[i] == ',')
		{
			dq.push_back(num);
			num = 0;
		}
		else
		{
			num = 10 * num + (arr[i] - '0');
		}
	}
	if (num != 0)
		dq.push_back(num); // ,을 만나지 않아서 마지막 숫자 push를 안했기에 push
}

void ft_print(deque<int> &dq)
{
	cout << '[';
	for (int i = 0; i < dq.size(); i++)
	{
		cout << dq[i];
		if (i + 1 != dq.size())
			cout << ',';
	}
	cout << "]\n";
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;

	cin >> t;
	while (t--)
	{
		deque<int> dq;
		string func, arr;
		bool r_flag = false, error = false;
		int n;

		cin >> func;
		cin >> n;
		cin >> arr;
		ft_parse(dq, arr);
		for (int i = 0; i < func.size(); ++i)
		{
			if (func[i] == 'R')
				r_flag = 1 - r_flag;
			else
			{
				if (dq.empty())
				{
					error = true;
					break;
				}
				else
				{
					if (r_flag)
						dq.pop_back();
					else
						dq.pop_front();
				}
			}
		}
		if (error)
			cout << "error\n";
		else
		{
			if (r_flag)
				reverse(dq.begin(), dq.end());
			ft_print(dq);
		}
	}
	return (0);
}