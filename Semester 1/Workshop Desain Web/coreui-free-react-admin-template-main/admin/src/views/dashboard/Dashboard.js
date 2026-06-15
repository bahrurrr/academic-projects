import React from 'react'
import {
  CCard, CCardBody, CCardHeader, CCol, CRow, CWidgetStatsA, CTable, CTableHead, CTableRow, CTableHeaderCell, CTableBody, CTableDataCell, CBadge, CListGroup, CListGroupItem
} from '@coreui/react'
import { CChartLine } from '@coreui/react-chartjs'
import CIcon from '@coreui/icons-react'
import { 
  cilArrowTop, cilCalendar, cilClock, cilBattery5, cilTerminal, cilBurn, cilMoon, cilLocationPin 
} from '@coreui/icons'

const Dashboard = () => {
  return (
    <>
      {/* --- ROW 1: HUD WIDGETS (SUDAH DIPERBAIKI UKURANNYA) --- */}
      <CRow>
        {/* WIDGET 1: SEMESTER */}
        <CCol sm={6} lg={3}>
          <CWidgetStatsA
            className="mb-4"
            color="primary"
            value="Semester 1"
            title="Current Server"
            action={<CIcon icon={cilCalendar} className="text-high-emphasis-inverse" />}
            chart={
              // PERBAIKAN: Menambahkan style height: 70px agar tingginya SAMA dengan grafik Energi
              <div className="d-flex align-items-center justify-content-center text-white-50" style={{ height: '87px' }}>
                <span className="fs-5 fw-bold">Week 8 (Mid-Game)</span>
              </div>
            }
          />
        </CCol>

        {/* WIDGET 2: ENERGY (HP) - Ini Patokannya */}
        <CCol sm={6} lg={3}>
          <CWidgetStatsA
            className="mb-4"
            color="info"
            value="85%"
            title="Energy (HP)"
            action={<CIcon icon={cilBattery5} className="text-high-emphasis-inverse" />}
            chart={
              <CChartLine
                className="mt-3 mx-3"
                style={{ height: '70px' }} // Ini adalah tinggi patokannya
                data={{
                  labels: ['M', 'T', 'W', 'T', 'F', 'S', 'S'],
                  datasets: [{
                    label: 'Energy',
                    backgroundColor: 'transparent',
                    borderColor: 'rgba(255,255,255,.55)',
                    data: [65, 59, 84, 84, 51, 55, 40],
                  }],
                }}
                options={{
                  plugins: { legend: { display: false } },
                  maintainAspectRatio: false,
                  scales: { x: { display: false }, y: { display: false } },
                  elements: { point: { radius: 0 } },
                }}
              />
            }
          />
        </CCol>

        {/* WIDGET 3: BUDGET */}
        <CCol sm={6} lg={3}>
          <CWidgetStatsA
            className="mb-4"
            color="warning"
            value="Rp 150.000"
            title="Daily Budget"
            action={<CIcon icon={cilArrowTop} className="text-high-emphasis-inverse" />}
            chart={
              // PERBAIKAN: Tinggi disamakan 70px
              <div className="d-flex align-items-center justify-content-center text-white-50" style={{ height: '87px' }}>
                 <span className="fs-5 fw-bold">Safe Zone</span>
              </div>
            }
          />
        </CCol>

        {/* WIDGET 4: QUESTS */}
        <CCol sm={6} lg={3}>
          <CWidgetStatsA
            className="mb-4"
            color="danger"
            value="2 Bosses"
            title="Active Quests"
            action={<CIcon icon={cilClock} className="text-high-emphasis-inverse" />}
            chart={
              // PERBAIKAN: Tinggi disamakan 70px
              <div className="d-flex align-items-center justify-content-center text-white-50" style={{ height: '87px' }}>
                <span className="fs-5 fw-bold">Deadline Critical</span>
              </div>
            }
          />
        </CCol>
      </CRow>

      {/* --- ROW 2: SCHEDULE & LOGS --- */}
      <CRow>
        <CCol xs={12} md={8}>
          <CCard className="mb-4">
            <CCardHeader className="bg-dark text-white fw-bold">
              <CIcon icon={cilCalendar} className="me-2" /> Today's Raid Schedule
            </CCardHeader>
            <CCardBody className="p-0">
              <CTable hover responsive className="mb-0">
                {/* PERBAIKAN: Header Tabel diberi warna Dark agar tulisan JELAS (tidak putih error) */}
                <CTableHead color="dark">
                  <CTableRow>
                    <CTableHeaderCell>Time</CTableHeaderCell>
                    <CTableHeaderCell>Raid Boss (Mata Kuliah)</CTableHeaderCell>
                    <CTableHeaderCell>Location</CTableHeaderCell>
                    <CTableHeaderCell>Status</CTableHeaderCell>
                  </CTableRow>
                </CTableHead>
                <CTableBody>
                  <CTableRow>
                    <CTableDataCell className="fw-bold text-muted">07:00 - 09:30</CTableDataCell>
                    <CTableDataCell>
                      <div className="fw-bold">Algoritma & Struktur Data</div>
                      <small className="text-muted">Guild Master: Pak Budi</small>
                    </CTableDataCell>
                    <CTableDataCell><CIcon icon={cilLocationPin} size="sm"/> Lab 204</CTableDataCell>
                    <CTableDataCell><CBadge color="success">CLEARED</CBadge></CTableDataCell>
                  </CTableRow>
                  <CTableRow>
                    <CTableDataCell className="fw-bold text-primary">10:00 - 12:00</CTableDataCell>
                    <CTableDataCell>
                      <div className="fw-bold">Matematika Diskrit</div>
                      <small className="text-muted">Guild Master: Bu Siti</small>
                    </CTableDataCell>
                    <CTableDataCell><CIcon icon={cilLocationPin} size="sm"/> R. 301</CTableDataCell>
                    <CTableDataCell><CBadge color="danger" shape="rounded-pill">IN PROGRESS</CBadge></CTableDataCell>
                  </CTableRow>
                </CTableBody>
              </CTable>
            </CCardBody>
          </CCard>
        </CCol>

        <CCol xs={12} md={4}>
          <CCard className="mb-4 text-white bg-dark">
            <CCardHeader className="border-bottom border-secondary">
              <CIcon icon={cilTerminal} className="me-2 text-success" /> System Logs
            </CCardHeader>
            <CCardBody className="p-0">
              <CListGroup flush className="bg-dark">
                <CListGroupItem className="bg-dark text-white border-secondary pt-3">
                  <small className="text-success font-monospace">[07:05] Player logged in.</small>
                </CListGroupItem>
                <CListGroupItem className="bg-dark text-white border-secondary">
                  <small className="text-info font-monospace">[09:30] Quest Completed: Algoritma.</small>
                </CListGroupItem>
                <CListGroupItem className="bg-dark text-white border-secondary pb-3">
                  <small className="text-warning font-monospace">[10:15] Warning: MP Low (Hungry).</small>
                </CListGroupItem>
              </CListGroup>
            </CCardBody>
          </CCard>
        </CCol>
      </CRow>

      {/* --- ROW 3: ACTIVE BUFFS/DEBUFFS (PERBAIKAN TAMPILAN) --- */}
      <h5 className="mb-3">Active Status Effects</h5>
      <CRow>
        <CCol md={4}>
          {/* PERBAIKAN: Dibungkus CCard agar punya background putih solid & border jelas */}
          <CCard className="mb-3 border-start-4 border-start-success shadow-sm">
            <CCardBody className="d-flex align-items-center p-3">
              <div className="bg-success text-white p-3 rounded me-3">
                <CIcon icon={cilBurn} size="xl"/>
              </div>
              <div>
                <h5 className="mb-1 text-success">Caffeine Rush</h5>
                <div className="small text-muted fw-bold">Buff: Coding Speed +20%</div>
                <div className="small text-muted">Duration: 2 Hours</div>
              </div>
            </CCardBody>
          </CCard>
        </CCol>

        <CCol md={4}>
          {/* PERBAIKAN: Background putih solid dengan aksen Merah */}
          <CCard className="mb-3 border-start-4 border-start-danger shadow-sm">
            <CCardBody className="d-flex align-items-center p-3">
              <div className="bg-danger text-white p-3 rounded me-3">
                <CIcon icon={cilMoon} size="xl"/>
              </div>
              <div>
                <h5 className="mb-1 text-danger">Sleep Deprived</h5>
                <div className="small text-muted fw-bold">Debuff: Focus -15%</div>
                <div className="small text-muted">Effect: Syntax Errors</div>
              </div>
            </CCardBody>
          </CCard>
        </CCol>

        <CCol md={4}>
          {/* PERBAIKAN: Background putih solid dengan aksen Biru */}
          <CCard className="mb-3 border-start-4 border-start-info shadow-sm">
            <CCardBody className="d-flex align-items-center p-3">
              <div className="bg-info text-white p-3 rounded me-3">
                <CIcon icon={cilLocationPin} size="xl"/>
              </div>
              <div>
                <h5 className="mb-1 text-info">Campus WiFi</h5>
                <div className="small text-muted fw-bold">Environment: Stable</div>
                <div className="small text-muted">Ping: 12ms</div>
              </div>
            </CCardBody>
          </CCard>
        </CCol>
      </CRow>
    </>
  )
}

export default Dashboard