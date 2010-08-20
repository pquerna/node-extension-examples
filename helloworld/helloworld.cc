/*
 * Licensed to Cloudkick, Inc ('Cloudkick') under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * Cloudkick licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <v8.h>
#include <node.h>
#include <node_events.h>
#include <node_buffer.h>

using namespace node;
using namespace v8;

class HelloWorld: ObjectWrap
{
private:
  int m_count;
public:

  static Persistent<FunctionTemplate> s_ct;
  static void Init(Handle<Object> target)
  {
    HandleScope scope;

    Local<FunctionTemplate> t = FunctionTemplate::New(New);

    s_ct = Persistent<FunctionTemplate>::New(t);
    s_ct->InstanceTemplate()->SetInternalFieldCount(1);
    s_ct->SetClassName(String::NewSymbol("HelloWorld"));

    NODE_SET_PROTOTYPE_METHOD(s_ct, "hello", Hello);

    target->Set(String::NewSymbol("HelloWorld"),
                s_ct->GetFunction());
  }

  HelloWorld() :
    m_count(0)
  {
  }

  ~HelloWorld()
  {
  }

  static Handle<Value> New(const Arguments& args)
  {
    HandleScope scope;
    HelloWorld* hw = new HelloWorld();
    hw->Wrap(args.This());
    return args.This();
  }

  static Handle<Value> Hello(const Arguments& args)
  {
    HandleScope scope;
    HelloWorld* hw = ObjectWrap::Unwrap<HelloWorld>(args.This());
    hw->m_count++;
    Local<String> result = String::New("Hello World");
    return scope.Close(result);
  }

};

Persistent<FunctionTemplate> HelloWorld::s_ct;

extern "C" {
  static void init (Handle<Object> target)
  {
    HelloWorld::Init(target);
  }

  NODE_MODULE(helloworld, init);
}
