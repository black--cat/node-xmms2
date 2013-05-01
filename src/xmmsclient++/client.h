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

/** @class Client client.h "xmmsclient/xmmsclient++/client.h"
 *  @brief This class is used to control everything through various
 *         Subsystems.
 *  
 *  You can access the subsystems directly from the public data fields
 *  described above.
 */
class Client : public node::ObjectWrap
{

	public:
    static void Init(v8::andle<v8::Object> target);
  
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
		static v8::Handle<v8::Value> Connect(const v8::Arguments& args);

		/** Tell the server to quit.
		 *  This will terminate the server. Destruct this object if you
		 *  just want to disconnect.
		 */
		static v8::Handle<v8::Value> Disconnect(const v8::Arguments& args);

		/** Return the connection status.
		 */
		static v8::Handle<v8::Value> IsConnected(const v8::Arguments& args);
    
    
    static Xmms2::Client _client;
    
};

