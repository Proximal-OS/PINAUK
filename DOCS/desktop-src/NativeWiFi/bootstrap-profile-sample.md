---
description: Used to authenticate to a wireless network for the first time before the computer has joined a domain.
ms.assetid: e1a5ce76-9761-4c65-8b26-a44bf2eb1835
title: Bootstrap profile sample
ms.topic: sample
ms.date: 05/31/2018
topic_type: 
- kbArticle
api_name: 
api_type: 
api_location: 
---

# Bootstrap profile sample

The Bootstrap profile sample can be used to authenticate to a wireless network for the first time before the computer has joined a domain.

This profile does not validate the certificates presented by the Remote Authentication Dial-In User Service (RADIUS) server, and should not be used after the machine is joined to a domain.

This sample is configured to use Wi-Fi Protected Access 2 security running in Enterprise mode (WPA2-Enterprise). Other security types can be used as long as the authentication method is PEAP-MSCHAPv2.

**Windows 7 and Windows Server 2008 R2 with the Wireless LAN Service installed:** Changes are implemented on Windows 7 and Windows Server 2008 R2 with the Wireless LAN Service installed to optimize wireless networking performance. The default setting for [**autoSwitch**](wlan-profileschema-wlanprofile-element.md#autoswitch) when this element is not set in a wireless LAN profile has changed. The default setting is changed to "false" on Windows 7 and Windows Server 2008 R2 with the Wireless LAN Service installed. The default setting was "true" on Windows Server 2008 and Windows Vista. Please refer to the [**autoSwitch**](wlan-profileschema-wlanprofile-element.md#autoswitch) schema element description for more information.

**Windows XP with SP3 and Wireless LAN API for Windows XP with SP2:** The [**name**](wlan-profileschema-wlanprofile-element.md#name) child of the [**WLANProfile**](wlan-profileschema-wlanprofile-element.md) element is ignored. The name of the profile, as stored in the profile store, is derived from the [**name**](wlan-profileschema-ssid-ssidconfig-element.md#name) child of the [**SSID**](wlan-profileschema-ssid-ssidconfig-element.md) element. The [**cacheUserData**](onexschema-onex-element.md#cacheuserdata), [**authMode**](onexschema-onex-element.md#authmode), and [**singleSignOn**](onexschema-singlesignon-onex-element.md) children of the [**OneX**](onexschema-onex-element.md) element are not supported, and should be removed from the profile before use.

``` syntax
<?xml version="1.0" encoding="US-ASCII"?>
<WLANProfile xmlns="https://www.microsoft.com/networking/WLAN/profile/v1">
    <name>SampleBootstrap</name>
    <SSIDConfig>
        <SSID>
            <name>SampleBootstrap</name>
        </SSID>
    </SSIDConfig>
    <connectionType>ESS</connectionType>
    <connectionMode>auto</connectionMode>
    <autoSwitch>false</autoSwitch>
    <MSM>
        <security>
            <authEncryption>
                <authentication>WPA2</authentication>
                <encryption>AES</encryption>
                <useOneX>true</useOneX>
            </authEncryption>
            <OneX xmlns="https://www.microsoft.com/networking/OneX/v1">
                <cacheUserData>true</cacheUserData>
                <authMode>machineOrUser</authMode>
                <singleSignOn>
                    <type>preLogon</type>
                    <maxDelay>10</maxDelay>
                </singleSignOn>
               <EAPConfig>
                    <EapHostConfig xmlns="https://www.microsoft.com/provisioning/EapHostConfig" 
                                   xmlns:eapCommon="https://www.microsoft.com/provisioning/EapCommon" 
                                   xmlns:baseEap="https://www.microsoft.com/provisioning/BaseEapMethodConfig">
                        <EapMethod>
                            <eapCommon:Type>25</eapCommon:Type> 
                            <eapCommon:AuthorId>0</eapCommon:AuthorId> 
                       </EapMethod>
                       <Config xmlns:baseEap="https://www.microsoft.com/provisioning/BaseEapConnectionPropertiesV1" 
                               xmlns:msPeap="https://www.microsoft.com/provisioning/MsPeapConnectionPropertiesV1" 
                               xmlns:msChapV2="https://www.microsoft.com/provisioning/MsChapV2ConnectionPropertiesV1">
                           <baseEap:Eap>
                               <baseEap:Type>25</baseEap:Type> 
                               <msPeap:EapType>
                                   <msPeap:ServerValidation>
                                       <msPeap:DisableUserPromptForServerValidation>false</msPeap:DisableUserPromptForServerValidation> 
                                       <msPeap:TrustedRootCA /> 
                                   </msPeap:ServerValidation>
                                   <msPeap:FastReconnect>true</msPeap:FastReconnect> 
                                   <msPeap:InnerEapOptional>0</msPeap:InnerEapOptional> 
                                   <baseEap:Eap>
                                       <baseEap:Type>26</baseEap:Type> 
                                       <msChapV2:EapType>
                                           <msChapV2:UseWinLogonCredentials>true</msChapV2:UseWinLogonCredentials> 
                                       </msChapV2:EapType>
                                   </baseEap:Eap>
                                   <msPeap:EnableQuarantineChecks>false</msPeap:EnableQuarantineChecks> 
                                   <msPeap:RequireCryptoBinding>false</msPeap:RequireCryptoBinding> 
                                   <msPeap:PeapExtensions /> 
                               </msPeap:EapType>
                           </baseEap:Eap>
                       </Config>
                   </EapHostConfig>
                </EAPConfig>
               </EAPConfig>
           </OneX>
        </security>
    </MSM>
</WLANProfile>
```

## Related topics

* [Wireless profile samples](wireless-profile-samples.md)
* [Wireless Access Deployment](/windows-server/networking/core-network-guide/cncg/wireless/e-wireless-access-deployment)
