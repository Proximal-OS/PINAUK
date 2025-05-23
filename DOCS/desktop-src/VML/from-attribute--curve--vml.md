---
title: From Attribute (Curve)(VML)
description: From Attribute (Curve)(VML)
ms.assetid: 70e940c1-3fa8-4a30-9ca8-584483cea485
ms.topic: reference
ms.date: 05/31/2018
---

# From Attribute (Curve)(VML)

This topic describes VML, a feature that is deprecated as of Windows Internet Explorer 9. Webpages and applications that rely on VML should be migrated to SVG or other widely supported standards.

> [!Note]  
> As of December 2011, this topic has been archived. As a result, it is no longer actively maintained. For more information, see [Archived Content](/previous-versions/windows/internet-explorer/ie-developer/). For information, recommendations, and guidance regarding the current version of Windows Internet Explorer, see [Internet Explorer Developer Center](https://msdn.microsoft.com/ie/).

 

Defines the starting point of a curve. Read/write. **VgVector2D**.

**Applies To**

[Curve](msdn-online-vml-curve-element.md)

**Tag Syntax**

<v: *element* from=" *expression* ">

**Script Syntax**

*element* .from="*expression*"

*expression*=*element*.from

**Remarks**

Defines the starting point of a cubic bezier curve in the coordinate space of the parent element. If the parent is not a VML element, the default [unit](msdn-online-vml-units.md) is a pixel (but in, cm, mm, pt, pc may also be specified). Default is 0,0.

*VML Standard Attribute*

**Example**

The curve is smiling. It starts at the left and ends at the right. The two control points are situated along the way so as to pull the curve down to give the appearance of a smile.


```HTML
   <v:curve id="mycurve"
   from="10pt,10pt" to="100pt,10pt"
   control1="40pt,10pt" control2="70pt,10pt">
   </v:curve>
```



 

 
