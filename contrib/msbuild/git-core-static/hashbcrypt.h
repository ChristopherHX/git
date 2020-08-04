#ifndef __HASHBCRYPT__HEAD
#define __HASHBCRYPT__HEAD
#ifdef __cplusplus
extern "C" {
#endif
#include <windows.h>
struct _bcryptctx
{
	void* hAlg;
	void* hHash;
	unsigned char * pbHashObject;
};
void bcrypt_hash_Init(struct _bcryptctx * ctx, const wchar_t * alg);
void bcrypt_hash_Update(struct _bcryptctx * ctx, PUCHAR data, ULONG length);
void bcrypt_hash_Final(PUCHAR data, struct _bcryptctx * ctx);
#ifdef __cplusplus
}
#endif
#endif