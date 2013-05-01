
#define BUILDING_NODE_EXTENSION

using namespace v8;

Persistent<Function> Client::constructor;

Client::Init(Handle<Object> target) {
  Local<FunctionTemplate> tpl = FunctionTemplate::New(New);
  Local<ObjectTemplate> instance = tpl->InstanceTemplate();
  
  instance->SetInternalFieldCount(1);
  
  instance->Set(String::NewSymbol("connect"),
      FunctionTemplate::New(Connect)->GetFunction());

  instance->Set(String::NewSymbol("disconnect"),
      FunctionTemplate::New(Disconnect)->GetFunction());

  instance->Set(String::NewSymbol("isConnected"),
      FunctionTemplate::New(IsConnected)->GetFunction());
  
  Persistent<Function> constructor = Persistent<Function>::New(tpl->GetFunction());
  
  constructor = Persistent<Function>::New(tpl->GetFunction());
  target->Set(String::NewSymbol("Client"), constructor);
}

Handle<Value> Client::New(const Arguments& args) {
  Client* client = new Client();
  client->Wrap(args.Holder());
  // _client(args[0].toString());
  return args.Holder();
}

Handle<Value> Client::Connect(const Arguments& args) {
  Client *client = Unwrap<Client>(args.Holder());
  // _client.connect(args[0].toString());
  return Undefined();
}

Handle<v8::Value> Disconnect(const v8::Arguments& args) {
  // _client.disconnect();
  return Undefined();
}

Handle<v8::Value> IsConnected(const v8::Arguments& args) {
  HandleScope scope;
  return scope.Close(Boolean::New(_client.isConnected()));
}

