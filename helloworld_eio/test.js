var helloeio = require('./build/Release/helloworld_eio');
var hi = new helloeio.HelloWorldEio();
hi.hello(function(data){
   console.log(data);
});
//Outputting something here to show that the callback is non-blocking and this
//output will be displayed before the Hello World message.
console.log('Outputted after the async call to hello world.');
