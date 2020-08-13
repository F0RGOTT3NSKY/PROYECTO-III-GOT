const express = require('express');
const router = express.Router();

const mysqlConnection = require('../Database');

router.get('/repositorios', (req, res) => {
    mysqlConnection.query('SELECT * FROM repositorios', (err, rows, fields) => {
        if(!err){
            res.json(rows);
        } else {
            console.log(err);
        }
    });
});

router.get('/archivos', (req, res) => {
    mysqlConnection.query('SELECT * FROM archivos', (err, rows, fields) => {
        if(!err){
            res.json(rows);
        } else {
            console.log(err);
        }
    })
});

router.get('/repositorios/:id', (req, res) => {
    const { id } = req.params;
    console.log(id);
});

module.exports = router;