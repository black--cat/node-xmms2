/*  XMMS2 - X Music Multiplexer System
 *  Copyright (C) 2003-2013 XMMS2 Team
 *
 *  PLUGINS ARE NOT CONSIDERED TO BE DERIVED WORK !!!
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 */

#define BUILDING_NODE_EXTENSION
#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <node.h>
#include <string>

/** @class Playback playback.h "xmmsclient/xmmsclient++/playback.h"
 *  @brief This class controls the playback.
 */
class Playback 
{

	public:
    static void Init();
  
  private:
    Playback();
    ~Playback();
    
		static v8::Persistent<v8::Function> constructor;
		static v8::Handle<v8::Value> New(const v8::Arguments& args);

		/** Stop decoding of current song.
		 *
		 *  This will start decoding of the song set with
		 *  Playlist::setNext, or the current song again if no
		 *  Playlist::setNext was executed.
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 */
		static v8::Handle<v8::Value> tickle(const v8::Arguments& args);

		/** Stops the current playback.
		 * 
		 *  This will make the server idle.
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 */
		static v8::Handle<v8::Value> stop(const v8::Arguments& args);

		/** Pause the current playback,
		 *  will tell the output to not read nor write.
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 */
		static v8::Handle<v8::Value> pause(const v8::Arguments& args);

		/** Starts playback if server is idle.
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 */
		static v8::Handle<v8::Value> start(const v8::Arguments& args);

		/** Seek to a absolute time in the current playback.
		 *
		 *  @param milliseconds The total number of ms where
		 *                      playback should continue.
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 */
		static v8::Handle<v8::Value> seekMs(const v8::Arguments& args);

		/** Seek to a time relative to the current position 
		 *  in the current playback.
		 *
		 *  @param milliseconds The offset in ms from the current
		 *                      position to where playback should continue.
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 */
		static v8::Handle<v8::Value> seekMsRel(const v8::Arguments& args);

		/** Seek to a absolute number of samples in the current playback.
		 *
		 *  @param samples The total number of samples where
		 *                 playback should continue.
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 */
		static v8::Handle<v8::Value> seekSamples(const v8::Arguments& args);

		/** Seek to a number of samples relative to the current
		 *  position in the current playback.
		 *
		 *  @param samples The offset in number of samples from the current
		 *                 position to where playback should continue.
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 */
		static v8::Handle<v8::Value> seekSamplesRel(const v8::Arguments& args);

		/** Make server emit the current id.
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 *
		 *  @return The currently playing ID.
		 */
		static v8::Handle<v8::Value> currentID(const v8::Arguments& args);

		/** Make server emit the playback status.
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 *
		 *  @return Playback status, compare with
		 *          Playback::[STOPPED|PLAYING|PAUSED]
		 */
		static v8::Handle<v8::Value> getStatus(const v8::Arguments& args);

		/** Make server emit the current playtime.
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 *
		 *  @return The playtime in milliseconds.
		 */
		static v8::Handle<v8::Value> getPlaytime(const v8::Arguments& args);

		/** Set the volume of a channel.
		 *
		 *  @param channel Name of the channel.
		 *  @param volume Volume within range [0-100].
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 */
		static v8::Handle<v8::Value> volumeSet(const v8::Arguments& args);

		/** Get a channel<->volume list from the server.
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 *
		 *  @return A Dict containing channel<->volume pairs.
		 */
		static v8::Handle<v8::Value> volumeGet(const v8::Arguments& args);

		static v8::Handle<v8::Value> broadcastCurrentID(const v8::Arguments& args);
		static v8::Handle<v8::Value> broadcastStatus(const v8::Arguments& args);
		static v8::Handle<v8::Value> broadcastVolumeChanged(const v8::Arguments& args);
		static v8::Handle<v8::Value> signalPlaytime(const v8::Arguments& args);

};

#endif
