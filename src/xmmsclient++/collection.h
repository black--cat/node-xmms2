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

/** @class Collection collection.h "xmmsclient/xmmsclient++/collection.h"
 *  @brief This class controls the collections on the server.
 */
class Collection
{

	public:
    static void Init();
  
  private:
    Collection();
    ~Collection();
    
		static v8::Persistent<v8::Function> constructor;
		static v8::Handle<v8::Value> New(const v8::Arguments& args);

		/** Get the structure of a collection saved on the server.
		 *
		 *  @param name The name of the collection on the server.
		 *  @param nsname The namespace in which to look for the collection.
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 *
		 *  @return a pointer to a Coll::Coll object representing
		 *  the collection structure.
		 */
		static v8::Handle<v8::Value> get(const v8::Arguments& args);

		/** List the names of collections saved in the given namespace.
		 *
		 *  @param nsname Namespace to list collection names from.
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 *
		 *  @return a list of collection names in the given namespace.
		 */
		static v8::Handle<v8::Value> list(const v8::Arguments& args);

		/** Save a collection structure under a given name in a
		 *  certain namespace on the server.
		 *
		 *  @param coll The collection structure to save.
		 *  @param name The name under which to save the collection.
		 *  @param nsname The namespace in which to save the collection.
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 */
		static v8::Handle<v8::Value> save(const v8::Arguments& args);

		/** Remove the collection given its name and its namespace.
		 *
		 *  @param name The name of the collection to remove.
		 *  @param nsname The namespace from which to remove the collection.
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 */
		static v8::Handle<v8::Value> remove(const v8::Arguments& args);

		/** List the names of collections that contain a given media.
		 *
		 *  @param id The id of the media.
		 *  @param nsname The namespace in which to look for collections.
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 *
		 *  @return a list of collection names.
		 */
		static v8::Handle<v8::Value> find(const v8::Arguments& args);

		/** Rename the collection given its name and its namespace.
		 *  @note A collection cannot be moved to another namespace.
		 *
		 *  @param from_name The name of the collection to rename.
		 *  @param to_name The new name for the collection.
		 *  @param nsname The namespace in which the collection to rename is.
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 */
		static v8::Handle<v8::Value> rename(const v8::Arguments& args);

		/** Import the content of a playlist file (.m3u, .pls,
		 *  etc) into the medialib and return an idlist collection
		 *  containing the imported media.
		 *
		 *  @param path The path to the playlist file.
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 *
		 *  @return a pointer to a #Coll::Idlist object containing
		 *  the ids of media imported from the playlist file.
		 */
		static v8::Handle<v8::Value> idlistFromPlaylistFile(const v8::Arguments& args);

		/** Retrieve the ids of media matched by a collection.
		 *  To query the content of a saved collection, use a
		 *  Reference operator.
		 *
		 *  @param coll The collection to query.
		 *  @param order The list of properties by which to order
		 *               the matching media.
		 *  @param limit_len Optional argument to limit the
		 *                   maximum number of media to retrieve.
		 *  @param limit_start Optional argument to set the offset
		 *                     at which to start retrieving media.
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 *
		 *  @return a list of media ids matched by the collection.
		 */
		static v8::Handle<v8::Value> queryIds(const v8::Arguments& args);

		/** Retrieve the properties of media matched by a collection.
		 *  To query the content of a saved collection, use a
		 *  Reference operator.
		 *
		 *  @param coll The collection to query.
		 *  @param fetch The list of properties to retrieve.
		 *  @param order The list of properties by which to order
		 *               the matching media.
		 *  @param limit_len Optional argument to limit the
		 *                   maximum number of media to retrieve.
		 *  @param limit_start Optional argument to set the offset
		 *                     at which to start retrieving media.
		 *  @param group The list of properties by which to group the results.
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 *
		 *  @return a list of property dicts for each media
		 *  matched by the collection.
		 */
		static v8::Handle<v8::Value> queryInfos(const v8::Arguments& args);

		/**
		 * FIXME: Comments
		 */
		static v8::Handle<v8::Value> parse(const v8::Arguments& args);

		/** Request the collection changed broadcast.
		 *
		 *  This will be called if a saved collection structure
		 *  changes on the serverside (saved, updated, renamed,
		 *  removed, etc).
		 *  The argument will be a dict containing the type, name
		 *  and namespace of the changed collection.
		 *
		 *  @param slot Function pointer to a function taking a
		 *              const Dict& and returning a bool.
		 *  @param error Function pointer to an error callback
		 *               function. (<b>optional</b>)
		 *
		 *  @throw connection_error If the client isn't connected.
		 */
		static v8::Handle<v8::Value> broadcastCollectionChanged(const v8::Arguments& args);

};

#endif
