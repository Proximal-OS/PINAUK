---
title: WM_NCPOINTERUP message
description: Posted when a pointer that made contact over the non-client area of a window breaks contact.
ms.assetid: 4bdc11da-227c-4be1-bf0b-99704caa1322
keywords:
- WM_NCPOINTERUP message Input Messages and Notifications
topic_type:
- apiref
api_name:
- WM_NCPOINTERUP
api_location:
- Winuser.h
api_type:
- HeaderDef
ms.topic: reference
ms.date: 02/03/2020
---

# WM_NCPOINTERUP message

Posted when a pointer that made contact over the non-client area of a window breaks contact. The message targets the window over which the pointer makes contact and the pointer is, at that point, implicitly captured to the window so that the window continues to receive input for the pointer until it breaks contact, including the **WM_NCPOINTERUP** notification.

If a window has captured this pointer, this message is not posted. Instead, a [**WM_POINTERUP**](wm-pointerup.md) is posted to the window that has captured this pointer.

> ![Important]  
> Desktop apps should be DPI aware. If your app is not DPI aware, screen coordinates contained in pointer messages and related structures might appear inaccurate due to DPI virtualization. DPI virtualization provides automatic scaling support to applications that are not DPI aware and is active by default (users can turn it off). For more information, see [Writing High-DPI Win32 Applications](/previous-versions//dd464660(v=vs.85)).

 


```C++
#define WM_NCPOINTERUP               0x0243
```



## Parameters

<dl> <dt>

*wParam* 
</dt> <dd>

Contains the pointer identifier and additional information. Use the following macros to retrieve this information.

[**GET_POINTERID_WPARAM**](/windows/win32/api/winuser/nf-winuser-get_pointerid_wparam)(wParam): pointer identifier

[**HIWORD**](../winmsg/hiword.md)(wParam): hit-test value returned from processing the [**WM_NCHITTEST**](../inputdev/wm-nchittest.md) message.

</dd> <dt>

*lParam* 
</dt> <dd>

Contains the point location of the pointer.

> [!Note]  
> Because the pointer may make contact with the device over a non-trivial area, this point location may be a simplification of a more complex pointer area. Whenever possible, an application should use the complete pointer area information instead of the point location.

 

Use the following macros to retrieve the physical screen coordinates of the point.

-   [**GET_X_LPARAM**](/windows/win32/api/windowsx/nf-windowsx-get_x_lparam)(lParam): the x (horizontal point) coordinate.
-   [**GET_Y_LPARAM**](/windows/win32/api/windowsx/nf-windowsx-get_y_lparam)(lParam): the y (vertical point) coordinate.

</dd> </dl>

## Return value

If an application processes this message, it should return zero.

If the application does not process this message, it should call [**DefWindowProc**](/windows/win32/api/winuser/nf-winuser-defwindowproca).

## Remarks

If the application does not process this message, [**DefWindowProc**](/windows/win32/api/winuser/nf-winuser-defwindowproca) may perform one or more system actions depending on the hit-test result included in the message. Typically, applications should not need to handle this message.

## Requirements



| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br/> | Windows 8 \[desktop apps only\]<br/>                                                               |
| Minimum supported server<br/> | Windows Server 2012 \[desktop apps only\]<br/>                                                     |
| Header<br/>                   | <dl> <dt>Winuser.h (include Windows.h)</dt> </dl> |



## See also

<dl> <dt>

[Messages](messages.md)
</dt> </dl>

 

