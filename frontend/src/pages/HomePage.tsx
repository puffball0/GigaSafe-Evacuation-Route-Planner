// import React from 'react';
// import './HomePage.css';
// import type { Page } from '../types';

// interface HomePageProps {
//   onNavigate: (page: Page) => void;
// }

// const HomePage: React.FC<HomePageProps> = ({ onNavigate }) => {
//   return (
//     <div className="home-page visible">
//       {/* Hero Section */}
//       <section className="hero">
//         <div className="hero-content">
//           <h1>GigaSafe</h1>
//           <p className="hero-subtitle">🔥 Emergency Response System</p>
//           <p className="hero-description">
//             Smart evacuation routing technology for Giga Mall Islamabad. Identify the fastest and
//             safest exit routes in any emergency situation with real-time guidance.
//           </p>
//           <button className="cta-button" onClick={() => onNavigate('visualization')}>
//             START VISUALIZATION
//           </button>
//         </div>
//       </section>

//       {/* Core Features */}
//       <section className="features">
//         <h2>Core Features</h2>
//         <div className="features-grid">
//           <div className="feature-card">
//             <div className="feature-icon">🗺️</div>
//             <h3>Interactive Floor Maps</h3>
//             <p>
//               Navigate through detailed floor plans of Giga Mall with real-time location tracking
//               and route visualization.
//             </p>
//           </div>

//           <div className="feature-card">
//             <div className="feature-icon">📍</div>
//             <h3>Location Selection</h3>
//             <p>
//               Click on any store or use dropdown menu to set your current location for accurate
//               route planning.
//             </p>
//           </div>

//           <div className="feature-card">
//             <div className="feature-icon">🎯</div>
//             <h3>Algorithm Visualization</h3>
//             <p>
//               Watch pathfinding algorithms work in real-time with step-by-step node exploration and
//               path computation.
//             </p>
//           </div>

//           <div className="feature-card">
//             <div className="feature-icon">⚡</div>
//             <h3>Fastest Routes</h3>
//             <p>
//               Dijkstra's algorithm ensures you get the shortest and safest path to the nearest
//               emergency exit.
//             </p>
//           </div>

//           <div className="feature-card">
//             <div className="feature-icon">📊</div>
//             <h3>Graph Visualization</h3>
//             <p>
//               View the underlying graph structure and understand how the navigation system works.
//             </p>
//           </div>

//           <div className="feature-card">
//             <div className="feature-icon">🌓</div>
//             <h3>Dark/Light Mode</h3>
//             <p>
//               Switch between dark and light themes for comfortable viewing in any environment.
//             </p>
//           </div>
//         </div>
//       </section>

//       {/* Safety Tips */}
//       <section className="safety-tips">
//         <div className="safety-content">
//           <h2>Emergency Safety Tips</h2>
//           <div className="tips-grid">
//             <div className="tip">
//               <h4>Stay Calm</h4>
//               <p>
//                 Keep a clear head and don't panic. Follow evacuation instructions carefully and
//                 help others if you can.
//               </p>
//             </div>

//             <div className="tip">
//               <h4>Know Your Exits</h4>
//               <p>
//                 Always be aware of at least two emergency exits from your location. Check exit
//                 signs when entering any floor.
//               </p>
//             </div>

//             <div className="tip">
//               <h4>Follow Instructions</h4>
//               <p>
//                 Listen to mall staff and emergency personnel. Follow the marked evacuation routes
//                 and assembly points.
//               </p>
//             </div>

//             <div className="tip">
//               <h4>Don't Use Elevators</h4>
//               <p>
//                 Always use stairs during emergencies. Elevators may malfunction or be needed by
//                 emergency services.
//               </p>
//             </div>
//           </div>
//         </div>
//       </section>

//       {/* Emergency Contacts */}
//       <section className="emergency-contacts">
//         <h2>Emergency Contacts</h2>
//         <div className="contacts-grid">
//           <div className="contact-card">
//             <h4>Emergency Services</h4>
//             <div className="contact-number">15</div>
//             <p className="contact-desc">National Emergency Helpline</p>
//           </div>

//           <div className="contact-card">
//             <h4>Rescue Services</h4>
//             <div className="contact-number">1122</div>
//             <p className="contact-desc">Punjab Emergency Service</p>
//           </div>

//           <div className="contact-card">
//             <h4>Mall Security</h4>
//             <div className="contact-number">051-XXX</div>
//             <p className="contact-desc">Giga Mall Security Desk</p>
//           </div>
//         </div>
//       </section>
//     </div>
//   );
// };

// export default HomePage;


import React from 'react';
import './HomePage.css';
import type { Page } from '../types';

interface HomePageProps {
  onNavigate: (page: Page) => void;
}

const HomePage: React.FC<HomePageProps> = ({ onNavigate }) => {
  return (
    <div className="home-page visible">
      {/* Hero Section */}
      <section className="hero">
        <div className="hero-content">
          <h1>GigaSafe</h1>
          <p className="hero-subtitle">🔥 Emergency Response System</p>
          <p className="hero-description">
            Smart evacuation routing technology for Giga Mall Islamabad. Identify the fastest and
            safest exit routes in any emergency situation with real-time guidance.
          </p>
          <div className="hero-buttons">
            <button className="cta-button primary" onClick={() => onNavigate('planner')}>
              EVACUATION PLANNER
            </button>
            <button className="cta-button secondary" onClick={() => onNavigate('visualization')}>
              ALGORITHM VISUALIZATION
            </button>
            <button className="cta-button secondary" onClick={() => onNavigate('hashmap')}>
              HASHMAP VISUALIZATION
            </button>
          </div>
        </div>
      </section>

      {/* Core Features */}
      <section className="features">
        <h2>Core Features</h2>
        <div className="features-grid">
          <div className="feature-card">
            <div className="feature-icon">🗺️</div>
            <h3>Interactive Floor Maps</h3>
            <p>
              Navigate through detailed floor plans of Giga Mall with real-time location tracking
              and route visualization.
            </p>
          </div>

          <div className="feature-card">
            <div className="feature-icon">📍</div>
            <h3>Location Selection</h3>
            <p>
              Click on any store or use dropdown menu to set your current location for accurate
              route planning.
            </p>
          </div>

          <div className="feature-card">
            <div className="feature-icon">🎯</div>
            <h3>Algorithm Visualization</h3>
            <p>
              Watch pathfinding algorithms work in real-time with step-by-step node exploration and
              path computation.
            </p>
          </div>

          <div className="feature-card">
            <div className="feature-icon">⚡</div>
            <h3>Fastest Routes</h3>
            <p>
              Dijkstra's algorithm ensures you get the shortest and safest path to the nearest
              emergency exit.
            </p>
          </div>

          <div className="feature-card">
            <div className="feature-icon">📊</div>
            <h3>Graph Visualization</h3>
            <p>
              View the underlying graph structure and understand how the navigation system works.
            </p>
          </div>

          <div className="feature-card">
            <div className="feature-icon">🌓</div>
            <h3>Dark/Light Mode</h3>
            <p>
              Switch between dark and light themes for comfortable viewing in any environment.
            </p>
          </div>
        </div>
      </section>

      {/* Safety Tips */}
      <section className="safety-tips">
        <div className="safety-content">
          <h2>Emergency Safety Tips</h2>
          <div className="tips-grid">
            <div className="tip">
              <h4>Stay Calm</h4>
              <p>
                Keep a clear head and don't panic. Follow evacuation instructions carefully and
                help others if you can.
              </p>
            </div>

            <div className="tip">
              <h4>Know Your Exits</h4>
              <p>
                Always be aware of at least two emergency exits from your location. Check exit
                signs when entering any floor.
              </p>
            </div>

            <div className="tip">
              <h4>Follow Instructions</h4>
              <p>
                Listen to mall staff and emergency personnel. Follow the marked evacuation routes
                and assembly points.
              </p>
            </div>

            <div className="tip">
              <h4>Don't Use Elevators</h4>
              <p>
                Always use stairs during emergencies. Elevators may malfunction or be needed by
                emergency services.
              </p>
            </div>
          </div>
        </div>
      </section>

      {/* Emergency Contacts */}
      <section className="emergency-contacts">
        <h2>Emergency Contacts</h2>
        <div className="contacts-grid">
          <div className="contact-card">
            <h4>Emergency Services</h4>
            <div className="contact-number">15</div>
            <p className="contact-desc">National Emergency Helpline</p>
          </div>

          <div className="contact-card">
            <h4>Rescue Services</h4>
            <div className="contact-number">1122</div>
            <p className="contact-desc">Punjab Emergency Service</p>
          </div>

          <div className="contact-card">
            <h4>Mall Security</h4>
            <div className="contact-number">051-8491040</div>
            <p className="contact-desc">Giga Mall Security Desk</p>
          </div>
        </div>
      </section>
    </div>
  );
};

export default HomePage;