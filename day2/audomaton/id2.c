/* C code produced by gperf version 3.0.3 */
/* Command-line: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/gperf -tT id2.key  */
/* Computed positions: -k'' */

#line 1 "id2.key"

#include "id2.h"      // (1) ヘッダのインクルード
#include <string.h>

#define TOTAL_KEYWORDS 4
#define MIN_WORD_LENGTH 2
#define MAX_WORD_LENGTH 5
#define MIN_HASH_VALUE 2
#define MAX_HASH_VALUE 5
/* maximum key range = 4, duplicates = 0 */

#ifdef __GNUC__
__inline
#else
#ifdef __cplusplus
inline
#endif
#endif
/*ARGSUSED*/
static unsigned int
hash (str, len)
     register const char *str;
     register unsigned int len;
{
  return len;
}

struct OPE *
in_word_set (str, len)
     register const char *str;
     register unsigned int len;
{
  static struct OPE wordlist[] =
    {
      {""}, {""},
#line 14 "id2.key"
      {"id", ID, ID, BEGIN},
#line 15 "id2.key"
      {"dyn", DYN, DYN, MIDDLE},
#line 17 "id2.key"
      {"appx", APPX, APPX, END},
#line 16 "id2.key"
      {"f_dir", F_DIR, F_DIR, MIDDLE}
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      unsigned int key = hash (str, len);

      if (key <= MAX_HASH_VALUE)
        {
          register const char *s = wordlist[key].name;

          if (*str == *s && !strcmp (str + 1, s + 1))
            return &wordlist[key];
        }
    }
  return 0;
}
