---
description: Explains how to generate, retrieve, verify, and export DSS keys and signatures.
ms.assetid: d28fe531-af4b-4b5e-ab67-47ef70f8fa5b
title: DSS Keys
ms.topic: reference
ms.date: 05/31/2018
---

# DSS Keys

-   [Generating and Retrieving DSS Keys](#generating-and-retrieving-dss-keys)
-   [Generating DSS Signatures](#generating-dss-signatures)
-   [Verifying a DSS Signature](#verifying-a-dss-signature)
-   [Exporting DSS Keys](#exporting-dss-keys)

## Generating and Retrieving DSS Keys

DSS Keys can be generated by a call to the [**CryptGenKey**](/windows/desktop/api/Wincrypt/nf-wincrypt-cryptgenkey) function. The call to **CryptGenKey** requires that either AT\_SIGNATURE or CALG\_DSS\_SIGN be passed in the *Algid* argument. This call will generate the P (prime modulus), Q (prime), G (generator), X (secret exponent), and Y (public key) values from scratch and persist them in a [*key BLOB*](../secgloss/k-gly.md) to local storage.

**To generate a DSS signature key pair**

1.  Call the [**CryptAcquireContext**](/windows/desktop/api/Wincrypt/nf-wincrypt-cryptacquirecontexta) function to get a handle to the Microsoft DSS Cryptographic Provider.
2.  Call [**CryptGenKey**](/windows/desktop/api/Wincrypt/nf-wincrypt-cryptgenkey) to generate the keys. Either AT\_SIGNATURE or CALG\_DSS\_SIGN must be passed in for the *Algid* argument and the upper 16 bits of the *dwFlags* argument must be set to the desired key size. If the upper 16 bits are zero, then the default key size of 1,024 bits will be used. A [**HCRYPTKEY**](hcryptkey.md) handle is returned in the *hKey* argument.

**To retrieve a pointer to previously generated signature keys**

1.  Call [**CryptAcquireContext**](/windows/desktop/api/Wincrypt/nf-wincrypt-cryptacquirecontexta) to get a handle to the Microsoft DSS Cryptographic Provider.
2.  Call the [**CryptGetUserKey**](/windows/desktop/api/Wincrypt/nf-wincrypt-cryptgetuserkey) function with the *dwKeySpec* argument set to either AT\_SIGNATURE or CALG\_DSS\_SIGN.

**To retrieve the P, Q, and G values**

1.  Call [**CryptAcquireContext**](/windows/desktop/api/Wincrypt/nf-wincrypt-cryptacquirecontexta) to get a handle to the Microsoft DSS Cryptographic Provider.
2.  Call [**CryptGetUserKey**](/windows/desktop/api/Wincrypt/nf-wincrypt-cryptgetuserkey) with the *dwKeySpec* argument set to either AT\_SIGNATURE or CALG\_DSS\_SIGN.
3.  Call [**CryptGetKeyParam**](/windows/desktop/api/Wincrypt/nf-wincrypt-cryptgetkeyparam) with the *hKey* argument set to the pointer retrieved in the previous step. The *dwParam* argument must be set to the desired flag; KP\_P, KP\_Q, or KP\_G. The value is returned in the *pbData* argument, and the length of the data is returned in the *pdwDataLen* argument. The value is returned with no header information and in [*little-endian*](../secgloss/l-gly.md) format.

## Generating DSS Signatures

Data to be signed must first be [*hashed*](../secgloss/h-gly.md) by using the [*SHA*](../secgloss/s-gly.md) algorithm. After that data is hashed, a [*DSS*](../secgloss/d-gly.md) signature is generated by calling the [**CryptSignHash**](/windows/desktop/api/Wincrypt/nf-wincrypt-cryptsignhasha) function.

**To generate a DSS signature**

1.  Call [**CryptAcquireContext**](/windows/desktop/api/Wincrypt/nf-wincrypt-cryptacquirecontexta) to get a handle to the Microsoft DSS Cryptographic Provider.
2.  Call [**CryptCreateHash**](/windows/desktop/api/Wincrypt/nf-wincrypt-cryptcreatehash) with the *Algid* argument set to CALG\_SHA to get a handle to a SHA hash object.
3.  Call [**CryptHashData**](/windows/desktop/api/Wincrypt/nf-wincrypt-crypthashdata) with the *hHash* argument set to the handle retrieved in the previous step. This creates a hash of the data and returns a handle to the hash in the *phHash* argument of the [**CryptCreateHash**](/windows/desktop/api/Wincrypt/nf-wincrypt-cryptcreatehash) function call.
4.  Call [**CryptSignHash**](/windows/desktop/api/Wincrypt/nf-wincrypt-cryptsignhasha) with the *hHash* argument set to the handle retrieved in the previous step. Either AT\_SIGNATURE or CALG\_DSS\_SIGN may be passed in the *dwKeySpec* parameter. The signature is returned to the address provided in the *pbSignature* argument, and the length of the signature is returned to the address provided in the *pdwSigLen* argument. A **NULL** pointer may be passed in the *pbSignature* argument, and, in this case, the signature is not generated, but the length of the signature is returned to the address provided in the *pdwSigLen* parameter.

## Verifying a DSS Signature

To verify a DSS signature, the DSS public key of the signer must be imported, the [*signed data*](../secgloss/s-gly.md) must be hashed, and then the signature can be verified.

**To verify a DSS signature**

1.  Call [**CryptAcquireContext**](/windows/desktop/api/Wincrypt/nf-wincrypt-cryptacquirecontexta) to get a handle to the Microsoft DSS Cryptographic Provider.
2.  Call [**CryptImportKey**](/windows/desktop/api/Wincrypt/nf-wincrypt-cryptimportkey) to import the signer's DSS public key.
3.  Call [**CryptCreateHash**](/windows/desktop/api/Wincrypt/nf-wincrypt-cryptcreatehash) with the *Algid* argument set to CALG\_SHA to get a handle to a SHA hash object.
4.  Call [**CryptHashData**](/windows/desktop/api/Wincrypt/nf-wincrypt-crypthashdata) with the *hHash* argument set to the handle retrieved in the previous step and with *pbData* pointing to the signed data. This creates a hash of the data and returns a handle to the hash in the *phHash* argument of the [**CryptCreateHash**](/windows/desktop/api/Wincrypt/nf-wincrypt-cryptcreatehash) function call.
5.  Call [**CryptVerifySignature**](/windows/desktop/api/Wincrypt/nf-wincrypt-cryptverifysignaturea) with the following settings:

    *hHash* is set to the handle to the hash performed in the previous step.

    *pbSignature* points to the signature to be verified.

    *dwSigLen* is set to the length of the signature.

    *hPubKey* is set to the handle of the public key imported in step 2.

    *dwFlags* is set to zero.

## Exporting DSS Keys

When you send [*signed data*](../secgloss/s-gly.md) to someone where the signature will need to be verified by the recipient, the signer's public key must be provided to the recipient and is usually sent along with the signed data. Therefore, it is necessary to be able to export the [*DSS*](../secgloss/d-gly.md) keys in a [*key BLOB*](../secgloss/k-gly.md) format.

**To export the DSS public key**

1.  Call [**CryptAcquireContext**](/windows/desktop/api/Wincrypt/nf-wincrypt-cryptacquirecontexta) to get a handle to the Microsoft DSS Cryptographic Provider.
2.  Call [**CryptGetUserKey**](/windows/desktop/api/Wincrypt/nf-wincrypt-cryptgetuserkey) with the *dwKeySpec* argument set to either AT\_SIGNATURE or CALG\_DSS\_SIGN.
3.  Call [**CryptExportKey**](/windows/desktop/api/Wincrypt/nf-wincrypt-cryptexportkey) with *hKey* set to the handle retrieved in the previous step, *dwBlobType* set to PUBLICKEYBLOB, and *dwFlags* set to zero. The DSS [*public key BLOB*](../secgloss/p-gly.md) is returned in *pbData*, and the length of the [*key BLOB*](../secgloss/k-gly.md) is returned in *pdwDataLen*. A **NULL** pointer may be passed in *pbData*, and, in this case, just the length of the DSS key BLOB will be returned. The BLOB returned when making the call to **CryptExportKey** is in the format described in [DSS Provider Key BLOBs](dss-provider-key-blobs.md).

**To export the DSS private key**

-   Follow the same procedure as for exporting a DSS public key, except that when making the call to [**CryptExportKey**](/windows/desktop/api/Wincrypt/nf-wincrypt-cryptexportkey), *dwBlobType* is set to PRIVATEKEYBLOB. The BLOB returned when making the call to **CryptExportKey** is in the format described in [DSS Provider Key BLOBs](dss-provider-key-blobs.md).

 

 
