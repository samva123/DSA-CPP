// #include <iostream>
// #include <cstring>
// #include <vector>
// #include <algorithm>
// using namespace std;

// // Global index to store permutations
// int idx = 0;

// // Store only valid permutations in perm[][]
// void desiredPermutations(char *a, char ch, int pos, int l, int r, char **perm)
// {
//     if (l == r)
//     {
//         // Restriction: skip permutation where a[pos] == ch
//         if (a[pos] == ch)
//             return;

//         // Copy permutation into perm list
//         perm[idx] = new char[strlen(a) + 1];
//         strcpy(perm[idx], a);
//         idx++;

//         return;
//     }

//     for (int i = l; i <= r; i++)
//     {
//         std::swap(a[l], a[i]);     // built-in swap
//         desiredPermutations(a, ch, pos, l + 1, r, perm);
//         std::swap(a[l], a[i]);     // backtrack
//     }
// }

// int main()
// {
//     char str[20];
//     char restricted;
//     int pos;

//     cin >> str;
//     cin >> restricted;
//     cin >> pos;

//     int n = strlen(str);

//     // max possible permutations = n!
//     int maxPerm = 1;
//     for (int i = 2; i <= n; i++) 
//         maxPerm *= i;

//     // allocate memory for perm
//     char **perm = new char*[maxPerm];

//     desiredPermutations(str, restricted, pos, 0, n - 1, perm);

//     // Convert to vector for easy sorting
//     vector<string> v;
//     for (int i = 0; i < idx; i++)
//         v.push_back(string(perm[i]));

//     sort(v.begin(), v.end());

//     // Print sorted permutations
//     for (string s : v)
//         cout << s << endl;

//     return 0;
// }

























#include <iostream>

using namespace std;

void print(int **v, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    // 1. allocate int
    int *intPtr = new int(5);

    // using malloc
    int *mptr = (int *)malloc(4);
    *mptr = 5;

    cout << *intPtr << " " << *mptr << endl;
    delete intPtr;
    free(mptr);

    // // 1D allocation
    // int *arrnew = new int[5];

    // // using malloc
    // int *arrmalloc = (int *)malloc(5 * sizeof(int));

    // for (int i = 0; i < 5; i++)
    // {
    //     int d;
    //     cin >> d;
    //     arrnew[i] = arrmalloc[i] = d;
    // }

    // for (int i = 0; i < 5; i++)
    // {
    //     cout << arrnew[i] << " " << arrmalloc[i] << endl;
    // }
    // delete[] arrnew;
    // free(arrmalloc);

    // 2D allocation
    // int rows = 5, cols = 5;
    // int **ptr2d = new int *[rows];

    // for (int i = 0; i < rows; ++i)
    //     ptr2d[i] = new int[cols];

    // int **ptr2dmalloc = (int **)malloc(sizeof(int *) * rows);
    // for (int i = 0; i < rows; i++)
    //     ptr2dmalloc[i] = (int *)malloc(sizeof(int) * cols);

    // for (int i = 0; i < rows; i++)
    // {
    //     for (int j = 0; j < cols; j++)
    //     {
    //         ptr2d[i][j] = 7;
    //         ptr2dmalloc[i][j] = 8;
    //     }
    // }

    // print(ptr2d, rows, cols);
    // print(ptr2dmalloc, rows, cols);

    // for (int i = 0; i < rows; ++i)
    //     delete[] ptr2d[i];
    // delete[] ptr2d;

    // for (int i = 0; i < rows; ++i)
    //     free(ptr2dmalloc[i]);
    // free(ptr2dmalloc);
    return 0;
}
