import React from 'react';
import { Link } from 'react-router-dom';
import { Box, Button, Typography, Paper } from '@mui/material';

function Dashboard() {
  return (
    <Paper elevation={3} sx={{ width: '60%', margin: 'auto', mt: 10, p: 4, borderRadius: 2 }}>
      <Typography variant="h4" sx={{ mb: 3, textAlign: 'center' }}>
        User Dashboard
      </Typography>
      <Typography variant="body1" sx={{ mb: 3, textAlign: 'center' }}>
        Welcome! Please update your health information to keep your profile up to date.
      </Typography>
      <Box sx={{ display: 'flex', justifyContent: 'center' }}>
        <Link to="/input" style={{ textDecoration: 'none' }}>
          <Button variant="contained" color="primary">
            Update Health Info
          </Button>
        </Link>
      </Box>
    </Paper>
  );
}

export default Dashboard;
