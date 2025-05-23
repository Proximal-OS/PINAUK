---
title: Output Protection Levels
description: Output Protection Levels
ms.assetid: '89a9fc13-5ade-4a33-8304-05a2ec999fc1'
keywords:
- Windows Media Format SDK,output protection levels (OPL)
- digital rights management (DRM),output protection levels (OPL)
- DRM (digital rights management),output protection levels (OPL)
- output protection levels (OPL)
- OPL (output protection levels)
ms.topic: reference
ms.date: 4/26/2023
ms.custom: UpdateFrequency5
---

# Output Protection Levels

\[The feature associated with this page, [Windows Media Format 11 SDK](/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](/windows/win32/medfound/source-reader) and [Sink Writer](/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Output protection levels (OPLs) are numerical ratings associated with various technologies that receive digital media content. The level a technology supports depends upon how secure it is. The OPL system, introduced in Windows Media DRM 10, enables licenses to be created with more flexibility than in previous versions. You can specify minimum OPLs required for playback and for copying. In addition, you can specify exceptions to the minimum OPL, either to allow a technology not rated high enough, or to disallow a technology with an OPL that exceeds the minimum.

By specifying restrictions to licenses using OPLs, a content owner need only use two actions (Copy and Play), where previous versions had separate actions defined for the various kinds of devices supported for copying (SDMI, non-SDMI, and Red Book audio CD).

**Note** DRM is not supported by the x64-based version of this SDK.

## Related topics

<dl> <dt>

[**Digital Rights Management Features**](digital-rights-management-features.md)
</dt> <dt>

[**Working with Output Protection Levels**](working-with-output-protection-levels.md)
</dt> </dl>

 

 




