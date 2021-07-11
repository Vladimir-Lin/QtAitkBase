#include <essentials.h>

N::DecisionTree:: DecisionTree   ( void                    )
                : Object         ( 0 , Types::DecisionTree )
                , DecisionTables (                         )
{
}

N::DecisionTree::~DecisionTree(void)
{
}

N::DecisionTree & N::DecisionTree::join(DecisionTree & tree)
{
  UUIDs Ds = ME   . keys ( )             ;
  UUIDs Ts = tree . keys ( )             ;
  UUIDs Xs = Ts   - Ds                   ;
  UUIDs Zs                               ;
  SUID  u                                ;
  if (Xs.count()>0)                      {
    foreach (u,Xs)                       {
      ME [ u ] = tree [ u ]              ;
    }                                    ;
  }                                      ;
  Ds = tree.Connectors.keys()            ;
  Ts =      Connectors.keys()            ;
  foreach (u,Ds)                         {
    if (Ts.contains(u))                  {
      Xs = tree.Connectors[u]            ;
      Zs =      Connectors[u]            ;
      Zs = Zs + Xs                       ;
      Zs = Uniqueness(Zs)                ;
      Connectors[u] = Zs                 ;
    } else                               {
      Connectors[u] = tree.Connectors[u] ;
    }                                    ;
  }                                      ;
  roots ( )                              ;
  return ME                              ;
}

UUIDs N::DecisionTree::roots(void)
{
  UUIDs Ds = ME         . keys ( ) ;
  UUIDs Ks = Connectors . keys ( ) ;
  UUIDs R                          ;
  UUIDs T                          ;
  SUID  u                          ;
  Root . clear ( )                 ;
  foreach (u,Ks)                   {
    T = Connectors[u]              ;
    R = R + T                      ;
  }                                ;
  R    = Uniqueness ( R )          ;
  Root = Ds - R                    ;
  return Root                      ;
}

UUIDs N::DecisionTree::reactions(void)
{
  UUIDs R                 ;
  UUIDs T                 ;
  SUID  u                 ;
  foreach (u,Current)     {
    T = ME[u].reactions() ;
    R = R + T             ;
  }                       ;
  R = Uniqueness ( R )    ;
  return R                ;
}

bool N::DecisionTree::next(UUIDs & react)
{
  UUIDs D                       ;
  UUIDs T                       ;
  SUID  u                       ;
  foreach (u,react)             {
    if (Connectors.contains(u)) {
      T = Connectors[u]         ;
      D = D + T                 ;
    }                           ;
  }                             ;
  if (D.count()>0)              {
    D = Uniqueness ( D )        ;
    Current = D                 ;
  } else                        {
    Current . clear ( )         ;
    return false                ;
  }                             ;
  return true                   ;
}
