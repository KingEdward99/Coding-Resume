import React from "react";
import PropTypes from "prop-types";
import "./Button.css";

const Button = ({ 
  label, 
  onClick, 
  type = "button", 
  variant = "primary", 
  size = "medium", 
  disabled = false 
}) => {
  return (
    <button
      className={`btn ${variant} ${size}`}
      onClick={onClick}
      type={type}
      disabled={disabled}
    >
      {label}
    </button>
  );
};

Button.propTypes = {
  label: PropTypes.string.isRequired,
  onClick: PropTypes.func,
  type: PropTypes.oneOf(["button", "submit", "reset"]),
  variant: PropTypes.oneOf(["primary", "secondary", "danger"]),
  size: PropTypes.oneOf(["small", "medium", "large"]),
  disabled: PropTypes.bool,
};

export default Button;
