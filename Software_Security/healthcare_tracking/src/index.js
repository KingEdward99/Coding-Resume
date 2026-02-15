import React from 'react';
import ReactDOM from 'react-dom/client'; // Correct import for React 18+
import App from './App'; // Your main app component
import './index.css'; // Import global styles (if any)

const root = ReactDOM.createRoot(document.getElementById('root')); // Use createRoot
root.render(
  <React.StrictMode>
    <App />
  </React.StrictMode>
);
