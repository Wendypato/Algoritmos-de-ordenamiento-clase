#include <iostream>
#include <vector>

using namespace std;

void mySwap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int>& vec, int low, int high)
{
    int pivot = vec[high];
    int i = low - 1;

    for(int j = low; j < high; j++)
    {
        if(vec[j] < pivot)
        {
            i++;
            mySwap(vec[i], vec[j]);
        }
    }
    mySwap(vec[i + 1], vec[high]);
    return i + 1;
}

void quickSort(vector<int>& vec, int low, int high)
{
    if(low < high)
    {
        int pi = partition(vec, low, high);

        quickSort(vec, low, pi - 1);
        quickSort(vec, pi + 1, high);
    }
}

int main()
{
    vector<int> vec = {10, 80, 30, 90, 40, 50, 70};

    quickSort(vec, 0, vec.size() - 1);

    for(int num : vec)
    {
        cout<<num<<" ";
    }
    
    return 0;
}
