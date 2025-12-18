#include <iostream>
using namespace std;
void Selection_sort(int arr[], int n)
{
    for (int i = 0; i <= n - 2; i++)
    {
        int mini = i;
        for (int j = i; j <= n - 1; j++)
        {
            if (arr[j] < arr[mini])
            {
                mini = j;
            }
        }
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
    }
}
int main()
{
    int n;
    cout << "Enter te size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " element: ";
    for (int i = 0; i < n; i++)

    {
        cin >> arr[i];
    }

    Selection_sort(arr, n);
    cout << "Sorted array: ";
    for (int x : arr)
    {
        cout << x << " ";
    }

    return 0;
}