//
//  LJJ_MD5.h
//  Sha1AndMD5Test
//
//  Created by peony on 2018/6/11.
//  Copyright © 2018年 peony. All rights reserved.
//

#ifndef LJJ_MD5_h
#define LJJ_MD5_h

#include <stdio.h>

///MD5的结果数据长度
static const size_t LJJ_MD5_HASH_SIZE   = 16;

/**
 计算一个字符串的MD5摘要

 @param buf 待计算MD5的字符串
 @param size 待计算MD5的长度
 @return 返回结果（因为结果是base64编码后的字符串，base64文件内部使用了malloc，但未调用free。所以返回的字符串使用完成后需释放）
 */
unsigned char *LJJ_MD5(const char *buf,
                       size_t size);

#endif /* LJJ_MD5_h */
