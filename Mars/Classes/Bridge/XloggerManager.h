// Tencent is pleased to support the open source community by making Mars available.
// Copyright (C) 2017 THL A29 Limited, a Tencent company. All rights reserved.
// Licensed under the MIT License (the "License"); you may not use this file except in 
// compliance with the License. You may obtain a copy of the License at
// http://opensource.org/licenses/MIT
// Unless required by applicable law or agreed to in writing, software distributed under the License is
// distributed on an "AS IS" basis, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
// either express or implied. See the License for the specific language governing permissions and
// limitations under the License.
/*
 * appender-swift-bridge.h
 *
 *  Created on: 2017-1-3
 *      Author: Jinkey
 */

#include <stdio.h>
#import "LogUtil.h"
#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, XloggerType) {
    XloggerTypeAll = kLevelAll,
    XloggerTypeVerbose = kLevelVerbose,
    XloggerTypeDebug = kLevelDebug,
    XloggerTypeInfo = kLevelInfo,
    XloggerTypeWarning = kLevelWarn,
    XloggerTypeError = kLevelError,
    XloggerTypeFatal = kLevelFatal,
    XloggerTypeNone = kLevelNone
};

#ifdef __cplusplus
#import <mars/xlog/appender.h>

typedef NS_ENUM(NSInteger, XloggerAppenderMode) {
    XloggerAppenderModeAsync = mars::xlog::kAppenderAsync,
    XloggerCompressModeSync = mars::xlog::kAppenderSync
};

typedef NS_ENUM(NSInteger, XloggerCompressMode) {
    XloggerCompressModeZlib = mars::xlog::kZlib,
    XloggerCompressModeZstd = mars::xlog::kZstd
};

#else

enum TAppenderMode
{
    kAppenderAsync,
    kAppenderSync,
};

enum TCompressMode{
    kZlib,
    kZstd,
};

typedef NS_ENUM(NSInteger, XloggerAppenderMode) {
    XloggerAppenderModeAsync = kAppenderAsync,
    XloggerCompressModeSync = kAppenderSync
};

typedef NS_ENUM(NSInteger, XloggerCompressMode) {
    XloggerCompressModeZlib = kZlib,
    XloggerCompressModeZstd = kZstd
};

#endif


@interface XLogerConfig : NSObject

@property (nonatomic, assign) XloggerAppenderMode mode;
@property (nonatomic, strong) NSString *logdir;
@property (nonatomic, strong) NSString *nameprefix;
@property (nonatomic, strong) NSString *pub_key;
@property (nonatomic, assign) XloggerCompressMode compress_mode;
@property (nonatomic, assign) int compress_level;
@property (nonatomic, strong) NSString *cachedir;
@property (nonatomic, assign) int cache_days;

@end

@interface XloggerManager: NSObject

+ (void)deinit;

+ (void)log:(XloggerType)level tag:(NSString *)tag content:(NSString *)content;

+ (void)setupWith:(XloggerType)debugLevel releaseLevel:(XloggerType)releaseLevel config:(XLogerConfig *)config;

+ (void)setupWith:(XloggerType)debugLevel releaseLevel:(XloggerType)releaseLevel path:(NSString *)path prefix:(NSString *)prefix;
+ (void)setupWith:(XloggerType)debugLevel releaseLevel:(XloggerType)releaseLevel path:(NSString *)path prefix:(NSString *)prefix isAsync:(BOOL)isAsync;
+(void)updateImmediately:(BOOL) isAsync;
@end
