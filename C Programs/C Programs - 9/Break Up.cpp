#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    int A[no_of_elements + 1];
    for(int i = 1; i <= no_of_elements; i++)
        scanf("%d", &A[i]);

    int is_palindrome[no_of_elements + 1][no_of_elements + 1];
    memset(is_palindrome, false, sizeof(is_palindrome));
    for(int i = 1; i <= no_of_elements; i++)
        is_palindrome[i][i] = true;

    for(int length = 2; length <= no_of_elements; length++)
    {
        for(int start = 1, end = start + length - 1; end <= no_of_elements; start++, end++)
        {
            if(A[start] == A[end] && (length == 2 || is_palindrome[start + 1][end - 1]))
            {
                is_palindrome[start][end] = true;
            }
        }
    }

    int minimum_palindromic_parts[no_of_elements + 1];
    minimum_palindromic_parts[0] = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        minimum_palindromic_parts[i] = i;

        for(int start = 1; start <= i; start++)
        {
            if(is_palindrome[start][i])
            {
                minimum_palindromic_parts[i] = min(minimum_palindromic_parts[i], 1 + minimum_palindromic_parts[start - 1]);
            }
        }
    }

    printf("%d\n", minimum_palindromic_parts[no_of_elements]);
    return 0;
}
