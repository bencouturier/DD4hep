// $Id: Geant4Setup.cpp 578 2013-05-17 22:33:09Z markus.frank $
//====================================================================
//  AIDA Detector description implementation for LCD
//--------------------------------------------------------------------
//
//  Author     : M.Frank
//
//====================================================================
#ifndef DD4HEP_CONDITIONS_CONDITIONSTRANSACTION_H
#define DD4HEP_CONDITIONS_CONDITIONSTRANSACTION_H

// Framework include files
#include "DD4hep/Primitives.h"

/*
 *   DD4hep namespace declaration
 */
namespace DD4hep {

  namespace XML { class Handle_t; }

  /*
   *   Conditions namespace declaration
   */
  namespace Geometry {

    // Forward declarations
    class LCDD;
    class ConditionsHandler;

    /** @class ConditionsTransaction
     *
     *  Manage conditions transaction to the handler for a given LCDD instance
     *
     *  @author  M.Frank
     *  @version 1.0
     *  @date    01/04/2014
     */
    struct ConditionsTransaction {
      /// Internal flag to remember transaction contexts
      bool flag;
      /// Reference to the current LCDD instance
      LCDD& lcdd;
      /// Reference to the conditions handler
      ConditionsHandler* m_handler;
      
      /// Default constructor
      ConditionsTransaction(LCDD& l, const XML::Handle_t& e);
      /// Default destructor
      ~ConditionsTransaction();
    };

  } /* End namespace Geometry        */
} /* End namespace DD4hep            */
#endif    /* DD4HEP_CONDITIONS_CONDITIONSTRANSACTION_H       */