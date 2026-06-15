import React from 'react'
import {
  CCard, CCardBody, CCardHeader, CCol, CRow, CTable, CTableHead, CTableRow, CTableHeaderCell, CTableBody, CTableDataCell, CBadge, CProgress, CProgressBar
} from '@coreui/react'
import CIcon from '@coreui/icons-react'
import { cilTask, cilCheckCircle, cilWarning } from '@coreui/icons'

const QuestBoard = () => {
  return (
    <>
      <CRow>
        {/* ACTIVE QUESTS (Tugas Belum Selesai) */}
        <CCol xs={12}>
          <CCard className="mb-4 border-top-danger border-top-3">
            <CCardHeader>
              <strong className="text-danger"><CIcon icon={cilWarning} className="me-2"/> Active Main Quests (Deadline Dekat)</strong>
            </CCardHeader>
            <CCardBody>
              <CTable hover responsive>
                <CTableHead>
                  <CTableRow>
                    <CTableHeaderCell>Quest Name (Mata Kuliah)</CTableHeaderCell>
                    <CTableHeaderCell>Difficulty</CTableHeaderCell>
                    <CTableHeaderCell>Due Date</CTableHeaderCell>
                    <CTableHeaderCell>Status</CTableHeaderCell>
                  </CTableRow>
                </CTableHead>
                <CTableBody>
                  <CTableRow>
                    <CTableDataCell>
                      <div className="fw-bold">Laporan Algoritma</div>
                      <small className="text-muted">Buat flowchart sorting</small>
                    </CTableDataCell>
                    <CTableDataCell><CBadge color="warning">Hard (4 SKS)</CBadge></CTableDataCell>
                    <CTableDataCell className="text-danger fw-bold">Besok, 23:59</CTableDataCell>
                    <CTableDataCell>0% (Not Started)</CTableDataCell>
                  </CTableRow>
                  <CTableRow>
                    <CTableDataCell>
                      <div className="fw-bold">Presentasi Agama</div>
                      <small className="text-muted">Kelompok 3</small>
                    </CTableDataCell>
                    <CTableDataCell><CBadge color="success">Easy (2 SKS)</CBadge></CTableDataCell>
                    <CTableDataCell>Lusa</CTableDataCell>
                    <CTableDataCell>50% (On Progress)</CTableDataCell>
                  </CTableRow>
                </CTableBody>
              </CTable>
            </CCardBody>
          </CCard>
        </CCol>

        {/* COMPLETED QUESTS (Riwayat Tugas) */}
        <CCol xs={12}>
          <CCard className="mb-4">
            <CCardHeader>
              <strong className="text-success"><CIcon icon={cilCheckCircle} className="me-2"/> Completed Quests</strong>
            </CCardHeader>
            <CCardBody>
              <CListGroup flush>
                <div className="d-flex justify-content-between border-bottom py-2">
                  <span>Makalah Pancasila</span>
                  <CBadge color="success">COMPLETED (+100 XP)</CBadge>
                </div>
                <div className="d-flex justify-content-between py-2">
                  <span>Install Linux Ubuntu</span>
                  <CBadge color="success">COMPLETED (+200 XP)</CBadge>
                </div>
              </CListGroup>
            </CCardBody>
          </CCard>
        </CCol>
      </CRow>
    </>
  )
}

export default QuestBoard