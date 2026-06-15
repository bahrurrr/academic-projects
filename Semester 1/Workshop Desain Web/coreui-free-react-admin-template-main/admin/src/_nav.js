import React from 'react'
import CIcon from '@coreui/icons-react'
import { cilGamepad, cilUser, cilMoney, cilChartPie, cilAccountLogout } from '@coreui/icons'
import { CNavItem, CNavTitle, CNavGroup } from '@coreui/react'

const _nav = [
  {
    component: CNavTitle,
    name: 'GAME SYSTEM',
  },
  {
    component: CNavItem,
    name: 'World Map',
    to: '/dashboard',
    icon: <CIcon icon={cilGamepad} customClassName="nav-icon" />,
    badge: {
      color: 'danger',
      text: 'LIVE',
    },
  },
  {
    component: CNavTitle,
    name: 'PLAYER STATS',
  },
  {
    component: CNavItem,
    name: 'Hero Profile',
    to: '/rpg/profile', // Perhatikan path ini
    icon: <CIcon icon={cilUser} customClassName="nav-icon" />,
  },
  {
    component: CNavItem,
    name: 'Inventory (Gold)',
    to: '/rpg/inventory', // Perhatikan path ini
    icon: <CIcon icon={cilMoney} customClassName="nav-icon" />,
  },
  {
    component: CNavItem,
    name: 'Adventure Log',
    to: '/rpg/log',
    icon: <CIcon icon={cilChartPie} customClassName="nav-icon" />,
  },
]

export default _nav