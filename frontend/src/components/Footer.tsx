import React from 'react';
import './Footer.css';

const Footer: React.FC = () => {
  return (
    <footer className="app-footer">
      <p className="footer-main">
        © 2025 Giga Mall Islamabad. Emergency Evacuation Route Planner.
      </p>
      <p className="footer-sub">
        For emergency services, dial 15 or your local emergency number.
      </p>
    </footer>
  );
};

export default Footer;