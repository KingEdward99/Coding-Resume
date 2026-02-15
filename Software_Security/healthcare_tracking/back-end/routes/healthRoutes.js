const express = require('express');
const router = express.Router();

router.post('/data', (req, res) => {
  const { name, age, gender, healthStatus, exposureDate, vaccinationStatus, contactHistory } = req.body;
  console.log('Health Data Received:', req.body);
  res.status(200).send('Health data submitted successfully.');
});

module.exports = router;
