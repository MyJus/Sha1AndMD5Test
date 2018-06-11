//
//  LJJ_MD5AndSha1Handle.h
//  Sha1AndMD5Test
//
//  Created by peony on 2018/6/11.
//  Copyright © 2018年 peony. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LJJ_MD5AndSha1Handle : NSObject

//基本上可以满足散列算法（改变较少，得到的数据差别较大）
+ (NSString *)LJJ_sha1:(NSString *)param;
+ (NSString *)LJJ_MD5:(NSString *)param;

@end
