//
//  LJJ_sha1.h
//  Sha1AndMD5Test
//
//  Created by peony on 2018/6/11.
//  Copyright © 2018年 peony. All rights reserved.
//

#ifndef LJJ_sha1_h
#define LJJ_sha1_h

#include <stdio.h>
///SHA1的结果数据长度
static const size_t LJJ_SHA1_HASH_SIZE  = 20;




/*!
 @brief      求内存块BUFFER的SHA1值
 @return     unsigned char* 返回的的结果（因为结果是base64编码后的字符串，base64文件内部使用了malloc，但未调用free。所以返回的字符串使用完成后需释放）
 @param[in]  buf    求SHA1的内存BUFFER指针
 @param[in]  size   BUFFER长度
 */
unsigned char *LJJ_sha1(const char *buf,
                        size_t size);

#endif /* LJJ_sha1_h */
