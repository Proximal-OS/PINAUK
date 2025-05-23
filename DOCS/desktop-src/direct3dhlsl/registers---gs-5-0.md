---
title: Registers - gs_5_0
description: The following input and output registers are implemented in the geometry shader version 5\_0.
ms.assetid: 9E99F584-611F-4CFC-B69A-66F2B4545D36
ms.topic: reference
ms.date: 05/31/2018
---

# Registers - gs\_5\_0

The following input and output registers are implemented in the geometry shader version 5\_0.

## Input Registers



| Register Type                                     | Count              | R/W | Dimension         | Indexable by r\# | Defaults | Requires DCL |
|---------------------------------------------------|--------------------|-----|-------------------|------------------|----------|--------------|
| 32-bit Temp (r\#)                                 | 4096(r\#+x\#\[n\]) | R/W | 4                 | No               | None     | Yes          |
| 32-bit Indexable Temp Array (x\#\[n\])            | 4096(r\#+x\#\[n\]) | R/W | 4                 | Yes              | None     | Yes          |
| 32-bit Input (v\[vertex\]\[element\])             | 32                 | R   | 4(comp)\*32(vert) | Yes              | None     | Yes          |
| 32-bit Input Primitive ID (vPrim)                 | 1                  | R   | 1                 | No               | None     | Yes          |
| 32-bit Input Instance ID (vInstanceID)            | 1                  | R   | 1                 | No               | None     | Yes          |
| Element in an input resource (t\#)                | 128                | R   | 1                 | No               | None     | Yes          |
| Sampler (s\#)                                     | 16                 | R   | 1                 | No               | None     | Yes          |
| ConstantBuffer reference (cb\#\[index\])          | 15                 | R   | 4                 | Yes(contents)    | None     | Yes          |
| Immediate ConstantBuffer reference (icb\[index\]) | 1                  | R   | 4                 | Yes(contents)    | None     | Yes          |



 

## Output Registers



| Register Type                                               | Count | R/W | Dimension | Indexable by r\# | Defaults | Requires DCL |
|-------------------------------------------------------------|-------|-----|-----------|------------------|----------|--------------|
| NULL (discard result, useful for ops with multiple results) | N/A   | W   | N/A       | N/A              | N/A      | No           |
| 32-bit output Vertex Data Element (o\#)                     | 32    | W   | N/A       | N/A              | 4        | Yes          |



 

## Related topics

<dl> <dt>

[Shader Model 5](d3d11-graphics-reference-sm5.md)
</dt> </dl>

 

 




