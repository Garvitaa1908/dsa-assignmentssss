#include <iostream>
#include <set>
using namespace std;

int countDistinct(int arr[], int n) {
    set<int> s;
    for (int i=0; i<n; i++) s.insert(arr[i]);
    return s.size();
}

int main() {
    int arr[] = {1,2,2,3,4,4,5};
    int n = 7;
    cout << "Total distinct elements: " << countDistinct(arr,n);
    return 0;
}
