/****************************************************************************
 *
 * Copyright (C) 2001 ~ 2021
 * 
 *  Neutrino International Inc.
 *  Oriphase Space Travelling Industry
 *
 * Author   : Brian Lin ( Foxman , Vladimir Lin , Vladimir Forest )
 * E-mail   : lin.foxman@gmail.com
 *          : lin.vladimir@gmail.com
 *          : wolfram_lin@yahoo.com
 *          : wolfram_lin@sina.com
 *          : wolfram_lin@163.com
 * Skype    : wolfram_lin
 * WeChat   : 153-0271-7160
 * WhatsApp : 153-0271-7160
 * QQ       : lin.vladimir@gmail.com (2107437784)
 * LINE     : lin-foxman
 *
 ****************************************************************************/
//////////////////////////////////////////////////////////////////////////////
#ifndef QT_AITK_BASE_MACROS_H
#define QT_AITK_BASE_MACROS_H
//////////////////////////////////////////////////////////////////////////////
#define QT_AITK_BASE_LIB 1
#define QT_AITK_BASE_VERSION 202107112301
//////////////////////////////////////////////////////////////////////////////
#define AITK_VERSION                  2.0
#define AITK_VERSION_STRING           "2.0"
//////////////////////////////////////////////////////////////////////////////
#define isLittleEndian                ( Q_BYTE_ORDER == Q_LITTLE_ENDIAN )
#define isBigEndian                   ( Q_BYTE_ORDER == Q_BIG_ENDIAN    )
#define isMacOSX                      ( Q_OS_MAC )
#define isAndroid                     ( Q_OS_ANDROID )
#define isLinux                       ( Q_OS_LINUX )
#define isWin64                       ( Q_OS_WIN64 )
#define isWin32                       ( Q_OS_WIN32 && !Q_OS_WIN64 )
#define ME                            (*this)
#define IsNull(item)                  (NULL==(item))
#define NotNull(item)                 (NULL!=(item))
#define NotEqual(a,b)                 ((a)!=(b))
#define IsMask(a,b)                   (((a) & (b))==(b))
#define nEqual(VAR,CONST)             ((CONST)==(VAR))
#define nGreater(A,B)                 ((A)>(B))
#define nLess(A,B)                    ((A)<(B))
#define nEnsureNull(VAR)              { if (NULL!=(VAR)) delete VAR; VAR = NULL; }
#define nDeleteArray(OBJ)             { if (NULL!=(OBJ)) delete [] OBJ ; OBJ = NULL; }
#define nDropOut(Condition)           if (Condition) return
#define nKickOut(Condition,Result)    if (Condition) return (Result)
#define nEqualOut(A,B,C)              if ((B)==(A)) return (C)
#define nSafeExec(variable)           if (NotNull(variable))
#define nIfSafe(variable)             if (NotNull(variable))
#define nFastCast(ITEM,Statement)     case ITEM : Statement ; break
#define nFullLoop(Index,Count)        for (int Index=0;Index<Count;Index++)
#define nMod(v,m)                     ((v%m)==0)
#define nSquare(N)                    ( (N) * (N) )
#define CiosMenuId(a,b,c)             ( ( a * 10000 ) + ( b * 100 ) + c )
#define nMemberCopy(Object,Member)    Member = Object . Member
#define nArrayCopy(Object,Member,N,T) for (int N=0;N<T;N++) Member[N] = Object . Member[N]
#define nTreeUuid(item,column)        item->data(column,Qt::UserRole).toULongLong()
#define nTreeInt(item,column)         item->data(column,Qt::UserRole).toInt()
#define nListUuid(item)               item->data(Qt::UserRole).toULongLong()
#define nTableUuid(item)              item->data(Qt::UserRole).toULongLong()
#define Casting(ClassName,Widget)     qobject_cast<ClassName *>(Widget)
#define nSafeCast(TYPE,VAR)           ((TYPE)VAR)
#define VcfCasting(ClassName,Widget)  qgraphicsitem_cast<ClassName *>(Widget)
#define VcfChild(vcfClass,vcf)        vcfClass * vcf = new vcfClass(GraphicsView(),this,plan)
#define VcfScopedMenu(menuName)       MenuManager menuName(GraphicsView())
#define VcfConstructor                QObject * parent,QGraphicsItem * item,Plan * plan = NULL
#define VcfHeadParaments              QObject * parent,QGraphicsItem * item,Plan * p
#define nClipboardText                qApp->clipboard()->text()
#define nClipboardMime                (QMimeData *)qApp->clipboard()->mimeData()
#define nSetClipboard(clipboardText)  qApp->clipboard()->setText(clipboardText)
#define nSetClipboardMime(MIME)       qApp->clipboard()->setMimeData(MIME)
#define qnDebug                       N::qPlan->Debug
#define nTimeNow                      QDateTime::currentDateTime()
#define FunctionString                QString(__FUNCTION__)
#define nMountSlot(src,target,sname)  connect(src,SIGNAL(sname),target,SLOT(sname))
#define nChecksum(BODY)               qChecksum(BODY.data(),BODY.size())
#define nConnect                      QObject::connect
#define nRegMeta(TYPE)                qRegisterMetaType<TYPE>(#TYPE)
#define PlanDebug                     if (NotNull(plan)) plan->Debug
#define FunctionDebug                 if (NotNull(plan)) plan->Debug(30,__FUNCTION__)
#define PlanTable(ID)                 plan->Tables[N::Tables::ID]
#define PlanEnabled(NAME)             plan->Booleans[NAME]
#define LinkAction(ID,Function)       connectAction(N::Menus::ID,this,SLOT(Function))
#define DisableAllActions             plan->disableAllAction
#define AssignAction(ID,text)         actionLabel(N::Menus::ID,text)
#define NewTreeWidgetItem(IT)         QTreeWidgetItem  * IT = new QTreeWidgetItem ()
#define NewListWidgetItem(IT)         QListWidgetItem  * IT = new QListWidgetItem ()
#define NewTableWidgetItem(IT)        QTableWidgetItem * IT = new QTableWidgetItem()
#define OcAssert(statement)
#define Alert(SONG)                   plan->Play((SUID)N::Command::SONG)
#define AppPlan                       ((Plan *)N::qPlan)
#define DoProcessEvents               plan->processEvents()
#define nInstruct(uuid)               (*((Instruction *)&uuid))
#define DeclTransformer               QVariants & Paraments,const QByteArray & Source,QByteArray & Target
#define DefineTransformer(func)       QVariants func(DeclTransformer)
#define ForLanguage(ID,Language)      { int ID ; foreach (ID,Language) {
#define EndLanguage(ID,Language)      } }
#define IfSqlQuery(SC,Q)              if (SC.Query(Q) && SC.Next())
#define IfSqlExec(SC)                 if (SC.Exec() && SC.Next())
#define IfSqlLoop(SC)                 if (SC.Exec()) while (SC.Next())
#define SqlLoopNow(SC,Q)              if (SC.Query(Q)) { while (SC.Next()) {
#define SqlLoopErr(SC,Q)              } } else {
#define SqlLoopEnd(SC,Q)              }
#define nStandardConstructor          QWidget * parent = NULL , N::Plan * plan = NULL
#define StandardConstructor           QWidget * parent = NULL ,    Plan * plan = NULL
#define nScopedMenu(menuNe,menuPt)    MenuManager menuNe(menuPt)
#define nConnectUuid                  SqlConnection & connection,SUID    uuid
#define nConnectName                  SqlConnection & connection,QString name
#define nDeclWidget                   QWidget * widget
#define nDeclDrops                    QWidget * widget,QPointF pos
#define DeclEmpty(ClassName)          class ClassName { }
#define AnyFunc(FUNCX)                ((AnythingFunction)FUNCX)
#define Iamv(member)                  (  this->member )
#define Iwas(member)                  (*(this->member))
#define UuidMax                       0xFFFFFFFFFFFFFFFFULL
#define FacialActionUuid              2383327738902944165ULL
#define PlayAudioUuid                 5837291319974772191ULL
#define PlayVideoUuid                 3623930284120264495ULL
#define BoneUuid                      9333000000000000001ULL
#define BodyFaceUuid                  9333000000000000021ULL
#define EarthUuid                     3974184930064418609ULL
#define RelationUUID(id)              ( 1242123421279021309 + N::Groups::id       )
#define ToGroupID(uuid)               ( uuid                - 1242123421279021309 )
#define SkinColorY                    0.03
#define SkinColorI(VAR)               RangeDouble VAR( 0.0750,0.3450)
#define SkinColorQ(VAR)               RangeDouble VAR(-0.0410,0.0410)
#define EnableDebugger                40
#define FromVariant(vxtype,vart)      ((vxtype *)VariantToVoid(vart))
#define DeclSQL                       SqlConnection & Connection
#define ThreadClass(TC)               Thread::Data.Properties["Class"] = QVariant(QString(TC))
#define WidgetClass                   if ( NULL != metaObject() ) ThreadClass(metaObject()->className())
//////////////////////////////////////////////////////////////////////////////
#define ConnectSQL(SC,SQL)       \
    N::SqlConnection SC(SQL)   ; \
    if (SC.open( __FUNCTION__ )) {
//////////////////////////////////////////////////////////////////////////////
#define DisconnectSQL(SC)        \
      SC.close()               ; \
    }                          ; \
    SC.remove()
//////////////////////////////////////////////////////////////////////////////
#define EnterSQL(SC,SQL)                                             \
    Bustle      (      )                                           ; \
    N::SqlConnection SC(SQL)                                       ; \
    if ( SC . open ( __FUNCTION__ , QtUUID::createUuidString() ) ) {
//////////////////////////////////////////////////////////////////////////////
#define ErrorSQL(SC,SQL) \
      SC.close ( ) ;     \
    } else               {
//////////////////////////////////////////////////////////////////////////////
#define LeaveSQL(SC,SQL) \
      SC.close ( ) ;     \
    } ;                  \
    SC.remove  ( ) ;     \
    Vacancy    ( ) ;
//////////////////////////////////////////////////////////////////////////////
#define nSqlDeleteUuid(SC,QQ,TT,uuid)               \
  {                                                 \
    QQ = SC.sql.DeleteFrom(TT,SC.WhereUuid(uuid)) ; \
    SC.Query(QQ)                                  ; \
  }
//////////////////////////////////////////////////////////////////////////////
#define nIsolatePainter(ClassName) \
    if (!EnterPainter()) return  ; \
    ClassName::paintEvent(event) ; \
    LeavePainter()               ;
//////////////////////////////////////////////////////////////////////////////
#define DockSignals                               \
  void attachDock  (QWidget           * widget  , \
                    QString             title   , \
                    Qt::DockWidgetArea  area    , \
                    Qt::DockWidgetAreas areas ) ; \
  void attachMdi   (QWidget * widget            , \
                    int       direction       )
//////////////////////////////////////////////////////////////////////////////
#define FastParkIn(Class,Widget,Parent,Plan,Action,SCOPE,Title,Position,Area) \
    Widget = new Class(Parent,Plan)                                 ;         \
    Widget-> Trigger = Action                                       ;         \
    Widget-> Scope   = SCOPE                                        ;         \
    Widget-> Docking(Parent,Title,Position,Area)                    ;         \
    Action-> setChecked(Widget->isDocking())                        ;         \
    connect(Action,SIGNAL(toggled(bool)),Widget,SLOT(DockIn(bool))) ;
//////////////////////////////////////////////////////////////////////////////
#define nNewWindow(nxClassName,nxWindow) \
  nxClassName * nxWindow = new nxClassName(Mdi,plan)
//////////////////////////////////////////////////////////////////////////////
#define BerthIn(ClassName,VariableName,Alignment)                     \
  ClassName * VariableName = new ClassName ( Container ( ) , plan ) ; \
  Parking ( VariableName , Alignment )
//////////////////////////////////////////////////////////////////////////////
#define NewVcf(vcfClass,vcf,vcfWidget,vcfParent)                   \
  vcfClass * vcf = new vcfClass ( vcfWidget , vcfParent , plan ) ; \
  Scene . addItem               ( vcf                          ) ; \
  addItem                       ( vcf , vcfParent              )
//////////////////////////////////////////////////////////////////////////////
#endif
