char *stringByToken(char *str, char *token, const unsigned int NSC, const unsigned int NTC)
{
    /*NSC IS THE NUMBER OF STRING CHARACTERS TO WRIRE BEFORE WRITING TOKEN CHARACTERS*/
    /*NTC IS THE NUMBER OF TOKEN CHARACTERS TO WRIRE BEFORE WRITING STRING CHARACTERS*/

    /*FIND LENGTH OF STRING, TOKEN AND OUTPUT STRING*/
    int STRING_LENGTH = strlen(str);
    int TOKEN_LENGTH = strlen(token);
    int OUTPUT_LENGTH = STRING_LENGTH + TOKEN_LENGTH;

    /*DYNAMICALLY ALLOCATE MEMORY FOR OUTPUT STRING USING calloc() TO INIZIALIZE IT*/
    char *OUTPUT_STRING = calloc(OUTPUT_LENGTH, sizeof(char));

    /*DECLARE AND DEFINE THE VARIABLES USED TO ITIRATE ON THE STRING AND TOKEN*/
    /*COUNTER VARIABLE IS USED TO WRITE SPECIFIC NUMBER Of CHARACTERS FROM STRING BEFORE SWITCHING TO THE OTHER*/
    int STRING_POINTER = 0;
    int TOKEN_POINTER = 0;
    int COUNTER = 0;

    /*FILL THE OUTPUT STRING WITH THE PROPER VALUES*/
    for(int i=0; i<OUTPUT_LENGTH;)
    {
        while((COUNTER<NSC)&&(STRING_POINTER<STRING_LENGTH))       //WRITE (NSC) CHARACTERS FROM STRING
        {
            OUTPUT_STRING[i] = str[STRING_POINTER];     //PLACE A CHARACTER FROM STING INTO THE OUTPUT STRING
            STRING_POINTER++;                           //INCREMENT THE STRING POINTER TO POINT TO THE NEXT CHARACTER OF THE STRING
            COUNTER++;                                  //INCREMENT THE COUNTER
            i++;                                        //INCREMENT THE OUTPUT STRING POINTER
        }
        COUNTER = 0;                                    //RESET THE COUNTER, i.e COUNTER IS USED TO WRITE FROM TOKEN AS WELL

        while((COUNTER<NTC)&&(TOKEN_POINTER<TOKEN_LENGTH))         //WRITE (NTC) CHARACTERS FROM TOKEN
        {
            OUTPUT_STRING[i] = token[TOKEN_POINTER];    //PLACE A CHARACTER FROM TOKEN INTO THE OUTPUT STRING
            TOKEN_POINTER++;                            //INCREMENT THE TOKEN POINTER TO POINT TO THE NEXT CHARACTER OF THE TOKEN
            COUNTER++;                                  //INCREMENT THE COUNTER
            i++;                                        //INCREMENT THE OUTPUT STRING POINTER
        }
        COUNTER = 0;                                    //RESET THE COUNTER
    }
    return OUTPUT_STRING;                               //RETURN THE ADDRESS OF THE OUTPUT STRING
}

char* token_replace_nth(char* token, char* s, int n)
{
    int len_s = strlen(s);
    int len_t = strlen(token);
    int size;
    if(len_s<(n*len_t))
        size = len_s + (len_t-(len_s/n));
    else
        size = len_s;
    char* out;
    out = malloc(size*sizeof(char));
    int flag = 0; int j = 0;

    if(len_s>=(n*len_t))
    {
        for(int i=0; i<size; i++)
        {
            if(j<len_t)
            {
                if(flag<(n-1))
                {
                    out[i] = s[i];
                    flag++;
                }
                else
                {
                    out[i] = token[j];
                    flag = 0;
                    j++;
                }
            }
            else
            {
                out[i] = s[i];
            }
        }
    }
    else
    {
        for(int i=0; i<size; i++)
        {
            if(i<len_s)
            {
                if(flag<(n-1))
                {
                    out[i] = s[i];
                    flag++;
                }
                else
                {
                    out[i] = token[j];
                    flag = 0;
                    j++;
                }
            }
            else
            {
                out[i] = token[j];
                j++;
            }
        }
    }
    return out;
}
