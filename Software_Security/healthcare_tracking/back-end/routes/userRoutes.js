const express = require('express');
const authMiddleware = require('../middleware/authMiddleware');
const { getUsers, createUser } = require('../controllers/userController');
const router = express.Router();

router.get('/', authMiddleware, getUsers);
router.post('/', authMiddleware, createUser);

module.exports = router;
