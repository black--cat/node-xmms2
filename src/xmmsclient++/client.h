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

/** @class Client client.h "xmmsclient/xmmsclient++/client.h"
 *  @brief This class is used to control everything through various
 *         Subsystems.
 *  
 *  You can access the subsystems directly from the public data fields
 *  described above.
 */
class Client 
{

	public:
    static void Init();
  
  private:
    Client();
    ~Client();
    
		static v8::Persistent<v8::Function> constructor;
		static v8::Handle<v8::Value> New(const v8::Arguments& args);

		/** Connects to the XMMS2 server.
		 *  if ipcpath is omitted or 0, it will try to open
		 *  the default path.
		 *
		 *  @param ipcpath The IPC path. It's broken down like this:
		 *                 @<protocol@>://@<path@>[:@<port@>]. Default is
		 *                 "unix:///tmp/xmms-ipc-@<username@>".
		 *                 - Protocol could be "tcp" or "unix".
		 *                 - Path is either the UNIX socket,
		 *                   or the ipnumber of the server.
		 *                 - Port is only used when the protocol tcp.
		 *  @throw connection_error If connection fails.
		 */
		static v8::Handle<v8::Value> connect(const v8::Arguments& args);

		/** Tell the server to quit.
		 *  This will terminate the server. Destruct this object if you
		 *  just want to disconnect.
		 */
		static v8::Handle<v8::Value> disconnect(const v8::Arguments& args);

		/** Get the current mainloop.
		 *  If no mainloop is set, it will create a default MainLoop.
		 *  
		 *  @return Reference to the current mainloop object.
		 */
		static v8::Handle<v8::Value> getMainLoop(const v8::Arguments& args);

		/** Set the mainloop which is to be used.
		 *  
		 *  @param ml A mainloop class derived from MainloopInterface.
		 *
		 *  @note The parameter @b must be created with <i>new</i>,
		 *        and it must @b not be destructed at any point.
		 *        The Client class will take care of its destruction.
		 */
		void setMainloop(const v8::Arguments& args);

		/** Set disconnection callback.
		 *  
		 *  @param slot A function pointer with function signature void()
		 */
		void setDisconnectCallback(const v8::Arguments& args);

		/** Return the connection status.
		 */
		static v8::Handle<v8::Value> isConnected(const v8::Arguments& args);

		/** Return the internal connection pointer.
		 */
		static v8::Handle<v8::Value> getConnection(const v8::Arguments& args);

};

#endif
