/* SPDX-License-Identifier: MIT
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
 *
 * Copyright:
 *   2020      Evan Nemerson <evan@nemerson.com>
 */

#if !defined(SIMDE_X86_XOP_H)
#define SIMDE_X86_XOP_H

#include "sse4.2.h"

#if !defined(SIMDE_X86_XOP_NATIVE) && defined(SIMDE_ENABLE_NATIVE_ALIASES)
#  define SIMDE_X86_XOP_ENABLE_NATIVE_ALIASES
#endif

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_cmov_si128 (simde__m128i a, simde__m128i b, simde__m128i c) {
  #if defined(SIMDE_X86_XOP_NATIVE)
    return _mm_cmov_si128(a, b, c);
  #elif defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_ternarylogic_epi32(a, b, c, 0xca);
  #elif defined(SIMDE_X86_SSE2_NATIVE)
    return _mm_or_si128(_mm_and_si128(c, a), _mm_andnot_si128(c, b));
  #else
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b),
      c_ = simde__m128i_to_private(c);

    #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
      r_.neon_i8 = vbslq_s8(c_.neon_u8, a_.neon_i8, b_.neon_i8);
    #elif defined(SIMDE_WASM_SIMD128_NATIVE)
      r_.wasm_v128 = wasm_v128_bitselect(a_.wasm_v128, b_.wasm_v128, c_.wasm_v128);
    #elif defined(SIMDE_POWER_ALTIVEC_P7_NATIVE)
      r_.altivec_i32 = vec_sel(b_.altivec_i32, a_.altivec_i32, c_.altivec_u32);
    #elif defined(SIMDE_VECTOR_SUBSCRIPT_OPS)
      r_.i32f = (c_.i32f & a_.i32f) | (~c_.i32f & b_.i32f);
    #else
      SIMDE_VECTORIZE
      for (size_t i = 0 ; i < (sizeof(r_.i32f) / sizeof(r_.i32f[0])) ; i++) {
        r_.i32f[i] = (c_.i32f[i] & a_.i32f[i]) | (~c_.i32f[i] & b_.i32f[i]);
      }
    #endif

    return simde__m128i_from_private(r_);
  #endif
}
#if defined(SIMDE_X86_XOP_ENABLE_NATIVE_ALIASES)
  #define _mm_cmov_si128(a, b, c) simde_mm_cmov_si128(a, b, c)
#endif

SIMDE_END_DECLS_

HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_XOP_H) */
