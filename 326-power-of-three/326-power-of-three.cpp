class Solution {
public:
    bool isPowerOfThree(int n) {
	if(n < 1) return false;
	string nbase3 = "";
	while(n) nbase3 += to_string(n % 3), n /= 3;   // conversion to base 3
	int i = 0;
	while(i < size(nbase3) - 1) if(nbase3[i++] != '0') return false; // checking if all digits in base 3 converted number except first one are 0
	return nbase3[i] == '1';   // check if starting digit is 1
}
};