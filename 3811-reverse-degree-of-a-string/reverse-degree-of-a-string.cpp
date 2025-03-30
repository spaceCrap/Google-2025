class Solution {
private:
    int reverseValue(char ch) {
        int val = ch - 'a';
        return 26 - val;
    }

public:
    int reverseDegree(string s) {
        int sum = 0;
        for (int i = 0; i < s.size(); i++) {
            int reverseVal = reverseValue(s[i]);
            int product = reverseVal * (i+1);
            sum += product;
        }

        return sum;
    }
};

// a = 26 - 0 = 26
// b = 1 => 26-1 = 5