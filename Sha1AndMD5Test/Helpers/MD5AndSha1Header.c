//
//  MD5AndSha1Header.c
//  Sha1AndMD5Test
//
//  Created by peony on 2018/6/11.
//  Copyright © 2018年 peony. All rights reserved.
//
#include "MD5AndSha1Header.h"

//将一个（字符串）数组，拷贝到另外一个uint32_t数组，同时每个uint32_t反字节序
void *swap_uint32_memcpy(void *to, const void *from, size_t length)
{
    memcpy(to, from, length);
    size_t remain_len =  (4 - (length & 3)) & 3;
    //数据不是4字节的倍数,补充0
    if (remain_len) {
        for (size_t i = 0; i < remain_len; ++i)
        {
            *((char *)(to) + length + i) = 0;

        }
        //调整成4的倍数
        length += remain_len;

    }//所有的数据反转
    for (size_t i = 0; i < length / 4; ++i) {
        ((uint32_t *)to)[i] = LJJ_SWAP_UINT32(((uint32_t *)to)[i]);

    }
    return to;
}
