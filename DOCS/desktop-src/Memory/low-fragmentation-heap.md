---
description: Heap fragmentation occurs when available memory is broken into small, noncontiguous blocks. The low-fragmentation heap (LFH) helps to reduce heap fragmentation.
ms.assetid: d10abf82-423c-4942-b05e-55de3a5c4219
title: Low-fragmentation Heap
ms.topic: reference
ms.date: 09/12/2023
---

# Low-fragmentation Heap

\[The information in this topic applies to Windows Server 2003 and Windows XP. Starting with Windows Vista, the system uses the low-fragmentation heap (LFH) as needed to service memory allocation requests. Applications do not need to enable the LFH for their heaps.\]

Heap fragmentation is a state in which available memory is broken into small, noncontiguous blocks. When a heap is fragmented, memory allocation can fail even when the total available memory in the heap is enough to satisfy a request, because no single block of memory is large enough. The low-fragmentation heap (LFH) helps to reduce heap fragmentation.

The LFH is not a separate heap. Instead, it is a policy that applications can enable for their heaps. When the LFH is enabled, the system allocates memory in certain predetermined sizes. When an application requests a memory allocation from a heap that has the LFH enabled, the system allocates the smallest block of memory that is large enough to contain the requested size. In the current implementation, the system does not use the LFH for allocations larger than approximately 16 KB, whether or not the LFH is enabled.

An application should enable the LFH only for the default heap of the calling process or for [private heaps](heap-functions.md) that the application has created. To enable the LFH for a heap, use the [**GetProcessHeap**](/windows/win32/api/HeapApi/nf-heapapi-getprocessheap) function to obtain a handle to the default heap of the calling process, or use the handle to a private heap created by the [**HeapCreate**](/windows/win32/api/HeapApi/nf-heapapi-heapcreate) function. Then call the [**HeapSetInformation**](/windows/win32/api/HeapApi/nf-heapapi-heapsetinformation) function with the handle.

The LFH cannot be enabled for heaps created with **HEAP_NO_SERIALIZE** or for heaps created with a fixed size. The LFH also cannot be enabled if you are using the heap debugging tools in [Debugging Tools for Windows](/windows-hardware/drivers/debugger/) or [Application Verifier](/windows-hardware/drivers/devtest/application-verifier).

After the LFH has been enabled for a heap, it cannot be disabled.

Applications that benefit most from the LFH are multithreaded applications that allocate memory frequently and use a variety of allocation sizes comfortably below 16 KB. However, not all applications benefit from the LFH. To assess the effects of enabling the LFH in your application, use performance profiling data.
