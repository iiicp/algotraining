#include <iostream>
#include <vector>

using namespace std;

void mergeSortedArray(vector<int> &A, int m, vector<int> &B)
{
    int n = B.size();
    int index = m + n;

    while (m > 0 && n > 0) {
        if (A[m - 1] > B[n - 1]) {
            A[--index] = A[m - 1];
            m--;
        }
        else {
            A[--index] = B[n - 1];
            n--;
        }
    }

    while (m > 0) {
        A[--index] = A[m - 1];
        m--;
    }

    while (n > 0) {
        A[--index] = B[n - 1];
        n--;
    }
}

int main()
{
    vector<int> A{1,2,3,4, 0, 0, 0};
    vector<int> B{2,3,5};
    mergeSortedArray(A,4, B);

    for (auto &n : A)
        std::cout << n << " ";
    
    std::cout << std::endl;
    return 0;
}
