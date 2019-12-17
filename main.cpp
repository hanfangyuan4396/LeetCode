#include <iostream>
#include <vector>

using namespace std;

int Dec2Bin(int dec, int len, vector<int>& bin);
vector<int> ReverseVector(vector<int>& vec);
int power(int times);
vector<vector<int>> subsets(vector<int>& nums);
vector<vector<int>> subsets_2(vector<int>& nums);
int main()
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);
	vector<vector<int>> sets(subsets_2(nums));
	for (int i = 0; i < power(nums.size()); i++)
	{
		for (int j = 0; j < sets[i].size(); j++)
		{
			cout << sets[i][j] << "    ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
int Dec2Bin(int dec, int len, vector<int>& bin)
{
	int weight;
	for (int i = 0; i < len; i++)
	{
		bin[i] = 0;
	}
	for (int i = len - 1; i >= 0; i--)
	{
		 weight = power(i);
		cout << "i:" << i << "  " << "weight:" << weight << endl;
		if (dec >= weight)
		{
			if (dec == weight)
			{
				bin[i] = 1;
				return 0;
			}
			else
			{
				bin[i] = 1;
				dec = dec - weight;
			}
		}
	}
}

vector<int> ReverseVector(vector<int>& vec)
{
	vector<int> revVec;
	vector<int>::reverse_iterator it;
	for (it = vec.rbegin(); it != vec.rend(); it++)
	{
		revVec.push_back(*it);
	}
	return revVec;
}

int power(int times)
{
	int result = 1;
	for (int i = 0; i < times; i++)
	{
		result = 2 * result;
	}
	return result;
}
vector<vector<int>> subsets(vector<int>& nums)
{
	vector<vector<int>> subVec;
	vector<int> temp;
	int len = nums.size();
	vector<int> bin(len);
	for (int i = 0; i < power(len); i++)
	{
		Dec2Bin(i, len, bin);
		for (int j = 0; j < len; j++)
		{
			if (bin[j] == 1)
			{
				temp.push_back(nums[j]);
			}
		}
		subVec.push_back(temp);
		temp.clear();
	}
	return subVec;
	
}

vector<vector<int>> subsets_2(vector<int>& nums)
{
	vector<vector<int>> res;
	vector<int> temp;
	int len = nums.size();
	for (int i = 0; i < 1 << len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (i >> j & 1)
			{
				temp.push_back(nums[j]);
			}
		}
		res.push_back(temp);
		temp.clear();
	}
	return res;
}