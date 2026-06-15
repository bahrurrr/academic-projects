import React from 'react'
import {
  CCard, CCardBody, CCardHeader, CCol, CRow, CProgress, CProgressBar, CListGroup, CListGroupItem, CBadge, CAvatar
} from '@coreui/react'
import { CChartRadar } from '@coreui/react-chartjs'
import CIcon from '@coreui/icons-react'
// PERBAIKAN DI SINI: Mengganti cilBackpack dengan cilBriefcase
import { cilLaptop, cilMobile, cilBriefcase } from '@coreui/icons'
import avatar1 from 'src/assets/images/avatars/1.jpg' 

const Profile = () => {
  return (
    <>
      <CCard className="mb-4 border-top-primary border-top-3 shadow-sm">
        <CCardBody>
          <CRow className="align-items-center">
            <CCol md={2} className="text-center">
              <CAvatar src={avatar1} size="xl" status="success" className="border border-3 border-warning" style={{ width: '100px', height: '100px' }} />
            </CCol>
            <CCol md={10}>
              <div className="d-flex justify-content-between align-items-center mb-2">
                <h4 className="mb-0">Player Name <CBadge color="warning" className="text-dark">Rank: Novice</CBadge></h4>
              </div>
              
              <div className="d-flex justify-content-between"><small className="fw-bold">HP (Health)</small> <small>85/100</small></div>
              <CProgress className="mb-2" height={15}><CProgressBar color="danger" value={85} /></CProgress>

              <div className="d-flex justify-content-between"><small className="fw-bold">MP (Focus)</small> <small>60/100</small></div>
              <CProgress className="mb-2" height={15}><CProgressBar color="info" value={60} /></CProgress>

              <div className="d-flex justify-content-between"><small className="fw-bold">XP (Progress)</small> <small>Lvl 1 (50%)</small></div>
              <CProgress height={10}><CProgressBar color="success" value={50} /></CProgress>
            </CCol>
          </CRow>
        </CCardBody>
      </CCard>

      <CRow>
        <CCol md={6}>
          <CCard className="mb-4">
            <CCardHeader className="bg-dark text-white">Attribute Skills</CCardHeader>
            <CCardBody>
              <CChartRadar
                data={{
                  labels: ['Coding', 'Logic', 'Design', 'Speaking', 'English', 'Math'],
                  datasets: [
                    {
                      label: 'Stats',
                      backgroundColor: 'rgba(255, 99, 132, 0.2)',
                      borderColor: 'rgba(255, 99, 132, 1)',
                      pointBackgroundColor: 'rgba(255, 99, 132, 1)',
                      pointBorderColor: '#fff',
                      pointHoverBackgroundColor: '#fff',
                      pointHoverBorderColor: 'rgba(255, 99, 132, 1)',
                      data: [80, 70, 60, 40, 65, 75],
                    },
                  ],
                }}
              />
            </CCardBody>
          </CCard>
        </CCol>

        <CCol md={6}>
          <CCard className="mb-4">
            <CCardHeader className="bg-dark text-white">Equipped Gear</CCardHeader>
            <CListGroup flush>
              <CListGroupItem className="d-flex justify-content-between align-items-center">
                <div>
                  <CIcon icon={cilLaptop} className="text-info me-2" />
                  <strong>Laptop Gaming</strong>
                  <div className="small text-muted">Type: Legendary Grimoire</div>
                </div>
                <CBadge color="secondary">Equipped</CBadge>
              </CListGroupItem>
              <CListGroupItem className="d-flex justify-content-between align-items-center">
                <div>
                  <CIcon icon={cilMobile} className="text-success me-2" />
                  <strong>Smartphone</strong>
                  <div className="small text-muted">Type: Communication Crystal</div>
                </div>
                <CBadge color="secondary">Equipped</CBadge>
              </CListGroupItem>
              {/* PERBAIKAN DI SINI JUGA */}
              <CListGroupItem className="d-flex justify-content-between align-items-center">
                <div>
                  <CIcon icon={cilBriefcase} className="text-warning me-2" />
                  <strong>Backpack</strong>
                  <div className="small text-muted">Type: Inventory Bag</div>
                </div>
                <CBadge color="secondary">Equipped</CBadge>
              </CListGroupItem>
            </CListGroup>
          </CCard>
        </CCol>
      </CRow>
    </>
  )
}

export default Profile