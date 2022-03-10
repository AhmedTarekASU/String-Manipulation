#ifndef STRTOKEN_H_INCLUDED
#define STRTOKEN_H_INCLUDED
#include "strtoken.c"
char *stringByToken(char *str, char *token, const unsigned int NSC, const unsigned int NTC);
char* token_replace_nth(char* token, char* s, int n);

#endif // STRTOKEN_H_INCLUDED