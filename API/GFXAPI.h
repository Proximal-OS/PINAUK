#ifndef GFXAPI_H
#define GFXAPI_H
#ifdef __cplusplus
extern "C" {
#endif
#include <efi.h>

UINT32* getFramebuffer();
UINT32 getFBPitch();
UINT32 getFBHeight();

#ifdef __cplusplus
}
#endif

#endif  // GFXAPI_H