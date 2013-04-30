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

/** @class Playlist playlist.h "xmmsclient/xmmsclient++/playlist.h"
 *  @brief This class controls the playlist
 */
class Playlist
{

	public:
    static void Init();
  
  private:
    Playlist();
    ~Playlist();
    
		static v8::Persistent<v8::Function> constructor;
		static v8::Handle<v8::Value> New(const v8::Arguments& args);

		/** Get the list of saved playlists.
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 */
		static v8::Handle<v8::Value> list(const v8::Arguments& args);

		/** Create a new empty playlist.
		 *
		 *  @param playlist the name of the playlist to create.
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 */
		static v8::Handle<v8::Value> create(const v8::Arguments& args);

		/** Load a saved playlist and make it the active playlist.
		 *
		 *  @param playlist the playlist to load.
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 */
		static v8::Handle<v8::Value> load(const v8::Arguments& args);

		/**	Add the url to a playlist.
		 *  The url should be absolute to the server-side. 
		 *  Note that you will have to include the protocol 
		 *  for the url to. ie: file://mp3/my_mp3s/first.mp3.
		 *  
		 *  @param url file to be added
		 *  @param playlist the playlist to modify (if omitted,
		 *                  act on the current playlist)
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 */
		static v8::Handle<v8::Value> addUrl(const v8::Arguments& args);

		/**	Add the url to a playlist.
		 *  Same as #addUrl but takes an encoded URL instead
		 *  
		 *  @param url file to be added
		 *  @param playlist the playlist to modify (if omitted,
		 *                  act on the current playlist)
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 */
		static v8::Handle<v8::Value> addUrlEncoded(const v8::Arguments& args);

		/**	Add the directory recursively to a playlist.
		 *  The url should be absolute to the server-side. 
		 *  Note that you will have to include the protocol 
		 *  for the url to. ie: file://mp3/my_mp3s/directory
		 *  
		 *  @param url directory to be added
		 *  @param playlist the playlist to modify (if omitted,
		 *                  act on the current playlist)
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 */
		static v8::Handle<v8::Value> addRecursive(const v8::Arguments& args);

		/**	Add the directory recursivly to a playlist.
		 *  Same as #addRecursive but takes a encoded URL instead.
		 *  
		 *  @param url directory to be added
		 *  @param playlist the playlist to modify (if omitted,
		 *                  act on the current playlist)
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 */
		static v8::Handle<v8::Value> addRecursiveEncoded(const v8::Arguments& args);

		/** Add a medialib id to a playlist.
		 *
		 *  @param id A medialib ID
		 *  @param playlist the playlist to modify (if omitted,
		 *                  act on the current playlist)
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 */
		static v8::Handle<v8::Value> addId(const v8::Arguments& args);

		/** Add an idlist to a playlist.
		 *
		 *  @param idlist an ID list
		 *  @param playlist the playlist to modify (if omitted,
		 *                  act on the current playlist)
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 *  @throw std::bad_cast If idlist is not a valid const Coll::Idlist&.
		 */
		static v8::Handle<v8::Value> addIdlist(const v8::Arguments& args);

		/**	Add the content of the given collection to a playlist.
		 *  The list of ordering properties defines how the set of
		 *  matching media is added.
		 *
		 *  @param collection The collection from which media will
		 *                    be added to the playlist.
		 *  @param order The order in which the matched media are added.
		 *  @param playlist the playlist to modify (if omitted,
		 *                  act on the current playlist)
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 */
		static v8::Handle<v8::Value> addCollection(const v8::Arguments& args);

		/** Clears a playlist.
		 *
		 *  @param playlist the playlist to modify (if omitted,
		 *                  act on the current playlist)
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 */
		static v8::Handle<v8::Value> clear(const v8::Arguments& args);

		/** Retrieve the current position in a playlist.
		 *
		 *  @param playlist the playlist to consider (if omitted,
		 *                  act on the current playlist)
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 *
		 *  @return Dict containing then name of a playlist in 'name' and
		 *  the current position in that playlist as integer in 'position'.
		 */
		static v8::Handle<v8::Value> currentPos(const v8::Arguments& args);

		/** Retrieve the name of the current active playlist.
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 *
		 *  @return current position as integer.
		 */
		static v8::Handle<v8::Value> currentActive(const v8::Arguments& args);

		/** Insert an entry at given position in a playlist.
		 *  
		 *  @param pos A position in the playlist.
		 *  @param url The URL to insert.
		 *  @param playlist the playlist to modify (if omitted,
		 *                  act on the current playlist)
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 */
		static v8::Handle<v8::Value> insertUrl(const v8::Arguments& args);

		/** Insert an entry at given position in a playlist.
		 *  Same as #insertUrl but takes a encoded url instead.
		 *  
		 *  @param pos A position in the playlist.
		 *  @param url The URL to insert.
		 *  @param playlist the playlist to modify (if omitted,
		 *                  act on the current playlist)
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 */
		static v8::Handle<v8::Value> insertUrlEncoded(const v8::Arguments& args);

		/** Insert a medialib ID at given position in a playlist.
		 *
		 *  @param pos A position in the playlist.
		 *  @param id A medialib ID.
		 *  @param playlist the playlist to modify (if omitted,
		 *                  act on the current playlist)
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 */
		static v8::Handle<v8::Value> insertId(const v8::Arguments& args);

		/**	Add the content of the given collection to a playlist.
		 *  The list of ordering properties defines how the set of
		 *  matching media is added.
		 *
		 *  @param pos A position in the playlist.
		 *  @param collection The collection from which media will
		 *                    be added to the playlist.
		 *  @param order The order in which the matched media are added.
		 *  @param playlist the playlist to modify (if omitted,
		 *                  act on the current playlist)
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 */
		static v8::Handle<v8::Value> insertCollection(const v8::Arguments& args);

		/**	Insert the directory recursively at a given position in a
		 *  playlist.
		 *  The url should be absolute to the server-side.
		 *  Note that you will have to include the protocol
		 *  for the url to. ie: file://mp3/my_mp3s/directory
		 *
		 *  @param pos A position in the playlist.
		 *  @param url directory to be added
		 *  @param playlist the playlist to modify (if omitted,
		 *                  act on the current playlist)
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 */
		static v8::Handle<v8::Value> insertRecursive(const v8::Arguments& args);

		/**	Insert the directory recursivly at a given position in a
		 *  playlist.
		 *  Same as #insertRecursive but takes a encoded URL instead.
		 *
		 *  @param pos A position in the playlist.
		 *  @param url directory to be added
		 *  @param playlist the playlist to modify (if omitted,
		 *                  act on the current playlist)
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 */
		static v8::Handle<v8::Value> insertRecursiveEncoded(const v8::Arguments& args);

		/** Retrieve the entries in a playlist.
		 *
		 *  @param playlist the playlist to consider (if omitted,
		 *                  act on the current playlist)
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 *
		 *  @return A List of medialib IDs
		 */
		static v8::Handle<v8::Value> listEntries(const v8::Arguments& args);

		/** Move a playlist entry to a new position (absolute move).
		 * 
		 *  @param curpos Position of the entry to be moved.
		 *  @param newpos Position where the entry should be moved to.
		 *  @param playlist the playlist to modify (if omitted,
		 *                  act on the current playlist)
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 */
		static v8::Handle<v8::Value> moveEntry(const v8::Arguments& args);

		/** Remove an entry from a playlist.
		 * 
		 *  @param pos The position that should be 
		 *             removed from the playlist.
		 *  @param playlist the playlist to modify (if omitted,
		 *                  act on the current playlist)
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 */
		static v8::Handle<v8::Value> removeEntry(const v8::Arguments& args);

		/** Removes a playlist.
		 *
		 *  @param playlist the playlist to remove.
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 */
		static v8::Handle<v8::Value> remove(const v8::Arguments& args);

		/** Set next entry in the playlist.
		 * 
		 *  @param pos A position to jump to.
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 */
		static v8::Handle<v8::Value> setNext(const v8::Arguments& args);

		/** Same as setNext but relative to the current position.
		 *
		 *  -1 will back one and 1 will move to the next entry.
		 *
		 *  @param pos Relative position for the jump.
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 */
		static v8::Handle<v8::Value> setNextRel(const v8::Arguments& args);

		/** Shuffles a playlist.
		 *
		 *  @param playlist the playlist to modify (if omitted,
		 *                  act on the current playlist)
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 */
		static v8::Handle<v8::Value> shuffle(const v8::Arguments& args);

		/** Sorts a playlist according to a list of properties.
		 * 
		 *  @param properties Properties to sort by.
		 *  @param playlist the playlist to modify (if omitted,
		 *                  act on the current playlist)
		 *
		 *  @throw connection_error If the client isn't connected.
		 *  @throw mainloop_running_error If a mainloop is running -
		 *  sync functions can't be called when mainloop is running. This
		 *  is only thrown if the programmer is careless or doesn't know
		 *  what he/she's doing. (logic_error)
		 *  @throw result_error If the operation failed.
		 */
		static v8::Handle<v8::Value> sort(const v8::Arguments& args);

		/** Request the playlist changed broadcast from the server.
		 *
		 *  Everytime someone manipulates the playlist this will be emitted.
		 *
		 *  @param slot Function pointer to a function taking a
		 *              const Dict& and returning a bool.
		 *  @param error Function pointer to an error callback
		 *               function. (<b>optional</b>)
		 *
		 *  @throw connection_error If the client isn't connected.
		 */
		static v8::Handle<v8::Value> broadcastChanged(const v8::Arguments& args);

		/** Request the playlist current position broadcast.
		 *
		 *  When the position in the playlist is
		 *  changed this will be called.
		 *
		 *  @param slot Function pointer to a function taking a
		 *              const Dict& and returning a bool.
		 *              Dict contains then name of a playlist
		 *              in 'name' and the updated position in
		 *              that playlist as integer in 'position'.
		 *  @param error Function pointer to an error callback
		 *               function. (<b>optional</b>)
		 *
		 *  @throw connection_error If the client isn't connected.
		 */
		static v8::Handle<v8::Value> broadcastCurrentPos(const v8::Arguments& args);

		/** Request the playlist loaded broadcast from the server.
		 *
		 *  Everytime someone loads a saved playlist this will be emitted.
		 *
		 *  @param slot Function pointer to a function taking a
		 *              const string& and returning a bool.
		 *  @param error Function pointer to an error callback
		 *               function. (<b>optional</b>)
		 *
		 *  @throw connection_error If the client isn't connected.
		 */
		static v8::Handle<v8::Value> broadcastLoaded(const v8::Arguments& args);

};

#endif
