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

/** @class Bindata bindata.h "xmmsclient/xmmsclient++/bindata.h"
 *  @brief This class handles binary data operations.
 */
class Bindata
{

	public:
    static void Init();
  
  private:
    Bindata();
    ~Bindata();
    
    static v8::Persistent<v8::Function> constructor;
    static v8::Handle<v8::Value> New(const v8::Arguments& args);

		/** Add binary data to the servers bindata directory.
		 *  
		 *  @param data Binary data to be added.
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 *
		 *  @return hash of the data which was added.
		 */
		static v8::Handle<v8::Value> add(const v8::Arguments& args);

		/** Retrieve binary data from the servers bindata directory,
		 *  based on the hash.
		 *
		 *  @param hash Hash of the binary data to fetch.
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 *
		 *  @return Binary data which matches the given hash.
		 */
	  static v8::Handle<v8::Value> retrieve(const v8::Arguments& args);

		/** Remove the binary data associated with the hash.
		 *  
		 *  @param hash Hash of the binary data to remove.
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 */
		static v8::Handle<v8::Value> remove(const v8::Arguments& args);

		/** List all bindata hashes stored on the server.
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 */
		static v8::Handle<v8::Value> list(const v8::Arguments& args);

};

#endif
