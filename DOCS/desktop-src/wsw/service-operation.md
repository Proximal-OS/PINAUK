---
title: Service Operation
description: Service operation is the code and the metadata associated with a specific operation of a service.
ms.assetid: 788940a0-b1d9-45d7-a4b5-6f0926026c7d
keywords:
- Service Operation Web Services for Windows
- WWSAPI
- WWS
ms.topic: reference
ms.date: 05/31/2018
---

# Service Operation

Service operation is the code and the metadata associated with a specific operation of a service.


In terms of WSDL, each wsdl:operation defined in the WSDL document for a given portType is a service operation.

``` syntax
<wsdl:definitions xmlns:soap="http://schemas.xmlsoap.org/wsdl/soap/" 
xmlns:wsu="http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-utility-1.0.xsd" 
xmlns:soapenc="http://schemas.xmlsoap.org/soap/encoding/" xmlns:tns="http://Example.org" 
xmlns:wsa="http://schemas.xmlsoap.org/ws/2004/08/addressing" xmlns:wsp="http://schemas.xmlsoap.org/ws/2004/09/policy" 
xmlns:wsap="http://schemas.xmlsoap.org/ws/2004/08/addressing/policy" xmlns:xsd="http://www.w3.org/2001/XMLSchema" 
xmlns:msc="http://schemas.microsoft.com/ws/2005/12/wsdl/contract" xmlns:wsaw="http://www.w3.org/2006/05/addressing/wsdl" 
xmlns:soap12="http://schemas.xmlsoap.org/wsdl/soap12/" xmlns:wsa10="http://www.w3.org/2005/08/addressing" 
xmlns:wsx="http://schemas.xmlsoap.org/ws/2004/09/mex" targetNamespace="http://Example.org" 
xmlns:wsdl="http://schemas.xmlsoap.org/wsdl/">
 <wsdl:portType name="ICalculator">
  <wsdl:operation name="Add">
   <wsdl:input wsaw:Action="http://Example.org/ICalculator/Add" 
   message="tns:ICalculator_Add_InputMessage" />
   <wsdl:output wsaw:Action="http://Example.org/ICalculator/AddResponse" 
   message="tns:ICalculator_Add_OutputMessage" />
  </wsdl:operation>
 </wsdl:portType>
</wsdl:definitions>
```

Each service operation within service model is given as a [**WS\_OPERATION\_DESCRIPTION**](/windows/desktop/api/WebServices/ns-webservices-ws_operation_description). WS\_OPERATION\_DESCRIPTION is generated by [wsutil.exe](web-service-compiler-tool.md).

For each wsdl:operation the tool generates a separate [**WS\_OPERATION\_DESCRIPTION**](/windows/desktop/api/WebServices/ns-webservices-ws_operation_description).

![Diagram showing how wsutil.exe generates a WS_CONTRACT_DESCRIPTION.](images/porttypetocontract.png)

``` syntax
static WS_OPERATION_DESCRIPTION serviceOperationsICalculator[] =
{
    {
        // Add Method
        &messageDescriptionAddICalculator,
        &messageDescriptionAddResponseICalculator,
        WsCountOf(parametersAddICalculator),
        ICalculator_Add_Stub 
    }
};
```

In terms of code each service operation has a function associated with it. The definition of this function is different for client and servers.

Service operations are classified into,

-   [Client Side Service Operations](client-side-service-operations.md)
-   [Server Side Service Operations](server-side-service-operations.md)

This classification is mainly based on the signature layout of the server and the client side implementations of service operations.

See also, [WSDL support section](wsdl-support.md).

The following enumerations are used with service operations:

-   [**WS\_PARAMETER\_TYPE**](/windows/desktop/api/WebServices/ne-webservices-ws_parameter_type)
-   [**WS\_SERVICE\_CANCEL\_REASON**](/windows/desktop/api/WebServices/ne-webservices-ws_service_cancel_reason)
-   [**WS\_SERVICE\_OPERATION\_MESSAGE\_OPTION**](/windows/win32/api/webservices/ne-webservices-ws_charset)

The following structures are used with service operations:

-   [**WS\_MESSAGE\_DESCRIPTION**](/windows/desktop/api/WebServices/ns-webservices-ws_message_description)
-   [**WS\_OPERATION\_DESCRIPTION**](/windows/desktop/api/WebServices/ns-webservices-ws_operation_description)
-   [**WS\_PARAMETER\_DESCRIPTION**](/windows/desktop/api/WebServices/ns-webservices-ws_parameter_description)

 

 




