/* ---------------------------------------------------------------------------
** This software is in the public domain, furnished "as is", without technical
** support, and with no warranty, express or implied, as to its usefulness for
** any purpose.
**
** HttpServerRequestHandler.h
** 
** -------------------------------------------------------------------------*/

#pragma once

#include <list>
#include <map>
#include <functional>

#include "json/json.h"
#include "CivetServer.h"


/* ---------------------------------------------------------------------------
**  http callback
** -------------------------------------------------------------------------*/
class HttpServerRequestHandler : public CivetServer
{
	public:
		typedef std::function<Json::Value(const struct mg_request_info *, const Json::Value &)> httpFunction;
	
		HttpServerRequestHandler(std::map<std::string,httpFunction>& func, const std::vector<std::string>& options); 
	
		void addWebsocketConnection(const struct mg_connection *conn);
		void delWebsocketConnection(const struct mg_connection *conn);
	
		void notifyWebsocketConnection(const char* buf, unsigned int size);
				
	protected:
		std::list<const struct mg_connection *> m_ws;
};


