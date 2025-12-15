// import React, { useState } from 'react';
// import Header from './components/Header';
// import Footer from './components/Footer';
// import HomePage from './pages/HomePage';
// import VisualizationPage from './pages/VisualizationPage';
// import './App.css';

// type Page = 'home' | 'visualization';

// function App() {
//   const [currentPage, setCurrentPage] = useState<Page>('home');
//   const [isDark, setIsDark] = useState<boolean>(true);

//   return (
//     <div className={isDark ? 'dark' : ''}>
//       <div className="min-h-screen bg-background text-foreground">
//         <Header 
//           currentPage={currentPage}
//           onNavigate={setCurrentPage}
//           isDark={isDark}
//           onToggleTheme={() => setIsDark(!isDark)}
//         />

//         <main>
//           {currentPage === 'home' && (
//             <HomePage onNavigate={setCurrentPage} />
//           )}
//           {currentPage === 'visualization' && (
//             <VisualizationPage onBack={() => setCurrentPage('home')} />
//           )}
//         </main>

//         <Footer />
//       </div>
//     </div>
//   );
// }

// export default App;

import React, { useState } from 'react';
import Header from './components/Header';
import Footer from './components/Footer';
import HomePage from './pages/HomePage';
import VisualizationPage from './pages/VisualizationPage';
import PlannerPage from './pages/PlannerPage';
import HashMapPage from './pages/HashMapPage'; // Import HashMapPage
import type { Page } from './types';
import './App.css';

function App() {
  const [currentPage, setCurrentPage] = useState<Page>('home');

  return (
    <div className="dark">
      <div className="min-h-screen bg-background text-foreground">
        <Header
          currentPage={currentPage}
          onNavigate={setCurrentPage}
        />

        <main>
          {currentPage === 'home' && (
            <HomePage onNavigate={setCurrentPage} />
          )}
          {currentPage === 'visualization' && (
            <VisualizationPage onBack={() => setCurrentPage('home')} />
          )}
          {currentPage === 'planner' && ( // Add PlannerPage route
            <PlannerPage onBack={() => setCurrentPage('home')} />
          )}
          {currentPage === 'hashmap' && (
            <HashMapPage onBack={() => setCurrentPage('home')} />
          )}
        </main>

        <Footer />
      </div>
    </div>
  );
}

export default App;