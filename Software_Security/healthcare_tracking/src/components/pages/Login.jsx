import React, { useState } from 'react';
import { useNavigate } from 'react-router-dom';
import { Box, TextField, Button, Typography, Paper } from '@mui/material';

function Login() {
  const [username, setUsername] = useState('');
  const [password, setPassword] = useState('');
  const navigate = useNavigate(); // For navigation

  const handleLogin = (e) => {
    e.preventDefault();

    // Mock Authentication (Replace with real authentication logic)
    if (username === 'admin' && password === 'password123') {
      alert('Login successful!');
      navigate('/dashboard'); // Navigate to Dashboard
    } else {
      alert('Invalid credentials');
    }
  };

  return (
    <Paper elevation={3} sx={{ width: 400, margin: 'auto', mt: 10, p: 4, borderRadius: 2 }}>
      <Typography variant="h5" sx={{ textAlign: 'center', mb: 3 }}>
        Login
      </Typography>
      <form onSubmit={handleLogin}>
        <TextField
          label="Username"
          fullWidth
          variant="outlined"
          value={username}
          onChange={(e) => setUsername(e.target.value)}
          sx={{ mb: 2 }}
        />
        <TextField
          label="Password"
          type="password"
          fullWidth
          variant="outlined"
          value={password}
          onChange={(e) => setPassword(e.target.value)}
          sx={{ mb: 2 }}
        />
        <Button
          type="submit"
          variant="contained"
          fullWidth
          sx={{ mt: 2, backgroundColor: 'primary.main' }}
        >
          Login
        </Button>
      </form>
    </Paper>
  );
}

export default Login;
