#include <bits/stdc++.h>
using namespace std;

// Using a structure to store element & count
// basically same as hashing, just without using map
struct eleCnt
{
    int ele;
    int cnt;
};

int countNK(int arr[], int n, int k)
{
    if (k < 2)
        return n;
    struct eleCnt temp[k - 1];
    for (int i = 0; i < k - 1; i++)
        temp[i].cnt = 0;

    for (int i = 0; i < n; i++)
    {
        int j;
        for (j = 0; j < k - 1; j++)
        {
            if (arr[i] == temp[j].ele)
            {
                temp[j].cnt++;
                break;
            }
        }
        if (j == k - 1)
        {
            int l;
            for (l = 0; l < k - 1; l++)
            {
                if (temp[l].cnt == 0)
                {
                    temp[l].ele = arr[i];
                    temp[l].cnt = 1;
                    break;
                }
            }
            if (l == k - 1)
                for (l = 0; l < k - 1; l++)
                    temp[l].cnt--;
        }
    }

    int ans = 0;
    for (int i = 0; i < k - 1; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
            if (arr[j] == temp[i].ele)
                cnt++;
        if (cnt > n / k)
            ans++;
    }
    return ans;
}

// hashing
int countNK(int arr[], int n, int k)
{
    unordered_map<int, int> freq;
    int cnt = 0;
    for (int i = 0; i < n; i++)
        freq[arr[i]]++;
    for (int i = 0; i < freq.size(); i++)
    {
        if (freq[i] > n / k)
            cnt++;
    }
    return cnt;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << countNK(arr, n, k);
}