#include <hashbcrypt.h>
#include <bcrypt.h>

void bcrypt_hash_Init(struct _bcryptctx * ctx, const wchar_t * alg)
{
	BCryptOpenAlgorithmProvider(&ctx->hAlg, alg, NULL, 0);
	ULONG cbData = 0;
	DWORD cbHashObject;
	BCryptGetProperty(ctx->hAlg, BCRYPT_OBJECT_LENGTH, (PUCHAR)&cbHashObject, sizeof(DWORD), &cbData, 0);
	ctx->pbHashObject = (PUCHAR)HeapAlloc(GetProcessHeap(), 0, cbHashObject);
	BCryptCreateHash(ctx->hAlg, &ctx->hHash, ctx->pbHashObject, cbHashObject, NULL, NULL, 0);
}

void bcrypt_hash_Update(struct _bcryptctx * ctx, PUCHAR data, ULONG length)
{
	BCryptHashData(ctx->hHash, data, length, NULL);
}

void bcrypt_hash_Final(PUCHAR data, struct _bcryptctx * ctx)
{
	BCryptFinishHash(ctx->hHash, data, 20, NULL);
	BCryptCloseAlgorithmProvider(ctx->hAlg, NULL);
	BCryptDestroyHash(ctx->hHash);
	HeapFree(GetProcessHeap(), 0, ctx->pbHashObject);
}