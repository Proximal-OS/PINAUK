---
description: Implements the Digest Access protocol, a lightweight authentication protocol for use with Hypertext Transfer Protocol or Simple Authentication Security Layer.
ms.assetid: '0b7d67c9-00ac-4b04-bf8e-97aaf1020108'
title: Microsoft Digest SSP
ms.topic: reference
ms.date: 09/14/2022
---

# Microsoft Digest SSP

Microsoft Digest is a [*security support provider*](../secgloss/s-gly.md) (SSP) that implements the Digest Access protocol, a lightweight authentication protocol for parties involved in Hypertext Transfer Protocol (HTTP) or Simple Authentication Security Layer (SASL) based communications.

Microsoft Digest provides a simple challenge response mechanism for authenticating clients. This SSP is intended for use by client/server applications using HTTP or SASL based communications.

> [!NOTE]
> Starting in Windows 11 22H2, Microsoft is deprecating Microsoft Digest, also known as wDigest. We will continue to support Microsoft Digest on supported versions of Windows. Future versions of Windows will include limited capabilities for Microsoft Digest, and eventually Microsoft Digest will no longer be supported on Windows.

> [!IMPORTANT]
> Digest authentication is not supported across forests.

The following sections provide information about Microsoft Digest SSP.

- [The Digest Access Protocol](the-digest-access-protocol.md)
- [Quality of Protection and Ciphers](quality-of-protection-and-ciphers.md)
- [Microsoft Digest Authentication](microsoft-digest-authentication.md)
- [IETF Specifications for Microsoft Digest SSP](ietf-specifications-for-microsoft-digest-ssp.md)
