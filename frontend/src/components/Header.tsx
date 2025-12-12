// import React from 'react';
// import type { Page } from '../types';
// import './Header.css';

// interface HeaderProps {
//   currentPage: Page;
//   onNavigate: (page: Page) => void;
//   isDark: boolean;
//   onToggleTheme: () => void;
// }

// const Header: React.FC<HeaderProps> = ({ currentPage, onNavigate, isDark, onToggleTheme }) => {
//   return (
//     <header className="app-header">
//       <div className="header-content">
//         <div className="logo-section">
//           <div className="logo-icon">🔥</div>
//           <div className="logo-text">
//             <h1>GigaSafe</h1>
//             <p>Emergency Evacuation System</p>
//           </div>
//         </div>

//         <nav className="nav-links">
//           <button
//             onClick={() => onNavigate('home')}
//             className={`nav-button ${currentPage === 'home' ? 'active' : ''}`}
//           >
//             Home
//           </button>
//           <button
//             onClick={() => onNavigate('visualization')}
//             className={`nav-button ${currentPage === 'visualization' ? 'active' : ''}`}
//           >
//             Visualization
//           </button>
//           <button onClick={onToggleTheme} className="theme-toggle">
//             {isDark ? '☀️' : '🌙'}
//           </button>
//         </nav>
//       </div>
//     </header>
//   );
// };

// export default Header;




import React from 'react';
import type { Page } from '../types';
import './Header.css';

interface HeaderProps {
  currentPage: Page;
  onNavigate: (page: Page) => void;
  isDark: boolean;
  onToggleTheme: () => void;
}

const Header: React.FC<HeaderProps> = ({ currentPage, onNavigate, isDark, onToggleTheme }) => {
  return (
    <header className="app-header">
      <div className="header-content">
        <div className="logo-section">
          <div className="logo-icon">🔥</div>
          <div className="logo-text">
            <h1>GigaSafe</h1>
            <p>Emergency Evacuation System</p>
          </div>
        </div>

        <nav className="nav-links">
          <button
            onClick={() => onNavigate('home')}
            className={`nav-button ${currentPage === 'home' ? 'active' : ''}`}
          >
            Home
          </button>
          <button
            onClick={() => onNavigate('planner')}
            className={`nav-button ${currentPage === 'planner' ? 'active' : ''}`}
          >
            Planner
          </button>
          <button
            onClick={() => onNavigate('visualization')}
            className={`nav-button ${currentPage === 'visualization' ? 'active' : ''}`}
          >
            Visualization
          </button>
          <button
            onClick={() => onNavigate('hashmap')}
            className={`nav-button ${currentPage === 'hashmap' ? 'active' : ''}`}
          >
            HashMap
          </button>
          <button onClick={onToggleTheme} className="theme-toggle">
            {isDark ? '☀️' : '🌙'}
          </button>
        </nav>
      </div>
    </header>
  );
};

export default Header;