import React from 'react';
import { BrowserRouter as Router, Routes, Route } from 'react-router-dom';
import Login from './components/pages/Login'; // Your Login page
import Dashboard from './components/pages/Dashboard'; // Protected Dashboard Page
import Home from './components/pages/Home'; // Example Home Page
import InputForm from './components/pages/InputForm';

function App() {
  return (
    <Router>
      <Routes>
        <Route path="/" element={<Home />} /> {/* Default Home Page */}
        <Route path="/login" element={<Login />} /> {/* Login Page */}
        <Route path="/dashboard" element={<Dashboard />} /> {/* Dashboard Page */}
        <Route path = "/input" element = {<InputForm/>} /> {/* Input Form */}
      </Routes>
    </Router>
  );
}

export default App;
