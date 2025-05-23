---
description: Registering MPEG2 Codecs
ms.assetid: f730a7df-af8f-4dce-9bfe-6ee1eca8fd90
title: Registering MPEG2 Codecs
ms.topic: concept-article
ms.date: 4/26/2023
ms.custom: UpdateFrequency5
---

# Registering MPEG2 Codecs

\[The feature associated with this page, [DirectShow](/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

This topic applies to Windows XP Media Center Edition only.

Windows XP Media Center Edition maintains two registry keys that it uses to determine which codec to use to play back MPEG2 video and audio files. The first registry key specifies the computer manufacturer's preferred MPEG2 codec, and the second lists all of the Media Center compatible codecs that are currently installed on the computer. When Media Center needs to play back an MPEG2 file, it uses the manufacturer's preferred codec, if one is specified. If not, it uses the first Media Center compatible codec listed in the registry. If the registry specifies no preferred or compatible codecs, Media Center uses the standard DirectShow filter merit to choose a codec.

To ensure that Media Center always uses a compatible MPEG2 codec, manufacturers of Media Center computers should specify the preferred MPEG2 codec at the following registry location:


```C++
HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Media Center\Service\Video
```



The key data should be as follows:


```C++
PreferredMPEG2VideoDecoder=REG_SZ "{MPEG2 Video CLSID GUID}"
PreferredMPEG2AudioDecoder=REG_SZ "{MPEG2 Audio CLSID GUID}"
```



The setup program for a Media Center compatible MPEG2 codec should register the codec by creating two instances of the following registry key—one for the video codec and one for the audio codec:


```C++
[HKEY_CLASSES_ROOT\CLSID\{083863F1-70DE-11d0-BD40-00A0C911CE86}\Instance\<Your Codec CLSID here>\Capabilities]
```



The key data should be as follows:


```C++
"{374ac4df-7c98-4257-b13d-36087dbee458}"=dword:00000001
```



 

 



