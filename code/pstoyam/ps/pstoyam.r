#ifndef Y_PSTOYAM_R
#define Y_PSTOYAM_R

#include "PIGeneral.h"

#include "pstoyamr.h"

resource 'PiPL' (MYRESOURCEID, MYPLUGINNAME " PiPL", purgeable)
{
    {
        Kind { ImageFormat },
        Name { MYPLUGINNAME },
        Version { (latestFormatVersion << 16) | latestFormatSubVersion },
        
        #ifdef __PIMac__
            #if (defined(__x86_64__))
                CodeMacIntel64 { "PluginMain" },
            #endif
            #if (defined(__i386__))
                CodeMacIntel32 { "PluginMain" },
            #endif
        #else
            #if defined(_WIN64)
                CodeWin64X86 { "PluginMain" },
            #else
                CodeWin32X86 { "PluginMain" },
            #endif
        #endif

        SupportedModes
        {
            doesSupportBitmap,
            doesSupportGrayScale,
            doesSupportIndexedColor,
            doesSupportRGBColor,
            notSupportCMYKColor,
            notSupportHSLColor,
            notSupportHSBColor,
            notSupportMultichannel,
            notSupportDuotone,
            notSupportLABColor
        },
        
        // If you want your format module always enabled.
        //EnableInfo { "true" },
        EnableInfo
        {
            "in (PSHOP_ImageMode, GrayScaleMode, IndexedColorMode, RGBMode, CMYKMode, HSLMode, HSBMode, MultichannelMode, DuotoneMode, LabMode)"
        },

        // New for Photoshop 8, document sizes that are really big
        // 32 bit row and columns, 2,000,000 current limit but we can handle more
        PlugInMaxSize { 2147483647, 2147483647 },

        // For older Photoshops that only support 30000 pixel documents, 
        // 16 bit row and columns
        FormatMaxSize { { 32767, 32767 } },

        FormatMaxChannels { {   1, 24, 24, 24, 24, 24, 
                               24, 24, 24, 24, 24, 24 } },

        FmtFileType { 'yui ', kPIHostBlendModeSignature },
        ReadTypes { { 'yui ', kPIHostBlendModeSignature } },
        FilteredTypes { { '8B1F', '    ' } },
        ReadExtensions { { 'yui ' } },
        WriteExtensions { { 'yui ' } },
        FilteredExtensions { { 'yui ' } },
        FormatFlags { fmtSavesImageResources, 
                      fmtCanRead, 
                      fmtCanWrite, 
                      fmtCanWriteIfRead, 
                      fmtCanWriteTransparency, 
                      fmtCanCreateThumbnail
        }
    }
};

#endif // Y_PSTOYAM_R
