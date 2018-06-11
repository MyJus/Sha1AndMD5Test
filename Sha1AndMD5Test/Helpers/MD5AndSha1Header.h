//
//  MD5AndSha1Header.h
//  Sha1AndMD5Test
//
//  Created by peony on 2018/6/11.
//  Copyright © 2018年 peony. All rights reserved.
//

#ifndef MD5AndSha1Header_h
#define MD5AndSha1Header_h

#include <string.h>
#include <stdint.h>
#include <assert.h>
#include "js_base_64.h"

//字节序的小头和大头的问题
#define LJJ_LITTLE_ENDIAN  0x0123
#define LJJ_BIG_ENDIAN     0x3210

//目前所有的代码都是为了小头党服务的，不知道有生之年这套代码是否还会为大头党服务一次？
#ifndef LJJ_BYTES_ORDER
#define LJJ_BYTES_ORDER    LJJ_LITTLE_ENDIAN
#endif
#ifndef LJJ_SWAP_UINT16

#define LJJ_SWAP_UINT16(x)  ((((x) & 0xff00) >>  8) | (((x) & 0x00ff) <<  8))
#endif
#ifndef LJJ_SWAP_UINT32
#define LJJ_SWAP_UINT32(x)  ((((x) & 0xff000000) >> 24) | (((x) & 0x00ff0000) >>  8) | \
(((x) & 0x0000ff00) <<  8) | (((x) & 0x000000ff) << 24))
#endif
#ifndef LJJ_SWAP_UINT64
#define LJJ_SWAP_UINT64(x)  ((((x) & 0xff00000000000000) >> 56) | (((x) & 0x00ff000000000000) >>  40) | \
(((x) & 0x0000ff0000000000) >> 24) | (((x) & 0x000000ff00000000) >>  8) | \
(((x) & 0x00000000ff000000) << 8 ) | (((x) & 0x0000000000ff0000) <<  24) | \
(((x) & 0x000000000000ff00) << 40 ) | (((x) & 0x00000000000000ff) <<  56))
#endif

#define ROTL32(dword, n) ((dword) << (n) ^ ((dword) >> (32 - (n))))
#define ROTR32(dword, n) ((dword) >> (n) ^ ((dword) << (32 - (n))))
#define ROTL64(qword, n) ((qword) << (n) ^ ((qword) >> (64 - (n))))
#define ROTR64(qword, n) ((qword) >> (n) ^ ((qword) << (64 - (n))))

void *swap_uint32_memcpy(void *to, const void *from, size_t length);


#endif /* MD5AndSha1Header_h */
