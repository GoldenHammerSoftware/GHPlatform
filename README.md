# GHPlatform

GHPlatform provides a way to use common OS features for iOS, win32, uwp, android, and OSX in a platform independent way.  It also contains some C++ extensions.  It contains code we never want to have to write again, so it makes as few architectural decisions as possible.

## Dependencies
https://github.com/GoldenHammerSoftware/GHString

## How to use

1) Add the cpp and header files in GHPlatform to your project.
2) Add the folder where GHPlatform lives to your #includes directories.  Ie is you are in src/GHPlatform/ then add src/ to your includes search path.
3) Add the appropriate GHPlatform/[platform] files to your project.  Ie for an iOS project add the files in GHPlatform/ios.
4) In platform code instantiate the appropriate GHPlatformServices.  Ie for win32 instantiate a GHPlatformServicesWin32 inside your winmain.
5) Have your code ask the GHPlatformServices interface for the platform independent factories.
6) Use any files inside bytestream or lang directly.

## Debug output

Printf does not always do what you would expect on every platform.  Instead include "GHPlatform/GHDebugMessage.h" and use GHDebugMessage::outputString("message");

## File access

*  GHFileOpener - Platform independent file opener.  Add resource paths to look in multiple directories.
*  GHFile - Platform independent file access.
*  GHFileC / GHFOpenFileOpener - fopen implementation of file access.
*  GHXorFile - A simple xor encrypted file wrapper for mild security.

## Bytestream

Bytestream is a way to efficiently iterate a stream of data.  We've used this in beat line to process streaming song data.  It can be used as an interface for dealing with data that could come from either a file on disk or a streaming internet feed.

## Threads

## Sockets (WIP)

## Time

## C++ utilities

## GHProperty