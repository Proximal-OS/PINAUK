---
description: The photo metadata policy for the System.Image.VerticalResolution property.
ms.assetid: a58b7463-3572-4ca8-8299-93d92d2f06fb
title: System.Image.VerticalResolution Photo Metadata Policy
ms.topic: reference
ms.date: 05/31/2018
---

# System.Image.VerticalResolution Photo Metadata Policy

The photo metadata policy for the [System.Image.VerticalResolution](../properties/props-system-image-verticalresolution.md) property.

### PKEY

PKEY\_Image\_VerticalResolution

### Containers

JPEG, TIFF

### Read-Only

Yes.

### Output PROPVARIANT Type

VT\_R8

### Conflict Resolution Policy

This value is generated by the system and it cannot be written directly. Values from different schemas are reconciled.

### JPEG Policy

### Read Paths



| Order | Path                   | Disk Format |
|-------|------------------------|-------------|
| 1     | /app1/ifd/{ushort=283} |             |
| 2     | /xmp/tiff:YResolution  |             |



 

### Remove Paths



| Order | Path                        |
|-------|-----------------------------|
| 1     | /app1/ifd/exif/{ushort=283} |
| 2     | /xmp/tiff:yresolution       |



 

### TIFF Policies

### Read Paths



| Order | Path                      | Disk Format |
|-------|---------------------------|-------------|
| 1     | /ifd/exif/{ushort=283}    |             |
| 2     | /ifd/xmp/tiff:YResolution |             |



 

### Remove Paths



| Order | Path                      |
|-------|---------------------------|
| 1     | /ifd/exif/{ushort=283}    |
| 2     | /ifd/xmp/tiff:yresolution |



 

## Remarks

## Related topics

<dl> <dt>

[System.Image.VerticalResolution](../properties/props-system-image-verticalresolution.md)
</dt> </dl>

 

 
