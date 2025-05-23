---
description: This documentation specifically refers to the Windows Vista extensions for DirectX graphics.
ms.assetid: 3cc0b08c-e126-4f1b-b5d1-0d6c1ebeb0c5
title: Feature Summary (Direct3D 9 for Windows Vista)
ms.topic: reference
ms.date: 05/31/2018
---

# Feature Summary (Direct3D 9 for Windows Vista)

This documentation specifically refers to the Windows Vista extensions for DirectX graphics. To develop the power of DirectX for Windows Vista, you must install the Windows Vista SDK as well as the DirectX SDK. Applications using DirectX for Windows Vista must be using hardware that uses the WDDM driver (Windows Device Driver Model) as opposed to the XPDM (XP Driver Model); drivers that do not implement the WDDM cannot instantiate Windows Vista DirectX graphics interfaces.

Discover the new DirectX graphics features in Windows Vista in one of these sections:

-   [Device Behavior Changes](#device-behavior-changes)
-   [Disabling Multithreaded Software Vertex Processing](#disabling-multithreaded-software-vertex-processing)
-   [One Bit Surfaces](#one-bit-surfaces)
-   [Reading Depth/Stencil Buffers](#reading-depthstencil-buffers)
-   [Sharing Resources](#sharing-resources)
-   [sRGB Conversion Before Blending](#srgb-conversion-before-blending)
-   [StretchRect Improvements](#stretchrect-improvements)
-   [Texture Creation in System Memory](#texture-creation-in-system-memory)

## Device Behavior Changes

Devices are now only lost under two circumstances; when the hardware is reset because it is hanging, and when the device driver is stopped. When hardware hangs, the device can be reset by calling [**ResetEx**](/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9ex-resetex). If hardware hangs, texture memory is lost.

After a driver is stopped, the IDirect9Ex object must be recreated to resume rendering.

When the presentation area is obscured by another window in windowed mode, or when a fullscreen application is minimized, [**PresentEx**](/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9ex-presentex) will return S\_D3DPRESENTATIONOCCLUDED. Full screen applications can resume rendering when they receive a [**WM\_ACTIVATEAPP**](../winmsg/wm-activateapp.md) callback message.

In previous versions of DirectX, when an application experienced a mode change, the only way to recover was to reset the device and re-create all video memory resources and swap chains. Now with DirectX for Windows Vista, calling Reset after a mode change does not cause texture memory surfaces, textures and state information to be lost and these resources do not need to be recreated.

## Disabling Multithreaded Software Vertex Processing

A new caps bit (D3DCREATE\_DISABLE\_PSGP\_THREADING) has been added that will disable multithreading for software vertex processing (swvp). Use this macro to generate a behavior flag for IDirect3D9::CreateDevice.


```
#define D3DCREATE_DISABLE_PSGP_THREADING
```



## One Bit Surfaces

There is a new one bit surface format type which can be especially useful for processing text glyphs. The new format is called D3DFMT\_A1. A one-bit surface is designed to be either used as a per-pixel texture, or the render target output generated by ComposeRects or ColorFill. There are no separate caps for the surface width and height; an implementation must support a single size surface that is 2K texels x 8K texels.

A one-bit surface has one bit per texel; therefore, a one would mean that all components (r,g,b,a) of a pixel are 1, and zero would mean that all components are equal to 0. You may use one-bit surfaces with the following APIs: ColorFill, UpdateSurface and UpdateTexture.

When a one-bit surface is read, the runtime can perform either point sample or convolution filtering. The convolution filter is adjustable (see [**SetConvolutionMonoKernel**](/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9ex-setconvolutionmonokernel)).

There are some restrictions for one-bit surfaces:

-   Mip-mapping is not supported
-   sRGB data cannot be read or written to a one-bit surface.
-   A one-bit surface cannot be used as a vertex texture or for multisampling.

## Reading Depth/Stencil Buffers

Use IDirect3DDevice9::UpdateSurface to read or write depth/stencil data from surfaces obtained from IDirect3DDevice9::CreateDepthStencilSurface or IDirect3DDevice9::GetDepthStencilSurface.

First, create a lockable, depth only or stencil only surface using IDirect3DDevice9::CreateOffscreenPlainSurface. Use one of the following formats:

-   D3DFMT\_D16\_LOCKABLE
-   D3DFMT\_D32F\_LOCKABLE
-   D3DFMT\_D32\_LOCKABLE
-   D3DFMT\_S8\_LOCKABLE

Second, transfer data between the depth/stencil buffer and the newly-created lockable depth or stencil surface. The transfer is performed using IDirect3DDevice9::UpdateSurface.

UpdateSurface will fail when both surfaces are a LOCKABLE format or both are non-lockable.

Transferring non-existent data will result in an error (for example, transferring from a non-lockable depth-only surface to a D3DFMT\_S8\_LOCKABLE surface).

The rest of the restrictions for IDirect3DDevice9::UpdateSurface still apply.

## Sharing Resources

Direct3D resources can now be shared between devices or processes. This applies to any Direct3D resource including textures, vertex buffers, index buffers, or surfaces (such as render targets, depth stencil buffers or off-screen plain surfaces). To be shared, you need to designate a resource for sharing at the time of creation, and locate the resource in the default pool (D3DPOOL\_DEFAULT). Once a resource is created for sharing, it can be shared across devices within a process, or shared across processes.

To enable shared resources, the resource creation APIs have an additional handle parameter. This is a HANDLE that points to the shared resource. In previous revisions of DirectX, this argument has been part of the API signature, but has been unused and must be set to **NULL**. Starting with Windows Vista, use pSharedHandle in the following ways:

-   Set the pointer (pSharedHandle) to **NULL** to not share a resource. This is just like the behavior of DirectX prior to Windows Vista.
-   To create a shared resource, call any resource creation API (see below) with an uninitialized handle (the pointer itself is not **NULL** (pSharedHandle != **NULL**), but the pointer points to a **NULL** value (\*pSharedHandle == **NULL**)). The API will generate a shared resource and return a valid handle.
-   To open and access a previously created shared resource by using a nonNULL shared resource handle, set pSharedHandle to the address of that handle. After you open the previously created shared resource in this manner, you can use the returned interface in the Direct3D 9 or Direct3D 9Ex API as if the interface were a typical resource of that type.

Resource creation APIs include - [**CreateTexture**](/windows/desktop/api), [**CreateVolumeTexture**](/windows/desktop/api), [**CreateCubeTexture**](/windows/desktop/api), [**CreateRenderTarget**](/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-createrendertarget), [**CreateVertexBuffer**](/windows/desktop/api), [**CreateIndexBuffer**](/windows/desktop/api), [**CreateDepthStencilSurface**](/windows/desktop/api), [**CreateOffscreenPlainSurface**](/windows/desktop/api), [**CreateDepthStencilSurfaceEx**](/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9ex-createdepthstencilsurfaceex), [**CreateOffscreenPlainSurfaceEx**](/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9ex-createoffscreenplainsurfaceex), and [**CreateRenderTargetEx**](/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9ex-createrendertargetex).

There are some restrictions for using shared resources. These include:

-   The API that you use to open a shared resource must match the API that you used to create the shared resource. For example, if you used [**CreateTexture**](/windows/desktop/api) to create a shared resource, you must use **CreateTexture** to open that shared resource; if you used [**CreateRenderTarget**](/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-createrendertarget) to create a shared resource, you must use **CreateRenderTarget** to open that shared resource; and so on.
-   When you open a shared resource, you must specify D3DPOOL\_DEFAULT.
-   Lockable resources (textures with D3DUSAGE\_DYNAMIC, vertex buffers and index buffers, for instance) can experience poor performance when shared. Lockable rendertargets will fail to be shared on some hardware.
-   References to a cross-process shared resource must have the same dimensions as the original resource. When passing a handle across process, include the dimension information so that the reference can be created identically.
-   Shared cross-process surfaces provide no synchronization mechanism. Read/write changes to a shared surface may not reflect a referencing process's view of the surface when expected. To provide synchronization, use event queries or lock the texture.
-   Only the process that initially creates a shared resource can lock it (any process that opens a reference to that shared resource cannot lock it).
-   If a shared resource is locked, there is no validation for other processes to know if the resource is available.

## sRGB Conversion Before Blending

You can now check to see if the device can convert pipeline data to sRGB before frame-buffer blending. This implies that the device converts the render-target values from sRGB. To see if conversion is supported by the hardware, check for this cap:


```
D3DPMISCCAPS_POSTBLENDSRGBCONVERT
```



This cap identifies hardware that supports conversion to sRGB before blending. This capability is important for the high quality rendering from fp16 frame buffers in the desktop window manager (DWM).

## StretchRect Improvements

In previous versions of DirectX, StretchRect has many restrictions to accommodate different drivers (see IDirect3DDevice9::StretchRect). Windows Vista is built on the Windows Device Driver Model (WDDM). This new driver model is much more robust, and allows drivers to handle special cases in the hardware.

In general, the only remaining restriction is that the render target must have been created with render-target usage (D3DUSAGE\_RENDERTARGET). This restriction is lifted if you are doing a simple copy (where the source and dest are the same format, same size and there are no sub-rectangles).

## Texture Creation in System Memory

Applications that need more flexibility over the use, allocation and deletion of the system memory can now create textures from a system memory pointer. For example, an application could create a Direct3D texture from a GDI system-memory bitmap pointer.

You need to do two things to create such a texture:

-   Allocate enough system memory to hold the texture surface. The minimum number of bytes is width x height x bytes per pixel.
-   Pass the address of a pointer to your system memory surface for the HANDLE\* parameter to IDirect3DDevice9::CreateTexture.

Here is the function prototype for IDirect3DDevice9::CreateTexture:


```
STDMETHOD(CreateTexture)(THIS_ UINT Width, UINT Height, UINT Levels, 
    DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DTexture9** ppTexture, 
    HANDLE* pSharedHandle)
```



A system-memory texture has the following restrictions:

-   The texture pitch must equal texture width times the number of bytes per pixel.
-   When using compressed formats (DXT formats), the application is responsible for allocating the correct size.
-   Only textures with a single mipmap level are supported.
-   The value passed to CreateTexture for the Pool argument must be D3DPOOL\_SYSTEMMEM.
-   This API wraps the supplied memory in a texture. Do not deallocate this memory until you are done with it.

 

 
