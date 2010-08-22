/* This code is PUBLIC DOMAIN, and is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND. See the accompanying 
 * LICENSE file.
 */

HelloWorldJs = function() {
  this.m_count = 0;
};


HelloWorldJs.prototype.hello = function()
{
  this.m_count++;
  return "Hello World";
};

exports.HelloWorldJs = HelloWorldJs;
