import React from 'react'
import { CFooter } from '@coreui/react'

const AppFooter = () => {
  return (
    <CFooter>
      <div>
        <span className="ms-1">&copy; 2025 Luthfi Creative.</span>
      </div>
      <div className="ms-auto">
        <span className="me-1">Designed by</span>
        <a href="#" target="_blank" rel="noopener noreferrer" className="text-decoration-none fw-bold">
          Luthfi Bahrul Rozaq
        </a>
        <span className="ms-1">- Level 1 Student</span>
      </div>
    </CFooter>
  )
}

export default React.memo(AppFooter)