set terminal pdfcairo enhanced font "Gill Sans,18" linewidth 3 rounded dashed size 4in, 3in

set style line 100 lt 1 lc rgb "#606060"
set style line 101 lt 0 lc rgb "#606060"

set border 3 back ls 100
set grid noxtics ytics back ls 101
set ytics nomirror

set style line 1 lt rgb "#000000" lw 2 pt 2
set style line 2 lt rgb "#CF0000" lw 2 pt 8
set style line 3 lt rgb "#0BC681" lw 2 pt 6
set style line 4 lt rgb "#0E1589" lw 2 pt 4
set style line 5 lt rgb "#E69F00" lw 2 pt 3
set style line 6 lt rgb "#8B008B" lw 2 pt 7

set title "OpenAtom on Blue Gene/Q"
set xlabel "Number of cores"
set ylabel "Time per step (s)"
set logscale x 2
set logscale y 10
# set xrange [128:32768]
# set yrange [0.01:10]

set key center
set xtics ("128" 128, "256" 256, "512" 512, "1K" 1024, "2K" 2048, "4K" 4096, "8K" 8192, "16K" 16384, "32K" 32768) nomirror

set output "bgq.pdf"

plot 'bgq.dat' u 1:3 t "W256" with linespoints ls 1, \
'bgq.dat' u 1:2 t "W32" with linespoints ls 2
