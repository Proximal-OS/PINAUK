---
description: The following example contains a CMC renewal request. The example was generated by using the Certreq.exe and Certutil.exe tools. The .inf file used as input to Certreq.exe contains the following configuration.
ms.assetid: 45b8e5f1-93e0-4216-945a-221a22acfd68
title: CMC Renewal Request
ms.topic: reference
ms.date: 05/31/2018
---

# CMC Renewal Request

The following example contains a CMC renewal request. The example was generated by using the Certreq.exe and Certutil.exe tools. The .inf file used as input to Certreq.exe contains the following configuration.

``` syntax
[NewRequest]
RequestType=cmc
RenewalCert=248f7d3c00000000086e
```

The configuration specifies the type of request (CMC) and the serial number of the certificate upon which the request is based. This generates the following output.

``` syntax
PKCS7/CMS Message:
  CMSG_SIGNED(2)
  CMSG_SIGNED_DATA_CMS_VERSION(3)
  Content Type: 1.3.6.1.5.5.7.12.2 CMC Data

PKCS7 Message Content:
================ Begin Nesting Level 1 ================
CMS Certificate Request:
Tagged Attributes: 1

  Body Part Id: 2
  1.3.6.1.4.1.311.10.10.1 CMC Attributes
  Value[0]:
    Data Reference: 0
    Cert Reference[0]: 1
  1 attributes:

  Attribute[0]: 1.3.6.1.4.1.311.21.20 (Client Information)
    Value[0][0]:
    Unknown Attribute type
    Client Id: = 9
      (XECI_DISABLE -- 0)
      (XECI_XENROLL -- 1)
      (XECI_AUTOENROLL -- 2)
      (XECI_REQWIZARD -- 3)
      (XECI_CERTREQ -- 4)
    User: JDOMCSC\administrator
    Machine: vich3d.jdomcsc.nttest.microsoft.com
    Process: certreq
    0000  30 48 02 01 09 0c 23 76  69 63 68 33 64 2e 6a 64   0H....#vich3d.jd
    0010  6f 6d 63 73 63 2e 6e 74  74 65 73 74 2e 6d 69 63   omcsc.nttest.mic
    0020  72 6f 73 6f 66 74 2e 63  6f 6d 0c 15 4a 44 4f 4d   rosoft.com..JDOM
    0030  43 53 43 5c 61 64 6d 69  6e 69 73 74 72 61 74 6f   CSC\administrato
    0040  72 0c 07 63 65 72 74 72  65 71                     r..certreq


Tagged Requests: 1
  CMC_TAGGED_CERT_REQUEST_CHOICE:
  Body Part Id: 1
================ Begin Nesting Level 2 ================
Element 0:
PKCS10 Certificate Request:
Version: 1
Subject:
    EMPTY

Public Key Algorithm:
    Algorithm ObjectId: 1.2.840.113549.1.1.1 RSA (RSA_SIGN)
    Algorithm Parameters:
    05 00
Public Key Length: 1024 bits
Public Key: UnusedBits = 0
    0000  30 81 89 02 81 81 00 b4  04 6e 1a b2 17 f6 bf d4
    0010  cb 51 17 cc a5 39 bd 54  ac 52 92 e9 0e bf d6 c4
    0020  0c df 32 e9 eb e3 b9 a1  30 5f 8e cd da d8 e0 6a
    0030  2c 1b 01 17 fc aa 31 04  42 11 cf 29 8f a2 64 03
    0040  3d 9d 23 e2 76 58 1c 75  47 bc e1 9b 41 79 c4 5b
    0050  40 65 9f 56 b1 a6 d2 74  b2 e7 2e 5e 2f 62 fc 7e
    0060  76 c8 81 cd d4 ca 0d bc  35 ba 59 57 61 11 12 14
    0070  74 34 88 3f 62 d3 26 fb  93 ce a7 ca 0e 5f 96 d1
    0080  d4 9e 70 8f be 73 bd 02  03 01 00 01
Request Attributes: 5
  5 attributes:

  Attribute[0]: 1.3.6.1.4.1.311.13.2.3 (OS Version)
    Value[0][0]:
        6.0.5361.2
    0000  16 0a 36 2e 30 2e 35 33  36 31 2e 32               ..6.0.5361.2

  Attribute[1]: 1.2.840.113549.1.9.14 (Certificate Extensions)
    Value[1][0]:
    Unknown Attribute type
Certificate Extensions: 2
    2.5.29.14: Flags = 0, Length = 16
    Subject Key Identifier
        d2 91 95 03 6a b4 a6 a7 43 cd bd 35 0e 1c 80 58 91 e3 9a 33

    0000  04 14 d2 91 95 03 6a b4  a6 a7 43 cd bd 35 0e 1c   ......j...C..5..
    0010  80 58 91 e3 9a 33                                  .X...3

    2.5.29.15: Flags = 1(Critical), Length = 4
    Key Usage
        Digital Signature (80)

    0000  03 02 07 80                                        ....

    0000  30 2f 30 1d 06 03 55 1d  0e 04 16 04 14 d2 91 95   0/0...U.........
    0010  03 6a b4 a6 a7 43 cd bd  35 0e 1c 80 58 91 e3 9a   .j...C..5...X...
    0020  33 30 0e 06 03 55 1d 0f  01 01 ff 04 04 03 02 07   30...U..........
    0030  80                                                 .

  Attribute[2]: 1.3.6.1.4.1.311.21.20 (Client Information)
    Value[2][0]:
    Unknown Attribute type
    Client Id: = 9
      (XECI_DISABLE -- 0)
      (XECI_XENROLL -- 1)
      (XECI_AUTOENROLL -- 2)
      (XECI_REQWIZARD -- 3)
      (XECI_CERTREQ -- 4)
    User: JDOMCSC\administrator
    Machine: vich3d.jdomcsc.nttest.microsoft.com
    Process: certreq
    0000  30 48 02 01 09 0c 23 76  69 63 68 33 64 2e 6a 64   0H....#vich3d.jd
    0010  6f 6d 63 73 63 2e 6e 74  74 65 73 74 2e 6d 69 63   omcsc.nttest.mic
    0020  72 6f 73 6f 66 74 2e 63  6f 6d 0c 15 4a 44 4f 4d   rosoft.com..JDOM
    0030  43 53 43 5c 61 64 6d 69  6e 69 73 74 72 61 74 6f   CSC\administrato
    0040  72 0c 07 63 65 72 74 72  65 71                     r..certreq

  Attribute[3]: 1.3.6.1.4.1.311.13.2.2 (Enrollment CSP)
    Value[3][0]:
    Unknown Attribute type
    CSP Provider Info
    KeySpec = 2
    Provider = Microsoft Strong Cryptographic Provider
    Signature: UnusedBits=0
    0000  30 56 02 01 02 1e 4e 00  4d 00 69 00 63 00 72 00   0V....N.M.i.c.r.
    0010  6f 00 73 00 6f 00 66 00  74 00 20 00 53 00 74 00   o.s.o.f.t. .S.t.
    0020  72 00 6f 00 6e 00 67 00  20 00 43 00 72 00 79 00   r.o.n.g. .C.r.y.
    0030  70 00 74 00 6f 00 67 00  72 00 61 00 70 00 68 00   p.t.o.g.r.a.p.h.
    0040  69 00 63 00 20 00 50 00  72 00 6f 00 76 00 69 00   i.c. .P.r.o.v.i.
    0050  64 00 65 00 72 03 01 00                            d.e.r...

  Attribute[4]: 1.3.6.1.4.1.311.13.1
    Value[4][0]:
    Unknown Attribute type
Renewal Certificate:
================ Begin Nesting Level 3 ================
X509 Certificate:
Version: 3
Serial Number: 248f7d3c00000000086e
    6e 08 00 00 00 00 3c 7d  8f 24
Signature Algorithm:
    Algorithm ObjectId: 1.2.840.10045.4.3.3 ECDSA SHA-384(certlib) (sha384ECDSA)
    Algorithm Parameters: NULL
Issuer:
    CN=JDOMCSC Longhorn Enterprise Root CA
    O=Microsoft
    [0,0]: CERT_RDN_PRINTABLE_STRING, Length = 9 (9/64 Characters)
        2.5.4.10 Organization (O)="Microsoft"

        4d 69 63 72 6f 73 6f 66  74                        Microsoft

        4d 00 69 00 63 00 72 00  6f 00 73 00 6f 00 66 00   M.i.c.r.o.s.o.f.
        74 00                                              t.

    [1,0]: CERT_RDN_PRINTABLE_STRING, Length = 35 (35/64 Characters)
        2.5.4.3 Common Name (CN)="JDOMCSC Longhorn Enterprise Root CA"

        4a 44 4f 4d 43 53 43 20  4c 6f 6e 67 68 6f 72 6e   JDOMCSC Longhorn
        20 45 6e 74 65 72 70 72  69 73 65 20 52 6f 6f 74    Enterprise Root
        20 43 41                                            CA

        4a 00 44 00 4f 00 4d 00  43 00 53 00 43 00 20 00   J.D.O.M.C.S.C. .
        4c 00 6f 00 6e 00 67 00  68 00 6f 00 72 00 6e 00   L.o.n.g.h.o.r.n.
        20 00 45 00 6e 00 74 00  65 00 72 00 70 00 72 00    .E.n.t.e.r.p.r.
        69 00 73 00 65 00 20 00  52 00 6f 00 6f 00 74 00   i.s.e. .R.o.o.t.
        20 00 43 00 41 00                                   .C.A.


NotBefore: 4/24/2006 4:13 PM
NotAfter: 4/24/2007 4:13 PM

Subject:
    E=Administrator@jdomcsc.nttest.microsoft.com
    CN=Administrator
    CN=Users
    DC=jdomcsc
    DC=nttest
    DC=microsoft
    DC=com
    [0,0]: CERT_RDN_IA5_STRING, Length = 3 (3/128 Characters)
        0.9.2342.19200300.100.1.25 Domain Component (DC)="com"

        63 6f 6d                                           com

        63 00 6f 00 6d 00                                  c.o.m.

    [1,0]: CERT_RDN_IA5_STRING, Length = 9 (9/128 Characters)
        0.9.2342.19200300.100.1.25 Domain Component (DC)="microsoft"

        6d 69 63 72 6f 73 6f 66  74                        microsoft

        6d 00 69 00 63 00 72 00  6f 00 73 00 6f 00 66 00   m.i.c.r.o.s.o.f.
        74 00                                              t.

    [2,0]: CERT_RDN_IA5_STRING, Length = 6 (6/128 Characters)
        0.9.2342.19200300.100.1.25 Domain Component (DC)="nttest"

        6e 74 74 65 73 74                                  nttest

        6e 00 74 00 74 00 65 00  73 00 74 00               n.t.t.e.s.t.

    [3,0]: CERT_RDN_IA5_STRING, Length = 7 (7/128 Characters)
        0.9.2342.19200300.100.1.25 Domain Component (DC)="jdomcsc"

        6a 64 6f 6d 63 73 63                               jdomcsc

        6a 00 64 00 6f 00 6d 00  63 00 73 00 63 00         j.d.o.m.c.s.c.

    [4,0]: CERT_RDN_PRINTABLE_STRING, Length = 5 (5/64 Characters)
        2.5.4.3 Common Name (CN)="Users"

        55 73 65 72 73                                     Users

        55 00 73 00 65 00 72 00  73 00                     U.s.e.r.s.

    [5,0]: CERT_RDN_PRINTABLE_STRING, Length = 13 (13/64 Characters)
        2.5.4.3 Common Name (CN)="Administrator"

        41 64 6d 69 6e 69 73 74  72 61 74 6f 72            Administrator

        41 00 64 00 6d 00 69 00  6e 00 69 00 73 00 74 00   A.d.m.i.n.i.s.t.
        72 00 61 00 74 00 6f 00  72 00                     r.a.t.o.r.

    [6,0]: CERT_RDN_IA5_STRING, Length = 42 (42/128 Characters)
        1.2.840.113549.1.9.1 Email Address (E)="Administrator@jdomcsc.nttest.microsoft.com"

        41 64 6d 69 6e 69 73 74  72 61 74 6f 72 40 6a 64   Administrator@jd
        6f 6d 63 73 63 2e 6e 74  74 65 73 74 2e 6d 69 63   omcsc.nttest.mic
        72 6f 73 6f 66 74 2e 63  6f 6d                     rosoft.com

        41 00 64 00 6d 00 69 00  6e 00 69 00 73 00 74 00   A.d.m.i.n.i.s.t.
        72 00 61 00 74 00 6f 00  72 00 40 00 6a 00 64 00   r.a.t.o.r.@.j.d.
        6f 00 6d 00 63 00 73 00  63 00 2e 00 6e 00 74 00   o.m.c.s.c...n.t.
        74 00 65 00 73 00 74 00  2e 00 6d 00 69 00 63 00   t.e.s.t...m.i.c.
        72 00 6f 00 73 00 6f 00  66 00 74 00 2e 00 63 00   r.o.s.o.f.t...c.
        6f 00 6d 00                                        o.m.


Public Key Algorithm:
    Algorithm ObjectId: 1.2.840.113549.1.1.1 RSA (RSA_SIGN)
    Algorithm Parameters:
    05 00
Public Key Length: 1024 bits
Public Key: UnusedBits = 0
    0000  30 81 89 02 81 81 00 91  9d 0a 8e 1d 7a 21 e9 ba
    0010  34 c7 54 1d 79 c9 35 91  e9 68 cb 3d ef 2b 4d a6
    0020  52 31 f4 95 31 44 02 75  cd d5 34 ec a2 32 0c 4f
    0030  97 b7 6c 87 ca b2 b0 5b  53 a6 74 b7 1e 69 a7 d8
    0040  c3 3d 03 20 14 5a cb 40  ed f8 5e ee c4 be 97 62
    0050  70 44 2f 47 1e 3e b5 61  33 d9 02 c3 87 62 4e 74
    0060  26 ef fa 0b 06 d0 0c ec  68 fc 93 10 88 5b 70 8f
    0070  94 13 eb 6e 86 d4 b5 14  e8 6f 87 21 3d 1d 3e 16
    0080  d4 cf e7 19 70 c7 31 02  03 01 00 01
Certificate Extensions: 9
    1.3.6.1.4.1.311.20.2: Flags = 0, Length = a
    Certificate Template Name (Certificate Type)
        User

    0000  1e 08 00 55 00 73 00 65  00 72                     ...U.s.e.r

    2.5.29.37: Flags = 0, Length = 22
    Enhanced Key Usage
        Encrypting File System (1.3.6.1.4.1.311.10.3.4)
        Secure Email (1.3.6.1.5.5.7.3.4)
        Client Authentication (1.3.6.1.5.5.7.3.2)

    0000  30 20 06 0a 2b 06 01 04  01 82 37 0a 03 04 06 08   0 ..+.....7.....
    0010  2b 06 01 05 05 07 03 04  06 08 2b 06 01 05 05 07   +.........+.....
    0020  03 02                                              ..

    2.5.29.15: Flags = 0, Length = 4
    Key Usage
        Digital Signature, Key Encipherment (a0)

    0000  03 02 05 a0                                        ....

    1.2.840.113549.1.9.15: Flags = 0, Length = 3e
    SMIME Capabilities
        [1]SMIME Capability
             Object ID=1.2.840.113549.3.2
             Parameters=02 02 00 80
        [2]SMIME Capability
             Object ID=1.2.840.113549.3.4
             Parameters=02 02 00 80
        [3]SMIME Capability
             Object ID=1.3.14.3.2.7
             Parameters=02 01 38
        [4]SMIME Capability
             Object ID=1.2.840.113549.3.7
             Parameters=02 02 00 a8

    0000  30 3c 30 0e 06 08 2a 86  48 86 f7 0d 03 02 02 02   0<0...*.H.......
    0010  00 80 30 0e 06 08 2a 86  48 86 f7 0d 03 04 02 02   ..0...*.H.......
    0020  00 80 30 0a 06 05 2b 0e  03 02 07 02 01 38 30 0e   ..0...+......80.
    0030  06 08 2a 86 48 86 f7 0d  03 07 02 02 00 a8         ..*.H.........

    2.5.29.14: Flags = 0, Length = 16
    Subject Key Identifier
        60 8a b3 ff 41 13 ee 58 9d 66 8f b2 0e 72 da 5f 5f 30 9e 90

    0000  04 14 60 8a b3 ff 41 13  ee 58 9d 66 8f b2 0e 72   ..`...A..X.f...r
    0010  da 5f 5f 30 9e 90                                  .__0..

    2.5.29.35: Flags = 0, Length = 18
    Authority Key Identifier
        KeyID=16 a1 b0 9e 8f 4f ee 2e d4 25 07 90 2b 89 37 21 70 c7 d6 65

    0000  30 16 80 14 16 a1 b0 9e  8f 4f ee 2e d4 25 07 90   0........O...%..
    0010  2b 89 37 21 70 c7 d6 65                            +.7!p..e

    2.5.29.31: Flags = 0, Length = 166
    CRL Distribution Points
        [1]CRL Distribution Point
             Distribution Point Name:
                  Full Name:
                       URL=ldap:///CN=JDOMCSC%20Longhorn%20Enterprise%20Root%20CA,CN=JAYTEST7,CN=CDP,CN=Public%20Key%20Services,CN=Services,CN=Configuration,DC=jdomcsc,DC=nttest,DC=microsoft,DC=com?certificateRevocationList?base?objectClass=cRLDistributionPoint
                       URL=https://jaytest7.jdomcsc.nttest.microsoft.com/CertEnroll/JDOMCSC%20Longhorn%20Enterprise%20Root%20CA.crl

    0000  30 82 01 62 30 82 01 5e  a0 82 01 5a a0 82 01 56   0..b0..^...Z...V
    0010  86 81 ea 6c 64 61 70 3a  2f 2f 2f 43 4e 3d 4a 44   ...ldap:///CN=JD
    0020  4f 4d 43 53 43 25 32 30  4c 6f 6e 67 68 6f 72 6e   OMCSC%20Longhorn
    0030  25 32 30 45 6e 74 65 72  70 72 69 73 65 25 32 30   %20Enterprise%20
    0040  52 6f 6f 74 25 32 30 43  41 2c 43 4e 3d 4a 41 59   Root%20CA,CN=JAY
    0050  54 45 53 54 37 2c 43 4e  3d 43 44 50 2c 43 4e 3d   TEST7,CN=CDP,CN=
    0060  50 75 62 6c 69 63 25 32  30 4b 65 79 25 32 30 53   Public%20Key%20S
    0070  65 72 76 69 63 65 73 2c  43 4e 3d 53 65 72 76 69   ervices,CN=Servi
    0080  63 65 73 2c 43 4e 3d 43  6f 6e 66 69 67 75 72 61   ces,CN=Configura
    0090  74 69 6f 6e 2c 44 43 3d  6a 64 6f 6d 63 73 63 2c   tion,DC=jdomcsc,
    00a0  44 43 3d 6e 74 74 65 73  74 2c 44 43 3d 6d 69 63   DC=nttest,DC=mic
    00b0  72 6f 73 6f 66 74 2c 44  43 3d 63 6f 6d 3f 63 65   rosoft,DC=com?ce
    00c0  72 74 69 66 69 63 61 74  65 52 65 76 6f 63 61 74   rtificateRevocat
    00d0  69 6f 6e 4c 69 73 74 3f  62 61 73 65 3f 6f 62 6a   ionList?base?obj
    00e0  65 63 74 43 6c 61 73 73  3d 63 52 4c 44 69 73 74   ectClass=cRLDist
    00f0  72 69 62 75 74 69 6f 6e  50 6f 69 6e 74 86 67 68   ributionPoint.gh
    0100  74 74 70 3a 2f 2f 6a 61  79 74 65 73 74 37 2e 6a   ttp://jaytest7.j
    0110  64 6f 6d 63 73 63 2e 6e  74 74 65 73 74 2e 6d 69   domcsc.nttest.mi
    0120  63 72 6f 73 6f 66 74 2e  63 6f 6d 2f 43 65 72 74   crosoft.com/Cert
    0130  45 6e 72 6f 6c 6c 2f 4a  44 4f 4d 43 53 43 25 32   Enroll/JDOMCSC%2
    0140  30 4c 6f 6e 67 68 6f 72  6e 25 32 30 45 6e 74 65   0Longhorn%20Ente
    0150  72 70 72 69 73 65 25 32  30 52 6f 6f 74 25 32 30   rprise%20Root%20
    0160  43 41 2e 63 72 6c                                  CA.crl

    1.3.6.1.5.5.7.1.1: Flags = 0, Length = 185
    Authority Information Access
        [1]Authority Info Access
             Access Method=Certification Authority Issuer (1.3.6.1.5.5.7.48.2)
             Alternative Name:
                  URL=ldap:///CN=JDOMCSC%20Longhorn%20Enterprise%20Root%20CA,CN=AIA,CN=Public%20Key%20Services,CN=Services,CN=Configuration,DC=jdomcsc,DC=nttest,DC=microsoft,DC=com?cACertificate?base?objectClass=certificationAuthority
        [2]Authority Info Access
             Access Method=Certification Authority Issuer (1.3.6.1.5.5.7.48.2)
             Alternative Name:
                  URL=https://jaytest7.jdomcsc.nttest.microsoft.com/CertEnroll/JAYTEST7.jdomcsc.nttest.microsoft.com_JDOMCSC%20Longhorn%20Enterprise%20Root%20CA.crt

    0000  30 82 01 81 30 81 e1 06  08 2b 06 01 05 05 07 30   0...0....+.....0
    0010  02 86 81 d4 6c 64 61 70  3a 2f 2f 2f 43 4e 3d 4a   ....ldap:///CN=J
    0020  44 4f 4d 43 53 43 25 32  30 4c 6f 6e 67 68 6f 72   DOMCSC%20Longhor
    0030  6e 25 32 30 45 6e 74 65  72 70 72 69 73 65 25 32   n%20Enterprise%2
    0040  30 52 6f 6f 74 25 32 30  43 41 2c 43 4e 3d 41 49   0Root%20CA,CN=AI
    0050  41 2c 43 4e 3d 50 75 62  6c 69 63 25 32 30 4b 65   A,CN=Public%20Ke
    0060  79 25 32 30 53 65 72 76  69 63 65 73 2c 43 4e 3d   y%20Services,CN=
    0070  53 65 72 76 69 63 65 73  2c 43 4e 3d 43 6f 6e 66   Services,CN=Conf
    0080  69 67 75 72 61 74 69 6f  6e 2c 44 43 3d 6a 64 6f   iguration,DC=jdo
    0090  6d 63 73 63 2c 44 43 3d  6e 74 74 65 73 74 2c 44   mcsc,DC=nttest,D
    00a0  43 3d 6d 69 63 72 6f 73  6f 66 74 2c 44 43 3d 63   C=microsoft,DC=c
    00b0  6f 6d 3f 63 41 43 65 72  74 69 66 69 63 61 74 65   om?cACertificate
    00c0  3f 62 61 73 65 3f 6f 62  6a 65 63 74 43 6c 61 73   ?base?objectClas
    00d0  73 3d 63 65 72 74 69 66  69 63 61 74 69 6f 6e 41   s=certificationA
    00e0  75 74 68 6f 72 69 74 79  30 81 9a 06 08 2b 06 01   uthority0....+..
    00f0  05 05 07 30 02 86 81 8d  68 74 74 70 3a 2f 2f 6a   ...0....https://j
    0100  61 79 74 65 73 74 37 2e  6a 64 6f 6d 63 73 63 2e   aytest7.jdomcsc.
    0110  6e 74 74 65 73 74 2e 6d  69 63 72 6f 73 6f 66 74   nttest.microsoft
    0120  2e 63 6f 6d 2f 43 65 72  74 45 6e 72 6f 6c 6c 2f   .com/CertEnroll/
    0130  4a 41 59 54 45 53 54 37  2e 6a 64 6f 6d 63 73 63   JAYTEST7.jdomcsc
    0140  2e 6e 74 74 65 73 74 2e  6d 69 63 72 6f 73 6f 66   .nttest.microsof
    0150  74 2e 63 6f 6d 5f 4a 44  4f 4d 43 53 43 25 32 30   t.com_JDOMCSC%20
    0160  4c 6f 6e 67 68 6f 72 6e  25 32 30 45 6e 74 65 72   Longhorn%20Enter
    0170  70 72 69 73 65 25 32 30  52 6f 6f 74 25 32 30 43   prise%20Root%20C
    0180  41 2e 63 72 74                                     A.crt

    2.5.29.17: Flags = 0, Length = 6a
    Subject Alternative Name
        Other Name:
             Principal Name=Administrator@jdomcsc.nttest.microsoft.com
        RFC822 Name=Administrator@jdomcsc.nttest.microsoft.com
    AltName: 2 entries:
    AltName[0] CERT_ALT_NAME_OTHER_NAME: 1.3.6.1.4.1.311.20.2.3 Principal Name: 
      CERT_RDN_UTF8_STRING, Length = 42 (42 Characters)
        "Administrator@jdomcsc.nttest.microsoft.com"

        41 64 6d 69 6e 69 73 74  72 61 74 6f 72 40 6a 64   Administrator@jd
        6f 6d 63 73 63 2e 6e 74  74 65 73 74 2e 6d 69 63   omcsc.nttest.mic
        72 6f 73 6f 66 74 2e 63  6f 6d                     rosoft.com

        41 00 64 00 6d 00 69 00  6e 00 69 00 73 00 74 00   A.d.m.i.n.i.s.t.
        72 00 61 00 74 00 6f 00  72 00 40 00 6a 00 64 00   r.a.t.o.r.@.j.d.
        6f 00 6d 00 63 00 73 00  63 00 2e 00 6e 00 74 00   o.m.c.s.c...n.t.
        74 00 65 00 73 00 74 00  2e 00 6d 00 69 00 63 00   t.e.s.t...m.i.c.
        72 00 6f 00 73 00 6f 00  66 00 74 00 2e 00 63 00   r.o.s.o.f.t...c.
        6f 00 6d 00                                        o.m.

    AltName[1] CERT_ALT_NAME_RFC822_NAME: "Administrator@jdomcsc.nttest.microsoft.com"

    0000  30 68 a0 3a 06 0a 2b 06  01 04 01 82 37 14 02 03   0h.:..+.....7...
    0010  a0 2c 0c 2a 41 64 6d 69  6e 69 73 74 72 61 74 6f   .,.*Administrato
    0020  72 40 6a 64 6f 6d 63 73  63 2e 6e 74 74 65 73 74   r@jdomcsc.nttest
    0030  2e 6d 69 63 72 6f 73 6f  66 74 2e 63 6f 6d 81 2a   .microsoft.com.*
    0040  41 64 6d 69 6e 69 73 74  72 61 74 6f 72 40 6a 64   Administrator@jd
    0050  6f 6d 63 73 63 2e 6e 74  74 65 73 74 2e 6d 69 63   omcsc.nttest.mic
    0060  72 6f 73 6f 66 74 2e 63  6f 6d                     rosoft.com

Signature Algorithm:
    Algorithm ObjectId: 1.2.840.10045.4.3.3 ECDSA SHA-384(certlib) (sha384ECDSA)
    Algorithm Parameters: NULL
Signature: UnusedBits=0
    0000  63 06 27 0d de 0c b2 62  ef 64 e8 f4 4f a6 c5 13
    0010  01 ef 00 10 6b 23 20 97  5c e4 65 20 83 00 5e fe
    0020  7a b2 85 83 f3 bb 95 4f  9d 9c b2 b7 94 5f 55 b7
    0030  00 31 02 b8 1e 3e 71 cc  45 53 9d 68 4d 31 39 ac
    0040  a9 3a 93 01 35 af b1 17  9b ad f3 64 d9 87 22 b2
    0050  52 31 d8 76 69 5f 3f 85  82 19 b3 fb a3 76 a2 57
    0060  95 17 a6 00 31 02 66 30
Non-root Certificate
Key Id Hash(rfc-sha1): 60 8a b3 ff 41 13 ee 58 9d 66 8f b2 0e 72 da 5f 5f 30 9e 90
Key Id Hash(sha1): 6e b9 3a 0e f0 9a be a0 ce 63 ed d7 cc ff 66 f3 63 da 73 82
Cert Hash(md5): 6d ae d5 a7 07 fe d0 b3 52 de c3 64 01 f4 55 a9
Cert Hash(sha1): fe cb d8 53 b3 a8 34 d8 b3 4b 4e e2 76 50 84 29 1c 81 3c e0
----------------  End Nesting Level 3  ----------------
    0000  30 82 06 c8 30 82 06 4d  a0 03 02 01 02 02 0a 24   0...0..M.......$
    0010  8f 7d 3c 00 00 00 00 08  6e 30 0a 06 08 2a 86 48   .}<.....n0...*.H
    0020  ce 3d 04 03 03 30 42 31  12 30 10 06 03 55 04 0a   .=...0B1.0...U..
    0030  13 09 4d 69 63 72 6f 73  6f 66 74 31 2c 30 2a 06   ..Microsoft1,0*.
    0040  03 55 04 03 13 23 4a 44  4f 4d 43 53 43 20 4c 6f   .U...#JDOMCSC Lo
    0050  6e 67 68 6f 72 6e 20 45  6e 74 65 72 70 72 69 73   nghorn Enterpris
    0060  65 20 52 6f 6f 74 20 43  41 30 1e 17 0d 30 36 30   e Root CA0...060
    0070  34 32 34 32 33 31 33 33  30 5a 17 0d 30 37 30 34   424231330Z..0704
    0080  32 34 32 33 31 33 33 30  5a 30 81 c4 31 13 30 11   24231330Z0..1.0.
    0090  06 0a 09 92 26 89 93 f2  2c 64 01 19 16 03 63 6f   ....&...,d....co
    00a0  6d 31 19 30 17 06 0a 09  92 26 89 93 f2 2c 64 01   m1.0.....&...,d.
    00b0  19 16 09 6d 69 63 72 6f  73 6f 66 74 31 16 30 14   ...microsoft1.0.
    00c0  06 0a 09 92 26 89 93 f2  2c 64 01 19 16 06 6e 74   ....&...,d....nt
    00d0  74 65 73 74 31 17 30 15  06 0a 09 92 26 89 93 f2   test1.0.....&...
    00e0  2c 64 01 19 16 07 6a 64  6f 6d 63 73 63 31 0e 30   ,d....jdomcsc1.0
    00f0  0c 06 03 55 04 03 13 05  55 73 65 72 73 31 16 30   ...U....Users1.0
    0100  14 06 03 55 04 03 13 0d  41 64 6d 69 6e 69 73 74   ...U....Administ
    0110  72 61 74 6f 72 31 39 30  37 06 09 2a 86 48 86 f7   rator1907..*.H..
    0120  0d 01 09 01 16 2a 41 64  6d 69 6e 69 73 74 72 61   .....*Administra
    0130  74 6f 72 40 6a 64 6f 6d  63 73 63 2e 6e 74 74 65   tor@jdomcsc.ntte
    0140  73 74 2e 6d 69 63 72 6f  73 6f 66 74 2e 63 6f 6d   st.microsoft.com
    0150  30 81 9f 30 0d 06 09 2a  86 48 86 f7 0d 01 01 01   0..0...*.H......
    0160  05 00 03 81 8d 00 30 81  89 02 81 81 00 91 9d 0a   ......0.........
    0170  8e 1d 7a 21 e9 ba 34 c7  54 1d 79 c9 35 91 e9 68   ..z!..4.T.y.5..h
    0180  cb 3d ef 2b 4d a6 52 31  f4 95 31 44 02 75 cd d5   .=.+M.R1..1D.u..
    0190  34 ec a2 32 0c 4f 97 b7  6c 87 ca b2 b0 5b 53 a6   4..2.O..l....[S.
    01a0  74 b7 1e 69 a7 d8 c3 3d  03 20 14 5a cb 40 ed f8   t..i...=. .Z.@..
    01b0  5e ee c4 be 97 62 70 44  2f 47 1e 3e b5 61 33 d9   ^....bpD/G.>.a3.
    01c0  02 c3 87 62 4e 74 26 ef  fa 0b 06 d0 0c ec 68 fc   ...bNt&.......h.
    01d0  93 10 88 5b 70 8f 94 13  eb 6e 86 d4 b5 14 e8 6f   ...[p....n.....o
    01e0  87 21 3d 1d 3e 16 d4 cf  e7 19 70 c7 31 02 03 01   .!=.>.....p.1...
    01f0  00 01 a3 82 04 5f 30 82  04 5b 30 17 06 09 2b 06   ....._0..[0...+.
    0200  01 04 01 82 37 14 02 04  0a 1e 08 00 55 00 73 00   ....7.......U.s.
    0210  65 00 72 30 29 06 03 55  1d 25 04 22 30 20 06 0a   e.r0)..U.%."0 ..
    0220  2b 06 01 04 01 82 37 0a  03 04 06 08 2b 06 01 05   +.....7.....+...
    0230  05 07 03 04 06 08 2b 06  01 05 05 07 03 02 30 0b   ......+.......0.
    0240  06 03 55 1d 0f 04 04 03  02 05 a0 30 4b 06 09 2a   ..U........0K..*
    0250  86 48 86 f7 0d 01 09 0f  04 3e 30 3c 30 0e 06 08   .H.......>0<0...
    0260  2a 86 48 86 f7 0d 03 02  02 02 00 80 30 0e 06 08   *.H.........0...
    0270  2a 86 48 86 f7 0d 03 04  02 02 00 80 30 0a 06 05   *.H.........0...
    0280  2b 0e 03 02 07 02 01 38  30 0e 06 08 2a 86 48 86   +......80...*.H.
    0290  f7 0d 03 07 02 02 00 a8  30 1d 06 03 55 1d 0e 04   ........0...U...
    02a0  16 04 14 60 8a b3 ff 41  13 ee 58 9d 66 8f b2 0e   ...`...A..X.f...
    02b0  72 da 5f 5f 30 9e 90 30  1f 06 03 55 1d 23 04 18   r.__0..0...U.#..
    02c0  30 16 80 14 16 a1 b0 9e  8f 4f ee 2e d4 25 07 90   0........O...%..
    02d0  2b 89 37 21 70 c7 d6 65  30 82 01 6f 06 03 55 1d   +.7!p..e0..o..U.
    02e0  1f 04 82 01 66 30 82 01  62 30 82 01 5e a0 82 01   ....f0..b0..^...
    02f0  5a a0 82 01 56 86 81 ea  6c 64 61 70 3a 2f 2f 2f   Z...V...ldap:///
    0300  43 4e 3d 4a 44 4f 4d 43  53 43 25 32 30 4c 6f 6e   CN=JDOMCSC%20Lon
    0310  67 68 6f 72 6e 25 32 30  45 6e 74 65 72 70 72 69   ghorn%20Enterpri
    0320  73 65 25 32 30 52 6f 6f  74 25 32 30 43 41 2c 43   se%20Root%20CA,C
    0330  4e 3d 4a 41 59 54 45 53  54 37 2c 43 4e 3d 43 44   N=JAYTEST7,CN=CD
    0340  50 2c 43 4e 3d 50 75 62  6c 69 63 25 32 30 4b 65   P,CN=Public%20Ke
    0350  79 25 32 30 53 65 72 76  69 63 65 73 2c 43 4e 3d   y%20Services,CN=
    0360  53 65 72 76 69 63 65 73  2c 43 4e 3d 43 6f 6e 66   Services,CN=Conf
    0370  69 67 75 72 61 74 69 6f  6e 2c 44 43 3d 6a 64 6f   iguration,DC=jdo
    0380  6d 63 73 63 2c 44 43 3d  6e 74 74 65 73 74 2c 44   mcsc,DC=nttest,D
    0390  43 3d 6d 69 63 72 6f 73  6f 66 74 2c 44 43 3d 63   C=microsoft,DC=c
    03a0  6f 6d 3f 63 65 72 74 69  66 69 63 61 74 65 52 65   om?certificateRe
    03b0  76 6f 63 61 74 69 6f 6e  4c 69 73 74 3f 62 61 73   vocationList?bas
    03c0  65 3f 6f 62 6a 65 63 74  43 6c 61 73 73 3d 63 52   e?objectClass=cR
    03d0  4c 44 69 73 74 72 69 62  75 74 69 6f 6e 50 6f 69   LDistributionPoi
    03e0  6e 74 86 67 68 74 74 70  3a 2f 2f 6a 61 79 74 65   nt.ghttp://jayte
    03f0  73 74 37 2e 6a 64 6f 6d  63 73 63 2e 6e 74 74 65   st7.jdomcsc.ntte
    0400  73 74 2e 6d 69 63 72 6f  73 6f 66 74 2e 63 6f 6d   st.microsoft.com
    0410  2f 43 65 72 74 45 6e 72  6f 6c 6c 2f 4a 44 4f 4d   /CertEnroll/JDOM
    0420  43 53 43 25 32 30 4c 6f  6e 67 68 6f 72 6e 25 32   CSC%20Longhorn%2
    0430  30 45 6e 74 65 72 70 72  69 73 65 25 32 30 52 6f   0Enterprise%20Ro
    0440  6f 74 25 32 30 43 41 2e  63 72 6c 30 82 01 93 06   ot%20CA.crl0....
    0450  08 2b 06 01 05 05 07 01  01 04 82 01 85 30 82 01   .+...........0..
    0460  81 30 81 e1 06 08 2b 06  01 05 05 07 30 02 86 81   .0....+.....0...
    0470  d4 6c 64 61 70 3a 2f 2f  2f 43 4e 3d 4a 44 4f 4d   .ldap:///CN=JDOM
    0480  43 53 43 25 32 30 4c 6f  6e 67 68 6f 72 6e 25 32   CSC%20Longhorn%2
    0490  30 45 6e 74 65 72 70 72  69 73 65 25 32 30 52 6f   0Enterprise%20Ro
    04a0  6f 74 25 32 30 43 41 2c  43 4e 3d 41 49 41 2c 43   ot%20CA,CN=AIA,C
    04b0  4e 3d 50 75 62 6c 69 63  25 32 30 4b 65 79 25 32   N=Public%20Key%2
    04c0  30 53 65 72 76 69 63 65  73 2c 43 4e 3d 53 65 72   0Services,CN=Ser
    04d0  76 69 63 65 73 2c 43 4e  3d 43 6f 6e 66 69 67 75   vices,CN=Configu
    04e0  72 61 74 69 6f 6e 2c 44  43 3d 6a 64 6f 6d 63 73   ration,DC=jdomcs
    04f0  63 2c 44 43 3d 6e 74 74  65 73 74 2c 44 43 3d 6d   c,DC=nttest,DC=m
    0500  69 63 72 6f 73 6f 66 74  2c 44 43 3d 63 6f 6d 3f   icrosoft,DC=com?
    0510  63 41 43 65 72 74 69 66  69 63 61 74 65 3f 62 61   cACertificate?ba
    0520  73 65 3f 6f 62 6a 65 63  74 43 6c 61 73 73 3d 63   se?objectClass=c
    0530  65 72 74 69 66 69 63 61  74 69 6f 6e 41 75 74 68   ertificationAuth
    0540  6f 72 69 74 79 30 81 9a  06 08 2b 06 01 05 05 07   ority0....+.....
    0550  30 02 86 81 8d 68 74 74  70 3a 2f 2f 6a 61 79 74   0....https://jayt
    0560  65 73 74 37 2e 6a 64 6f  6d 63 73 63 2e 6e 74 74   est7.jdomcsc.ntt
    0570  65 73 74 2e 6d 69 63 72  6f 73 6f 66 74 2e 63 6f   est.microsoft.co
    0580  6d 2f 43 65 72 74 45 6e  72 6f 6c 6c 2f 4a 41 59   m/CertEnroll/JAY
    0590  54 45 53 54 37 2e 6a 64  6f 6d 63 73 63 2e 6e 74   TEST7.jdomcsc.nt
    05a0  74 65 73 74 2e 6d 69 63  72 6f 73 6f 66 74 2e 63   test.microsoft.c
    05b0  6f 6d 5f 4a 44 4f 4d 43  53 43 25 32 30 4c 6f 6e   om_JDOMCSC%20Lon
    05c0  67 68 6f 72 6e 25 32 30  45 6e 74 65 72 70 72 69   ghorn%20Enterpri
    05d0  73 65 25 32 30 52 6f 6f  74 25 32 30 43 41 2e 63   se%20Root%20CA.c
    05e0  72 74 30 71 06 03 55 1d  11 04 6a 30 68 a0 3a 06   rt0q..U...j0h.:.
    05f0  0a 2b 06 01 04 01 82 37  14 02 03 a0 2c 0c 2a 41   .+.....7....,.*A
    0600  64 6d 69 6e 69 73 74 72  61 74 6f 72 40 6a 64 6f   dministrator@jdo
    0610  6d 63 73 63 2e 6e 74 74  65 73 74 2e 6d 69 63 72   mcsc.nttest.micr
    0620  6f 73 6f 66 74 2e 63 6f  6d 81 2a 41 64 6d 69 6e   osoft.com.*Admin
    0630  69 73 74 72 61 74 6f 72  40 6a 64 6f 6d 63 73 63   istrator@jdomcsc
    0640  2e 6e 74 74 65 73 74 2e  6d 69 63 72 6f 73 6f 66   .nttest.microsof
    0650  74 2e 63 6f 6d 30 0a 06  08 2a 86 48 ce 3d 04 03   t.com0...*.H.=..
    0660  03 03 69 00 30 66 02 31  00 a6 17 95 57 a2 76 a3   ..i.0f.1....W.v.
    0670  fb b3 19 82 85 3f 5f 69  76 d8 31 52 b2 22 87 d9   .....?_iv.1R."..
    0680  64 f3 ad 9b 17 b1 af 35  01 93 3a a9 ac 39 31 4d   d......5..:..91M
    0690  68 9d 53 45 cc 71 3e 1e  b8 02 31 00 b7 55 5f 94   h.SE.q>...1..U_.
    06a0  b7 b2 9c 9d 4f 95 bb f3  83 85 b2 7a fe 5e 00 83   ....O......z.^..
    06b0  20 65 e4 5c 97 20 23 6b  10 00 ef 01 13 c5 a6 4f    e.\. #k.......O
    06c0  f4 e8 64 ef 62 b2 0c de  0d 27 06 63               ..d.b....'.c
Signature Algorithm:
    Algorithm ObjectId: 1.2.840.113549.1.1.5 sha1RSA
    Algorithm Parameters:
    05 00
Signature: UnusedBits=0
    0000  22 7a f2 8c 41 31 c2 4e  ad b0 a7 9e dd 83 a0 02
    0010  c4 06 79 52 08 c6 ea e9  86 51 b8 69 a0 78 44 a4
    0020  25 84 5f 41 b8 d1 06 32  b3 2f c9 99 c2 95 41 00
    0030  45 01 57 70 bf 3c 5f 39  9b 83 d3 9e 61 d6 2d 0c
    0040  fa 3e 8b 27 07 da 75 20  98 2b fc d0 c4 e2 c5 d2
    0050  48 f3 36 9d 48 03 60 a5  f8 38 4d e3 3a ef d1 53
    0060  9b f3 5a 6d 69 c6 35 3f  2c 8c 87 d7 86 ec 73 be
    0070  b0 ff 52 2b 29 2b a3 ee  58 56 b8 26 54 5d f7 15
Signature matches Public Key
Key Id Hash(rfc-sha1): d2 91 95 03 6a b4 a6 a7 43 cd bd 35 0e 1c 80 58 91 e3 9a 33
Key Id Hash(sha1): af cd 76 a2 8c 0a 19 7f 65 08 ee 52 19 76 6a 56 73 73 ef 71
----------------  End Nesting Level 2  ----------------

Tagged Content Info: 0
Tagged Other Messages: 0
----------------  End Nesting Level 1  ----------------

Signer Count: 1

Signer Info[0]:
Signature matches request Public Key
CMSG_SIGNER_INFO_CMS_VERSION(3)
CERT_ID_KEY_IDENTIFIER(2)
    0000  d2 91 95 03 6a b4 a6 a7  43 cd bd 35 0e 1c 80 58
    0010  91 e3 9a 33
Hash Algorithm:
    Algorithm ObjectId: 1.3.14.3.2.26 sha1 (sha1NoSign)
    Algorithm Parameters: NULL
Encrypted Hash Algorithm:
    Algorithm ObjectId: 1.2.840.113549.1.1.1 RSA (RSA_SIGN)
    Algorithm Parameters: NULL
Encrypted Hash:
    0000  a4 e7 b3 6b e9 f7 3c 2a  fd c1 33 ed 3c b1 99 f8
    0010  c9 c1 5b 20 be 32 f7 94  d2 1d 07 de a4 8c 76 aa
    0020  1a 39 5e 6b 04 3c e8 d4  dd fa 7b 5a 25 e1 61 4f
    0030  03 00 c1 18 59 56 77 52  3c 99 22 fd 78 37 c5 8f
    0040  51 2e 06 2a 29 66 d3 83  0e eb 04 ed f3 aa d7 00
    0050  31 9e db 49 72 77 bb a8  f7 e0 3a 23 bc cb b9 29
    0060  3c eb cb a6 aa 0c 7c be  77 b7 7e db 3f 65 a7 be
    0070  a9 88 99 b0 c8 12 a0 e2  27 c4 04 f1 88 09 8e 6b

Authenticated Attributes[0]:
  2 attributes:

  Attribute[0]: 1.2.840.113549.1.9.3 (Content Type)
    Value[0][0]:
    Unknown Attribute type
    1.3.6.1.5.5.7.12.2 CMC Data
    0000  06 08 2b 06 01 05 05 07  0c 02                     ..+.......

  Attribute[1]: 1.2.840.113549.1.9.4 (Message Digest)
    Value[1][0]:
    Unknown Attribute type
    Message Digest(certutil):
        f1 13 a1 dc 4d 88 2e 81 70 35 53 2a d2 de 5c 9a ce e8 8e db
    0000  04 14 f1 13 a1 dc 4d 88  2e 81 70 35 53 2a d2 de   ......M...p5S*..
    0010  5c 9a ce e8 8e db                                  \.....

Unauthenticated Attributes[0]:
  0 attributes:

Computed Hash: a6 da bb a8 3c 44 da e1 76 c2 a3 20 45 d9 4c 31 7f 40 51 92
No Recipient

No Certificates
No CRLs
CertUtil: -dump command completed successfully.
```

## Related topics

<dl> <dt>

[Sample Requests](sample-requests.md)
</dt> </dl>

 

 



