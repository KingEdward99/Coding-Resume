const mongoose = require('mongoose');

const customerSchema = new mongoose.Schema({
  name: { type: String, required: true },
  age: { type: Number, required: true },
  gender: { type: String, required: true },
  healthStatus: { type: String, required: true },
  exposureDate: { type: Date, required: true },
  vaccinationStatus: { type: String, required: true },
  contactHistory: { type: String, required: true },
});

const Customer = mongoose.model('Customer', customerSchema);

module.exports = Customer;