---
description: The following functions are implemented in the Ws2\_32.dll, and are intended to be used by applications that install Windows Sockets transport and namespace service providers on a computer.
ms.assetid: 3289737a-77b6-45d1-9c0a-3ed05b3475c2
title: Installation and Configuration Functions
ms.topic: reference
ms.date: 05/31/2018
---

# Installation and Configuration Functions

The following functions are implemented in the Ws2\_32.dll, and are intended to be used by applications that install Windows Sockets transport and namespace service providers on a computer. These functions neither affect currently running applications, nor are the changes made by these functions visible to currently running applications.

For all providers, a provider identifier is a GUID which is generated by the developer of the provider (using the Uuidgen.exe utility) and supplied to Ws2\_32.dll.



| Function                                                                      | Description                                                                                                                                              |
|-------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------|
| [**WSCDeinstallProvider**](/windows/desktop/api/Ws2spi/nf-ws2spi-wscdeinstallprovider)                        | Removes a transport service provider from the registry.                                                                                                  |
| [**WSCDeinstallProvider32**](/windows/desktop/api/Ws2spi/nf-ws2spi-wscdeinstallprovider32)                      | Removes the specified 32-bit transport service provider from the registry on a 64-bit platform.                                                          |
| [**WSCEnumProtocols**](/windows/desktop/api/Ws2spi/nf-ws2spi-wscenumprotocols)                                | Retrieves information about available transport protocols.                                                                                               |
| [**WSCEnumProtocols32**](/windows/desktop/api/Ws2spi/nf-ws2spi-wscenumprotocols32)                              | Retrieves information about available transport protocols in the 32-bit catalog on 64-bit platforms.                                                     |
| [**WSCInstallProvider**](/windows/desktop/api/Ws2spi/nf-ws2spi-wscinstallprovider)                            | Registers a new transport service provider.                                                                                                              |
| [**WSCInstallProvider64\_32**](/windows/desktop/api/Ws2spi/nf-ws2spi-wscinstallprovider64_32)                   | Registers a new transport service provider into the 32-bit and 64-bit system configuration databases on a 64-bit platform.                               |
| [**WSCInstallProviderAndChains**](/windows/desktop/api/Ws2spi/nf-ws2spi-wscinstallproviderandchains)            | Registers a new 32-bit transport service provider as well as its specific protocol chains into the system configuration database on a 32-bit platform.   |
| [**WSCInstallProviderAndChains64\_32**](/windows/desktop/api/Ws2spi/nf-ws2spi-wscinstallproviderandchains64_32) | Registers a new transport provider and its specific protocol chains into both the 32-bit and 64-bit system configuration databases on a 64-bit platform. |



 

 

 



