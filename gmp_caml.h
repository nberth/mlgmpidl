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
#include "caml/mlvalues.h"

#ifdef __cplusplus
extern "C" {
#endif

struct gmp_randstate__t {
  gmp_randstate_t mp;
};
typedef __gmp_randstate_struct* gmp_randstate_ptr;

value camlidl_mpz_ptr_c2ml(mpz_ptr* mpz);
void camlidl_mpz_ptr_ml2c(value val, mpz_ptr* mpz);

value camlidl_mpq_ptr_c2ml(mpq_ptr* mpq);
void camlidl_mpq_ptr_ml2c(value val, mpq_ptr* mpq);

value camlidl_gmp_randstate_ptr_c2ml(gmp_randstate_ptr* gmp_randstate);
void camlidl_gmp_randstate_ptr_ml2c(value val, gmp_randstate_ptr* gmp_randstate);

void camlidl_mpz_ml2c(value val, __mpz_struct* mpz);
void camlidl_mpq_ml2c(value val, __mpq_struct* mpq);

#ifdef __cplusplus
}
#endif

#endif
