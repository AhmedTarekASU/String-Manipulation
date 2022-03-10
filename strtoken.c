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

char *stringTokenReplace(char *str, char *token, const unsigned int REPLACE_BY_N)
{
    /*DECLARE AND DEFINE THE LENGTHS OF THE STRING AND THE TOKEN*/
    int STRING_LENGTH = strlen(str);
    int TOKEN_LENGTH = strlen(token);

    /*CALCULATE THE LENGTH OF THE OUTPUT STRING*/
    int OUTPUT_LENGTH;
    int q = STRING_LENGTH/(REPLACE_BY_N+1);
    int R = STRING_LENGTH%(REPLACE_BY_N+1);
    OUTPUT_LENGTH = q*(REPLACE_BY_N+1)+R+(TOKEN_LENGTH-q);

    /*DECLARE AND DEFINE TOKEN POINTER AND STRING CHARACTER COUNTER*/
    int TOKEN_POINTER = 0;
    int COUNTER = 0;

    /*DYNAMICALLY ALLOCATE THE OUTPUT STRING USING calloc() TO INITIALIZE IT*/
    char *OUTPUT_STRING = calloc(OUTPUT_LENGTH, sizeof(char));

    /*FILL THE OUTPUT STRING WITH THE PROPER VALUES*/
    for(int i=0; i<OUTPUT_LENGTH;)
    {
        while((COUNTER<REPLACE_BY_N)&&(i<STRING_LENGTH))
        {
            OUTPUT_STRING[i] = str[i];
            COUNTER++;
            i++;
        }
        COUNTER = 0;
        if(TOKEN_POINTER<TOKEN_LENGTH)
        {
            OUTPUT_STRING[i] = token[TOKEN_POINTER];
            TOKEN_POINTER++;
            i++;
        }
    }
    return OUTPUT_STRING;
}

char *integerToString(int number)
{
    /*DYNAMICALLY ALLOCATE THE OUTPUT STRING USING calloc() WITH SIZE 1*/
    char *OUTPUT_STRING = calloc(1,sizeof(char));
    /*CHECK IF THE NUMBER IS A NEGATIVE NUMBER*/
    if(number<0)        //IF NUMBER IS NEGATIVE THEN PLACE A NEGATIVE IN THE FIRST LOCATION
    {
        OUTPUT_STRING[0] = '-';
        OUTPUT_STRING = realloc(OUTPUT_STRING, 2*sizeof(char));
    }
    int i = number<0? 1:0;  //TO KNOW WHETHER TO ACCESS THE FIRST LOCATION OR NOT
    /*CHECK HOW MANY DIGITS ARE IN THE GIVEN NUMBER*/
    int q = number>=0? number:(-1)*number;      //SET q = ABSOLUTE(number)
    int DIGITS = 0;
    while(q>0)
    {
        q = q/10;
        DIGITS++;
    }
    q = number>=0? number:(-1)*number;      //RESET q AS WE WILL USE IT LATER
    /*REALLOCATE THE OUTPUT STRING TO THE PROPER SIZE TO CONTAIN THE DIGITS*/
    OUTPUT_STRING = realloc(OUTPUT_STRING, (DIGITS+i)*sizeof(char));
    /*CALCULATE THE LENGTH OF THE OUTPUT STRING*/
    int OUTPUT_LENGTH = DIGITS + i;
    /*PLACE THE DIGITS IN THE OUTPUT STRING*/
    for(int j=OUTPUT_LENGTH-1; j>=i; j--)
    {
        char TEMP = q%10 + '0';
        OUTPUT_STRING[j] = TEMP;
        q = q/10;
    }
    return OUTPUT_STRING;
}