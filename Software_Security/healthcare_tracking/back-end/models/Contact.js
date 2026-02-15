const mongoose = require('mongoose');

const contactSchema = new mongoose.Schema({
  customerId: { type: mongoose.Schema.Types.ObjectId, ref: 'User' },
  phone: { type: String, required: true },
  address: { type: String, required: true },
});

module.exports = mongoose.model('Contact', contactSchema);
