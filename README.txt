First function is  : char *stringByToken(char *str, char *token, const unsigned int NSC, const unsigned int NTC)
	
	it is used to interchange characters of a string and a token string (NSC) string characters by (NTC) Token characters
	Example:
		suppose string = "AAAAAAAAAA" 
		and  a 	TOKEN  = "BBBBBB"    
		if NSC = 3 and NTC is 2 , it will write 3 characters from String and 2 characters from token and repeat
		then the output is
		OUTPUT = "AAABBAAABBAAABBA"
			     ^    ^    ^

Second Function is : char* stringTokenReplace(char* token, char* s, int REPLACE_BY_N)

	it is used to replace a character from a string by a character from a token each (REPLACE_BY_N) characters written from the string
	Example:
		Suppose string = "ABCDEFGHIJ"
		And  a  TOKEN  = "123"
		If n = 2 then each 2 characters written from the string their 3rd Character is replaced by one from the Token
		Then the output is 
		OUTPUT = "AB1DE2GH3J"
			    ^  ^  ^