#ifndef Y_PSTOYAMCOMMON_H
#define Y_PSTOYAMCOMMON_H

// don't check the keyword in vc++ 2012
#if defined(WIN32)
#define _ALLOW_KEYWORD_MACROS
#endif // WIN32

#include "pstoyamr.h"

#include <PIGeneral.h>
#include <PIFormat.h>

#include "yam.h"

#define YPSBLENDMODE_LAYERGROUP            0x00000586

OSErr FSWrite(int32 refNum, int32* count, void* buffPtr);

#endif