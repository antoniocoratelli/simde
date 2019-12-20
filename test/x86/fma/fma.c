/* Copyright (c) 2018, 2019 Evan Nemerson <evan@nemerson.com>
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "../x86-internal.h"
#include "../../../simde/x86/fma.h"

static MunitResult
test_simde_mm_fmadd_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d c;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -364.57), SIMDE_FLOAT64_C( -702.81)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -890.80), SIMDE_FLOAT64_C( -433.89)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  486.26), SIMDE_FLOAT64_C( -304.02)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(325245.22), SIMDE_FLOAT64_C(304638.21)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  278.35), SIMDE_FLOAT64_C( -601.69)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -850.98), SIMDE_FLOAT64_C(   10.48)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -876.47), SIMDE_FLOAT64_C( -253.46)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(-237746.75), SIMDE_FLOAT64_C(-6559.17)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -495.32), SIMDE_FLOAT64_C(  626.54)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  243.15), SIMDE_FLOAT64_C( -595.67)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  652.27), SIMDE_FLOAT64_C(  684.47)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(-119784.79), SIMDE_FLOAT64_C(-372526.61)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -675.35), SIMDE_FLOAT64_C( -855.85)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  863.96), SIMDE_FLOAT64_C( -244.88)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  266.15), SIMDE_FLOAT64_C( -217.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(-583209.24), SIMDE_FLOAT64_C(209362.65)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -945.02), SIMDE_FLOAT64_C( -266.12)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  248.34), SIMDE_FLOAT64_C( -754.68)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  686.19), SIMDE_FLOAT64_C(  201.29)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(-234000.08), SIMDE_FLOAT64_C(201036.73)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -923.40), SIMDE_FLOAT64_C(  347.92)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -299.09), SIMDE_FLOAT64_C( -322.35)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -172.16), SIMDE_FLOAT64_C(  792.83)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(276007.55), SIMDE_FLOAT64_C(-111359.18)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -997.96), SIMDE_FLOAT64_C( -774.36)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  336.57), SIMDE_FLOAT64_C( -666.28)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   18.66), SIMDE_FLOAT64_C(  857.72)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(-335864.74), SIMDE_FLOAT64_C(516798.30)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  425.15), SIMDE_FLOAT64_C( -554.19)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -602.50), SIMDE_FLOAT64_C( -329.67)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -208.43), SIMDE_FLOAT64_C(  819.37)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(-256361.30), SIMDE_FLOAT64_C(183519.19)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_fmadd_pd(test_vec[i].a, test_vec[i].b, test_vec[i].c);
    simde_assert_m128d_f64_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_fmadd_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d b;
    simde__m256d c;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   463.71), SIMDE_FLOAT64_C(  -551.83),
                         SIMDE_FLOAT64_C(   568.05), SIMDE_FLOAT64_C(  -826.17)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   440.29), SIMDE_FLOAT64_C(   762.39),
                         SIMDE_FLOAT64_C(  -806.23), SIMDE_FLOAT64_C(  -848.48)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   222.93), SIMDE_FLOAT64_C(  -604.06),
                         SIMDE_FLOAT64_C(  -844.49), SIMDE_FLOAT64_C(   221.50)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(204389.81), SIMDE_FLOAT64_C(-421313.73),
                         SIMDE_FLOAT64_C(-458823.44), SIMDE_FLOAT64_C(701210.22)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   418.00), SIMDE_FLOAT64_C(  -725.82),
                         SIMDE_FLOAT64_C(   -54.90), SIMDE_FLOAT64_C(  -342.22)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   280.70), SIMDE_FLOAT64_C(   983.58),
                         SIMDE_FLOAT64_C(  -289.88), SIMDE_FLOAT64_C(   305.30)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -404.92), SIMDE_FLOAT64_C(  -664.17),
                         SIMDE_FLOAT64_C(   164.15), SIMDE_FLOAT64_C(  -785.83)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(116927.68), SIMDE_FLOAT64_C(-714566.21),
                         SIMDE_FLOAT64_C( 16078.56), SIMDE_FLOAT64_C(-105265.60)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   267.84), SIMDE_FLOAT64_C(   153.22),
                         SIMDE_FLOAT64_C(   565.53), SIMDE_FLOAT64_C(    45.62)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   253.29), SIMDE_FLOAT64_C(  -448.85),
                         SIMDE_FLOAT64_C(  -379.10), SIMDE_FLOAT64_C(   896.99)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   305.51), SIMDE_FLOAT64_C(   -18.42),
                         SIMDE_FLOAT64_C(   560.02), SIMDE_FLOAT64_C(  -441.54)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( 68146.70), SIMDE_FLOAT64_C(-68791.22),
                         SIMDE_FLOAT64_C(-213832.40), SIMDE_FLOAT64_C( 40479.14)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   698.02), SIMDE_FLOAT64_C(  -282.65),
                         SIMDE_FLOAT64_C(  -531.77), SIMDE_FLOAT64_C(  -673.05)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -227.36), SIMDE_FLOAT64_C(   165.86),
                         SIMDE_FLOAT64_C(  -853.86), SIMDE_FLOAT64_C(   210.39)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -443.02), SIMDE_FLOAT64_C(  -362.32),
                         SIMDE_FLOAT64_C(   833.55), SIMDE_FLOAT64_C(   692.62)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(-159144.85), SIMDE_FLOAT64_C(-47242.65),
                         SIMDE_FLOAT64_C(454890.68), SIMDE_FLOAT64_C(-140910.37)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -601.68), SIMDE_FLOAT64_C(   654.88),
                         SIMDE_FLOAT64_C(   957.42), SIMDE_FLOAT64_C(   563.37)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -958.65), SIMDE_FLOAT64_C(   523.00),
                         SIMDE_FLOAT64_C(  -211.18), SIMDE_FLOAT64_C(  -889.28)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   180.36), SIMDE_FLOAT64_C(   481.63),
                         SIMDE_FLOAT64_C(  -222.77), SIMDE_FLOAT64_C(   -51.21)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(576980.89), SIMDE_FLOAT64_C(342983.87),
                         SIMDE_FLOAT64_C(-202410.73), SIMDE_FLOAT64_C(-501044.88)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   731.42), SIMDE_FLOAT64_C(  -631.15),
                         SIMDE_FLOAT64_C(  -982.89), SIMDE_FLOAT64_C(  -397.65)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    69.37), SIMDE_FLOAT64_C(  -394.43),
                         SIMDE_FLOAT64_C(   -18.09), SIMDE_FLOAT64_C(   272.24)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   920.14), SIMDE_FLOAT64_C(  -196.58),
                         SIMDE_FLOAT64_C(   324.68), SIMDE_FLOAT64_C(  -193.62)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( 51658.75), SIMDE_FLOAT64_C(248747.91),
                         SIMDE_FLOAT64_C( 18105.16), SIMDE_FLOAT64_C(-108449.86)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -561.20), SIMDE_FLOAT64_C(  -459.54),
                         SIMDE_FLOAT64_C(  -681.08), SIMDE_FLOAT64_C(   -49.66)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   197.69), SIMDE_FLOAT64_C(  -813.71),
                         SIMDE_FLOAT64_C(  -990.48), SIMDE_FLOAT64_C(  -180.87)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -453.27), SIMDE_FLOAT64_C(  -557.45),
                         SIMDE_FLOAT64_C(  -780.15), SIMDE_FLOAT64_C(   693.73)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(-111396.90), SIMDE_FLOAT64_C(373374.84),
                         SIMDE_FLOAT64_C(673815.97), SIMDE_FLOAT64_C(  9675.73)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   297.04), SIMDE_FLOAT64_C(   950.40),
                         SIMDE_FLOAT64_C(  -454.41), SIMDE_FLOAT64_C(   419.22)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   303.25), SIMDE_FLOAT64_C(  -917.33),
                         SIMDE_FLOAT64_C(   128.78), SIMDE_FLOAT64_C(   208.96)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   735.53), SIMDE_FLOAT64_C(   976.90),
                         SIMDE_FLOAT64_C(   803.26), SIMDE_FLOAT64_C(   610.54)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( 90812.91), SIMDE_FLOAT64_C(-870853.53),
                         SIMDE_FLOAT64_C(-57715.66), SIMDE_FLOAT64_C( 88210.75)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_fmadd_pd(test_vec[i].a, test_vec[i].b, test_vec[i].c);
    simde_assert_m256d_f64_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_fmadd_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 c;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(    68.47), SIMDE_FLOAT32_C(   -20.99), SIMDE_FLOAT32_C(  -768.39), SIMDE_FLOAT32_C(   464.52)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   297.92), SIMDE_FLOAT32_C(   902.90), SIMDE_FLOAT32_C(   496.10), SIMDE_FLOAT32_C(  -932.73)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -341.38), SIMDE_FLOAT32_C(  -852.40), SIMDE_FLOAT32_C(   426.68), SIMDE_FLOAT32_C(   755.10)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 20057.20), SIMDE_FLOAT32_C(-19804.27), SIMDE_FLOAT32_C(-380771.59), SIMDE_FLOAT32_C(-432516.62)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   969.18), SIMDE_FLOAT32_C(   318.32), SIMDE_FLOAT32_C(  -273.65), SIMDE_FLOAT32_C(    39.39)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   995.10), SIMDE_FLOAT32_C(   620.67), SIMDE_FLOAT32_C(   664.82), SIMDE_FLOAT32_C(   711.85)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   473.88), SIMDE_FLOAT32_C(   360.15), SIMDE_FLOAT32_C(  -250.82), SIMDE_FLOAT32_C(   -88.76)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(964904.88), SIMDE_FLOAT32_C(197931.83), SIMDE_FLOAT32_C(-182178.80), SIMDE_FLOAT32_C( 27951.01)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   164.14), SIMDE_FLOAT32_C(  -848.02), SIMDE_FLOAT32_C(   235.35), SIMDE_FLOAT32_C(  -999.97)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   466.54), SIMDE_FLOAT32_C(    41.59), SIMDE_FLOAT32_C(  -619.09), SIMDE_FLOAT32_C(   332.19)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -720.05), SIMDE_FLOAT32_C(    91.37), SIMDE_FLOAT32_C(     3.41), SIMDE_FLOAT32_C(  -151.75)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 75857.83), SIMDE_FLOAT32_C(-35177.78), SIMDE_FLOAT32_C(-145699.44), SIMDE_FLOAT32_C(-332331.78)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -664.98), SIMDE_FLOAT32_C(  -765.11), SIMDE_FLOAT32_C(  -950.95), SIMDE_FLOAT32_C(   967.68)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   463.42), SIMDE_FLOAT32_C(   310.01), SIMDE_FLOAT32_C(  -859.78), SIMDE_FLOAT32_C(  -247.59)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   372.25), SIMDE_FLOAT32_C(  -546.43), SIMDE_FLOAT32_C(   -18.65), SIMDE_FLOAT32_C(  -608.78)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(-307792.78), SIMDE_FLOAT32_C(-237738.19), SIMDE_FLOAT32_C(817589.19), SIMDE_FLOAT32_C(-240196.67)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   739.81), SIMDE_FLOAT32_C(  -275.42), SIMDE_FLOAT32_C(  -462.27), SIMDE_FLOAT32_C(  -299.55)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -308.92), SIMDE_FLOAT32_C(   948.18), SIMDE_FLOAT32_C(  -344.73), SIMDE_FLOAT32_C(  -942.49)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   780.24), SIMDE_FLOAT32_C(   819.52), SIMDE_FLOAT32_C(  -913.65), SIMDE_FLOAT32_C(   715.95)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(-227761.88), SIMDE_FLOAT32_C(-260328.23), SIMDE_FLOAT32_C(158444.69), SIMDE_FLOAT32_C(283038.81)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -766.06), SIMDE_FLOAT32_C(  -563.42), SIMDE_FLOAT32_C(  -122.27), SIMDE_FLOAT32_C(  -338.00)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   496.12), SIMDE_FLOAT32_C(  -751.97), SIMDE_FLOAT32_C(   655.86), SIMDE_FLOAT32_C(   174.40)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -985.27), SIMDE_FLOAT32_C(   574.75), SIMDE_FLOAT32_C(   212.10), SIMDE_FLOAT32_C(  -683.32)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(-381042.97), SIMDE_FLOAT32_C(424249.66), SIMDE_FLOAT32_C(-79979.90), SIMDE_FLOAT32_C(-59630.52)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -663.22), SIMDE_FLOAT32_C(   549.14), SIMDE_FLOAT32_C(   733.90), SIMDE_FLOAT32_C(   785.76)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -149.60), SIMDE_FLOAT32_C(  -221.89), SIMDE_FLOAT32_C(  -452.29), SIMDE_FLOAT32_C(   -18.14)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   979.50), SIMDE_FLOAT32_C(  -484.31), SIMDE_FLOAT32_C(  -965.78), SIMDE_FLOAT32_C(  -291.28)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(100197.21), SIMDE_FLOAT32_C(-122332.99), SIMDE_FLOAT32_C(-332901.44), SIMDE_FLOAT32_C(-14544.97)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(    82.89), SIMDE_FLOAT32_C(  -639.53), SIMDE_FLOAT32_C(   680.97), SIMDE_FLOAT32_C(  -745.76)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   377.68), SIMDE_FLOAT32_C(  -229.15), SIMDE_FLOAT32_C(   986.42), SIMDE_FLOAT32_C(  -430.87)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   506.24), SIMDE_FLOAT32_C(  -791.48), SIMDE_FLOAT32_C(  -896.55), SIMDE_FLOAT32_C(  -775.82)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 31812.13), SIMDE_FLOAT32_C(145756.81), SIMDE_FLOAT32_C(670825.81), SIMDE_FLOAT32_C(320549.81)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_fmadd_ps(test_vec[i].a, test_vec[i].b, test_vec[i].c);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_fmadd_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 b;
    simde__m256 c;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(    39.90), SIMDE_FLOAT32_C(    46.80),
                         SIMDE_FLOAT32_C(   -90.30), SIMDE_FLOAT32_C(   -57.20),
                         SIMDE_FLOAT32_C(    71.50), SIMDE_FLOAT32_C(    75.00),
                         SIMDE_FLOAT32_C(    -0.30), SIMDE_FLOAT32_C(    14.60)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -90.60), SIMDE_FLOAT32_C(   -15.30),
                         SIMDE_FLOAT32_C(   -46.70), SIMDE_FLOAT32_C(    73.50),
                         SIMDE_FLOAT32_C(   -27.40), SIMDE_FLOAT32_C(   -79.00),
                         SIMDE_FLOAT32_C(   -14.10), SIMDE_FLOAT32_C(    22.30)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -19.50), SIMDE_FLOAT32_C(    61.50),
                         SIMDE_FLOAT32_C(   -38.80), SIMDE_FLOAT32_C(   -19.20),
                         SIMDE_FLOAT32_C(    54.40), SIMDE_FLOAT32_C(   -71.00),
                         SIMDE_FLOAT32_C(   -11.30), SIMDE_FLOAT32_C(    -2.70)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -3634.44), SIMDE_FLOAT32_C(  -654.54),
                         SIMDE_FLOAT32_C(  4178.21), SIMDE_FLOAT32_C( -4223.40),
                         SIMDE_FLOAT32_C( -1904.70), SIMDE_FLOAT32_C( -5996.00),
                         SIMDE_FLOAT32_C(    -7.07), SIMDE_FLOAT32_C(   322.88)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(    56.00), SIMDE_FLOAT32_C(   -61.10),
                         SIMDE_FLOAT32_C(   -84.20), SIMDE_FLOAT32_C(    -8.30),
                         SIMDE_FLOAT32_C(    96.60), SIMDE_FLOAT32_C(    92.70),
                         SIMDE_FLOAT32_C(   -19.40), SIMDE_FLOAT32_C(   -41.30)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -20.80), SIMDE_FLOAT32_C(   -77.90),
                         SIMDE_FLOAT32_C(    22.80), SIMDE_FLOAT32_C(   -62.40),
                         SIMDE_FLOAT32_C(    47.20), SIMDE_FLOAT32_C(    23.30),
                         SIMDE_FLOAT32_C(   -14.70), SIMDE_FLOAT32_C(     1.80)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    -2.50), SIMDE_FLOAT32_C(   -40.20),
                         SIMDE_FLOAT32_C(   -64.40), SIMDE_FLOAT32_C(    46.00),
                         SIMDE_FLOAT32_C(    19.60), SIMDE_FLOAT32_C(    30.00),
                         SIMDE_FLOAT32_C(    23.60), SIMDE_FLOAT32_C(    20.60)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -1167.30), SIMDE_FLOAT32_C(  4719.49),
                         SIMDE_FLOAT32_C( -1984.16), SIMDE_FLOAT32_C(   563.92),
                         SIMDE_FLOAT32_C(  4579.12), SIMDE_FLOAT32_C(  2189.91),
                         SIMDE_FLOAT32_C(   308.78), SIMDE_FLOAT32_C(   -53.74)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   -73.60), SIMDE_FLOAT32_C(   -63.70),
                         SIMDE_FLOAT32_C(    -7.10), SIMDE_FLOAT32_C(   -70.90),
                         SIMDE_FLOAT32_C(    23.30), SIMDE_FLOAT32_C(    22.20),
                         SIMDE_FLOAT32_C(     4.90), SIMDE_FLOAT32_C(   -85.30)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    75.60), SIMDE_FLOAT32_C(    -6.90),
                         SIMDE_FLOAT32_C(    73.70), SIMDE_FLOAT32_C(   -85.70),
                         SIMDE_FLOAT32_C(   -25.90), SIMDE_FLOAT32_C(   -59.90),
                         SIMDE_FLOAT32_C(   -56.20), SIMDE_FLOAT32_C(   -30.70)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    54.00), SIMDE_FLOAT32_C(   -79.70),
                         SIMDE_FLOAT32_C(    71.20), SIMDE_FLOAT32_C(   -74.20),
                         SIMDE_FLOAT32_C(   -48.90), SIMDE_FLOAT32_C(    -7.20),
                         SIMDE_FLOAT32_C(   -59.10), SIMDE_FLOAT32_C(   -84.70)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -5510.16), SIMDE_FLOAT32_C(   359.83),
                         SIMDE_FLOAT32_C(  -452.07), SIMDE_FLOAT32_C(  6001.93),
                         SIMDE_FLOAT32_C(  -652.37), SIMDE_FLOAT32_C( -1336.98),
                         SIMDE_FLOAT32_C(  -334.48), SIMDE_FLOAT32_C(  2534.01)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(    57.50), SIMDE_FLOAT32_C(    93.40),
                         SIMDE_FLOAT32_C(    -2.20), SIMDE_FLOAT32_C(    77.20),
                         SIMDE_FLOAT32_C(    79.40), SIMDE_FLOAT32_C(   -81.10),
                         SIMDE_FLOAT32_C(    25.80), SIMDE_FLOAT32_C(    -5.40)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -36.80), SIMDE_FLOAT32_C(   -46.10),
                         SIMDE_FLOAT32_C(    57.50), SIMDE_FLOAT32_C(    47.70),
                         SIMDE_FLOAT32_C(    38.00), SIMDE_FLOAT32_C(    48.30),
                         SIMDE_FLOAT32_C(    86.60), SIMDE_FLOAT32_C(    85.60)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    92.60), SIMDE_FLOAT32_C(    68.60),
                         SIMDE_FLOAT32_C(   -48.10), SIMDE_FLOAT32_C(   -53.80),
                         SIMDE_FLOAT32_C(   -45.80), SIMDE_FLOAT32_C(    33.60),
                         SIMDE_FLOAT32_C(    47.80), SIMDE_FLOAT32_C(    61.30)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -2023.40), SIMDE_FLOAT32_C( -4237.14),
                         SIMDE_FLOAT32_C(  -174.60), SIMDE_FLOAT32_C(  3628.64),
                         SIMDE_FLOAT32_C(  2971.40), SIMDE_FLOAT32_C( -3883.53),
                         SIMDE_FLOAT32_C(  2282.08), SIMDE_FLOAT32_C(  -400.94)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(    39.30), SIMDE_FLOAT32_C(    47.70),
                         SIMDE_FLOAT32_C(   -46.40), SIMDE_FLOAT32_C(    22.40),
                         SIMDE_FLOAT32_C(   -47.70), SIMDE_FLOAT32_C(   -87.50),
                         SIMDE_FLOAT32_C(    56.70), SIMDE_FLOAT32_C(   -98.30)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    47.80), SIMDE_FLOAT32_C(    25.10),
                         SIMDE_FLOAT32_C(    86.40), SIMDE_FLOAT32_C(    20.80),
                         SIMDE_FLOAT32_C(   -68.30), SIMDE_FLOAT32_C(    -7.70),
                         SIMDE_FLOAT32_C(    87.10), SIMDE_FLOAT32_C(    24.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    30.50), SIMDE_FLOAT32_C(    80.40),
                         SIMDE_FLOAT32_C(   -81.20), SIMDE_FLOAT32_C(   -60.10),
                         SIMDE_FLOAT32_C(   -62.20), SIMDE_FLOAT32_C(    51.30),
                         SIMDE_FLOAT32_C(   -56.00), SIMDE_FLOAT32_C(   -52.90)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  1909.04), SIMDE_FLOAT32_C(  1277.67),
                         SIMDE_FLOAT32_C( -4090.16), SIMDE_FLOAT32_C(   405.82),
                         SIMDE_FLOAT32_C(  3195.71), SIMDE_FLOAT32_C(   725.05),
                         SIMDE_FLOAT32_C(  4882.57), SIMDE_FLOAT32_C( -2412.10)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(    35.30), SIMDE_FLOAT32_C(   -51.40),
                         SIMDE_FLOAT32_C(   -71.80), SIMDE_FLOAT32_C(    28.30),
                         SIMDE_FLOAT32_C(    41.70), SIMDE_FLOAT32_C(   -29.90),
                         SIMDE_FLOAT32_C(    47.10), SIMDE_FLOAT32_C(   -23.50)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -72.20), SIMDE_FLOAT32_C(     5.10),
                         SIMDE_FLOAT32_C(    50.30), SIMDE_FLOAT32_C(     8.80),
                         SIMDE_FLOAT32_C(    10.30), SIMDE_FLOAT32_C(    88.00),
                         SIMDE_FLOAT32_C(   -32.10), SIMDE_FLOAT32_C(   -71.80)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    92.50), SIMDE_FLOAT32_C(   -22.70),
                         SIMDE_FLOAT32_C(   -32.50), SIMDE_FLOAT32_C(   -64.00),
                         SIMDE_FLOAT32_C(    53.40), SIMDE_FLOAT32_C(    57.00),
                         SIMDE_FLOAT32_C(    85.20), SIMDE_FLOAT32_C(    51.90)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -2456.16), SIMDE_FLOAT32_C(  -284.84),
                         SIMDE_FLOAT32_C( -3644.04), SIMDE_FLOAT32_C(   185.04),
                         SIMDE_FLOAT32_C(   482.91), SIMDE_FLOAT32_C( -2574.20),
                         SIMDE_FLOAT32_C( -1426.71), SIMDE_FLOAT32_C(  1739.20)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(    62.00), SIMDE_FLOAT32_C(   -58.50),
                         SIMDE_FLOAT32_C(   -89.10), SIMDE_FLOAT32_C(    51.50),
                         SIMDE_FLOAT32_C(     2.30), SIMDE_FLOAT32_C(   -87.50),
                         SIMDE_FLOAT32_C(   -72.60), SIMDE_FLOAT32_C(    96.30)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -25.70), SIMDE_FLOAT32_C(    80.90),
                         SIMDE_FLOAT32_C(   -77.80), SIMDE_FLOAT32_C(     4.90),
                         SIMDE_FLOAT32_C(    70.20), SIMDE_FLOAT32_C(    32.70),
                         SIMDE_FLOAT32_C(   -60.70), SIMDE_FLOAT32_C(    68.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -99.00), SIMDE_FLOAT32_C(   -12.20),
                         SIMDE_FLOAT32_C(    41.70), SIMDE_FLOAT32_C(     9.80),
                         SIMDE_FLOAT32_C(   -34.40), SIMDE_FLOAT32_C(   -50.10),
                         SIMDE_FLOAT32_C(    35.40), SIMDE_FLOAT32_C(    62.60)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -1692.40), SIMDE_FLOAT32_C( -4744.85),
                         SIMDE_FLOAT32_C(  6973.68), SIMDE_FLOAT32_C(   262.15),
                         SIMDE_FLOAT32_C(   127.06), SIMDE_FLOAT32_C( -2911.35),
                         SIMDE_FLOAT32_C(  4442.22), SIMDE_FLOAT32_C(  6611.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   -40.00), SIMDE_FLOAT32_C(    62.80),
                         SIMDE_FLOAT32_C(   -40.00), SIMDE_FLOAT32_C(    16.60),
                         SIMDE_FLOAT32_C(    60.10), SIMDE_FLOAT32_C(    22.60),
                         SIMDE_FLOAT32_C(   -12.40), SIMDE_FLOAT32_C(    91.30)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -98.70), SIMDE_FLOAT32_C(    17.00),
                         SIMDE_FLOAT32_C(   -23.90), SIMDE_FLOAT32_C(    29.60),
                         SIMDE_FLOAT32_C(   -52.60), SIMDE_FLOAT32_C(   -30.60),
                         SIMDE_FLOAT32_C(    43.40), SIMDE_FLOAT32_C(    76.50)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    61.00), SIMDE_FLOAT32_C(   -10.10),
                         SIMDE_FLOAT32_C(    48.20), SIMDE_FLOAT32_C(    50.20),
                         SIMDE_FLOAT32_C(    12.20), SIMDE_FLOAT32_C(    64.80),
                         SIMDE_FLOAT32_C(   -68.90), SIMDE_FLOAT32_C(   -86.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  4009.00), SIMDE_FLOAT32_C(  1057.50),
                         SIMDE_FLOAT32_C(  1004.20), SIMDE_FLOAT32_C(   541.56),
                         SIMDE_FLOAT32_C( -3149.06), SIMDE_FLOAT32_C(  -626.76),
                         SIMDE_FLOAT32_C(  -607.06), SIMDE_FLOAT32_C(  6898.45)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_fmadd_ps(test_vec[i].a, test_vec[i].b, test_vec[i].c);
    simde_assert_m256_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_fmadd_sd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d c;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   96.50), SIMDE_FLOAT64_C(  -99.50)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   16.90), SIMDE_FLOAT64_C(  -76.80)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   53.90), SIMDE_FLOAT64_C(    6.40)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   96.50), SIMDE_FLOAT64_C( 7648.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   53.00), SIMDE_FLOAT64_C(   -2.10)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -68.70), SIMDE_FLOAT64_C(  -11.70)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -76.30), SIMDE_FLOAT64_C(   62.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   53.00), SIMDE_FLOAT64_C(   87.47)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   34.00), SIMDE_FLOAT64_C(   30.50)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -42.50), SIMDE_FLOAT64_C(   32.70)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -36.20), SIMDE_FLOAT64_C(   36.10)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   34.00), SIMDE_FLOAT64_C( 1033.45)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -75.50), SIMDE_FLOAT64_C(  -58.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   29.70), SIMDE_FLOAT64_C(  -42.30)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   95.20), SIMDE_FLOAT64_C(   92.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -75.50), SIMDE_FLOAT64_C( 2545.40)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -59.60), SIMDE_FLOAT64_C(   12.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -84.80), SIMDE_FLOAT64_C(   50.40)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   42.20), SIMDE_FLOAT64_C(  -77.30)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -59.60), SIMDE_FLOAT64_C(  572.86)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   78.40), SIMDE_FLOAT64_C(  -77.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -76.10), SIMDE_FLOAT64_C(  -11.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    5.80), SIMDE_FLOAT64_C(  -75.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   78.40), SIMDE_FLOAT64_C(  771.10)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    6.70), SIMDE_FLOAT64_C(   47.60)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   24.30), SIMDE_FLOAT64_C(   93.60)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   93.40), SIMDE_FLOAT64_C(  -50.10)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    6.70), SIMDE_FLOAT64_C( 4405.26)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -59.60), SIMDE_FLOAT64_C(  -73.40)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    1.20), SIMDE_FLOAT64_C(   10.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   45.00), SIMDE_FLOAT64_C(  -86.50)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -59.60), SIMDE_FLOAT64_C( -886.56)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_fmadd_sd(test_vec[i].a, test_vec[i].b, test_vec[i].c);
    simde_assert_m128d_f64_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_fmadd_ss(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 c;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   29.70), SIMDE_FLOAT32_C(  -13.10), SIMDE_FLOAT32_C(  -92.70), SIMDE_FLOAT32_C(   44.80)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   25.90), SIMDE_FLOAT32_C(   67.70), SIMDE_FLOAT32_C(  -12.20), SIMDE_FLOAT32_C(   72.20)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   45.60), SIMDE_FLOAT32_C(   36.90), SIMDE_FLOAT32_C(  -98.40), SIMDE_FLOAT32_C(  -64.80)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   29.70), SIMDE_FLOAT32_C(  -13.10), SIMDE_FLOAT32_C(  -92.70), SIMDE_FLOAT32_C( 3169.76)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   16.70), SIMDE_FLOAT32_C(   85.50), SIMDE_FLOAT32_C(   89.70), SIMDE_FLOAT32_C(  -23.80)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   70.80), SIMDE_FLOAT32_C(   99.80), SIMDE_FLOAT32_C(  -87.00), SIMDE_FLOAT32_C(    9.00)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   42.40), SIMDE_FLOAT32_C(   38.10), SIMDE_FLOAT32_C(  -58.60), SIMDE_FLOAT32_C(  -71.70)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   16.70), SIMDE_FLOAT32_C(   85.50), SIMDE_FLOAT32_C(   89.70), SIMDE_FLOAT32_C( -285.90)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -85.70), SIMDE_FLOAT32_C(   66.60), SIMDE_FLOAT32_C(  -84.60), SIMDE_FLOAT32_C(  -90.50)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   61.30), SIMDE_FLOAT32_C(  -91.00), SIMDE_FLOAT32_C(  -35.60), SIMDE_FLOAT32_C(  -66.30)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   76.30), SIMDE_FLOAT32_C(  -46.00), SIMDE_FLOAT32_C(   54.10), SIMDE_FLOAT32_C(   17.60)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -85.70), SIMDE_FLOAT32_C(   66.60), SIMDE_FLOAT32_C(  -84.60), SIMDE_FLOAT32_C( 6017.75)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   14.40), SIMDE_FLOAT32_C(  -25.60), SIMDE_FLOAT32_C(  -65.60), SIMDE_FLOAT32_C(  -71.00)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   65.40), SIMDE_FLOAT32_C(   95.90), SIMDE_FLOAT32_C(   51.70), SIMDE_FLOAT32_C(  -84.50)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -47.60), SIMDE_FLOAT32_C(  -50.00), SIMDE_FLOAT32_C(   88.40), SIMDE_FLOAT32_C(  -28.80)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   14.40), SIMDE_FLOAT32_C(  -25.60), SIMDE_FLOAT32_C(  -65.60), SIMDE_FLOAT32_C( 5970.70)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   29.50), SIMDE_FLOAT32_C(  -26.70), SIMDE_FLOAT32_C(    8.30), SIMDE_FLOAT32_C(  -34.70)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   76.70), SIMDE_FLOAT32_C(  -34.90), SIMDE_FLOAT32_C(  -78.80), SIMDE_FLOAT32_C(   84.50)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   45.30), SIMDE_FLOAT32_C(  -18.40), SIMDE_FLOAT32_C(  -36.50), SIMDE_FLOAT32_C(  -89.00)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   29.50), SIMDE_FLOAT32_C(  -26.70), SIMDE_FLOAT32_C(    8.30), SIMDE_FLOAT32_C(-3021.15)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   64.00), SIMDE_FLOAT32_C(   46.60), SIMDE_FLOAT32_C(  -17.50), SIMDE_FLOAT32_C(   24.10)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -67.40), SIMDE_FLOAT32_C(  -16.40), SIMDE_FLOAT32_C(   38.30), SIMDE_FLOAT32_C(  -92.30)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -66.80), SIMDE_FLOAT32_C(   10.60), SIMDE_FLOAT32_C(   -6.70), SIMDE_FLOAT32_C(  -49.00)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   64.00), SIMDE_FLOAT32_C(   46.60), SIMDE_FLOAT32_C(  -17.50), SIMDE_FLOAT32_C(-2273.43)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -98.50), SIMDE_FLOAT32_C(   15.30), SIMDE_FLOAT32_C(  -33.40), SIMDE_FLOAT32_C(    4.80)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   97.00), SIMDE_FLOAT32_C(  -35.60), SIMDE_FLOAT32_C(   63.50), SIMDE_FLOAT32_C(  -94.30)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   -9.90), SIMDE_FLOAT32_C(  -97.20), SIMDE_FLOAT32_C(  -13.80), SIMDE_FLOAT32_C(   11.60)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -98.50), SIMDE_FLOAT32_C(   15.30), SIMDE_FLOAT32_C(  -33.40), SIMDE_FLOAT32_C( -441.04)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -11.00), SIMDE_FLOAT32_C(  -65.00), SIMDE_FLOAT32_C(  -76.20), SIMDE_FLOAT32_C(   54.80)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   37.10), SIMDE_FLOAT32_C(  -97.90), SIMDE_FLOAT32_C(  -36.50), SIMDE_FLOAT32_C(   50.70)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -26.80), SIMDE_FLOAT32_C(  -74.90), SIMDE_FLOAT32_C(  -84.40), SIMDE_FLOAT32_C(   35.70)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -11.00), SIMDE_FLOAT32_C(  -65.00), SIMDE_FLOAT32_C(  -76.20), SIMDE_FLOAT32_C( 2814.06)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_fmadd_ss(test_vec[i].a, test_vec[i].b, test_vec[i].c);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_fmaddsub_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d c;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -72.20), SIMDE_FLOAT64_C(   74.40)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   41.60), SIMDE_FLOAT64_C(  -13.50)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   18.90), SIMDE_FLOAT64_C(   65.30)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(-2984.62), SIMDE_FLOAT64_C(-1069.70)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   14.70), SIMDE_FLOAT64_C(   97.50)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   47.70), SIMDE_FLOAT64_C(   86.80)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   75.80), SIMDE_FLOAT64_C(   19.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  776.99), SIMDE_FLOAT64_C( 8443.10)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -24.00), SIMDE_FLOAT64_C(   39.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -0.00), SIMDE_FLOAT64_C(   42.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -66.10), SIMDE_FLOAT64_C(  -55.20)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -66.10), SIMDE_FLOAT64_C( 1731.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -45.20), SIMDE_FLOAT64_C(   65.10)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -64.40), SIMDE_FLOAT64_C(   58.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   79.80), SIMDE_FLOAT64_C(   19.30)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( 2990.68), SIMDE_FLOAT64_C( 3756.50)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   14.50), SIMDE_FLOAT64_C(  -64.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   92.20), SIMDE_FLOAT64_C(  -68.80)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -2.50), SIMDE_FLOAT64_C(  -96.40)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( 1334.40), SIMDE_FLOAT64_C( 4561.52)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   61.50), SIMDE_FLOAT64_C(   42.40)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   77.20), SIMDE_FLOAT64_C(   23.30)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   32.20), SIMDE_FLOAT64_C(   12.10)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( 4780.00), SIMDE_FLOAT64_C(  975.82)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -38.20), SIMDE_FLOAT64_C(    8.10)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -10.10), SIMDE_FLOAT64_C(   98.60)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -14.20), SIMDE_FLOAT64_C(   22.60)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  371.62), SIMDE_FLOAT64_C(  776.06)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(    8.40), SIMDE_FLOAT64_C(  -30.70)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -39.30), SIMDE_FLOAT64_C(   73.40)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   25.30), SIMDE_FLOAT64_C(    2.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -304.82), SIMDE_FLOAT64_C(-2256.28)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_fmaddsub_pd(test_vec[i].a, test_vec[i].b, test_vec[i].c);
    simde_assert_m128d_f64_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_fmaddsub_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d b;
    simde__m256d c;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -52.10), SIMDE_FLOAT64_C(  -92.00),
                         SIMDE_FLOAT64_C(  -82.90), SIMDE_FLOAT64_C(  -49.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -49.30), SIMDE_FLOAT64_C(  -97.40),
                         SIMDE_FLOAT64_C(   58.80), SIMDE_FLOAT64_C(   67.60)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   23.30), SIMDE_FLOAT64_C(   87.10),
                         SIMDE_FLOAT64_C(   71.70), SIMDE_FLOAT64_C(   97.10)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( 2591.83), SIMDE_FLOAT64_C( 8873.70),
                         SIMDE_FLOAT64_C(-4802.82), SIMDE_FLOAT64_C(-3409.50)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -83.80), SIMDE_FLOAT64_C(   50.40),
                         SIMDE_FLOAT64_C(  -94.80), SIMDE_FLOAT64_C(  -86.80)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    3.10), SIMDE_FLOAT64_C(  -46.80),
                         SIMDE_FLOAT64_C(   -3.10), SIMDE_FLOAT64_C(   83.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -11.70), SIMDE_FLOAT64_C(   76.10),
                         SIMDE_FLOAT64_C(   44.50), SIMDE_FLOAT64_C(   28.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -271.48), SIMDE_FLOAT64_C(-2434.82),
                         SIMDE_FLOAT64_C(  338.38), SIMDE_FLOAT64_C(-7232.40)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -64.40), SIMDE_FLOAT64_C(   40.90),
                         SIMDE_FLOAT64_C(   36.80), SIMDE_FLOAT64_C(   -1.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -57.50), SIMDE_FLOAT64_C(    5.00),
                         SIMDE_FLOAT64_C(  -21.50), SIMDE_FLOAT64_C(   -1.70)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   21.60), SIMDE_FLOAT64_C(  -36.20),
                         SIMDE_FLOAT64_C(  -67.50), SIMDE_FLOAT64_C(  -19.30)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( 3724.60), SIMDE_FLOAT64_C(  240.70),
                         SIMDE_FLOAT64_C( -858.70), SIMDE_FLOAT64_C(   21.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -37.10), SIMDE_FLOAT64_C(    2.20),
                         SIMDE_FLOAT64_C(  -99.10), SIMDE_FLOAT64_C(   78.20)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -60.20), SIMDE_FLOAT64_C(   29.30),
                         SIMDE_FLOAT64_C(    2.50), SIMDE_FLOAT64_C(  -40.10)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   59.60), SIMDE_FLOAT64_C(  -28.40),
                         SIMDE_FLOAT64_C(   58.10), SIMDE_FLOAT64_C(   96.90)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( 2293.02), SIMDE_FLOAT64_C(   92.86),
                         SIMDE_FLOAT64_C( -189.65), SIMDE_FLOAT64_C(-3232.72)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -88.70), SIMDE_FLOAT64_C(  -20.50),
                         SIMDE_FLOAT64_C(   28.00), SIMDE_FLOAT64_C(  -13.70)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -49.60), SIMDE_FLOAT64_C(  -13.90),
                         SIMDE_FLOAT64_C(   71.80), SIMDE_FLOAT64_C(  -29.40)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -95.70), SIMDE_FLOAT64_C(   48.30),
                         SIMDE_FLOAT64_C(   78.20), SIMDE_FLOAT64_C(   -6.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( 4303.82), SIMDE_FLOAT64_C(  236.65),
                         SIMDE_FLOAT64_C( 2088.60), SIMDE_FLOAT64_C(  408.78)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   74.60), SIMDE_FLOAT64_C(   40.20),
                         SIMDE_FLOAT64_C(   -4.40), SIMDE_FLOAT64_C(   51.30)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   21.60), SIMDE_FLOAT64_C(  -83.50),
                         SIMDE_FLOAT64_C(   -2.00), SIMDE_FLOAT64_C(   -6.60)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   13.70), SIMDE_FLOAT64_C(   39.10),
                         SIMDE_FLOAT64_C(   92.60), SIMDE_FLOAT64_C(  -41.90)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( 1625.06), SIMDE_FLOAT64_C(-3395.80),
                         SIMDE_FLOAT64_C(  101.40), SIMDE_FLOAT64_C( -296.68)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -14.60), SIMDE_FLOAT64_C(  -32.40),
                         SIMDE_FLOAT64_C(   94.80), SIMDE_FLOAT64_C(   -5.20)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   15.40), SIMDE_FLOAT64_C(  -34.50),
                         SIMDE_FLOAT64_C(   91.60), SIMDE_FLOAT64_C(  -58.60)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -70.70), SIMDE_FLOAT64_C(  -91.10),
                         SIMDE_FLOAT64_C(  -42.30), SIMDE_FLOAT64_C(   64.70)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -295.54), SIMDE_FLOAT64_C( 1208.90),
                         SIMDE_FLOAT64_C( 8641.38), SIMDE_FLOAT64_C(  240.02)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   68.20), SIMDE_FLOAT64_C(  -45.40),
                         SIMDE_FLOAT64_C(   33.10), SIMDE_FLOAT64_C(   17.10)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   52.00), SIMDE_FLOAT64_C(   24.80),
                         SIMDE_FLOAT64_C(    6.10), SIMDE_FLOAT64_C(   68.80)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   30.10), SIMDE_FLOAT64_C(   11.20),
                         SIMDE_FLOAT64_C(  -78.00), SIMDE_FLOAT64_C(  -47.50)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( 3576.50), SIMDE_FLOAT64_C(-1137.12),
                         SIMDE_FLOAT64_C(  123.91), SIMDE_FLOAT64_C( 1223.98)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_fmaddsub_pd(test_vec[i].a, test_vec[i].b, test_vec[i].c);
    simde_assert_m256d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_fmaddsub_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 c;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -75.30), SIMDE_FLOAT32_C(   37.60), SIMDE_FLOAT32_C(   76.00), SIMDE_FLOAT32_C(   -4.20)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -15.80), SIMDE_FLOAT32_C(   64.20), SIMDE_FLOAT32_C(   50.90), SIMDE_FLOAT32_C(   26.10)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   64.80), SIMDE_FLOAT32_C(  -10.00), SIMDE_FLOAT32_C(  -97.40), SIMDE_FLOAT32_C(  -90.30)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 1254.54), SIMDE_FLOAT32_C( 2423.92), SIMDE_FLOAT32_C( 3771.00), SIMDE_FLOAT32_C(  -19.32)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -48.70), SIMDE_FLOAT32_C(   50.40), SIMDE_FLOAT32_C(  -22.00), SIMDE_FLOAT32_C(   76.40)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -80.30), SIMDE_FLOAT32_C(  -99.30), SIMDE_FLOAT32_C(  -86.10), SIMDE_FLOAT32_C(   30.10)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -41.10), SIMDE_FLOAT32_C(   57.20), SIMDE_FLOAT32_C(  -41.90), SIMDE_FLOAT32_C(  -88.50)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 3869.51), SIMDE_FLOAT32_C(-5061.92), SIMDE_FLOAT32_C( 1852.30), SIMDE_FLOAT32_C( 2388.14)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   99.70), SIMDE_FLOAT32_C(    2.10), SIMDE_FLOAT32_C(   41.80), SIMDE_FLOAT32_C(  -15.20)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   16.20), SIMDE_FLOAT32_C(  -74.30), SIMDE_FLOAT32_C(  -71.40), SIMDE_FLOAT32_C(   51.70)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   71.10), SIMDE_FLOAT32_C(  -90.60), SIMDE_FLOAT32_C(  -33.50), SIMDE_FLOAT32_C(  -68.40)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 1686.24), SIMDE_FLOAT32_C(  -65.43), SIMDE_FLOAT32_C(-3018.02), SIMDE_FLOAT32_C( -717.44)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   39.90), SIMDE_FLOAT32_C(   12.10), SIMDE_FLOAT32_C(  -93.10), SIMDE_FLOAT32_C(  -73.80)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -72.70), SIMDE_FLOAT32_C(  -61.90), SIMDE_FLOAT32_C(    1.90), SIMDE_FLOAT32_C(   89.00)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -63.40), SIMDE_FLOAT32_C(  -46.10), SIMDE_FLOAT32_C(   50.20), SIMDE_FLOAT32_C(  -74.10)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(-2964.13), SIMDE_FLOAT32_C( -702.89), SIMDE_FLOAT32_C( -126.69), SIMDE_FLOAT32_C(-6494.10)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -37.90), SIMDE_FLOAT32_C(   16.10), SIMDE_FLOAT32_C(   65.80), SIMDE_FLOAT32_C(   65.20)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -95.90), SIMDE_FLOAT32_C(    9.30), SIMDE_FLOAT32_C(   33.70), SIMDE_FLOAT32_C(  -30.80)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    4.30), SIMDE_FLOAT32_C(  -27.90), SIMDE_FLOAT32_C(  -62.30), SIMDE_FLOAT32_C(  -71.40)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 3638.91), SIMDE_FLOAT32_C(  177.63), SIMDE_FLOAT32_C( 2155.16), SIMDE_FLOAT32_C(-1936.76)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   40.20), SIMDE_FLOAT32_C(  -28.10), SIMDE_FLOAT32_C(  -39.20), SIMDE_FLOAT32_C(   15.00)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -33.70), SIMDE_FLOAT32_C(  -55.90), SIMDE_FLOAT32_C(   -9.80), SIMDE_FLOAT32_C(  -88.20)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    3.20), SIMDE_FLOAT32_C(  -50.90), SIMDE_FLOAT32_C(   35.30), SIMDE_FLOAT32_C(  -45.30)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(-1351.54), SIMDE_FLOAT32_C( 1621.69), SIMDE_FLOAT32_C(  419.46), SIMDE_FLOAT32_C(-1277.70)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(    2.60), SIMDE_FLOAT32_C(   70.50), SIMDE_FLOAT32_C(   56.20), SIMDE_FLOAT32_C(    5.90)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -66.40), SIMDE_FLOAT32_C(   95.00), SIMDE_FLOAT32_C(   95.50), SIMDE_FLOAT32_C(  -15.90)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -60.10), SIMDE_FLOAT32_C(  -25.30), SIMDE_FLOAT32_C(  -69.10), SIMDE_FLOAT32_C(  -77.70)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -232.74), SIMDE_FLOAT32_C( 6722.80), SIMDE_FLOAT32_C( 5298.00), SIMDE_FLOAT32_C(  -16.11)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -91.20), SIMDE_FLOAT32_C(   32.90), SIMDE_FLOAT32_C(   -8.90), SIMDE_FLOAT32_C(  -97.30)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -78.50), SIMDE_FLOAT32_C(   49.50), SIMDE_FLOAT32_C(   63.70), SIMDE_FLOAT32_C(  -83.00)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   10.30), SIMDE_FLOAT32_C(   73.30), SIMDE_FLOAT32_C(  -68.20), SIMDE_FLOAT32_C(   60.90)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 7169.50), SIMDE_FLOAT32_C( 1555.25), SIMDE_FLOAT32_C( -635.13), SIMDE_FLOAT32_C( 8015.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_fmaddsub_ps(test_vec[i].a, test_vec[i].b, test_vec[i].c);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_fmaddsub_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 b;
    simde__m256 c;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -61.10), SIMDE_FLOAT32_C(  -95.60),
                         SIMDE_FLOAT32_C(   56.00), SIMDE_FLOAT32_C(   46.30),
                         SIMDE_FLOAT32_C(  -62.80), SIMDE_FLOAT32_C(   38.90),
                         SIMDE_FLOAT32_C(  -92.60), SIMDE_FLOAT32_C(   65.40)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -38.30), SIMDE_FLOAT32_C(   -1.90),
                         SIMDE_FLOAT32_C(  -28.00), SIMDE_FLOAT32_C(  -43.20),
                         SIMDE_FLOAT32_C(  -19.40), SIMDE_FLOAT32_C(   57.60),
                         SIMDE_FLOAT32_C(  -97.20), SIMDE_FLOAT32_C(   81.20)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   93.20), SIMDE_FLOAT32_C(  -43.00),
                         SIMDE_FLOAT32_C(  -47.40), SIMDE_FLOAT32_C(  -77.00),
                         SIMDE_FLOAT32_C(  -59.90), SIMDE_FLOAT32_C(   17.90),
                         SIMDE_FLOAT32_C(   -9.60), SIMDE_FLOAT32_C(  -61.30)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( 2433.33), SIMDE_FLOAT32_C(  224.64),
                         SIMDE_FLOAT32_C(-1615.40), SIMDE_FLOAT32_C(-1923.16),
                         SIMDE_FLOAT32_C( 1158.42), SIMDE_FLOAT32_C( 2222.74),
                         SIMDE_FLOAT32_C( 8991.12), SIMDE_FLOAT32_C( 5371.78)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -23.40), SIMDE_FLOAT32_C(  -24.60),
                         SIMDE_FLOAT32_C(   35.70), SIMDE_FLOAT32_C(   59.90),
                         SIMDE_FLOAT32_C(  -91.00), SIMDE_FLOAT32_C(  -25.40),
                         SIMDE_FLOAT32_C(  -88.30), SIMDE_FLOAT32_C(  -99.80)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -30.70), SIMDE_FLOAT32_C(   97.10),
                         SIMDE_FLOAT32_C(   86.90), SIMDE_FLOAT32_C(  -81.10),
                         SIMDE_FLOAT32_C(  -71.30), SIMDE_FLOAT32_C(  -61.20),
                         SIMDE_FLOAT32_C(  -26.10), SIMDE_FLOAT32_C(   31.60)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -74.30), SIMDE_FLOAT32_C(  -19.40),
                         SIMDE_FLOAT32_C(  -70.80), SIMDE_FLOAT32_C(  -13.00),
                         SIMDE_FLOAT32_C(   82.90), SIMDE_FLOAT32_C(  -75.70),
                         SIMDE_FLOAT32_C(  -31.50), SIMDE_FLOAT32_C(   73.50)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  644.08), SIMDE_FLOAT32_C(-2369.26),
                         SIMDE_FLOAT32_C( 3031.53), SIMDE_FLOAT32_C(-4844.89),
                         SIMDE_FLOAT32_C( 6571.20), SIMDE_FLOAT32_C( 1630.18),
                         SIMDE_FLOAT32_C( 2273.13), SIMDE_FLOAT32_C(-3227.18)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   70.20), SIMDE_FLOAT32_C(  -20.40),
                         SIMDE_FLOAT32_C(  -51.50), SIMDE_FLOAT32_C(   82.30),
                         SIMDE_FLOAT32_C(   31.30), SIMDE_FLOAT32_C(   17.80),
                         SIMDE_FLOAT32_C(  -39.60), SIMDE_FLOAT32_C(   66.80)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -72.50), SIMDE_FLOAT32_C(   52.00),
                         SIMDE_FLOAT32_C(  -54.80), SIMDE_FLOAT32_C(   14.00),
                         SIMDE_FLOAT32_C(   91.80), SIMDE_FLOAT32_C(  -80.70),
                         SIMDE_FLOAT32_C(  -97.90), SIMDE_FLOAT32_C(  -99.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -76.10), SIMDE_FLOAT32_C(   26.90),
                         SIMDE_FLOAT32_C(   24.90), SIMDE_FLOAT32_C(  -50.60),
                         SIMDE_FLOAT32_C(   66.90), SIMDE_FLOAT32_C(   82.40),
                         SIMDE_FLOAT32_C(   98.50), SIMDE_FLOAT32_C(    9.60)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-5165.60), SIMDE_FLOAT32_C(-1087.70),
                         SIMDE_FLOAT32_C( 2847.10), SIMDE_FLOAT32_C( 1202.80),
                         SIMDE_FLOAT32_C( 2940.24), SIMDE_FLOAT32_C(-1518.86),
                         SIMDE_FLOAT32_C( 3975.34), SIMDE_FLOAT32_C(-6622.80)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -28.40), SIMDE_FLOAT32_C(   22.80),
                         SIMDE_FLOAT32_C(   16.40), SIMDE_FLOAT32_C(   80.20),
                         SIMDE_FLOAT32_C(  -24.10), SIMDE_FLOAT32_C(  -83.00),
                         SIMDE_FLOAT32_C(  -74.10), SIMDE_FLOAT32_C(  -49.60)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -73.70), SIMDE_FLOAT32_C(   59.00),
                         SIMDE_FLOAT32_C(   36.90), SIMDE_FLOAT32_C(    7.50),
                         SIMDE_FLOAT32_C(  -74.80), SIMDE_FLOAT32_C(  -84.40),
                         SIMDE_FLOAT32_C(   79.60), SIMDE_FLOAT32_C(  -90.70)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -76.40), SIMDE_FLOAT32_C(   28.10),
                         SIMDE_FLOAT32_C(  -13.60), SIMDE_FLOAT32_C(  -71.50),
                         SIMDE_FLOAT32_C(  -52.20), SIMDE_FLOAT32_C(  -30.20),
                         SIMDE_FLOAT32_C(  -62.60), SIMDE_FLOAT32_C(    2.30)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( 2016.68), SIMDE_FLOAT32_C( 1317.10),
                         SIMDE_FLOAT32_C(  591.56), SIMDE_FLOAT32_C(  673.00),
                         SIMDE_FLOAT32_C( 1750.48), SIMDE_FLOAT32_C( 7035.40),
                         SIMDE_FLOAT32_C(-5960.96), SIMDE_FLOAT32_C( 4496.42)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   74.80), SIMDE_FLOAT32_C(   79.60),
                         SIMDE_FLOAT32_C(  -91.30), SIMDE_FLOAT32_C(   86.60),
                         SIMDE_FLOAT32_C(   41.70), SIMDE_FLOAT32_C(  -74.30),
                         SIMDE_FLOAT32_C(  -75.60), SIMDE_FLOAT32_C(   28.50)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   96.00), SIMDE_FLOAT32_C(   10.10),
                         SIMDE_FLOAT32_C(  -63.40), SIMDE_FLOAT32_C(   96.90),
                         SIMDE_FLOAT32_C(   66.20), SIMDE_FLOAT32_C(  -75.30),
                         SIMDE_FLOAT32_C(  -11.80), SIMDE_FLOAT32_C(   30.70)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   31.70), SIMDE_FLOAT32_C(  -47.90),
                         SIMDE_FLOAT32_C(   27.70), SIMDE_FLOAT32_C(   40.70),
                         SIMDE_FLOAT32_C(  -22.80), SIMDE_FLOAT32_C(   35.80),
                         SIMDE_FLOAT32_C(  -30.10), SIMDE_FLOAT32_C(   88.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( 7212.50), SIMDE_FLOAT32_C(  851.86),
                         SIMDE_FLOAT32_C( 5816.12), SIMDE_FLOAT32_C( 8350.84),
                         SIMDE_FLOAT32_C( 2737.74), SIMDE_FLOAT32_C( 5558.99),
                         SIMDE_FLOAT32_C(  861.98), SIMDE_FLOAT32_C(  786.95)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   91.80), SIMDE_FLOAT32_C(  -99.10),
                         SIMDE_FLOAT32_C(  -91.30), SIMDE_FLOAT32_C(   69.40),
                         SIMDE_FLOAT32_C(   38.40), SIMDE_FLOAT32_C(  -90.40),
                         SIMDE_FLOAT32_C(   62.20), SIMDE_FLOAT32_C(  -62.50)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   82.70), SIMDE_FLOAT32_C(  -63.90),
                         SIMDE_FLOAT32_C(   57.00), SIMDE_FLOAT32_C(  -53.70),
                         SIMDE_FLOAT32_C(  -62.00), SIMDE_FLOAT32_C(   87.90),
                         SIMDE_FLOAT32_C(  -60.70), SIMDE_FLOAT32_C(  -94.50)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   65.30), SIMDE_FLOAT32_C(   61.10),
                         SIMDE_FLOAT32_C(  -35.30), SIMDE_FLOAT32_C(  -37.60),
                         SIMDE_FLOAT32_C(    3.40), SIMDE_FLOAT32_C(   10.20),
                         SIMDE_FLOAT32_C(   25.70), SIMDE_FLOAT32_C(   31.10)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( 7657.16), SIMDE_FLOAT32_C( 6271.39),
                         SIMDE_FLOAT32_C(-5239.40), SIMDE_FLOAT32_C(-3689.18),
                         SIMDE_FLOAT32_C(-2377.40), SIMDE_FLOAT32_C(-7956.36),
                         SIMDE_FLOAT32_C(-3749.84), SIMDE_FLOAT32_C( 5875.15)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   -9.70), SIMDE_FLOAT32_C(   54.70),
                         SIMDE_FLOAT32_C(  -66.40), SIMDE_FLOAT32_C(  -34.70),
                         SIMDE_FLOAT32_C(  -27.90), SIMDE_FLOAT32_C(   92.40),
                         SIMDE_FLOAT32_C(  -11.40), SIMDE_FLOAT32_C(   14.60)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -0.90), SIMDE_FLOAT32_C(  -71.50),
                         SIMDE_FLOAT32_C(   67.00), SIMDE_FLOAT32_C(  -56.30),
                         SIMDE_FLOAT32_C(   74.40), SIMDE_FLOAT32_C(    9.80),
                         SIMDE_FLOAT32_C(   -5.30), SIMDE_FLOAT32_C(   63.80)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -47.10), SIMDE_FLOAT32_C(   81.20),
                         SIMDE_FLOAT32_C(   31.00), SIMDE_FLOAT32_C(   11.50),
                         SIMDE_FLOAT32_C(   67.80), SIMDE_FLOAT32_C(  -14.20),
                         SIMDE_FLOAT32_C(  -62.80), SIMDE_FLOAT32_C(   84.70)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -38.37), SIMDE_FLOAT32_C(-3992.25),
                         SIMDE_FLOAT32_C(-4417.80), SIMDE_FLOAT32_C( 1942.11),
                         SIMDE_FLOAT32_C(-2007.96), SIMDE_FLOAT32_C(  919.72),
                         SIMDE_FLOAT32_C(   -2.38), SIMDE_FLOAT32_C(  846.78)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -14.10), SIMDE_FLOAT32_C(  -90.60),
                         SIMDE_FLOAT32_C(   37.70), SIMDE_FLOAT32_C(   63.50),
                         SIMDE_FLOAT32_C(  -67.90), SIMDE_FLOAT32_C(  -75.70),
                         SIMDE_FLOAT32_C(   48.30), SIMDE_FLOAT32_C(   69.80)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   21.20), SIMDE_FLOAT32_C(  -56.80),
                         SIMDE_FLOAT32_C(  -51.20), SIMDE_FLOAT32_C(  -55.60),
                         SIMDE_FLOAT32_C(   65.10), SIMDE_FLOAT32_C(   21.30),
                         SIMDE_FLOAT32_C(  -29.20), SIMDE_FLOAT32_C(  -61.60)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   55.80), SIMDE_FLOAT32_C(  -16.50),
                         SIMDE_FLOAT32_C(   90.30), SIMDE_FLOAT32_C(   10.50),
                         SIMDE_FLOAT32_C(  -35.10), SIMDE_FLOAT32_C(    8.40),
                         SIMDE_FLOAT32_C(  -35.70), SIMDE_FLOAT32_C(   70.80)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -243.12), SIMDE_FLOAT32_C( 5162.58),
                         SIMDE_FLOAT32_C(-1839.94), SIMDE_FLOAT32_C(-3541.10),
                         SIMDE_FLOAT32_C(-4455.39), SIMDE_FLOAT32_C(-1620.81),
                         SIMDE_FLOAT32_C(-1446.06), SIMDE_FLOAT32_C(-4370.48)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_fmaddsub_ps(test_vec[i].a, test_vec[i].b, test_vec[i].c);
    simde_assert_m256_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_fmsub_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d c;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -86.00), SIMDE_FLOAT64_C(  -88.70)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   79.20), SIMDE_FLOAT64_C(  -72.70)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   69.30), SIMDE_FLOAT64_C(  -94.80)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(-6880.50), SIMDE_FLOAT64_C( 6543.29)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   29.00), SIMDE_FLOAT64_C(  -23.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   88.90), SIMDE_FLOAT64_C(   98.30)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -27.80), SIMDE_FLOAT64_C(  -64.50)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( 2605.90), SIMDE_FLOAT64_C(-2196.40)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -56.40), SIMDE_FLOAT64_C(   49.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   79.10), SIMDE_FLOAT64_C(  -51.70)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -66.70), SIMDE_FLOAT64_C(   16.60)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(-4394.54), SIMDE_FLOAT64_C(-2596.43)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -73.50), SIMDE_FLOAT64_C(   25.30)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   95.60), SIMDE_FLOAT64_C(   38.70)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   96.40), SIMDE_FLOAT64_C(   40.10)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(-7123.00), SIMDE_FLOAT64_C(  939.01)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   96.70), SIMDE_FLOAT64_C(  -25.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -31.20), SIMDE_FLOAT64_C(  -59.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -18.60), SIMDE_FLOAT64_C(  -15.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(-2998.44), SIMDE_FLOAT64_C( 1567.31)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -63.20), SIMDE_FLOAT64_C(  -69.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -27.30), SIMDE_FLOAT64_C(   57.70)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   17.60), SIMDE_FLOAT64_C(   32.80)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( 1707.76), SIMDE_FLOAT64_C(-4066.03)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -33.50), SIMDE_FLOAT64_C(   64.70)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -68.40), SIMDE_FLOAT64_C(  -49.20)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   44.70), SIMDE_FLOAT64_C(   88.70)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( 2246.70), SIMDE_FLOAT64_C(-3271.94)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -79.60), SIMDE_FLOAT64_C(  -61.60)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -29.20), SIMDE_FLOAT64_C(  -21.10)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -94.70), SIMDE_FLOAT64_C(  -26.20)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( 2419.02), SIMDE_FLOAT64_C( 1325.96)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_fmsub_pd(test_vec[i].a, test_vec[i].b, test_vec[i].c);
    simde_assert_m128d_f64_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_fmsub_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d b;
    simde__m256d c;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   34.80), SIMDE_FLOAT64_C(   57.60),
                         SIMDE_FLOAT64_C(   21.20), SIMDE_FLOAT64_C(   58.70)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -15.50), SIMDE_FLOAT64_C(  -85.90),
                         SIMDE_FLOAT64_C(   76.40), SIMDE_FLOAT64_C(   37.40)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -67.00), SIMDE_FLOAT64_C(  -15.40),
                         SIMDE_FLOAT64_C(   94.00), SIMDE_FLOAT64_C(  -95.50)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -472.40), SIMDE_FLOAT64_C(-4932.44),
                         SIMDE_FLOAT64_C( 1525.68), SIMDE_FLOAT64_C( 2290.88)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   79.40), SIMDE_FLOAT64_C(  -18.40),
                         SIMDE_FLOAT64_C(  -87.30), SIMDE_FLOAT64_C(  -43.70)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   46.70), SIMDE_FLOAT64_C(  -61.00),
                         SIMDE_FLOAT64_C(   22.50), SIMDE_FLOAT64_C(  -19.30)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -92.50), SIMDE_FLOAT64_C(   24.60),
                         SIMDE_FLOAT64_C(   48.50), SIMDE_FLOAT64_C(   81.10)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( 3800.48), SIMDE_FLOAT64_C( 1097.80),
                         SIMDE_FLOAT64_C(-2012.75), SIMDE_FLOAT64_C(  762.31)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -53.30), SIMDE_FLOAT64_C(   37.50),
                         SIMDE_FLOAT64_C(  -12.20), SIMDE_FLOAT64_C(   77.20)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   44.30), SIMDE_FLOAT64_C(   68.70),
                         SIMDE_FLOAT64_C(   45.00), SIMDE_FLOAT64_C(  -94.90)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   10.90), SIMDE_FLOAT64_C(  -78.60),
                         SIMDE_FLOAT64_C(   59.40), SIMDE_FLOAT64_C(   54.70)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(-2372.09), SIMDE_FLOAT64_C( 2654.85),
                         SIMDE_FLOAT64_C( -608.40), SIMDE_FLOAT64_C(-7380.98)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -45.20), SIMDE_FLOAT64_C(  -98.30),
                         SIMDE_FLOAT64_C(    6.30), SIMDE_FLOAT64_C(  -64.20)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   47.00), SIMDE_FLOAT64_C(  -17.30),
                         SIMDE_FLOAT64_C(   90.50), SIMDE_FLOAT64_C(   33.20)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -47.40), SIMDE_FLOAT64_C(  -48.00),
                         SIMDE_FLOAT64_C(   92.50), SIMDE_FLOAT64_C(  -62.30)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(-2077.00), SIMDE_FLOAT64_C( 1748.59),
                         SIMDE_FLOAT64_C(  477.65), SIMDE_FLOAT64_C(-2069.14)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -66.50), SIMDE_FLOAT64_C(   50.50),
                         SIMDE_FLOAT64_C(  -60.50), SIMDE_FLOAT64_C(   97.50)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -77.70), SIMDE_FLOAT64_C(  -31.10),
                         SIMDE_FLOAT64_C(   56.50), SIMDE_FLOAT64_C(  -49.90)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -78.10), SIMDE_FLOAT64_C(  -33.20),
                         SIMDE_FLOAT64_C(   60.50), SIMDE_FLOAT64_C(   91.20)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( 5245.15), SIMDE_FLOAT64_C(-1537.35),
                         SIMDE_FLOAT64_C(-3478.75), SIMDE_FLOAT64_C(-4956.45)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   97.80), SIMDE_FLOAT64_C(    3.10),
                         SIMDE_FLOAT64_C(   -8.70), SIMDE_FLOAT64_C(   56.90)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   88.60), SIMDE_FLOAT64_C(  -73.80),
                         SIMDE_FLOAT64_C(   92.30), SIMDE_FLOAT64_C(   21.50)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -81.80), SIMDE_FLOAT64_C(  -53.80),
                         SIMDE_FLOAT64_C(  -76.80), SIMDE_FLOAT64_C(  -90.20)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( 8746.88), SIMDE_FLOAT64_C( -174.98),
                         SIMDE_FLOAT64_C( -726.21), SIMDE_FLOAT64_C( 1313.55)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -20.60), SIMDE_FLOAT64_C(  -46.30),
                         SIMDE_FLOAT64_C(   51.00), SIMDE_FLOAT64_C(   60.50)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -26.30), SIMDE_FLOAT64_C(  -65.50),
                         SIMDE_FLOAT64_C(  -31.40), SIMDE_FLOAT64_C(   -0.20)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -79.80), SIMDE_FLOAT64_C(   98.80),
                         SIMDE_FLOAT64_C(   31.60), SIMDE_FLOAT64_C(  -29.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  621.58), SIMDE_FLOAT64_C( 2933.85),
                         SIMDE_FLOAT64_C(-1633.00), SIMDE_FLOAT64_C(   16.90)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   73.70), SIMDE_FLOAT64_C(  -28.30),
                         SIMDE_FLOAT64_C(   -1.90), SIMDE_FLOAT64_C(  -61.50)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -19.60), SIMDE_FLOAT64_C(  -92.40),
                         SIMDE_FLOAT64_C(  -22.30), SIMDE_FLOAT64_C(  -53.90)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -75.90), SIMDE_FLOAT64_C(   72.50),
                         SIMDE_FLOAT64_C(  -50.10), SIMDE_FLOAT64_C(   18.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(-1368.62), SIMDE_FLOAT64_C( 2542.42),
                         SIMDE_FLOAT64_C(   92.47), SIMDE_FLOAT64_C( 3296.85)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_fmsub_pd(test_vec[i].a, test_vec[i].b, test_vec[i].c);
    simde_assert_m256d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_fmsub_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 c;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -36.50), SIMDE_FLOAT32_C(   13.70), SIMDE_FLOAT32_C(   -3.10), SIMDE_FLOAT32_C(   21.40)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   80.60), SIMDE_FLOAT32_C(   11.30), SIMDE_FLOAT32_C(   96.80), SIMDE_FLOAT32_C(  -38.20)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   -8.50), SIMDE_FLOAT32_C(  -28.20), SIMDE_FLOAT32_C(  -26.80), SIMDE_FLOAT32_C(  -95.00)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(-2933.40), SIMDE_FLOAT32_C(  183.01), SIMDE_FLOAT32_C( -273.28), SIMDE_FLOAT32_C( -722.48)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   59.20), SIMDE_FLOAT32_C(   -6.20), SIMDE_FLOAT32_C(  -52.90), SIMDE_FLOAT32_C(  -75.70)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   61.80), SIMDE_FLOAT32_C(  -76.10), SIMDE_FLOAT32_C(  -87.70), SIMDE_FLOAT32_C(  -40.50)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   34.20), SIMDE_FLOAT32_C(   37.10), SIMDE_FLOAT32_C(    7.30), SIMDE_FLOAT32_C(   67.80)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 3624.36), SIMDE_FLOAT32_C(  434.72), SIMDE_FLOAT32_C( 4632.03), SIMDE_FLOAT32_C( 2998.05)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -85.40), SIMDE_FLOAT32_C(   36.60), SIMDE_FLOAT32_C(  -55.80), SIMDE_FLOAT32_C(    5.90)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -37.10), SIMDE_FLOAT32_C(   37.80), SIMDE_FLOAT32_C(   -6.30), SIMDE_FLOAT32_C(   90.40)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   16.90), SIMDE_FLOAT32_C(  -83.90), SIMDE_FLOAT32_C(   82.90), SIMDE_FLOAT32_C(   23.00)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 3151.44), SIMDE_FLOAT32_C( 1467.38), SIMDE_FLOAT32_C(  268.64), SIMDE_FLOAT32_C(  510.36)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   59.30), SIMDE_FLOAT32_C(   97.10), SIMDE_FLOAT32_C(   -5.30), SIMDE_FLOAT32_C(  -37.40)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   -7.50), SIMDE_FLOAT32_C(   42.80), SIMDE_FLOAT32_C(  -32.50), SIMDE_FLOAT32_C(  -34.60)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   25.50), SIMDE_FLOAT32_C(   87.80), SIMDE_FLOAT32_C(   95.90), SIMDE_FLOAT32_C(  -68.30)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -470.25), SIMDE_FLOAT32_C( 4068.08), SIMDE_FLOAT32_C(   76.35), SIMDE_FLOAT32_C( 1362.34)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -87.90), SIMDE_FLOAT32_C(  -35.50), SIMDE_FLOAT32_C(  -15.00), SIMDE_FLOAT32_C(   72.80)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   78.40), SIMDE_FLOAT32_C(   83.00), SIMDE_FLOAT32_C(   34.70), SIMDE_FLOAT32_C(   -8.50)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   99.60), SIMDE_FLOAT32_C(   96.00), SIMDE_FLOAT32_C(   45.40), SIMDE_FLOAT32_C(  -79.90)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(-6990.96), SIMDE_FLOAT32_C(-3042.50), SIMDE_FLOAT32_C( -565.90), SIMDE_FLOAT32_C( -538.90)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   26.30), SIMDE_FLOAT32_C(   69.80), SIMDE_FLOAT32_C(  -48.50), SIMDE_FLOAT32_C(  -58.50)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   85.00), SIMDE_FLOAT32_C(  -97.40), SIMDE_FLOAT32_C(   16.90), SIMDE_FLOAT32_C(  -37.30)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -22.30), SIMDE_FLOAT32_C(   21.90), SIMDE_FLOAT32_C(  -79.20), SIMDE_FLOAT32_C(  -99.20)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( 2257.80), SIMDE_FLOAT32_C(-6820.42), SIMDE_FLOAT32_C( -740.45), SIMDE_FLOAT32_C( 2281.25)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   24.00), SIMDE_FLOAT32_C(   51.40), SIMDE_FLOAT32_C(  -24.70), SIMDE_FLOAT32_C(  -32.50)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   34.10), SIMDE_FLOAT32_C(   90.10), SIMDE_FLOAT32_C(   39.10), SIMDE_FLOAT32_C(  -33.10)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   63.90), SIMDE_FLOAT32_C(  -54.20), SIMDE_FLOAT32_C(  -27.60), SIMDE_FLOAT32_C(   31.70)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  754.50), SIMDE_FLOAT32_C( 4685.34), SIMDE_FLOAT32_C( -938.17), SIMDE_FLOAT32_C( 1044.05)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   45.70), SIMDE_FLOAT32_C(  -95.60), SIMDE_FLOAT32_C(   14.60), SIMDE_FLOAT32_C(   -3.40)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -90.50), SIMDE_FLOAT32_C(  -20.20), SIMDE_FLOAT32_C(   91.40), SIMDE_FLOAT32_C(   25.10)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -26.90), SIMDE_FLOAT32_C(   29.30), SIMDE_FLOAT32_C(   77.50), SIMDE_FLOAT32_C(  -80.00)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(-4108.95), SIMDE_FLOAT32_C( 1901.82), SIMDE_FLOAT32_C( 1256.94), SIMDE_FLOAT32_C(   -5.34)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_fmsub_ps(test_vec[i].a, test_vec[i].b, test_vec[i].c);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_fmsub_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 b;
    simde__m256 c;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   71.60), SIMDE_FLOAT32_C(   70.70),
                         SIMDE_FLOAT32_C(   40.60), SIMDE_FLOAT32_C(   -9.30),
                         SIMDE_FLOAT32_C(  -79.10), SIMDE_FLOAT32_C(   52.30),
                         SIMDE_FLOAT32_C(  -67.90), SIMDE_FLOAT32_C(   25.70)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -51.50), SIMDE_FLOAT32_C(   43.80),
                         SIMDE_FLOAT32_C(   41.70), SIMDE_FLOAT32_C(  -77.20),
                         SIMDE_FLOAT32_C(   -5.00), SIMDE_FLOAT32_C(   96.70),
                         SIMDE_FLOAT32_C(  -13.50), SIMDE_FLOAT32_C(   -2.70)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -28.70), SIMDE_FLOAT32_C(  -28.30),
                         SIMDE_FLOAT32_C(    1.80), SIMDE_FLOAT32_C(  -81.10),
                         SIMDE_FLOAT32_C(  -82.10), SIMDE_FLOAT32_C(  -69.80),
                         SIMDE_FLOAT32_C(   42.10), SIMDE_FLOAT32_C(   74.70)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-3658.70), SIMDE_FLOAT32_C( 3124.96),
                         SIMDE_FLOAT32_C( 1691.22), SIMDE_FLOAT32_C(  799.06),
                         SIMDE_FLOAT32_C(  477.60), SIMDE_FLOAT32_C( 5127.21),
                         SIMDE_FLOAT32_C(  874.55), SIMDE_FLOAT32_C( -144.09)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -49.00), SIMDE_FLOAT32_C(  -78.70),
                         SIMDE_FLOAT32_C(  -72.10), SIMDE_FLOAT32_C(   26.10),
                         SIMDE_FLOAT32_C(  -91.90), SIMDE_FLOAT32_C(    1.40),
                         SIMDE_FLOAT32_C(   89.80), SIMDE_FLOAT32_C(   94.20)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -13.70), SIMDE_FLOAT32_C(    0.70),
                         SIMDE_FLOAT32_C(   57.80), SIMDE_FLOAT32_C(   33.00),
                         SIMDE_FLOAT32_C(  -83.50), SIMDE_FLOAT32_C(   -8.10),
                         SIMDE_FLOAT32_C(   91.30), SIMDE_FLOAT32_C(   65.20)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -67.90), SIMDE_FLOAT32_C(  -56.40),
                         SIMDE_FLOAT32_C(    5.90), SIMDE_FLOAT32_C(    2.40),
                         SIMDE_FLOAT32_C(   91.80), SIMDE_FLOAT32_C(   50.80),
                         SIMDE_FLOAT32_C(   64.70), SIMDE_FLOAT32_C(  -56.10)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  739.20), SIMDE_FLOAT32_C(    1.31),
                         SIMDE_FLOAT32_C(-4173.28), SIMDE_FLOAT32_C(  858.90),
                         SIMDE_FLOAT32_C( 7581.85), SIMDE_FLOAT32_C(  -62.14),
                         SIMDE_FLOAT32_C( 8134.04), SIMDE_FLOAT32_C( 6197.94)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   40.00), SIMDE_FLOAT32_C(   -5.30),
                         SIMDE_FLOAT32_C(   85.00), SIMDE_FLOAT32_C(   83.70),
                         SIMDE_FLOAT32_C(   96.80), SIMDE_FLOAT32_C(  -59.70),
                         SIMDE_FLOAT32_C(  -72.50), SIMDE_FLOAT32_C(   -8.10)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   77.50), SIMDE_FLOAT32_C(   50.00),
                         SIMDE_FLOAT32_C(   72.40), SIMDE_FLOAT32_C(   98.40),
                         SIMDE_FLOAT32_C(   69.10), SIMDE_FLOAT32_C(   35.80),
                         SIMDE_FLOAT32_C(  -92.90), SIMDE_FLOAT32_C(   63.70)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   73.80), SIMDE_FLOAT32_C(  -94.30),
                         SIMDE_FLOAT32_C(  -79.50), SIMDE_FLOAT32_C(   64.60),
                         SIMDE_FLOAT32_C(   63.40), SIMDE_FLOAT32_C(  -65.00),
                         SIMDE_FLOAT32_C(   75.20), SIMDE_FLOAT32_C(   48.70)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( 3026.20), SIMDE_FLOAT32_C( -170.70),
                         SIMDE_FLOAT32_C( 6233.50), SIMDE_FLOAT32_C( 8171.48),
                         SIMDE_FLOAT32_C( 6625.48), SIMDE_FLOAT32_C(-2072.26),
                         SIMDE_FLOAT32_C( 6660.05), SIMDE_FLOAT32_C( -564.67)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -82.20), SIMDE_FLOAT32_C(   93.30),
                         SIMDE_FLOAT32_C(    9.70), SIMDE_FLOAT32_C(   -2.70),
                         SIMDE_FLOAT32_C(   86.00), SIMDE_FLOAT32_C(  -20.80),
                         SIMDE_FLOAT32_C(   67.70), SIMDE_FLOAT32_C(  -47.20)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -83.70), SIMDE_FLOAT32_C(   12.00),
                         SIMDE_FLOAT32_C(   23.10), SIMDE_FLOAT32_C(  -42.00),
                         SIMDE_FLOAT32_C(   46.30), SIMDE_FLOAT32_C(   48.20),
                         SIMDE_FLOAT32_C(   86.90), SIMDE_FLOAT32_C(  -91.50)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -48.60), SIMDE_FLOAT32_C(   92.30),
                         SIMDE_FLOAT32_C(  -12.70), SIMDE_FLOAT32_C(  -48.20),
                         SIMDE_FLOAT32_C(   60.90), SIMDE_FLOAT32_C(   43.20),
                         SIMDE_FLOAT32_C(  -71.30), SIMDE_FLOAT32_C(  -56.60)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( 6928.74), SIMDE_FLOAT32_C( 1027.30),
                         SIMDE_FLOAT32_C(  236.77), SIMDE_FLOAT32_C(  161.60),
                         SIMDE_FLOAT32_C( 3920.90), SIMDE_FLOAT32_C(-1045.76),
                         SIMDE_FLOAT32_C( 5954.43), SIMDE_FLOAT32_C( 4375.40)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   32.60), SIMDE_FLOAT32_C(   90.30),
                         SIMDE_FLOAT32_C(  -31.90), SIMDE_FLOAT32_C(   33.60),
                         SIMDE_FLOAT32_C(   47.40), SIMDE_FLOAT32_C(   49.30),
                         SIMDE_FLOAT32_C(  -73.00), SIMDE_FLOAT32_C(   55.80)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -72.60), SIMDE_FLOAT32_C(   34.70),
                         SIMDE_FLOAT32_C(   -8.30), SIMDE_FLOAT32_C(  -47.40),
                         SIMDE_FLOAT32_C(  -91.00), SIMDE_FLOAT32_C(  -99.10),
                         SIMDE_FLOAT32_C(  -84.60), SIMDE_FLOAT32_C(  -13.50)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -84.20), SIMDE_FLOAT32_C(   35.00),
                         SIMDE_FLOAT32_C(  -58.10), SIMDE_FLOAT32_C(   81.70),
                         SIMDE_FLOAT32_C(    1.20), SIMDE_FLOAT32_C(  -33.20),
                         SIMDE_FLOAT32_C(   36.00), SIMDE_FLOAT32_C(  -80.90)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-2282.56), SIMDE_FLOAT32_C( 3098.41),
                         SIMDE_FLOAT32_C(  322.87), SIMDE_FLOAT32_C(-1674.34),
                         SIMDE_FLOAT32_C(-4314.60), SIMDE_FLOAT32_C(-4852.43),
                         SIMDE_FLOAT32_C( 6139.80), SIMDE_FLOAT32_C( -672.40)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -58.90), SIMDE_FLOAT32_C(   53.10),
                         SIMDE_FLOAT32_C(  -76.60), SIMDE_FLOAT32_C(   83.00),
                         SIMDE_FLOAT32_C(   91.20), SIMDE_FLOAT32_C(  -33.50),
                         SIMDE_FLOAT32_C(  -65.20), SIMDE_FLOAT32_C(  -55.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -47.40), SIMDE_FLOAT32_C(  -20.10),
                         SIMDE_FLOAT32_C(  -89.40), SIMDE_FLOAT32_C(   87.90),
                         SIMDE_FLOAT32_C(  -65.50), SIMDE_FLOAT32_C(  -20.70),
                         SIMDE_FLOAT32_C(   88.30), SIMDE_FLOAT32_C(   20.40)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   50.40), SIMDE_FLOAT32_C(   75.40),
                         SIMDE_FLOAT32_C(   79.80), SIMDE_FLOAT32_C(    5.10),
                         SIMDE_FLOAT32_C(   -6.50), SIMDE_FLOAT32_C(  -47.90),
                         SIMDE_FLOAT32_C(   48.50), SIMDE_FLOAT32_C(  -69.90)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( 2741.46), SIMDE_FLOAT32_C(-1142.71),
                         SIMDE_FLOAT32_C( 6768.24), SIMDE_FLOAT32_C( 7290.60),
                         SIMDE_FLOAT32_C(-5967.10), SIMDE_FLOAT32_C(  741.35),
                         SIMDE_FLOAT32_C(-5805.66), SIMDE_FLOAT32_C(-1052.10)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(    8.30), SIMDE_FLOAT32_C(   22.80),
                         SIMDE_FLOAT32_C(  -55.20), SIMDE_FLOAT32_C(  -62.40),
                         SIMDE_FLOAT32_C(  -29.10), SIMDE_FLOAT32_C(   56.20),
                         SIMDE_FLOAT32_C(   96.20), SIMDE_FLOAT32_C(   45.90)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    9.40), SIMDE_FLOAT32_C(  -58.60),
                         SIMDE_FLOAT32_C(  -71.50), SIMDE_FLOAT32_C(   52.70),
                         SIMDE_FLOAT32_C(  -96.40), SIMDE_FLOAT32_C(   75.70),
                         SIMDE_FLOAT32_C(   -3.70), SIMDE_FLOAT32_C(   35.60)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -87.20), SIMDE_FLOAT32_C(  -73.80),
                         SIMDE_FLOAT32_C(  -51.80), SIMDE_FLOAT32_C(   49.30),
                         SIMDE_FLOAT32_C(    9.90), SIMDE_FLOAT32_C(   32.40),
                         SIMDE_FLOAT32_C(  -44.20), SIMDE_FLOAT32_C(   88.50)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  165.22), SIMDE_FLOAT32_C(-1262.28),
                         SIMDE_FLOAT32_C( 3998.60), SIMDE_FLOAT32_C(-3337.78),
                         SIMDE_FLOAT32_C( 2795.34), SIMDE_FLOAT32_C( 4221.94),
                         SIMDE_FLOAT32_C( -311.74), SIMDE_FLOAT32_C( 1545.54)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -71.10), SIMDE_FLOAT32_C(  -36.70),
                         SIMDE_FLOAT32_C(    2.00), SIMDE_FLOAT32_C(  -19.80),
                         SIMDE_FLOAT32_C(  -33.20), SIMDE_FLOAT32_C(   94.30),
                         SIMDE_FLOAT32_C(    1.20), SIMDE_FLOAT32_C(   43.50)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   91.40), SIMDE_FLOAT32_C(   40.00),
                         SIMDE_FLOAT32_C(   26.00), SIMDE_FLOAT32_C(   80.90),
                         SIMDE_FLOAT32_C(  -92.20), SIMDE_FLOAT32_C(  -86.10),
                         SIMDE_FLOAT32_C(   71.10), SIMDE_FLOAT32_C(   10.10)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   29.80), SIMDE_FLOAT32_C(  -33.80),
                         SIMDE_FLOAT32_C(  -52.50), SIMDE_FLOAT32_C(   52.00),
                         SIMDE_FLOAT32_C(  -20.10), SIMDE_FLOAT32_C(  -49.80),
                         SIMDE_FLOAT32_C(   36.10), SIMDE_FLOAT32_C(   37.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-6528.34), SIMDE_FLOAT32_C(-1434.20),
                         SIMDE_FLOAT32_C(  104.50), SIMDE_FLOAT32_C(-1653.82),
                         SIMDE_FLOAT32_C( 3081.14), SIMDE_FLOAT32_C(-8069.43),
                         SIMDE_FLOAT32_C(   49.22), SIMDE_FLOAT32_C(  402.35)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_fmsub_ps(test_vec[i].a, test_vec[i].b, test_vec[i].c);
    simde_assert_m256_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_fmsub_sd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d c;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   43.20), SIMDE_FLOAT64_C(  -60.20)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -12.80), SIMDE_FLOAT64_C(   56.50)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -27.10), SIMDE_FLOAT64_C(   60.10)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   43.20), SIMDE_FLOAT64_C(-3461.40)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -79.30), SIMDE_FLOAT64_C(   88.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   44.30), SIMDE_FLOAT64_C(   37.40)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   77.70), SIMDE_FLOAT64_C(   22.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -79.30), SIMDE_FLOAT64_C( 3302.86)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   -1.70), SIMDE_FLOAT64_C(  -49.80)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   87.10), SIMDE_FLOAT64_C(  -41.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -71.70), SIMDE_FLOAT64_C(   16.20)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -1.70), SIMDE_FLOAT64_C( 2025.60)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -81.20), SIMDE_FLOAT64_C(   22.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -90.90), SIMDE_FLOAT64_C(   95.10)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -81.00), SIMDE_FLOAT64_C(  -21.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -81.20), SIMDE_FLOAT64_C( 2113.20)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   86.00), SIMDE_FLOAT64_C(   69.40)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -68.40), SIMDE_FLOAT64_C(  -83.70)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   95.80), SIMDE_FLOAT64_C(   94.30)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   86.00), SIMDE_FLOAT64_C(-5903.08)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -19.30), SIMDE_FLOAT64_C(  -49.30)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -62.80), SIMDE_FLOAT64_C(   42.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   30.00), SIMDE_FLOAT64_C(  -69.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -19.30), SIMDE_FLOAT64_C(-2001.60)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   23.40), SIMDE_FLOAT64_C(  -19.50)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   85.50), SIMDE_FLOAT64_C(   56.90)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   27.00), SIMDE_FLOAT64_C(  -47.20)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   23.40), SIMDE_FLOAT64_C(-1062.35)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -59.40), SIMDE_FLOAT64_C(   23.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -67.50), SIMDE_FLOAT64_C(   79.20)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   98.40), SIMDE_FLOAT64_C(  -48.80)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -59.40), SIMDE_FLOAT64_C( 1870.40)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_fmsub_sd(test_vec[i].a, test_vec[i].b, test_vec[i].c);
    simde_assert_m128d_f64_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_fmsub_ss(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m128 c;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   81.20), SIMDE_FLOAT32_C(   26.30), SIMDE_FLOAT32_C(   21.90), SIMDE_FLOAT32_C(   41.80)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   37.70), SIMDE_FLOAT32_C(   61.40), SIMDE_FLOAT32_C(   87.60), SIMDE_FLOAT32_C(  -37.20)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   85.80), SIMDE_FLOAT32_C(  -48.50), SIMDE_FLOAT32_C(   52.10), SIMDE_FLOAT32_C(   67.70)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   81.20), SIMDE_FLOAT32_C(   26.30), SIMDE_FLOAT32_C(   21.90), SIMDE_FLOAT32_C(-1622.66)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -23.60), SIMDE_FLOAT32_C(  -82.80), SIMDE_FLOAT32_C(   55.80), SIMDE_FLOAT32_C(  -90.30)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   53.10), SIMDE_FLOAT32_C(  -75.20), SIMDE_FLOAT32_C(  -26.00), SIMDE_FLOAT32_C(   93.80)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   47.50), SIMDE_FLOAT32_C(   39.90), SIMDE_FLOAT32_C(  -49.20), SIMDE_FLOAT32_C(  -86.90)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -23.60), SIMDE_FLOAT32_C(  -82.80), SIMDE_FLOAT32_C(   55.80), SIMDE_FLOAT32_C(-8383.24)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(    0.90), SIMDE_FLOAT32_C(  -99.10), SIMDE_FLOAT32_C(   26.00), SIMDE_FLOAT32_C(   32.50)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   29.60), SIMDE_FLOAT32_C(  -93.20), SIMDE_FLOAT32_C(  -96.10), SIMDE_FLOAT32_C(   87.50)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   76.20), SIMDE_FLOAT32_C(  -98.50), SIMDE_FLOAT32_C(    4.10), SIMDE_FLOAT32_C(  -66.50)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    0.90), SIMDE_FLOAT32_C(  -99.10), SIMDE_FLOAT32_C(   26.00), SIMDE_FLOAT32_C( 2910.25)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -58.80), SIMDE_FLOAT32_C(    0.70), SIMDE_FLOAT32_C(  -50.10), SIMDE_FLOAT32_C(  -58.60)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   53.70), SIMDE_FLOAT32_C(  -83.00), SIMDE_FLOAT32_C(  -66.70), SIMDE_FLOAT32_C(   96.60)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -97.40), SIMDE_FLOAT32_C(   97.80), SIMDE_FLOAT32_C(   93.40), SIMDE_FLOAT32_C(  -82.50)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -58.80), SIMDE_FLOAT32_C(    0.70), SIMDE_FLOAT32_C(  -50.10), SIMDE_FLOAT32_C(-5578.26)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   26.20), SIMDE_FLOAT32_C(    0.50), SIMDE_FLOAT32_C(   53.40), SIMDE_FLOAT32_C(   40.40)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -60.30), SIMDE_FLOAT32_C(  -94.00), SIMDE_FLOAT32_C(   14.10), SIMDE_FLOAT32_C(  -94.50)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   75.80), SIMDE_FLOAT32_C(   16.70), SIMDE_FLOAT32_C(   -3.80), SIMDE_FLOAT32_C(  -98.50)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   26.20), SIMDE_FLOAT32_C(    0.50), SIMDE_FLOAT32_C(   53.40), SIMDE_FLOAT32_C(-3719.30)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(    6.90), SIMDE_FLOAT32_C(   37.30), SIMDE_FLOAT32_C(   95.60), SIMDE_FLOAT32_C(   26.20)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    6.20), SIMDE_FLOAT32_C(   51.70), SIMDE_FLOAT32_C(  -27.80), SIMDE_FLOAT32_C(   35.60)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   96.60), SIMDE_FLOAT32_C(   16.30), SIMDE_FLOAT32_C(  -87.40), SIMDE_FLOAT32_C(   51.00)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    6.90), SIMDE_FLOAT32_C(   37.30), SIMDE_FLOAT32_C(   95.60), SIMDE_FLOAT32_C(  881.72)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -41.80), SIMDE_FLOAT32_C(  -50.90), SIMDE_FLOAT32_C(   94.30), SIMDE_FLOAT32_C(   92.50)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -51.70), SIMDE_FLOAT32_C(   66.70), SIMDE_FLOAT32_C(   35.70), SIMDE_FLOAT32_C(   84.90)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -89.60), SIMDE_FLOAT32_C(  -35.50), SIMDE_FLOAT32_C(  -45.20), SIMDE_FLOAT32_C(  -87.60)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -41.80), SIMDE_FLOAT32_C(  -50.90), SIMDE_FLOAT32_C(   94.30), SIMDE_FLOAT32_C( 7940.85)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   60.00), SIMDE_FLOAT32_C(   45.70), SIMDE_FLOAT32_C(   16.60), SIMDE_FLOAT32_C(   40.70)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -13.60), SIMDE_FLOAT32_C(  -11.50), SIMDE_FLOAT32_C(  -61.10), SIMDE_FLOAT32_C(  -64.20)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   96.70), SIMDE_FLOAT32_C(  -80.10), SIMDE_FLOAT32_C(   37.00), SIMDE_FLOAT32_C(   74.70)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   60.00), SIMDE_FLOAT32_C(   45.70), SIMDE_FLOAT32_C(   16.60), SIMDE_FLOAT32_C(-2687.64)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_fmsub_ss(test_vec[i].a, test_vec[i].b, test_vec[i].c);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitTest test_suite_tests[] = {
  TEST_FUNC(mm_fmadd_pd),
  TEST_FUNC(mm256_fmadd_pd),
  TEST_FUNC(mm_fmadd_ps),
  TEST_FUNC(mm256_fmadd_ps),
  TEST_FUNC(mm_fmadd_sd),
  TEST_FUNC(mm_fmadd_ss),

  TEST_FUNC(mm_fmaddsub_pd),
  TEST_FUNC(mm256_fmaddsub_pd),
  TEST_FUNC(mm_fmaddsub_ps),
  TEST_FUNC(mm256_fmaddsub_ps),

  TEST_FUNC(mm_fmsub_pd),
  TEST_FUNC(mm256_fmsub_pd),
  TEST_FUNC(mm_fmsub_ps),
  TEST_FUNC(mm256_fmsub_ps),
  TEST_FUNC(mm_fmsub_sd),
  TEST_FUNC(mm_fmsub_ss),

  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

#if defined(SIMDE_NO_NATIVE)
#  define simde_fma_test_suite simde_fma_emul_test_suite
#endif

MunitSuite simde_fma_test_suite = {
  (char*) "/fma",
  test_suite_tests,
  NULL,
  1,
  MUNIT_SUITE_OPTION_NONE
};