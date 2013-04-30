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

/** @class Xform xform.h "xmmsclient/xmmsclient++/xform.h"
 *  @brief This class controls the xform object.
 */
class Xform
{
	public:
    static void Init();
  
  private:
    Xform();
    ~Xform();
    
		static v8::Persistent<v8::Function> constructor;
		static v8::Handle<v8::Value> New(const v8::Arguments& args);

		/** Browse available media in a path.
		 *  A list of paths available (directly) under the
		 *  specified path is returned.
		 *
		 *  @param url Path to browse.
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 *
		 *  @return a list of information dict for each path.
		 */
		static v8::Handle<v8::Value> browse(const v8::Arguments& args);

		/** Browse available media in a path.
		 *  Same as #browse but takes an encoded path instead.
		 *
		 *  @param url Encoded path to browse.
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 *
		 *  @return a list of information dict for each path.
		 */
		static v8::Handle<v8::Value> browseEncoded(const v8::Arguments& args);

};

#endif
