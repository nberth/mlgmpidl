/* File generated from mpz.idl */

#include <stddef.h>
#include <string.h>
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/fail.h>
#include <caml/callback.h>
#ifdef Custom_tag
#include <caml/custom.h>
#include <caml/bigarray.h>
#endif
#include <caml/camlidlruntime.h>


#include "limits.h"
#include "caml/custom.h"
#include "gmp_caml.h"

#define camlidl_ml2c_mpz_mpz_ptr(v,c,ctx) camlidl_mpz_ptr_ml2c(v,c)

#define camlidl_c2ml_mpz_mpz_ptr(c,ctx) camlidl_mpz_ptr_c2ml(c)

value camlidl_mpz_mpz_init(value _unit)
{
  mpz_t OUTOUTOUT; mpz_ptr OUTTOUTTOUTT = OUTOUTOUT;; /*out*/
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  mpz_init(OUTOUTOUT);
  _vres = camlidl_c2ml_mpz_mpz_ptr(&OUTTOUTTOUTT, _ctx);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_init2(
	value _v_N)
{
  mpz_t OUTOUTOUT; mpz_ptr OUTTOUTTOUTT = OUTOUTOUT;; /*out*/
  unsigned long N; /*in*/
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  N = Long_val(_v_N);
  mpz_init2(OUTOUTOUT, N);
  _vres = camlidl_c2ml_mpz_mpz_ptr(&OUTTOUTTOUTT, _ctx);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_realloc2(
	value _v_ROP,
	value _v_N)
{
  mpz_ptr ROP; /*in*/
  unsigned long N; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_ROP, &ROP, _ctx);
  N = Long_val(_v_N);
  mpz_realloc2(ROP, N);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_set(
	value _v_ROP,
	value _v_OP)
{
  mpz_ptr ROP; /*in*/
  mpz_ptr OP; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_ROP, &ROP, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_OP, &OP, _ctx);
  mpz_set(ROP, OP);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_set_si(
	value _v_ROP,
	value _v_OP)
{
  mpz_ptr ROP; /*in*/
  long OP; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_ROP, &ROP, _ctx);
  OP = Long_val(_v_OP);
  mpz_set_si(ROP, OP);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_set_d(
	value _v_ROP,
	value _v_OP)
{
  mpz_ptr ROP; /*in*/
  double OP; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_ROP, &ROP, _ctx);
  OP = Double_val(_v_OP);
  mpz_set_d(ROP, OP);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_set_str(
	value _v_ROP,
	value _v_STR,
	value _v_BASE)
{
  mpz_ptr ROP; /*in*/
  char *STR; /*in*/
  int BASE; /*in*/
  int _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_ROP, &ROP, _ctx);
  STR = String_val(_v_STR);
  BASE = Int_val(_v_BASE);
  _res = mpz_set_str(ROP, STR, BASE);
  _vres = Val_int(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_swap(
	value _v_ROP1,
	value _v_ROP2)
{
  mpz_ptr ROP1; /*in*/
  mpz_ptr ROP2; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_ROP1, &ROP1, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_ROP2, &ROP2, _ctx);
  mpz_swap(ROP1, ROP2);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_init_set(
	value _v_OP)
{
  mpz_t OUTOUTOUT; mpz_ptr OUTTOUTTOUTT = OUTOUTOUT;; /*out*/
  mpz_ptr OP; /*in*/
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_OP, &OP, _ctx);
  mpz_init_set(OUTOUTOUT, OP);
  _vres = camlidl_c2ml_mpz_mpz_ptr(&OUTTOUTTOUTT, _ctx);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_init_set_si(
	value _v_OP)
{
  mpz_t OUTOUTOUT; mpz_ptr OUTTOUTTOUTT = OUTOUTOUT;; /*out*/
  long OP; /*in*/
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  OP = Long_val(_v_OP);
  mpz_init_set_si(OUTOUTOUT, OP);
  _vres = camlidl_c2ml_mpz_mpz_ptr(&OUTTOUTTOUTT, _ctx);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_init_set_d(
	value _v_OP)
{
  mpz_t OUTOUTOUT; mpz_ptr OUTTOUTTOUTT = OUTOUTOUT;; /*out*/
  double OP; /*in*/
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  OP = Double_val(_v_OP);
  mpz_init_set_d(OUTOUTOUT, OP);
  _vres = camlidl_c2ml_mpz_mpz_ptr(&OUTTOUTTOUTT, _ctx);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_init_set_str(
	value _v_STR,
	value _v_BASE)
{
  mpz_t OUTOUTOUT; mpz_ptr OUTTOUTTOUTT = OUTOUTOUT;; /*out*/
  char *STR; /*in*/
  int BASE; /*in*/
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  STR = String_val(_v_STR);
  BASE = Int_val(_v_BASE);
  /* begin user-supplied calling sequence */
  {
  int n = mpz_init_set_str(OUTOUTOUT,STR,BASE);
  if (n){ mpz_clear(OUTOUTOUT); caml_invalid_argument(""); }
  }
  /* end user-supplied calling sequence */
  _vres = camlidl_c2ml_mpz_mpz_ptr(&OUTTOUTTOUTT, _ctx);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_get_si(
	value _v_OP)
{
  mpz_ptr OP; /*in*/
  long _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_OP, &OP, _ctx);
  _res = mpz_get_si(OP);
  _vres = copy_nativeint(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_get_d(
	value _v_OP)
{
  mpz_ptr OP; /*in*/
  double _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_OP, &OP, _ctx);
  _res = mpz_get_d(OP);
  _vres = copy_double(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_get_d_2exp(
	value _v_OP)
{
  long *EXP; /*out*/
  mpz_ptr OP; /*in*/
  double _res;
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  long _c1;
  value _vresult;
  value _vres[2] = { 0, 0, };

  camlidl_ml2c_mpz_mpz_ptr(_v_OP, &OP, _ctx);
  EXP = &_c1;
  _res = mpz_get_d_2exp(EXP, OP);
  Begin_roots_block(_vres, 2)
    _vres[0] = copy_double(_res);
    _vres[1] = Val_long(*EXP);
    _vresult = camlidl_alloc_small(2, 0);
    Field(_vresult, 0) = _vres[0];
    Field(_vresult, 1) = _vres[1];
  End_roots()
  camlidl_free(_ctx);
  return _vresult;
}

value camlidl_mpz_mpz_get_str(
	value _v_BASE,
	value _v_OP)
{
  int BASE; /*in*/
  mpz_ptr OP; /*in*/
  char *_res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  BASE = Int_val(_v_BASE);
  camlidl_ml2c_mpz_mpz_ptr(_v_OP, &OP, _ctx);
  /* begin user-supplied calling sequence */
_res = mpz_get_str(NULL,BASE,OP);
  /* end user-supplied calling sequence */
  _vres = copy_string(_res);
  camlidl_free(_ctx);
  /* begin user-supplied deallocation sequence */
free(_res);
  /* end user-supplied deallocation sequence */
  return _vres;
}

value camlidl_mpz_mpz_add(
	value _v_ROP,
	value _v_OP1,
	value _v_OP2)
{
  mpz_ptr ROP; /*in*/
  mpz_ptr OP1; /*in*/
  mpz_ptr OP2; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_ROP, &ROP, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_OP1, &OP1, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_OP2, &OP2, _ctx);
  mpz_add(ROP, OP1, OP2);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_add_ui(
	value _v_ROP,
	value _v_OP1,
	value _v_OP2)
{
  mpz_ptr ROP; /*in*/
  mpz_ptr OP1; /*in*/
  unsigned long OP2; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_ROP, &ROP, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_OP1, &OP1, _ctx);
  OP2 = Long_val(_v_OP2);
  mpz_add_ui(ROP, OP1, OP2);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_sub(
	value _v_ROP,
	value _v_OP1,
	value _v_OP2)
{
  mpz_ptr ROP; /*in*/
  mpz_ptr OP1; /*in*/
  mpz_ptr OP2; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_ROP, &ROP, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_OP1, &OP1, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_OP2, &OP2, _ctx);
  mpz_sub(ROP, OP1, OP2);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_sub_ui(
	value _v_ROP,
	value _v_OP1,
	value _v_OP2)
{
  mpz_ptr ROP; /*in*/
  mpz_ptr OP1; /*in*/
  unsigned long OP2; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_ROP, &ROP, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_OP1, &OP1, _ctx);
  OP2 = Long_val(_v_OP2);
  mpz_sub_ui(ROP, OP1, OP2);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_ui_sub(
	value _v_ROP,
	value _v_OP1,
	value _v_OP2)
{
  mpz_ptr ROP; /*in*/
  unsigned long OP1; /*in*/
  mpz_ptr OP2; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_ROP, &ROP, _ctx);
  OP1 = Long_val(_v_OP1);
  camlidl_ml2c_mpz_mpz_ptr(_v_OP2, &OP2, _ctx);
  mpz_ui_sub(ROP, OP1, OP2);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_mul(
	value _v_ROP,
	value _v_OP1,
	value _v_OP2)
{
  mpz_ptr ROP; /*in*/
  mpz_ptr OP1; /*in*/
  mpz_ptr OP2; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_ROP, &ROP, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_OP1, &OP1, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_OP2, &OP2, _ctx);
  mpz_mul(ROP, OP1, OP2);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_mul_si(
	value _v_ROP,
	value _v_OP1,
	value _v_OP2)
{
  mpz_ptr ROP; /*in*/
  mpz_ptr OP1; /*in*/
  long OP2; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_ROP, &ROP, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_OP1, &OP1, _ctx);
  OP2 = Long_val(_v_OP2);
  mpz_mul_si(ROP, OP1, OP2);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_addmul(
	value _v_ROP,
	value _v_OP1,
	value _v_OP2)
{
  mpz_ptr ROP; /*in*/
  mpz_ptr OP1; /*in*/
  mpz_ptr OP2; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_ROP, &ROP, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_OP1, &OP1, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_OP2, &OP2, _ctx);
  mpz_addmul(ROP, OP1, OP2);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_addmul_ui(
	value _v_ROP,
	value _v_OP1,
	value _v_OP2)
{
  mpz_ptr ROP; /*in*/
  mpz_ptr OP1; /*in*/
  unsigned long OP2; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_ROP, &ROP, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_OP1, &OP1, _ctx);
  OP2 = Long_val(_v_OP2);
  mpz_addmul_ui(ROP, OP1, OP2);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_submul(
	value _v_ROP,
	value _v_OP1,
	value _v_OP2)
{
  mpz_ptr ROP; /*in*/
  mpz_ptr OP1; /*in*/
  mpz_ptr OP2; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_ROP, &ROP, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_OP1, &OP1, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_OP2, &OP2, _ctx);
  mpz_submul(ROP, OP1, OP2);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_submul_ui(
	value _v_ROP,
	value _v_OP1,
	value _v_OP2)
{
  mpz_ptr ROP; /*in*/
  mpz_ptr OP1; /*in*/
  unsigned long OP2; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_ROP, &ROP, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_OP1, &OP1, _ctx);
  OP2 = Long_val(_v_OP2);
  mpz_submul_ui(ROP, OP1, OP2);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_mul_2exp(
	value _v_ROP,
	value _v_OP1,
	value _v_OP2)
{
  mpz_ptr ROP; /*in*/
  mpz_ptr OP1; /*in*/
  unsigned long OP2; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_ROP, &ROP, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_OP1, &OP1, _ctx);
  OP2 = Long_val(_v_OP2);
  mpz_mul_2exp(ROP, OP1, OP2);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_neg(
	value _v_ROP,
	value _v_OP)
{
  mpz_ptr ROP; /*in*/
  mpz_ptr OP; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_ROP, &ROP, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_OP, &OP, _ctx);
  mpz_neg(ROP, OP);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_abs(
	value _v_ROP,
	value _v_OP)
{
  mpz_ptr ROP; /*in*/
  mpz_ptr OP; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_ROP, &ROP, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_OP, &OP, _ctx);
  mpz_abs(ROP, OP);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_cdiv_q(
	value _v_Q,
	value _v_N,
	value _v_D)
{
  mpz_ptr Q; /*in*/
  mpz_ptr N; /*in*/
  mpz_ptr D; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_Q, &Q, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_N, &N, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_D, &D, _ctx);
  mpz_cdiv_q(Q, N, D);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_cdiv_r(
	value _v_R,
	value _v_N,
	value _v_D)
{
  mpz_ptr R; /*in*/
  mpz_ptr N; /*in*/
  mpz_ptr D; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_R, &R, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_N, &N, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_D, &D, _ctx);
  mpz_cdiv_r(R, N, D);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_cdiv_qr(
	value _v_Q,
	value _v_R,
	value _v_N,
	value _v_D)
{
  mpz_ptr Q; /*in*/
  mpz_ptr R; /*in*/
  mpz_ptr N; /*in*/
  mpz_ptr D; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_Q, &Q, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_R, &R, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_N, &N, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_D, &D, _ctx);
  mpz_cdiv_qr(Q, R, N, D);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_cdiv_q_ui(
	value _v_Q,
	value _v_N,
	value _v_D)
{
  mpz_ptr Q; /*in*/
  mpz_ptr N; /*in*/
  unsigned long D; /*in*/
  unsigned long _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_Q, &Q, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_N, &N, _ctx);
  D = Long_val(_v_D);
  _res = mpz_cdiv_q_ui(Q, N, D);
  _vres = Val_long(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_cdiv_r_ui(
	value _v_R,
	value _v_N,
	value _v_D)
{
  mpz_ptr R; /*in*/
  mpz_ptr N; /*in*/
  unsigned long D; /*in*/
  unsigned long _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_R, &R, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_N, &N, _ctx);
  D = Long_val(_v_D);
  _res = mpz_cdiv_r_ui(R, N, D);
  _vres = Val_long(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_cdiv_qr_ui(
	value _v_Q,
	value _v_R,
	value _v_N,
	value _v_D)
{
  mpz_ptr Q; /*in*/
  mpz_ptr R; /*in*/
  mpz_ptr N; /*in*/
  unsigned long D; /*in*/
  unsigned long _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_Q, &Q, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_R, &R, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_N, &N, _ctx);
  D = Long_val(_v_D);
  _res = mpz_cdiv_qr_ui(Q, R, N, D);
  _vres = Val_long(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_cdiv_ui(
	value _v_N,
	value _v_D)
{
  mpz_ptr N; /*in*/
  unsigned long D; /*in*/
  unsigned long _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_N, &N, _ctx);
  D = Long_val(_v_D);
  _res = mpz_cdiv_ui(N, D);
  _vres = Val_long(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_cdiv_q_2exp(
	value _v_Q,
	value _v_N,
	value _v_B)
{
  mpz_ptr Q; /*in*/
  mpz_ptr N; /*in*/
  unsigned long B; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_Q, &Q, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_N, &N, _ctx);
  B = Long_val(_v_B);
  mpz_cdiv_q_2exp(Q, N, B);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_cdiv_r_2exp(
	value _v_R,
	value _v_N,
	value _v_B)
{
  mpz_ptr R; /*in*/
  mpz_ptr N; /*in*/
  unsigned long B; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_R, &R, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_N, &N, _ctx);
  B = Long_val(_v_B);
  mpz_cdiv_r_2exp(R, N, B);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_fdiv_q(
	value _v_Q,
	value _v_N,
	value _v_D)
{
  mpz_ptr Q; /*in*/
  mpz_ptr N; /*in*/
  mpz_ptr D; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_Q, &Q, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_N, &N, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_D, &D, _ctx);
  mpz_fdiv_q(Q, N, D);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_fdiv_r(
	value _v_R,
	value _v_N,
	value _v_D)
{
  mpz_ptr R; /*in*/
  mpz_ptr N; /*in*/
  mpz_ptr D; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_R, &R, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_N, &N, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_D, &D, _ctx);
  mpz_fdiv_r(R, N, D);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_fdiv_qr(
	value _v_Q,
	value _v_R,
	value _v_N,
	value _v_D)
{
  mpz_ptr Q; /*in*/
  mpz_ptr R; /*in*/
  mpz_ptr N; /*in*/
  mpz_ptr D; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_Q, &Q, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_R, &R, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_N, &N, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_D, &D, _ctx);
  mpz_fdiv_qr(Q, R, N, D);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_fdiv_q_ui(
	value _v_Q,
	value _v_N,
	value _v_D)
{
  mpz_ptr Q; /*in*/
  mpz_ptr N; /*in*/
  unsigned long D; /*in*/
  unsigned long _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_Q, &Q, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_N, &N, _ctx);
  D = Long_val(_v_D);
  _res = mpz_fdiv_q_ui(Q, N, D);
  _vres = Val_long(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_fdiv_r_ui(
	value _v_R,
	value _v_N,
	value _v_D)
{
  mpz_ptr R; /*in*/
  mpz_ptr N; /*in*/
  unsigned long D; /*in*/
  unsigned long _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_R, &R, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_N, &N, _ctx);
  D = Long_val(_v_D);
  _res = mpz_fdiv_r_ui(R, N, D);
  _vres = Val_long(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_fdiv_qr_ui(
	value _v_Q,
	value _v_R,
	value _v_N,
	value _v_D)
{
  mpz_ptr Q; /*in*/
  mpz_ptr R; /*in*/
  mpz_ptr N; /*in*/
  unsigned long D; /*in*/
  unsigned long _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_Q, &Q, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_R, &R, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_N, &N, _ctx);
  D = Long_val(_v_D);
  _res = mpz_fdiv_qr_ui(Q, R, N, D);
  _vres = Val_long(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_fdiv_ui(
	value _v_N,
	value _v_D)
{
  mpz_ptr N; /*in*/
  unsigned long D; /*in*/
  unsigned long _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_N, &N, _ctx);
  D = Long_val(_v_D);
  _res = mpz_fdiv_ui(N, D);
  _vres = Val_long(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_fdiv_q_2exp(
	value _v_Q,
	value _v_N,
	value _v_B)
{
  mpz_ptr Q; /*in*/
  mpz_ptr N; /*in*/
  unsigned long B; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_Q, &Q, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_N, &N, _ctx);
  B = Long_val(_v_B);
  mpz_fdiv_q_2exp(Q, N, B);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_fdiv_r_2exp(
	value _v_R,
	value _v_N,
	value _v_B)
{
  mpz_ptr R; /*in*/
  mpz_ptr N; /*in*/
  unsigned long B; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_R, &R, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_N, &N, _ctx);
  B = Long_val(_v_B);
  mpz_fdiv_r_2exp(R, N, B);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_tdiv_q(
	value _v_Q,
	value _v_N,
	value _v_D)
{
  mpz_ptr Q; /*in*/
  mpz_ptr N; /*in*/
  mpz_ptr D; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_Q, &Q, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_N, &N, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_D, &D, _ctx);
  mpz_tdiv_q(Q, N, D);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_tdiv_r(
	value _v_R,
	value _v_N,
	value _v_D)
{
  mpz_ptr R; /*in*/
  mpz_ptr N; /*in*/
  mpz_ptr D; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_R, &R, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_N, &N, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_D, &D, _ctx);
  mpz_tdiv_r(R, N, D);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_tdiv_qr(
	value _v_Q,
	value _v_R,
	value _v_N,
	value _v_D)
{
  mpz_ptr Q; /*in*/
  mpz_ptr R; /*in*/
  mpz_ptr N; /*in*/
  mpz_ptr D; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_Q, &Q, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_R, &R, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_N, &N, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_D, &D, _ctx);
  mpz_tdiv_qr(Q, R, N, D);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_tdiv_q_ui(
	value _v_Q,
	value _v_N,
	value _v_D)
{
  mpz_ptr Q; /*in*/
  mpz_ptr N; /*in*/
  unsigned long D; /*in*/
  unsigned long _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_Q, &Q, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_N, &N, _ctx);
  D = Long_val(_v_D);
  _res = mpz_tdiv_q_ui(Q, N, D);
  _vres = Val_long(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_tdiv_r_ui(
	value _v_R,
	value _v_N,
	value _v_D)
{
  mpz_ptr R; /*in*/
  mpz_ptr N; /*in*/
  unsigned long D; /*in*/
  unsigned long _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_R, &R, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_N, &N, _ctx);
  D = Long_val(_v_D);
  _res = mpz_tdiv_r_ui(R, N, D);
  _vres = Val_long(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_tdiv_qr_ui(
	value _v_Q,
	value _v_R,
	value _v_N,
	value _v_D)
{
  mpz_ptr Q; /*in*/
  mpz_ptr R; /*in*/
  mpz_ptr N; /*in*/
  unsigned long D; /*in*/
  unsigned long _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_Q, &Q, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_R, &R, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_N, &N, _ctx);
  D = Long_val(_v_D);
  _res = mpz_tdiv_qr_ui(Q, R, N, D);
  _vres = Val_long(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_tdiv_ui(
	value _v_N,
	value _v_D)
{
  mpz_ptr N; /*in*/
  unsigned long D; /*in*/
  unsigned long _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_N, &N, _ctx);
  D = Long_val(_v_D);
  _res = mpz_tdiv_ui(N, D);
  _vres = Val_long(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_tdiv_q_2exp(
	value _v_Q,
	value _v_N,
	value _v_B)
{
  mpz_ptr Q; /*in*/
  mpz_ptr N; /*in*/
  unsigned long B; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_Q, &Q, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_N, &N, _ctx);
  B = Long_val(_v_B);
  mpz_tdiv_q_2exp(Q, N, B);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_tdiv_r_2exp(
	value _v_R,
	value _v_N,
	value _v_B)
{
  mpz_ptr R; /*in*/
  mpz_ptr N; /*in*/
  unsigned long B; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_R, &R, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_N, &N, _ctx);
  B = Long_val(_v_B);
  mpz_tdiv_r_2exp(R, N, B);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_gmod(
	value _v_R,
	value _v_N,
	value _v_D)
{
  mpz_ptr R; /*in*/
  mpz_ptr N; /*in*/
  mpz_ptr D; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_R, &R, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_N, &N, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_D, &D, _ctx);
  /* begin user-supplied calling sequence */
mpz_mod(R,N,D);
  /* end user-supplied calling sequence */
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_gmod_ui(
	value _v_R,
	value _v_N,
	value _v_D)
{
  mpz_ptr R; /*in*/
  mpz_ptr N; /*in*/
  unsigned long D; /*in*/
  unsigned long _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_R, &R, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_N, &N, _ctx);
  D = Long_val(_v_D);
  /* begin user-supplied calling sequence */
mpz_mod_ui(R,N,D);
  /* end user-supplied calling sequence */
  _vres = Val_long(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_divexact_ui(
	value _v_Q,
	value _v_N,
	value _v_D)
{
  mpz_ptr Q; /*in*/
  mpz_ptr N; /*in*/
  unsigned long D; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_Q, &Q, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_N, &N, _ctx);
  D = Long_val(_v_D);
  mpz_divexact_ui(Q, N, D);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_divisible_p(
	value _v_N,
	value _v_D)
{
  mpz_ptr N; /*in*/
  mpz_ptr D; /*in*/
  int _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_N, &N, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_D, &D, _ctx);
  _res = mpz_divisible_p(N, D);
  _vres = Val_int(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_divisible_ui_p(
	value _v_N,
	value _v_D)
{
  mpz_ptr N; /*in*/
  unsigned long D; /*in*/
  int _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_N, &N, _ctx);
  D = Long_val(_v_D);
  _res = mpz_divisible_ui_p(N, D);
  _vres = Val_int(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_divisible_2exp_p(
	value _v_N,
	value _v_B)
{
  mpz_ptr N; /*in*/
  unsigned long B; /*in*/
  int _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_N, &N, _ctx);
  B = Long_val(_v_B);
  _res = mpz_divisible_2exp_p(N, B);
  _vres = Val_int(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_congruent_p(
	value _v_N,
	value _v_C,
	value _v_D)
{
  mpz_ptr N; /*in*/
  mpz_ptr C; /*in*/
  mpz_ptr D; /*in*/
  int _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_N, &N, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_C, &C, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_D, &D, _ctx);
  _res = mpz_congruent_p(N, C, D);
  _vres = Val_int(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_congruent_ui_p(
	value _v_N,
	value _v_C,
	value _v_D)
{
  mpz_ptr N; /*in*/
  unsigned long C; /*in*/
  unsigned long D; /*in*/
  int _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_N, &N, _ctx);
  C = Long_val(_v_C);
  D = Long_val(_v_D);
  _res = mpz_congruent_ui_p(N, C, D);
  _vres = Val_int(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_congruent_2exp_p(
	value _v_N,
	value _v_C,
	value _v_B)
{
  mpz_ptr N; /*in*/
  mpz_ptr C; /*in*/
  unsigned long B; /*in*/
  int _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_N, &N, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_C, &C, _ctx);
  B = Long_val(_v_B);
  _res = mpz_congruent_2exp_p(N, C, B);
  _vres = Val_int(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_powm(
	value _v_ROP,
	value _v_BASE,
	value _v_EXP,
	value _v_MOD)
{
  mpz_ptr ROP; /*in*/
  mpz_ptr BASE; /*in*/
  mpz_ptr EXP; /*in*/
  mpz_ptr MOD; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_ROP, &ROP, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_BASE, &BASE, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_EXP, &EXP, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_MOD, &MOD, _ctx);
  mpz_powm(ROP, BASE, EXP, MOD);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_powm_ui(
	value _v_ROP,
	value _v_BASE,
	value _v_EXP,
	value _v_MOD)
{
  mpz_ptr ROP; /*in*/
  mpz_ptr BASE; /*in*/
  unsigned long EXP; /*in*/
  mpz_ptr MOD; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_ROP, &ROP, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_BASE, &BASE, _ctx);
  EXP = Long_val(_v_EXP);
  camlidl_ml2c_mpz_mpz_ptr(_v_MOD, &MOD, _ctx);
  mpz_powm_ui(ROP, BASE, EXP, MOD);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_pow_ui(
	value _v_ROP,
	value _v_BASE,
	value _v_EXP)
{
  mpz_ptr ROP; /*in*/
  mpz_ptr BASE; /*in*/
  unsigned long EXP; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_ROP, &ROP, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_BASE, &BASE, _ctx);
  EXP = Long_val(_v_EXP);
  mpz_pow_ui(ROP, BASE, EXP);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_ui_pow_ui(
	value _v_ROP,
	value _v_BASE,
	value _v_EXP)
{
  mpz_ptr ROP; /*in*/
  unsigned long BASE; /*in*/
  unsigned long EXP; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_ROP, &ROP, _ctx);
  BASE = Long_val(_v_BASE);
  EXP = Long_val(_v_EXP);
  mpz_ui_pow_ui(ROP, BASE, EXP);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_root(
	value _v_ROP,
	value _v_OP,
	value _v_N)
{
  mpz_ptr ROP; /*in*/
  mpz_ptr OP; /*in*/
  unsigned long N; /*in*/
  int _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_ROP, &ROP, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_OP, &OP, _ctx);
  N = Long_val(_v_N);
  _res = mpz_root(ROP, OP, N);
  _vres = Val_int(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_sqrt(
	value _v_ROP,
	value _v_OP)
{
  mpz_ptr ROP; /*in*/
  mpz_ptr OP; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_ROP, &ROP, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_OP, &OP, _ctx);
  mpz_sqrt(ROP, OP);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_sqrtrem(
	value _v_ROP1,
	value _v_ROP2,
	value _v_OP)
{
  mpz_ptr ROP1; /*in*/
  mpz_ptr ROP2; /*in*/
  mpz_ptr OP; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_ROP1, &ROP1, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_ROP2, &ROP2, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_OP, &OP, _ctx);
  mpz_sqrtrem(ROP1, ROP2, OP);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_perfect_power_p(
	value _v_OP)
{
  mpz_ptr OP; /*in*/
  int _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_OP, &OP, _ctx);
  _res = mpz_perfect_power_p(OP);
  _vres = Val_int(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_perfect_square_p(
	value _v_OP)
{
  mpz_ptr OP; /*in*/
  int _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_OP, &OP, _ctx);
  _res = mpz_perfect_square_p(OP);
  _vres = Val_int(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_probab_prime_p(
	value _v_N,
	value _v_REPS)
{
  mpz_ptr N; /*in*/
  int REPS; /*in*/
  int _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_N, &N, _ctx);
  REPS = Int_val(_v_REPS);
  _res = mpz_probab_prime_p(N, REPS);
  _vres = Val_int(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_nextprime(
	value _v_ROP,
	value _v_OP)
{
  mpz_ptr ROP; /*in*/
  mpz_ptr OP; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_ROP, &ROP, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_OP, &OP, _ctx);
  mpz_nextprime(ROP, OP);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_gcd(
	value _v_ROP,
	value _v_OP1,
	value _v_OP2)
{
  mpz_ptr ROP; /*in*/
  mpz_ptr OP1; /*in*/
  mpz_ptr OP2; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_ROP, &ROP, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_OP1, &OP1, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_OP2, &OP2, _ctx);
  mpz_gcd(ROP, OP1, OP2);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_gcd_ui(
	value _v_ROP,
	value _v_OP1,
	value _v_OP2)
{
  mpz_ptr *ROP; /*in*/
  mpz_ptr OP1; /*in*/
  unsigned long OP2; /*in*/
  unsigned long _res;
  value _v1;
  mpz_ptr _c2;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  if (_v_ROP == Val_int(0)) {
    ROP = NULL;
  } else {
    _v1 = Field(_v_ROP, 0);
    ROP = &_c2;
    camlidl_ml2c_mpz_mpz_ptr(_v1, &_c2, _ctx);
  }
  camlidl_ml2c_mpz_mpz_ptr(_v_OP1, &OP1, _ctx);
  OP2 = Long_val(_v_OP2);
  /* begin user-supplied calling sequence */
_res = mpz_gcd_ui(ROP ? *ROP : NULL,OP1,OP2);
  /* end user-supplied calling sequence */
  _vres = Val_long(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_gcdext(
	value _v_G,
	value _v_S,
	value _v_T,
	value _v_A,
	value _v_B)
{
  mpz_ptr G; /*in*/
  mpz_ptr S; /*in*/
  mpz_ptr T; /*in*/
  mpz_ptr A; /*in*/
  mpz_ptr B; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_G, &G, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_S, &S, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_T, &T, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_A, &A, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_B, &B, _ctx);
  mpz_gcdext(G, S, T, A, B);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_lcm(
	value _v_ROP,
	value _v_OP1,
	value _v_OP2)
{
  mpz_ptr ROP; /*in*/
  mpz_ptr OP1; /*in*/
  mpz_ptr OP2; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_ROP, &ROP, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_OP1, &OP1, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_OP2, &OP2, _ctx);
  mpz_lcm(ROP, OP1, OP2);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_lcm_ui(
	value _v_ROP,
	value _v_OP1,
	value _v_OP2)
{
  mpz_ptr ROP; /*in*/
  mpz_ptr OP1; /*in*/
  unsigned long OP2; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_ROP, &ROP, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_OP1, &OP1, _ctx);
  OP2 = Long_val(_v_OP2);
  mpz_lcm_ui(ROP, OP1, OP2);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_invert(
	value _v_ROP,
	value _v_OP1,
	value _v_OP2)
{
  mpz_ptr ROP; /*in*/
  mpz_ptr OP1; /*in*/
  mpz_ptr OP2; /*in*/
  int _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_ROP, &ROP, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_OP1, &OP1, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_OP2, &OP2, _ctx);
  _res = mpz_invert(ROP, OP1, OP2);
  _vres = Val_int(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_jacobi(
	value _v_A,
	value _v_B)
{
  mpz_ptr A; /*in*/
  mpz_ptr B; /*in*/
  int _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_A, &A, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_B, &B, _ctx);
  _res = mpz_jacobi(A, B);
  _vres = Val_int(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_legendre(
	value _v_A,
	value _v_P)
{
  mpz_ptr A; /*in*/
  mpz_ptr P; /*in*/
  int _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_A, &A, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_P, &P, _ctx);
  _res = mpz_legendre(A, P);
  _vres = Val_int(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_kronecker(
	value _v_A,
	value _v_B)
{
  mpz_ptr A; /*in*/
  mpz_ptr B; /*in*/
  int _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_A, &A, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_B, &B, _ctx);
  _res = mpz_kronecker(A, B);
  _vres = Val_int(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_kronecker_si(
	value _v_A,
	value _v_B)
{
  mpz_ptr A; /*in*/
  long B; /*in*/
  int _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_A, &A, _ctx);
  B = Long_val(_v_B);
  _res = mpz_kronecker_si(A, B);
  _vres = Val_int(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_si_kronecker(
	value _v_A,
	value _v_B)
{
  long A; /*in*/
  mpz_ptr B; /*in*/
  int _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  A = Long_val(_v_A);
  camlidl_ml2c_mpz_mpz_ptr(_v_B, &B, _ctx);
  _res = mpz_si_kronecker(A, B);
  _vres = Val_int(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_remove(
	value _v_ROP,
	value _v_OP,
	value _v_F)
{
  mpz_ptr ROP; /*in*/
  mpz_ptr OP; /*in*/
  mpz_ptr F; /*in*/
  unsigned long _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_ROP, &ROP, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_OP, &OP, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_F, &F, _ctx);
  _res = mpz_remove(ROP, OP, F);
  _vres = Val_long(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_fac_ui(
	value _v_ROP,
	value _v_OP)
{
  mpz_ptr ROP; /*in*/
  unsigned long OP; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_ROP, &ROP, _ctx);
  OP = Long_val(_v_OP);
  mpz_fac_ui(ROP, OP);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_bin_ui(
	value _v_ROP,
	value _v_N,
	value _v_K)
{
  mpz_ptr ROP; /*in*/
  mpz_ptr N; /*in*/
  unsigned long K; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_ROP, &ROP, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_N, &N, _ctx);
  K = Long_val(_v_K);
  mpz_bin_ui(ROP, N, K);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_bin_uiui(
	value _v_ROP,
	value _v_N,
	value _v_K)
{
  mpz_ptr ROP; /*in*/
  unsigned long N; /*in*/
  unsigned long K; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_ROP, &ROP, _ctx);
  N = Long_val(_v_N);
  K = Long_val(_v_K);
  mpz_bin_uiui(ROP, N, K);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_fib_ui(
	value _v_FN,
	value _v_N)
{
  mpz_ptr FN; /*in*/
  unsigned long N; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_FN, &FN, _ctx);
  N = Long_val(_v_N);
  mpz_fib_ui(FN, N);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_fib2_ui(
	value _v_FN,
	value _v_FNSUB1,
	value _v_N)
{
  mpz_ptr FN; /*in*/
  mpz_ptr FNSUB1; /*in*/
  unsigned long N; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_FN, &FN, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_FNSUB1, &FNSUB1, _ctx);
  N = Long_val(_v_N);
  mpz_fib2_ui(FN, FNSUB1, N);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_lucnum_ui(
	value _v_LN,
	value _v_N)
{
  mpz_ptr LN; /*in*/
  unsigned long N; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_LN, &LN, _ctx);
  N = Long_val(_v_N);
  mpz_lucnum_ui(LN, N);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_lucnum2_ui(
	value _v_LN,
	value _v_LNSUB1,
	value _v_N)
{
  mpz_ptr LN; /*in*/
  mpz_ptr LNSUB1; /*in*/
  unsigned long N; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_LN, &LN, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_LNSUB1, &LNSUB1, _ctx);
  N = Long_val(_v_N);
  mpz_lucnum2_ui(LN, LNSUB1, N);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_cmp(
	value _v_OP1,
	value _v_OP2)
{
  mpz_ptr OP1; /*in*/
  mpz_ptr OP2; /*in*/
  int _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_OP1, &OP1, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_OP2, &OP2, _ctx);
  _res = mpz_cmp(OP1, OP2);
  _vres = Val_int(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_cmp_d(
	value _v_OP1,
	value _v_OP2)
{
  mpz_ptr OP1; /*in*/
  double OP2; /*in*/
  int _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_OP1, &OP1, _ctx);
  OP2 = Double_val(_v_OP2);
  _res = mpz_cmp_d(OP1, OP2);
  _vres = Val_int(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_cmp_si(
	value _v_OP1,
	value _v_OP2)
{
  mpz_ptr OP1; /*in*/
  long OP2; /*in*/
  int _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_OP1, &OP1, _ctx);
  OP2 = Long_val(_v_OP2);
  _res = mpz_cmp_si(OP1, OP2);
  _vres = Val_int(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_cmpabs(
	value _v_OP1,
	value _v_OP2)
{
  mpz_ptr OP1; /*in*/
  mpz_ptr OP2; /*in*/
  int _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_OP1, &OP1, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_OP2, &OP2, _ctx);
  _res = mpz_cmpabs(OP1, OP2);
  _vres = Val_int(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_cmpabs_d(
	value _v_OP1,
	value _v_OP2)
{
  mpz_ptr OP1; /*in*/
  double OP2; /*in*/
  int _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_OP1, &OP1, _ctx);
  OP2 = Double_val(_v_OP2);
  _res = mpz_cmpabs_d(OP1, OP2);
  _vres = Val_int(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_cmpabs_ui(
	value _v_OP1,
	value _v_OP2)
{
  mpz_ptr OP1; /*in*/
  unsigned long OP2; /*in*/
  int _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_OP1, &OP1, _ctx);
  OP2 = Long_val(_v_OP2);
  _res = mpz_cmpabs_ui(OP1, OP2);
  _vres = Val_int(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_sgn(
	value _v_OP)
{
  mpz_ptr OP; /*in*/
  int _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_OP, &OP, _ctx);
  _res = mpz_sgn(OP);
  _vres = Val_int(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_gand(
	value _v_ROP,
	value _v_OP1,
	value _v_OP2)
{
  mpz_ptr ROP; /*in*/
  mpz_ptr OP1; /*in*/
  mpz_ptr OP2; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_ROP, &ROP, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_OP1, &OP1, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_OP2, &OP2, _ctx);
  /* begin user-supplied calling sequence */
mpz_and(ROP,OP1,OP2);
  /* end user-supplied calling sequence */
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_ior(
	value _v_ROP,
	value _v_OP1,
	value _v_OP2)
{
  mpz_ptr ROP; /*in*/
  mpz_ptr OP1; /*in*/
  mpz_ptr OP2; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_ROP, &ROP, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_OP1, &OP1, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_OP2, &OP2, _ctx);
  mpz_ior(ROP, OP1, OP2);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_xor(
	value _v_ROP,
	value _v_OP1,
	value _v_OP2)
{
  mpz_ptr ROP; /*in*/
  mpz_ptr OP1; /*in*/
  mpz_ptr OP2; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_ROP, &ROP, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_OP1, &OP1, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_OP2, &OP2, _ctx);
  mpz_xor(ROP, OP1, OP2);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_com(
	value _v_ROP,
	value _v_OP)
{
  mpz_ptr ROP; /*in*/
  mpz_ptr OP; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_ROP, &ROP, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_OP, &OP, _ctx);
  mpz_com(ROP, OP);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_popcount(
	value _v_OP)
{
  mpz_ptr OP; /*in*/
  unsigned long _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_OP, &OP, _ctx);
  /* begin user-supplied calling sequence */
_res = mpz_popcount(OP); if (_res==ULONG_MAX) _res = Max_long;
  /* end user-supplied calling sequence */
  _vres = Val_long(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_hamdist(
	value _v_OP1,
	value _v_OP2)
{
  mpz_ptr OP1; /*in*/
  mpz_ptr OP2; /*in*/
  unsigned long _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_OP1, &OP1, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_OP2, &OP2, _ctx);
  /* begin user-supplied calling sequence */
_res = mpz_hamdist(OP1,OP2); if (_res==ULONG_MAX) _res = Max_long;
  /* end user-supplied calling sequence */
  _vres = Val_long(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_scan0(
	value _v_OP,
	value _v_STARTING_BIT)
{
  mpz_ptr OP; /*in*/
  unsigned long STARTING_BIT; /*in*/
  unsigned long _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_OP, &OP, _ctx);
  STARTING_BIT = Long_val(_v_STARTING_BIT);
  /* begin user-supplied calling sequence */
_res = mpz_scan0(OP,STARTING_BIT); if (_res==ULONG_MAX) _res = Max_long;
  /* end user-supplied calling sequence */
  _vres = Val_long(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_scan1(
	value _v_OP,
	value _v_STARTING_BIT)
{
  mpz_ptr OP; /*in*/
  unsigned long STARTING_BIT; /*in*/
  unsigned long _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_OP, &OP, _ctx);
  STARTING_BIT = Long_val(_v_STARTING_BIT);
  /* begin user-supplied calling sequence */
_res = mpz_scan1(OP,STARTING_BIT); if (_res==ULONG_MAX) _res = Max_long;
  /* end user-supplied calling sequence */
  _vres = Val_long(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_setbit(
	value _v_ROP,
	value _v_BIT_INDEX)
{
  mpz_ptr ROP; /*in*/
  unsigned long BIT_INDEX; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_ROP, &ROP, _ctx);
  BIT_INDEX = Long_val(_v_BIT_INDEX);
  mpz_setbit(ROP, BIT_INDEX);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_clrbit(
	value _v_ROP,
	value _v_BIT_INDEX)
{
  mpz_ptr ROP; /*in*/
  unsigned long BIT_INDEX; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_ROP, &ROP, _ctx);
  BIT_INDEX = Long_val(_v_BIT_INDEX);
  mpz_clrbit(ROP, BIT_INDEX);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_tstbit(
	value _v_OP,
	value _v_BIT_INDEX)
{
  mpz_ptr OP; /*in*/
  unsigned long BIT_INDEX; /*in*/
  int _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_OP, &OP, _ctx);
  BIT_INDEX = Long_val(_v_BIT_INDEX);
  _res = mpz_tstbit(OP, BIT_INDEX);
  _vres = Val_int(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_import(
	value _v_ROP,
	value _v_OP,
	value _v_ORDER,
	value _v_ENDIAN)
{
  mpz_ptr ROP; /*in*/
  int COUNT; /*in*/
  int *OP; /*in*/
  int ORDER; /*in*/
  int ENDIAN; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_ROP, &ROP, _ctx);
  OP = Bigarray_val(_v_OP)->data;
  COUNT = Bigarray_val(_v_OP)->dim[0];
  ORDER = Int_val(_v_ORDER);
  ENDIAN = Int_val(_v_ENDIAN);
  /* begin user-supplied calling sequence */
mpz_import (ROP, COUNT, ORDER, sizeof(intnat), ENDIAN, 0, OP);
  /* end user-supplied calling sequence */
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpz_mpz_export(
	value _v_OP,
	value _v_ORDER,
	value _v_ENDIAN)
{
  mpz_ptr OP; /*in*/
  int ORDER; /*in*/
  int ENDIAN; /*in*/
  int *COUNT; /*in*/
  int *_res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_OP, &OP, _ctx);
  ORDER = Int_val(_v_ORDER);
  ENDIAN = Int_val(_v_ENDIAN);
  /* begin user-supplied calling sequence */
_res = mpz_export (NULL, COUNT, ORDER, sizeof(intnat), ENDIAN, 0, OP);
  /* end user-supplied calling sequence */
  _vres = alloc_bigarray_dims(
          BIGARRAY_INT32 | BIGARRAY_C_LAYOUT | BIGARRAY_MANAGED,
          1, _res, *COUNT);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_fits_ulong_p(
	value _v_OP)
{
  mpz_ptr OP; /*in*/
  int _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_OP, &OP, _ctx);
  _res = mpz_fits_ulong_p(OP);
  _vres = Val_int(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_fits_slong_p(
	value _v_OP)
{
  mpz_ptr OP; /*in*/
  int _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_OP, &OP, _ctx);
  _res = mpz_fits_slong_p(OP);
  _vres = Val_int(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_fits_uint_p(
	value _v_OP)
{
  mpz_ptr OP; /*in*/
  int _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_OP, &OP, _ctx);
  _res = mpz_fits_uint_p(OP);
  _vres = Val_int(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_fits_sint_p(
	value _v_OP)
{
  mpz_ptr OP; /*in*/
  int _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_OP, &OP, _ctx);
  _res = mpz_fits_sint_p(OP);
  _vres = Val_int(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_fits_ushort_p(
	value _v_OP)
{
  mpz_ptr OP; /*in*/
  int _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_OP, &OP, _ctx);
  _res = mpz_fits_ushort_p(OP);
  _vres = Val_int(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_fits_sshort_p(
	value _v_OP)
{
  mpz_ptr OP; /*in*/
  int _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_OP, &OP, _ctx);
  _res = mpz_fits_sshort_p(OP);
  _vres = Val_int(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_odd_p(
	value _v_OP)
{
  mpz_ptr OP; /*in*/
  int _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_OP, &OP, _ctx);
  _res = mpz_odd_p(OP);
  _vres = Val_int(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_even_p(
	value _v_OP)
{
  mpz_ptr OP; /*in*/
  int _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_OP, &OP, _ctx);
  _res = mpz_even_p(OP);
  _vres = Val_int(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_size(
	value _v_OP)
{
  mpz_ptr OP; /*in*/
  int _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_OP, &OP, _ctx);
  _res = mpz_size(OP);
  _vres = Val_int(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpz_mpz_sizeinbase(
	value _v_OP,
	value _v_BASE)
{
  mpz_ptr OP; /*in*/
  int BASE; /*in*/
  int _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_OP, &OP, _ctx);
  BASE = Int_val(_v_BASE);
  /* begin user-supplied calling sequence */
  if (BASE<2 || BASE>36) caml_invalid_argument("Argument not supported");
  _res = mpz_sizeinbase (OP,BASE);
  /* end user-supplied calling sequence */
  _vres = Val_int(_res);
  camlidl_free(_ctx);
  return _vres;
}

