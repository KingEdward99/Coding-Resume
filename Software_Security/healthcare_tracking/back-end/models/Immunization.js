const mongoose = require('mongoose');

const immunizationSchema = new mongoose.Schema({
  userId: { type: mongoose.Schema.Types.ObjectId, ref: 'User' },
  vaccineName: { type: String, required: true },
  dateAdministered: { type: Date, required: true },
});

module.exports = mongoose.model('Immunization', immunizationSchema);
