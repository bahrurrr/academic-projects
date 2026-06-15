import React from 'react'
import {
  CCard,
  CCardBody,
  CCardHeader,
  CCol,
  CRow,
  CTable,
  CTableHead,
  CTableRow,
  CTableHeaderCell,
  CTableBody,
  CTableDataCell,
  CBadge,
} from '@coreui/react'

// Data palsu (mock data) untuk tabel pesanan
const ordersData = [
  {
    id: '#1201',
    pelanggan: 'Budi Santoso',
    tanggal: '4 Nov 2025',
    total: 'Rp 450.000',
    status: 'Selesai',
  },
  {
    id: '#1202',
    pelanggan: 'Ani Wijaya',
    tanggal: '4 Nov 2025',
    total: 'Rp 1.200.000',
    status: 'Pending',
  },
  {
    id: '#1203',
    pelanggan: 'Rahmat Hidayat',
    tanggal: '3 Nov 2025',
    total: 'Rp 150.000',
    status: 'Selesai',
  },
  {
    id: '#1204',
    pelanggan: 'Citra Lestari',
    tanggal: '3 Nov 2025',
    total: 'Rp 85.000',
    status: 'Dibatalkan',
  },
  {
    id: '#1205',
    pelanggan: 'Eko Prasetyo',
    tanggal: '2 Nov 2025',
    total: 'Rp 760.000',
    status: 'Selesai',
  },
]

// Fungsi helper untuk menentukan warna badge berdasarkan status
const getBadgeColor = (status) => {
  switch (status) {
    case 'Selesai':
      return 'success'
    case 'Pending':
      return 'warning'
    case 'Dibatalkan':
      return 'danger'
    default:
      return 'primary'
  }
}

const RecentOrdersTable = () => {
  return (
    <CRow>
      <CCol xs={12}>
        <CCard className="mb-4">
          <CCardHeader>
            <strong>Pesanan Terbaru</strong>
          </CCardHeader>
          <CCardBody>
            <CTable align="middle" className="mb-0 border" hover responsive>
              <CTableHead color="light">
                <CTableRow>
                  <CTableHeaderCell>ID Pesanan</CTableHeaderCell>
                  <CTableHeaderCell>Pelanggan</CTableHeaderCell>
                  <CTableHeaderCell>Tanggal</CTableHeaderCell>
                  <CTableHeaderCell>Total</CTableHeaderCell>
                  <CTableHeaderCell>Status</CTableHeaderCell>
                </CTableRow>
              </CTableHead>
              <CTableBody>
                {ordersData.map((item, index) => (
                  <CTableRow v-for="item in tableItems" key={index}>
                    <CTableDataCell>
                      <div>{item.id}</div>
                    </CTableDataCell>
                    <CTableDataCell>
                      <div>{item.pelanggan}</div>
                    </CTableDataCell>
                    <CTableDataCell>
                      <div>{item.tanggal}</div>
                    </CTableDataCell>
                    <CTableDataCell>
                      <div>{item.total}</div>
                    </CTableDataCell>
                    <CTableDataCell>
                      <CBadge color={getBadgeColor(item.status)}>
                        {item.status}
                      </CBadge>
                    </CTableDataCell>
                  </CTableRow>
                ))}
              </CTableBody>
            </CTable>
          </CCardBody>
        </CCard>
      </CCol>
    </CRow>
  )
}

export default RecentOrdersTable