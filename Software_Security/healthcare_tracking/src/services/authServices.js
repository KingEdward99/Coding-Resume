import axios from "axios";

const API_URL = process.env.REACT_APP_API_BASE_URL + "/auth";

// User login
export const login = async (email, password) => {
  try {
    const response = await axios.post(`${API_URL}/login`, { email, password });
    return response.data; // Token and user details
  } catch (error) {
    throw error.response.data; // Handle errors
  }
};

// User registration
export const register = async (userData) => {
  try {
    const response = await axios.post(`${API_URL}/register`, userData);
    return response.data; // Success message
  } catch (error) {
    throw error.response.data; // Handle errors
  }
};
