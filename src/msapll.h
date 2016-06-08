/*
 * msapll.h
 *
 *  Created on: Jun 9, 2015
 *      Author: diego
 */

#ifndef MSAPLL_H_
#define MSAPLL_H_

#include "msa.h"
#include "plldefs.h"

namespace modeltest
{

  class MsaPll : public Msa
  {
  public:
    MsaPll (std::string msa_filename, mt_size_t n_taxa);        /* fasta   */
    MsaPll (std::string msa_filename, pll_msa_t * msa_data);    /* phylip  */
    MsaPll (std::string msa_filename, msa_format_t msa_format); /* generic */
    virtual ~MsaPll ();

    virtual const char * get_header (mt_index_t index) const;
    virtual const char * const *get_headers() const;
    virtual const char * get_sequence (mt_index_t index) const;
    virtual const unsigned int * get_weights( void ) const;
    virtual bool reorder_sites(partitioning_scheme_t & scheme);

    virtual void print() const;

    static bool test(std::string const& msa_filename,
               mt_size_t *n_tips,
               mt_size_t *n_sites,
               msa_format_t *msa_format = 0,
               data_type_t *datatype = 0);
  private:
    std::vector <pll_partition_t *> pll_partitions;
    char **sequences;
    char **tipnames;
    unsigned int * weights;
  };

} /* namespace modeltest */

#endif /* MSAPLL_H_ */
