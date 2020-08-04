#ifndef __SHA1BCRYPT__HEAD
#define __SHA1BCRYPT__HEAD
#include <hashbcrypt.h>
#define platform_SHA_CTX struct _bcryptctx
#define platform_SHA1_Init(ctx) bcrypt_hash_Init(ctx, BCRYPT_SHA1_ALGORITHM)
#define platform_SHA1_Update bcrypt_hash_Update
#define platform_SHA1_Final	bcrypt_hash_Final
#endif