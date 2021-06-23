/*

sort an array using recursion

*/

//CODE




#include <bits/stdc++.h>
using namespace std;

vector<int> put(vector<int> nums,int key)
{
	if(nums.size()==0 || nums[nums.size()-1]<=key)
    {
		nums.push_back(key);
		return nums;
	}
	
	int val = nums[nums.size()-1];
	nums.pop_back();
	nums = put(nums,key);
	nums.push_back(val);
	return nums;
}

vector<int> sort(vector<int> nums)
{
	if(nums.size()==1)
		return nums;

	int lastNum = nums[nums.size()-1];
	nums.pop_back();
	nums = sort(nums);
	return nums = put(nums,lastNum);
}

int main()
{
	int size;
	cout<<"Enter size"<<endl;
	cin >> size;
	vector<int> nums;
	cout<<"Enter elements"<<endl;
	for(int i=0; i<size; i++)
	{
		int x; 
		cin >> x;
		nums.push_back(x);
	}

	nums = sort(nums);
	cout<<"After sorting"<<endl;
	for(int i = 0; i < size; i++)
	{
		cout << nums[i] << " ";
	}

}
