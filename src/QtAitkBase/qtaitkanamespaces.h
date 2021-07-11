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
#ifndef QT_AITK_BASE_NAMESPACES_H
#define QT_AITK_BASE_NAMESPACES_H
//////////////////////////////////////////////////////////////////////////////
namespace N                                                                  {

  typedef enum      {
    InitAll     = 0 ,
    InitNetwork = 1 ,
    InitLIBAV   = 2 ,
    InitCURL    = 3 ,
    InitMath    = 4 }
  InitialSystem     ;

  namespace Types               {

    typedef enum                {
      None               =    0 , // Generic type
      Type               =    1 , // Object type names
      Language           =    2 , // Human Language ID
      Name               =    3 , // Object names
      Action             =    4 , // Execution action types
      HistoryType        =    5 , // Histroical event type
      History            =    6 , // History Uuid
      People             =    7 , // People Uuid
      Resource           =    8 , // Resource types
      Picture            =    9 , // Picture
      Audio              =   10 , // Audio file
      Video              =   11 , // Video file
      PlainText          =   12 , // Plain text blocks
      XML                =   13 , // XML blocks
      File               =   14 , // File
      Schedule           =   15 , // Scheduler Events
      Task               =   16 , // Task Manager
      Acupuncture        =   17 , // Acupunctures
      DataTypes          =   18 , // Data types of programming Languages
      Eyes               =   19 , // Eyes types
      Hairs              =   20 , // Hair colors
      Gender             =   21 , // Human sexuality
      Star               =   22 , // Astrophysics stars
      TopLevelDomain     =   23 , // Internet TLD
      SecondLevelDomain  =   24 , // Internet Second level domains
      Keyword            =   25 , // Language keywords
      DomainName         =   26 , // Domain name
      Username           =   27 , // Normally e-mail username
      Encoding           =   28 , // Language Encoding
      KeywordRelation    =   29 , // Keyword relations
      URL                =   30 , // something like http://www.xxx.com/...
      EMail              =   31 , // E-Mail Uuid
      IPv4               =   32 , // IPv4 Address
      IPv6               =   33 , // IPv6 Address
      Race               =   34 , // Human races
      Particle           =   35 , // Basic physical particle
      Composite          =   36 , // Compositive physical particle
      Paper              =   37 , // Paper specification
      Organization       =   38 , // Human organization
      TypeOfOrganization =   39 , // Type of organization, Obosleted => use Tags instead
      Occupation         =   40 , // Occupations
      Meaning            =   41 , // Pure meaning
      MimeTypes          =   42 , // File MIME types
      Nation             =   43 , // Countries
      Administrative     =   44 , // Administrative regions
      Currency           =   45 , // Currency names
      CurrencyPair       =   46 , // Something like EUR/USD
      Flow               =   47 , // Flow chart (whole complete one)
      Document           =   48 , // Document UUID
      DecisionTable      =   49 , // Decision table
      DecisionTree       =   50 , // Decision tree
      Equipment          =   51 , // Equipments
      Face               =   52 , // Human faces
      OperationSystem    =   53 , // OS type
      ParamentType       =   54 , // Parament packet type
      Parament           =   55 , // Parament UUID
      Surname            =   56 , // Human surname
      VCF                =   57 , // Very Complex Format Object UUID
      Script             =   58 , // Script language files UUID
      Source             =   59 , // Source code UUID
      Palette            =   60 , // Color palette
      Knowledge          =   61 , // Knowledge node
      Field              =   62 , // Knowledge field
      KnowledgeBase      =   63 , // Knowledge database
      Gallery            =   64 , // Galleries of Pictures
      Continent          =   65 , // Geographical continents
      Point              =   66 , // Geometric points
      Contour            =   67 , // Close loop regions
      Line               =   68 , // Geometric lines
      Surface            =   69 , // Geometric surfaces
      MeaningTypes       =   70 , // Type of Meanings
      Project            =   71 , // Project UUID
      ProjectType        =   72 , // Project Types
      MathType           =   73 , // Mathematical object type
      MathObject         =   74 , // Mathematical objects
      Tag                =   75 , // Classification tags
      Album              =   76 , // Video or audio album
      Sexuality          =   77 , // Biological sexualities of all animals
      SqlDataType        =   78 , // SQL data types
      Coding             =   79 , // Programming Languages
      Compound           =   80 , // Chemical compounds
      RNA                =   81 , // Biological RNA
      DNA                =   82 , // Biological DNA
      Location           =   83 , // Geographical location on Earth
      Chromosome         =   84 , // Biological chromosomes
      Statistics         =   85 , // SQL Statistics
      DocumentFile       =   86 , // Document file
      Calendar           =   87 , // Calendar types
      Panel              =   88 , // Panel groups
      Execution          =   89 , // Executions
      GroupRelation      =   90 , // Group relations
      Division           =   91 , // Master group , division
      Period             =   92 , // Time period
      Variable           =   93 , // Variable name
      Body               =   94 , // Human body part
      Organ              =   95 , // Human body organ type
      Phone              =   96 , // Phone number
      CountryCode        =   97 , // Phone country code
      AreaCode           =   98 , // Phone area code
      Trigger            =   99 , // Trigger procedure
      Rectangle          =  100 , // Rectangle
      Painting           =  101 , // Painting objects
      Graphics           =  102 , // Graphics objects
      Length             =  103 , // Length units
      Shapes             =  104 , // Two dimensional geometric objects
      Manifolds          =  105 , // Geometric manifolds
      POSet              =  106 , // Partially ordered sets
      SetMember          =  107 , // Members of set
      Condition          =  108 , // Condition variables
      Indicator          =  109 , // Fuzzy indicator functions
      Commodity          =  110 , // Commodity IDs
      Package            =  111 , // Software package
      Version            =  112 , // Source/Software version
      Camera             =  113 , // 3D Graphics camera
      Light              =  114 , // 3D Graphics Light
      IPA                =  115 , // International Phonetic Alphabet
      SqlConnection      =  116 , // SQL connection settings
      SqlItem            =  117 , // SQL column item
      SqlTable           =  118 , // SQL table
      SqlPlan            =  119 , // SQL plan
      Enumeration        =  120 , // Member enumeration list, normally it is a CHECK LIST different with C/C++ enumerations
      SqlServer          =  121 , // SQL Server identifier
      Weight             =  122 , // Physical weight
      Energy             =  123 , // Energy units
      Area               =  124 , // Geographical Area
      DNS                =  125 , // DNS Acceration
      Newsgroup          =  126 , // Newsgroup
      Celestial          =  127 , // Celestial body types
      Equation           =  128 , // Mathematical equation
      Component          =  129 , // Programming components, such as macro, class
      SqlConstraint      =  130 , // SQL constraints
      Matrix             =  131 , // Mathematical matrix
      Sentence           =  132 , // Linguistic sentence
      Paragraph          =  133 , // Document paragraph
      Acoustic           =  134 , // Acoustic feature
      Terminology        =  135 , // Knowledge terminology
      Array              =  136 , // Data arrays
      Bound              =  137 , // Particle bound states
      Consanguinity      =  138 , // Consanguinity
      Kinship            =  139 , // Kinships
      Genealogy          =  140 , // Genealogy
      Sketch             =  141 , // Sketch
      CppState           =  142 , // C++ Analyizer State
      Spreadsheet        =  143 , // Spreadsheet table
      Nucleus            =  144 , // Physical nucleus
      ClfType            =  145 , // Chinese Language Formula Combinational Types
      RuleBase           =  146 , // Rule-based knowledge system
      Potential          =  147 , // Potential pending objects
      SetsAlgebra        =  148 , // Sets algebra
      ColorGroup         =  149 , // Color group
      InternetDomain     =  150 , // Internet domain name , ICANN assigned
      CCD                =  151 , // Digital camera paraments
      Obsolete           =  152 , // Obsolete objects
      Pending            =  153 , // Pending append objects
      Coroutine          =  154 , // Coroutine
      Semantic           =  155 , // Semantic fields
      Concept            =  156 , // Conceptual meanings
      Ideograph          =  157 , // a well-defined pure meaning
      Subgroup           =  158 , // Subgroup for a secondary classification
      FaceShape          =  159 , // Human face shapes
      Culture            =  160 , // Specific culture
      Phoneme            =  161 , // Phonemes
      EyesShape          =  162 , // Eyes shapes
      StyleSheet         =  163 , // CSS
      Stroke             =  164 , // Stroke (CJKV)
      Grapheme           =  165 , // Script grapheme
      Emotion            =  166 , // Creature Emotions
      Entry              =  167 , // Data entries
      Reference          =  168 , // Frame of Reference
      Constant           =  169 , // Math and Nature Constants
      StellarSpectrum    =  170 , // Stellar spectral classification
      EarthSpot          =  171 , // Earth geographical location
      Account            =  172 , // Accounts, Bank, Skype, Website
      FutureIndex        =  173 , // Future goods index
      StockSecurity      =  174 , // Security in Stock markets
      EconomicIndex      =  175 , // Economic Index
      VideoNote          =  176 , // Video Note
      Description        =  177 , // Generic descriptions
      Reality            =  178 , // Reality object
      Model              =  179 , // 3D Object Model
      MusicAlbum         =  180 , // Music Album
      TypesEnd           =  181 ,
      UserType           = 1501 }
      ObjectTypes               ;

  }

  namespace Groups {

    typedef enum           {
      Subordination =  1   ,
      Icon          =  2   ,
      Sexuality     =  3   ,
      Trigger       =  4   ,
      StartTrigger  =  5   ,
      FinalTrigger  =  6   ,
      Action        =  7   ,
      Condition     =  8   ,
      Synonymous    =  9   ,
      Equivalent    = 10   ,
      Contains      = 11   ,
      Using         = 12   ,
      Possible      = 13   ,
      Originate     = 14   ,
      Capable       = 15   ,
      Estimate      = 16   ,
      Alias         = 17   ,
      Counterpart   = 18   ,
      Explain       = 19   ,
      Fuzzy         = 20   ,
      Greater       = 21   ,
      Less          = 22   ,
      Before        = 23   ,
      After         = 24   ,
      Tendency      = 25   ,
      Different     = 26   ,
      End           = 27   }
      Relations            ; // Do not use `End` as a value, it changes all the time

    typedef enum         {
      User          =  0 ,
      ISP           =  1 ,
      Unix          =  2 ,
      Windows       =  3 ,
      CIOS          =  4 ,
      Bank          =  5 ,
      Google        =  6 ,
      Yahoo         =  7 ,
      Skype         =  8 ,
      LINE          =  9 ,
      WeChat        = 10 ,
      PayPal        = 14 ,
      Website       = 11 ,
      FTP           = 12 ,
      Mail          = 13 ,
      Chat          = 15 ,
      SQL           = 16 ,
      Source        = 17 ,
      MetaTrader    = 18 ,
      Others        = 19 ,
      EndOfAccounts = 20 }
      AccountTypes       ;

  }

  namespace Tables                    {

    typedef enum                      {
      NoTable                =      0 ,
      MajorUuid              = 100001 ,
      Objects                = 100002 ,
      Types                  = 100003 ,
      Names                  = 100004 ,
      NameMaps               = 100005 ,
      Divisions              = 100006 ,
      Groups                 = 100007 ,
      Tags                   = 100008 ,
      Gender                 = 100009 ,
      Triggers               = 100010 ,
      AreaCode               = 100011 ,
      Phones                 = 100012 ,
      Variables              = 100013 ,
      Rectangles             = 100014 ,
      Points                 = 100015 ,
      Painters               = 100016 ,
      Units                  = 100017 ,
      UFlags                 = 100018 ,
      Shapes                 = 100019 ,
      Manifolds              = 100020 ,
      Figures                = 100021 ,
      PoSets                 = 100022 ,
      SetMembers             = 100023 ,
      SetOrders              = 100024 ,
      Subsets                = 100025 ,
      PDL                    = 100026 ,
      Scheduling             = 100027 ,
      DeleteUuid             = 100028 ,
      Decisions              = 100029 ,
      Conditions             = 100030 ,
      Indicators             = 100031 ,
      Actions                = 100032 ,
      Binaries               = 100033 ,
      CountryCode            = 100034 ,
      Area                   = 100035 ,
      Continents             = 100036 ,
      Encodings              = 100037 ,
      TLD                    = 100038 ,
      GTLD                   = 100039 ,
      SitesTld               = 100040 ,
      SitesSld               = 100041 ,
      SitesError             = 100042 ,
      WebPages               = 100043 ,
      WebContents            = 100044 ,
      Languages              = 100045 ,
      MimeTypes              = 100046 ,
      PaperSize              = 100047 ,
      Nations                = 100048 ,
      Triples                = 100049 ,
      Projects               = 100050 ,
      ProjectTypes           = 100051 ,
      Sources                = 100052 ,
      Packages               = 100053 ,
      Commodities            = 100054 ,
      IPA                    = 100055 ,
      Rating                 = 100056 ,
      SqlServers             = 100057 ,
      SqlDataTypes           = 100058 ,
      SqlConnections         = 100059 ,
      SqlItems               = 100060 ,
      SqlConstraints         = 100061 ,
      SqlSchemeMaps          = 100062 ,
      SqlTables              = 100063 ,
      SqlCreations           = 100064 ,
      SqlSchemes             = 100065 ,
      SqlPlans               = 100066 ,
      Calendars              = 100067 ,
      Eyes                   = 100068 ,
      Hairs                  = 100069 ,
      Faces                  = 100070 ,
      Races                  = 100071 ,
      Resources              = 100072 ,
      Weight                 = 100073 ,
      Energy                 = 100074 ,
      DNS                    = 100075 ,
      IpAddress              = 100076 ,
      Newsgroups             = 100077 ,
      NewsAttributes         = 100078 ,
      Solar                  = 100079 ,
      Celestials             = 100080 ,
      Usernames              = 100081 ,
      Comity                 = 100082 ,
      Cameras                = 100083 ,
      Amplitude              = 100084 ,
      MathTypes              = 100085 ,
      MathObjects            = 100086 ,
      EMails                 = 100087 ,
      Flows                  = 100088 ,
      Codes                  = 100089 ,
      DataModels             = 100090 ,
      Preprocessors          = 100091 ,
      CppDefines             = 100092 ,
      Namespaces             = 100093 ,
      NamespaceMaps          = 100094 ,
      Includes               = 100095 ,
      Enumerations           = 100096 ,
      EnumerationLists       = 100097 ,
      Relations              = 100098 ,
      Extensions             = 100099 ,
      CheckLists             = 100100 ,
      Identifiers            = 100101 ,
      PdlExtensions          = 100102 ,
      Tasks                  = 100103 ,
      TaskProperties         = 100104 ,
      TaskRelations          = 100105 ,
      Settings               = 100106 ,
      Platforms              = 100107 ,
      Periods                = 100108 ,
      Chronology             = 100109 ,
      History                = 100110 ,
      Contours               = 100111 ,
      Equipments             = 100112 ,
      ActionTypes            = 100113 ,
      PeopleUuid             = 100114 ,
      PictureUuid            = 100115 ,
      ThumbUuid              = 100116 ,
      PictureOrders          = 100117 ,
      Events                 = 100118 ,
      EventHistory           = 100119 ,
      Videos                 = 100120 ,
      Audios                 = 100121 ,
      AudioFiles             = 100122 ,
      Bookmarks              = 100123 ,
      Sites                  = 100124 ,
      Classes                = 100125 ,
      Templates              = 100126 ,
      Typedefs               = 100127 ,
      Unions                 = 100128 ,
      Structures             = 100129 ,
      Functions              = 100130 ,
      DataTypes              = 100131 ,
      Scripts                = 100132 ,
      Primes                 = 100133 ,
      Acupunctures           = 100134 ,
      Surnames               = 100135 ,
      Meanings               = 100136 ,
      MeaningTypes           = 100137 ,
      Affiliations           = 100138 ,
      Alphabets              = 100139 ,
      Keywords               = 100140 ,
      Documents              = 100141 ,
      PlainText              = 100142 ,
      Files                  = 100143 ,
      VCF                    = 100144 ,
      Organizations          = 100145 ,
      Occupations            = 100146 ,
      Particles              = 100147 ,
      Composite              = 100148 ,
      Stars                  = 100149 ,
      Syntaxes               = 100150 ,
      Libraries              = 100151 ,
      Administrations        = 100152 ,
      Comments               = 100153 ,
      CameraParaments        = 100154 ,
      Matrices               = 100155 ,
      FaceParaments          = 100156 ,
      Sentences              = 100157 ,
      Paragraphs             = 100158 ,
      AcousticFeatures       = 100159 ,
      Terminology            = 100160 ,
      Histogram              = 100161 ,
      Genealogy              = 100162 ,
      Knowledge              = 100163 ,
      KnowledgeFields        = 100164 ,
      KnowledgeBases         = 100165 ,
      KnowledgeMaps          = 100166 ,
      Currency               = 100167 ,
      CurrencyPairs          = 100168 ,
      CheckItems             = 100169 ,
      Accelerators           = 100170 ,
      Arrays                 = 100171 ,
      Consanguinities        = 100172 ,
      Kinships               = 100173 ,
      CppState               = 100174 ,
      KeywordRelations       = 100175 ,
      SqlStatistics          = 100176 ,
      UrlPatterns            = 100177 ,
      Domains                = 100178 ,
      XML                    = 100179 ,
      Organs                 = 100180 ,
      Body                   = 100181 ,
      EventNotes             = 100182 ,
      Automations            = 100183 ,
      Executions             = 100184 ,
      Applications           = 100185 ,
      PictureColors          = 100186 ,
      PicturePalettes        = 100187 ,
      PictureLaplace         = 100188 ,
      Palettes               = 100189 ,
      ColorGroups            = 100190 ,
      SourceMaps             = 100191 ,
      SourceVersion          = 100192 ,
      KeywordNames           = 100193 ,
      DocumentFiles          = 100194 ,
      DocumentGroups         = 100195 ,
      HistoryTypes           = 100196 ,
      DecisionBranches       = 100197 ,
      ParamentTypes          = 100198 ,
      Paraments              = 100199 ,
      Sketch                 = 100200 ,
      FileManager            = 100201 ,
      Nuclei                 = 100202 ,
      ClfTypes               = 100203 ,
      Rules                  = 100204 ,
      FisDB                  = 100205 ,
      BadFaces               = 100206 ,
      Potentials             = 100207 ,
      SetsAlgebra            = 100208 ,
      DnsMX                  = 100209 ,
      CCD                    = 100210 ,
      SiteDepot              = 100211 ,
      PictureDepot           = 100212 ,
      ThumbDepot             = 100213 ,
      DocumentCodecs         = 100214 ,
      HttpStatus             = 100215 ,
      SitePages              = 100216 ,
      DocumentMimes          = 100217 ,
      PageParent             = 100218 ,
      PageTitles             = 100219 ,
      XmlDepot               = 100220 ,
      WwwPages               = 100221 ,
      WwwURIs                = 100222 ,
      WwwHeaders             = 100223 ,
      ImportBodies           = 100224 ,
      PageTLDs               = 100225 ,
      PageSLDs               = 100226 ,
      PageProtocols          = 100227 ,
      FileDepot              = 100228 ,
      TextDepot              = 100229 ,
      ForexSuppliers         = 100230 ,
      ClfElements            = 100231 ,
      ClfCompositions        = 100232 ,
      Requests               = 100233 ,
      Cultures               = 100234 ,
      FaceShapes             = 100235 ,
      Phonemes               = 100236 ,
      EyesShapes             = 100237 ,
      VideoGroups            = 100238 ,
      StyleSheets            = 100239 ,
      Subgroups              = 100240 ,
      NewsServers            = 100241 ,
      ClfTree                = 100242 ,
      ClfStrokes             = 100243 ,
      ClfGraphemes           = 100244 ,
      BoundStates            = 100245 ,
      Nucleus                = 100246 ,
      Emotions               = 100247 ,
      Axes                   = 100248 ,
      Constants              = 100249 ,
      FeaturePoints          = 100250 ,
      KeyPoints              = 100251 ,
      IconGroups             = 100252 ,
      PictureGroups          = 100253 ,
      PeopleGroups           = 100254 ,
      AlbumGroups            = 100255 ,
      CodeGroups             = 100256 ,
      NetGroups              = 100257 ,
      OtherGroups            = 100258 ,
      Entries                = 100259 ,
      PersonMaps             = 100260 ,
      ClipMaps               = 100261 ,
      EarthSpot              = 100262 ,
      ForexCommodities       = 100263 ,
      PictureSummary         = 100264 ,
      Descriptions           = 100265 ,
      Reality                = 100266 ,
      Populations            = 100267 ,
      ISO3166                = 100268 ,
      /////////////////////////////////
      Private                = 100500 ,
      MarkTime               = 100501 ,
      Branon                 = 100502 ,
      BranonPanel            = 100503 ,
      /////////////////////////////////
      UserTable              = 900000 }
      SystemTables                    ;

  }

  namespace CPU
  {

    typedef enum              {
      _RDTSC     = 0x00000001 ,
      _ALTIVEC   = 0x00000002 ,
      _MMX       = 0x00000004 ,
      _3DNOW     = 0x00000008 ,
      _SSE       = 0x00000010 ,
      _SSE2      = 0x00000020 ,
      _SSE3      = 0x00000040 ,
      _SSE41     = 0x00000100 ,
      _SSE42     = 0x00000200 }
      Features                ;

    typedef enum              {
      Unknown    = 0          , // < cannot determine power status
      OnBattery  = 1          , // < Not plugged in, running on the battery
      NoBattery  = 2          , // < Plugged in, no battery available
      Charging   = 3          , // < Plugged in, charging battery
      Charged    = 4          } // < Plugged in, battery charged
      PowerState              ;

  }

  namespace IdSections         {

    typedef enum               {
      Human           =   9979 ,
      SetMembers      =   7244 ,
      HumanSurname    = 213141 ,
      HumanOrgan      =   3677 ,
      Acupuncture     =   3679 ,
      HistoryTypeHead = 197732 ,
      HistoryHead     = 141312 ,
      PeriodHead      = 141313 ,
      DontCare        =      0 }
      SectionNumbers           ;

  }

  namespace Dynamic       {

    enum ParamentTypes    {
      Functionality = 0   ,
      Nature        = 1   ,
      Math          = 2   ,
      Constant      = 3   ,
      Automation    = 4   ,
      Application   = 5   ,
      System        = 6 } ;

    typedef enum          {
      Default       =   0 ,
      Typo          =   1 ,
      Pen           =   2 ,
      Stage         =   3 ,
      Abbreviation  =   4 ,
      Identifier    =   5 ,
      Entry         =   6 ,
      Pronunciation =   7 ,
      Other         =  99 ,
      EndName       =   8 }
      NameUsages          ;

  }

  namespace Decisions      {

    typedef enum           {
      Node            =  0 ,
      Database        =  1 ,
      File            =  2 ,
      Opportunity     =  3 ,
      Probability     =  4 ,
      Logic           =  5 ,
      Fuzzy           =  6 ,
      Dynamic         =  7 ,
      Functional      =  8 ,
      Script          =  9 ,
      Virtual         = 10 ,
      EndOfConditions = 11 }
      Conditions           ;

  }

  typedef enum {
    North = 0  ,
    South = 1  ,
    East  = 2  ,
    West  = 3  }
    Direction  ;

  typedef enum    {
    Nothing   = 0 ,
    TCP       = 1 ,
    UDP       = 2 ,
    RAW       = 3 ,
    RDM       = 4 ,
    SEQPACKET = 5 }
    SocketType    ;

  typedef enum        {
    SAMPLE_NONE  =  0 ,
    SAMPLE_8000  =  1 ,
    SAMPLE_11025 =  2 ,
    SAMPLE_16000 =  3 ,
    SAMPLE_22050 =  4 ,
    SAMPLE_44100 =  8 ,
    SAMPLE_48000 = 10 ,
    SAMPLE_96000 = 16 }
    SampleRate        ;

  typedef enum               {
    Error              =  -1 ,
    None               =   0 ,
    Notify             =   1 ,
    Period             =   2 ,
    Record             =   3 ,
    Meeting            =   4 ,
    Automation         =   5 ,
    Operation          =   6 ,
    Sync               =   7 ,
    Download           =   8 ,
    Upload             =   9 ,
    Audio              =  10 ,
    Video              =  11 ,
    TV                 =  12 ,
    Programming        =  13 ,
    Backup             =  14 ,
    FileUpdate         =  15 ,
    Cooking            =  16 ,
    Sleep              =  17 ,
    Housework          =  18 ,
    Shopping           =  19 ,
    Communication      =  20 ,
    Finish             =  21 ,
    Obsolete           =  22 ,
    Others             =  23 ,
    ForexTrade         =  24 ,
    MaxEventTypeNumber =  25 }
    EventType                ;

  typedef enum              {
    RootTask           = -1 ,
    ParentTask         =  0 ,
    ChildTask          =  1 ,
    BranchTask         =  2 }
    TaskEnum                ;

  typedef enum              {
    SqlDatabase        =  1 ,
    SqlTable           =  2 ,
    SqlColumn          =  3 }
    SqlMajorItem            ;

  enum IpcState          {
    IpcNoConnection  = 0 ,
    IpcDisconnecting = 1 ,
    IpcConnected     = 2 ,
    IpcReading       = 3 ,
    IpcWriting       = 4 ,
    IpcIdle          = 5 ,
    IpcNoop          = 6
  }                      ;

  namespace Transformers         {

    typedef enum                 {
      Hollowness        = 100001 ,
      Copier            = 100002 ,
      B32Encoder        = 100011 ,
      B32Decoder        = 100012 ,
      B64Encoder        = 100013 ,
      B64Decoder        = 100014 ,
      QtZipCompressor   = 101001 ,
      QtZipDecompressor = 101002 ,
      RleCompressor     = 101003 ,
      RleDecompressor   = 101004 ,
      GzipCompressor    = 101005 ,
      GzipDecompressor  = 101006 ,
      BzipCompressor    = 101007 ,
      BzipDecompressor  = 101008 ,
      XzCompressor      = 101009 ,
      XzDecompressor    = 101010 ,
      LzoCompressor     = 101011 ,
      LzoDecompressor   = 101012 ,
      MD4Encoder        = 101013 ,
      MD5Encoder        = 101014 ,
      UserAddenda       = 200000 }
      GenericTransformIDs        ;

  }

  namespace Compressions {

    typedef enum       {
      QZ          =  0 , // Qt style qCompress/qUncompress
      GZ          =  1 , // GNU ZIP
      BZ          =  2 , // BZIP2
      XZ          =  3 , // XZ Utils
      LZ          =  4 , // LZIP
      LZO         =  5 , // LZO
      LZMA        =  6 , // 7z LZMA
      RLE         =  7 , // Generic RLE Algorithm
      LHA         =  8 , // LHA, LZH
      ShannonFano =  9 , // Shannon-Fano coding
      Huffman     = 10 , // Huffman coding
      LZ77        = 11 , // LZ77
      LZW         = 12 , // LZW , LZ78
      LZX         = 13 , // LZW , LZ77 family
      SQX         = 14 , // SQX
      RICE        = 15 , // Rice coding
      UCL         = 16 , // UCL
      LZ4         = 17 , // LZ4
      QuickLZ     = 18 , // QuickLZ
      LZF         = 19 , // LZF
      Snappy      = 20 , // Snappy
      EOC         = 21 } // End of compression type
      GeneralMethods   ;

  }

  namespace SQL        {

    typedef enum       {
      NONE        =  0 ,
      ENUM        =  1 ,
      SET         =  2 ,
      TINYINT     =  3 ,
      SMALLINT    =  4 ,
      MEDIUMINT   =  5 ,
      INT         =  6 ,
      BIGINT      =  7 ,
      FLOAT       =  8 ,
      DOUBLE      =  9 ,
      REAL        = 10 ,
      DECIMAL     = 11 ,
      NUMERIC     = 12 ,
      CHAR        = 13 ,
      VARCHAR     = 14 ,
      TINYTEXT    = 15 ,
      TEXT        = 16 ,
      MEDIUMTEXT  = 17 ,
      LONGTEXT    = 18 ,
      TINYBLOB    = 19 ,
      BLOB        = 20 ,
      MEDIUMBLOB  = 21 ,
      LONGBLOB    = 22 ,
      DATE        = 23 ,
      DATETIME    = 24 ,
      TIMESTAMP   = 25 ,
      TIME        = 26 ,
      YEAR        = 27 ,
      MAXSQLTYPES = 28 }
      SqlType          ;

    enum SqlProperty            {
      SQLNULL          = 0x0000 ,
      SQLNOTNULL       = 0x0001 ,
      SQLAUTOINCREMENT = 0x0002 ,
      SQLPRIMARYKEY    = 0x0004 ,
      SQLUNIQUE        = 0x0008 ,
      SQLINDEX         = 0x0010 ,
      SQLFILL          = 0x0020
    }                           ;

  }

  namespace Mouse     {

    enum MouseStatus  {
      Press       = 1 ,
      Move        = 2 ,
      Release     = 3 ,
      DoubleClick = 4
    }                 ;

  }

  namespace Tags        {

    enum TagRelation    {
      None          = 0 ,
      Offspring     = 1 ,
      Bidirectional = 2 ,
      Parallel      = 3 ,
      Fuzzy         = 4
    }                   ;

  }

  namespace Flow       {

    enum ChartType     {
      Simple       = 0 ,
      FlowChart    = 1 ,
      DecisionTree = 2 ,
      DataFlow     = 3 ,
      WorkFlow     = 4 ,
      Programming  = 5 ,
      Algorithm    = 6 ,
      Mind         = 7 ,
      Composite    = 8 ,
      MaxChartType = 9
    }                  ;

    enum FlowType     {
      BlackBox    = 0 ,
      Execution   = 1 ,
      Decision    = 2 ,
      Input       = 3 ,
      Output      = 4 ,
      Entry       = 5 ,
      Exit        = 6 ,
      LoopControl = 7 ,
      Floating    = 8 ,
      MaxFlowType = 9
    }                 ;

  }

  namespace Command {

    enum Automation {
      Update   =  0 ,
      Refresh  =  1 ,
      Open     =  2 ,
      Close    =  3 ,
      Next     =  4 ,
      Previous =  5 ,
      Left     =  6 ,
      Right    =  7 ,
      Up       =  8 ,
      Down     =  9 ,
      Search   = 10 ,
      Record   = 11 ,
      Play     = 12 ,
      ZoomIn   = 13 ,
      ZoomOut  = 14
    }               ;

    enum Event      {
      Wrong    =  0 ,
      Click    =  1 ,
      Selected =  2 ,
      Menu     =  3 ,
      Error    =  4 ,
      Done     =  5 ,
      Action   =  6
    }               ;

  }

  namespace Project         {

    enum ProjectType        {
      MAJORPROJECT     =  0 ,
      SUBPROJECT       =  1 ,
      DOCUMENTS        =  2 ,
      PLANNER          =  3 ,
      SCHEDULER        =  4 ,
      TASK             =  5 ,
      FINANCE          =  6 ,
      TEST             =  7 ,
      NETWORK          =  8 ,
      SQL              =  9 ,
      FLOW             = 10 ,
      DATAMODEL        = 11 ,
      CLASSMODEL       = 12 ,
      QTPROJECT        = 13 ,
      INSTALLER        = 14 ,
      SOURCES          = 15 ,
      PICTURES         = 16 ,
      GUI              = 17 ,
      KNOWLEDGE        = 18 ,
      WEBSITE          = 19 ,
      BOOKMARKS        = 20 ,
      SKETCH           = 21 ,
      DATASHEET        = 22 ,
      MAXPROJECTNUMBER = 23
    }                       ;

  }

  namespace Network           {

    enum LocalServerState     {
      InterpreterClient =   0 ,
      InterpreterServer =   1 ,
      TryBinding        =   0 ,
      Pending           =   1 ,
      NextConnection    =   2 ,
      BindFailure       =  11 ,
      WaitConnection    =  12 ,
      LoopWait          =  91 ,
      NextLoop          =  99 ,
      LocalPrepare      =   0 ,
      LocalConnecting   =   1 ,
      LocalWelcome      =   9 ,
      LocalReady        =  11 ,
      LocalRead         =  12 ,
      LocalTimeOut      =  81 ,
      LocalAgain        =  82 ,
      LocalDisconnect   =  99 ,
      RemotePrepare     = 100 ,
      RemoteConnecting  = 101 ,
      RemoteWelcome     = 109 ,
      RemoteReady       = 111 ,
      RemoteRead        = 112 ,
      RemoteTimeOut     = 181 ,
      RemoteAgain       = 182 ,
      RemoteDisconnect  = 199 ,
      SharedPrepare     = 200 ,
      SharedConnecting  = 201 ,
      SharedWelcome     = 209 ,
      SharedReady       = 211 ,
      SharedRead        = 212 ,
      SharedTimeOut     = 281 ,
      SharedAgain       = 282 ,
      SharedDisconnect  = 299
    }                         ;

  }

  namespace Fonts {

    enum FontId           {
      Default     =     0 ,
      Menu        =     1 ,
      Editor      =     2 ,
      Tree        =     3 ,
      ToolTip     =     4 ,
      Status      =     5 ,
      Message     =     6 ,
      ComboBox    =     7 ,
      TreeView    =     8 ,
      ListView    =     9 ,
      TableView   =    10 ,
      Label       =    11 ,
      CheckBox    =    12 ,
      Progress    =    13 ,
      Button      =    14 ,
      Spin        =    15 ,
      IPA         =    16 ,
      Math        =    17 ,
      User        =    18 ,
      Class       = 10001 ,
      Inherit     = 10002 ,
      Keyword     = 10003 ,
      Specifier   = 10004 ,
      Qualifier   = 10005 ,
      Member      = 10006 ,
      Function    = 10007 ,
      Symbol      = 10008 ,
      Requirement = 10009 ,
      Comment     = 10010
    }                     ;

  }

  namespace Texts {

    enum Layout {
      TopLeftToTopRight    = 0 , // LeftToRight + UpToDown
      TopRightToTopLeft    = 1 , // RightToLeft + UpToDown
      TopRightToBottomLeft = 2 , // TopRight => BottomLeft
      TopLeftToBottomRight = 3
    };

  }

  namespace Tasks       {

    enum Behaviors  {
      Undecided   = 0   ,
      Standalone  = 1   ,
      Framework   = 2   ,
      Root        = 3   ,
      Child       = 4   ,
      Heir        = 5   ,
      Decision    = 6   ,
      Prerequiste = 7   ,
      Obsolete    = 8 } ;

    enum States          {
      Template    =  1   ,
      Proposed    =  2   ,
      Analysis    =  3   ,
      Preparation =  4   ,
      Ready       =  5   ,
      Dispatching =  6   ,
      Assigned    =  7   ,
      Execution   =  8   ,
      Feedback    =  9   ,
      Completed   = 10   ,
      Terminated  = 11   ,
      Expired     = 12   ,
      Forwarded   = 13   ,
      Finished    = 14   ,
      Failed      = 15   ,
      Delegated   = 16   ,
      Rejected    = 17   ,
      Review      = 18   ,
      End         = 19 } ;

  }

  namespace Plugins   {

    enum WidgetLayout {
      ItemStyle   = 0 ,
      WidgetStyle = 1
    }                 ;

  }

  namespace Acoustics {

    typedef enum   {
      Input  = 1   ,
      Output = 2   ,
      Camera = 3   }
      Equipment    ;

    typedef enum   {
      Guess   = 0  ,
      Int8    = 1  ,
      UInt8   = 2  ,
      Int16   = 3  ,
      Int24   = 4  ,
      Int32   = 5  ,
      Float32 = 6  ,
      Double  = 7  ,
      Custom  = 8  }
      SampleFormat ;

  }

  namespace Calendars           {

    enum CalendarId             {
      StarDate            =   0 ,
      StarTime            =   1 ,
      ISO                 =   2 ,
      Cosmos              =   3 ,
      Geogrian            =   4 ,
      Proleptic           =   5 ,
      Julian              =   6 ,
      Holocene            =   7 ,
      Buddhist            =   8 ,
      Taiwanese           =   9 ,
      Juche               =  10 ,
      Bengali             =  11 ,
      Lunar               =  12 ,
      World               =  13 ,
      Bahai               =  14 ,
      Armenian            =  15 ,
      Zoroastrian         =  16 ,
      Berber              =  17 ,
      Burmese             =  18 ,
      Byzantine           =  19 ,
      Coptic              =  20 ,
      Ethiopian           =  21 ,
      Hebrew              =  22 ,
      Hindu               =  23 ,
      Persian             =  24 ,
      Islamic             =  25 ,
      Thai                =  26 ,
      Assyrian            =  27 ,
      Perpetual           =  28 ,
      Akan                =  29 ,
      Discordian          =  30 ,
      Germanic            =  31 ,
      Igbo                =  32 ,
      Gaelic              =  33 ,
      Jain                =  34 ,
      Saka                =  35 ,
      Javanese            =  36 ,
      Kurdish             =  37 ,
      Lithuanian          =  38 ,
      Malayalam           =  39 ,
      Nanakshahi          =  40 ,
      Nepali              =  41 ,
      NepalSambat         =  42 ,
      RevisedJulian       =  43 ,
      Romanian            =  44 ,
      Runic               =  45 ,
      Tamil               =  46 ,
      ThaiLunar           =  47 ,
      Tibetan             =  48 ,
      Xhosa               =  49 ,
      Yoruba              =  50 ,
      Attic               =  51 ,
      Aztec               =  52 ,
      Babylonian          =  53 ,
      Bulgar              =  54 ,
      Coligny             =  55 ,
      Egyptian            =  56 ,
      Enoch               =  57 ,
      Florentine          =  58 ,
      FrenchRepublican    =  59 ,
      Hellenic            =  60 ,
      OldIcelandic        =  61 ,
      AncientMacedonian   =  62 ,
      Mesoamerican        =  63 ,
      Pentecontad         =  64 ,
      Positivist          =  65 ,
      RapaNui             =  66 ,
      Roman               =  67 ,
      Rumi                =  68 ,
      Soviet              =  69 ,
      Swedish             =  70 ,
      Celtic              =  71 ,
      Inca                =  72 ,
      Turkmen             =  73 ,
      ProlepticJulian     =  74 ,
      Dreamspell          =  75 ,
      Invariable          =  76 ,
      Tranquility         =  77 ,
      BalinesePawukon     =  78 ,
      BalineseSaka        =  79 ,
      Pax                 =  80 ,
      CommonCivilTime     =  81 ,
      Symmetry            =  82 ,
      HankeHenryPermanent =  83 ,
      HermeticLeapWeek    =  84 ,
      Darian              =  85 ,
      MiddleEarth         =  86 ,
      GalaxyLegend        =  87 ,
      GalaxyRepublic      =  88 ,
      GalaxyEmperor       =  89 ,
      NewGalaxyEmperor    =  90 ,
      Regnal              =  91 ,
      AbUrbeCondita       =  92 ,
      Japanese            =  93 ,
      Korean              =  94 ,
      Confucius           =  95 ,
      Huangdi             =  96 ,
      Dao                 =  97 ,
      Dai                 =  98 ,
      Maya                =  99 ,
      Tzolkin             = 100 ,
      Haab                = 101 ,
      MayaLunar           = 102 ,
      MayaVenus           = 103 ,
      India               = 104 ,
      StarTrek            = 105 ,
      End                     } ;

    enum TimeLine         {
      Out           = 0   ,
      Fuzzy         = 1   ,
      About         = 2   ,
      At            = 3   ,
      Before        = 4   ,
      After         = 5   ,
      Duration      = 6   ,
      EndOfTimeLine = 7 } ;

  }

  namespace VCF                {

    enum GraphicsItemId               {
      Cursor           = 0x00000001   ,
      Arrow            = 0x00000002   ,
      Rectangle        = 0x00000003   ,
      Paragraph        = 0x00000010   ,
      Canvas           = 0x00000011   ,
      Label            = 0x00000012   ,
      Table            = 0x00000013   ,
      Path             = 0x00000014   ,
      Lines            = 0x00000015   ,
      Contours         = 0x00000016   ,
      Linker           = 0x00000017   ,
      Panel            = 0x00000018   ,
      Interface        = 0x00000019   ,
      Slider           = 0x0000001A   ,
      Node             = 0x0000001B   ,
      Cells            = 0x0000001C   ,
      Glyph            = 0x0000001D   ,
      Block            = 0x0000001E   ,
      Wave             = 0x0000001F   ,
      Picture          = 0x00000021   ,
      Color            = 0x00000022   ,
      ColorPicker      = 0x00000023   ,
      SqlTable         = 0x00000031   ,
      TimeBar          = 0x00000041   ,
      TimeSection      = 0x00000042   ,
      Gantt            = 0x00000043   ,
      Flags            = 0x00000050   ,
      Document         = 0x00000051   ,
      Decision         = 0x00000061   ,
      Action           = 0x00000062   ,
      Branch           = 0x00000063   ,
      UI               = 0x00000071   ,
      Mind             = 0x00000081   ,
      Blocks           = 0x00000091   ,
      Scheduler        = 0x00000101   ,
      Task             = 0x00000201   ,
      Tasks            = 0x00000202   ,
      Forex            = 0x00000301   ,
      Candlestick      = 0x00000311   ,
      Earth            = 0x00000401   ,
      Source           = 0x00000501   ,
      Flow             = 0x00000601   ,
      Flows            = 0x00000602   ,
      Paper            = 0x00001000   ,
      Ruler            = 0x00001001   ,
      Calibration      = 0x00001002   ,
      Grid             = 0x00001003   ,
      BaccaratNotation = 0x00060001   ,
      BaccaratPaper    = 0x00060002 } ;

    enum FontIds               {
      Content   = 0x00000001   ,
      Bold      = 0x00000002   ,
      Oblique   = 0x00000003   ,
      Capital   = 0x00000004   ,
      Subject   = 0x00000005   ,
      Chapter   = 0x00000006   ,
      Section   = 0x00000007   ,
      Item      = 0x00000008   ,
      List      = 0x00000009   ,
      Keyword   = 0x0000000A   ,
      Knowledge = 0x0000000B   ,
      Hyperlink = 0x0000000C   ,
      Citation  = 0x0000000D   ,
      Comment   = 0x0000000E   ,
      Signature = 0x0000000F   ,
      User      = 0x00000010 } ;

    enum ArrowStates {
      Nothing  = 0   ,
      Triangle = 1   ,
      Ellipse  = 2
    }                ;

  }

  namespace Menus {

    typedef enum            {
      Start        =      0 ,
      Quit         =      1 ,
      Insert       =      2 ,
      Search       =      3 ,
      Replace      =      4 ,
      Refresh      =      5 ,
      Rename       =      6 ,
      Undo         =      7 ,
      Redo         =      8 ,
      Cut          =      9 ,
      Copy         =     10 ,
      Paste        =     11 ,
      Delete       =     12 ,
      Select       =     13 ,
      SelectAll    =     14 ,
      SelectNone   =     15 ,
      ZoomIn       =     16 ,
      ZoomOut      =     17 ,
      Font         =     18 ,
      Properties   =     19 ,
      Load         =     20 ,
      Save         =     21 ,
      Close        =     22 ,
      SaveAs       =     23 ,
      SaveAll      =     24 ,
      CloseAll     =     25 ,
      Play         =     26 ,
      Forward      =     27 ,
      Backward     =     28 ,
      Stop         =     29 ,
      Import       =     30 ,
      Export       =     31 ,
      Print        =     32 ,
      ExportPDF    =     33 ,
      Cascade      =     34 ,
      Tile         =     35 ,
      Subwindow    =     36 ,
      Tabbed       =     37 ,
      Reload       =     38 ,
      Home         =     39 ,
      End          =     40 ,
      Previous     =     41 ,
      Next         =     42 ,
      PictureTool  =     43 ,
      PictureStart =     44 ,
      PicturePage  =     45 ,
      PictureMove  =     46 ,
      Label        =     47 ,
      GoUp         =     48 ,
      GoDown       =     49 ,
      PreviousPage =     50 ,
      NextPage     =     51 ,
      GoHome       =     52 ,
      GoEnd        =     53 ,
      Language     =     54 ,
      Eradicate    =     55 ,
      Original     =     56 ,
      Back         =     57 ,
      Pause        =     58 ,
      Resume       =     59 ,
      AppMenu      =     60 ,
      UserMenu     =     61 ,
      DeviceMenuId = 100000 }
      GlobalMenus           ;

  }

  namespace History           {

    enum HistoryTypes         {
      ProgramStart     =  1   ,
      ProgramAbort     =  2   ,
      ProgramFinish    =  3   ,
      PeopleBirth      =  4   ,
      PeopleDie        =  5   ,
      NationBirth      =  6   ,
      NationVanish     =  7   ,
      ActionStart      =  8   ,
      ActionChange     =  9   ,
      ActionEnd        = 10   ,
      WorkingPeriod    = 11   ,
      SleepPeriod      = 12   ,
      Hint             = 13   ,
      TimeSpot         = 14   ,
      FileCreation     = 15   ,
      FileModification = 16   ,
      PublishDate      = 17   ,
      StartTag         = 18 } ;

  }

  namespace Human {

    typedef enum {
      Bone  = 1  ,
      Heart = 2  ,
      End   = 3  }
      Body       ;

    typedef enum      {
      Family      = 1 , // Surname
      Given       = 2 , // Given name
      Middle      = 3 , // Western style
      Clan        = 4 , // Clans
      Father      = 5 , // Patrilineality
      Mother      = 6 , // Matrilineality
      Art         = 7 , // Pseudonym
      Pen         = 8 , // Nickname
      EndOfNaming = 9 }
      Naming          ;

    typedef enum           {
      Eastern          = 1 , // Family + Given
      Western          = 2 , // Given  + Middle + Family
      Patrilineality   = 3 , // Father + Given
      Matrilineality   = 4 , // Mother + Given
      Clans            = 5 , // Given  + Family + Clan
      Arabic           = 6 , // Pen    + Given  + Art    + Father + Family
      EndOfNamingRules = 7 }
      NamingRules          ;

    typedef enum            {
      Analytic       = 0x01 ,
      Isolating      = 0x02 ,
      Synthetic      = 0x10 ,
      Fusional       = 0x11 ,
      Agglutinative  = 0x12 ,
      Polysynthetic  = 0x14 ,
      Oligosynthetic = 0x18 }
      LanguageTypes         ;

  }

  namespace Directory    {

    enum Paths           {
      Documents   =  1   ,
      Images      =  2   ,
      Sounds      =  3   ,
      Download    =  4   ,
      Upload      =  5   ,
      History     =  6   ,
      Development =  7   ,
      Plugins     =  8   ,
      Player      =  9   ,
      Web         = 10   ,
      Scripts     = 11   ,
      Qt          = 12   ,
      MetaTrader  = 13   ,
      Include     = 14   ,
      Help        = 15   ,
      Backup      = 16   ,
      Android     = 17   ,
      Temporary   = 18   ,
      Users       = 19   ,
      Binary      = 20 } ;

  }

  namespace Faces
  {
    enum ClassiferId   {
      FrontalFace =  1 ,
      LeftEye     =  2 ,
      RightEye    =  3 ,
      Mouth       =  4 ,
      Nose        =  5 ,
      LeftEar     =  6 ,
      RightEar    =  7 ,
      Glass       =  8 ,
      Body        =  9 ,
      UpperBody   = 10 ,
      LowerBody   = 11
    }                  ;
  }

  namespace Graphics
  {

    typedef enum    {
      Font     =  1 ,
      Gradient =  2 ,
      Pen      =  3 ,
      Brush    =  4 }
      Painters      ;

    typedef enum             {
      None      =          0 ,
      Start     =          1 ,
      Flat      =          2 ,
      Cubic     =          3 ,
      Quadratic =          4 ,
      End       =          5 ,
      Linear    = 0x00010000 ,
      Plane     = 0x00020000 ,
      Solid     = 0x00040000 }
      ContourTypes           ;

    typedef enum         {
      RGBA  =          1 ,
      CMYK  =          2 ,
      HSV   =          3 ,
      HSL   =          4 ,
      YUV   =          5 ,
      YIQ   =          6 ,
      XYZ   =          7 ,
      Lab   =          8 ,
      LUV   =          9 ,
      BaseR = 0x00010000 ,
      BaseG = 0x00020000 ,
      BaseB = 0x00040000 ,
      BaseA = 0x00080000 ,
      BaseC = 0x00100000 ,
      BaseM = 0x00200000 ,
      BaseY = 0x00400000 ,
      BaseK = 0x00800000 ,
      BaseL = 0x01000000 ,
      BaseV = 0x02000000 }
      ColorModel         ;

    typedef enum       {
      LinearLayout = 1 ,
      Divide       = 2 ,
      Belong       = 3 ,
      TopLeft      = 4 ,
      TopRight     = 5 ,
      BottomLeft   = 6 ,
      BottomRight  = 7 ,
      Overline     = 8 ,
      Underline    = 9 }
      MathLayout       ;

  }

  namespace Physics
  {

    typedef enum       {
      Pixel       =   0, /* Not actual unit, used on computer rendition */
      /* Astronomy System */
      Parsec      =   1, /* 206265AU
                            30,856,804,798,079,115 Meters
                            about 3.261567 ly
                          */
      LightYear   =   2, /* 9,460,730,472,580,800 Meters */
      LightDay    =   3, /* 25,902,068,371,200 Meters */
      LightHour   =   4, /* 1,079,252,848,800 Meters */
      AU          =   5, /* 149,597,870,691 Meters */
      LightMinute =   6, /* 17,987,547,480 Meters */
      LightSpeed  =   7, /* 299,792,458 Meters */
      /* SI System */
      Yottametre  = 101, /* 10 ^  24 Meters */
      Zettametre  = 102, /* 10 ^  21 Meters */
      Exametre    = 103, /* 10 ^  18 Meters */
      Petametre   = 104, /* 10 ^  15 Meters */
      Terametre   = 105, /* 10 ^  12 Meters */
      Gigametre   = 106, /* 10 ^   9 Meters */
      Megametre   = 107, /* 10 ^   6 Meters */
      Kilometer   = 108, /* 10 ^   3 Meters */
      Hectometre  = 109, /* 10 ^   2 Meters */
      Decametre   = 110, /* 10 ^   1 Meters */
      Meter       = 111, /* Light Speed : 299792458 Meters */
      Decimeter   = 112, /* 10 ^ - 1 Meter */
      Centimeter  = 113, /* 10 ^ - 2 Meter */
      Millimeter  = 114, /* 10 ^ - 3 Meter */
      Micrometre  = 115, /* 10 ^ - 6 Meter */
      Nanometer   = 116, /* 10 ^ - 9 Meter */
      Angstrom    = 117, /* 10 ^ -10 Meter */
      Picometre   = 118, /* 10 ^ -12 Meter */
      Fermi       = 119, /* 10 ^ -15 Meter */
      Attometer   = 120, /* 10 ^ -18 Meter */
      Zeptometre  = 121, /* 10 ^ -21 Meter */
      Yoctometre  = 122, /* 10 ^ -24 Meter */
      SuperString = 123, /* 10 ^ -33 Meter */
      Planck      = 124, /* 10 ^ -36 Meter */
      MilliPlanck = 125, /* 10 ^ -39 Meter */
      NanoPlanck  = 126, /* 10 ^ -45 Meter */
      /* Imperial Units */
      Mile        = 201, /* 1609.344 Meters */
      Furlong     = 202, /* 220 Yards */
      Chain       = 203, /* 22 Yards */
      Rod         = 204, /* 5.5 Yards , 5.0292 Meters */
      Perch       = 205, /* 5.5 Yards , same name */
      Pole        = 206, /* 5.5 Yards , same name */
      Lug         = 207, /* 5.5 Yards , same name */
      Fathom      = 208, /* 2 Yards , 182.88 Centimeters */
      Yard        = 209, /* 91.44 Centimeters */
      Foot        = 210, /* 30.48 Centimeters */
      Hand        = 211, /* 10.16 Centimeters */
      Inch        = 212, /* 2.54 Centimeters */
      /* Chinese Modern Unit */
      ChineseLi   = 301, /* 500 Meters */
      ChineseYin  = 302, /* 15 Yin = 1 Li */
      ChineseZhang= 303, /* 150 Zhang = 1 Li */
      ChineseBu   = 304, /* 5 Chi */
      ChineseChi  = 305, /* 1500 Chi = 1 Li */
      ChineseCun  = 306, /* 0.1 Chi */
      ChineseFen  = 307, /* 0.01 Chi */
      TangBigFoot = 308, /* 29.6 Centimeters */
      /* Korea , Japan */
      KoreanChi   = 401, /* 35.6 Centimeters */
      /* India Unit */
      YojanaMin   = 501, /* 13 Kilometers */
      Yojana      = 502, /* Yojana average */
      YojanaMax   = 503, /* 16 Kilometers */
      /* Nautical mile */
      Nautical    = 601, /* 1852 Meters */
      Rig         = 602, /* 5556 Meters */
      /* Printing */
      Pica        = 701, /* 12 points */
      Point       = 702, /* 1 point = 127/360 mm about 352.7 um */
      /* Russian  */
      Verst       = 801  /* 1.0668 Kilometer */
    } Unit             ;

  }

  namespace XML
  {
    enum AttributeQuery {
      Success     = 1   ,
      NoAttribute = 2   ,
      WrongType   = 3 } ;

    enum Encoding       {
      Unknown     = 0   ,
      UTF8        = 1   ,
      Legacy      = 2 } ;

    const Encoding DefaultEncoding = Unknown ;

  }

  namespace Scripts {

    enum ScriptTypes  {
      Mapper    = 1   ,
      Forex     = 2   ,
      SQL       = 3   ,
      Version   = 4   ,
      Image     = 5   ,
      Generator = 6   ,
      Document  = 7   ,
      Matching  = 8 } ;

  }

  namespace Sets      {

    enum SetTypes     {
      Unordered = 0   ,
      POSet     = 1   ,
      Preorder  = 2   ,
      Ordered   = 3   ,
      Totally   = 4   ,
      Fuzzy     = 5   ,
      EndOrder  = 6 } ;

  }

  namespace Encoders {

    enum AvEncoder {
      NONE               =   0 ,
      MPEG1VIDEO         =   1 ,
      MPEG2VIDEO         =   2 ,
      H261               =   3 ,
      H263               =   4 ,
      RV10               =   5 ,
      RV20               =   6 ,
      MJPEG              =   7 ,
      MJPEGB             =   8 ,
      LJPEG              =   9 ,
      SP5X               =  10 ,
      JPEGLS             =  11 ,
      MPEG4              =  12 ,
      RAWVIDEO           =  13 ,
      MSMPEG4V1          =  14 ,
      MSMPEG4V2          =  15 ,
      MSMPEG4V3          =  16 ,
      WMV1               =  17 ,
      WMV2               =  18 ,
      H263P              =  19 ,
      H263I              =  20 ,
      FLV1               =  21 ,
      SVQ1               =  22 ,
      SVQ3               =  23 ,
      DVVIDEO            =  24 ,
      HUFFYUV            =  25 ,
      CYUV               =  26 ,
      H264               =  27 ,
      INDEO3             =  28 ,
      VP3                =  29 ,
      THEORA             =  30 ,
      ASV1               =  31 ,
      ASV2               =  32,
      FFV1               =  33 ,
      N4XM               =  34 ,
      VCR1               =  35 ,
      CLJR               =  36 ,
      MDEC               =  37 ,
      ROQ                =  38 ,
      INTERPLAY_VIDEO    =  39 ,
      XAN_WC3            =  40 ,
      XAN_WC4            =  41 ,
      RPZA               =  42 ,
      CINEPAK            =  43 ,
      WS_VQA             =  44 ,
      MSRLE              =  45 ,
      MSVIDEO1           =  46 ,
      IDCIN              =  47 ,
      N8BPS              =  48 ,
      SMC                =  49 ,
      FLIC               =  50 ,
      TRUEMOTION1        =  51 ,
      VMDVIDEO           =  52 ,
      MSZH               =  53 ,
      ZLIB               =  54 ,
      QTRLE              =  55 ,
      TSCC               =  56 ,
      ULTI               =  57 ,
      QDRAW              =  58 ,
      VIXL               =  59 ,
      QPEG               =  60 ,
      PNG                =  61 ,
      PPM                =  62 ,
      PBM                =  63 ,
      PGM                =  64 ,
      PGMYUV             =  65 ,
      PAM                =  66 ,
      FFVHUFF            =  67 ,
      RV30               =  68 ,
      RV40               =  69 ,
      VC1                =  70 ,
      WMV3               =  71 ,
      LOCO               =  72 ,
      WNV1               =  73 ,
      AASC               =  74 ,
      INDEO2             =  75 ,
      FRAPS              =  76 ,
      TRUEMOTION2        =  77 ,
      BMP                =  78 ,
      CSCD               =  79 ,
      MMVIDEO            =  80 ,
      ZMBV               =  81 ,
      AVS                =  82 ,
      SMACKVIDEO         =  83 ,
      NUV                =  84 ,
      KMVC               =  85 ,
      FLASHSV            =  86 ,
      CAVS               =  87 ,
      JPEG2000           =  88 ,
      VMNC               =  89 ,
      VP5                =  90 ,
      VP6                =  91 ,
      VP6F               =  92 ,
      TARGA              =  93 ,
      DSICINVIDEO        =  94 ,
      TIERTEXSEQVIDEO    =  95 ,
      TIFF               =  96 ,
      GIF                =  97 ,
      DXA                =  98 ,
      DNXHD              =  99 ,
      THP                = 100 ,
      SGI                = 101 ,
      C93                = 102 ,
      BETHSOFTVID        = 103 ,
      PTX                = 104 ,
      TXD                = 105 ,
      VP6A               = 106 ,
      AMV                = 107 ,
      VB                 = 108 ,
      PCX                = 109 ,
      SUNRAST            = 110 ,
      INDEO4             = 111 ,
      INDEO5             = 112 ,
      MIMIC              = 113 ,
      RL2                = 114 ,
      ESCAPE124          = 115 ,
      DIRAC              = 116 ,
      BFI                = 117 ,
      CMV                = 118 ,
      MOTIONPIXELS       = 119 ,
      TGV                = 120 ,
      TGQ                = 121 ,
      TQI                = 122 ,
      AURA               = 123 ,
      AURA2              = 124 ,
      V210X              = 125 ,
      TMV                = 126 ,
      V210               = 127 ,
      DPX                = 128 ,
      MAD                = 129 ,
      FRWU               = 130 ,
      FLASHSV2           = 131 ,
      CDGRAPHICS         = 132 ,
      R210               = 133 ,
      ANM                = 134 ,
      BINKVIDEO          = 135 ,
      IFF_ILBM           = 136 ,
      IFF_BYTERUN1       = 137 ,
      KGV1               = 138 ,
      YOP                = 139 ,
      VP8                = 140 ,
      PICTOR             = 141 ,
      ANSI               = 142 ,
      A64_MULTI          = 143 ,
      A64_MULTI5         = 144 ,
      R10K               = 145 ,
      MXPEG              = 146 ,
      LAGARITH           = 147 ,
      PRORES             = 148 ,
      JV                 = 149 ,
      DFA                = 150 ,
      WMV3IMAGE          = 151 ,
      VC1IMAGE           = 152 ,
      UTVIDEO            = 153 ,
      BMV_VIDEO          = 154 ,
      VBLE               = 155 ,
      DXTORY             = 156 ,
      V410               = 157 ,
      XWD                = 158 ,
      CDXL               = 159 ,
      XBM                = 160 ,
      ZEROCODEC          = 161 ,
      MSS1               = 162 ,
      MSA1               = 163 ,
      TSCC2              = 164 ,
      MTS2               = 165 ,
      CLLC               = 166 ,
      MSS2               = 167 ,
      VP9                = 168 ,
      AIC                = 169 ,
      HNM4_VIDEO         = 170 ,
      BRENDER_PIX        = 171 ,
      Y41P               = 172 ,
      ESCAPE130          = 173 ,
      EXR                = 174 ,
      AVRP               = 175 ,
      N012V              = 176 ,
      G2M                = 177 ,
      AVUI               = 178 ,
      AYUV               = 179 ,
      TARGA_Y216         = 180 ,
      V308               = 181 ,
      V408               = 182 ,
      YUV4               = 183 ,
      SANM               = 184 ,
      PAF_VIDEO          = 185 ,
      AVRN               = 186 ,
      CPIA               = 187 ,
      XFACE              = 188 ,
      SGIRLE             = 189 ,
      MVC1               = 190 ,
      MVC2               = 191 ,
      SNOW               = 192 ,
      WEBP               = 193 ,
      SMVJPEG            = 194 ,
      HEVC               = 195 ,
      FIRST_AUDIO        = 196 ,
      PCM_S16LE          = 197 ,
      PCM_S16BE          = 198 ,
      PCM_U16LE          = 199 ,
      PCM_U16BE          = 200 ,
      PCM_S8             = 201 ,
      PCM_U8             = 202 ,
      PCM_MULAW          = 203 ,
      PCM_ALAW           = 204 ,
      PCM_S32LE          = 205 ,
      PCM_S32BE          = 206 ,
      PCM_U32LE          = 207 ,
      PCM_U32BE          = 208 ,
      PCM_S24LE          = 209 ,
      PCM_S24BE          = 210 ,
      PCM_U24LE          = 211 ,
      PCM_U24BE          = 212 ,
      PCM_S24DAUD        = 213 ,
      PCM_ZORK           = 214 ,
      PCM_S16LE_PLANAR   = 215 ,
      PCM_DVD            = 216 ,
      PCM_F32BE          = 217 ,
      PCM_F32LE          = 218 ,
      PCM_F64BE          = 219 ,
      PCM_F64LE          = 220 ,
      PCM_BLURAY         = 221 ,
      PCM_LXF            = 222 ,
      S302M              = 223 ,
      PCM_S8_PLANAR      = 224 ,
      PCM_S24LE_PLANAR   = 225 ,
      PCM_S32LE_PLANAR   = 226 ,
      PCM_S16BE_PLANAR   = 227 ,
      ADPCM_IMA_QT       = 228 ,
      ADPCM_IMA_WAV      = 229 ,
      ADPCM_IMA_DK3      = 230 ,
      ADPCM_IMA_DK4      = 231 ,
      ADPCM_IMA_WS       = 232 ,
      ADPCM_IMA_SMJPEG   = 233 ,
      ADPCM_MS           = 234 ,
      ADPCM_4XM          = 235 ,
      ADPCM_XA           = 236 ,
      ADPCM_ADX          = 237 ,
      ADPCM_EA           = 238 ,
      ADPCM_G726         = 239 ,
      ADPCM_CT           = 240 ,
      ADPCM_SWF          = 241 ,
      ADPCM_YAMAHA       = 242 ,
      ADPCM_SBPRO_4      = 243 ,
      ADPCM_SBPRO_3      = 244 ,
      ADPCM_SBPRO_2      = 245 ,
      ADPCM_THP          = 246 ,
      ADPCM_IMA_AMV      = 247 ,
      ADPCM_EA_R1        = 248 ,
      ADPCM_EA_R3        = 249 ,
      ADPCM_EA_R2        = 250 ,
      ADPCM_IMA_EA_SEAD  = 251 ,
      ADPCM_IMA_EA_EACS  = 252 ,
      ADPCM_EA_XAS       = 253 ,
      ADPCM_EA_MAXIS_XA  = 254 ,
      ADPCM_IMA_ISS      = 255 ,
      ADPCM_G722         = 256 ,
      ADPCM_IMA_APC      = 257 ,
      VIMA               = 258 ,
      ADPCM_AFC          = 259 ,
      ADPCM_IMA_OKI      = 260 ,
      ADPCM_DTK          = 261 ,
      ADPCM_IMA_RAD      = 262 ,
      ADPCM_G726LE       = 263 ,
      AMR_NB             = 264 ,
      AMR_WB             = 265 ,
      RA_144             = 266 ,
      RA_288             = 267 ,
      ROQ_DPCM           = 268 ,
      INTERPLAY_DPCM     = 269 ,
      XAN_DPCM           = 270 ,
      SOL_DPCM           = 271 ,
      MP2                = 272 ,
      MP3                = 273 ,
      AAC                = 274 ,
      AC3                = 275 ,
      DTS                = 276 ,
      VORBIS             = 277 ,
      DVAUDIO            = 278 ,
      WMAV1              = 279 ,
      WMAV2              = 280 ,
      MACE3              = 281 ,
      MACE6              = 282 ,
      VMDAUDIO           = 283 ,
      FLAC               = 284 ,
      MP3ADU             = 285 ,
      MP3ON4             = 286 ,
      SHORTEN            = 287 ,
      ALAC               = 288 ,
      WESTWOOD_SND1      = 289 ,
      GSM                = 290 ,
      QDM2               = 291 ,
      COOK               = 292 ,
      TRUESPEECH         = 293 ,
      TTA                = 294 ,
      SMACKAUDIO         = 295 ,
      QCELP              = 296 ,
      WAVPACK            = 297 ,
      DSICINAUDIO        = 298 ,
      IMC                = 299 ,
      MUSEPACK7          = 300 ,
      MLP                = 301 ,
      GSM_MS             = 302 ,
      ATRAC3             = 303 ,
      APE                = 304 ,
      NELLYMOSER         = 305 ,
      MUSEPACK8          = 306 ,
      SPEEX              = 307 ,
      WMAVOICE           = 308 ,
      WMAPRO             = 309 ,
      WMALOSSLESS        = 310 ,
      ATRAC3P            = 311 ,
      EAC3               = 312 ,
      SIPR               = 313 ,
      MP1                = 314 ,
      TWINVQ             = 315 ,
      TRUEHD             = 316 ,
      MP4ALS             = 317 ,
      ATRAC1             = 318 ,
      BINKAUDIO_RDFT     = 319 ,
      BINKAUDIO_DCT      = 320 ,
      AAC_LATM           = 321 ,
      QDMC               = 322 ,
      CELT               = 323 ,
      G723_1             = 324 ,
      G729               = 325 ,
      N8SVX_EXP          = 326 ,
      N8SVX_FIB          = 327 ,
      BMV_AUDIO          = 328 ,
      RALF               = 329 ,
      IAC                = 330 ,
      ILBC               = 331 ,
      METASOUND          = 332 ,
      FFWAVESYNTH        = 333 ,
      SONIC              = 334 ,
      SONIC_LS           = 335 ,
      PAF_AUDIO          = 336 ,
      OPUS               = 337 ,
      TAK                = 338 ,
      EVRC               = 339 ,
      SMV                = 340 ,
      FIRST_SUBTITLE     = 341 ,
      DVD_SUBTITLE       = 342 ,
      DVB_SUBTITLE       = 343 ,
      TEXT               = 344 ,
      XSUB               = 345 ,
      SSA                = 346 ,
      MOV_TEXT           = 347 ,
      HDMV_PGS_SUBTITLE  = 348 ,
      DVB_TELETEXT       = 349 ,
      SRT                = 350 ,
      MICRODVD           = 351 ,
      EIA_608            = 352 ,
      JACOSUB            = 353 ,
      SAMI               = 354 ,
      REALTEXT           = 355 ,
      SUBVIEWER1         = 356 ,
      SUBVIEWER          = 357 ,
      SUBRIP             = 358 ,
      WEBVTT             = 359 ,
      MPL2               = 360 ,
      VPLAYER            = 361 ,
      PJS                = 362 ,
      ASS                = 363 ,
      FIRST_UNKNOWN      = 364 ,
      TTF                = 365 ,
      BINTEXT            = 366 ,
      XBIN               = 367 ,
      IDF                = 368 ,
      OTF                = 369 ,
      SMPTE_KLV          = 370 ,
      DVD_NAV            = 371 ,
      END                = 372
    };

  }

  namespace Speak {

    typedef enum        {
      ToneAdjust = 1000 ,
      Peaks      =    9 ,
      Markers    =    8 }
      SpeakParaments    ;

    typedef enum        {
      Cascade = 1       ,
      All     = 2       }
      SynthesisModel    ;

    typedef enum        {
      Impulsive = 1     ,
      Natural   = 2     ,
      Sampled   = 3     }
      Glottals          ;

    typedef enum      {
      PAUSE      =  0 ,
      STRESS     =  1 ,
      VOWEL      =  2 ,
      LIQUID     =  3 ,
      STOP       =  4 ,
      VSTOP      =  5 ,
      FRICATIVE  =  6 ,
      VFRICATIVE =  7 ,
      NASAL      =  8 ,
      VIRTUAL    =  9 ,
      DELETED    = 14 ,
      INVALID    = 15 }
      PhonemeTypes    ;

    typedef enum               {
      ARTICULATION = 0xf0000   ,
      WAVE         = 0x01      ,
      UNSTRESSED   = 0x02      ,
      FORTIS       = 0x08      ,
      VOICED       = 0x10      ,
      SIBILANT     = 0x20      ,
      NOLINK       = 0x40      ,
      TRILL        = 0x80      ,
      VOWEL2       = 0x100     , // liquid that is considered a vowel
      PALATAL      = 0x200     ,
      SINGLE_INSTN = 0x1000    , // this phoneme has a single instruction program, with an implicit Return
      BRKAFTER     = 0x4000    , // [*] add a post-pause
      NONSYLLABIC  = 0x100000  , // don't count this vowel as a syllable when finding the stress position
      LONG         = 0x200000  ,
      LENGTHENSTOP = 0x400000  , // make the pre-pause slightly longer
      RHOTIC       = 0x800000  , // bit 23
      NOPAUSE      = 0x1000000 ,
      PREVOICE     = 0x2000000 }
      PhonemeProperties        ; // for voiced stops

    typedef enum         {
      FLAG1 = 0x10000000 ,
      FLAG2 = 0x20000000 ,
      FLAG3 = 0x40000000 ,
      LOCAL = 0x80000000 } // used during compilation
      PhonemeFlags       ;

    typedef enum         {
      PcControl     =  1 ,
      PcStressU     =  2 ,
      PcStressD     =  3 ,
      PcStress2     =  4 ,
      PcStress3     =  5 ,
      PcStressP     =  6 ,
      PcStressP2    =  7 ,   // priority stress within a word
      PcStressPrev  =  8 ,
      PcPause       =  9 ,
      PcPauseShort  = 10 ,
      PcPauseNoLink = 11 ,
      PcLengthen    = 12 ,
      PcSchwa       = 13 ,
      PcSchwaShort  = 14 ,
      PcEndWord     = 15 ,
      PcDefaultTone = 17 ,
      PcCapital     = 18 ,
      PcGlottalStop = 19 ,
      PcSyllabic    = 20 ,
      PcSwitch      = 21 ,
      PcX1          = 22 ,     // a language specific action
      PcPauseVShort = 23 ,
      PcPauseLong   = 24 ,
      PcReducedT    = 25 ,
      PcStressTonic = 26 ,
      PcPauseClause = 27 ,
      PcVowelTypes  = 28 }
      PhonemeCodes       ; // 28 to 33

    typedef enum             {
      MnemonicRules     =  1 ,
      MnemonicFlags     =  2 ,
      VoiceGenders      =  3 ,
      OptionsTable      =  4 ,
      KeywordTable      =  5 ,
      SsmlTags          =  6 ,
      MnemonicGender    =  7 ,
      MnemonicVolume    =  8 ,
      MnemonicRate      =  9 ,
      MnemonicPitch     = 10 ,
      MnemonicRange     = 11 ,
      MnemonicKeys      = 12 ,
      MnemonicPunct     = 13 ,
      MnemonicCapitals  = 14 ,
      MnemonicInterpret = 15 ,
      SayAsFormat       = 16 ,
      MnemonicBreak     = 17 ,
      MnemonicEmphasis  = 18 }
      SynthesisTables        ;

    typedef enum           {
      RussianAll       = 0 ,
      RussianCapital   = 1 ,
      RussianMinuscule = 2 }
      RussianAlphabets     ;

  }

  namespace Cpp
  {

    enum CppObjects         {
      Define      =       1 ,
      Include     =       2 ,
      Enumeration =       3 ,
      Namespace   =       4 ,
      Typedef     =       5 ,
      Union       =       6 ,
      Structure   =       7 ,
      Class       =       8 ,
      Template    =       9 ,
      Function    =      10 ,
      Variable    =      11 ,
      Statement   =      12 ,
      Macro       =      13 ,
      Bits        =      14 ,
      Scope       =      15 ,
      Combine     = 0x10000
    }                       ;

    enum CppState             {
      Empty             =   0 ,
      Perfect           =   1 ,
      Optimize          =   2 ,
      Revise            =   3 ,
      Options           =   4 ,
      Suggestion        =   5 ,
      Affected          =   6 ,
      Duplicated        =   7 ,
      Warning           =   8 ,
      Abuse             =   9 ,
      Dangerous         =  10 ,
      Improvements      =  11 ,
      Ignore            =  12 ,
      Incorrect         =  13 ,
      BracketError      =  14 ,
      SyntaxError       =  15 ,
      StructureError    =  16 ,
      ProcedureError    =  17 ,
      DeclareError      =  18 ,
      DefineError       =  19 ,
      PreprocessorError =  20 ,
      CastingError      =  21 ,
      Fatal             =  22 ,
      Crash             =  23
    }                         ;

    typedef enum      {
      Void       =  0 ,
      Char       =  1 ,
      Byte       =  2 ,
      Short      =  3 ,
      UShort     =  4 ,
      Integer    =  5 ,
      UInt       =  6 ,
      LongLong   =  7 ,
      ULongLong  =  8 ,
      Float      =  9 ,
      Double     = 10 ,
      LDouble    = 11 ,
      VLong      = 12 ,
      VDouble    = 13 ,
      Rational   = 14 ,
      VComplex   = 15 ,
      VPrecision = 16 ,
      pADIC      = 17 ,
      Pointer    = 18 ,
      Symbolic   = 19 } // For Algebra => Variable
      ValueTypes      ;

    enum BlobTypes      {
      Undecided  =    0 ,
      // Between 1 - 11 are C++ ValueTypes
      Blob       =  101 ,
      StringBlob =  102 , // QString::fromUtf8(StringBlob) => QString
      Ann        =  103 , // Artificial Neural Network
      EndOfBlobs =  104
    }                   ;

  }

  namespace PDL
  {

    enum PdlObjects           {
      StandardType = 10000000 ,
      DataType     = 10000001 ,
      Syntax       = 10000002 ,
      Closure      = 10000003
    }                         ;

  }

  namespace Scene
  {

    enum SceneNodeType {
      Abstract  = 0    ,
      Root      = 1    ,
      Transform = 2    ,
      Camera    = 3    ,
      Light     = 4    ,
      Object    = 5    ,
      Universe  = 6    ,
      Hierarchy = 7    ,
      Texture   = 8
    }                  ;

  }

  namespace Blood
  {

    enum BloodRelation  {
      Unknown       = 0 ,
      Affinity      = 1 ,
      Consanguinity = 2 ,
      Foster        = 3 ,
      Society       = 4 ,
      Artificial    = 5 ,
      Irrelevant    = 6
    }                   ;

  }

  namespace Forex
  {

    enum Periods    { // Tick Time Period
      Ticks =     0 , // Real time quote
      M1    =     1 , //  1 minute
      M5    =     5 , //  5 minutes
      M15   =    15 , // 15 minutes
      M30   =    30 , // 30 minutes
      H1    =    60 , //  1 hour
      H4    =   240 , //  4 hours
      D1    =  1440 , //  1 day
      W1    = 10080 , //  1 week
      MN1   = 43200   //  1 month
    }               ;

    enum Orders     { // Order Types
      Buy       = 0 , // Long
      Sell      = 1 , // Short
      BuyLimit  = 2 , // Buy limit
      SellLimit = 3 , // Sell limit
      BuyStop   = 4 , // Buy stop
      SellStop  = 5 , // Sell stop
      Balance   = 6 , // Balance
      Credit    = 7   // Credit
    }               ;

    enum ChartTypes      {
      TickBar        = 0 ,
      BarChart       = 1 ,
      Candlesticks   = 2 ,
      LineChart      = 3 ,
      ElderImpulse   = 4 ,
      EquiVolume     = 5 ,
      HeikinAshi     = 6 ,
      KagiChart      = 7 ,
      RenkoChart     = 8 ,
      ThreeLineBreak = 9
    }                    ;

    enum Trends            { // Trend types
      None             = 0 , // No trend
      Long             = 1 , // Long trend
      Short            = 2 , // Short trend
      LongOscillation  = 3 , // Long side oscillation
      ShortOscillation = 4 , // Short side oscillation
      LongReverse      = 5 , // Long side Reversal
      ShortReverse     = 6 , // Short side Reversal
      Oscillation      = 7   // Oscillation trend
    }                      ;

    enum Transactions   { // Switch Order Management Type , internal use only
      NoTransaction = 0 , // No update
      Update        = 1 , // At update
      New           = 2 , // New order
      Close         = 3   // Finish update
    }                   ;

    enum Analysis { // Trend analysis
      NoTrend = 0   // No trend
    }             ;

    enum Reactions   { // Order Reactions
      Wait      = 0 , // Order rescue mission under waiting
      Warn      = 1 , // Order enter the warning zone
      Speculate = 2 , // Order takes too much of time to gain profit, speculate it and find proper time to gain minimal profit
      Hedge     = 3 , // Order success, rescue mission launches
      Stoploss  = 4 , // Order failure, rescue mission launches
      Anew      = 5 , // Order anew, when it takes too much of time or enter warning zone, and regain the possible gain minial profit position
      Final     = 6 , // Order success, no rescue mission is required
      Custom    = 7 , // Custom order
      Strategy  = 8 , // Order Strategy
      Track     = 9   // Track Profit
    }               ;

    enum Hedge    { // Hedge Status
      Single  = 0 , // Waiting for another side of hedge order
      Ready   = 1 , // Hedge pair waiting state
      Resolve = 2 , // Hedge pair resolving state
      Rescue  = 3 , // Hedge pair rescue state
      Error   = 9
    }             ;

    enum Tactics  { // Group Tactics
      Watch   = 0 , // Wait and see
      Scalper = 1 , // Scalper tactics
      Profit  = 2   // Add new order on current profitable order
    }             ;

    enum Assets    { // Finance asset status
      Freeze   = 0 , // you did not use your money at all
      Bankrupt = 1 , // you had already bankrupt, capital under 5 dollars
      Light    = 2 , // lightly use your money, free margin above 90%
      Properly = 3 , // you use your money properly, free margin above 60%
      Pressure = 4 , // your money usage is under pressure , free margin under 60%
      Gambler  = 5 , // you are a gambler, free margin under 20%
      Overante = 6   // you had over raise your ante , too many orders, free margin under 10%
    }              ;

    enum History    { // Order history analysis
      NewOrder  = 0 , // Order history analysis , new order , do nothing please
      Idle      = 1 , // Idle order , the quotes stick , no profit and no loss
      Correct   = 2 , // Correct order, in the zone, profitable
      Incorrect = 3 , // Incorrect order, arrive deficit zone
      Recover   = 4   // Incorrect order but the price recover, the best suggestion is to take profit whenever it gains a little profit
    }               ;

    enum QuoteBars   { // Quote bar type
      NoBar   =    0 , // Not yet calculated
      Flat    =    1 , // Open = Close and Open != High and Close != Low
      Top     =    2 , // Open = Close and Open  = High and Close  = High
      Bottom  =    3 , // Open = Close and Open  = Low  and Close  = Low
      BidSide =    4 , // Open > Close and Close = Low
      BidBack =    5 , // Open > Close and Close > Low
      AskSide =    6 , // Open < Close and Open  = High
      AskBack =    7 , // Open < Close and Open  < High
      Others  = 1001   // Other conditions
    }                ;

    enum Curves    { // Trend curve type
      NoCurve  = 0 , // No analysis
      Bestline = 1 , // Best line trend
      Parabola = 2   // Parabola trend
    }              ;

    enum Weekly  { // Allowed weekly trade
      Forbid = 0 , // No trade allow
      Ask    = 1 , // Allow long side
      Bid    = 2   // Allow short side
    }            ;

    enum Volume   { // Volume Ratio Level
      Low     = 0 , // Volume[n] < Volume Stable (0.75)
      Stable  = 1 , // Volume[n] [0.75-1.10]
      Big     = 2 , // Volume[n] [1.10-1.50]
      Great   = 3 , // Volume[n] [1.50-1.80]
      Large   = 4 , // Volume[n] [1.80-2.50]
      Extreme = 5   // Volume[n] > 2.50
    }             ;

    enum Actions          { // Default analysis actions
      Zone        =  1001 , // Price zone analysis
      Line        =  1002 , // Best line analysis
      Curve       =  1003 , // Parabola analysis
      Resistance  =  1004 , // Volume resistance pressure analysis
      Regression  =  1005 , // Regression indicators analysis
      Alligator   =  1006 , // Alligator indicator analysis
      BullBear    =  1007 , // Bear/Bull indicators analysis
      ForceIndex  =  1008 , // Force Index indicators analysis , Force Index
      CCI         =  1009 , // Commodity Channel Index indicators analysis
      Bollinger   =  1010 , // Bollinger Bands indicators analysis
      ADX         =  1011 , // Average Directional Index
      MFI         =  1012 , // Money Flow Index
      RSI         =  1013 , // RSI analysis
      MACD        =  1014 , // MACD analysis
      Stochastics =  1015 , // Stochastics analysis
      OBV         =  1016 , // OBV analysis
      SAR         =  1017 , // Parabolic SAR analysis
      SMA         =  1018 , // Simple Moving Average analysis
      EMA         =  1019 , // Exponential Moving Average analysis
      AD          =  1020 , // Exponential Moving Average analysis
      PivotPoints =  1021 , // Pivot points analysis
      DeMarker    =  1022 , // DeMarker analysis
      ZigZag      =  1023 , // ZigZag analysis
      Pattern     =  1901 , // Patterns analysis
      Gaps        =  1902 , // Gaps analysis
      Direction   =  1999   // Direction analysis
    }                     ;

    enum ChartAnalysis        { // Chart zone analysis
      Queue              =  0 , // Not yet analysis
      Small              =  1 , // 15 points in one hour, 25 points in two hours
      Slow               =  2 , // 35 points in one hour, occupy 90% within four hours
      Trend              =  3 , // fluctuation is too big, 140 points in one day, 72 points in four hours
      Tornado            =  4 , // a great wave
      Tsunami            =  5 , // a very powerful wave
      Normal             = 11 , // Normal trend, fluctuation below 72 points in one day
      Common             = 21 , // Common trend, fluctuation below 55 points in eight hours
      Compact            = 22 , // Compact trend, 15-35 points in one hour, occupy 60% within two hours
      CompactOscillation = 23 , // compact oscillation, 15-35 points in one hour, above 55 points in two hours, below 72 points in eight hours
      CompactTrend       = 24 , // compact trend, 15-35 points in one hour, above 55 points in two hours, between 72-120 points in eight hours
      RestWork           = 29 , // Not yet identify
      RecentTrend        = 41 , // fluctuation is too big, 140 points in one day, 55 points recently occurs
      Narrow             = 99   // Very narrow zone, normally below 10-15 points
    }                         ;

    enum Gaps         { // Gap types
      Tie        =  0 , // No gap
      Routine    = 11 , // Common gap
      BreakAway  = 21 , // Break away gap
      RunAway    = 31 , // Run away gap
      Exhaustion = 41   // Exhaustion gap
    }                 ;

    enum Patterns          { // Chart Pattern types
      Chaos          =   0 ,
      Unknown        =   1 ,
      BottomW        = 100 ,
      WT01           = 101 ,
      WT02           = 102 ,
      WT03           = 103 ,
      WT04           = 104 ,
      WT05           = 105 ,
      WT06           = 106 ,
      WT07           = 107 ,
      WT08           = 108 ,
      WT09           = 109 ,
      WT10           = 110 ,
      WT11           = 111 ,
      WT12           = 112 ,
      WT13           = 113 ,
      WT14           = 114 ,
      WT15           = 115 ,
      WT16           = 116 ,
      TopM           = 120 ,
      MT01           = 121 ,
      MT02           = 122 ,
      MT03           = 123 ,
      MT04           = 124 ,
      MT05           = 125 ,
      MT06           = 126 ,
      MT07           = 127 ,
      MT08           = 128 ,
      MT09           = 129 ,
      MT10           = 130 ,
      MT11           = 131 ,
      MT12           = 132 ,
      MT13           = 133 ,
      MT14           = 134 ,
      MT15           = 135 ,
      MT16           = 136 ,
      BollingerWalks = 141 ,
      Gartley        = 161 ,
      Butterfly      = 181
    }                      ;

    enum Pivots             { // Pivot Point Position
      Nought          =   0 ,
      Standard        =   1 ,
      Fibonacci       =   2 ,
      DeMark          =   3 ,
      StandardAtPivot =  11 ,
      DeMarkAtPivot   =  12 ,
      Center          =  13 ,
      StandardAtS1    = 101 ,
      StandardAtR1    = 102 ,
      StandardAtS2    = 103 ,
      StandardAtR2    = 104 ,
      StandardZ1U     = 111 , // R1-Pivot
      StandardZ1L     = 112 , // Pivot-S1
      StandardZ2U     = 121 , // R2-R1
      StandardZ2L     = 122 , // S1-S2
      StandardR2U     = 131 , // R2-
      StandardS2L     = 132 , // S2-
      FibonacciAtS1   = 201 ,
      FibonacciAtR1   = 202 ,
      FibonacciAtS2   = 203 ,
      FibonacciAtR2   = 204 ,
      FibonacciAtS3   = 205 ,
      FibonacciAtR3   = 206 ,
      FibonacciZ1U    = 211 ,
      FibonacciZ1L    = 212 ,
      FibonacciZ2U    = 221 ,
      FibonacciZ2L    = 222 ,
      FibonacciZ3U    = 231 ,
      FibonacciZ3L    = 232 ,
      FibonacciR3U    = 241 ,
      FibonacciS3L    = 242 ,
      DeMarkAtS1      = 301 ,
      DeMarkAtR1      = 302 ,
      DeMarkZ1U       = 311 ,
      DeMarkZ1L       = 312 ,
      DeMarkR2U       = 321 ,
      DeMarkS2L       = 322
    }                       ;

  }

  // Artificial Neural Network
  namespace Ann
  {

    /**************************************************************************\
     *                                                                        *
     * The activation functions used for the neurons during training. The     *
     * activation functions can either be defined for a group of neurons by   *
     * <fann_set_activation_function_hidden> and                              *
     * <fann_set_activation_function_output> or it can be defined for a       *
     * single neuron by <fann_set_activation_function>.                       *
     *                                                                        *
     * The steepness of an activation function is defined in the same way by  *
     * <fann_set_activation_steepness_hidden>,                                *
     * <fann_set_activation_steepness_output> and                             *
     * <fann_set_activation_steepness>.                                       *
     *                                                                        *
     * The functions are described with functions where:                      *
     * x is the input to the activation function,                             *
     * y is the output,                                                       *
     * s is the steepness and                                                 *
     * d is the derivation.                                                   *
     *                                                                        *
     * Linear - Linear activation function.                                   *
     *  * span: -inf < y < inf                                                *
     *  * y = x*s, d = 1*s                                                    *
     *  * Can NOT be used in fixed point.                                     *
     *                                                                        *
     * Threshold - Threshold activation function.                             *
     *  * x < 0 -> y = 0, x >= 0 -> y = 1                                     *
     *  * Can NOT be used during training.                                    *
     *                                                                        *
     * Symmetric Threshold - Threshold activation function.                   *
     *  * x < 0 -> y = 0, x >= 0 -> y = 1                                     *
     *  * Can NOT be used during training.                                    *
     *                                                                        *
     * Sigmoid - Sigmoid activation function.                                 *
     *  * One of the most used activation functions.                          *
     *  * span: 0 < y < 1                                                     *
     *  * y = 1/(1 + exp(-2*s*x))                                             *
     *  * d = 2*s*y*(1 - y)                                                   *
     *                                                                        *
     * Stepwise Sigmoid - Stepwise linear approximation to sigmoid.           *
     *  * Faster than sigmoid but a bit less precise.                         *
     *                                                                        *
     * Symmetric Sigmoid - Symmetric sigmoid activation function, aka. tanh.  *
     *  * One of the most used activation functions.                          *
     *  * span: -1 < y < 1                                                    *
     *  * y = tanh(s*x) = 2/(1 + exp(-2*s*x)) - 1                             *
     *  * d = s*(1-(y*y))                                                     *
     *                                                                        *
     * Symmetric Stepwise Sigmoid - Stepwise linear approximation to          *
     *                              symmetric sigmoid.                        *
     *  * Faster than symmetric sigmoid but a bit less precise.               *
     *                                                                        *
     * Gaussian - Gaussian activation function.                               *
     *  * 0 when x = -inf, 1 when x = 0 and 0 when x = inf                    *
     *  * span: 0 < y < 1                                                     *
     *  * y = exp(-x*s*x*s)                                                   *
     *  * d = -2*x*s*y*s                                                      *
     *                                                                        *
     * Symmetric gaussian - Symmetric gaussian activation function.           *
     *  * -1 when x = -inf, 1 when x = 0 and 0 when x = inf                   *
     *  * span: -1 < y < 1                                                    *
     *  * y = exp(-x*s*x*s)*2-1                                               *
     *  * d = -2*x*s*(y+1)*s                                                  *
     *                                                                        *
     * Elliot - Fast (sigmoid like) activation function                       *
     *          defined by David Elliott                                      *
     *  * span: 0 < y < 1                                                     *
     *  * y = ((x*s) / 2) / (1 + |x*s|) + 0.5                                 *
     *  * d = s*1/(2*(1+|x*s|)*(1+|x*s|))                                     *
     *                                                                        *
     * Symmetric Elliot - Fast (symmetric sigmoid like) activation function   *
     *  * span: -1 < y < 1                                                    *
     *  * y = (x*s) / (1 + |x*s|)                                             *
     *  * d = s*1/((1+|x*s|)*(1+|x*s|))                                       *
     *                                                                        *
     * Linear Piece - Bounded linear activation function.                     *
     *  * span: 0 <= y <= 1                                                   *
     *  * y = x*s, d = 1*s                                                    *
     *                                                                        *
     * Symmetric Linear Piece - Bounded linear activation function.           *
     *  * span: -1 <= y <= 1                                                  *
     *  * y = x*s, d = 1*s                                                    *
     *                                                                        *
     * Symmetric Sine - Periodical sinus activation function.                 *
     *  * span: -1 <= y <= 1                                                  *
     *  * y = sin(x*s)                                                        *
     *  * d = s*cos(x*s)                                                      *
     *                                                                        *
     * Symmetric Cosine - Periodical cosinus activation function.             *
     *  * span: -1 <= y <= 1                                                  *
     *  * y = cos(x*s)                                                        *
     *  * d = s*-sin(x*s)                                                     *
     *                                                                        *
     * Sine - Periodical sinus activation function.                           *
     *  * span: 0 <= y <= 1                                                   *
     *  * y = sin(x*s)/2+0.5                                                  *
     *  * d = s*cos(x*s)/2                                                    *
     *                                                                        *
     * Cosine - Periodical cosinus activation function.                       *
     *  * span: 0 <= y <= 1                                                   *
     *  * y = cos(x*s)/2+0.5                                                  *
     *  * d = s*-sin(x*s)/2                                                   *
     *                                                                        *
    \**************************************************************************/

    enum Functions                  {
      Nothing                  =  0 ,
      Linear                   =  1 ,
      Threshold                =  2 ,
      SymmetricThreshold       =  3 ,
      Sigmoid                  =  4 ,
      StepwiseSigmoid          =  5 ,
      SymmetricSigmoid         =  6 ,
      SymmetricStepwiseSigmoid =  7 ,
      Gaussian                 =  8 ,
      SymmetricGaussian        =  9 ,
      StepwiseGaussian         = 10 ,
      Elliot                   = 11 ,
      SymmetricElliot          = 12 ,
      LinearPiece              = 13 ,
      SymmetricLinearPiece     = 14 ,
      Sine                     = 15 ,
      SymmetricSine            = 16 ,
      Cosine                   = 17 ,
      SymmetricCosine          = 18
    }                               ;

    enum Errors                  {
      NoError               =  0 ,
      CannotOpenConfigR     =  1 ,
      CannotOpenConfigW     =  2 ,
      WrongConfigVersion    =  3 ,
      CannotReadConfig      =  4 ,
      CannotReadNeuron      =  5 ,
      CannotReadConnections =  6 ,
      WrongNumConnections   =  7 ,
      CannotOpenTDW         =  8 ,
      CannotOpenTDR         =  9 ,
      CannotOpenTD          = 10 ,
      CannotAllocateMemory  = 11 ,
      CannotTrainActivation = 12 ,
      CannotUseActivation   = 13 ,
      TrainDataMismatch     = 14 ,
      CannotUseTrainALG     = 15 ,
      TrainDataSubset       = 16 ,
      IndexOutOfBound       = 17 ,
      ScaleNotPresent       = 18 ,
      InputNoMatch          = 19 ,
      OutputNoMatch         = 20
    }                            ;

    enum NetworkTypes {
      Layer    = 0    ,
      Shortcut = 1
    }                 ;

    enum Trains       {
      Incremental = 0 ,
      Batch       = 1 ,
      RProp       = 2 ,
      QuickProp   = 3 ,
      SarProp     = 4
    }                 ;

    enum ErrorFunctions {
      ErrorLinear = 0   ,
      ErrorTanh   = 1
    }                   ;

    enum StopFunctions {
      MSE = 0          ,
      BIT = 1
    }                  ;

  }

  namespace Fuzzy
  {

    enum FuzzyOperatorIds       {
      IdMaximum           = 101 ,
      IdAlgebraicSum      = 102 ,
      IdBoundedSum        = 103 ,
      IdNormalizedSum     = 104 ,
      IdDrasticSum        = 105 ,
      IdEinsteinSum       = 106 ,
      IdHamacherSum       = 107 ,
      IdMinimum           = 201 ,
      IdAlgebraicProduct  = 202 ,
      IdBoundedDifference = 203 ,
      IdDrasticProduct    = 204 ,
      IdEinsteinProduct   = 205 ,
      IdHamacherProduct   = 206
    }                           ;

  }

  namespace CLF
  {

    // Totally 48 Chinese glyph combinational types
    // For some additional functions, full implementation is 50 types
    enum Types               {
      MeaningLess       =  0 , // We do not have this type actually
      Conformation      =  1 , // Elementary grapheme , only one grapheme
      Complex           =  2 , // In a simplified version , we do not disassemble complex structure
      H11               =  3 , // A B       : Horizontal arrangement 1 : 1
      H11E              =  4 , // A A       : Horizontal arrangement 1 : 1 , but only A
      H12               =  5 , // A B       : Horizontal arrangement 1 : 2
      H21               =  6 , // A B       : Horizontal arrangement 2 : 1
      H3                =  7 , // A B C     : Horizontal arrangement 1 : 1 : 1
      H3C               =  8 , // A B A     : Horizontal arrangement 1 : 1 : 1 , but only A,B
      V11               =  9 , // A B       : Vertical arrangement 1 : 1
      V11E              = 10 , // A A       : Vertical arrangement 1 : 1 , but only A
      V12               = 11 , // A B       : Vertical arrangement 1 : 2
      V21               = 12 , // A B       : Vertical arrangement 2 : 1
      V3                = 13 , // A B C     : Vertical arrangement 1 : 1 : 1
      V3C               = 14 , // A B A     : Vertical arrangement 1 : 1 : 1 , but only A,B
      Hat               = 15 , // A B       : B Wearing a hat A
      Siege             = 16 , // A B       : A siege B
      Triplet           = 17 , // A B C     : Triangle arrangement
      TriSymmetry       = 18 , // A A A     : Triangle arrangement , but only A
      Quadlet           = 19 , // A B C D   : Symmertic quad graphemes
      QuadSymmetry      = 20 , // A A A A   : Symmertic quad graphemes , but only A
      Five              = 21 , // A B C D E : Quadlet with additional center grapheme
      FiveSymmetry      = 22 , // A A A A B : Quadlet with additional center grapheme , but only A,B
      Chair             = 23 , // A B       : L shape , Body B sits on A
      Sofa              = 24 , // A B       : Reverse L shape , Body B sits on A
      Body              = 25 , // A B       : Body B wearing a coat A
      Sheet             = 26 , // A B       : Reverse Body shape
      Door              = 27 , // A B       : Notch to down
      Concave           = 28 , // A B       : Notch to up
      Giant             = 29 , // A B       : Notch to right
      Teeth             = 30 , // A B       : Notch to left
      Mountain          = 31 , // A B C     : B and C hide inside Mountain A
      MountainSymmetry  = 32 , // A B B     : B and B hide inside Mountain A
      Rain              = 33 , // A B C     : Reverse Mountain
      RainSymmetry      = 34 , // A B B     : Reverse Mountain , but only A,B
      EUD               = 35 , // A B C     : E shape
      EudSymmetry       = 36 , // A B B     : E shape , but only A,B
      REUD              = 37 , // A B C     : Reverse E shape
      ReudSymmetry      = 38 , // A B B     : Reverse E shape , but only A,B
      TShape            = 39 , // A B C     : T shape
      TShapeSymmetry    = 40 , // A B B     : T shape , but only A,B
      Thumbtack         = 41 , // A B C     : Reverse T shape
      ThumbtackSymmetry = 42 , // A B B     : Reverse T shape , but only A,B
      RightT            = 43 , // A B C     : Right T
      RightTSymmetry    = 44 , // A B B     : Right T , but only A,B
      LeftT             = 45 , // A B C     : Left T
      LeftTSymmetry     = 46 , // A B B     : Left T , but only A,B
      Worker            = 47 , // A B C     : Work shape
      WorkerSymmetry    = 48 , // A B B     : Work shape , but only A,B
      HShape            = 49 , // A B C     : Rotated Work shape
      HShapeSymmetry    = 50   // A B B     : Rotated Work shape , but only A,B
    }                        ;

    // H11              => +-------+-------+
    //                     |       |       |
    //                     |       |       |
    //                     |       |       |
    //                     |       |       |
    //                     |       |       |
    //                     |       |       |
    //                     |       |       |
    //                     +-------+-------+
    //
    // H12              => +----+----------+
    //                     |    |          |
    //                     |    |          |
    //                     |    |          |
    //                     |    |          |
    //                     |    |          |
    //                     |    |          |
    //                     |    |          |
    //                     +----+----------+
    //
    // H21              => +----------+----+
    //                     |          |    |
    //                     |          |    |
    //                     |          |    |
    //                     |          |    |
    //                     |          |    |
    //                     |          |    |
    //                     |          |    |
    //                     +----------+----+
    //
    // H3               => +----+-----+----+
    //                     |    |     |    |
    //                     |    |     |    |
    //                     |    |     |    |
    //                     |    |     |    |
    //                     |    |     |    |
    //                     |    |     |    |
    //                     |    |     |    |
    //                     +----+-----+----+
    //
    // V11              => +---------------+
    //                     |               |
    //                     |               |
    //                     |               |
    //                     +---------------+
    //                     |               |
    //                     |               |
    //                     |               |
    //                     +---------------+
    //
    // V12              => +---------------+
    //                     |               |
    //                     |               |
    //                     +---------------+
    //                     |               |
    //                     |               |
    //                     |               |
    //                     |               |
    //                     +---------------+
    //
    // V21              => +---------------+
    //                     |               |
    //                     |               |
    //                     |               |
    //                     |               |
    //                     +---------------+
    //                     |               |
    //                     |               |
    //                     +---------------+
    //
    // V3               => +---------------+
    //                     |               |
    //                     |               |
    //                     +---------------+
    //                     |               |
    //                     |               |
    //                     +---------------+
    //                     |               |
    //                     |               |
    //                     +---------------+
    //
    // Triplet          =>     +-----+
    //                         |     |
    //                         |     |
    //                         +-----+
    //
    //                     +-----+ +-----+
    //                     |     | |     |
    //                     |     | |     |
    //                     +-----+ +-----+
    //
    // Quadlet          => +-----+ +-----+
    //                     |     | |     |
    //                     |     | |     |
    //                     +-----+ +-----+
    //
    //                     +-----+ +-----+
    //                     |     | |     |
    //                     |     | |     |
    //                     +-----+ +-----+
    //
    // Five             => +--+       +--+
    //                     |  |       |  |
    //                     +--+       +--+
    //                        +-------+
    //                        |       |
    //                        |       |
    //                        +-------+
    //                     +--+       +--+
    //                     |  |       |  |
    //                     +--+       +--+
    //

    typedef enum     {
      Consonants = 1 ,
      Medials    = 2 ,
      Rhymes     = 3 ,
      Dialect    = 4 ,
      Formosan   = 5 ,
      Hokkien    = 6 ,
      MinNan     = 7 }
      Bopomofo       ;

  }

  namespace Knowledge
  {

    enum RuleTypes {
      Scope   =  1 , // Value scope
      Logic   =  2 , // Classical logic rule system
      Fuzzy   =  3 , // Fuzzy inference system
      Ann     =  4 , // Artificial Neural Network
      Game    =  5 , // Game theory rule system
      Lexical =  6   // Lexical rule system
    }              ;

  }

  namespace Grammar
  {

    enum Category       {
      Vague        =  0 ,
      Noun         =  1 ,
      Pronoun      =  2 ,
      Adjective    =  3 ,
      Adverb       =  4 ,
      Preposition  =  5 ,
      Participle   =  6 ,
      Interjection =  7 ,
      Conjunction  =  8 ,
      Verb         =  9
    }                   ;

    enum Properties      {
      Variant       =  0 ,
      Agency        =  1 ,
      Animacy       =  2 ,
      Aspect        =  3 ,
      Case          =  4 ,
      Clusivity     =  5 ,
      Comparison    =  6 ,
      Definiteness  =  7 ,
      Evidentiality =  8 ,
      Focus         =  9 ,
      Gender        = 10 ,
      Mirativity    = 11 ,
      Modality      = 12 ,
      Mood          = 13 ,
      Nouns         = 14 ,
      Number        = 15 ,
      Person        = 16 ,
      Polarity      = 17 ,
      Tense         = 18 ,
      Topic         = 19 ,
      Transitivity  = 20 ,
      Valency       = 21 ,
      Voice         = 22 ,
      Volition      = 23
    }                    ;

  }

  namespace Reasons
  {

    enum Errors          {
      Unknown      =   0 ,
      EndOfFile    =   1 ,
      Truncated    =   2 ,
      Missing      =   3 ,
      NotSupported =   4 ,
      End          =   5
    }                    ;

  }

  namespace LP
  {

    typedef enum {
      IfNormal   ,
      IfTrue     ,
      IfFalse    }
      IfKind     ;

  }

  namespace UDT
  {

    typedef enum          {
      // this values are defined same as linux epoll.h
      // so that if system values are used by mistake, they should have the same effect
      UDT_EPOLL_IN  = 0x1 ,
      UDT_EPOLL_OUT = 0x4 ,
      UDT_EPOLL_ERR = 0x8 }
      EPOLLOpt            ;

    typedef enum     {
      INIT       = 1 ,
      OPENED     = 2 ,
      LISTENING  = 3 ,
      CONNECTING = 4 ,
      CONNECTED  = 5 ,
      BROKEN     = 6 ,
      CLOSING    = 7 ,
      CLOSED     = 8 ,
      NONEXIST   = 9 }
      UdtStatus      ;

    typedef enum     {
      UDT_MSS        , // the Maximum Transfer Unit
      UDT_SNDSYN     , // if sending is blocking
      UDT_RCVSYN     , // if receiving is blocking
      UDT_CC         , // custom congestion control algorithm
      UDT_FC         , // Flight flag size (window size)
      UDT_SNDBUF     , // maximum buffer in sending queue
      UDT_RCVBUF     , // UDT receiving buffer size
      UDT_LINGER     , // waiting for unsent data when closing
      UDP_SNDBUF     , // UDP sending buffer size
      UDP_RCVBUF     , // UDP receiving buffer size
      UDT_MAXMSG     , // maximum datagram message size
      UDT_MSGTTL     , // time-to-live of a datagram message
      UDT_RENDEZVOUS , // rendezvous connection mode
      UDT_SNDTIMEO   , // send() timeout
      UDT_RCVTIMEO   , // recv() timeout
      UDT_REUSEADDR  , // reuse an existing port or create a new one
      UDT_MAXBW      , // maximum bandwidth (bytes per second) that the connection can use
      UDT_STATE      , // current socket state, see UDTSTATUS, read only
      UDT_EVENT      , // current avalable events associated with the socket
      UDT_SNDDATA    , // size of data in the sending buffer
      UDT_RCVDATA    } // size of data available for recv
      UdtOptions     ;

  }

  namespace Cryptography
  {

    typedef enum      {
      Digest      = 1 , // One way encryption
      Cipher      = 2 , // Symmetric cryptography , AES , DES
      Asymmetric  = 3 , // Public key cryptography , RSA , DSA
      Compression = 4 ,
      PKI         = 5 ,
      Signature   = 6 ,
      Others      = 7 }
      CryptoMethods   ;

  }

  namespace Autonomy
  {

    typedef enum      {
      Dreaming   =  0 ,
      Repose     =  1 ,
      Comply     =  2 ,
      Adaptive   =  3 ,
      Impulsive  =  4 ,
      Connective =  5 ,
      MindMeld   =  6 ,
      GrandLink  =  7 ,
      Meeting    =  8 ,
      Dating     =  9 }
      MindStates      ;

  }

  namespace Barcode
  {

    typedef enum {
      Codabar              =   0 , // Codabar
      Code25NonInterleaved =   1 , // Code 25 Non-Interleaved 2 of 5
      Code25Interleaved    =   2 , // Code 25 Interleaved 2 of 5
      Code11               =   3 , // Code 11
      Code39               =   4 , // Code 39
      Code93               =   5 , // Code 93
      Code128              =   6 , // Code 128
      CPC                  =   7 , // CPC Binary
      DUN14                =   8 , // DUN 14
      EAN2                 =   9 , // EAN 2
      EAN5                 =  10 , // EAN 5
      EAN8                 =  11 , // EAN 8
      EAN13                =  12 , // EAN 13
      EAN128               =  13 , // EAN 128 , UCC 128 , GS1-128
      FIM                  =  14 , // Facing Identification Mark
      RSS                  =  15 , // Reduced Space Symbology , GS1 Databar
      HIBC                 =  16 , // Health Industry Bar Code
      IMB                  =  17 , // Intelligent Mail barcode
      ITF14                =  18 , // ITF-14
      JAN                  =  19 , // JAN , Japanese Barcode , EAN-13 compatible
      KarTrak              =  20 , // KarTrak ACI
      LIB                  =  21 , // Latent image barcode
      MSI                  =  22 , // MSI , Used for warehouse shelves and inventory
      Pharmacode           =  23 , // Pharmaceutical packaging
      PLANET               =  24 , // United States Postal Service
      Plessey              =  25 , // Catalogs, store shelves, inventory
      PostBar              =  26 , // Canadian Post office
      POSTNET              =  27 , // United States Postal Service
      KIX                  =  28 , // RM4SCC , Royal Mail , Royal TPG Post
      Telepen              =  29 , // Libraries (UK)
      UPC                  =  30 , // U.P.C.
      Aztec                =  31 , // Aztec Code (Matrix code)
      Code1                =  32 , // Code 1 (Matrix code)
      ColorCode            =  33 , // ColorZip[32] (Matrix code)
      CCC                  =  34 , // Color Construct Code (Matrix code)
      CyberCode            =  35 , // Sony CyberCode (Matrix code)
      DTouch               =  36 , // d-touch (Matrix code)
      DataGlyphs           =  37 , // Palo Alto Research Center (Xerox PARC) (Matrix code)
      DataMatrix           =  38 , // Microscan Systems (Matrix code)
      Datastrip            =  39 , // Datastrip Code (Matrix code)
      DigitalPaper         =  40 , // digital paper (Matrix code)
      EZcode               =  41 , // ScanLife EZcode (Matrix code)
      HCCB                 =  42 , // High Capacity Color Barcode (Matrix code)
      HueCode              =  43 , // Robot Design Associates HueCode (Matrix code)
      InterCode            =  44 , // Iconlab, standard 2D barcode in South Korea (Matrix code)
      MaxiCode             =  45 , // United Parcel Service (Matrix code)
      MMCC                 =  46 , // Mobile multi-coloured composite (Matrix code)
      NexCode              =  47 , // S5 Systems (Matrix code)
      Nintendo             =  48 , // Olympus Corporation , Nintendo e-Reader (Matrix code)
      PDF417               =  49 , // Symbol Technologies
      Qode                 =  50 , // NeoMedia Technologies Qode
      QRcode               =  51 , // Toyota QR code
      ShotCode             =  52 , // High Energy Magic Ltd , TRIPCode
      SPARQCode            =  53 , // QR Code encoding standard from MSKYNET, Inc.
      Neutrino             =  54 , // Neutrino 2D Barcode
    } BarcodeTypes               ;

  }

  namespace Baccarat
  {

    typedef enum   {
      Playing =  0 ,
      Banker  =  1 ,
      Player  =  2 ,
      Tie     =  3 ,
      Red     =  4 ,
      Blue    =  5 ,
      Line    = 16 }
      PlayState    ;

  }

  namespace Unify
  {

    typedef enum            {
      TagsHead    = 354123  ,
      RealityHead = 437791  ,
      NamesHead   = 771283  ,
      NationHead  = 798799  ,
      UnifyEnd    = 9999999 }
      UuidHeaderCode        ;

  }

}

namespace Rishon
{
  enum Ports           {
    KrcFX       = 9689 ,
    Player      = 9697 ,
    Business    = 9719 ,
    Finance     = 9721 ,
    Hathor      = 9733 ,
    Personal    = 9739 ,
    Science     = 9743 ,
    Slider      = 9749 ,
    Update      = 9767 ,
    Baccarat    = 9769 ,
    SicBo       = 9781 ,
    Avatar      = 9787 ,
    Apprentice  = 9817 ,
    Video       = 9829 ,
    Tasks       = 9833 ,
    Pictures    = 9839 ,
    People      = 9851 ,
    Network     = 9857 ,
    Linguistics = 9859 ,
    Knowledge   = 9871 ,
    Indra       = 9883 ,
    History     = 9887 ,
    Graphics    = 9901 ,
    Geography   = 9907 ,
    Forex       = 9923 ,
    Documents   = 9929 ,
    Designer    = 9931 ,
    Database    = 9941 ,
    Backup      = 9949 ,
    Audios      = 9967 ,
    Testbed     = 9973 ,
    CIOS        = 9979
  }                    ;
}
//////////////////////////////////////////////////////////////////////////////
#endif
