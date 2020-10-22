#ifndef __SHA256BCRYPT__HEAD
#define __SHA256BCRYPT__HEAD
#include <hashbcrypt.h>
#define platform_SHA256_CTX struct _bcryptctx
#define platform_SHA256_Init(ctx) bcrypt_hash_Init(ctx, BCRYPT_SHA256_ALGORITHM)
#define platform_SHA256_Update bcrypt_hash_Update
#define platform_SHA256_Final bcrypt_hash_Final
#endif