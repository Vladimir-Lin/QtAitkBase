#include <essentials.h>

N::DecisionTable:: DecisionTable ( void                     )
                 : Object        ( 0 , Types::DecisionTable )
{
}

N::DecisionTable:: DecisionTable (const DecisionTable & table)
{
  ME = table ;
}

N::DecisionTable::~DecisionTable (void)
{
}

void N::DecisionTable::clear(void)
{
  conditions . clear ( ) ;
  actions    . clear ( ) ;
}

void N::DecisionTable::addAction(DecisionAction & action)
{
  actions << action;
}

void N::DecisionTable::setCondition(SUID id,bool cond)
{
  conditions[id] = cond ;
}

void N::DecisionTable::setConditions (int total,ConditionItem * items)
{
  for (int i=0;i<total;i++)                   {
    setCondition(items[i].id,items[i].enable) ;
  }                                           ;
}

bool N::DecisionTable::isAction(DecisionAction & action)
{
  SUID ic                                               ;
  foreach (ic,action.conditions)                        {
    if (!conditions.contains(ic)) return false          ;
    if (action.stands[ic]!=conditions[ic]) return false ;
  }                                                     ;
  return true                                           ;
}

UUIDs N::DecisionTable::reactions(void)
{
  UUIDs A                                 ;
  for (int i=0;i<actions.count();i++)     {
    if (isAction(actions[i]))             {
      if (!A.contains(actions[i].action)) {
        A << actions[i].action            ;
      }                                   ;
    }                                     ;
  }                                       ;
  return A                                ;
}

N::DecisionTable & N::DecisionTable::operator = (const DecisionTable & table)
{
  nMemberCopy ( table , uuid       ) ;
  nMemberCopy ( table , type       ) ;
  nMemberCopy ( table , conditions ) ;
  nMemberCopy ( table , actions    ) ;
  return ME                          ;
}

N::DecisionTable & N::DecisionTable::operator = (const QByteArray & data)
{
  setConditions ( data ) ;
  return ME              ;
}

void N::DecisionTable::setConditions(const QByteArray & data)
{
  if (data.size()<=sizeof(ConditionHeader)) return           ;
  ConditionHeader * heads = (ConditionHeader *)data.data()   ;
  if ( heads->type  != 0 ) return                            ;
  if ( heads->total <= 0 ) return                            ;
  char          * p     = (char *)data.data()                ;
  ConditionItem * items = (ConditionItem *)(p+heads->offset) ;
  setConditions ( heads->total , items )                     ;
}

bool N::DecisionTable::toByteArray(QByteArray & data)
{
  QByteArray DA                                              ;
  int        s = sizeof(ConditionHeader)                     ;
  s += sizeof(ConditionItem)*conditions.count()              ;
  DA . resize ( s )                                          ;
  DA . fill   ( 0 )                                          ;
  ConditionHeader * heads = (ConditionHeader *)DA.data()     ;
  heads -> uuid   = uuid                                     ;
  heads -> total  = conditions.count()                       ;
  heads -> offset = sizeof(ConditionHeader)                  ;
  char          * p     = (char *)DA.data()                  ;
  ConditionItem * items = (ConditionItem *)(p+heads->offset) ;
  SUID            u                                          ;
  UUIDs           C = conditions.keys()                      ;
  for (int i=0;i<C.count();i++)                              {
    u               = C[i]                                   ;
    items[i].id     = u                                      ;
    items[i].enable = conditions[u]                          ;
  }                                                          ;
  data . append ( DA )                                       ;
  return true                                                ;
}
