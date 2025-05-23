---
title: Watermarking Support
description: Watermarking Support
ms.assetid: 1fafb15e-57b8-4dd0-8f0c-ccf460f05157
keywords:
- Windows Media Format SDK,watermarking support
- Windows Media Format SDK,digital watermarking
- Advanced Systems Format (ASF),watermarking support
- ASF (Advanced Systems Format),watermarking support
- Advanced Systems Format (ASF),digital watermarking
- ASF (Advanced Systems Format),digital watermarking
- Windows Media Format SDK,DMO
- Advanced Systems Format (ASF),DMO
- ASF (Advanced Systems Format),DMO
- Windows Media Format SDK,IWMWatermarkInfo interface
- Advanced Systems Format (ASF),IWMWatermarkInfo interface
- ASF (Advanced Systems Format),IWMWatermarkInfo interface
- watermarking,about
- digital watermarking
- DirectX Media Object (DMO),about
- DMO (DirectX Media Object),about
- IWMWatermarkInfo
ms.topic: concept-article
ms.date: 4/26/2023
ms.custom: UpdateFrequency5
---

# Watermarking Support

\[The feature associated with this page, [Windows Media Format 11 SDK](/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](/windows/win32/medfound/source-reader) and [Sink Writer](/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Digital watermarking is a way to embed copyright or other information in the data of a media stream. Techniques for watermarking vary widely from one solution to the next. The simplest form of watermarking is simply adding an identifying image to each frame of a video stream. Television stations frequently use this technique to insert a semi-transparent logo in a bottom corner of their broadcast. More sophisticated forms of digital watermarking are imperceptible to the user watching or listening to the content.

The Windows Media Format SDK supports the use of digital watermarking [*DMOs*](wmformat-glossary.md). In practice, a watermarking system is very similar to a codec: it takes media samples, runs algorithms on the data, and outputs the altered samples. When a watermarking system is specified for a stream, the writer object includes the DMO in its processing of input samples.

You must specify watermark configuration information when you configure a stream for watermarking. The configuration values will be different depending upon the watermarking DMO. The DMO you use should come with instructions describing the configuration values it supports.

For information about the settings used to specify a watermarking system, see [**IWMWriterAdvanced2::SetInputSetting**](/previous-versions/windows/desktop/api/Wmsdkidl/nf-wmsdkidl-iwmwriteradvanced2-setinputsetting)

You can program your application to enumerate the watermarking DMOs installed on the client computer. For more information, see the [**IWMWatermarkInfo**](/previous-versions/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmwatermarkinfo) interface.

## Related topics

<dl> <dt>

[**File Writing Features**](file-writing-features.md)
</dt> </dl>

 

 




