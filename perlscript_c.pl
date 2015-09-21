print "\n/* This file is part of the MLGmpIDL interface, released under LGPL license with an exception allowing the redistribution of statically linked executables.\n  Please read the COPYING file packaged in the distribution  */";
while (<>) {
    s/([^ ]*)_ptr OUTOUTOUT;/$1_t OUTOUTOUT; $1_ptr OUTTOUTTOUTT = OUTOUTOUT;/g;
    s/\(\&OUTOUTOUT/\(\&OUTTOUTTOUTT/g;  
    s/struct mpfr_rnd_t/mpfr_rnd_t/g;
    print;
}
