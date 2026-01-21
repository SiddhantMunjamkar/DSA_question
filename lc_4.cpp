#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
	{
		vector<int> s;
		int index1 = 0;
		int index2 = 0;
		int size1 = nums1.size();
		int size2 = nums2.size();
		while (index1 < size1 && index2 < size2)
		{
			if (nums1[index1] < nums2[index2])
			{
				s.push_back(nums1[index1++]);
			}
			else
			{
				s.push_back(nums2[index2++]);
			}
		}
		while (index1 < size1)
		{
			s.push_back(nums1[index1++]);
		}
		while (index2 < size2)
		{
			s.push_back(nums2[index2++]);
		}

		int n = s.size();

	
	}

	~Solution() {}
};

int main()
{
	Solution sol;
	vector<int> nums1(1, 2);
	vector<int> nums2(3, 4);
	double result = sol.findMedianSortedArrays(nums1, nums2);
	cout << result << endl;

	return 0;
}