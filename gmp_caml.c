/* ********************************************************************** */
/* gmp_caml.c */
/* ********************************************************************** */

/* This file is part of the MLGmpIDL interface, released under LGPL license.
   Please read the COPYING file packaged in the distribution  */

#include <assert.h>
#include <stdio.h>
#include "caml/fail.h"
#include "caml/alloc.h"
#include "caml/custom.h"
#include "caml/memory.h"
#include "caml/callback.h"
#include "caml/camlidlruntime.h"

#include "gmp_caml.h"

/* ********************************************************************** */
/* I. Custom datatypes: fastest coding */
/* ********************************************************************** */

/* ====================================================================== */
/* I.1 mpz_t */
/* ====================================================================== */

void camlidl_custom_mpz_finalize(value val)
{
  __mpz_struct* mpz = (__mpz_struct*)(Data_custom_val(val));
  mpz_clear(mpz);
}

int camlidl_custom_mpz_compare(value val1, value val2)
{
  int res;
  __mpz_struct* mpz1;
  __mpz_struct* mpz2;

  mpz1 = (__mpz_struct*)(Data_custom_val(val1));
  mpz2 = (__mpz_struct*)(Data_custom_val(val2));
  res = mpz_cmp(mpz1,mpz2);
  res = res > 0 ? 1 : res==0 ? 0 : -1;
  return res;
}
long camlidl_custom_mpz_hash(value val)
{
  __mpz_struct* mpz = (__mpz_struct*)(Data_custom_val(val));
  long hash = mpz_get_si(mpz);
  return hash;
}

struct custom_operations camlidl_custom_mpz = {
  "camlidl_gmp_custom_mpz",
  &camlidl_custom_mpz_finalize,
  &camlidl_custom_mpz_compare,
  &camlidl_custom_mpz_hash,
  custom_serialize_default,
  custom_deserialize_default
};

value camlidl_mpz_ptr_c2ml(mpz_ptr* mpz)
{
  value val;

  val = alloc_custom(&camlidl_custom_mpz, sizeof(__mpz_struct), 0, 1);
  *(((__mpz_struct*)(Data_custom_val(val)))) = *(*mpz);
  return val;
}
void camlidl_mpz_ptr_ml2c(value val, mpz_ptr* mpz)
{
  *mpz = (mpz_ptr)(Data_custom_val(val));
}

void camlidl_mpz_ml2c(value val, __mpz_struct* mpz)
{
  *mpz = *((mpz_ptr)(Data_custom_val(val)));
}


/* ====================================================================== */
/* I.2 mpq_t */
/* ====================================================================== */

void camlidl_custom_mpq_finalize(value val)
{
  __mpq_struct* mpq = (__mpq_struct*)(Data_custom_val(val));
  mpq_clear(mpq);
}

int camlidl_custom_mpq_compare(value val1, value val2)
{
  int res;
  __mpq_struct* mpq1;
  __mpq_struct* mpq2;

  mpq1 = (__mpq_struct*)(Data_custom_val(val1));
  mpq2 = (__mpq_struct*)(Data_custom_val(val2));
  res = mpq_cmp(mpq1,mpq2);
  res = res > 0 ? 1 : res==0 ? 0 : -1;
  return res;
}
long camlidl_custom_mpq_hash(value val)
{
 __mpq_struct* mpq = (__mpq_struct*)(Data_custom_val(val));
  unsigned long num = mpz_get_ui(mpq_numref(mpq));
  unsigned long den = mpz_get_ui(mpq_denref(mpq));
  long hash = num<den ? den/num : num/den;
  return hash;
}

struct custom_operations camlidl_custom_mpq = {
  "camlidl_gmp_custom_mpq",
  &camlidl_custom_mpq_finalize,
  &camlidl_custom_mpq_compare,
  &camlidl_custom_mpq_hash,
  custom_serialize_default,
  custom_deserialize_default
};

    value camlidl_mpq_ptr_c2ml(mpq_ptr* mpq)
{
  value val;

  val = alloc_custom(&camlidl_custom_mpq, sizeof(__mpq_struct), 0, 1);
  *(((__mpq_struct*)(Data_custom_val(val)))) = *(*mpq);
  return val;
}
void camlidl_mpq_ptr_ml2c(value val, mpq_ptr* mpq)
{
  *mpq = (mpq_ptr)(Data_custom_val(val));
}
void camlidl_mpq_ml2c(value val, __mpq_struct* mpq)
{
  *mpq = *((mpq_ptr)(Data_custom_val(val)));
}


/* ====================================================================== */
/* I.3 gmp_randstate_t */
/* ====================================================================== */

void camlidl_custom_gmp_randstate_finalize(value val)
{
 __gmp_randstate_struct* gmp_randstate = (__gmp_randstate_struct*)(Data_custom_val(val));
  gmp_randclear(gmp_randstate);
}

struct custom_operations camlidl_custom_gmp_randstate = {
  "camlidl_gmp_custom_randstate",
  &camlidl_custom_gmp_randstate_finalize,
  custom_compare_default,
  custom_hash_default,
  custom_serialize_default,
  custom_deserialize_default
};

value camlidl_gmp_randstate_ptr_c2ml(gmp_randstate_ptr* gmp_randstate)
{
  value val;

  val = alloc_custom(&camlidl_custom_gmp_randstate, sizeof(__gmp_randstate_struct), 0, 1);
  *((__gmp_randstate_struct*)(Data_custom_val(val))) = *(*gmp_randstate);
  return val;
}
void camlidl_gmp_randstate_ptr_ml2c(value val, gmp_randstate_ptr* gmp_randstate)
{
  *gmp_randstate = (gmp_randstate_ptr)(Data_custom_val(val));
}

/* ********************************************************************** */
/* II. Custom datatypes: more standard coding */
/* ********************************************************************** */

/* ====================================================================== */
/* II.1 mpz2_t */
/* ====================================================================== */
/*
void camlidl_custom_mpz2_finalize(value val)
{
  CAMLparam1(val);
  __mpz_struct** mpz = (__mpz_struct**)(Data_custom_val(val));
  mpz_clear(*mpz);
  free(*mpz);
}

int camlidl_custom_mpz2_compare(value val1, value val2)
{
  CAMLparam2(val1,val2);
  int res;
  __mpz_struct** mpz1;
  __mpz_struct** mpz2;

  mpz1 = (__mpz_struct**)(Data_custom_val(val1));
  mpz2 = (__mpz_struct**)(Data_custom_val(val2));
  res = mpz_cmp(*mpz1,*mpz2);
  res = res > 0 ? 1 : res==0 ? 0 : -1;
  CAMLreturn(res);
}
long camlidl_custom_mpz2_hash(value val)
{
  CAMLparam1(val);
  __mpz_struct** mpz = (__mpz_struct**)(Data_custom_val(val));
  long hash = mpz_get_si(*mpz);
  CAMLreturn(hash);
}

struct custom_operations camlidl_custom_mpz2 = {
  "camlidl_gmp_custom_mpz2",
  &camlidl_custom_mpz2_finalize,
  &camlidl_custom_mpz2_compare,
  &camlidl_custom_mpz2_hash,
  custom_serialize_default,
  custom_deserialize_default
};

value camlidl_mpz2_ptr_c2ml(mpz_ptr* mpz)
{
  value val;
  __mpz_struct* p;

  p = malloc(sizeof(__mpz_struct));
  *p = *(*mpz);
  val = alloc_custom(&camlidl_custom_mpz2, sizeof(__mpz_struct*), 0, 1);
  *(((__mpz_struct**)(Data_custom_val(val)))) = p;
  return val;
}
void camlidl_mpz2_ptr_ml2c(value val, mpz_ptr* mpz)
{
  *mpz = *(__mpz_struct**)(Data_custom_val(val));
}
*/
/* ====================================================================== */
/* II.2 mpq2_t */
/* ====================================================================== */
/*
void camlidl_custom_mpq2_finalize(value val)
{
  CAMLparam1(val);
  __mpq_struct** mpq = (__mpq_struct**)(Data_custom_val(val));
  mpq_clear(*mpq);
}

int camlidl_custom_mpq2_compare(value val1, value val2)
{
  CAMLparam2(val1,val2);
  int res;
  __mpq_struct** mpq1;
  __mpq_struct** mpq2;

  mpq1 = (__mpq_struct**)(Data_custom_val(val1));
  mpq2 = (__mpq_struct**)(Data_custom_val(val2));
  res = mpq_cmp(*mpq1,*mpq2);
  res = res > 0 ? 1 : res==0 ? 0 : -1;
  CAMLreturn(res);
}
long camlidl_custom_mpq2_hash(value val)
{
  CAMLparam1(val);
  __mpq_struct** mpq = (__mpq_struct**)(Data_custom_val(val));
  unsigned long num = mpz_get_ui(mpq_numref(*mpq));
  unsigned long den = mpz_get_ui(mpq_denref(*mpq));
  long hash = num<den ? den/num : num/den;
  CAMLreturn(hash);
}

struct custom_operations camlidl_custom_mpq2 = {
  "camlidl_gmp_custom_mpq2",
  &camlidl_custom_mpq2_finalize,
  &camlidl_custom_mpq2_compare,
  &camlidl_custom_mpq2_hash,
  custom_serialize_default,
  custom_deserialize_default
};

value camlidl_mpq2_ptr_c2ml(mpq_ptr* mpq)
{
  value val;
  __mpq_struct* p;
  p = malloc(sizeof(__mpq_struct));
  *p = *(*mpq);
  val = alloc_custom(&camlidl_custom_mpq2, sizeof(__mpq_struct), 0, 1);
  *((__mpq_struct**)(Data_custom_val(val))) = p;
  return val;
}
void camlidl_mpq2_ptr_ml2c(value val, mpq_ptr* mpq)
{
  *mpq = *(__mpq_struct**)(Data_custom_val(val));
}
*/

/* ====================================================================== */
/* II.3 gmp_randstate2_t */
/* ====================================================================== */
/*
void camlidl_custom_gmp_randstate2_finalize(value val)
{
  CAMLparam1(val);
 __gmp_randstate_struct** gmp_randstate = (__gmp_randstate_struct**)(Data_custom_val(val));
  gmp_randclear(*gmp_randstate);
  free(*gmp_randstate);
}

struct custom_operations camlidl_custom_gmp_randstate2 = {
  "camlidl_gmp_custom_randstate2",
  &camlidl_custom_gmp_randstate2_finalize,
  custom_compare_default,
  custom_hash_default,
  custom_serialize_default,
  custom_deserialize_default
};

value camlidl_gmp_randstate2_ptr_c2ml(gmp_randstate_ptr* gmp_randstate)
{
  value val;
  __gmp_randstate_struct* p;
  p = malloc(sizeof(__gmp_randstate_struct));
  *p = *(*gmp_randstate);

  val = alloc_custom(&camlidl_custom_gmp_randstate2, sizeof(__gmp_randstate_struct*), 0, 1);
  *((__gmp_randstate_struct**)(Data_custom_val(val))) = p;
  return val;
}
void camlidl_gmp_randstate2_ptr_ml2c(value val, gmp_randstate_ptr* gmp_randstate)
{
  *gmp_randstate = *(__gmp_randstate_struct**)(Data_custom_val(val));
}
*/

