PROJECT(mwerAlign)

set(mwerAlign_LIB_SRCS
    Evaluator.cc  
    Evaluator_unsegmentedWER.cc  
    IOfile.cc  
    mwerAlign.cc  
    SimpleText2.cc
    gzstream.cc
)

add_library(mwerAlignLib STATIC ${mwerAlign_LIB_SRCS})
install(TARGETS mwerAlignLib DESTINATION lib)
install(FILES Evaluator.hh Evaluator_unsegmentedWER.hh IOfile.hh mwerAlign.cc SimpleText2.hh gzstream.hh DESTINATION include)

