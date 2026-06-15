import React from 'react'
import { CChartLine } from '@coreui/react-chartjs'

const MainChart = () => {
  return (
    <>
      <CChartLine
        style={{ height: '300px', marginTop: '40px' }}
        data={{
          labels: ['Januari', 'Februari', 'Maret', 'April', 'Mei', 'Juni', 'Juli'],
          datasets: [
            {
              label: 'Pemasukan (Kiriman + Freelance)',
              // SAYA GANTI KODE INI SUPAYA TIDAK ERROR:
              backgroundColor: 'rgba(51, 153, 255, 0.1)', // Warna Biru Transparan
              borderColor: '#3399ff',                      // Warna Biru
              pointHoverBackgroundColor: '#3399ff',
              borderWidth: 2,
              data: [1500000, 2000000, 1500000, 2500000, 3000000, 2000000, 2200000],
              fill: true,
            },
            {
              label: 'Pengeluaran Bulanan',
              backgroundColor: 'transparent',
              // SAYA GANTI KODE INI JUGA:
              borderColor: '#e55353',                      // Warna Merah
              pointHoverBackgroundColor: '#e55353',
              borderWidth: 2,
              data: [1200000, 1800000, 1400000, 2100000, 2800000, 1700000, 1600000],
            },
          ],
        }}
        options={{
          maintainAspectRatio: false,
          plugins: {
            legend: {
              display: false,
            },
          },
          scales: {
            x: {
              grid: {
                drawOnChartArea: false,
              },
            },
            y: {
              ticks: {
                beginAtZero: true,
                maxTicksLimit: 5,
                stepSize: Math.ceil(3000000 / 5),
                max: 3500000,
              },
            },
          },
          elements: {
            line: {
              tension: 0.4,
            },
            point: {
              radius: 0,
              hitRadius: 10,
              hoverRadius: 4,
              hoverBorderWidth: 3,
            },
          },
        }}
      />
    </>
  )
}

export default MainChart