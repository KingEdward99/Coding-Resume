import React, { useState } from 'react';
import { TextField, Select, MenuItem, Button, Box, Typography, FormControl, InputLabel } from '@mui/material';

function InputForm() {
  const [form, setForm] = useState({
    name: '',
    age: '',
    gender: '',
    healthStatus: '',
    exposureDate: '',
    vaccinationStatus: '',
    contactHistory: '',
  });

  const handleChange = (e) => {
    setForm({ ...form, [e.target.name]: e.target.value });
  };

  const handleSubmit = async (e) => {
    e.preventDefault();
  
    const response = await fetch('http://localhost:3000/input', {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json',
      },
      body: JSON.stringify(form),
    });
  
    if (response.ok) {
      console.log('Health data submitted successfully.');
      // Additional success handling (e.g., reset form, show a message)
    } else {
      console.error('Failed to submit health data.');
      // Error handling
    }
  };
  

  return (
    <Box sx={{ width: '50%', margin: 'auto', mt: 5, p: 3, boxShadow: 3, borderRadius: 2 }}>
      <Typography variant="h5" sx={{ mb: 2 }}>Health Information Form</Typography>
      <form onSubmit={handleSubmit}>
        <TextField
          fullWidth
          label="Name"
          name="name"
          value={form.name}
          onChange={handleChange}
          sx={{ mb: 2 }}
        />
        <TextField
          fullWidth
          label="Age"
          name="age"
          type="number"
          value={form.age}
          onChange={handleChange}
          sx={{ mb: 2 }}
        />
        <FormControl fullWidth sx={{ mb: 2 }}>
          <InputLabel>Gender</InputLabel>
          <Select name="gender" value={form.gender} onChange={handleChange}>
            <MenuItem value="male">Male</MenuItem>
            <MenuItem value="female">Female</MenuItem>
            <MenuItem value="other">Other</MenuItem>
          </Select>
        </FormControl>
        <TextField
          fullWidth
          label="Health Status"
          name="healthStatus"
          value={form.healthStatus}
          onChange={handleChange}
          sx={{ mb: 2 }}
        />
        <TextField
          fullWidth
          label="Exposure Date"
          name="exposureDate"
          type="date"
          InputLabelProps={{ shrink: true }}
          value={form.exposureDate}
          onChange={handleChange}
          sx={{ mb: 2 }}
        />
        <FormControl fullWidth sx={{ mb: 2 }}>
          <InputLabel>Vaccination Status</InputLabel>
          <Select name="vaccinationStatus" value={form.vaccinationStatus} onChange={handleChange}>
            <MenuItem value="Vaccinated">Vaccinated</MenuItem>
            <MenuItem value="Not Vaccinated">Not Vaccinated</MenuItem>
          </Select>
        </FormControl>
        <TextField
          fullWidth
          label="Contact History"
          name="contactHistory"
          multiline
          rows={3}
          value={form.contactHistory}
          onChange={handleChange}
          sx={{ mb: 2 }}
        />
        <Button variant="contained" type="submit" fullWidth>
          Submit
        </Button>
      </form>
    </Box>
  );
}

export default InputForm;
