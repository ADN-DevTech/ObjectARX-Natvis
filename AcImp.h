
#pragma once

#pragma pack(push, 8)


////////////////////////////////////////////////////////////////////////////////
//
//	AcRx class
//
////////////////////////////////////////////////////////////////////////////////
class AcRxImpClass
	{
	public:
		BYTE m_dummy[8];
		ACHAR  *m_strName;									// Offset 8
	};



////////////////////////////////////////////////////////////////////////////////
//
//	AcDb class
//
////////////////////////////////////////////////////////////////////////////////

//
// Win32: sizeof(AcObjectFlags) == 4
// X64:   sizeof(AcObjectFlags) == 4
//
struct AcObjectFlags
	{
	unsigned m_dummy1 : 3;
	unsigned m_bGraphicsModified : 1;
	unsigned m_bErased : 1;
	unsigned m_bXDataModified : 1;
	unsigned m_dummy2 : 10;
	unsigned m_bReadEnabled : 1;
	unsigned m_dummy3 : 4;
	unsigned m_bNotifyEnabled : 1;
	unsigned m_dummy4 : 1;
	unsigned m_bWriteEnabled : 1;
	unsigned m_dummy5 : 8;
	};

class AcImpPtr
	{
	public:
#if (OMF_VER >= 14)
		void* m_dummy[8];						// Offset 0   (0)
#else
		void* m_dummy[4];						// Offset 0   (0)
#endif
		double m_dThickness;				// Offset 32 (16)
		AcGeVector3d m_Normal;			// Offset 40 (24)
	};

//
// Win32: sizeof(AcImpObject) == 20
// X64:   sizeof(AcImpObject) == 40
//
class AcImpObject
	{
	public:
		void* m_dummy1;							// Offset  0  (0)
		AcImpPtr *m_Ptr;						// Offset  8  (4)
		void* m_dummy2;							// Offset 16  (8)
		AcDbObjectId m_id;					// Offset 24 (12)
		AcObjectFlags m_flags;			// Offset 32 (16)
	};

//
// Win32: sizeof(AcImpObject) == 
//				                       <2014 >=2014
// X64:   sizeof(AcImpObject) == 176   152
//
class AcImpEntity : public AcImpObject
	{
	public:
#if defined(_WIN64)
	#if (OMF_VER < 14)
		void* m_dummy1[17];					// Offset  40
	#elif (OMF_VER == 14)
		void* m_dummy1[14];					// Offset  40
	#else
		void* m_dummy1[2];					// Offset  40
	#endif
#else
		void* m_dummy1[9];					// Offset     (20)
#endif
	};

class AcImpCurve : public AcImpEntity
	{
	public:
	};

class AcImpLine : public AcImpCurve
	{
	public:
		AcGePoint3d m_startPoint;
		AcGePoint3d m_endPoint;
	};

class AcImpArc : public AcImpCurve
	{
	public:
#if defined(_WIN64)
		void* m_dummy1[2];
#else
		void* m_dummy1[7];
#endif
		AcGePoint3d m_Center;
		double m_dRadius;
		double m_dStartAngle;
		double m_dEndAngle;
	};

class AcImpCircle : public AcImpCurve
	{
	public:
#if defined(_WIN64)
		void* m_dummy1[2];
#else
		void* m_dummy1[7];
#endif
		AcGePoint3d m_Center;
		double m_dRadius;
	};


struct AcDbTextFlags1
	{
	AcDb::TextVertMode m_VerticalMode : 16;
	__int64 m_dummy1 : 48;
	};

struct AcDbTextFlags2
	{
	unsigned m_dummy1 : 1;
	unsigned m_bMirroredInX : 1;
	unsigned m_bMirroredInY : 1;
	unsigned m_dummy2 : 29;
	};

class AcImpText : public AcImpEntity
	{
	public:
		AcDbTextFlags1 m_flags1;
//		BYTE m_dummy2[8];										// Offset 184 (8 Byte packing!)
		double m_dOblique;
		double m_dTextHeight;
		double m_dWidthFactor;
		ACHAR  *m_strText;
		BYTE m_dummy3[8];
		AcDbTextFlags2 m_flags2;

//		folgende Werte hab' ich (noch) nicht gefunden
//		short m_HorizonalMode;
//		double m_dRotation;
	};


struct AcDbMTextFlags
	{
	unsigned m_dummy1 : 32;
	AcDbMText::FlowDirection m_FlowDirection : 32;
	};

class AcImpMText : public AcImpEntity
	{
	public:
		AcGeVector3d m_Normal;
#if defined(_WIN64)
#else
 		BYTE m_dummy2[16];
#endif
		double m_dTextHeight;
		double m_dLineSpacingFactor;
		ACHAR *m_strContents;
		BYTE m_dummy4[16];
		BYTE m_dummy5[4];
		AcDbMText::FlowDirection m_FlowDirection;

// 		AcGeVector3d m_Direction;			// Offset 
// 		BYTE m_dummy2[24];						// Offset 
// 		AcGePoint3d m_Location;				// Offset 
// 		BYTE m_dummy3[8];							// Offset 
// 		double m_dWidth;							// Offset 
	};


#pragma pack(pop)
