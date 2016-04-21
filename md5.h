#ifndef CPPUTIL_CPP_UTIL_MD5_H
#define CPPUTIL_CPP_UTIL_MD5_H

// Copyright (C) 1991-2, RSA Data Security, Inc. Created 1991. All
// rights reserved.

// License to copy and use this software is granted provided that it
// is identified as the "RSA Data Security, Inc. MD5 Message-Digest
// Algorithm" in all material mentioning or referencing this software
// or this function.
//
// License is also granted to make and use derivative works provided
// that such works are identified as "derived from the RSA Data
// Security, Inc. MD5 Message-Digest Algorithm" in all material
// mentioning or referencing the derived work.
//
// RSA Data Security, Inc. makes no representations concerning either
// the merchantability of this software or the suitability of this
// software for any particular purpose. It is provided "as is"
// without express or implied warranty of any kind.
//
// These notices must be retained in any copies of any part of this
// documentation and/or software.



// The original md5 implementation avoids external libraries.
// This version has dependency on stdio.h for file input and
// string.h for memcpy.
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>

namespace Util {

// #pragma region MD5 defines
// Constants for MD5Transform routine.
#define S11 7
#define S12 12
#define S13 17
#define S14 22
#define S21 5
#define S22 9
#define S23 14
#define S24 20
#define S31 4
#define S32 11
#define S33 16
#define S34 23
#define S41 6
#define S42 10
#define S43 15
#define S44 21

// F, G, H and I are basic MD5 functions.
#define F(x, y, z) (((x) & (y)) | ((~x) & (z)))
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))

// ROTATE_LEFT rotates x left n bits.
#define ROTATE_LEFT(x, n) (((x) << (n)) | ((x) >> (32-(n))))

// FF, GG, HH, and II transformations for rounds 1, 2, 3, and 4.
// Rotation is separate from addition to prevent recomputation.
#define FF(a, b, c, d, x, s, ac) { \
  (a) += F((b), (c), (d)) + (x) + (UINT4)(ac); \
  (a) = ROTATE_LEFT((a), (s)); \
  (a) += (b); \
}

#define GG(a, b, c, d, x, s, ac) { \
  (a) += G((b), (c), (d)) + (x) + (UINT4)(ac); \
  (a) = ROTATE_LEFT((a), (s)); \
  (a) += (b); \
}

#define HH(a, b, c, d, x, s, ac) { \
  (a) += H((b), (c), (d)) + (x) + (UINT4)(ac); \
  (a) = ROTATE_LEFT((a), (s)); \
  (a) += (b); \
}

#define II(a, b, c, d, x, s, ac) { \
  (a) += I((b), (c), (d)) + (x) + (UINT4)(ac); \
  (a) = ROTATE_LEFT((a), (s)); \
  (a) += (b); \
}

// #pragma endregion
typedef unsigned char BYTE;

// POINTER defines a generic pointer type
typedef unsigned char* POINTER;

// UINT2 defines a two byte word
typedef unsigned short int UINT2;

// UINT4 defines a four byte word
typedef unsigned int UINT4;

// convenient object t hat wraps
// the C-functions for use in C++ only
class MD5 {
public:
	MD5();
	virtual ~MD5();

private:
	MD5(const MD5& obj);
	void operator=(const MD5& obj);

private:
	struct Context {
		UINT4 state[4];                                   /* state (ABCD) */
		UINT4 count[2];        /* number of bits, modulo 2^64 (lsb first) */
		unsigned char buffer[64];                         /* input buffer */
	} context ;

	// #pragma region static helper functions
	// The core of the MD5 algorithm is here.
	// MD5 basic transformation. Transforms state based on block.
	static void MD5Transform(UINT4 state[4], unsigned char block[64]);

	// Encodes input (UINT4) into output (unsigned char). Assumes len is
	// a multiple of 4.
	static void Encode(unsigned char* output, UINT4* input, unsigned int len);

	// Decodes input (unsigned char) into output (UINT4). Assumes len is
	// a multiple of 4.
	static void Decode(UINT4 *output, unsigned char *input, unsigned int len);

public:
	void Init();

	// MD5 block update operation. Continues an MD5 message-digest
	// operation, processing another message block, and updating the
	// context.
	void Update(unsigned char *input, unsigned int inputLen);

	// MD5 finalization. Ends an MD5 message-digest operation, writing the
	// the message digest and zeroizing the context.
	// Writes to digestRaw
	void Final();

	/// Buffer must be 32+1 (nul) = 33 chars long at least 
	void WriteToString();


public:
	// an MD5 digest is a 16-byte number (32 hex digits)
	BYTE digestRaw[16] ;

	// This version of the digest is actually
	// a "printf'd" version of the digest.
	char digestChars[33] ;

	/// Load a file from disk and digest it
	// Digests a file and returns the result.
	const char* DigestFile( const char *filename);

	/// Digests a byte-array already in memory
	const char* DigestMemory( BYTE *memchunk, int len);

	// Digests a string and prints the result.
	const char* DigestString(const char *string);
};

bool Md5String(const char* str, std::string& res);
bool Md5File(const char* filepath, std::string& res);

} //end namespace Util
#endif  //CPPUTIL_CPP_UTIL_MD5_H
