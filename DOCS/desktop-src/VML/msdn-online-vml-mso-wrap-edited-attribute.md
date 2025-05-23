---
title: VML MSO-Wrap-Edited Attribute
description: VML MSO-Wrap-Edited Attribute
ms.assetid: cb0e8618-e649-4a3c-9433-2be77c4b65f9
ms.topic: reference
ms.date: 05/31/2018
---

# VML MSO-Wrap-Edited Attribute

This topic describes VML, a feature that is deprecated as of Windows Internet Explorer 9. Webpages and applications that rely on VML should be migrated to SVG or other widely supported standards.

> [!Note]  
> As of December 2011, this topic has been archived. As a result, it is no longer actively maintained. For more information, see [Archived Content](/previous-versions/windows/internet-explorer/ie-developer/). For information, recommendations, and guidance regarding the current version of Windows Internet Explorer, see [Internet Explorer Developer Center](https://msdn.microsoft.com/ie/).

 

Determines whether the wrap coordinates were customized by the user. Read/write. **VgTriState**.

**Applies To**

[Shape](shape-element--vml.md)

**Tag Syntax**

<v: *element* style="mso-wrap-edited: *expression* ">

**Remarks**

If the wrap coordinates are generated by an editor, this attribute is **True**; otherwise they were customized by a user.

*Microsoft Office Extensions Attribute*

**Example**

The shape's wrap coordinates were generated by a shape editor.


```HTML
   <v:shape id="rect01"
   fillcolor="red" strokecolor="red"
   coordorigin="-500 -500" coordsize="1000 1000"
   style="position:relative;top:0;left:0;width:100pt;height:100pt;mso-wrap-edited:True"
   path="m 1,1 l 1,200, 200,200, 200,1 x e">
   </v:shape>
```



 

 
