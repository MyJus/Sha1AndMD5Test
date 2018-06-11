//
//  LJJ_MD5AndSha1Handle.m
//  Sha1AndMD5Test
//
//  Created by peony on 2018/6/11.
//  Copyright © 2018年 peony. All rights reserved.
//

#import "LJJ_MD5AndSha1Handle.h"
#import "LJJ_sha1.h"
#import "LJJ_MD5.h"

@implementation LJJ_MD5AndSha1Handle

+ (NSString *)LJJ_sha1:(NSString *)param {
    
    const char *buf = (const char *)[param cStringUsingEncoding:NSUTF8StringEncoding];
    char *sha1Char = (char*)LJJ_sha1(buf, strlen(buf));
    NSString *returnString = [NSString stringWithUTF8String:sha1Char];
    free(sha1Char);
    return returnString;
    
}

+ (NSString *)LJJ_MD5:(NSString *)param {
    const char *buf = (const char *)[param cStringUsingEncoding:NSUTF8StringEncoding];
    char *MD5Char = (char*)LJJ_MD5(buf, strlen(buf));
    NSString *returnString = [NSString stringWithUTF8String:MD5Char];
    free(MD5Char);
    return returnString;
    
}

@end
