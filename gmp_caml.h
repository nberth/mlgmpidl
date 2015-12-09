/* ********************************************************************** */
/* gmp_caml.h */
/* ********************************************************************** */

/* This file is part of the MLGmpIDL interface, released under LGPL license.
   Please read the COPYING file packaged in the distribution  */

#ifndef __GMP_CAML_H__
#define __GMP_CAML_H__

#include <stdio.h>
#include <assert.h>
#include "gmp.h"
#include "mpfr.h"
#include "caml/mlvalues.h"

#ifdef __cplusplus
extern "C" {
#endif

struct gmp_randstate__t {
  gmp_randstate_t mp;
};
typedef __gmp_randstate_struct* gmp_randstate_ptr;
typedef mpz_ptr mpz_ptrm;
typedef mpq_ptr mpq_ptrm;
typedef mpf_ptr mpf_ptrm;
typedef mpfr_ptr mpfr_ptrm;


value camlidl_mpz_ptr_c2ml(mpz_ptr* mpz);
void camlidl_mpz_ptr_ml2c(value val, mpz_ptr* mpz);
void camlidl_mpz_ml2c(value val, __mpz_struct* mpz);

value camlidl_mpq_ptr_c2ml(mpq_ptr* mpq);
void camlidl_mpq_ptr_ml2c(value val, mpq_ptr* mpq);
void camlidl_mpq_ml2c(value val, __mpq_struct* mpq);

value camlidl_mpf_ptr_c2ml(mpf_ptr* mpf);
void camlidl_mpf_ptr_ml2c(value val, mpf_ptr* mpf);
void camlidl_mpf_ml2c(value val, __mpf_struct* mpf);

value camlidl_mpfr_ptr_c2ml(mpfr_ptr* mpf);
void camlidl_mpfr_ptr_ml2c(value val, mpfr_ptr* mpf);
void camlidl_mpfr_ml2c(value val, __mpfr_struct* mpf);
static inline
value camlidl_mpfr_rnd_t_c2ml(mpfr_rnd_t* rnd)
{
  int res =
#if MPFR_VERSION_MAJOR >= 3
    (*rnd==MPFR_RNDNA) ? 6 :
#endif
    (int)(*rnd);
  return Val_int(res);
}
static inline
void camlidl_mpfr_rnd_t_ml2c(value val, mpfr_rnd_t* rnd)
{
  int arg = Int_val(val);
#if MPFR_VERSION_MAJOR >= 3
  arg = (arg==6) ? (int)MPFR_RNDNA : arg;
#endif
  *rnd = (mpfr_rnd_t)(Int_val(arg));
}

value camlidl_gmp_randstate_ptr_c2ml(gmp_randstate_ptr* gmp_randstate);
void camlidl_gmp_randstate_ptr_ml2c(value val, gmp_randstate_ptr* gmp_randstate);


int mpz_fits_int_p (mpz_t OP);
int mpf_fits_int_p (mpf_t OP);

#ifdef __cplusplus
}
#endif

#endif
