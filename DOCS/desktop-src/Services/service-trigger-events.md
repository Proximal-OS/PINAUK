---
description: A service can register to be started or stopped when a trigger event occurs.
ms.assetid: ca02a3ae-b16a-4427-b6db-b935c9cf23b3
title: Service Trigger Events
ms.topic: concept-article
ms.date: 05/31/2018
---

# Service Trigger Events

A service can register to be started or stopped when a trigger event occurs. This eliminates the need for services to start when the system starts, or for services to poll or actively wait for an event; a service can start when it is needed, instead of starting automatically whether or not there is work to do. Examples of predefined trigger events include arrival of a device of a specified device interface class or availability of a particular firewall port. A service can also register for a custom trigger event generated by an [Event Tracing for Windows](../etw/event-tracing-portal.md) (ETW) provider.

**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** Service trigger events are not supported until Windows Server 2008 R2 and Windows 7.

A trigger consists of a trigger event type, a trigger event subtype, the action to be taken in response to the trigger event, and (for certain trigger event types) one or more trigger-specific data items. The subtype and the trigger-specific data items together specify the conditions for notifying the service of the event. The format of a data item depends on the trigger event type; a data item can be binary data, a string, or a multistring. Strings must be Unicode; ANSI strings are not supported.

To register for trigger events, the service calls [**ChangeServiceConfig2**](/windows/desktop/api/Winsvc/nf-winsvc-changeserviceconfig2a) with **SERVICE\_CONFIG\_TRIGGER\_INFO** and supplies a [**SERVICE\_TRIGGER\_INFO**](/windows/desktop/api/winsvc/ns-winsvc-service_trigger_info) structure. The **SERVICE\_TRIGGER\_INFO** structure points to an array of [**SERVICE\_TRIGGER**](/windows/desktop/api/winsvc/ns-winsvc-service_trigger) structures, each specifying one trigger.

The specified trigger action is taken if the trigger condition is true when the system starts, or if the trigger condition becomes true while the system is running. For example, if a service registers to be started when a particular device is available, the service is started when the system starts if the device is already plugged in to the computer; the service is started when the device arrives if the user plugs in the device while the system is running.

If a trigger has trigger-specific data items, the trigger action is taken only if the data item that accompanies the trigger event matches one of the data items that the service specified with the trigger. Binary data matching is done by bitwise comparison. String matching is case-insensitive. If the data item is a multistring, all strings in the multistring must match.

When a service is started in response to a trigger event, the service receives **SERVICE\_TRIGGER\_STARTED\_ARGUMENT** as *argv*\[1\] in its [*ServiceMain*](/windows/win32/api/winsvc/nc-winsvc-lpservice_main_functiona) callback function. *Argv*\[0\] is always the short name of the service.

A service that registers to be started in response to a trigger event might stop itself after an idle time-out when the service has no work to do. A service that stops itself must be prepared to handle **SERVICE\_CONTROL\_TRIGGEREVENT** control requests that arrive while the service is stopping itself. The SCM sends a **SERVICE\_CONTROL\_TRIGGEREVENT** control request whenever a new trigger event occurs while the service is in the running state. To avoid losing trigger events, the service should return **ERROR\_SHUTDOWN\_IN\_PROGRESS** for any **SERVICE\_CONTROL\_TRIGGEREVENT** control request that arrives while the service is transitioning from running to stopped. This instructs the SCM to queue trigger events and wait for the service to enter the stopped state. The SCM then takes the action associated with the queued trigger event, such as starting the service.

When the service is ready to handle trigger events again, it sets **SERVICE\_ACCEPT\_TRIGGEREVENT** in its controls-accepted mask in a call to [**SetServiceStatus**](/windows/desktop/api/Winsvc/nf-winsvc-setservicestatus). This is usually done when the service calls **SetServiceStatus** with **SERVICE\_RUNNING**. The SCM then issues a **SERVICE\_CONTROL\_TRIGGEREVENT** request for each queued trigger event until the queue is empty.

A service that has dependent services running cannot be stopped in response to a trigger event.

Trigger-start and trigger-stop requests are not guaranteed under low memory conditions.

Use the [**QueryServiceConfig2**](/windows/desktop/api/Winsvc/nf-winsvc-queryserviceconfig2a) function to retrieve a service’s trigger event configuration.

The SC tool (sc.exe) can be used to configure or query a service’s trigger events at the command prompt. Use the **triggerinfo** option to configure a service to start or stop in response to a trigger event. Use the **qtriggerinfo** option to query the trigger configuration of a service.

The following example queries the trigger configuration of the W32time service, which is configured to start when the computer is joined to a domain and stop when the computer leaves the domain.

``` syntax
C:\>sc qtriggerinfo w32time
[SC] QueryServiceConfig2 SUCCESS

SERVICE_NAME: w32time

        START SERVICE
          DOMAIN JOINED STATUS         : 1ce20aba-9851-4421-9430-1ddeb766e809 [DOMAIN JOINED]
        STOP SERVICE
          DOMAIN JOINED STATUS         : ddaf516e-58c2-4866-9574-c3b615d42ea1 [NOT DOMAIN JOINED]
```

The following example queries the trigger configuration of the tablet input service, which is configured to start when a HID device with the **GUID** {4d1e55b2-f16f-11cf-88cb-001111000030} and any of the specified HID device IDs arrives.

``` syntax
C:\>sc qtriggerinfo tabletinputservice
[SC] QueryServiceConfig2 SUCCESS

SERVICE_NAME: tabletinputservice

        START SERVICE
          DEVICE INTERFACE ARRIVAL     : 4d1e55b2-f16f-11cf-88cb-001111000030 [INTERFACE CLASS GUID]
            DATA                       : HID_DEVICE_UP:000D_U:0001
            DATA                       : HID_DEVICE_UP:000D_U:0002
            DATA                       : HID_DEVICE_UP:000D_U:0003
            DATA                       : HID_DEVICE_UP:000D_U:0004
```

 

 
