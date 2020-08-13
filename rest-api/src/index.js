const express = require('express');
const app = express();

// SETTINGS
app.set('port', process.env.PORT || 3000);

// MIDDLEWARES
app.use(express.json());

// ROUTES
app.use(require('./Routes/repositorios'));

// STARTING THE SERVER
app.listen(app.get('port'), () =>{
    console.log('Server on port', app.get('port'));
});