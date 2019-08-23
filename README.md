# GHPlatform

GHPlatform provides a way to use common OS features for iOS, win32, uwp, android, and OSX in a platform independent way.  It also contains some C++ extensions.  It contains code we never want to have to write again, so it makes as few architectural decisions as possible.

## Dependencies
https://github.com/GoldenHammerSoftware/GHString - Install adjacent to where you install GHPlatform.

## How to use

1) Add the cpp and header files in GHPlatform to your project.
2) Add the folder where GHPlatform lives to your #includes directories.  Ie is you are in src/GHPlatform/ then add src/ to your includes search path.
3) Add the appropriate GHPlatform/[platform] files to your project.  Ie for an iOS project add the files in GHPlatform/ios.
4) In platform code instantiate the appropriate GHPlatformServices.  Ie for win32 instantiate a GHPlatformServicesWin32 inside your winmain.
5) Have your code ask the GHPlatformServices interface for the platform independent factories.
6) Use any platform independent classes directly.

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

## Sockets

*  GHSocket - Interface for sending/receiving on a platform socket.
*  GHSocketMgr - Creates sockets for the current platform.

## Time

*  GHTimeVal - Represents a point in time.
*  GHTimeCalculator - Platform interface to get the current time.
*  GHTimeUpdater - Controller for incrementing a GHTimeVal to represent the new most current point in time.

## C++ utilities

## Property 

## Message

*  GHMessage - An arbitrary chunk of data with an identifier.
*  GHMessageHandler - Interface for something that listens for a message.
*  GHEventMgr - A registry of listeners for messages by type.
*  GHMessageQueue - A thread-safe way to send out messages without an event manager dependency.

## Controller

*  GHController - Interface for something that has an update function.
*  GHControllerMgr - Manages a list of things that should update.  Activates/deactivates/sorts/calls-update.

## State machine

GHStateMachine manages switching between various states.  Each state has a list of transitions in and a list of transitions out.  We use it for things like switching from in-game to paused, with the paused transitions showing a gui and the in-game transitions pushing the physics updater and input controls.

*  GHStateMachine - A list of transitions for each state.
*  GHTransition - Interface for something that does something when entering or leaving a specific state.
*  GHControllerTransition - A transition that adds or removes a controller from a controller manager.

## Profiler

A lightweight way to get performance information about your code.

## Resource