---
title: Reader Response to ASF Features
description: Reader Response to ASF Features
ms.assetid: 0cf800ca-63e8-47e2-a2fc-7ba6789fb4bb
keywords:
- Windows Media Format SDK,reader responses to ASF features
- Advanced Systems Format (ASF),reader responses to features
- ASF (Advanced Systems Format),reader responses to features
- reader responses to ASF features
ms.topic: reference
ms.date: 4/26/2023
ms.custom: UpdateFrequency5
---

# Reader Response to ASF Features

\[The feature associated with this page, [Windows Media Format 11 SDK](/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](/windows/win32/medfound/source-reader) and [Sink Writer](/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Most of the special ASF file features can be set in files to interact with custom playing applications designed to handle them. However, some of the features have built-in support in the reader object.

The reader object will automatically select streams from sets that are mutually exclusive by bit rate. This special case is referred to as multiple bit rate (MBR). The stream the reader selects is based on the bit rate of the stream. The stream number and the order in which it was added to the mutual exclusion object are irrelevant to the automatic selection. If a file includes more than one set of streams mutually exclusive by bit rate, the reader will select streams based on calculating the best use of the available bandwidth.

Language-based mutual exclusion is set using an output setting, before playback. If you combine both language and bit-rate-based mutual exclusion, you should group the bit-rate-based mutually exclusive streams by language and then make the groups mutually exclusive by language. The reader will check the language first, and then determine which bit rate to use.

Stream prioritization is set using an array of records. The records in the array are in descending order of priority. The last stream in the array is the first that will be dropped by the reader.

## Related topics

<dl> <dt>

[**ASF File Features**](asf-file-features.md)
</dt> <dt>

[**Mutual Exclusion**](mutual-exclusion.md)
</dt> <dt>

[**Stream Prioritization**](stream-prioritization.md)
</dt> </dl>

 

 




