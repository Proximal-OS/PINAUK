#include "GFXAPI.h"
#include <stdio.h>

UINT32* getFramebuffer() 
{
    return (UINT32*)gop->Mode->FrameBufferBase;
}
UINT32 getFBPitch()
{
    return gop->Mode->Info->PixelsPerScanLine;
}
UINT32 getFBHeight()
{
    return gop->Mode->Info->VerticalResolution;
}