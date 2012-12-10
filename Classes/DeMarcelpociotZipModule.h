/**
 * Marcel Pociot 2012
 *
 * Appcelerator Titanium is Copyright (c) 2009-2010 by Appcelerator, Inc.
 * and licensed under the Apache Public License (version 2)
 */
#import "TiModule.h"

@interface DeMarcelpociotZipModule : TiModule
{
    KrollCallback *startCallback;
    KrollCallback *successCallback;
    KrollCallback *errorCallback;
    KrollCallback *progressCallback;
}

@end
