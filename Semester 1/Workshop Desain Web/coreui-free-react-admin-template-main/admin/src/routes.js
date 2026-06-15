import React from 'react'

// --- BAGIAN 1: IMPORT FILE ---
const Dashboard = React.lazy(() => import('./views/dashboard/Dashboard'))

// Pastikan path-nya sesuai dengan folder yang kamu buat!
// Huruf besar kecil (Case Sensitive) berpengaruh! 'rpg/Profile' beda dengan 'rpg/profile'
const HeroProfile = React.lazy(() => import('./views/rpg/Profile')) 
const Inventory = React.lazy(() => import('./views/rpg/Inventory')) 

const routes = [
  { path: '/', exact: true, name: 'Home' },
  { path: '/dashboard', name: 'Dashboard', element: Dashboard },
  
  // --- BAGIAN 2: DAFTARKAN URL ---
  // Pastikan 'path' disini SAMA PERSIS dengan 'to' di _nav.js
  { path: '/rpg/profile', name: 'Hero Profile', element: HeroProfile },
  { path: '/rpg/inventory', name: 'Inventory', element: Inventory },
  
  // Jika kamu punya menu "Adventure Log" di _nav.js tapi belum bikin filenya/routenya,
  // menu itu kalau diklik bakal error/kosong.
]

export default routes