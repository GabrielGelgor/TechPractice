const http = require('http');

const hostname = '127.0.0.1';
const port = 3000;

var connect = require('connect');
var serveStatic = require('serve-static');

connect().use(serveStatic(__dirname)).listen(8000, function(){
    console.log('Server running on 8000...');
})
