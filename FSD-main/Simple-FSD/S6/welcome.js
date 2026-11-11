const http = require('http');
const os=require('os');
const path=require('path');
const EventEmitter = require('events');
const myEvents = new EventEmitter();
myEvents.on('welcome',()=>{
    console.log("Welcome event occured");
});
myEvents.emit('welcome');
const server= http.createServer((req,res)=>{
    if(req.url==='/details'){
        res.writeHead(200,{'Content-Type':'text/html'});
        res.write("<h1>Os information </h1>");
        res.write("<p>Platform : "+os.platform()+"</p>");
        res.write("<p>architecture : "+os.arch()+"</p>");
        res.write("<p>CPUs : "+os.cpus().length+"</p>");
        res.write("<p>Total memory : "+os.totalmem()+"</p>");
        res.write("<p>free memory : "+os.freemem()+"</p>");
        res.write("<h1>path info : </h1>");
        res.write("<p>File Name : "+path.basename(__filename)+"</p>");
        res.write("<p>File Extension : "+path.extname(__filename)+"</p>");
    }
    else{
        res.writeHead(404,{'Content-Type':'text/plain'});
        res.end("page not found");
    }
});
server.listen(3000,()=>{
    console.log("Server running on port 3000");
});

//Run using following commands
//node welcome.js
//Open http://localhost:3000/details