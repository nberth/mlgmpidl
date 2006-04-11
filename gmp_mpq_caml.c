/* File generated from mpq.idl */

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


#include "caml/custom.h"
#include "gmp_caml.h"

extern void camlidl_mpz_ptr_ml2c(value, mpz_ptr *);
#define camlidl_ml2c_mpz_mpz_ptr(v,c,ctx) camlidl_mpz_ptr_ml2c(v,c)

extern value camlidl_mpz_ptr_c2ml(mpz_ptr *);
#define camlidl_c2ml_mpz_mpz_ptr(c,ctx) camlidl_mpz_ptr_c2ml(c)


#define camlidl_ml2c_mpq_mpq_ptr(v,c,ctx) camlidl_mpq_ptr_ml2c(v,c)

#define camlidl_c2ml_mpq_mpq_ptr(c,ctx) camlidl_mpq_ptr_c2ml(c)

value camlidl_mpq_mpq_canonicalize(
	value _v_OP)
{
  mpq_ptr OP; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpq_mpq_ptr(_v_OP, &OP, _ctx);
  mpq_canonicalize(OP);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpq_mpq_init(value _unit)
{
  mpq_t OUTOUTOUT; mpq_ptr OUTTOUTTOUTT = OUTOUTOUT;; /*out*/
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  mpq_init(OUTOUTOUT);
  _vres = camlidl_c2ml_mpq_mpq_ptr(&OUTTOUTTOUTT, _ctx);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpq_mpq_set(
	value _v_ROP,
	value _v_OP)
{
  mpq_ptr ROP; /*in*/
  mpq_ptr OP; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpq_mpq_ptr(_v_ROP, &ROP, _ctx);
  camlidl_ml2c_mpq_mpq_ptr(_v_OP, &OP, _ctx);
  mpq_set(ROP, OP);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpq_mpq_set_z(
	value _v_ROP,
	value _v_OP)
{
  mpq_ptr ROP; /*in*/
  mpz_ptr OP; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpq_mpq_ptr(_v_ROP, &ROP, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_OP, &OP, _ctx);
  mpq_set_z(ROP, OP);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpq_mpq_set_si(
	value _v_ROP,
	value _v_OP1,
	value _v_OP2)
{
  mpq_ptr ROP; /*in*/
  long OP1; /*in*/
  unsigned long OP2; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpq_mpq_ptr(_v_ROP, &ROP, _ctx);
  OP1 = Long_val(_v_OP1);
  OP2 = Long_val(_v_OP2);
  mpq_set_si(ROP, OP1, OP2);
  camlidl_free(_ctx);
  /* begin user-supplied deallocation sequence */
mpq_canonicalize(ROP);
  /* end user-supplied deallocation sequence */
  return Val_unit;
}

value camlidl_mpq_mpq_set_str(
	value _v_ROP,
	value _v_STR,
	value _v_BASE)
{
  mpq_ptr ROP; /*in*/
  char *STR; /*in*/
  int BASE; /*in*/
  int _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpq_mpq_ptr(_v_ROP, &ROP, _ctx);
  STR = String_val(_v_STR);
  BASE = Int_val(_v_BASE);
  _res = mpq_set_str(ROP, STR, BASE);
  _vres = Val_int(_res);
  camlidl_free(_ctx);
  /* begin user-supplied deallocation sequence */
mpq_canonicalize(ROP);
  /* end user-supplied deallocation sequence */
  return _vres;
}

value camlidl_mpq_mpq_swap(
	value _v_ROP1,
	value _v_ROP2)
{
  mpq_ptr ROP1; /*in*/
  mpq_ptr ROP2; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpq_mpq_ptr(_v_ROP1, &ROP1, _ctx);
  camlidl_ml2c_mpq_mpq_ptr(_v_ROP2, &ROP2, _ctx);
  mpq_swap(ROP1, ROP2);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpq_mpq_get_d(
	value _v_OP)
{
  mpq_ptr OP; /*in*/
  double _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpq_mpq_ptr(_v_OP, &OP, _ctx);
  _res = mpq_get_d(OP);
  _vres = copy_double(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpq_mpq_set_d(
	value _v_ROP,
	value _v_OP)
{
  mpq_ptr ROP; /*in*/
  double OP; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpq_mpq_ptr(_v_ROP, &ROP, _ctx);
  OP = Double_val(_v_OP);
  mpq_set_d(ROP, OP);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpq_mpq_get_str(
	value _v_BASE,
	value _v_OP)
{
  int BASE; /*in*/
  mpq_ptr OP; /*in*/
  char *_res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  BASE = Int_val(_v_BASE);
  camlidl_ml2c_mpq_mpq_ptr(_v_OP, &OP, _ctx);
  /* begin user-supplied calling sequence */
_res = mpq_get_str(NULL,BASE,OP);
  /* end user-supplied calling sequence */
  _vres = copy_string(_res);
  camlidl_free(_ctx);
  /* begin user-supplied deallocation sequence */
free(_res);
  /* end user-supplied deallocation sequence */
  return _vres;
}

value camlidl_mpq_mpq_add(
	value _v_ROP,
	value _v_OP1,
	value _v_OP2)
{
  mpq_ptr ROP; /*in*/
  mpq_ptr OP1; /*in*/
  mpq_ptr OP2; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpq_mpq_ptr(_v_ROP, &ROP, _ctx);
  camlidl_ml2c_mpq_mpq_ptr(_v_OP1, &OP1, _ctx);
  camlidl_ml2c_mpq_mpq_ptr(_v_OP2, &OP2, _ctx);
  mpq_add(ROP, OP1, OP2);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpq_mpq_sub(
	value _v_ROP,
	value _v_OP1,
	value _v_OP2)
{
  mpq_ptr ROP; /*in*/
  mpq_ptr OP1; /*in*/
  mpq_ptr OP2; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpq_mpq_ptr(_v_ROP, &ROP, _ctx);
  camlidl_ml2c_mpq_mpq_ptr(_v_OP1, &OP1, _ctx);
  camlidl_ml2c_mpq_mpq_ptr(_v_OP2, &OP2, _ctx);
  mpq_sub(ROP, OP1, OP2);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpq_mpq_mul(
	value _v_ROP,
	value _v_OP1,
	value _v_OP2)
{
  mpq_ptr ROP; /*in*/
  mpq_ptr OP1; /*in*/
  mpq_ptr OP2; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpq_mpq_ptr(_v_ROP, &ROP, _ctx);
  camlidl_ml2c_mpq_mpq_ptr(_v_OP1, &OP1, _ctx);
  camlidl_ml2c_mpq_mpq_ptr(_v_OP2, &OP2, _ctx);
  mpq_mul(ROP, OP1, OP2);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpq_mpq_mul_2exp(
	value _v_ROP,
	value _v_OP1,
	value _v_OP2)
{
  mpq_ptr ROP; /*in*/
  mpq_ptr OP1; /*in*/
  unsigned long OP2; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpq_mpq_ptr(_v_ROP, &ROP, _ctx);
  camlidl_ml2c_mpq_mpq_ptr(_v_OP1, &OP1, _ctx);
  OP2 = Long_val(_v_OP2);
  mpq_mul_2exp(ROP, OP1, OP2);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpq_mpq_div(
	value _v_ROP,
	value _v_OP1,
	value _v_OP2)
{
  mpq_ptr ROP; /*in*/
  mpq_ptr OP1; /*in*/
  mpq_ptr OP2; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpq_mpq_ptr(_v_ROP, &ROP, _ctx);
  camlidl_ml2c_mpq_mpq_ptr(_v_OP1, &OP1, _ctx);
  camlidl_ml2c_mpq_mpq_ptr(_v_OP2, &OP2, _ctx);
  mpq_div(ROP, OP1, OP2);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpq_mpq_div_2exp(
	value _v_ROP,
	value _v_OP1,
	value _v_OP2)
{
  mpq_ptr ROP; /*in*/
  mpq_ptr OP1; /*in*/
  unsigned long OP2; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpq_mpq_ptr(_v_ROP, &ROP, _ctx);
  camlidl_ml2c_mpq_mpq_ptr(_v_OP1, &OP1, _ctx);
  OP2 = Long_val(_v_OP2);
  mpq_div_2exp(ROP, OP1, OP2);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpq_mpq_neg(
	value _v_ROP,
	value _v_OP)
{
  mpq_ptr ROP; /*in*/
  mpq_ptr OP; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpq_mpq_ptr(_v_ROP, &ROP, _ctx);
  camlidl_ml2c_mpq_mpq_ptr(_v_OP, &OP, _ctx);
  mpq_neg(ROP, OP);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpq_mpq_abs(
	value _v_ROP,
	value _v_OP)
{
  mpq_ptr ROP; /*in*/
  mpq_ptr OP; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpq_mpq_ptr(_v_ROP, &ROP, _ctx);
  camlidl_ml2c_mpq_mpq_ptr(_v_OP, &OP, _ctx);
  mpq_abs(ROP, OP);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpq_mpq_inv(
	value _v_ROP,
	value _v_OP)
{
  mpq_ptr ROP; /*in*/
  mpq_ptr OP; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpq_mpq_ptr(_v_ROP, &ROP, _ctx);
  camlidl_ml2c_mpq_mpq_ptr(_v_OP, &OP, _ctx);
  mpq_inv(ROP, OP);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpq_mpq_cmp(
	value _v_OP1,
	value _v_OP2)
{
  mpq_ptr OP1; /*in*/
  mpq_ptr OP2; /*in*/
  int _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpq_mpq_ptr(_v_OP1, &OP1, _ctx);
  camlidl_ml2c_mpq_mpq_ptr(_v_OP2, &OP2, _ctx);
  _res = mpq_cmp(OP1, OP2);
  _vres = Val_int(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpq_mpq_cmp_si(
	value _v_OP1,
	value _v_NUM2,
	value _v_DEN2)
{
  mpq_ptr OP1; /*in*/
  long NUM2; /*in*/
  unsigned long DEN2; /*in*/
  int _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpq_mpq_ptr(_v_OP1, &OP1, _ctx);
  NUM2 = Long_val(_v_NUM2);
  DEN2 = Long_val(_v_DEN2);
  _res = mpq_cmp_si(OP1, NUM2, DEN2);
  _vres = Val_int(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpq_mpq_sgn(
	value _v_OP)
{
  mpq_ptr OP; /*in*/
  int _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpq_mpq_ptr(_v_OP, &OP, _ctx);
  _res = mpq_sgn(OP);
  _vres = Val_int(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpq_mpq_equal(
	value _v_OP1,
	value _v_OP2)
{
  mpq_ptr OP1; /*in*/
  mpq_ptr OP2; /*in*/
  int _res;
  value _vres;

  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpq_mpq_ptr(_v_OP1, &OP1, _ctx);
  camlidl_ml2c_mpq_mpq_ptr(_v_OP2, &OP2, _ctx);
  _res = mpq_equal(OP1, OP2);
  _vres = Val_int(_res);
  camlidl_free(_ctx);
  return _vres;
}

value camlidl_mpq_mpq_get_num(
	value _v_NUMERATOR,
	value _v_RATIONAL)
{
  mpz_ptr NUMERATOR; /*in*/
  mpq_ptr RATIONAL; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_NUMERATOR, &NUMERATOR, _ctx);
  camlidl_ml2c_mpq_mpq_ptr(_v_RATIONAL, &RATIONAL, _ctx);
  mpq_get_num(NUMERATOR, RATIONAL);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpq_mpq_get_den(
	value _v_DENOMINATOR,
	value _v_RATIONAL)
{
  mpz_ptr DENOMINATOR; /*in*/
  mpq_ptr RATIONAL; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpz_mpz_ptr(_v_DENOMINATOR, &DENOMINATOR, _ctx);
  camlidl_ml2c_mpq_mpq_ptr(_v_RATIONAL, &RATIONAL, _ctx);
  mpq_get_den(DENOMINATOR, RATIONAL);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpq_mpq_set_num(
	value _v_RATIONAL,
	value _v_NUMERATOR)
{
  mpq_ptr RATIONAL; /*in*/
  mpz_ptr NUMERATOR; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpq_mpq_ptr(_v_RATIONAL, &RATIONAL, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_NUMERATOR, &NUMERATOR, _ctx);
  mpq_set_num(RATIONAL, NUMERATOR);
  camlidl_free(_ctx);
  return Val_unit;
}

value camlidl_mpq_mpq_set_den(
	value _v_RATIONAL,
	value _v_DENOMINATOR)
{
  mpq_ptr RATIONAL; /*in*/
  mpz_ptr DENOMINATOR; /*in*/
  struct camlidl_ctx_struct _ctxs = { CAMLIDL_TRANSIENT, NULL };
  camlidl_ctx _ctx = &_ctxs;
  camlidl_ml2c_mpq_mpq_ptr(_v_RATIONAL, &RATIONAL, _ctx);
  camlidl_ml2c_mpz_mpz_ptr(_v_DENOMINATOR, &DENOMINATOR, _ctx);
  mpq_set_den(RATIONAL, DENOMINATOR);
  camlidl_free(_ctx);
  return Val_unit;
}

