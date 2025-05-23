---
description: This topic describes how to use audio/video effects with MFPlay.
ms.assetid: 90f34bf3-899f-46e0-80c8-af83caa4835d
title: How to Add Audio or Video Effects
ms.topic: how-to
ms.date: 05/31/2018
---

# How to Add Audio or Video Effects

\[The feature associated with this page, MFPlay, is a legacy feature. It has been superseded by [MediaPlayer](/uwp/api/Windows.Media.Playback.MediaPlayer) and  [IMFMediaEngine](/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** and **IMFMediaEngine** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

This topic describes how to use audio/video effects with MFPlay.

To use an effect with MFPlay, the effect must be implemented as a Media Foundation transform (MFT). For more information, see [Media Foundation Transforms](media-foundation-transforms.md).

**To Add an Audio or Video Effect**

1.  Create an instance of the MFT that implements the effect.
2.  Call [**IMFPMediaPlayer::InsertEffect**](/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayer-inserteffect).

Call [**InsertEffect**](/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayer-inserteffect) before you open the media file for playback. MFPlay automatically determines whether the effect is a video effect or audio effect.

The [**InsertEffect**](/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayer-inserteffect) method also takes a Boolean parameter that specifies whether the effect is optional or required. If MFPlay cannot add a required effect (for example, because the stream format is incompatible), a playback error occurs. In most cases, it is better to set an effect as optional.

MFPlay continues to use the effect for all subsequent playback. To remove the effect, call [**IMFPMediaPlayer::RemoveEffect**](/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayer-removeeffect) or [**IMFPMediaPlayer::RemoveAllEffects**](/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayer-removealleffects).


```C++
HRESULT AddPlaybackEffect(REFGUID clsid, IMFPMediaPlayer *pPlayer)
{
    IMFTransform *pMFT = NULL;

    HRESULT hr = CoCreateInstance(clsid, NULL, CLSCTX_INPROC_SERVER, 
        IID_PPV_ARGS(&pMFT));

    if (SUCCEEDED(hr))
    {
        hr = pPlayer->InsertEffect(pMFT, TRUE); // Set as optional.
    }

    SafeRelease(&pMFT);
    return hr;
}
```



## Requirements

MFPlay requires Windows 7.

## Related topics

<dl> <dt>

[Using MFPlay for Audio/Video Playback](using-mfplay-for-audio-video-playback.md)
</dt> </dl>

 

 



