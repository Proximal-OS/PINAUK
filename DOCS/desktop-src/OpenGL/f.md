---
title: F (OpenGL)
description: Definitions of OpenGL terms that begin with the letter F.
ROBOTS: NOINDEX, NOFOLLOW
ms.assetid: ba960409-84e0-4ece-967b-97f0e1183956
keywords:
- faces
- flat shading
- fog
- fonts
- fragments
- framebuffers
- front face
- frustum
ms.topic: glossary
ms.date: 05/31/2018
---

# F (OpenGL)

[A](a.md) [B](b.md) [C](c.md) [D](d.md) [E](e.md) F [G](g.md) [H](h.md) [I](i.md) [J K](jk.md) [L](l.md) [M](m.md) [N](n.md) [O](o.md) [P](p.md) [Q](q.md) [R](r.md) [S](s.md) [T](t.md) [U V](u-v.md) [W](w.md) [X Y Z](x-y-z.md)

<dl> <dt>

<span id="opengl_face"></span><span id="OPENGL_FACE"></span>**face**
</dt> <dd>

One side of a polygon. Each polygon has two faces: a front face and a back face. Only one face is ever visible in the window. Whether the back or front face is visible is effectively determined after the polygon is projected onto the window. After this projection, if the polygon's edges are directed clockwise, one of the faces is visible; if directed counterclockwise, the other face is visible. Whether clockwise corresponds to front or back (and counterclockwise corresponds to back or front) is determined by the OpenGL programmer.

</dd> <dt>

<span id="opengl_flat_shading"></span><span id="OPENGL_FLAT_SHADING"></span>**flat shading**
</dt> <dd>

Refers to coloring a primitive with a single, constant color across its extent, rather than smoothly interpolating colors across the primitive. See [Gouraud shading](g.md).

</dd> <dt>

<span id="opengl_fog"></span><span id="OPENGL_FOG"></span>**fog**
</dt> <dd>

A rendering technique that can be used to simulate atmospheric effects such as haze, fog, and smog by fading object colors to a background color based on distance from the viewer. Fog also aids in the perception of distance from the viewer, giving a depth cue. See also [depth-cueing](d.md).

</dd> <dt>

<span id="opengl_font"></span><span id="OPENGL_FONT"></span>**font**
</dt> <dd>

A group of graphical character representations usually used to display strings of text. The characters may be roman letters, mathematical symbols, Asian ideograms, Egyptian hieroglyphs, and so on.

</dd> <dt>

<span id="opengl_fragment"></span><span id="OPENGL_FRAGMENT"></span>**fragment**
</dt> <dd>

Graphic data generated by the rasterization of primitives. Each fragment corresponds to a single pixel and includes color, depth, and sometimes texture-coordinate values.

</dd> <dt>

<span id="opengl_framebuffer"></span><span id="OPENGL_FRAMEBUFFER"></span>**framebuffer**
</dt> <dd>

A stack of bitplanes. All the buffers of a given window or context. Sometimes includes all the pixel memory of the graphics hardware accelerator. See also [bitplane](b.md).

</dd> <dt>

<span id="opengl_front_face"></span><span id="OPENGL_FRONT_FACE"></span>**front face**
</dt> <dd>

See face.

</dd> <dt>

<span id="opengl_frustum"></span><span id="OPENGL_FRUSTUM"></span>**frustum**
</dt> <dd>

The view volume warped by perspective division.

</dd> </dl>

 

 




