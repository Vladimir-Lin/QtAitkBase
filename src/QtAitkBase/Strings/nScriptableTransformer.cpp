#include <essentials.h>

#ifndef QT_STATIC

N::ScriptableTransformer:: ScriptableTransformer ( QObject * parent )
                         : QObject               (           parent )
                         , QScriptable           (                  )
                         , TransformManager      (                  )
{
  Configure ( ) ;
}

N::ScriptableTransformer::~ScriptableTransformer (void)
{
}

void N::ScriptableTransformer::Configure(void)
{
  Transformers [ N::Transformers::Hollowness        ] = Emptiness       ;
  Transformers [ N::Transformers::Copier            ] = DataCopier      ;
  Transformers [ N::Transformers::B32Encoder        ] = Base32Encoder   ;
  Transformers [ N::Transformers::B32Decoder        ] = Base32Decoder   ;
  Transformers [ N::Transformers::B64Encoder        ] = Base64Encoder   ;
  Transformers [ N::Transformers::B64Decoder        ] = Base64Decoder   ;
  Transformers [ N::Transformers::QtZipCompressor   ] = QzCompressor    ;
  Transformers [ N::Transformers::QtZipDecompressor ] = QzDecompressor  ;
  Transformers [ N::Transformers::RleCompressor     ] = RleCompressor   ;
  Transformers [ N::Transformers::RleDecompressor   ] = RleDecompressor ;
  Transformers [ N::Transformers::GzipCompressor    ] = GzCompressor    ;
  Transformers [ N::Transformers::GzipDecompressor  ] = GzDecompressor  ;
  Transformers [ N::Transformers::BzipCompressor    ] = BzCompressor    ;
  Transformers [ N::Transformers::BzipDecompressor  ] = BzDecompressor  ;
  Transformers [ N::Transformers::XzCompressor      ] = XzCompressor    ;
  Transformers [ N::Transformers::XzDecompressor    ] = XzDecompressor  ;
  Transformers [ N::Transformers::LzoCompressor     ] = LzoCompressor   ;
  Transformers [ N::Transformers::LzoDecompressor   ] = LzoDecompressor ;
  Transformers [ N::Transformers::MD4Encoder        ] = MD4Encoder      ;
  Transformers [ N::Transformers::MD5Encoder        ] = MD5Encoder      ;
}

QVariants N::ScriptableTransformer::Transformer   (
            QString                     Paraments ,
            const ScriptableByteArray & Source    ,
                  ScriptableByteArray & Target    )
{
  QStringList s = CommandTokens        ( Paraments           ) ;
  QVariants   v                                                ;
  v << s                                                       ;
  return TransformManager::Transformer ( v , Source , Target ) ;
}

QScriptValue N::TransformerAttachment(QScriptContext * context,QScriptEngine * engine)
{
  N::ScriptableTransformer * tf = new N::ScriptableTransformer ( engine ) ;
  return engine -> newQObject ( tf )                                      ;
}

#endif
