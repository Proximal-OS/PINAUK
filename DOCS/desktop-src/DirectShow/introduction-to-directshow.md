---
description: Introduction to DirectShow
ms.assetid: 39a701b3-2633-426f-9733-2172ad3ea372
title: Introduction to DirectShow
ms.topic: concept-article
ms.date: 4/26/2023
ms.custom: UpdateFrequency5
---

# Introduction to DirectShow

\[The feature associated with this page, [DirectShow](/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Microsoft® DirectShow® is an architecture for streaming media on the Microsoft Windows® platform. DirectShow provides for high-quality capture and playback of multimedia streams. It supports a wide variety of formats, including Advanced Systems Format (ASF), Motion Picture Experts Group (MPEG), Audio-Video Interleaved (AVI), MPEG Audio Layer-3 (MP3), and WAV sound files. It supports capture from digital and analog devices based on the Windows Driver Model (WDM) or Video for Windows. It automatically detects and uses video and audio acceleration hardware when available, but also supports systems without acceleration hardware.

DirectShow is based on the Component Object Model (COM). To write a DirectShow application or component, you must understand COM client programming. For most applications, you do not need to implement your own COM objects. DirectShow provides the components you need. If you want to extend DirectShow by writing your own components, however, you must implement them as COM objects.

DirectShow is designed for C++. Microsoft does not provide a managed API for DirectShow.

DirectShow simplifies media playback, format conversion, and capture tasks. At the same time, it provides access to the underlying stream control architecture for applications that require custom solutions. You can also create your own DirectShow components to support new formats or custom effects.

Examples of the types of application you can write with DirectShow include file players, TV and DVD players, video editing applications, file format converters, audio-video capture applications, encoders and decoders, digital signal processors, and more.

This section contains the following topics:

-   [What's New in DirectShow](whats-new-in-directshow.md)
-   [Supported Formats in DirectShow](supported-formats-in-directshow.md)
-   [DirectShow FAQ](directshow-faq.yml)

## Related topics

<dl> <dt>

[Getting Started](getting-started.md)
</dt> <dt>

[Using DirectShow](using-directshow.md)
</dt> </dl>

 

 



