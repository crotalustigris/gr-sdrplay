/* -*- c++ -*- */
/* 
 * Copyright 2018 HB9FXQ, Frank Werner-Krippendorf.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "rspduo_source_impl.h"

namespace gr {
  namespace sdrplay {

    rspduo_source::sptr
    rspduo_source::make()
    {
      return gnuradio::get_initial_sptr
        (new rspduo_source_impl());
    }

    /*
     * The private constructor
     */
    rspduo_source_impl::rspduo_source_impl()
      : gr::sync_block("rspduo_source",
              gr::io_signature::make(0, 0, 0),
              gr::io_signature::make(1, 1/** With API version 3 we can add 2 channels :-)**/, sizeof(gr_complex)))
    {}

    /*
     * Our virtual destructor.
     */
    rspduo_source_impl::~rspduo_source_impl()
    {
    }

    int
    rspduo_source_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      gr_complex *out = (gr_complex *) output_items[0];

      // Do <+signal processing+>

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace sdrplay */
} /* namespace gr */

