#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'palindromeIndex' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int palindromeIndex(string s) {
    int l = s.length();
    int left = 0, right = l - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            int newLeft = left + 1;
            int newRight = right;
            while (newLeft < newRight) {
                if (s[newLeft] != s[newRight])
                    break;

                newLeft++;
                newRight--;
            }
            if (newLeft >= newRight)
                return left;

            newLeft = left;
            newRight = right - 1;
            while (newLeft < newRight) {
                if (s[newLeft] != s[newRight])
                    break;
                newLeft++;
                newRight--;
            }
            if (newLeft >= newRight)
                return right;

            return -1;
        }
        left++;
        right--;
    }

    return -1;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = palindromeIndex(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
