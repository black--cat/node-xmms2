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

/** @class Config config.h "xmmsclient/xmmsclient++/config.h"
 *  @brief This class controls the configuration values in the server.
 */
class Config
{

	public:
    static void Init();
  
  private:
    Config();
    ~Config();
    
		static v8::Persistent<v8::Function> constructor;
		static v8::Handle<v8::Value> New(const v8::Arguments& args);

		/** Registers a config value in the server.
		 *  
		 *  @param name should be @<clientname@>.myval
		 *              like cli.path or something like that.
		 *  @param defval The default value for this config value.
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 */
		static v8::Handle<v8::Value> valueRegister(const v8::Arguments& args);

		/** Sets a config value in the server.
		 *
		 *  @param key Key of the config value to set.
		 *  @param value Value for the config key.
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 */
		static v8::Handle<v8::Value> valueSet(const v8::Arguments& args);

		/** Gets the value of a config key.
		 *  
		 *  @param key Key of the config value to get.
		 *
		 *  @return String holding the value of the key.
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 */
		static v8::Handle<v8::Value> valueGet(const v8::Arguments& args);

		/** Gets a key<->value list of config values from the server.
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 *  
		 *  @return Dict containing all configuration keys and their values.
		 */
		static v8::Handle<v8::Value> valueList(const v8::Arguments& args);

		/** Requests the <i>config value changed</i> broadcast.
		 *
		 *  @param slot Function pointer to a function taking
		 *              const Dict& and returning a bool.
		 *  @param error Function pointer to an error callback
		 *               function. (<b>optional</b>)
		 *
		 *  @throw connection_error If the client isn't connected.
		 */
		static v8::Handle<v8::Value> broadcastValueChanged(const v8::Arguments& args);

};

#endif
