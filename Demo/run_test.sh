# USAGE: bash run_test.sh

./../../../bin/timagescale testimg.raw testimg_2_times_larger_nn.raw 16 256 256 1 512 512 1 0
./../../../bin/timagescale testimg.raw testimg_2_times_larger_max.raw 16 256 256 1 512 512 1 0
./../../../bin/timagescale testimg.raw testimg_2_times_wider_nn.raw 16 256 256 1 512 256 1 0
./../../../bin/timagescale testimg.raw testimg_2_times_wider_max.raw 16 256 256 1 512 256 1 0
./../../../bin/timagescale testimg.raw testimg_2_times_taller_nn.raw 16 256 256 1 256 512 1 0
./../../../bin/timagescale testimg.raw testimg_2_times_taller_max.raw 16 256 256 1 256 512 1 0
./../../../bin/timagescale testimg.raw testimg_2_times_smaller_nn.raw 16 256 256 1 128 128 1 0
./../../../bin/timagescale testimg.raw testimg_2_times_smaller_max.raw 16 256 256 1 128 128 1 0
