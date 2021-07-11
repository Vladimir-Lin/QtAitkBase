#include <essentials.h>

N::TransformManager:: TransformManager (void)
{
}

N::TransformManager:: TransformManager (const TransformManager & manager)
{
  Transformers = manager . Transformers ;
}

N::TransformManager::~TransformManager (void)
{
}

int N::TransformManager::add(SUID type,GenericTransform transformer)
{
  Transformers [ type ] = transformer ;
  return Transformers . count( )      ;
}

QVariants N::TransformManager::Transformer (
            QVariants        & Paraments   ,
            const QByteArray & Source      ,
                  QByteArray & Target      )
{
  QVariants Empty                                                         ;
  if (   Paraments.count() <=0                             ) return Empty ;
  if ( ! Paraments.first().canConvert(QMetaType::ULongLong)) return Empty ;
  SUID type = (SUID)Paraments.first().toULongLong()                       ;
  if ( ! Transformers . contains ( type )                  ) return Empty ;
  return Transformers [ type ] ( Paraments , Source , Target )            ;
}
