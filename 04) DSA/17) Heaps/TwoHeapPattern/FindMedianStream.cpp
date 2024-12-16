#include <iostream>
#include <queue>
using namespace std;
//Link: https://www.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1
class Solution
{
public:
    int n = 0;
    priority_queue<int> s; // Max heap
    priority_queue<int, vector<int>, greater<int>> q; // Min heap

    void insertHeap(int &x)
    {
        if (s.empty() || x <= s.top()) {
            s.push(x);
        } else {
            q.push(x);
        }
        balanceHeaps();
        n++;
    }
    
    void balanceHeaps()
    {
        if (s.size() > q.size() + 1) {
            q.push(s.top());
            s.pop();
        } else if (q.size() > s.size()) {
            s.push(q.top());
            q.pop();
        }
    }
    
    double getMedian()
    {
        if (s.size() > q.size()) return s.top();
        return (s.top() + q.top()) / 2.0;
    }
};

int main()
{
    Solution solution;

    // Test case 1
    int num1 = 1;
    solution.insertHeap(num1);
    cout << "Median after inserting 1: " << solution.getMedian() << endl;

    // Test case 2
    int num2 = 5;
    solution.insertHeap(num2);
    cout << "Median after inserting 5: " << solution.getMedian() << endl;

    // Test case 3
    int num3 = 2;
    solution.insertHeap(num3);
    cout << "Median after inserting 2: " << solution.getMedian() << endl;

    // Test case 4
    int num4 = 8;
    solution.insertHeap(num4);
    cout << "Median after inserting 8: " << solution.getMedian() << endl;

    // Test case 5
    int num5 = 3;
    solution.insertHeap(num5);
    cout << "Median after inserting 3: " << solution.getMedian() << endl;

    return 0;
}
