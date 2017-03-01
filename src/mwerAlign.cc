/* ---------------------------------------------------------------- */
/* Copyright 2003 (c) by RWTH Aachen - Lehrstuhl fuer Informatik VI */
/* Richard Zens                                                     */
/* ---------------------------------------------------------------- */
#include "mwerAlign.hh"
#include <iostream>
#include <fstream>
#include <sstream>

void MwerSegmenter::mwerAlign(const std::string& ref, const std::string& hyp, std::string& result)
{
//   cerr << ref << endl << hyp << endl;
  std::istringstream strRef(ref), strHyp(hyp);
  E->loadrefsFromStream(strRef);
  E->setOptions(maxER_, human_);
  E->setcase(true);
  Text hyps;
  strHyp >> hyps;
  std::ostringstream strOut;
  double unsegmentedWER=100.0*E->_evaluate2(hyps, strOut);
  std::cerr<<"AS-WER (automatic segmentation mWER): "<<unsegmentedWER<<"\n";
  result = strOut.str();
}
void MwerSegmenter::mwerAlign(const std::string& ref, const std::string& hyp, const std::string& hypBi, std::string& result)
{
//   cerr << ref << endl << hyp << endl;
  std::istringstream strRef(ref), strHyp(hyp), strHypBi(hypBi);
  E->loadrefsFromStream(strRef);
  E->setOptions(maxER_, human_);
  E->setcase(true);
  Text hyps;
  strHyp >> hyps;
  Text hypsBi;
  strHypBi >> hypsBi;
  std::ostringstream strOut;
  double unsegmentedWER=100.0*E->_evaluate2(hyps, hypsBi, strOut);
  std::cerr<<"AS-WER (automatic segmentation mWER): "<<unsegmentedWER<<"\n";
  result = strOut.str();
}
