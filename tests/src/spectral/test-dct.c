#include <aubio.h>

int main (void)
{
  int return_code = 0;
  uint_t win_s = 32; // window size
  uint_t i, n_iters = 10; // number of iterations
  // create dct object
  aubio_dct_t * dct = new_aubio_dct(win_s);

  fvec_t * in = new_fvec (win_s); // input buffer
  fvec_t * dctout = new_fvec (win_s); // output buffer

  if (!dct || !in || !dctout) {
    return_code = 1;
    return return_code;
  }

  in->data[0] = 1.;
  for (i = 0; i < n_iters; i++) {
    // execute stft
    aubio_dct_do (dct, in, dctout);
    aubio_dct_rdo (dct, dctout, in);
  }
  fvec_print(dctout);
  fvec_print(in);
  del_fvec(dctout);
  del_fvec(in);

  del_aubio_dct(dct);
  return return_code;
}
