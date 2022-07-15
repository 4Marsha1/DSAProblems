class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        int i = 0, j = 0, n1 = version1.length(), n2 = version2.length();
        while (i < n1 || j < n2)
        {
            long long a = 0, b = 0;
            while (i < n1 && version1[i] == '0')
                i++;
            while (j < n2 && version2[j] == '0')
                j++;
            while (i < n1 && version1[i] != '.')
            {
                a = a * 10 + version1[i] - '0';
                i++;
            }
            while (j < n2 && version2[j] != '.')
            {
                b = b * 10 + version2[j] - '0';
                j++;
            }
            if (a != b)
            {
                return a > b ? 1 : -1;
            }
            i++;
            j++;
        }
        return 0;
    }
};