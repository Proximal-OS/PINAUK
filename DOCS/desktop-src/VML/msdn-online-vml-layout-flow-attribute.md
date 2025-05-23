---
title: VML Layout-Flow Attribute
description: VML Layout-Flow Attribute
ms.assetid: 63b06dcb-5179-4046-9e02-4441d0d7bcd6
ms.topic: reference
ms.date: 05/31/2018
---

# VML Layout-Flow Attribute

This topic describes VML, a feature that is deprecated as of Windows Internet Explorer 9. Webpages and applications that rely on VML should be migrated to SVG or other widely supported standards.

> [!Note]  
> As of December 2011, this topic has been archived. As a result, it is no longer actively maintained. For more information, see [Archived Content](/previous-versions/windows/internet-explorer/ie-developer/). For information, recommendations, and guidance regarding the current version of Windows Internet Explorer, see [Internet Explorer Developer Center](https://msdn.microsoft.com/ie/).

 

Determines the flow of the text layout in a textbox. Read/write. **String**.

**Applies To**

[TextBox](msdn-online-vml-textbox-element.md)

**Tag Syntax**

<v: *element* style="layout-flow: *expression* ">

**Remarks**

Values include:



| Value                  | Description                                 |
|------------------------|---------------------------------------------|
| horizontal             | Text is displayed horizontally. Default.    |
| vertical               | Text is displayed vertically.               |
| vertical-ideographic   | Ideographic text is displayed vertically.   |
| horizontal-ideographic | Ideographic text is displayed horizontally. |



 

*VML Standard Attribute*

**Example**

The text flow in the textbox will flow vertically.


```HTML
   <v:shape id="rect01"
   coordorigin="0 0" coordsize="200 200"
   strokecolor="red" fillcolor="red"
   style="top:1;left:1;width:50;height:50"
   path="m 1,1 l 1,200, 200,200, 200,1 x e">
   <textbox string="VML text" layout-flow="vertical"/>
   </v:shape>
```



 

 
