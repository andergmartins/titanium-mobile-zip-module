//
//  ZipArchive.h
//
//
//  Created by aish on 08-9-11.
//  acsolu@gmail.com
//  Copyright 2008  Inc. All rights reserved.
//
// History:
//    09-11-2008 version 1.0    release
//    10-18-2009 version 1.1    support password protected zip files
//    10-21-2009 version 1.2    fix date bug
//    01-10-2012 version 1.3    titanium improvements (m.pociot@gmail.com)

#import <UIKit/UIKit.h>
#import "TiModule.h"

#include "minizip/zip.h"
#include "minizip/unzip.h"
#include "DeMarcelpociotZipModule.h"


@protocol ZipArchiveDelegate <NSObject>
@optional
-(void) ErrorMessage:(NSString*) msg;
-(BOOL) OverWriteOperation:(NSString*) file;

@end


@interface ZipArchive : NSObject {
@public
    NSMutableArray* unzippedFiles;
@private
	zipFile		_zipFile;
	unzFile		_unzFile;

	NSString*   _password;
	id			_delegate;
}
@property (nonatomic, retain) NSMutableArray *unzippedFiles;
@property (nonatomic, retain) id delegate;

-(BOOL) CreateZipFile2:(NSString*) zipFile;
-(BOOL) CreateZipFile2:(NSString*) zipFile Password:(NSString*) password;
-(BOOL) addFileToZip:(NSString*) file newname:(NSString*) newname;
-(BOOL) CloseZipFile2;

-(BOOL) UnzipOpenFile:(NSString*) zipFile withStartCallback:(KrollCallback*) startCallback withEventDispatcher:(DeMarcelpociotZipModule*) eventDispatcher;
-(BOOL) UnzipOpenFile:(NSString*) zipFile Password:(NSString*) password withStartCallback:(KrollCallback*) startCallback withEventDispatcher:(DeMarcelpociotZipModule*) eventDispatcher;
-(BOOL) UnzipFileTo:(NSString*) path overWrite:(BOOL) overwrite originalFileName:(NSString*) originalFile withProgressCallback:(KrollCallback*) progressCallback withEventDispatcher:(DeMarcelpociotZipModule*) eventDispatcher;
-(BOOL) UnzipCloseFile;
@end
