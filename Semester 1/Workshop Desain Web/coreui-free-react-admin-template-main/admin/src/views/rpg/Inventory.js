import React from 'react'
import {
  CCard, CCardBody, CCardHeader, CCol, CRow, CTable, CTableHead, CTableRow, CTableHeaderCell, CTableBody, CTableDataCell, CBadge, CListGroup, CListGroupItem, CProgress, CProgressBar
} from '@coreui/react'
import { CChartDoughnut } from '@coreui/react-chartjs'
import CIcon from '@coreui/icons-react'
import { cilHistory, cilCart } from '@coreui/icons'

const Inventory = () => {
  return (
    <>
      <CRow>
        {/* TOTAL GOLD */}
        <CCol xs={12} md={8}>
          <CCard className="mb-4 bg-warning text-white shadow">
            <CCardBody className="p-4 d-flex justify-content-between align-items-center">
              <div>
                <h5 className="text-uppercase text-white-50">Current Gold</h5>
                <h1 className="display-4 fw-bold text-white">1,500 G</h1>
              </div>
              <div className="text-end">
                 <small className="text-white-50">Estimasi bertahan: 15 Hari</small>
              </div>
            </CCardBody>
          </CCard>
        </CCol>

        {/* STATISTIK PENGELUARAN (CHART) */}
        <CCol xs={12} md={4}>
           <CCard className="mb-4">
            {/* Perbaikan Header: Pakai bg-dark agar kontras */}
            <CCardHeader className="bg-dark text-white">Spending Analysis</CCardHeader>
            <CCardBody>
              <CChartDoughnut
                data={{
                  labels: ['Makan', 'Transport', 'Kuota', 'Lainnya'],
                  datasets: [{
                    backgroundColor: ['#41B883', '#E46651', '#00D8FF', '#DD1B16'],
                    data: [60, 20, 15, 5],
                  }],
                }}
                options={{
                    plugins: { legend: { display: false } }
                }}
              />
            </CCardBody>
           </CCard>
        </CCol>
      </CRow>

      <CRow>
        {/* HISTORY TABLE */}
        <CCol md={8}>
          <CCard className="mb-4">
            {/* Perbaikan 1: Header Card diberi warna Dark agar tidak terlihat 'putih error' */}
            <CCardHeader className="bg-dark text-white fw-bold">
              <CIcon icon={cilHistory} className="me-2" /> Transaction Scrolls
            </CCardHeader>
            <CCardBody className="p-0">
              <CTable hover striped responsive className="mb-0">
                {/* Perbaikan 2: Header Tabel diberi warna Dark agar tulisan Date/Activity/Amount jelas */}
                <CTableHead color="dark">
                  <CTableRow>
                    <CTableHeaderCell>Date</CTableHeaderCell>
                    <CTableHeaderCell>Activity</CTableHeaderCell>
                    <CTableHeaderCell className="text-end">Amount</CTableHeaderCell>
                  </CTableRow>
                </CTableHead>
                <CTableBody>
                  <CTableRow>
                    <CTableDataCell>01 Nov</CTableDataCell>
                    <CTableDataCell><CBadge color="success" className="me-2">REWARD</CBadge> Bulanan Ortu</CTableDataCell>
                    <CTableDataCell className="text-end text-success fw-bold">+ 2000 G</CTableDataCell>
                  </CTableRow>
                  <CTableRow>
                    <CTableDataCell>02 Nov</CTableDataCell>
                    <CTableDataCell><CBadge color="danger" className="me-2">BUY</CBadge> Makan Siang</CTableDataCell>
                    <CTableDataCell className="text-end text-danger fw-bold">- 15 G</CTableDataCell>
                  </CTableRow>
                  <CTableRow>
                    <CTableDataCell>05 Nov</CTableDataCell>
                    <CTableDataCell><CBadge color="info" className="me-2">BUY</CBadge> Bensin Motor</CTableDataCell>
                    <CTableDataCell className="text-end text-danger fw-bold">- 20 G</CTableDataCell>
                  </CTableRow>
                </CTableBody>
              </CTable>
            </CCardBody>
          </CCard>
        </CCol>

        {/* WISHLIST */}
        <CCol md={4}>
          <CCard className="mb-4">
            {/* Perbaikan 3: Header Wishlist diberi warna Primary (Biru) */}
            <CCardHeader className="bg-primary text-white">
              <CIcon icon={cilCart} className="me-2" /> Rare Items (Wishlist)
            </CCardHeader>
            <CListGroup flush>
              <CListGroupItem>
                <div className="d-flex justify-content-between mb-1">
                  <strong>Monitor 24"</strong>
                  <small className="text-muted">300/1500 G</small>
                </div>
                <CProgress height={6}><CProgressBar color="warning" value={20} /></CProgress>
              </CListGroupItem>
              <CListGroupItem>
                <div className="d-flex justify-content-between mb-1">
                  <strong>Mech Keyboard</strong>
                  <small className="text-muted">800/1000 G</small>
                </div>
                <CProgress height={6}><CProgressBar color="info" value={80} /></CProgress>
              </CListGroupItem>
            </CListGroup>
          </CCard>
        </CCol>
      </CRow>
    </>
  )
}

export default Inventory