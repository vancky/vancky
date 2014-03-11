#include <iostream> 
using namespace std; 
int n; 
int a[105]; 
//下标从0开始 
int partition(int a[], int low, int high) 
{//快速排序中的一趟 
    int key;//作为枢轴来使用 
    key = a[low]; 
    while(low < high) 
    { 
        while(low < high && a[high] >= key) 
        --high; 
        a[low] = a[high]; 
        while(low < high && a[low] <= key) 
        ++low; 
        a[high] = a[low]; 
    } 
    a[low] = key; 
    return low; 
} 
void qsort(int a[], int low, int high) 
{//快速排序的递归形式 
    int loc; 
    if(low < high) 
    { 
        loc = partition(a, low, high);//一趟排序结果的调用 
        qsort(a, low, loc - 1); 
        qsort(a, loc + 1, high); 
    } 
} 
int main() 
{ 
    int i; 
    cin >> n; 
    for(i = 0; i < n; i++) cin >> a[i]; 
    qsort(a, 0, n - 1); 
    for(i = 0; i < n; i++) cout << a[i] << " "; 
    cout << endl; 
    return 0; 
} 