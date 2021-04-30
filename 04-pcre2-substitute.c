#include <stdio.h>
#include <string.h>
#define PCRE2_CODE_UNIT_WIDTH 8
#include <pcre2.h>

/* gcc -mconsole -Wall pcre2_hello.c -o pcre2_hello.exe -lpcre2-8 */

int main(int argc,char **argv) {
  int re_error;
  PCRE2_SIZE re_offset;
  // PCRE2_UCHAR re_buff[1024];
  pcre2_code *re;

  const PCRE2_SPTR pattern = (PCRE2_SPTR)"[0-9]+";
  const PCRE2_SPTR subject = (PCRE2_SPTR)"Ahoj 48236478263 CAu";
  const PCRE2_SPTR replace = (PCRE2_SPTR)"NEJAKE_CISLO";

  re = pcre2_compile(pattern,PCRE2_ZERO_TERMINATED,0,&re_error,&re_offset,0);
  if(re == 0) {
    printf("PCRE: Compilation has failed !\n");
  } 

  pcre2_jit_compile(re,PCRE2_JIT_COMPLETE);

  PCRE2_UCHAR output[1024] = "";
  PCRE2_SIZE  outlen = sizeof(output) / sizeof(PCRE2_UCHAR);
  int rc = pcre2_substitute(re,subject,PCRE2_ZERO_TERMINATED,0,
           PCRE2_SUBSTITUTE_GLOBAL|PCRE2_SUBSTITUTE_EXTENDED,0,0,
           replace,PCRE2_ZERO_TERMINATED,output,&outlen);

  if(rc > 0) {
    printf("%s\n",output);
  } else {
    printf("PCRE substitute: %d\n",rc);
    // pcre2_get_error_message(rc,re_buff,1024);
    // printf("PCRE substitute: %s\n",re_buff);    
  }

  pcre2_code_free(re);
  return 0;
}
