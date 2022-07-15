class Solution
{
public:
    int myAtoi(string s)
    {
        int i = 0;
        int n = s.size();
        while (i < n && s[i] == ' ')
            i++;
        if (i == n)
            return 0;
        int flag = 1;
        if (!isdigit(s[i]))
        {
            if (s[i] == '.' || isalpha(s[i]))
                return 0;
            else if (s[i] == '-')
                flag = -1;
            else
                flag = 1;
            i++;
        }
        long long result = 0;
        for (int j = i; j < n; j++)
        {
            if (!isdigit(s[j]))
                break;
            result = result * 10 + (s[j] - '0');
            if (result * flag >= INT_MAX)
                return INT_MAX;
            if (result * flag <= INT_MIN)
                return INT_MIN;
        }
        return result * flag;
    }
};