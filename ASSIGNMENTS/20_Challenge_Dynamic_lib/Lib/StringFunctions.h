/*
str - string to search
searchCharacter - char to loor for
return type - int: count for the number of times that character was found
*/
int numberOfCharactersInString(char *str, char searchCharacter);

/*
source - source string
return type - int:0 on success
*/
int removeNonAlphaCharacters(char* source);

/*
source - source string
return type - int: length of string
*/
int lengthOfString(char *source);

/*
str1 - string to concatenate to (resulting string)
str2 - second string to concatenate from
x - double pointer to the new str
return type - int:0 on success
*/
int strConcat(char *str1, char *str2, char **x);

/*
source - string to cope from
destination - double pointer for the second string to copy to
return type - int:0 on success
*/
int strCopy(char *source, char **destination);

/*
source - source string
from - starting index from where you want to get substring
n - number of characters to be copied in substring
target - target string in which you want to store targe string
return type - int: 0 on success
*/
int substring(char *source, int from, int n, char *target);