---
title: Adding User-Controlled Playback
description: Adding User-Controlled Playback
ms.assetid: c865bbc1-f78a-4d88-ab60-fba76818d175
keywords:
- MCIWndCreate function
ms.topic: how-to
ms.date: 4/26/2023
ms.custom: UpdateFrequency5
---

# Adding User-Controlled Playback

\[The feature associated with this page, [MCIWnd Window Class](/windows/win32/multimedia/mciwnd-window-class), is a legacy feature. It has been superseded by [MediaPlayer](/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **MCIWnd Window Class**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

You can add user-controlled playback to an existing application by calling the [**MCIWndCreate**](/windows/desktop/api/Vfw/nf-vfw-mciwndcreatea) function as follows:


```C++
MCIWndCreate(hwndParent, hInstModule, NULL, "filename.typ"); 
```



The [**MCIWndCreate**](/windows/desktop/api/Vfw/nf-vfw-mciwndcreatea) parameters identify handles to the parent window and to the module instance associated with the MCIWnd window. They also specify window styles and the filename (or device name) to associate with the MCIWnd window.

**MCIWndCreate** automatically performs the following steps that, for other window classes, you would implement in your code yourself:

1.  Register the MCIWnd window class.
2.  Create the MCIWnd window.
3.  Load the specified content.
4.  Establish the current playback position at the beginning of the content.
5.  Display the device control.
6.  Display the playback area of the window, if needed.

 

 




