#ifndef STRTOKEN_H_INCLUDED
#define STRTOKEN_H_INCLUDED
#include "strtoken.c"
char *stringByToken(char *str, char *token, const unsigned int NSC, const unsigned int NTC);
char *stringTokenReplace(char *str, char *token, const unsigned int REPLACE_BY_N);

#endif // STRTOKEN_H_INCLUDED