#define PCRE_STATIC
#include <stdio.h>
#include <string.h>
#include <pcre.h>
#define OVECCOUNT 30
#define EBUFLEN 128
#define BUFLEN 1024

/**************************************************************
https://man7.org/linux/man-pages/man3/pcreapi.3.html
gcc -mconsole -Wall pcre_hello.c -o pre_hello.exe -lpcre
**************************************************************/

/***************************************************************************************************************************
   2nd argument of pcre_compile
   OPTIONS (second argument) (||'ed together) can be:
       PCRE_ANCHORED       -- Like adding ^ at start of pattern.
       PCRE_CASELESS       -- Like m//i
       PCRE_DOLLAR_ENDONLY -- Make $ match end of string regardless of \n's
                              No Perl equivalent.
       PCRE_DOTALL         -- Makes . match newlins too.  Like m//s
       PCRE_EXTENDED       -- Like m//x
       PCRE_EXTRA          -- 
       PCRE_MULTILINE      -- Like m//m
       PCRE_UNGREEDY       -- Set quantifiers to be ungreedy.  Individual quantifiers
                              may be set to be greedy if they are followed by "?".
       PCRE_UTF8           -- Work with UTF8 strings.

  PCRE_ANCHORED          Match only at the first position
  PCRE_BSR_ANYCRLF       \R matches only CR, LF, or CRLF
  PCRE_BSR_UNICODE       \R matches all Unicode line endings
  PCRE_NEWLINE_ANY       Recognize any Unicode newline sequence
  PCRE_NEWLINE_ANYCRLF   Recognize CR, LF, & CRLF as newline sequences
  PCRE_NEWLINE_CR        Recognize CR as the only newline sequence
  PCRE_NEWLINE_CRLF      Recognize CRLF as the only newline sequence
  PCRE_NEWLINE_LF        Recognize LF as the only newline sequence
  PCRE_NOTBOL            Subject string is not the beginning of a line
  PCRE_NOTEOL            Subject string is not the end of a line
  PCRE_NOTEMPTY          An empty string is not a valid match
  PCRE_NOTEMPTY_ATSTART  An empty string at the start of the subject is not a valid match
  PCRE_NO_START_OPTIMIZE Do not do "start-match" optimizations
  PCRE_NO_UTF16_CHECK    Do not check the subject for UTF-16 validity (only relevant if PCRE_UTF16 was set at compile time)
  PCRE_NO_UTF32_CHECK    Do not check the subject for UTF-32 validity (only relevant if PCRE_UTF32 was set at compile time)
  PCRE_NO_UTF8_CHECK     Do not check the subject for UTF-8 validity (only relevant if PCRE_UTF8 was set at compile time)
  PCRE_PARTIAL           ) Return PCRE_ERROR_PARTIAL for a partial
  PCRE_PARTIAL_SOFT      )   match if no full matches are found
  PCRE_PARTIAL_HARD      Return PCRE_ERROR_PARTIAL for a partial match
                           if that is found before a full match

*****************************************************************************************************************************/

int main(int argc, char **argv) {
  pcre *re;
  const char *error;
  int erroroffset;
  int ovector[OVECCOUNT];
  int i,rc;
  char pattern[] = "([0-9]+)\\s+(ahoj|cau)\\s+(hello|ciao).*";
  char data[] = "9274891 ahoj ciao heuhdowe";

  re = pcre_compile(pattern,PCRE_CASELESS|PCRE_MULTILINE,&error,&erroroffset,NULL);
  /* pcre *pcre_compile(const char *pattern, int options, const char **errptr, int *erroffset, const unsigned char *tableptr); */
  if(re == NULL) { printf("PCRE compilation error at %d: %s\n",erroroffset,error); return 1; }
  rc = pcre_exec(re,NULL,data,strlen(data),0,0,ovector,OVECCOUNT);
  /*  int pcre_exec(const pcre *code, const pcre_extra *extra, const char *subject, 
                    int length, int startoffset, int options, int *ovector, int ovecsize); */


  /* pcre_exec OPTIONS (||'ed together) can be:
       PCRE_ANCHORED -- can be turned on at this time.
       PCRE_NOTBOL
       PCRE_NOTEOL
       PCRE_NOTEMPTY */

  // Report what happened in the pcre_exec call..
  //printf("pcre_exec return: %d\n", pcreExecRet);
  if(rc < 0) { // Something bad happened..
    switch(rc) {
    case PCRE_ERROR_NOMATCH      : printf("PCRE compile: String did not match the pattern\n");        break;
    case PCRE_ERROR_NULL         : printf("PCRE compile: Something was null\n");                      break;
    case PCRE_ERROR_BADOPTION    : printf("PCRE compile: A bad option was passed\n");                 break;
    case PCRE_ERROR_BADMAGIC     : printf("PCRE compile: Magic number bad (compiled re corrupt?)\n"); break;
    case PCRE_ERROR_UNKNOWN_NODE : printf("PCRE compile: Something kooky in the compiled re\n");      break;
    case PCRE_ERROR_NOMEMORY     : printf("PCRE compile: Ran out of memory\n");                       break;
    default                      : printf("PCRE compile: Unknown error\n");                           break;
    } /* end switch */
  } else {
    printf("Result: We have %d match!\n",rc);
  }

  if(rc < 0) {
    if(rc == PCRE_ERROR_NOMATCH) printf("Sorry :-)\n");
    else printf("PCRE Error %d\n",rc);
    pcre_free(re);
    return 1;
  }

  printf("\nOK. The pattern has been found %d times.\n",rc);
  for(i=0; i<rc; i++) {
    char *re_finding = data + ovector[2*i];
    int   re_length  = ovector[2*i+1] - ovector[2*i];
    printf("Finding $%02d chars: %.*s\n",i,re_length,re_finding);
  }

  pcre_free(re);
  return 0;
}


