#include <essentials.h>

N::DecisionTables:: DecisionTables                (void)
                  : QMap < SUID , DecisionTable > (    )
{
}

N::DecisionTables::~DecisionTables (void)
{
}

int N::DecisionTables::Blank(int index)
{
  DecisionTable dt    ;
  dt.uuid     = index ;
  ME[index]   = dt    ;
  return count()      ;
}
