#include <essentials.h>

N::DecisionAction:: DecisionAction (void)
                  : action         (0   )
                  , pointer        (NULL)
{
}

N::DecisionAction:: DecisionAction (const DecisionAction & decision)
{
  ME = decision ;
}

N::DecisionAction::~DecisionAction (void)
{
}

N::DecisionAction & N::DecisionAction::operator = (const DecisionAction & decision)
{
  nMemberCopy ( decision , action     ) ;
  nMemberCopy ( decision , arguments  ) ;
  nMemberCopy ( decision , conditions ) ;
  nMemberCopy ( decision , stands     ) ;
  nMemberCopy ( decision , pointer    ) ;
  return ME                             ;
}

N::DecisionAction & N::DecisionAction::operator = (const QByteArray & data)
{
  addConditions ( data ) ;
  return ME              ;
}

bool N::DecisionAction::operator == (const DecisionAction & decision)
{
  if ( action     != decision . action     ) return false ;
  if ( pointer    != decision . pointer    ) return false ;
  if ( arguments  != decision . arguments  ) return false ;
  if ( conditions != decision . conditions ) return false ;
  if ( stands     != decision . stands     ) return false ;
  return true                                             ;
}

void N::DecisionAction::clear (void)
{
  conditions . clear ( ) ;
  stands     . clear ( ) ;
}

void N::DecisionAction::addCondition (SUID id,bool cond)
{
  conditions << id   ;
  stands [id] = cond ;
}

void N::DecisionAction::addConditions (int total,ConditionItem * items)
{
  for (int i=0;i<total;i++)                   {
    addCondition(items[i].id,items[i].enable) ;
  }                                           ;
}

void N::DecisionAction::addConditions (const QByteArray & data)
{
  if (data.size()<=sizeof(ConditionHeader)) return           ;
  ConditionHeader * heads = (ConditionHeader *)data.data()   ;
  if ( heads->type  != 0 ) return                            ;
  if ( heads->total <= 0 ) return                            ;
  char          * p     = (char *)data.data()                ;
  ConditionItem * items = (ConditionItem *)(p+heads->offset) ;
  addConditions ( heads->total , items )                     ;
}

bool N::DecisionAction::execute(void)
{
  return false ;
}

bool N::DecisionAction::toByteArray(QByteArray & data)
{
  if (stands.count()!=conditions.count()) return false       ;
  QByteArray DA                                              ;
  int        s = sizeof(ConditionHeader)                     ;
  s += sizeof(ConditionItem)*conditions.count()              ;
  DA . resize ( s )                                          ;
  DA . fill   ( 0 )                                          ;
  ConditionHeader * heads = (ConditionHeader *)DA.data()     ;
  heads -> uuid   = action                                   ;
  heads -> total  = conditions.count()                       ;
  heads -> offset = sizeof(ConditionHeader)                  ;
  char          * p     = (char *)DA.data()                  ;
  ConditionItem * items = (ConditionItem *)(p+heads->offset) ;
  SUID            u                                          ;
  for (int i=0;i<conditions.count();i++)                     {
    u               = conditions[i]                          ;
    items[i].id     = u                                      ;
    items[i].enable = stands[u]                              ;
  }                                                          ;
  data . append ( DA )                                       ;
  return true                                                ;
}
