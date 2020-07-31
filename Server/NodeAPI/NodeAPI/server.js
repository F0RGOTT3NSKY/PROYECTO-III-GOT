var express = require('express'),
    app = express(),
    port = process.env.PORT || 8080;

app.listen(port);
app.get('/', (request, response) => {
    console.log(`URL: ${request.url}`);
    response.send('Hello, Server!');
});
app.use(function (req, res) {
    res.status(404).send({ url: req.originalUrl + ' not found' })
});

console.log('todo list RESTful API server started on: ' + port);