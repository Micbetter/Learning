/*找到有序数组的中位数*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double FindMiddleValue(vector<int>& a, vector<int>& b);

int main()
{
    return 0;
}

double FindMiddleValue(vector<int>& a, vector<int>& b)
{
    double r = 0;
    vector<double> t;

    for(auto a_:a)
        t.push_back(a_);
    for(auto b_:b)
        t.push_back(b_);
    
    sort(t.begin(),t.end());

    int size = t.size();
    if((size % 2) == 0)
    {
        r = t[size / 2];
    }
    else
    {
        r = (t[(size-1)/2] + t[(size+1)/2]) / 2;
    }
    


    return r;
}