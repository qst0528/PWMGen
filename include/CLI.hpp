#include <Arduino.h>
#include <SimpleSerialShell.h>

namespace CLI
{
  struct lookupVals
  {
    char *name;
    int   val;
  };

  int lookup(const char *aName, const lookupVals entries[]) {
    int i = 0;
    for (; entries[i].name; i++)
      {
      if (strncasecmp(aName, entries[i].name, 20) == 0) {
        break;
      }
    }
    return entries[i].val;
  }
} // namespace CLI
