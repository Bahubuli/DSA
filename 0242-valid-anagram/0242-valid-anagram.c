bool isAnagram(char * s, char * t){
	int chars[26] = {0}, index;
	for ( index = 0; s[index]; ++index ) chars[s[index] - 'a'] ++;
	for ( index = 0; t[index]; ++index ) chars[t[index] - 'a'] --;
	for ( index = 0; index < 26; ++index ) if ( chars[index] ) return false;
	return true;
}

