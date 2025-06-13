void sha256_compute(const uint8_t* data, size_t len, uint8_t hash[32]);
uint32_t swap_endian32(uint32_t x);
#define ROTR(x, n) ((x >> n) | (x << (32 - n)))
#define SHR(x, n)  (x >> n)

#define CH(x, y, z)  ((x & y) ^ (~x & z))
#define MAJ(x, y, z) ((x & y) ^ (x & z) ^ (y & z))

#define BSIG0(x) (ROTR(x, 2) ^ ROTR(x, 13) ^ ROTR(x, 22))
#define BSIG1(x) (ROTR(x, 6) ^ ROTR(x, 11) ^ ROTR(x, 25))
#define SSIG0(x) (ROTR(x, 7) ^ ROTR(x, 18) ^ SHR(x, 3))
#define SSIG1(x) (ROTR(x, 17) ^ ROTR(x, 19) ^ SHR(x, 10))

#define BE32(x) swap_endian32(x)

uint32_t H[8] = {
	  0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
	  0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
};
uint32_t K[64] = {
	  0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
	  0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
	  0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
	  0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
	  0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
	  0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
	  0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
	  0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};
// Context to keep track of state
typedef struct {
	uint32_t h[8];         // Current hash state
	uint64_t total_len;    // Total message length in bits
	uint8_t buffer[64];    // Data block buffer (512 bits)
	size_t buffer_len;     // Number of bytes currently in buffer
} sha256_ctx;
void sha256_init(sha256_ctx* ctx);

void sha256_update(sha256_ctx* ctx, const uint8_t* data, size_t len);
void sha256_final(sha256_ctx* ctx, uint8_t hash[32]);

void sha256_init(sha256_ctx* ctx) 
{
	ctx->h[0] = 0x6a09e667;
	ctx->h[1] = 0xbb67ae85;
	ctx->h[2] = 0x3c6ef372;
	ctx->h[3] = 0xa54ff53a;
	ctx->h[4] = 0x510e527f;
	ctx->h[5] = 0x9b05688c;
	ctx->h[6] = 0x1f83d9ab;
	ctx->h[7] = 0x5be0cd19;
	ctx->total_len = 0;
	ctx->buffer_len = 0;
}
void sha256_process_block(sha256_ctx* ctx)
{
	uint32_t W[64];
	for (int i = 0; i <= 15; i++) 
	{
		//W[i] = swap_endian32(ctx->buffer[i]);
		W[i] = ((uint32_t)ctx->buffer[4 * i + 0] << 24) |
			((uint32_t)ctx->buffer[4 * i + 1] << 16) |
			((uint32_t)ctx->buffer[4 * i + 2] << 8) |
			((uint32_t)ctx->buffer[4 * i + 3]);
	}
	for (int i = 16; i <= 63; i++) 
	{
		W[i] = SSIG1(W[i - 2]) + W[i - 7] + SSIG0(W[i - 15]) + W[i - 16];
	}
	uint32_t a = ctx->h[0];
	uint32_t b = ctx->h[1];
	uint32_t c = ctx->h[2];
	uint32_t d = ctx->h[3];
	uint32_t e = ctx->h[4];
	uint32_t f = ctx->h[5];
	uint32_t g = ctx->h[6];
	uint32_t h = ctx->h[7];

	for (int t = 0; t <= 63; t++) 
	{
		uint32_t T1 = h + BSIG1(e) + CH(e, f, g) + K[t] + W[t];
		uint32_t T2 = BSIG0(a) + MAJ(a, b, c);
		h = g;
		g = f;
		f = e;
		e = d + T1;
		d = c;
		c = b;
		b = a;
		a = T1 + T2;
	}
	ctx->h[0] += a;
	ctx->h[1] += b;
	ctx->h[2] += c;
	ctx->h[3] += d;
	ctx->h[4] += e;
	ctx->h[5] += f;
	ctx->h[6] += g;
	ctx->h[7] += h;
}
void sha256_update(sha256_ctx* ctx, const uint8_t* data, size_t len)
{
	ctx->total_len += len;
	size_t buffer_fill = ctx->buffer_len;	// buffer_len is number of bytes currently in the buffer, according to the comment I wrote yesterday. Not sure and don't have to be sure — it the comment says so, it's true
	size_t space_left = 64 - buffer_fill;
	if (len < space_left) 
	{
		for (size_t i = 0; i < len; i++) 
		{
			ctx->buffer[buffer_fill + i] = data[i];
		}
		ctx->buffer_len += len;
		return;
	}
	else
	{
		for (size_t i = 0; i < space_left; i++) 
		{
			ctx->buffer[buffer_fill + i] = data[i];
		}
		sha256_process_block(ctx);
		ctx->buffer_len = 0;
		data += space_left;
		len -= space_left;
	}
	while (len >= 64) 
	{
		// Copy the next 64 bytes directly into the buffer
		for (size_t i = 0; i < 64; i++) 
		{
			ctx->buffer[i] = data[i];
		}

		sha256_process_block(ctx);
		data += 64;
		len -= 64;
	}
	for (size_t i = 0; i < len; i++) 
	{
		ctx->buffer[i] = data[i];
	}
	ctx->buffer_len = len;
}
void sha256_final(sha256_ctx* ctx, uint8_t hash[32]) 
{
	ctx->buffer[ctx->buffer_len++] = 0x80;
	if (ctx->buffer_len > 56)
	{
		// Not enough room for padding + length => pad to 64, process block, and continue in a new block
		while (ctx->buffer_len < 64) 
		{
			ctx->buffer[ctx->buffer_len++] = 0x00;
		}
		sha256_process_block(ctx);     // process this full block
		ctx->buffer_len = 0;
	}
	// Now pad to exactly 56 bytes
	while (ctx->buffer_len < 56) 
	{
		ctx->buffer[ctx->buffer_len++] = 0x00;
	}
	uint64_t bit_len = ctx->total_len * 8;
	for (int i = 0; i < 8; i++) 
	{
		ctx->buffer[56 + i] = (uint8_t)(bit_len >> (56 - 8 * i));
	}
	sha256_process_block(ctx);

	// Convert final hash state to big-endian output
	for (int i = 0; i < 8; i++) 
	{
		uint32_t h_be = BE32(ctx->h[i]);
		hash[4 * i + 0] = (h_be >> 24) & 0xFF;
		hash[4 * i + 1] = (h_be >> 16) & 0xFF;
		hash[4 * i + 2] = (h_be >> 8) & 0xFF;
		hash[4 * i + 3] = h_be & 0xFF;
	}
}
void sha256_compute(const uint8_t* data, size_t len, uint8_t hash[32])
{
	sha256_ctx ctx;
	sha256_init(&ctx);
	sha256_update(&ctx, data, len);
	sha256_final(&ctx, hash);
}
uint32_t swap_endian32(uint32_t x) 
{
	return ((x >> 24) & 0x000000FF) |
		((x >> 8) & 0x0000FF00) |
		((x << 8) & 0x00FF0000) |
		((x << 24) & 0xFF000000);
}