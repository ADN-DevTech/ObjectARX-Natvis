
#pragma once

#pragma pack(push, 8)



////////////////////////////////////////////////////////////////////////////////
//
//	3d-AcGe-classes
//
////////////////////////////////////////////////////////////////////////////////

class AcGeImpEntity3d
	{
	public:
		void* m_Dummy[4];				// Offset 0
	};

class AcGeImpCurve3d : public AcGeImpEntity3d
	{
	public:
	};

class AcGeImpLinearEnt3d : public AcGeImpCurve3d
	{
	public:												//				Win32  X64
		AcGePoint3d  m_startPoint;	// Offset  16     32
		AcGeVector3d m_Direction;		// Offset  40     56
	};

class AcGeImpLineSeg3d : public AcGeImpLinearEnt3d
	{
	public:
	};

class AcGeImpLine3d : public AcGeImpLinearEnt3d
	{
	public:
	};

class AcGeImpRay3d : public AcGeImpLinearEnt3d
	{
	public:
	};

class AcGeImpSurface : public AcGeImpEntity3d
	{
	public:
	};

class AcGeImpPlanarEnt : public AcGeImpSurface
	{
	public:
		void* m_dummy1[2];
		BYTE m_dummy2[32];
		AcGePoint3d m_Origin;				// Offset  80  (56)
		AcGeVector3d m_vAxis;				// Offset 104  (80)
		AcGeVector3d m_uAxis;				// Offset 128 (104)
	};

class AcGeImpBoundBlock3d: public AcGeImpEntity3d
	{

	public:
		int m_bIsBox;						// Offset  32 (16)
		BYTE m_dummy2[4];				// Offset  36 (20)
		AcGePoint3d m_Base;			// Offset  40 (24)
		AcGeVector3d m_xDir;		// Offset  64	(48)
		AcGeVector3d m_yDir;		// Offset  88 (72)
		AcGeVector3d m_zDir;		// Offset 112 (96)
	};



////////////////////////////////////////////////////////////////////////////////
//
//	2d-AcGe-classes
//
////////////////////////////////////////////////////////////////////////////////

class AcGeImpEntity2d
	{
	public:
		void* m_Dummy[4];				// Offset 0
	};

class AcGeImpCurve2d : public AcGeImpEntity2d
	{
	public:
	};

class AcGeImpLinearEnt2d : public AcGeImpCurve2d
	{
	public:
		AcGePoint2d m_startPoint;		// Offset 32
		BYTE m_cDummy[8];
		AcGeVector2d m_Direction;		// Offset 56
	};

class AcGeImpLineSeg2d : public AcGeImpLinearEnt2d
	{
	public:
	};

class AcGeImpLine2d : public AcGeImpLinearEnt2d
	{
	public:
	};

class AcGeImpRay2d : public AcGeImpLinearEnt2d
	{
	public:
	};

class AcGeImpBoundBlock2d: public AcGeImpEntity2d
	{

	public:
		int m_bIsBox;						// Offset  32
		BYTE m_dummy2[4];				// Offset  36
		AcGePoint2d m_Base;			// Offset  40
		BYTE m_cDumm1[8];				// Offset  56
		AcGeVector2d m_xDir;		// Offset  64
		BYTE m_cDummy2[8];			// Offset  80
		AcGeVector2d m_yDir;		// Offset  88
	};

// 32 Bit == 4 Bytes
struct AcGeIntervalFlags
	{
	unsigned m_bBoundedAbove : 1;
	unsigned m_bBoundedBelow : 1;
	unsigned m_dummy2 : 30;
	};

class AcGeImpInterval
	{
	public:
		double m_dLowerBound;					// Offset 0
		double m_dUpperBound;					// Offset 8
		double m_dTolerance;					// Offset 16
		AcGeIntervalFlags m_Flags;		// Offset 24
	};

#pragma pack(pop)
