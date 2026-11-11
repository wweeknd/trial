const express = require('express');
const cookieParser = require('cookie-parser');
const session = require('express-session');
const app = express();
app.use(cookieParser());
app.use(session({
  secret: 'abc',
  resave: false,
  saveUninitialized: true,
}));
app.get('/',(req,res)=>{
    res.cookie('user',"Mahesh");
    if(!req.session.count){
        req.session.count = 0;
    }
    req.session.count++;
    res.send("Cookie user: "+req.cookies.user+"<br>Session count: "+req.session.count);
});
app.listen(3000);

//Execute the following commands in terminal to run this code
//npm init -y
//npm install express cookie-parser express-session
//node server.js
