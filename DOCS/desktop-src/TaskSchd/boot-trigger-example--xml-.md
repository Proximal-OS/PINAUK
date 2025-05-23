---
title: Boot Trigger Example (XML)
description: The XML in this example defines a task that starts Notepad when the system is booted.
ms.assetid: 6dd7155c-6163-4408-9cef-c313134beeb0
ms.topic: reference
ms.date: 05/31/2018
topic_type: 
- kbArticle
api_name: 
api_type: 
api_location: 
---

# Boot Trigger Example (XML)

The XML in this example defines a task that starts Notepad when the system is booted.

To register a task that is defined in XML, you can use either the [**ITaskFolder::RegisterTask**](/windows/desktop/api/taskschd/nf-taskschd-itaskfolder-registertask) function ([**TaskFolder.RegisterTask**](taskfolder-registertask.md) for scripting) or the Schtasks.exe command-line tool. If you use the Schtasks.exe tool (located in the C:\\Windows\\System32 directory), then you can use the following command to register the task: **schtasks /create /XML** *\<path to the XML file containing the task definition\>* **/tn** *\<task name\>*.

## To define a task to start Notepad on system boot

The following XML example shows how to define a task with a single execution action (starting Notepad), a single boot trigger that starts the task when the system is booted, and several other task settings that affect how the task is handled by the Task Scheduler.


```XML
<?xml version="1.0" ?>
<!--
This sample schedules a task to start notepad.exe when
the system is booted.
-->
<Task xmlns="http://schemas.microsoft.com/windows/2004/02/mit/task">
    <RegistrationInfo>
        <Date>2005-10-11T13:21:17-08:00</Date>
        <Author>AuthorName</Author>
        <Version>1.0.0</Version>
        <Description>Starts Notepad on system boot.</Description>
    </RegistrationInfo>
    <Triggers>
        <BootTrigger>
            <StartBoundary>2005-10-11T13:21:17-08:00</StartBoundary>
            <EndBoundary>2006-01-01T00:00:00-08:00</EndBoundary>
            <Enabled>true</Enabled>
            <ExecutionTimeLimit>PT5M</ExecutionTimeLimit>
        </BootTrigger>
    </Triggers>
    <Principals>
        <Principal>
            <UserId>Administrator</UserId>
            <LogonType>InteractiveToken</LogonType>
        </Principal>
    </Principals>
    <Settings>
        <Enabled>true</Enabled>
        <AllowStartOnDemand>true</AllowStartOnDemand>
        <AllowHardTerminate>true</AllowHardTerminate>
    </Settings>
    <Actions>
        <Exec>
            <Command>notepad.exe</Command>
        </Exec>
    </Actions>
</Task>
```



## TaskScheduler Schema Elements

Here are some important elements to keep in mind when using this example.

-   [**RegistrationInfo**](taskschedulerschema-registrationinfo-tasktype-element.md): Contains registration information about the task.
-   [**Triggers**](taskschedulerschema-triggers-tasktype-element.md): Defines the trigger that starts the task.
-   [**BootTrigger**](taskschedulerschema-boottrigger-triggergroup-element.md): Defines the boot trigger. In this case only two child elements are used: the start and end boundaries that specify when the trigger is activated and deactivated.
-   [**Principal**](taskschedulerschema-principal-principaltype-element.md): Defines the security context that a task runs under.
-   [**Settings**](taskschedulerschema-settings-tasktype-element.md): Defines the task settings that the Task Scheduler uses to perform the task.
-   [**Actions**](taskschedulerschema-actions-tasktype-element.md): Defines the actions the task performs. In this case, running Notepad.

## Related topics

<dl> <dt>

[Using the Task Scheduler](using-the-task-scheduler.md)
</dt> </dl>

 

 




