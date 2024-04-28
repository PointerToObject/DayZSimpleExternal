#include <iostream>
#include <Windows.h>
#include "Vector.h"



struct Table {
	std::uint64_t contentsBase;
	int count;
};




struct World
{
    char pad_0000[40];
    unsigned __int64 EngineDx;

    char pad_0001[392];
    unsigned __int64 Camera;

    char pad_0002[2624];
    float Grass;

    char pad_0003[508];
    unsigned __int64 BulletTable;
    unsigned int BulletTableCount;

    char pad_0004[316];
    unsigned __int64 NearTable;
    unsigned int NearTableCount;

    char pad_0005[316];
    unsigned __int64 FarTable;
    unsigned int FarTableCount;

    char pad_0006[3956];
    unsigned __int64 SlowTable;
    unsigned int SlowTableCount;

    char pad_0007[68];
    unsigned __int64 ItemTable;
    unsigned int ItemTableCount;

    char pad_0008[2292];
    unsigned __int64 PlayerEntityLink;

    char pad_0009[12];
    float EyeAccom;
};



struct Camera
{
    unsigned __int64 VirtualTable;

    CVector Right;
    CVector Up;
    CVector Forward;
    CVector Translation;

    char pad_0000[32];
    CVector ViewPort;

    char pad_0001[108];
    CVector Projection1;
    CVector Projection2;



    bool ScreenPosition(CVector vWorld, CVector& vScreen)
    {

        CVector vTemp = vWorld - Translation;

        vTemp = {
            vTemp.Dot(Right),
            vTemp.Dot(Up),
            vTemp.Dot(Forward)
        };

        if (vTemp.z <= 0.19f)
            return false;

        vScreen = {
            ViewPort.x * (1.0F + vTemp.x / Projection1.x / vTemp.z),
            ViewPort.y * (1.0F - vTemp.y / Projection2.y / vTemp.z),
            vTemp.z
        };

        return true;
    }
};





/* respawn player
void FUN_14054f000(void)

{
  undefined8 uVar1;
  char cVar2;

  cVar2 = FUN_140540310();
  if (cVar2 == '\0') {
	FUN_1409bdb00("Unable to respawn player.");
	return;
  }
  uVar1 = FUN_14067c300();
  FUN_14067e260(uVar1);
  FUN_1408365e0(DAT_14414cf70);
  return;
}
*/

/*
float FUN_140545bb0(void)

{
  float fVar1;

  fVar1 = (float)FUN_1407efbb0(DAT_14414c6b0,0x10);
  return fVar1 * 0.001;
}

*/