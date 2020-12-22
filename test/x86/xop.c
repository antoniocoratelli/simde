/* Copyright (c) 2020 Evan Nemerson <evan@nemerson.com>
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

#define SIMDE_TESTS_CURRENT_ISAX xop
#include <simde/x86/xop.h>
#include <test/x86/test-sse2.h>

static int
test_simde_mm_cmov_si128 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const int32_t c[4];
    const int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(  1002835682), -INT32_C(   885627840),  INT32_C(  1720944886),  INT32_C(  1241126463) },
      {  INT32_C(   183163363),  INT32_C(  1912827998), -INT32_C(  1815182000), -INT32_C(    10275359) },
      {  INT32_C(  1724161062), -INT32_C(   147719679), -INT32_C(  1033976445), -INT32_C(  1106552613) },
      {  INT32_C(  1277874631), -INT32_C(  1020108706),  INT32_C(  1402110162),  INT32_C(  1231697211) } },
    { { -INT32_C(  1882589903), -INT32_C(  1258173339),  INT32_C(   843698001),  INT32_C(   707963908) },
      {  INT32_C(  1251014217),  INT32_C(  1933689584),  INT32_C(  1647681415),  INT32_C(   690045431) },
      { -INT32_C(  1665603018),  INT32_C(   122796726), -INT32_C(  1908761975), -INT32_C(  1866961849) },
      { -INT32_C(   829885319),  INT32_C(  1963051108),  INT32_C(  1645055751),  INT32_C(   691088820) } },
    { {  INT32_C(  1390037346), -INT32_C(  1832510709), -INT32_C(  1292567621),  INT32_C(  1943737660) },
      { -INT32_C(  1257270017), -INT32_C(   675454898),  INT32_C(  1113978875), -INT32_C(   976085405) },
      {  INT32_C(  1914154087), -INT32_C(  2113610297),  INT32_C(   355858649),  INT32_C(   227020814) },
      { -INT32_C(   686155526), -INT32_C(   675464949),  INT32_C(  1383399355), -INT32_C(  1042669971) } },
    { { -INT32_C(   222062684), -INT32_C(   204832520), -INT32_C(   634048649), -INT32_C(  1264646323) },
      {  INT32_C(  2049357491),  INT32_C(  1845308052),  INT32_C(   830616099), -INT32_C(   415364286) },
      { -INT32_C(  1697054302), -INT32_C(   124935295),  INT32_C(   550683347),  INT32_C(  2094363081) },
      { -INT32_C(   219695183), -INT32_C(   168261484),  INT32_C(   286274163), -INT32_C(  1212216501) } },
    { { -INT32_C(  1124599000),  INT32_C(  1227486246),  INT32_C(  1752869670),  INT32_C(  1498396854) },
      {  INT32_C(  1005791674), -INT32_C(  1623948852),  INT32_C(   230688323), -INT32_C(  1601596040) },
      { -INT32_C(  1235451760), -INT32_C(  1694530188), -INT32_C(   419202768), -INT32_C(   331328974) },
      { -INT32_C(  1107842774),  INT32_C(   220824748),  INT32_C(  1757556579),  INT32_C(  1221170554) } },
    { {  INT32_C(  1210528635), -INT32_C(   119055436), -INT32_C(   637163678), -INT32_C(   847606212) },
      { -INT32_C(  2088511985), -INT32_C(  1960934565),  INT32_C(   779231740), -INT32_C(   283463053) },
      { -INT32_C(  1707654426), -INT32_C(     7201123),  INT32_C(    47814598),  INT32_C(   902779686) },
      {  INT32_C(   161977963), -INT32_C(   124871722),  INT32_C(   774088570), -INT32_C(   816143755) } },
    { { -INT32_C(  2068294871), -INT32_C(   770648362),  INT32_C(  1795261175),  INT32_C(   458890037) },
      { -INT32_C(    71986851),  INT32_C(  1979336879),  INT32_C(    91804895),  INT32_C(  1362773799) },
      {  INT32_C(  1893069722), -INT32_C(  1052514871), -INT32_C(  1658043288), -INT32_C(  1111980449) },
      { -INT32_C(  1951378611), -INT32_C(   189215514),  INT32_C(   156274935),  INT32_C(  1494893365) } },
    { { -INT32_C(   960991977), -INT32_C(  1791184203), -INT32_C(  1365592954), -INT32_C(  1761618437) },
      { -INT32_C(  1861823288),  INT32_C(   575818170), -INT32_C(   306217331),  INT32_C(   464156420) },
      { -INT32_C(  1696439580), -INT32_C(  1691410924), -INT32_C(   850802222),  INT32_C(  1717782686) },
      { -INT32_C(  2086341620), -INT32_C(  1317252162), -INT32_C(  1396787569),  INT32_C(   535525274) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi32(test_vec[i].b);
    simde__m128i c = simde_x_mm_loadu_epi32(test_vec[i].c);
    simde__m128i r = simde_mm_cmov_si128(a, b, c);
    simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i c = simde_test_x86_random_i32x4();
    simde__m128i r = simde_mm_cmov_si128(a, b, c);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_cmov_si128)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/test-x86-footer.h>
