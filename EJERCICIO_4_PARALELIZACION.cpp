#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
#include <chrono> 
#include <sys/time.h>
#include <bits/stdc++.h> 
using namespace std;




 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

void populateArray(int arr[], std::size_t size)
{
    for(int i = 0; i < size; ++i)
    {
        arr[i] = ( std::rand() % 200 ) + 1;
    }
}

class Solution {

    '''
    PARALELIZACION
    '''
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.empty()) return NULL;
        auto m = max_element(begin(nums), end(nums));
        TreeNode* root = new TreeNode(*m);
        if (m != begin(nums)) {
            vector<int> left(begin(nums), m);
            root->left = constructMaximumBinaryTree(left);
        }
        if (m != end(nums) - 1) {
            vector<int> right(m + 1, end(nums));
            root->right = constructMaximumBinaryTree(right);
        }
        return root;
    }
};



int main()
{
    const int ARRAY_SIZE = 10000;
    int arr[ARRAY_SIZE];
    vector<int> vec;
    	// input array
	  
	  int n = sizeof(arr) / sizeof(arr[0]);

	  std::vector<int> dest(arr, arr + n);
    Solution solv;
    populateArray(arr, ARRAY_SIZE);
    printf("%i, %i", arr[0], arr[9999]);

    struct timeval start, end; 
  
    // start timer. 
    gettimeofday(&start, NULL); 
  
    // unsync the I/O of C and C++. 
    ios_base::sync_with_stdio(false); 

    TreeNode* root;
    root = solv.constructMaximumBinaryTree(dest);
  
    // stop timer. 
    gettimeofday(&end, NULL); 
  
    // Calculating total time taken by the program. 
    double time_taken; 
  
    time_taken = (end.tv_sec - start.tv_sec) * 1e6; 
    time_taken = (time_taken + (end.tv_usec -  
                              start.tv_usec)) * 1e-6; 
  
    cout << "Time taken by program is : " << fixed 
         << time_taken << setprecision(6); 
    cout << " sec" << endl; 
    printf("The max element of the vector is: %i", root);
}
