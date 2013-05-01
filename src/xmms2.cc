
#include <cstdlib>
#include <iostream>
#include <string>
#include <node.h>
#include <xmmsclient/xmmsclient++.h>

#include "xmmsclient++/client.h"

static void InitAll (Handle<Object> target) {
    HandleScope scope;
    Client::Init(target);
}

NODE_MODULE(xmms2, InitAll);

