---
description: The PlayBackwards event is sent when the PlayBackwards command has been enabled or disabled.
ms.assetid: '35e1deaf-7ca0-4bf5-a0ac-5e02f5edb646'
title: PlayBackwards
ms.topic: reference
ms.date: 4/26/2023
ms.custom: UpdateFrequency5
---

# PlayBackwards

\[The feature associated with this page, [DirectShow](/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

> [!Note]  
> This component is available for use in the Microsoft Windows 2000, Windows XP, and Windows Server 2003 operating systems. It may be altered or unavailable in subsequent versions.

 

The `PlayBackwards` event is sent when the `PlayBackwards` command has been enabled or disabled.

``` syntax
PlayBackwards(bEnabled)
```

## Parameters

<dl> <dt>

<span id="bEnabled"></span><span id="benabled"></span><span id="BENABLED"></span>*bEnabled*
</dt> <dd>

Specifies whether the operation is enabled or disabled as a Boolean.

</dd> </dl>

 

 



